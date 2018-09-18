#include "services.h"
Services* Services::services=0;
ServicesDestroyer Services::destroyer;

Services::Services(QObject *parent) : QObject(parent)
{
    serviceHistory=new ServiceHistory();
    serviceHttp=new ServiceHTTP();
    streamData=&StreamData::Instance();
    connect(this,SIGNAL(addedAnswer()),streamData,SLOT(lastWasTrasnalate()));
    connect(dynamic_cast<QObject*>(serviceHttp),SIGNAL(receiveAnswer(QNetworkReply*)),this,SLOT(receivedTranslatedText(QNetworkReply*)));
}

Services &Services::Instance()
{
    if(!services){
        services=new Services();
        destroyer.init(services);
    }
    return *services;
}

void Services::transalate(QString langFrom, QString langTo, QString sourceText)
{
    serviceHttp->sendRequest(converter.toString(langFrom,langTo,sourceText));
    *streamData<<langFrom<<langTo<<sourceText;
}

void Services::deleteAll()
{
    serviceHistory->deleteAll();
}

void Services::deleteRow(int id)
{
    serviceHistory->deleteRow(id);
}

ListElementhistory Services::readAll()
{
    ListElementhistory leh=parser.fromListRecords(serviceHistory->readAll());
    return leh;
}

void Services::receivedTranslatedText(QNetworkReply *reply)
{
    QString response=converter.translatedFromReply(reply);
    if(response.isEmpty()) streamData->clear();
    else{
        *streamData<<response;
        emit addedAnswer();
        serviceHistory->insertRow(parser.fromStringList(streamData->readAll()));
    }
}

ServicesDestroyer::~ServicesDestroyer()
{
    delete instance;
}

void ServicesDestroyer::init(Services *services)
{
    instance=services;
}
