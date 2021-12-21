#include "../../include/consoleScreen.h"
#include "../../include/consoleEnvironment.h"
#include "../../include/consoleEnvironmentHandler.h"

void sleepFor(int x){
    std::chrono::milliseconds timespan(x); 
    std::this_thread::sleep_for(timespan);
}

CE::RigidBody *createNewBody(int x, int y, char chr,  CE::ConsoleScreen *screen){
    return new CE::RigidBody(screen,chr,x,y);
}


void callMoveX(CE::ConsoleEnvironmentHandler *_handle, int n){
    _handle->moveX(n);
}
void callMoveY(CE::ConsoleEnvironmentHandler *_handle, int n){
    _handle->moveY(n);
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
    }
}

int main(){
    CE::ConsoleScreen mainScreen(20,10,0,0,'#');
    bool inGame = true;
    
    CE::RigidBody _head(&mainScreen,'P',0,0);
    CE::ConsoleEnvironmentHandler _handler;
    _handler.add(&_head);

    int _direction = 2;
    int *valueDirection = new int(1);
    void (*p)(CE::ConsoleEnvironmentHandler *_handle, int n) = callMoveX;
    std::thread _thread02(getMove,& _direction);
    while(inGame){ // 0 - left ; 1 - up; 2 - right ; 3 - down
        p(&_handler, *valueDirection);
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
        sleepFor(600);
    }
}