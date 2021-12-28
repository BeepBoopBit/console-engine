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


void createRandomHeads(CE::ConsoleEnvironmentHandler *_handler, CE::ConsoleScreen *mainScreen, int amount){
    for(int i = 0; i < amount; ++i){
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> x(0,19); // distribution in range [1, 6]
        std::uniform_int_distribution<std::mt19937::result_type> y(0,9); // distribution in range [1, 6]
        _handler->add(createNewBody(x(rng),y(rng),'P',mainScreen));
    }
}

char getMove(char *val){
    while(true){
        *val = _getwch();
    }
}
void moveUp(CE::RigidBody *_head){
    _head->moveY(-1);
}
void moveLeft(CE::RigidBody *_head){
    _head->moveX(-1);
}
void moveDown(CE::RigidBody *_head){
    _head->moveY(1);
}
void moveRight(CE::RigidBody *_head){
    _head->moveX(1);
}

// We need some sort of "ATTACH" Functions

void foodEat(CE::RigidBody *_head, CE::ConsoleEnvironmentHandler *_body,std::map<int, std::pair<int,int>> foodIndexMap){
    
    while(true){
        int headX = _head->getPosX(),
            headY = _head->getPosY();
        auto search = foodIndexMap.find(headY);
        // pair -> indexBody, index_X
        if((search != foodIndexMap.end()) && (search->second.second == headY)){
            _body->getEnvironment(search->second.first)->setPosition(headX, headY);
        }
    }
    
}

int main(){
    CE::ConsoleScreen mainScreen(20,10,0,0,'#');    
    CE::RigidBody _head(&mainScreen,'P',0,0);
    CE::ConsoleEnvironmentHandler _body;

    CE::ConsoleEnvironmentHandler _aroundBody;
    //createRandomHeads(&_aroundBody, &mainScreen, 1);
    _aroundBody.add(createNewBody(5,4,'P',&mainScreen));

    // food Index should be sorted?
    std::map<int, int> foodIndexMap;
    foodIndexMap[4] = 5;

    char *userInput = new char('d');

    std::thread movement(getMove, userInput);
    movement.detach();

    while(true){
        if(*userInput == 'w'){
            moveUp(&_head);
        }else if(*userInput == 'a'){
            moveLeft(&_head);
        }else if(*userInput == 's'){
            moveDown(&_head);
        }else if(*userInput == 'd'){
            moveRight(&_head);
        }
        mainScreen.print();
        sleepFor(200);
    }


    
}