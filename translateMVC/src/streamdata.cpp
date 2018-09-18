#include "streamdata.h"
StreamData* StreamData::stream=0;
StreamDataDestroyer StreamData::destroyer;

StreamData &StreamData::Instance()
{
    if(!stream){
        stream=new StreamData();
        destroyer.init(stream);
    }
    return *stream;
}

InputData StreamData::getInputData()
{
    return inputData;
}

Answer StreamData::getAnswer()
{
    return answer;
}

void StreamData::writeInputData(InputData _input)
{
    inputData=_input;
    emit inputDataIs();
}

void StreamData::writeAnswer(Answer _answer)
{
    answer=_answer;
    emit answerIs();
}

StreamData::StreamData(QObject *parent) : QObject(parent)
{

}

StreamDataDestroyer::~StreamDataDestroyer()
{
    delete instance;
}

void StreamDataDestroyer::init(StreamData *streamData)
{
    instance=streamData;
}
