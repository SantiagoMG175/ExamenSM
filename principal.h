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
#include "tabla.h"

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
    void altura();

    QString getM() const;

    QString getH() const;
    QString datos();

private slots:
    void on_cmdGenerar_pressed();
    void on_cmdDatos_released();

private:
    Ui::Principal *ui;
    QString m, h;
    float mf, hf;
    float imc;




};
#endif // PRINCIPAL_H
