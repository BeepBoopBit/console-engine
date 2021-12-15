#ifndef CONSOLEENVIRONMENT_H
#define CONSOLEENVIRONMENT_H

#include "consoleScreen.h"
namespace CE{
    class ConsoleEnvironment{
    private:
        typedef std::string::size_type sSize;
    public:
        ConsoleEnvironment(ConsoleScreen *screen, char chr, std::string type){
            _screen = screen;
            _chr = chr;
            _type = type;
            _positions.reserve(_screen->getScreenTotal()+_screen->getScreenHeight()+10);
        }
        void create(std::string type, sSize posX = 0, sSize posY = 0){
            // in-progress
        }
        void fillHorizontal(sSize x1, sSize x2, sSize y){
            if(x1 >= x2){
                _screen->callError("range");
            }
            _screen->checkRange(x1,y);
            _screen->checkRange(x2,y);
            _screen->fillHorizontal(_chr, x1, x2, y);
        }
        void fillVertical(sSize x, sSize y1, sSize y2){
            if(y1 >= y2){
                _screen->callError("range");
            }
            _screen->checkRange(x,y1);
            _screen->checkRange(x,y2);
            _screen->fillVertical(_chr, x, y1, y2);
        }
        void updatePosition(){

        }
    private: // checker
    private:
        std::vector<std::vector<sSize>> _positions; // _position[y][x]
        std::map<sSize, std::pair<sSize,char>> stuff;
        std::string _type;
        char _chr;
        ConsoleScreen *_screen;
    };

};

#endif // CONSOLEENVIRONMENT_H