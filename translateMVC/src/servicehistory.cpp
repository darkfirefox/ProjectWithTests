#include "servicehistory.h"
ServiceHistory* ServiceHistory::service=0;
ServiceHistoryDestroyer ServiceHistory::destroyer;


ServiceHistory::ServiceHistory(QObject *parent) : QObject(parent)
{
    db.init();
    stream=&StreamData::Instance();
    connect(stream,SIGNAL(readyToStore()),this,SLOT(storeDataFromStream()));
}

bool ServiceHistory::deleteAll()
{
    return db.deleteAll();
}

bool ServiceHistory::deleteRow(int id)
{
    return db.deleteRow(id);
}

bool ServiceHistory::insertRow(QString langFrom,QString langTo,QString textFrom,QString textTo)
{
    return db.insertRow(parser.fromStrings(langFrom,langTo,textFrom,textTo));
}

ListElementhistory ServiceHistory::readAll()
{
    ListRecords recs = db.readAll();
    qDebug()<<"readed all";
    ListElementhistory list;
    for(int i=0;i<recs.size();i++){
        list.add(parser.fromRecord(recs.getAt(i)));
    }
    return list;
}

ServiceHistory &ServiceHistory::Instance()
{
    if(!service){
        service=new ServiceHistory();
        destroyer.init(service);
    }
    return *service;
}

void ServiceHistory::storeDataFromStream()
{
    db.insertRow(parser.fromStringList(stream->readAll()));
}

ServiceHistoryDestroyer::~ServiceHistoryDestroyer()
{
    delete instance;
}

void ServiceHistoryDestroyer::init(ServiceHistory *service)
{
    instance=service;
}
