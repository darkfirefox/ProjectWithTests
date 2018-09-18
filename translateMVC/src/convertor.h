#ifndef CONVERTOR_H
#define CONVERTOR_H
#include <QString>
#include "answer.h"
#include "inputdata.h"
class Convertor
{
public:
    Convertor();

    InputData toInputData(QString langFrom,QString langTo, QString textFrom);
    Answer toAnswer(QString answer);
};

#endif // CONVERTOR_H
