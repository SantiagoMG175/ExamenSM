#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}

float Principal::calcular()
{

    float imc;
    QString m, h, altura;
    float mf, hf;

    h=ui->inAltura->text();
    m=ui->inPeso->text();

     mf=m.toFloat();
     hf=h.toFloat();

     imc = mf/(hf*hf);

     if(imc<18.5){
     ui->outEstado->setText("Peso inferior al normal");
     }else if (imc <24.9){
       ui->outEstado->setText("Peso normal");
     }else if( imc < 29.9){
     ui->outEstado->setText("Sobrepeso");
     }else if(imc>=30){
       ui->outEstado->setText("Obesidad");
     }


      altura = hf*100;
      ui->outPActual->setText(altura);

 return imc;

}

void Principal::validacion()
{

    if(ui->inAltura->text().isEmpty()){
        QMessageBox::warning(this,"Calculadora","Debe ingresar su altura");

    }else if(ui->inPeso->text().isEmpty()){
             QMessageBox::warning(this,"Calculadora","Debe ingresar su peso");
    }
}

void Principal::limpiarDatos()
{
     ui->inAltura->setText("");
     ui->inPeso->setText("");
}



void Principal::on_cmdGenerar_pressed()
{
    ui->imc1->setText(QString::number(calcular()));
    validacion();

    ui->outActual->setText(ui->inPeso->text());
    ui->outMax->setText(ui->inPeso->text());
    ui->outMin->setText(ui->inPeso->text());

    limpiarDatos();
}
