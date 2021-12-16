#ifndef CONSOLEENVIRONMENT_H
#define CONSOLEENVIRONMENT_H

#include "consoleScreen.h"
namespace CE{

    class ConsoleEnvironment{
    private:
        typedef long long lSize;
    public:
        enum AreaBodyType {Box, Circle};
    public: // setter
        void setVisibility(bool isTrue){
            bool visible = isVisible();
            if(visible != isTrue){
                notifyVisibility(_x, _y, isTrue);
                _visibility = isTrue;
            }
        }
        void setPosition(lSize x, lSize y){
            _prevX = _x;
            _prevY = _y;
            _x = x;
            _y = y;
            notifyPosition();
        }
        void setChar(char chr){
            _chr = chr;
        }
        void setScreen(ConsoleScreen *screen){
            _screen = screen;
        }
    public: // getter
        lSize getPosX(){
            return _x;
        }
        lSize getPosY(){
            return _y;
        }
        lSize getPrevPosX(){
            return _prevX;
        }
        lSize getPrevPosY(){
            return _prevY;
        }
        char getChar(){
            return _chr;
        }
    protected: // utility
        bool isVisible(){
            return _visibility;
        }
    protected: // Others
        void notifyVisibility(lSize x, lSize y, bool isTrue){
            if(_screen){
                if(isTrue){
                    _screen->updateVisibility(x,y, _chr);
                }else{
                    _screen->updateVisibility(x,y);
                }
            }
        }
        void notifyPosition(){
            _screen->updatePosition(_chr,_x,_y,_prevX, _prevY);
        }
    private:
        bool _visibility = true;
        long long _x = 0,
                  _y = 0;
        long long _prevX = 0,
                  _prevY = 0;
        char _chr = '#';
        ConsoleScreen *_screen = nullptr;
    };
    class RigidBody : public ConsoleEnvironment{ // to be implemented
    private:
        typedef long long lSize;
    public:
        RigidBody(ConsoleScreen *screen = nullptr, char chr = '#', lSize posX = 0, lSize posY = 0, bool visibility = true, AreaBodyType bType = Box){
            setScreen(screen);
            setChar(chr);
            setPosition(posX, posY);
            setVisibility(visibility);
        }
    private:
    };

    class StaticBody : public ConsoleEnvironment{ // to be implemented
    private:
        typedef long long lSize;
    public:
        StaticBody(ConsoleScreen *screen = nullptr, char chr = '#', lSize posX = 0, lSize posY = 0, bool visibility = true, AreaBodyType bType = Box){
            setScreen(screen);
            setChar(chr);
            setPosition(posX, posY);
            setVisibility(visibility);
        }
    private:
    };

};

#endif // CONSOLEENVIRONMENT_H