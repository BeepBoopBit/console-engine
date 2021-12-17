#include "../include/consoleScreen.h"
#include "../include/consoleEnvironment.h"
#include "../include/consoleEnvironmentHandler.h"

void sleepFor(int x){
    std::chrono::milliseconds timespan(x); 
    std::this_thread::sleep_for(timespan);
}

int main(){
    CE::ConsoleScreen mainScreen(5,5,5,5,'#');
    CE::RigidBody Tree(&mainScreen,'T',1,1);
    CE::RigidBody Stone(&mainScreen,'O',1,2);
    mainScreen.print();

}