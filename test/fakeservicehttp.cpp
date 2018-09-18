#include "fakeservicehttp.h"

FakeServiceHTTP::FakeServiceHTTP()
{

}

void FakeServiceHTTP::sendRequest(QString url)
{
    QNetworkAccessManager* nam=new QNetworkAccessManager();
    emit receiveAnswer(nam->get(QNetworkRequest(QUrl(url))));
}
