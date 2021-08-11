#include "tabla.h"
#include "ui_tabla.h"

Tabla::Tabla(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tabla)
{
    ui->setupUi(this);
}

Tabla::~Tabla()
{
    delete ui;
}



void Tabla::escribir(QString data)
{

    ui->outDatos->setText(data);



}


