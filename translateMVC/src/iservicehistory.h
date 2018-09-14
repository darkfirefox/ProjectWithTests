#ifndef ISERVICEHISTORY_H
#define ISERVICEHISTORY_H
class ListElementhistory;
class IServiceHistory{
public:
    virtual bool deleteAll()=0;
    virtual bool deleteRow(int id)=0;
    virtual bool insertRow(QString langFrom,QString langTo,QString textFrom,QString textTo)=0;
    virtual ListElementhistory readAll()=0;
};

#endif // ISERVICEHISTORY_H
