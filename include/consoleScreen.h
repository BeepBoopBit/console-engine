#ifndef CONSOLESCREEN_H
#define CONSOLESCREEN_H

#include "includes.h"
namespace CE{
    class ConsoleEnvironment;
    class ConsoleScreen{
    private:
        typedef std::string::size_type sSize;
        friend class ConsoleEnvironment;

    public: // constructors
        ConsoleScreen(const sSize &width, const sSize &height) : _screenWidth(width), _screenHeight(height){ // working
            // +height for the \n
            // +10 because I want to
            _screen.reserve(((width*height)+height)+10);
            _screen = std::string(((width*height)+height),'o');
            for(int i = 0; i < height; ++i){
                _screen[((width+1)*(i+1))-1] = '\n';
            }
        }
        void print(){
            update();
        }
        sSize getScreenWidth(){
            return _screenWidth;
        }
        sSize getScreenHeight(){
            return _screenHeight;
        }

    public: // functions
        void update(){
            std::cout << _screen;
        }
        bool isOutOfRange(int x, int y = 0){
            if(x > _screenWidth){
                std::cout << "Out of Bounce" << std::endl;
                return true;
            }else if(x < 0){
                std::cout << "Out of Bounce" << std::endl;
                return true;
            }
            if(y > _screenHeight){
                std::cout << "Out of Bounce" << std::endl;
                return true;
            }else if(y < 0){
                std::cout << "Out of Bounce" << std::endl;
                return true;
            }
            return false;
        }
        bool isOutOfRange(const std::initializer_list<sSize> &pos){
            if(*(pos.begin()) > *(pos.begin()+1)){ // if x1 > x2
                std::cout << "Out of Bounce" << std::endl;
                return true;
            }
            if(isOutOfRange(*(pos.begin()+1))){ // if x2 is out of bounce
                return true;
            }
            return false;
        }
        void fillHorizontal(char chr, const std::initializer_list<sSize> &pos){
            sSize x1 = *(pos.begin()),
                  x2 = *(pos.begin()+1),
                  y = *(pos.begin()+2);
            for(int i = x1; i < x2; ++i){
                _screen[(y*(_screenWidth+1))+i] = chr;
            }
        }
        void fillVertical(char chr, const std::initializer_list<sSize> &pos){
            sSize y1 = *(pos.begin()),
                  y2 = *(pos.begin()+1),
                  x = *(pos.begin()+2);
            for(int i = y1; i < y2; ++i){
                _screen[(i*(_screenWidth+1))+x] = chr;
            }
                  
        }
    private: // variables
        std::string _screen;
        const int _screenWidth;
        const int _screenHeight;
    
    protected:
    };

};


#endif // CONSOLESCREEN_H