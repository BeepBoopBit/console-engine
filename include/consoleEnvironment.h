#ifndef CONSOLEENVIRONMENT_H
#define CONSOLEENVIRONMENT_H

#include "consoleScreen.h"
namespace CE{
    class ConsoleEnvironment{
    private:
        typedef std::string::size_type sSize;
    public:
        ConsoleEnvironment(ConsoleScreen *screen){
            _screen = screen;
            
        }
        void create(std::string type, sSize posX = 0, sSize posY = 0){
            // in-progress
        }
        void fillHorizontal(char chr, sSize amount, const std::initializer_list<sSize> &pos){
            if((*(pos.begin()+1)) < *(pos.begin())){
                std::cout << "Wrong Input" << std::endl;
                exit(-1);
            }
            if(_screen->isOutOfRange(*(pos.begin()+1))){
                std::cout << "Out Of Bounce" << std::endl;
                exit(-1);
            }
            _screen->fillHorizontal(chr, amount, pos);
        }
    private:
        sSize _posX, _posY;
        std::string _type;
        ConsoleScreen *_screen;
    };

};

#endif // CONSOLEENVIRONMENT_H