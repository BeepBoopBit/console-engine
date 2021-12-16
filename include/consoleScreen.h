#ifndef CONSOLESCREEN_H
#define CONSOLESCREEN_H
#include "includes.h"

/**
 * @brief 
 * @todo Create a ConsoleScreenHandler
 */
namespace CE{
    class ConsoleEnvironment;
    class ConsoleScreen{
    private:
        typedef long long lSize;
        friend class ConsoleEnvironment;
    public: // constructors
        ConsoleScreen(const lSize &width, const lSize &height, char chr = ' ') : _screenWidth(width), _screenHeight(height){ // working
            for(int i = 0; i < height; ++i){
                _screen[i] = std::make_pair(std::vector<long long>(width), std::string(width, chr));
                for(int j = 0; j < width; ++j){
                    _screen[i].first[j] = j;
                }
            }
            _chr = chr;
        }
        void add(){
            // add screen in a screen (MAYBE)
        }
        void debugPrint(){
            system("cls"); // TEST
            for(auto i: _screen){
                std::cout << i.second.second << '\n';
            }
        }
    private: // functions
        void checkRange(int x, int y = 0){
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
        std::map<long long, std::pair<std::vector<long long>, std::string>> *getScreen(){
            return &_screen;
        }
    private: // variables
        std::map<long long, std::pair<std::vector<long long>, std::string>> _screen;
        const lSize _screenWidth;
        const lSize _screenHeight;
        char _chr;
    protected:
    };
    
};


#endif // CONSOLESCREEN_H