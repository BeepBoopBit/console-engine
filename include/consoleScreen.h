#ifndef CONSOLESCREEN_H
#define CONSOLESCREEN_H
#include "includes.h"

/**
 * @brief 
 * @todo Create a ConsoleScreenHandler
 * @todo Implement Color
 */
namespace CE{
    class ConsoleEnvironment;
    class ConsoleScreen{
    public:
        typedef std::string::size_type sType;

    public: // constructors
        ConsoleScreen()  : _screenWidth(20), _screenHeight(10), _background(' '){
            setupMap();
        }
        
        ConsoleScreen(sType width, sType height, char background = ' ') : _screenWidth(width), _screenHeight(height), _background(background){
            setupMap();
        }
    
    public: // movement (WORKING)
        /**
         * When moving, the previous value will be replaced by the background character
         **/
        
        void move(int pX, int pY, int nX, int nY){
            // save the previous character
            char chrPrev = _screen[pX + (pY*(_screenWidth + (1)))];
            // replace the previous position by the background
            _screen[pX + (pY*(_screenWidth + (1)))] = _background;
            // move to the next position
            _screen[nX + (nY*(_screenWidth + (1)))] = chrPrev;
        }
        void moveUp(int pX, int pY, int num){
            move(pX, pY, pX, pY-num);
        }
        void moveLeft(int pX, int pY, int num){
            move(pX, pY, pX-num, pY);
        }
        void moveDown(int pX, int pY, int num){
            move(pX, pY, pX, pY+num);
        }
        void moveRight(int pX, int pY, int num){
            move(pX, pY, pX+num, pY);
        }
    
    public: // utility
        void print(){
            std::cout << _screen;
        }

    public: // debug
        void place(int x, int y, char character){
            _screen[x+(y*(_screenWidth+1))] = character;
        }

    private:
        void setupMap(){
            for(int i = 0; i < _screenHeight; ++i){
                _screen += std::string(_screenWidth, _background) + '\n';
            }
        }
    private:
        std::string _screen;
        sType _screenWidth,
              _screenHeight;
        char _background;
    };
    
};


#endif // CONSOLESCREEN_H