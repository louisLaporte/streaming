#ifndef STREAMEDITOR_H
#define STREAMEDITOR_H

#include <QWidget>

namespace Ui {
class streamEditor;
}

class streamEditor : public QWidget
{
    Q_OBJECT

public:
    explicit streamEditor(QWidget *parent = 0);
    ~streamEditor();
    void comboBox_initValue();

public slots :
    void set_bin_fromDescription(QString str);
   // void on_button_stop_pressed();
   // void on_button_execute_pressed();
    void stop_pressed();
    void execute_pressed();
    void lineEdit_changed(QString);

signals:
    void send_pipeline(QString);
    void start_gstreamer_command();
    void stop_gstreamer_command();


private:
    Ui::streamEditor *ui;
};

#endif // STREAMEDITOR_H
