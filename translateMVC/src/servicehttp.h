#ifndef SERVICEHTTP_H
#define SERVICEHTTP_H

#include <QString>
#include <QObject>
#include <QNetworkReply>
#include "networkmanager.h"
#include "iservicehtttp.h"
class ServiceHTTP : public QObject,public IServiceHttp
{
    Q_OBJECT
public:
    explicit ServiceHTTP(QObject *parent = nullptr);

    void sendRequest(QString url);
signals:
    void  receiveAnswer(QNetworkReply* reply);
private slots:
    void receiveReply(QNetworkReply* reply);
private:
    NetworkManager* network;
    QString response;
};

#endif // SERVICEHTTP_H
