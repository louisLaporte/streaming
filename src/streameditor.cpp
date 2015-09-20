#include "streameditor.h"
#include "ui_streameditor.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QIODevice>
#include <QDebug>
streamEditor::streamEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::streamEditor)
{
    ui->setupUi(this);

    connect(ui->lineEdit_ip,SIGNAL(textChanged(QString)),this,SLOT(set_bin_fromDescription(QString)));
    connect(ui->lineEdit_port,SIGNAL(textChanged(QString)),this,SLOT(set_bin_fromDescription(QString)));
    connect(ui->comboBox_source,SIGNAL(currentIndexChanged(QString)),SLOT(set_bin_fromDescription(QString)));
    connect(ui->comboBox_gdp_depayloader,SIGNAL(currentIndexChanged(QString)),SLOT(set_bin_fromDescription(QString)));
    connect(ui->comboBox_rtp_depayloader,SIGNAL(currentIndexChanged(QString)),SLOT(set_bin_fromDescription(QString)));
    connect(ui->comboBox_parser,SIGNAL(currentIndexChanged(QString)),SLOT(set_bin_fromDescription(QString)));
    connect(ui->comboBox_decoder,SIGNAL(currentIndexChanged(QString)),SLOT(set_bin_fromDescription(QString)));
    connect(ui->comboBox_converter,SIGNAL(currentIndexChanged(QString)),SLOT(set_bin_fromDescription(QString)));
    connect(ui->comboBox_sinker,SIGNAL(currentIndexChanged(QString)),this,SLOT(set_bin_fromDescription(QString)));

    connect(ui->lineEdit_pipeline,SIGNAL(textChanged(QString)),this,SLOT(lineEdit_changed(QString)));

    connect(ui->execute_display_1_button,SIGNAL(pressed()),this,SLOT(execute_pressed()));
    connect(ui->stop_display_1_button,SIGNAL(pressed()),this,SLOT(stop_pressed()));

}
void streamEditor::lineEdit_changed(QString str)
{
    emit send_pipeline(str);
}



