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
                return true;
            }
            if(y > _screenHeight){
                return true;
            }
            return false;
        }
        void fillHorizontal(char chr, sSize amount, const std::initializer_list<sSize> &pos){
            sSize x2 = *(pos.begin()+1),
                  y = *(pos.begin()+2);
            sSize x1 = *(pos.begin());
            for(int i = x1; i < x2; ++i){
                _screen[(y*(_screenWidth+1))+i] = chr;
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