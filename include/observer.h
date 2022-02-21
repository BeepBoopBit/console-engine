#ifndef OBSERVER_H
#define OBSERVER_H

#include "consoleScreen.h"

namespace CE{
    class Observer{
    public:
        typedef std::string::size_type sType;
    
    public: // constructor
        Observer(ConsoleScreen* screen){
            _screen = screen;
        }
    public:
        void notifyPosition(sType pX, sType pY, sType nX, sType nY){
            _screen->move(pX,pY, nX, nY);
        }
        void notifyPrePosition(sType pX, sType pY, sType nX, sType nY){
            _screen->move(pX,pY, nX, nY);
        }
        void notifyInitialPosition(sType x, sType y, char character){
            _screen->initialEntity(x,y,character);
        }
    private:
        ConsoleScreen* _screen;
    };
}
#endif // OBSERVER_H