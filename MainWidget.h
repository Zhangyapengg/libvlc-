#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWidget.h"
#include <basetsd.h>
typedef SSIZE_T ssize_t;
#include "vlc/vlc.h"


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    libvlc_media_player_t* getPlayer();
    void setTimeSlider(int value);
    void setVolumeSlider(int value);
    qint64 getDuration();
    void setLable(QString buff);


private:
    Ui::MainWidgetClass ui;

    libvlc_instance_t* m_pInstance = nullptr;
    libvlc_media_player_t* m_pMediaPlayer = nullptr;
    libvlc_media_t* m_pMedia = nullptr;
    QString fileName;
    libvlc_event_manager_t* m_pEvent_manager = nullptr;
     
    qint64 m_totalSecs = -1;

};
