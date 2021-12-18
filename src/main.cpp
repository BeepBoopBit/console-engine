#include "../include/consoleScreen.h"
#include "../include/consoleEnvironment.h"
#include "../include/consoleEnvironmentHandler.h"

void sleepFor(int x){
    std::chrono::milliseconds timespan(x); 
    std::this_thread::sleep_for(timespan);
}

CE::RigidBody *createNewTrees(int x, int y, char chr,  CE::ConsoleScreen *screen){
    return new CE::RigidBody(screen,chr,x,y);
}

int main(){
    CE::ConsoleScreen mainScreen(5,5,0,0,'1');
    CE::ConsoleEnvironmentHandler _handlers;
    _handlers.read("E:/Programming/console-engine/src/map00.txt");
    mainScreen.print();
}