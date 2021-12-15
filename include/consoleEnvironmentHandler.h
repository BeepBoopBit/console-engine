#ifndef _CONSOLEENVIRONMENTHANDLER_H
#define _CONSOLEENVIRONMENTHANDLER_H

#include "consoleEnvironment.h"

namespace CE{
    class ConsoleEnvironmentHandler{
    public:
        void add(ConsoleEnvironment* env){
            _environment.push_back(env);
        }
        void remove(ConsoleEnvironment* env){
            for(auto i = _environment.begin(); i != _environment.end(); ++i){
                if(*i == env){
                    _environment.erase(i);
                }
            }
        }
        std::vector<ConsoleEnvironment*> *getEnvironment(){
            return &_environment;
        }
        bool isEmpty(){
            if(_environment.empty()){
                return true;
            }
            return false;
        }
    private:
        std::vector<ConsoleEnvironment*> _environment;
    };
}

#endif //_CONSOLEENVIRONMENTHANDLER_H