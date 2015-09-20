#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
/*
        GStreamer INCLUDE
*/
#include <QGlib/Connect>
#include <QGlib/Error>
#include <QGst/Init>
#include <QGst/Pipeline>
#include <QGst/ElementFactory>
#include <QGst/Parse>
#include <QGst/Pad>
#include <QGst/Structure>
#include <QGst/Bus>

namespace Ui {
class videoWidget;
}

class videoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit videoWidget(QWidget *parent = 0);
    ~videoWidget();
private:
    void playVideo();

private slots:
    void add_pipeline_str(QString);
    void display_screen_1();
    void stop_display_screen_1();

private:
    Ui::videoWidget *ui;
    QString m_stream_bin,m_video_bin,m_play_bin;
    QGst::PipelinePtr m_stream_pipeline,m_video_pipeline,m_play_pipeline;
    QGst::PipelinePtr m_local_pipeline;
};

#endif // VIDEOWIDGET_H
