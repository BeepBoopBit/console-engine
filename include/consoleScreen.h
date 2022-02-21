#ifndef CONSOLESCREEN_H
#define CONSOLESCREEN_H

#include "includes.h"

/**
 * @brief 
 * @todo Create a ConsoleScreenHandler
 * @todo Implement Color
 */
namespace CE{

    class Observer;
    class ConsoleScreen{
    public:
        typedef std::string::size_type sType;
        friend Observer;
    public: // constructors
        ConsoleScreen()  : _screenWidth(20), _screenHeight(10), _background(' '){
            setupMap();
        }
        
        ConsoleScreen(sType width, sType height, char background = ' ') : _screenWidth(width), _screenHeight(height), _background(background), _storedBackground(background){
            setupMap();
        }
    
    public: // movement (WORKING)
        /**
         * When moving, the previous value will be replaced by the background character
         **/
        
        void move(sType pX, sType pY, sType nX, sType nY){

            // save the previous character
            char chrPrev = _screen[pX + (pY*(_screenWidth + (1)))];
            
            // replace the previous position by the previous character in that position
            _screen[pX + (pY*(_screenWidth + (1)))] = _storedBackground;
            
            // save the character to his next destination
            _storedBackground = _screen[nX + (nY*(_screenWidth + (1)))];

            // move to the next position
            _screen[nX + (nY*(_screenWidth + (1)))] = chrPrev;
        }
        void movePre(sType pX, sType pY, sType nX, sType nY){

            // save the previous character
            char chrPrev = _screen[pX + (pY*(_screenWidth + (1)))];
            
            // replace the previous position by the previous character in that position
            _screen[pX + (pY*(_screenWidth + (1)))] = _storedBackground;
            
            // save the character to his next destination
            _storedBackground = _screen[nX + (nY*(_screenWidth + (1)))];

            // move to the next position
            _screen[nX + (nY*(_screenWidth + (1)))] = _storedBackground;
        }
        void moveUp(sType pX, sType pY, sType num){
            move(pX, pY, pX, pY-num);
        }
        void moveLeft(sType pX, sType pY, sType num){
            move(pX, pY, pX-num, pY);
        }
        void moveDown(sType pX, sType pY, sType num){
            move(pX, pY, pX, pY+num);
        }
        void moveRight(sType pX, sType pY, sType num){
            move(pX, pY, pX+num, pY);
        }
    
    public: // utility
        void print(){
            std::cout << _screen;
        }
    
    private:
        void setupMap(){
            for(sType i = 0; i < _screenHeight; ++i){
                _screen += std::string(_screenWidth, _background) + '\n';
            }
        }
        
        void place(sType x, sType y, char character){
            _screen[x+(y*(_screenWidth+1))] = character;
        }

    protected:
        void initialEntity(sType x, sType y, char character){
            place(x,y,character);
        }
    private:
        std::string _screen;
        sType _screenWidth,
              _screenHeight;
        char _background,
             _storedBackground;
        bool isFirst = true;
    };
    
};


#endif // CONSOLESCREEN_H