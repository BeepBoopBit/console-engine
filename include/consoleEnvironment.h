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
        void fillHorizontal(char chr, const std::initializer_list<sSize> &pos){
            if(_screen->isOutOfRange(pos)){
                exit(-1);
            }
            _screen->fillHorizontal(chr, pos);
        }
        void fillVertical(char chr, const std::initializer_list<sSize> &pos){
            if(_screen->isOutOfRange(pos)){
                exit(-1);
            }
            _screen->fillVertical(chr, pos);
        }
    private: // checker
    private:
        sSize _posX, _posY;
        std::string _type;
        ConsoleScreen *_screen;
    };

};

#endif // CONSOLEENVIRONMENT_H