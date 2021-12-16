#include "../include/consoleScreen.h"
#include "../include/consoleEnvironment.h"




int main(){
    CE::ConsoleScreen mainScreen(5,5, '#');
    std::chrono::milliseconds timespan(500); 
    CE::RigidBody Tree(&mainScreen,'o',1,1);
    mainScreen.debugPrint();
    std::this_thread::sleep_for(timespan);
    Tree.setPosition(0,0);
    mainScreen.debugPrint();
    std::this_thread::sleep_for(timespan);
    
}