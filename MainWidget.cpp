#include "MainWidget.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
void vlc_callback(const struct libvlc_event_t* p_event, void* p_data)
{
    MainWidget* main = static_cast<MainWidget*>(p_data);

    if (main)
    {
        if (p_event->type == libvlc_MediaPlayerPositionChanged) {
            float postion = libvlc_media_player_get_position(main->getPlayer());
            main->setTimeSlider(postion * 100);

            qint64 curSecs = libvlc_media_player_get_time(main->getPlayer()) / 1000;

            int curhour = curSecs / 3600;
            int curmin = (curSecs - curhour * 3600) / 60;
            int cursec = curSecs - curhour * 3600 - curmin * 60;

            char buff1[256] = { 0 };
            sprintf(buff1, "%02d:%02d:%02d", curhour, curmin, cursec);
            QString str1(buff1);

            qint64 totalSecs = main->getDuration();

            int hour = totalSecs / 3600;
            int min = (totalSecs - hour * 3600) / 60;
            int sec = totalSecs - hour * 3600 - min * 60;

            char buff2[256] = { 0 };
            sprintf(buff2, "%02d:%02d:%02d", hour, min, sec);
            QString str2(buff2);
            
            main->setLable(str1 + " \ " + str2);

        }
        else if(p_event->type == libvlc_MediaPlayerAudioVolume)
        {
            float volume = libvlc_audio_get_volume(main->getPlayer());
            main->setVolumeSlider(volume);
        }
        
    }

}

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    //vlc初始化
    m_pInstance = libvlc_new(0, nullptr);

    if (m_pInstance)
    {
        m_pMediaPlayer = libvlc_media_player_new(m_pInstance);
        if (!m_pMediaPlayer)
        {
            QMessageBox::information(this, u8"提示", u8"libvlc_media_player_new failed");
            libvlc_release(m_pInstance);
            exit(EXIT_FAILURE);
        }
        else
        {
            m_pEvent_manager = libvlc_media_player_event_manager(m_pMediaPlayer);
            libvlc_event_attach(m_pEvent_manager, libvlc_MediaPlayerPositionChanged, vlc_callback, this);
            libvlc_event_attach(m_pEvent_manager, libvlc_MediaPlayerAudioVolume, vlc_callback, this);

        }
    }
    else
    {
        QMessageBox::information(this, u8"提示", u8"libvlc_new failed");
        exit(EXIT_FAILURE);
    }

    connect(ui.openfile, &QPushButton::clicked, this, [=]()
        {
            fileName = QFileDialog::getOpenFileName(this, u8"请选择文件", "D:/", u8"视频文件(*.mp4 *.flv);;所有文件");
            fileName = QDir::toNativeSeparators(fileName);
            if (fileName.isEmpty())
            {
                QMessageBox::information(this, u8"提示", u8"libvlc_path_new failed");
                return;
            }

            //设置路径
            m_pMedia = libvlc_media_new_path(m_pInstance, fileName.toStdString().c_str());
            if (m_pMedia)
            {
                //解析media
                libvlc_media_parse(m_pMedia);
                //设置media
                libvlc_media_player_set_media(m_pMediaPlayer, m_pMedia);
                //设置播放的窗口句柄
                libvlc_media_player_set_hwnd(m_pMediaPlayer, (void*)(ui.videowidget->winId()));
                //释放media
                m_totalSecs = libvlc_media_get_duration(m_pMedia) / 1000;
                libvlc_media_release(m_pMedia);
                m_pMedia = nullptr;

                //播放视频
                libvlc_media_player_play(m_pMediaPlayer);
            }
            else
            {
                QMessageBox::information(this, u8"提示", u8"libvlc_media_new failed");
                exit(EXIT_FAILURE);
            }

        });

    connect(ui.pauseBtn, &QPushButton::clicked, this, [=]()
        {   
            if (libvlc_media_player_get_state(m_pMediaPlayer) == libvlc_state_t::libvlc_Playing)
            {
                libvlc_media_player_pause(m_pMediaPlayer);
            }
                  
        });

    connect(ui.playBtn, &QPushButton::clicked, this, [=]()
        {
            if (libvlc_media_player_get_state(m_pMediaPlayer) == libvlc_state_t::libvlc_Paused
                || libvlc_media_player_get_state(m_pMediaPlayer) == libvlc_state_t::libvlc_Stopped)
            {
                libvlc_media_player_play(m_pMediaPlayer);
            }

        });
    connect(ui.stopBtn, &QPushButton::clicked, this, [=]()
        {
            if (libvlc_media_player_get_state(m_pMediaPlayer) == libvlc_state_t::libvlc_Playing
                || libvlc_media_player_get_state(m_pMediaPlayer) == libvlc_state_t::libvlc_Paused)
            {
                libvlc_media_player_stop(m_pMediaPlayer);
            }
        });
    connect(ui.timeSlider, &QSlider::sliderMoved, this, [=](int value)
        {
            libvlc_media_player_set_position(m_pMediaPlayer, value / 100.0);
        });
    
    connect(ui.volumeSlider, &QSlider::sliderMoved, this, [=](int value)
        {
            libvlc_audio_set_volume(m_pMediaPlayer, value);
        });

    connect(ui.fullBtn, &QPushButton::clicked, this, [=]()
        {
            int bo = 1;
            libvlc_set_fullscreen(m_pMediaPlayer, bo);

        });


}

MainWidget::~MainWidget()
{
    if (m_pMediaPlayer)
    {
        libvlc_media_player_release(m_pMediaPlayer);
        m_pMediaPlayer = nullptr;
    }
    

    //最后释放
    if (m_pInstance)
    {
        libvlc_release(m_pInstance);
        m_pInstance = nullptr;
    }
}

libvlc_media_player_t* MainWidget::getPlayer()
{
    return m_pMediaPlayer;
}

void MainWidget::setTimeSlider(int value)
{
    ui.timeSlider->setValue(value);
}

void MainWidget::setVolumeSlider(int value)
{
    ui.volumeSlider->setValue(value);
}

qint64 MainWidget::getDuration()
{
    return m_totalSecs;
}

void MainWidget::setLable(QString buff)
{
    ui.timeLable->setText(buff);
}

