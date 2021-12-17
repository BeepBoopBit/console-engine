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
    CE::ConsoleScreen mainScreen(10,10,5,5,'#');
    CE::ConsoleEnvironmentHandler _handle;
    for(int i = 0; i < 6; ++i){ // top
        _handle.add(createNewTrees(i+2,1,'P',&mainScreen));
    }
    for(int i = 0; i < 6; ++i){ // left
        _handle.add(createNewTrees(2,2+i,'P',&mainScreen));
    }
    for(int i = 0; i < 6; ++i){ // right
        _handle.add(createNewTrees(7,2+i,'P',&mainScreen));
    }
    for(int i = 0; i < 6; ++i){ // bottom
        _handle.add(createNewTrees(i+2,8,'P',&mainScreen));
    }

    _handle.setColor(100,50,120);
    mainScreen.print();


}