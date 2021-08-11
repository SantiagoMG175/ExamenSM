#ifndef TABLA_H
#define TABLA_H

#include <QMainWindow>
#include "principal.h"

namespace Ui {
class Tabla;
}

class Tabla : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tabla(QWidget *parent = nullptr);
    ~Tabla();

     QString datos();
     void escribir(QString data);


private:
     Ui::Tabla *ui;

};

#endif // TABLA_H
