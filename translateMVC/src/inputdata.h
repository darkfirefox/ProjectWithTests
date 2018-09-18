#ifndef INPUTDATA_H
#define INPUTDATA_H
#include <QString>

class InputData
{
public:
    InputData();

    void setLangFrom(QString _langFrom);
    void setLangTo(QString _langTo);
    void setTextFrom(QString _textFrom);

    QString getLangFrom() const;
    QString getLangTo() const;
    QString getTextFrom() const;
private:
    QString langFrom;
    QString langTo;
    QString textFrom;
};

#endif // INPUTDATA_H
