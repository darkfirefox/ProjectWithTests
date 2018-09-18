#ifndef SERVICES_H
#define SERVICES_H

#include <QObject>
#include "servicehistory.h"
#include "servicehttp.h"
#include "streamdata.h"
#include "databaseparser.h"
#include "requestconverter.h"
#include "convertor.h"
class Services;
class ServicesDestroyer
{
public:
    ~ServicesDestroyer();
    void init(Services* services);
private:
    Services* instance;
};

class Services : public QObject
{
    Q_OBJECT
public:
    static Services& Instance();

    void transalate(QString langFrom,QString langTo,QString sourceText);
    bool deleteAll();
    bool deleteRow(int id);
    ListElementhistory readAll();

    void setService(IServiceHistory* service);
    void setService(IServiceHttp* service);
signals:
    void writeInputData(InputData inputData);
    void writeAnswer(Answer answer);
public slots:
private slots:
    void receivedTranslatedText(QNetworkReply* reply);
private:
    IServiceHttp* serviceHttp;
    IServiceHistory* serviceHistory;
    StreamData* streamData;

    RequestConverter converter;
    DatabaseParser parser;
    Convertor conv;

    static Services* services;
    static ServicesDestroyer destroyer;
protected:
    explicit Services();
    friend class ServicesDestroyer;
    Services(const Services&);
    Services& operator =(Services&);
    ~Services(){}
};

#endif // SERVICES_H
