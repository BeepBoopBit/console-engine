#ifndef CONSOLESCREEN_H
#define CONSOLESCREEN_H

#include "includes.h"
namespace CE{
    class ConsoleEnvironment;
    class ConsoleScreen{
    private:
        typedef long long lSize;
        friend class ConsoleEnvironment;

    public: // constructors
        ConsoleScreen(const lSize &width, const lSize &height, char chr = ' ') : _screenWidth(width), _screenHeight(height){ // working
            for(int i = 0; i < height; ++i){
                _screen[i] = std::make_pair(std::vector<long long>(width), std::string(6, chr));
                for(int j = 0; j < width; ++j){
                    _screen[i].first[j] = j;
                }
                _screen[i].second[5] = '\n';
            }
        }
        void debugPrint(){
            update();
            std::cout << std::endl;
            for(auto i: _screen){
                for(auto j: (i.second.first)){
                    std::cout << j << ' ';
                }
                std::cout << std::endl;
            }
        }
    private: // functions
        void update(){
            for(auto i: _screen){
                std::cout << i.second.second;
            }
        }
        void checkRange(int x, int y = 0){
            if(x > _screenWidth){
                callError("range");
            }else if(x < 0){
                callError("range");
            }
            if(y > _screenHeight){
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
        void fillHorizontal(const char &chr, lSize x1, lSize x2, lSize y){ // assume that the position is existing
            for(int i = x1; i < x2; ++i){
                _screen[y].second[i] = chr;
            }
        }
        void fillVertical(const char &chr, lSize x, lSize y1, lSize y2){
            for(int i = y1; i < y2; ++i){
                _screen[i].second[x] = chr;
            }
        }

    private: // getter
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
    
    protected:
    };

};


#endif // CONSOLESCREEN_H