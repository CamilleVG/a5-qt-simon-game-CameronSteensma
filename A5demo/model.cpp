#include "model.h"
#include <iostream>

model::model(QObject *parent) : QObject(parent)
{
    data =4;
}

void model::startGame(){
    data+=1;
    emit deactivateStartButton();
    int numMoves = 1;
    while (numMoves > 0)
    {
         int colorData = arc4random() % 2;//arc4random is better randGenerator than rand
         moveList.push_back(colorData);
         numMoves--;
    }
    int time = 1000;
    for (int color: moveList)
    {
        switch(color)
        {
        case(0):
            QTimer::singleShot(time, this, &model::flashRed);
            //emit sequenceRed("background-color: red");
            time+=500;
            //color is red, emit signal to turn SEQUENCE LABEL red OR to highlight redButton
            QTimer::singleShot(time, this, &model::revertToDefault);
            time+=1000;
            break;
        case(1):
            //color is blue, emit signal to turn SEQUENCE LABEL blue OR to highlight blueButton
            /* Replace timer start w/ singleshot 3 arg parameter calls */
            QTimer::singleShot(time, this, &model::flashBlue);
            //emit sequenceBlue("background-color: blue");
            time+=500;
            QTimer::singleShot(time, this, &model::revertToDefault);
            time+=1000;
            break;
        }
    }

    timer+= 5000;
    QTimer::singleShot(time, this, &model::checkMovesList);
    //generate number between 0 and 1 inclusive to define the sequence
    //make startButton inactive until game is lost or restarted
    //emit updateSpinBox(data);
    //std::cout << "data is " << data << std::endl;
}
void model::checkMovesList(){
    if (moveList.empty()){
        emit activateStartButton();
    }
}
void model::checkRed(){
        int expected = moveList[0];
        moveList.pop_front();
        if (expected != 0){
            emit lostGame();
            emit activateStartButton();
        }
}

void model::checkBlue(){
        int expected = moveList[0];
        moveList.pop_front();
        if (expected != 1){
            emit lostGame();
            emit activateStartButton();
        }
}

void model::flashRed(){
    emit revertBlue("background-color:rgb(173, 216, 230)");
    emit highlightRed("background-color: red");

}

void model::flashBlue(){
    emit revertRed("background-color:rgb(255, 203, 204)");
    emit highlightBlue("background-color: blue");
}

void model::revertToDefault(){
      emit revertRed("background-color:rgb(255, 203, 204)");
      emit revertBlue("background-color:rgb(173, 216, 230)");
}

void model::timerSlot(){

   std::cout << "Timer...";
}
