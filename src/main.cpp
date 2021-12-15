#include "../include/consoleScreen.h"
#include "../include/consoleEnvironmentHandler.h"


CE::ConsoleScreen mainScreen(5,5, '#');
CE::ConsoleEnvironment Tree('T',0,0);
CE::ConsoleEnvironmentHandler _envHandle;


int main(){
    std::chrono::milliseconds timespan(1500); 
    std::cout << std::endl;
    _envHandle.add(&Tree);
    mainScreen.update(_envHandle);

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            Tree.setPosition(i,j);
        mainScreen.update(_envHandle);
            mainScreen.debugPrint();
            std::this_thread::sleep_for(timespan);
        }
    }
}