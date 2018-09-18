#ifndef SERVICES_H
#define SERVICES_H

#include <QObject>
#include "servicehistory.h"
#include "servicehttp.h"
#include "streamdata.h"
#include "databaseparser.h"
#include "requestconverter.h"
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
    void deleteAll();
    void deleteRow(int id);
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

    static Services* services;
    static ServicesDestroyer destroyer;
protected:
    explicit Services(QObject *parent = nullptr);
    friend class ServicesDestroyer;
    Services(const Services&);
    Services& operator =(Services&);
    ~Services(){}
};

#endif // SERVICES_H
