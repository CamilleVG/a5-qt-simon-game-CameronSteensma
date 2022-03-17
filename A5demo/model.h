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
    void checkRed();
    void checkBlue();

signals: //define signals to be emitted from FORM objects
    void updateSpinBox(int);
    void highlightRed(const QString);
    void highlightBlue(const QString);
    void revertRed(const QString);
    void revertBlue(const QString);
    void deactivateStartButton();
    void activateStartButton();
    void lostGame();



public slots://add slots here for functionality of FORM objects
    void startGame();//Implement slot in model.cpp
    void timerSlot();


private:
    int data;
    QVector<int> moveList;
    void flashRed();
    void flashBlue();
    void revertToDefault();

    void checkMovesList();
};

#endif // MODEL_H
