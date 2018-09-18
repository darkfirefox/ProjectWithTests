#ifndef FAKESERVICEHTTP_H
#define FAKESERVICEHTTP_H
#include <QObject>
#include "src/iservicehtttp.h"
#include <QNetworkReply>

class FakeServiceHTTP : public QObject,public IServiceHttp
{
    Q_OBJECT
public:
    FakeServiceHTTP();
    void sendRequest(QString url);
signals:
    void  receiveAnswer(QObject* reply);
};

#endif // FAKESERVICEHTTP_H
