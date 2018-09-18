#ifndef ISERVICEHISTORY_H
#define ISERVICEHISTORY_H
class ListRecords;
class ElementHistory;
class IServiceHistory{
public:
    virtual bool deleteAll()=0;
    virtual bool deleteRow(int id)=0;
    virtual bool insertRow(ElementHistory element)=0;
    virtual ListRecords readAll()=0;
};

#endif // ISERVICEHISTORY_H
