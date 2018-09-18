#include "answer.h"

Answer::Answer()
{

}

void Answer::setAnswer(QString _answer)
{
    answer=_answer;
}

QString Answer::getAnswer() const
{
    return answer;
}
