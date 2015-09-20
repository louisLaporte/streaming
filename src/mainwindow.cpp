#include "mainwindow.h"

/*
 * INTERNET PROTOCOL SUITE
 * ---------------------------------------------------------------------------------+
 * #1 Application layer                                                             |
 * ---------------------------------------------------------------------------------+
 * We use RTP, this is a network protocol like HTTP, SSL, SSH , SMTP ...            |
 * but it is use for video and audio transmission                                   |
 *                                                                                  |
 * RTP = Real-time Transport Protocol (More info RFC 3550 and RFC 3551) Not SRTP    |
 * ---------------------------------------------------------------------------------+
 * #2 Transaport layer                                                              |
 * ---------------------------------------------------------------------------------+
 * We use TCP/UDP                                                                   |
 *                                                                                  |
 * TCP = Transmission Control Protocol                                              |
 * UDP = User Datagram Protocol                                                     |
 * ---------------------------------------------------------------------------------+
 *
 *
 * GSTREAMER VIDEO
 * ---------------------------------------------------------------------------------+
 * A usefull link for gstreamer knowlegde and comprehension CommandLineInterface :  |
 * http://www.z25.org/static/_rd_/videostreaming_intro_plab/                        |
 *  http://nicolargo.developpez.com/tutoriels/audio/gstreamer-theorie/              |
 * ---------------------------------------------------------------------------------+
 * SERVER SIDE                                                                      |
 * ---------------------------------------------------------------------------------+
 * For us this is the transmitter from our emmbded system or Desktop system         |
 * ---------------------------------------------------------------------------------+
 * CLIENT SIDE                                                                      |
 * ---------------------------------------------------------------------------------+
 * For us this is the receiver from the Desktop system                              |
 * ---------------------------------------------------------------------------------+
 *
 * qt-gstreamer doc
 * http://gstreamer.freedesktop.org/data/doc/gstreamer/head/qt-gstreamer/html/
 * http://gstreamer.freedesktop.org/data/doc/gstreamer/head/gstreamer/html/gstreamer-GstValue.html
 */







MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    m_video_1 = new videoWidget();

    m_streamEditor =new streamEditor();

    ui->streamToolTab->removeTab(0);
    ui->streamToolTab->insertTab(0,m_streamEditor,"Stream");
    ui->videoLayout->addWidget(m_video_1);

    connect(m_streamEditor,SIGNAL(send_pipeline(QString)),m_video_1,SLOT(add_pipeline_str(QString)));

    connect(m_streamEditor,SIGNAL(start_gstreamer_command()),m_video_1,SLOT(display_screen_1()));
    connect(m_streamEditor,SIGNAL(stop_gstreamer_command()),m_video_1,SLOT(stop_display_screen_1()));
    m_streamEditor->comboBox_initValue();

}



MainWindow::~MainWindow()
{
    delete ui;
}





