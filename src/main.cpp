#include "../include/consoleScreen.h"
#include "../include/consoleEnvironment.h"

CE::ConsoleScreen mainScreen(5,5, '#');
CE::ConsoleEnvironment Tree(&mainScreen,'o',"water");


void testHorizontal(){
    Tree.fillHorizontal(0,5,0); // x1, x2, y
    Tree.fillHorizontal(1,5,1); // x1, x2, y
    Tree.fillHorizontal(2,5,2); // x1, x2, y
    Tree.fillHorizontal(3,5,3); // x1, x2, y
    Tree.fillHorizontal(4,5,4); // x1, x2, y
}

void testVertical(){
    Tree.fillVertical(0,0,5); // x, y1, y2 
    Tree.fillVertical(1,1,5); // x, y1, y2 
    Tree.fillVertical(2,2,5); // x, y1, y2 
    Tree.fillVertical(3,3,5); // x, y1, y2 
    Tree.fillVertical(4,4,5); // x, y1, y2 
}

int main(){
    testVertical();

    mainScreen.debugPrint();
}