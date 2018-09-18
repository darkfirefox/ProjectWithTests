#include "servicesT.h"
ServicesT* ServicesT::services=0;
ServicesTDestroyer ServicesT::destroyer;

ServicesT::ServicesT(QObject *parent) : QObject(parent)
{
    serviceHistory=new FakeServiceHistory();
    serviceHttp=new FakeServiceHTTP();
    streamData=&StreamData::Instance();
    connect(this,SIGNAL(addedAnswer()),streamData,SLOT(lastWasTrasnalate()));
    connect(dynamic_cast<QObject*>(serviceHttp),SIGNAL(receiveAnswer(QObject*)),this,SLOT(receivedTranslatedText(QObject*)));
}

ServicesT &ServicesT::Instance()
{
    if(!services){
        services=new ServicesT();
        destroyer.init(services);
    }
    return *services;
}

void ServicesT::transalate(QString langFrom, QString langTo, QString sourceText)
{
    serviceHttp->sendRequest(converter.toString(langFrom,langTo,sourceText));
    *streamData<<langFrom<<langTo<<sourceText;
}

bool ServicesT::deleteAll()
{
    return serviceHistory->deleteAll();
}

bool ServicesT::deleteRow(int id)
{
    return serviceHistory->deleteRow(id);
}

ListElementhistory ServicesT::readAll()
{
    ListElementhistory leh=parser.fromListRecords(serviceHistory->readAll());
    return leh;
}

void ServicesT::receivedTranslatedText(QObject *reply)
{
    QString res="response";
        *streamData<<res;
        emit addedAnswer();
}

ServicesTDestroyer::~ServicesTDestroyer()
{
    delete instance;
}

void ServicesTDestroyer::init(ServicesT *services)
{
    instance=services;
}
