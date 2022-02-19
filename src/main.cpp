#include "../include/consoleScreen.h"
#include "../include/observer.h"
#include "../include/consoleEntity.h"


int main(){
    CE::ConsoleScreen *mainScreen = new CE::ConsoleScreen(10,10,'#');
    CE::Observer *mainObserver = new CE::Observer(mainScreen);
    CE::ConsoleEntity *SnakeHead = new CE::ConsoleEntity(mainObserver,'P', 5, 0);
    CE::ConsoleEntity *SnakeBody00 = new CE::ConsoleEntity(mainObserver,'O', 4,0);
    CE::ConsoleEntity *SnakeBody01 = new CE::ConsoleEntity(mainObserver,'O', 3,0);
    CE::ConsoleEntityHandler WholeSnake;
    WholeSnake.attach(SnakeHead);
    WholeSnake.attach(SnakeBody00);
    WholeSnake.attach(SnakeBody01);
    mainScreen->print();
    WholeSnake.moveDown(2);
    std::cout << std::endl;
    mainScreen->print();

    
    return 0;
}