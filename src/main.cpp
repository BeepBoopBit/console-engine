#include "../include/consoleScreen.h"



int main(){
    CE::ConsoleScreen a(10,10,'#');
    a.place(0,0,'P');
    a.print();

    
    return 0;
}