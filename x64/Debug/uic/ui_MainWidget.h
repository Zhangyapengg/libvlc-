/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *videowidget;
    QSlider *timeSlider;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *timeLable;
    QPushButton *openfile;
    QPushButton *playBtn;
    QPushButton *pauseBtn;
    QPushButton *stopBtn;
    QPushButton *fullBtn;
    QLabel *label;
    QSlider *volumeSlider;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *MainWidgetClass)
    {
        if (MainWidgetClass->objectName().isEmpty())
            MainWidgetClass->setObjectName(QString::fromUtf8("MainWidgetClass"));
        MainWidgetClass->resize(862, 624);
        verticalLayout = new QVBoxLayout(MainWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        videowidget = new QWidget(MainWidgetClass);
        videowidget->setObjectName(QString::fromUtf8("videowidget"));

        verticalLayout->addWidget(videowidget);

        timeSlider = new QSlider(MainWidgetClass);
        timeSlider->setObjectName(QString::fromUtf8("timeSlider"));
        timeSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(timeSlider);

        widget = new QWidget(MainWidgetClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(10000000, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        timeLable = new QLabel(widget);
        timeLable->setObjectName(QString::fromUtf8("timeLable"));

        horizontalLayout->addWidget(timeLable);

        openfile = new QPushButton(widget);
        openfile->setObjectName(QString::fromUtf8("openfile"));

        horizontalLayout->addWidget(openfile);

        playBtn = new QPushButton(widget);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));

        horizontalLayout->addWidget(playBtn);

        pauseBtn = new QPushButton(widget);
        pauseBtn->setObjectName(QString::fromUtf8("pauseBtn"));

        horizontalLayout->addWidget(pauseBtn);

        stopBtn = new QPushButton(widget);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));

        horizontalLayout->addWidget(stopBtn);

        fullBtn = new QPushButton(widget);
        fullBtn->setObjectName(QString::fromUtf8("fullBtn"));
        fullBtn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(fullBtn);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        volumeSlider = new QSlider(widget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(volumeSlider);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(MainWidgetClass);

        QMetaObject::connectSlotsByName(MainWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MainWidgetClass)
    {
        MainWidgetClass->setWindowTitle(QCoreApplication::translate("MainWidgetClass", "MainWidget", nullptr));
        timeLable->setText(QCoreApplication::translate("MainWidgetClass", "\346\234\252\351\200\211\345\256\232\350\247\206\351\242\221", nullptr));
        openfile->setText(QCoreApplication::translate("MainWidgetClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        playBtn->setText(QCoreApplication::translate("MainWidgetClass", "\346\222\255\346\224\276", nullptr));
        pauseBtn->setText(QCoreApplication::translate("MainWidgetClass", "\346\232\202\345\201\234", nullptr));
        stopBtn->setText(QCoreApplication::translate("MainWidgetClass", "\345\201\234\346\255\242", nullptr));
        fullBtn->setText(QCoreApplication::translate("MainWidgetClass", "\345\205\250\345\261\217", nullptr));
        label->setText(QCoreApplication::translate("MainWidgetClass", "  \351\237\263\351\207\217\357\274\232 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidgetClass: public Ui_MainWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
