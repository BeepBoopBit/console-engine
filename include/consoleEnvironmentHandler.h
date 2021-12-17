#ifndef CEENVIRONMENTHANDLER_H
#define CEENVIRONMENTHANDLER_H

#include "consoleEnvironment.h"

namespace CE{
    class ConsoleEnvironmentHandler : private ConsoleEnvironment{
    private:
        typedef long long lSize;
    public:
        void add(ConsoleEnvironment *_env){
            _environments.push_back(_env);
        }
        bool checkForDuplicateEnvironment(){
            for(int i = 0; i < _environments.size(); ++i){
                for(int j = 0; j < _environments.size(); ++j){
                    if((i != j) && (_environments[i] == _environments[j])){
                        return true;
                    }
                }
            }
            return false;
        }
        void setVisibility(bool isTrue){
            for(int i = 0; i < _environments.size(); ++i){
                _environments[i]->setVisibility(isTrue);
            }
        }
        void moveX(lSize x){
            for(int i = 0; i < _environments.size(); ++i){
                lSize newX = _environments[i]->getPosX()+x;
                lSize y = _environments[i]->getPosY();
                _environments[i]->setPosition(newX,y);
            }
        }
        void moveY(lSize y){
            for(int i = 0; i < _environments.size(); ++i){
                lSize x = _environments[i]->getPosX();
                lSize newY = _environments[i]->getPosY()+y;
                _environments[i]->setPosition(x,newY);
            }
        }
        void setChar(char chr){
            for(int i = 0; i < _environments.size(); ++i){
                _environments[i]->setChar(chr);
            }
        }
        void setScreen(ConsoleScreen *screen){
            for(int i = 0; i < _environments.size(); ++i){
                _environments[i]->setScreen(screen);
            }
        }
        void setColor(int r, int g, int b){
            for(int i = 0; i < _environments.size(); ++i){
                _environments[i]->setColor(r,g,b);
            }
        }
    private:
        std::vector<ConsoleEnvironment*> _environments;
    };
}

#endif // CEENVIRONMENTHANDLER_H