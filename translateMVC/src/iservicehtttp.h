#ifndef ISERVICEHTTTP_H
#define ISERVICEHTTTP_H
class IServiceHttp
{
public:
   virtual void sendRequest(QString url)=0;
};
#endif // ISERVICEHTTTP_H
