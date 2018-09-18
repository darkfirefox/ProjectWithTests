#include "fakeservicehttp.h"

FakeServiceHTTP::FakeServiceHTTP()
{

}

void FakeServiceHTTP::sendRequest(QString url)
{
    QObject *ob;
    emit receiveAnswer(ob);
}
