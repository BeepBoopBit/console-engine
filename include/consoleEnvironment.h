#ifndef CONSOLEENVIRONMENT_H
#define CONSOLEENVIRONMENT_H

#include "consoleScreen.h"
namespace CE{

    class ConsoleEnvironment{
    protected:
        virtual void visibility(bool isTrue) = 0;
        virtual void setPosition(long long x, long long y) = 0;
        //virtual void setChar(char chr) = 0;
        //virtual long long getPosX() = 0;
        //virtual long long getPosY() = 0;
        //virtual long long getPrevPosX() = 0;
        //virtual long long getPrevPosY() = 0;
        //virtual char getChar() = 0;
        bool _visibility = true;
        long long _x = 0,
                  _y = 0;
        long long _prevX = 0,
                  _prevY = 0;
        char _chr = '#';

    };
    class RigidBody : ConsoleEnvironment{
    private:
        typedef long long lSize;
    public:
        RigidBody(ConsoleScreen *screen, char chr = '#', lSize posX = 0, lSize posY = 0){
            _chr = chr;
            _screen = screen;
            setPosition(posX, posY);
        }
        void visibility(bool isTrue){
            notifyVisibility(isTrue);
        }
        void setPosition(lSize x, lSize y){
            _prevX = _x;
            _prevY = _y;
            _x = x;
            _y = y;
            notifyPosition();
        }
    private:
        void notifyVisibility(bool isTrue){
            if(_screen){
                _screen->updateVisibility(isTrue);
            }
        }
        void notifyPosition(){
            _screen->updatePosition(_chr,_x,_y,_prevX, _prevY);
        }
    private:
        ConsoleScreen *_screen = nullptr;
    };

    class StaticBody : ConsoleEnvironment{

    };

};

#endif // CONSOLEENVIRONMENT_H