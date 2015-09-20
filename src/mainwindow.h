#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

#include "streameditor.h"
#include "videowidget.h"

#include <QGst/Message>
namespace Ui{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

signals:

private:
    Ui::MainWindow *ui;
    streamEditor *m_streamEditor;
    videoWidget *m_video_1;

};

#endif // MAINWINDOW_H
