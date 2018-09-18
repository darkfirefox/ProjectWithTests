#ifndef STREAMDATA_H
#define STREAMDATA_H

#include <QObject>
#include "inputdata.h"
#include "answer.h"

class StreamData;
class StreamDataDestroyer
{
public:
   ~StreamDataDestroyer();
    void init(StreamData* streamData);
private:
    StreamData* instance;
};
class StreamData : public QObject
{
    Q_OBJECT
public:
    static StreamData &Instance();

    InputData getInputData();
    Answer getAnswer();
signals:
    void inputDataIs();
    void answerIs();
public slots:
    void writeInputData(InputData _input);
    void writeAnswer(Answer _answer);
private:
    InputData inputData;
    Answer answer;

    static StreamData* stream;
    static StreamDataDestroyer destroyer;
protected:
    explicit StreamData(QObject *parent = nullptr);
    friend class StreamDataDestroyer;
    StreamData(const StreamData&);
    StreamData& operator =(StreamData&);
    ~StreamData(){}
};

#endif // STREAMDATA_H
