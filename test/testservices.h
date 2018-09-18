#ifndef TESTSERVICES_H
#define TESTSERVICES_H

#include <QObject>
#include <QTest>
#include "src/services.h"
#include <QSignalSpy>
#include "fakeservicehistory.h"
#include "fakeservicehttp.h"

class TestServices : public QObject
{
    Q_OBJECT
private:
    Services* services;
    StreamData* stream;
private slots:
    void init();
    void translate();
    void deleteRow();
    void deleteAll();
    void readAll();
};

#endif // TESTSERVICES_H
