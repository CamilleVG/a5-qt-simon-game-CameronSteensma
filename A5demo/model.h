#ifndef MODEL_H
#define MODEL_H
#include <QObject>
#include <QTimer>

class model : public QObject
{
    Q_OBJECT
public:
    explicit model(QObject *parent = nullptr);
    QTimer* timer;
signals: //define signals to be emitted from FORM objects
    void updateSpinBox(int);
    void sequenceRed(const QString);
    void sequenceBlue(const QString);

public slots://add slots here for functionality of FORM objects
    void startGame();//Implement slot in model.cpp
    void timerSlot();


private:
    int data;
    QVector<int> moveList;
};

#endif // MODEL_H
