#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QMap>
#include <QDataStream>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    void fill();
    QString name();
    void setName(const QString& value);
    QMap<QString, QString> map();
    void setMap(QMap<QString, QString> newMap); //recebe um novo mapa pra setar

    //para acessar partes privadas da classe | não é membro
    friend QDataStream& operator<<(QDataStream &stream, const Test &t)
    {
        qInfo() << "Operator <<";
        //stream, que chama a função (não é objeto da classe (this) pra modificar),
        //por isso a func n pode ser membro.
        stream << t.m_name;
        stream << t.m_map;
        return stream;
    }

    friend QDataStream& operator>>(QDataStream &stream, Test &t)
    {
        qInfo() << "Operator >>";
        stream >> t.m_name;
        stream >> t.m_map;
        return stream;
    }

signals:

private:
    QString m_name;
    QMap<QString, QString> m_map;
};

#endif // TEST_H
