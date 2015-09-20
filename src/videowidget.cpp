#include "videowidget.h"
#include "ui_videowidget.h"
#include <QDebug>
#include <QFile>


videoWidget::videoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::videoWidget)
{
    ui->setupUi(this);
    m_local_pipeline = QGst::Pipeline::create();

}

videoWidget::~videoWidget()
{
    delete ui;
}
void videoWidget::add_pipeline_str(QString str)
{

    m_stream_bin=str;
}

void videoWidget::display_screen_1()
{

    QGst::ElementPtr bin;
    m_stream_pipeline = QGst::Pipeline::create();


    bin = QGst::Bin::fromDescription(
                m_stream_bin
               );

    m_stream_pipeline->add(bin);
    ui->videoWidget_gst->watchPipeline(m_stream_pipeline);


    //go!
    m_stream_pipeline->setState(QGst::StatePlaying);
}

void videoWidget::stop_display_screen_1()
{
    if (m_stream_pipeline) {
        m_stream_pipeline->setState(QGst::StateNull);
        ui->videoWidget_gst->stopPipelineWatch();

        m_stream_pipeline.clear();


    }
}

