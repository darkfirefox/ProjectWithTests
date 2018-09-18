#include "convertor.h"

Convertor::Convertor()
{

}

InputData Convertor::toInputData(QString langFrom, QString langTo, QString textFrom)
{
    InputData id;
    id.setLangFrom(langFrom);
    id.setLangTo(langTo);
    id.setTextFrom(textFrom);
    return id;
}

Answer Convertor::toAnswer(QString answer)
{
    Answer an;
    an.setAnswer(answer);
    return an;
}
