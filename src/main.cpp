#include "../include/consoleScreen.h"
#include "../include/observer.h"
#include "../include/consoleEntity.h"


int main(){
    CE::ConsoleScreen *mainScreen = new CE::ConsoleScreen(10,10,'#');
    CE::Observer *mainObserver = new CE::Observer(mainScreen);
    CE::ConsoleEntity SnakeHead(mainObserver,'P');
    SnakeHead.moveDown(3);
    mainScreen->print();

    
    return 0;
}