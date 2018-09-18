#include "inputdata.h"

InputData::InputData()
{

}

void InputData::setLangFrom(QString _langFrom)
{
    langFrom=_langFrom;
}

void InputData::setLangTo(QString _langTo)
{
    langTo=_langTo;
}

void InputData::setTextFrom(QString _textFrom)
{
    textFrom=_textFrom;
}

QString InputData::getLangFrom() const
{
    return langFrom;
}

QString InputData::getLangTo() const
{
    return langTo;
}

QString InputData::getTextFrom() const
{
    return textFrom;
}
