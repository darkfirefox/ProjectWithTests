#include "servicehttp.h"

ServiceHTTP::ServiceHTTP(QObject *parent) : QObject(parent)
{
    network=new NetworkManager();
    connect(network,SIGNAL(receivedResponse(QNetworkReply*)),this,SLOT(receiveReply(QNetworkReply*)));
}

void ServiceHTTP::sendRequest(QString url)
{
    network->sendPostRequest(url);
}

void ServiceHTTP::receiveReply(QNetworkReply *reply)
{
    emit receiveAnswer(reply);
}
