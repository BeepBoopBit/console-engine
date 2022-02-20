#include "../include/consoleScreen.h"
#include "../include/observer.h"
#include "../include/consoleEntity.h"

void printCurrent(CE::ConsoleEntity *entity){
    std::cout << "Current: (";
    std::cout << entity->getCurrentX() << ", " << entity->getCurrentY() << ")\n";
}

void printPrevious(CE::ConsoleEntity *entity){
    std::cout << "Previous: (";
    std::cout << entity->getPreviousX() << ", " << entity->getPreviousY() << ")\n";
}

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

    std::cout << std::endl;
    printCurrent(SnakeHead);
    printCurrent(SnakeBody00);
    printCurrent(SnakeBody01);
    printPrevious(SnakeHead);
    printPrevious(SnakeBody00);
    printPrevious(SnakeBody01);
    std::cout << std::endl;


    WholeSnake.moveDown(2);
    mainScreen->print();

    std::cout << std::endl;
    printCurrent(SnakeHead);
    printCurrent(SnakeBody00);
    printCurrent(SnakeBody01);
    printPrevious(SnakeHead);
    printPrevious(SnakeBody00);
    printPrevious(SnakeBody01);
    std::cout << std::endl;

    
    return 0;
}