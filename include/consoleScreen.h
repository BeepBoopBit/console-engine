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
    private:
        typedef long long lSize;
        friend class ConsoleEnvironment;
    public: // constructors
        ConsoleScreen(const lSize &width, const lSize &height, lSize startX = 0, lSize startY = 0, char chr = ' ') : _screenWidth(width), _screenHeight(height){ // working
            for(int i = 0; i < height; ++i){
                _screen[i] = std::make_pair(std::vector<lSize>(width), std::vector<std::vector<std::string>>(width));
                for(int j = 0; j < width; ++j){ // populate the x's
                    _screen[i].first[j] = j;
                }
                for(int j = 0; j < width; ++j){ // {"COLOR", "CHAR", "COLOR"}
                    _screen[i].second[j].push_back("\033[0m");
                    _screen[i].second[j].push_back(std::string(1,chr));
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
            for(int i = 0; i < _screen.size(); ++i){ // SO BAD HAHAHAHA
                move_to(_x,_y+i);
                for(auto j: _screen[i].second){
                    std::cout << j[0] << j[1] << "\033[0m";
                }
                std::cout << '\n';
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
            _screen[y].second[x][_defaultX] = chr;
            if(py != y || px != x){
                _screen[py].second[px][_defaultX] = _chr;
            }
        }
        void updateVisibility(lSize x, lSize y, char chr = '\0'){
            if(chr == '\0'){
                _screen[y].second[x][_defaultX] = _chr;
            }else{
                _screen[y].second[x][_defaultX] = chr;

            }
        }
        void updateColor(lSize x, lSize y, std::string color){
            _screen[y].second[x][0] = color;
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
        std::map<lSize, std::pair<std::vector<lSize>, std::vector<std::vector<std::string>>>> *getScreen(){
            return &_screen;
        }
    private: // variables
        std::map<lSize, std::pair<std::vector<lSize>, std::vector<std::vector<std::string>>>> _screen;
        const lSize _screenWidth;
        const lSize _screenHeight;
        char _chr;
        lSize _x; 
        lSize _y;
        const lSize _defaultX = 1; // the 'char' is always in the 1st index {COLOR,CHAR,COLOR} 
    protected:
    };
    
};


#endif // CONSOLESCREEN_H