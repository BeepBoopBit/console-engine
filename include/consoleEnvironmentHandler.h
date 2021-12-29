#ifndef CEENVIRONMENTHANDLER_H
#define CEENVIRONMENTHANDLER_H

#include "consoleEnvironment.h"

namespace CE{
    class ConsoleEnvironmentHandler : private ConsoleEnvironment{
    private:
        typedef long long lSize;
    public:
        ConsoleEnvironmentHandler(){

        }
        void add(ConsoleEnvironment *_env){
            _environments.push_back(_env);
        }
        void addFront(ConsoleEnvironment *_env){
            _environments.insert(_environments.begin(), _env);
        }
        void remove(ConsoleEnvironment *env){
            for(int i = 0; i < _environments.size(); ++i){
                if(_environments[i] == env){
                    _environments.erase(_environments.begin() +i);
                }
            }
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
            if(x > 0){
                for(int i = _environments.size()-1; i >= 0; --i){
                    lSize newX = _environments[i]->getPosX()+x;
                    lSize y = _environments[i]->getPosY();
                    _environments[i]->setPosition(newX,y);
                }
            }else{
                for(int i = 0; i < _environments.size(); ++i){
                    lSize newX = _environments[i]->getPosX()+x;
                    lSize y = _environments[i]->getPosY();
                    _environments[i]->setPosition(newX,y);
                }
            }
        }
        void moveY(lSize y){
            if(y > 0){
                for(int i = _environments.size()-1; i >= 0; --i){
                    lSize x = _environments[i]->getPosX();
                    lSize newY = _environments[i]->getPosY()+y;
                    _environments[i]->setPosition(x,newY);
                }
            }else{
                for(int i = 0; i < _environments.size(); ++i){
                    lSize x = _environments[i]->getPosX();
                    lSize newY = _environments[i]->getPosY()+y;
                    _environments[i]->setPosition(x,newY);
                }
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
        void read(std::string path){
            std::ifstream iOpen(path);
            if(iOpen.is_open()){
                std::string indivLine;
                int y = 0;
                while(std::getline(iOpen, indivLine)){
                    for(int i = 0; i < indivLine.length(); ++i){
                        _environments.push_back(createNewEnvironment(indivLine[i], i, y));
                    }
                    ++y;
                }
            }else{
                std::cout << "FILE IS MISSING" << std::endl;
                exit(-1);
            }
        }
        void read(std::string path, ConsoleScreen *screen){
            std::ifstream iOpen(path);
            if(iOpen.is_open()){
                std::string indivLine;
                int x = 0, y = 0;
                while(std::getline(iOpen, indivLine)){
                    for(int i = 0; i < indivLine.length(); ++i){
                        _environments.push_back(createNewEnvironment(screen,indivLine[i], x, y));
                        ++x;
                    }
                    ++y;
                    x = 0;
                }
            }else{
                std::cout << "FILE IS MISSING" << std::endl;
                exit(-1);
            }
        }
        std::vector<ConsoleEnvironment*> getEnvironment(){
            return _environments;
        }
        ConsoleEnvironment* getEnvironment(lSize index){
            return _environments[index];
        }
        lSize getPosX(lSize index){
            return _environments[index]->getPosX();
        }
        lSize getPosY(lSize index){
            return _environments[index]->getPosY();
        }
        bool empty(){
            return _environments.empty();
        }
    private:
        ConsoleEnvironment* createNewEnvironment(char chr, lSize posX, lSize posY){
            ConsoleEnvironment *temp = new ConsoleEnvironment(chr, posX, posY);
            return temp;
        }
        ConsoleEnvironment* createNewEnvironment(ConsoleScreen *screen, char chr, lSize posX, lSize posY){
            ConsoleEnvironment *temp = new ConsoleEnvironment(screen, chr, posX, posY);
            return temp;
        }
        std::vector<ConsoleEnvironment*> _environments;
    };
}

#endif // CEENVIRONMENTHANDLER_H