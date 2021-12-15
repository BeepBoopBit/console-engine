#ifndef CONSOLEENVIRONMENT_H
#define CONSOLEENVIRONMENT_H

#include "consoleScreen.h"
namespace CE{
    class ConsoleEnvironment{
    private:
        typedef long long lSize;
    public:
        ConsoleEnvironment(ConsoleScreen *screen, char chr, std::string type){
            _screen = screen;
            _chr = chr;
            _type = type;
        }
        void create(std::string type, lSize posX = 0, lSize posY = 0){
            // in-progress
        }
        void fillHorizontal(lSize x1, lSize x2, lSize y){
            if(x1 >= x2){
                _screen->callError("range");
            }
            _screen->checkRange(x1,y);
            _screen->checkRange(x2,y);
            _screen->fillHorizontal(_chr, x1, x2, y);
            updatePosition({x1,x2}, {y});
        }
        void fillVertical(lSize x, lSize y1, lSize y2){
            if(y1 >= y2){
                _screen->callError("range");
            }
            _screen->checkRange(x,y1);
            _screen->checkRange(x,y2);
            _screen->fillVertical(_chr, x, y1, y2);
            updatePosition({x}, {y1,y2});
        }
        void positionPrint(){
            for(auto i: _positions){
                std::cout <<  i.first << ' ' << i.second << '\n';
            }
            std::cout << std::endl;
        }
    private: // checker
        void updatePosition(const std::initializer_list<lSize> &posX, const std::initializer_list<lSize> &posY){
            if(posY.size() > 1){
                for(int i = *(posY.begin()); i < (*(posY.begin()+1)); ++i){
                    _positions.push_back(std::make_pair(*(posX.begin()), i));
                }
            }else{
                for(int i = *(posX.begin()); i < (*(posX.begin()+1)); ++i){
                    _positions.push_back(std::make_pair(i, *(posY.begin())));
                }
            }
        }
    private:
        std::vector<std::pair<int,int>> _positions;
        // _pos[n].first -> x
        // _pos[n].second -> y
        std::string _type;
        char _chr;
        ConsoleScreen *_screen;
    };

};

#endif // CONSOLEENVIRONMENT_H