streamEditor::~streamEditor()
{
    delete ui;
}
void streamEditor::execute_pressed()
{
    qWarning()<<"execute pressed";
    emit start_gstreamer_command();
}
void streamEditor::stop_pressed()
{
    qWarning()<<"stop pressed";
    emit stop_gstreamer_command();
}
void streamEditor::comboBox_initValue()
{
    ui->comboBox_source->setToolTip("source");

    qWarning()<<QDir::currentPath();
    QString dataDir = QDir::currentPath()+"/../src/DATA/";
    qWarning()<<dataDir;

    QString intputFile_source           =dataDir+"SOURCE.txt";
    QString intputFile_gdp_depayloader  =dataDir+"DEPAYLOADER.txt";
    QString intputFile_rtp_depayloader  =dataDir+"DEPAYLOADER.txt";
    QString intputFile_parser           =dataDir+"PARSER.txt";
    QString intputFile_decoder          =dataDir+"DECODER.txt";
    QString intputFile_converter        =dataDir+"CONVERTER.txt";
    QString intputFile_sink             =dataDir+"SINK.txt";

    QFile outputFile_source         (intputFile_source);
    QFile outputFile_gdp_depayloader(intputFile_gdp_depayloader);
    QFile outputFile_rtp_depayloader(intputFile_rtp_depayloader);
    QFile outputFile_parser         (intputFile_parser);
    QFile outputFile_decoder        (intputFile_decoder);
    QFile outputFile_converter      (intputFile_converter);
    QFile outputFile_sink           (intputFile_sink);


    //SOURCE
    if (!outputFile_source.open(QIODevice::ReadOnly| QIODevice::Text))
        //return;
    {/*qDebug()<<QString("Failed to open %1").arg(outputFile_source);*/}
    else
    {
        QTextStream in(&outputFile_source);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            ui->comboBox_source->addItem(line);
        }
        outputFile_source.close();
        // add blank if unused variable
        ui->comboBox_source->addItem("");
        int source_default_pos=ui->comboBox_source->findText("tcpclientsrc");
        ui->comboBox_source->setCurrentIndex(source_default_pos);
    }
    //GDP_DEPAYLOADER
    if (!outputFile_gdp_depayloader.open(QIODevice::ReadOnly| QIODevice::Text))
        //return;
    {}
    else
    {
        QTextStream in(&outputFile_gdp_depayloader);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            ui->comboBox_gdp_depayloader->addItem(line);
        }
        outputFile_gdp_depayloader.close();
        ui->comboBox_gdp_depayloader->addItem("");
        int gdp_depayloader_default_pos=ui->comboBox_gdp_depayloader->findText("gdpdepay");
        ui->comboBox_gdp_depayloader->setCurrentIndex(gdp_depayloader_default_pos);
    }
    //RTP_DEPAYLOADER
    if (!outputFile_rtp_depayloader.open(QIODevice::ReadOnly| QIODevice::Text))
        //return;
    {}
    else
    {
        QTextStream in(&outputFile_rtp_depayloader);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            ui->comboBox_rtp_depayloader->addItem(line);
        }
        outputFile_rtp_depayloader.close();
        ui->comboBox_rtp_depayloader->addItem("");
        int rtp_depayloader_default_pos=ui->comboBox_rtp_depayloader->findText("rtph264depay");
        ui->comboBox_rtp_depayloader->setCurrentIndex(rtp_depayloader_default_pos);
    }
    //PARSER
    if (!outputFile_parser.open(QIODevice::ReadOnly| QIODevice::Text))
        //return;
    {}
    else
    {
        QTextStream in(&outputFile_parser);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            ui->comboBox_parser->addItem(line);
        }
        outputFile_parser.close();
        ui->comboBox_parser->addItem("");
        int parser_default_pos=ui->comboBox_parser->findText("h264parse");
        ui->comboBox_parser->setCurrentIndex(parser_default_pos);
    }
    //DECODER
    if (!outputFile_decoder.open(QIODevice::ReadOnly| QIODevice::Text))
        //return;
    {}
    else
    {
        QTextStream in(&outputFile_decoder);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            ui->comboBox_decoder->addItem(line);
        }
        outputFile_decoder.close();
        ui->comboBox_decoder->addItem("");
        int decoder_default_pos=ui->comboBox_decoder->findText("avdec_h264");
        ui->comboBox_decoder->setCurrentIndex(decoder_default_pos);
    }
    //CONVERTER
    if (!outputFile_converter.open(QIODevice::ReadOnly| QIODevice::Text))
        //return;
    {}
    else
    {
        QTextStream in(&outputFile_converter);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            ui->comboBox_converter->addItem(line);
        }
        outputFile_converter.close();
        ui->comboBox_converter->addItem("");
        int converter_default_pos=ui->comboBox_converter->findText("videoconvert");
        ui->comboBox_converter->setCurrentIndex(converter_default_pos);
    }
    //SINK
    if (!outputFile_sink.open(QIODevice::ReadOnly| QIODevice::Text))
        //return;
    {}
    else
    {
        QTextStream in(&outputFile_sink);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            ui->comboBox_sinker->addItem(line);
        }
        outputFile_sink.close();
        ui->comboBox_sinker->addItem("");
        int source_default_pos=ui->comboBox_sinker->findText("autovideosink");
        ui->comboBox_sinker->setCurrentIndex(source_default_pos);
    }

    //pipeline init construction

    //define IP an PORT
    ui->lineEdit_ip->setText("");
    ui->lineEdit_port->setText("5000");

    QString linker_str= " ! ";
    //SRC STRING
    QString src_str=QString("%1 %2%3 %4%5")
            .arg(ui->comboBox_source->currentText())
            .arg(ui->label_ip->text())
            .arg(ui->lineEdit_ip->displayText())
            .arg(ui->label_port->text())
            .arg(ui->lineEdit_port->displayText());
    //GDP PAYLOADER STRING
    QString gdp_depayloader_str;
    if(ui->comboBox_gdp_depayloader->currentText()!=NULL)
    {
        gdp_depayloader_str = QString ("%1 %2")
                .arg(linker_str)
                .arg(ui->comboBox_gdp_depayloader->currentText());
    }
    else
    {
        gdp_depayloader_str = QString ("%1")
                .arg(ui->comboBox_gdp_depayloader->currentText());
    }
    //RTP DEPAYLOADER STRING
    QString rtp_depayloader_str;
    if(ui->comboBox_rtp_depayloader->currentText()!=NULL)
    {
        rtp_depayloader_str = QString ("%1 %2")
                .arg(linker_str)
                .arg(ui->comboBox_rtp_depayloader->currentText());
    }
    else
    {
        rtp_depayloader_str = QString ("%1")
                .arg(ui->comboBox_rtp_depayloader->currentText());
    }
    //PARSER STRING
    QString parser_str;
    if(ui->comboBox_parser->currentText()!=NULL)
    {
        parser_str = QString ("%1 %2")
                .arg(linker_str)
                .arg(ui->comboBox_parser->currentText());
    }
    else
    {
        parser_str = QString ("%1")
                .arg(ui->comboBox_parser->currentText());
    }
    //DECODER STRING
    QString decoder_str;
    if(ui->comboBox_decoder->currentText()!=NULL)
    {
        decoder_str = QString ("%1 %2")
                .arg(linker_str)
                .arg(ui->comboBox_decoder->currentText());
    }
    else
    {
        decoder_str = QString ("%1")
                .arg(ui->comboBox_decoder->currentText());
    }
    //CONVERTER
    QString converter_str;
    if(ui->comboBox_converter->currentText()!=NULL)
    {
        converter_str = QString ("%1 %2")
                .arg(linker_str)
                .arg(ui->comboBox_converter->currentText());
    }
    else
    {
        converter_str = QString ("%1")
                .arg(ui->comboBox_converter->currentText());
    }
    //SINK
    QString sinker_str;
    if(ui->comboBox_sinker->currentText()!=NULL)
    {
        sinker_str = QString ("%1 %2")
                .arg(linker_str)
                .arg(ui->comboBox_sinker->currentText());
    }
    else
    {
        sinker_str = QString ("%1")
                .arg(ui->comboBox_sinker->currentText());
    }

    // CONSTRUCT PIPELINE
    QString pipeline_str=QString("%1 %2 %3 %4 %5 %6 %7")
            .arg(src_str)
            .arg(gdp_depayloader_str)
            .arg(rtp_depayloader_str)
            .arg(parser_str)
            .arg(decoder_str)
            .arg(converter_str)
            .arg(sinker_str);




    ui->lineEdit_pipeline->setText(pipeline_str);
    emit send_pipeline(pipeline_str);

}



