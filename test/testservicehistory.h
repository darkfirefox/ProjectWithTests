#ifndef TESTSERVICEHISTORY_H
#define TESTSERVICEHISTORY_H

#include <QObject>
#include "src/servicehistory.h"
class TestServiceHistory : public QObject
{
    Q_OBJECT
private:
    ServiceHistory* service;
private slots:
    void init();
    void readAll();
    void insertRow();
    void deleteRow();
    void deleteAll();
};

#endif // TESTSERVICEHISTORY_H
