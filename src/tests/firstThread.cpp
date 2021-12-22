#include "../../include/consoleScreen.h"
#include "../../include/consoleEnvironment.h"
#include "../../include/consoleEnvironmentHandler.h"


#include <random>

void sleepFor(int x){
    std::chrono::milliseconds timespan(x); 
    std::this_thread::sleep_for(timespan);
}

CE::RigidBody *createNewBody(int x, int y, char chr,  CE::ConsoleScreen *screen){
    return new CE::RigidBody(screen,chr,x,y);
}


void callMoveX(CE::ConsoleEnvironmentHandler *_head, CE::ConsoleEnvironmentHandler *_body, int n){
    for(int i = 0; i < (_body->getEnvironment()).size(); ++i){
        int bodyPosX = _body->getEnvironment()[i]->getPosX(),
            headPosX = _head->getEnvironment()[0]->getPosX(),
         bodyPosY = _body->getEnvironment()[i]->getPosY(),
            headPosY = _head->getEnvironment()[0]->getPosY(); 
        if((bodyPosX == headPosX) && (bodyPosY == headPosY)){
            _head->addFront(_body->getEnvironment()[i]); // add
            _body->getEnvironment()[i]->setPositionStart(headPosX - 1,headPosY); // reposition
            _body->remove(_body->getEnvironment()[i]);
            break;
        }
    }
    _head->moveX(n);
    sleepFor(700);
}
void callMoveY(CE::ConsoleEnvironmentHandler *_head, CE::ConsoleEnvironmentHandler *_body, int n){
    for(int i = 0; i < (_body->getEnvironment()).size(); ++i){
        int bodyPosX = _body->getEnvironment()[i]->getPosX(),
            headPosX = _head->getEnvironment()[0]->getPosX(),
            bodyPosY = _body->getEnvironment()[i]->getPosY(),
            headPosY = _head->getEnvironment()[0]->getPosY(); 
        if((bodyPosX == headPosX) && (bodyPosY == headPosY)){
            _head->addFront(_body->getEnvironment()[i]); // add
            _body->getEnvironment()[i]->setPositionStart(headPosX,headPosY-1); // reposition
        }
    }
    _head->moveY(n);
    sleepFor(700);
}

void getMove(int *direction){
    while(true){
        char userInput = ' ';
        userInput = _getwch();
        if(userInput == 'a'){
            *direction = 0;
        } else if(userInput == 'w'){
            *direction = 1;
        } else if(userInput == 'd'){
            *direction = 2;
        } else if(userInput == 's'){
            *direction = 3;
        }else{
            *direction = 0;
        }
        sleepFor(700);
    }
}

void createRandomHeads(CE::ConsoleEnvironmentHandler *_handler, CE::ConsoleScreen *mainScreen, int amount){
    
    for(int i = 0; i < amount; ++i){
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> x(0,19); // distribution in range [1, 6]
        std::uniform_int_distribution<std::mt19937::result_type> y(0,9); // distribution in range [1, 6]
        _handler->add(createNewBody(x(rng),y(rng),'P',mainScreen));
    }
}

int main(){
    CE::ConsoleScreen mainScreen(20,10,0,0,'#');
    bool inGame = true;
    
    CE::RigidBody _head(&mainScreen,'P',0,0);
    CE::ConsoleEnvironmentHandler _headHandler;
    _headHandler.add(&_head);

    CE::ConsoleEnvironmentHandler _aroundBody;
    //createRandomHeads(&_aroundBody, &mainScreen, 1);
    _aroundBody.add(createNewBody(5,4,'P',&mainScreen));


    int _direction = 2, *valueDirection = new int(1);
    void (*p)(CE::ConsoleEnvironmentHandler *_handle, CE::ConsoleEnvironmentHandler *_body, int n) = callMoveX;
    std::thread _thread02(getMove,&_direction);
    while(inGame){ // 0 - left ; 1 - up; 2 - right ; 3 - down
        p(&_headHandler, &_aroundBody, *valueDirection);
        if(_direction == 0){ // left
            p = callMoveX;
            *valueDirection = -1;
        }else if(_direction == 1){ // up
            p = callMoveY;
            *valueDirection = -1;
        }else if(_direction == 2){ // right
            p = callMoveX;
            *valueDirection = 1;
        }else{ // down
            p = callMoveY;
            *valueDirection = 1;
        }
        mainScreen.print();
        sleepFor(700);
    }
}