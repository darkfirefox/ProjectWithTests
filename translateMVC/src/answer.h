#ifndef ANSWER_H
#define ANSWER_H
#include <QString>

class Answer
{
public:
    Answer();

    void setAnswer(QString _answer);
    QString getAnswer() const;
private:
    QString answer;
};

#endif // ANSWER_H
