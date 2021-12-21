#ifndef CONSOLEENVIRONMENT_H
#define CONSOLEENVIRONMENT_H

#include "consoleScreen.h"

/**
 * @brief 
 * @todo Operator overloading for ConsoleEnvironemnt to RigidBody and ConsoleEnvironment to StaticBody
 * 
 */
namespace CE{
    class ConsoleEnvironment{
    private:
        typedef long long lSize;
    public:
        enum AreaBodyType {Box, Circle};
        ConsoleEnvironment(){
            _screen = nullptr;
            _chr = ' ';
            _x = 0;
            _y = 0;
            _prevX = 0;
            _prevY = 0;
            _visibility = 0;
        }
        ConsoleEnvironment(char chr, lSize posX = 0, lSize posY = 0, bool visibility = true, AreaBodyType bType = Box){
            _chr = chr;
            _x = posX;
            _y = posY;
            _prevX = posX;
            _prevY = posY;
            _visibility = visibility;
        }
        ConsoleEnvironment(ConsoleScreen *screen, char chr, lSize posX = 0, lSize posY = 0, bool visibility = true, AreaBodyType bType = Box){
            setScreen(screen);
            setChar(chr);
            setPositionStart(posX, posY);
            setVisibility(visibility);
        }
    public: // setter
        void setVisibility(bool isTrue){
            bool visible = isVisible();
            if(visible != isTrue){
                notifyVisibility(isTrue);
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
        inline void setChar(char chr){
            _chr = chr;
        }
        inline void setScreen(ConsoleScreen *screen){
            _screen = screen;
        }
        void setColor(int r, int g, int b){
            if(((r > 255) || (r < 0)) && ((g > 255) || (g < 0)) && ((b > 255) || (b < 0))){
                std::cout << "Wrong Color" << std::endl;
                exit(-1);
            }
            _color = "\033[38;2;" + std::to_string(r) + ';' + std::to_string(g) + ';' + std::to_string(b) + 'm';
            notifyColor();
        }
        void resetColor(){
            _color = "\033[0m";
            notifyColor();
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
    protected: // Notification
        void notifyVisibility(bool isTrue){
            if(_screen){
                if(isTrue){
                    _screen->updateVisibility(_x,_y,_chr);
                }else{
                    _screen->updateVisibility(_x,_y);
                }
            }
        }
        void notifyPosition(){
            _screen->updatePosition(_chr,_x,_y,_prevX, _prevY);
        }
        void notifyColor(){
            _screen->updateColor(_x, _y, _color);
        }
    protected: // Setter
        void setPositionStart(lSize x, lSize y){
            _prevX = x;
            _prevY = y;
            _x = x;
            _y = y;
            notifyPosition();
        }
    private:
        bool _visibility = true;
        long long _x = 0,
                  _y = 0;
        long long _prevX = 0,
                  _prevY = 0;
        char _chr = ' ';
        ConsoleScreen *_screen = nullptr;
        std::string _color = "\033[0m";
    };
    class RigidBody : public ConsoleEnvironment{ // to be implemented
    private:
        typedef long long lSize;
    public:
        RigidBody(ConsoleScreen *screen = nullptr, char chr = ' ', lSize posX = 0, lSize posY = 0, bool visibility = true, AreaBodyType bType = Box){
            setScreen(screen);
            setChar(chr);
            setPositionStart(posX, posY);
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
            setPositionStart(posX, posY);
            setVisibility(visibility);
        }
    private:
    };

};

#endif // CONSOLEENVIRONMENT_H