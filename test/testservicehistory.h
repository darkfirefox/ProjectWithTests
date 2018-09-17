#ifndef TESTSERVICEHISTORY_H
#define TESTSERVICEHISTORY_H

#include <QObject>
#include "fakeservicehistory.h"
class TestServiceHistory : public QObject
{
    Q_OBJECT
private:
    FakeServiceHistory* service;
private slots:
    void init();
    void readAll();
    void insertRow();
    void deleteRow();
    void deleteAll();
};

#endif // TESTSERVICEHISTORY_H
