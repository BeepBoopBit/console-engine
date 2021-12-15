#include "../include/consoleScreen.h"
#include "../include/consoleEnvironment.h"
int main(){
    // position are starting to zero
    CE::ConsoleScreen mainScreen(5,5);
    CE::ConsoleEnvironment Tree(&mainScreen);
    //Tree.fillHorizontal('1',5,{4,5,0}); // x1, x2, y
    //Tree.fillHorizontal('2',5,{4,5,1}); // x1, x2, y
    //Tree.fillHorizontal('3',5,{4,5,2}); // x1, x2, y
    //Tree.fillHorizontal('4',5,{4,5,3}); // x1, x2, y
    //Tree.fillHorizontal('5',5,{4,5,4}); // x1, x2, y
    
    Tree.fillVertical('1',{0,5,0});
    Tree.fillVertical('2',{1,5,1});
    Tree.fillVertical('3',{2,5,2});
    Tree.fillVertical('4',{3,5,3});
    Tree.fillVertical('5',{4,5,4});
    mainScreen.print();
}