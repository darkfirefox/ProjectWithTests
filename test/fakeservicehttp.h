#ifndef FAKESERVICEHTTP_H
#define FAKESERVICEHTTP_H
#include "src/iservicehtttp.h"

class FakeServiceHTTP : public IServiceHttp
{
public:
    FakeServiceHTTP();
    void sendRequest(QString url);
};

#endif // FAKESERVICEHTTP_H