void streamEditor::set_bin_fromDescription(QString str)
{
    Q_UNUSED(str);
    QString ip_adress=QString("\"%1\"").arg(ui->lineEdit_ip->displayText());


    QString linker_str= " ! ";
    //SRC STRING
    QString src_str=QString("%1 %2 %3 %4 %5")
            .arg(ui->comboBox_source->currentText())
            .arg(ui->label_ip->text())
            .arg(ip_adress)
            .arg(ui->label_port->text())
            .arg(ui->lineEdit_port->displayText());

    //GDP PAYLOADER STRING
    QString gdp_depayloader_str;
    if(ui->comboBox_gdp_depayloader->currentText()!=NULL)
    {
        gdp_depayloader_str = QString ("%1 %2")
                .arg(linker_str)
                .arg(ui->comboBox_gdp_depayloader->currentText());
    }
    else
    {
        gdp_depayloader_str = QString ("%1")
                .arg(ui->comboBox_gdp_depayloader->currentText());
    }
    //RTP DEPAYLOADER STRING
    QString rtp_depayloader_str;
    if(ui->comboBox_rtp_depayloader->currentText()!=NULL)
    {
        rtp_depayloader_str = QString ("%1 %2")
                .arg(linker_str)
                .arg(ui->comboBox_rtp_depayloader->currentText());
    }
    else
    {
        rtp_depayloader_str = QString ("%1")
                .arg(ui->comboBox_rtp_depayloader->currentText());
    }
    //PARSER STRING
    QString parser_str;
    if(ui->comboBox_parser->currentText()!=NULL)
    {
        parser_str = QString ("%1 %2")
                .arg(linker_str)
                .arg(ui->comboBox_parser->currentText());
    }
    else
    {
        parser_str = QString ("%1")
                .arg(ui->comboBox_parser->currentText());
    }
    //DECODER STRING
    QString decoder_str;
    if(ui->comboBox_decoder->currentText()!=NULL)
    {
        decoder_str = QString ("%1 %2")
                .arg(linker_str)
                .arg(ui->comboBox_decoder->currentText());
    }
    else
    {
        decoder_str = QString ("%1")
                .arg(ui->comboBox_decoder->currentText());
    }
    //CONVERTER
    QString converter_str;
    if(ui->comboBox_converter->currentText()!=NULL)
    {
        converter_str = QString ("%1 %2")
                .arg(linker_str)
                .arg(ui->comboBox_converter->currentText());
    }
    else
    {
        converter_str = QString ("%1")
                .arg(ui->comboBox_converter->currentText());
    }
    //SINK
    QString sinker_str;
    if(ui->comboBox_sinker->currentText()!=NULL)
    {
        sinker_str = QString ("%1 %2")
                .arg(linker_str)
                .arg(ui->comboBox_sinker->currentText());
    }
    else
    {
        sinker_str = QString ("%1")
                .arg(ui->comboBox_sinker->currentText());
    }

    // CONSTRUCT PIPELINE
    QString pipeline_str=QString("%1 %2 %3 %4 %5 %6 %7")
            .arg(src_str)
            .arg(gdp_depayloader_str)
            .arg(rtp_depayloader_str)
            .arg(parser_str)
            .arg(decoder_str)
            .arg(converter_str)
            .arg(sinker_str);



    ui->lineEdit_pipeline->setText(pipeline_str);
    emit send_pipeline(pipeline_str);

}
