#ifndef SERVICES_H
#define SERVICES_H

#include <QObject>
#include "src/servicehistory.h"
#include "src/servicehttp.h"
#include "src/streamdata.h"
#include "src/databaseparser.h"
#include "src/requestconverter.h"
#include "fakeservicehistory.h"
#include "fakeservicehttp.h"
class ServicesT;
class ServicesTDestroyer
{
public:
    ~ServicesTDestroyer();
    void init(ServicesT* services);
private:
    ServicesT* instance;
};

class ServicesT : public QObject
{
    Q_OBJECT
public:
    static ServicesT& Instance();

    void transalate(QString langFrom,QString langTo,QString sourceText);
    bool deleteAll();
    bool deleteRow(int id);
    ListElementhistory readAll();
signals:
    void addedAnswer();
public slots:
private slots:
    void receivedTranslatedText(QNetworkReply* reply);
private:
    IServiceHttp* serviceHttp;
    IServiceHistory* serviceHistory;
    StreamData* streamData;

    RequestConverter converter;
    DatabaseParser parser;

    static ServicesT* services;
    static ServicesTDestroyer destroyer;
protected:
    explicit ServicesT(QObject *parent = nullptr);
    friend class ServicesTDestroyer;
    ServicesT(const ServicesT&);
    ServicesT& operator =(ServicesT&);
    ~ServicesT(){}
};

#endif // SERVICES_H
