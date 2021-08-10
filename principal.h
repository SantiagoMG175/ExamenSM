#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QCoreApplication>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QDateTime>


QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

    float calcular();
    void validacion();
    void limpiarDatos();



private slots:


    void on_cmdGenerar_pressed();

private:
    Ui::Principal *ui;




};
#endif // PRINCIPAL_H
