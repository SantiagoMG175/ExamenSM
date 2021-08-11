#include "principal.h"

#include <QApplication>
#include <QInputDialog>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList idiomas;
    idiomas << "Italiano (IT)" << "Español (ECU)";
    QString idiomaSel = QInputDialog::getItem(NULL, "Idioma", "Seleccione el idioma", idiomas);
    QTranslator traduccion;
    if(idiomaSel == "Italiano (IT)")
    {
        traduccion.load(":/traducciones/examen_santiago_mino_it_IT.qm");
    }else

    {
        traduccion.load(":/traducciones/examen_santiago_mino_es_EC.qm");
    }

    a.installTranslator(&traduccion);
    Principal w;
    w.show();
    return a.exec();
}
