#include <QCoreApplication>
#include <QDebug>
#include "test.h"
#include "converter.h"

void writeJson(QString path)
{
    Test t;
    t.fill();
    //o obj t (que contém o Json preenchido) é passado por referência, junto com o path do file
    Converter::writeJson(&t, path);
}

void readJson(QString path)
{
    Test *t;
    //Arquivo Json preenchido é enviado para ser lido
    t = Converter::readJson(path);

    if(!t)
    {
        qInfo() << "Object not loaded!";
        return;
    }

    //lendo propriedade name
    qInfo() << "Name:" << t->name();
    //lendo map
    foreach(QString key, t->map().keys())
    {
        qInfo() << key << " : " << t->map().value(key);
    }
}

void writeXML(QString path)
{
    Test t;
    t.fill();
    //o obj t (que contém o XML preenchido) é passado por referência, junto com o path do file
    Converter::writeXml(&t, path);
}

void readXML(QString path)
{
    Test *t;
    //Arquivo XML preenchido é enviado para ser lido
    t = Converter::readXml(path);

    if(!t)
    {
        qInfo() << "Object not loaded!";
        return;
    }

    //lendo propriedade name
    qInfo() << "Name:" << t->name();
    //lendo map
    foreach(QString key, t->map().keys())
    {
        qInfo() << key << " : " << t->map().value(key);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "test.txt";

    //writeJson(path);
    //readJson(path);

    writeXML(path);
    readXML(path);

    return a.exec();
}
