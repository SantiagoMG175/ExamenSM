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

void Principal::altura()

{
   hf=h.toFloat() * 100;

  ui->outAlturaA->setText(QString::number(hf)+".0 cm");

}


void Principal::on_cmdGenerar_pressed()
{
    ui->outIMC->setText(QString::number(calcular()));
    validacion();

    ui->outActual->setText(ui->inPeso->text());
    ui->outMax->setText(ui->inPeso->text());
    ui->outMin->setText(ui->inPeso->text());

    limpiarDatos();
    altura();

}
QString Principal::datos()
{
    time_t t;
        char fecha[100];
        struct tm *tm;
        t=time(NULL);
        tm=localtime(&t);
        strftime(fecha, 100, "%d/%m/%Y     %H:%M:%S ", tm);

   QString str;

   str = "Altura: " + h + " m"+ "\n" +
         "Peso: " + m + " Kg" + "\n" +
         "Fecha: " + fecha + "\n";

   return str;
}


void Principal::on_cmdDatos_released()
{

    Tabla *tabla = new Tabla();
    tabla->show();
    tabla->escribir(datos());


}

QString Principal::getH() const
{
    return h;
}

QString Principal::getM() const
{
    return m;
}
