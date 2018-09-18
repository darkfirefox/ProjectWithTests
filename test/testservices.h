#ifndef TESTSERVICES_H
#define TESTSERVICES_H

#include <QObject>
#include <QTest>
#include "servicesT.h"

class TestServices : public QObject
{
    Q_OBJECT
private:
    ServicesT* services;
    StreamData* stream;
private slots:
    void init();
    void translate();
    void deleteRow();
    void deleteAll();
    void readAll();
};

#endif // TESTSERVICES_H
