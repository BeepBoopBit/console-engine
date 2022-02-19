#ifndef CONSOLE_ENTITY_H
#define CONSOLE_ENTITY_H

#include "observer.h"
#include <string>


namespace CE{
    class ConsoleEntity{
    public:
        typedef std::string::size_type sType;
    public: // constructor
        ConsoleEntity(Observer *observer, char character, int x = 0, int y = 0): _observer(observer), _character(character), _pX(x), _pY(y), _cX(x), _cY(y){
            _observer->notifyInitialPosition(x,y,character);
        }
    public:
        void move(int pX, int pY, int nX, int nY){
            _pX = pX;
            _pY = pY;
            _cX = nX;
            _cY = nY;
            _observer->notifyPosition(pX, pY, nX, nY);
        }
        void moveUp(int num){
            move(_cX, _cY, _cX, _cY-num);
        }
        void moveLeft(int num){
            move(_cX, _cY, _cX-num, _cY);
        }
        void moveDown(int num){
            move(_cX, _cY, _cX, _cY+num);
        }
        void moveRight(int num){
            move(_cX, _cY, _cX+num, _cY);
        }
    private:
        sType _pX, _pY;
        sType _cX, _cY;
        CE::Observer *_observer;
        char _character;
    };
}
#endif // CONSOLE_ENTITY_H