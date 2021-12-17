#ifndef CONSOLESCREEN_H
#define CONSOLESCREEN_H
#include "includes.h"

/**
 * @brief 
 * @todo Create a ConsoleScreenHandler
 * @todo Implement Position in Screen
 */
namespace CE{
    class ConsoleEnvironment;
    class ConsoleScreen{
    private:
        typedef long long lSize;
        friend class ConsoleEnvironment;
    public: // constructors
        ConsoleScreen(const lSize &width, const lSize &height, lSize startX = 0, lSize startY = 0, char chr = ' ') : _screenWidth(width), _screenHeight(height){ // working
            for(int i = 0; i < height; ++i){
                _screen[i] = std::make_pair(std::vector<lSize>(width), std::string(width, chr));
                for(int j = 0; j < width; ++j){
                    _screen[i].first[j] = j;
                }
            }
            _chr = chr;
            _x = startX;
            _y = startY;
        }
        void add(){
            // add screen in a screen (MAYBE)
        }
        void print(){
            system("cls");
            for(int i = 0; i < _screen.size(); ++i){
                move_to(_x,_y+i);
                std::cout << _screen[i].second;
            }
        }
    private: // functions
        void checkRange(lSize x, lSize y = 0){
            if(x >= _screenWidth){
                callError("range");
            }else if(x < 0){
                callError("range");
            }
            if(y >= _screenHeight){
                callError("range");
            }else if(y < 0){
                callError("range");
            }
        }
        void callError(std::string type){
            if(type == "range"){
                std::cout << "Out of Bounce" << std::endl;
                exit(-1);
            }
        }
        void move_to(long x, long y){
            std::cout << "\033[" << y << ';' << x << 'H';
        }
    private: // UPDATE
        void updatePosition(char chr, lSize x, lSize y, lSize px, lSize py){
            checkRange(x,y); // no ned to check for px and py, since we're sure they are always correct
            _screen[y].second[x] = chr;
            if(py != y || px != x){
                _screen[py].second[px] = _chr;
            }
        }
        void updateVisibility(lSize x, lSize y, char chr = '\0'){
            if(chr == '\0'){
                _screen[y].second[x] = _chr;
            }else{
                _screen[y].second[x] = chr;

            }
        }
    public: // getter
        lSize getScreenWidth(){
            return _screenWidth;
        }
        lSize getScreenHeight(){
            return _screenHeight;
        }
        lSize getScreenTotal(){
            return _screenWidth*_screenHeight;
        }
        std::map<lSize, std::pair<std::vector<lSize>, std::string>> *getScreen(){
            return &_screen;
        }
    private: // variables
        std::map<lSize, std::pair<std::vector<lSize>, std::string>> _screen;
        const lSize _screenWidth;
        const lSize _screenHeight;
        char _chr;
        lSize _x;
        lSize _y;
    protected:
    };
    
};


#endif // CONSOLESCREEN_H