#include "model.h"
#include <iostream>

model::model(QObject *parent) : QObject(parent)
{
    data =0;
}

void model::startGame(){
    data+=1;
    //deactivateStartButton();
    int numMoves = 1;
    while (numMoves > 0)
    {
         int colorData = arc4random() % 2;//arc4random is better randGenerator than rand
         moveList.push_back(colorData);
         numMoves--;
    }
    int time = 500;
    for (int color: moveList)
    {
        switch(color)
        {
        case(0):
            timer->singleShot(time, this, model::sequenceRed);
            emit sequenceRed("background-color: red");
            time+=500;
            //color is red, emit signal to turn SEQUENCE LABEL red OR to highlight redButton
            break;
        case(1):
            //color is blue, emit signal to turn SEQUENCE LABEL blue OR to highlight blueButton
            /* Replace timer start w/ singleshot 3 arg parameter calls */
            timer->start(time);
            emit sequenceBlue("background-color: blue");
            time+=500;
            break;
        }
    }


    //generate number between 0 and 1 inclusive to define the sequence
    //make startButton inactive until game is lost or restarted
    emit updateSpinBox(data);
    //std::cout << "data is " << data << std::endl;
}

void model::timerSlot(){

   std::cout << "Timer...";
}
