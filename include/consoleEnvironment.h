#ifndef CONSOLEENVIRONMENT_H
#define CONSOLEENVIRONMENT_H
#include "includes.h"

namespace CE{
    class ConsoleEnvironment{
    private:
        typedef long long lSize;
    public: // --------------------- CREATION --------------------- 
        enum BodyType {RigidBody, StaticBody};
        enum AreaBodyType {Box, Circle};
        ConsoleEnvironment(char chr, lSize posX = 0, lSize posY = 0, BodyType bType = RigidBody, AreaBodyType aType = Box, bool show = true){
            // others
            _chr = chr;
            visibility(show);

            // type
            _bType = bType;
            _aType = aType;

            // position
            _posX       = posX;
            _posY       = posY;
            _prevPosX   = posX;
            _prevPosY   = posY;

        }
    
    public: // --------------------- FUNCTIONALITY --------------------- 
        void visibility(bool isTrue){
            _visibility = isTrue;
        }
        void setPosition(lSize x, lSize y){
            _posX = x;
            _posY = y;
        }
        void setChar(char chr){
            _chr = chr;
        }
    public: // --------------------- GETTER ---------------------
        lSize getPositionX(){
            return _posX;
        }
        lSize getPositionY(){
            return _posY;
        }
        lSize getPrevPositionX(){
            return _prevPosX;
        }
        lSize getPrevPositionY(){
            return _prevPosY;
        }
        char getChar(){
            return _chr;
        }
    void updatePrevPos(){
        _prevPosX = _posX;
        _prevPosY = _posY;
    }    
    private: // --------------------- CHECKER --------------------- 
        void updatePrevPosition(lSize x, lSize y){
            _prevPosX = x;
            _prevPosY = y;
        }

    private: // --------------------- VARIABLES --------------------- 
        lSize           _posX       = 0,
                        _posY       = 0,
                        _prevPosX   = 0,
                        _prevPosY   = 0;
        BodyType        _bType      = StaticBody;
        AreaBodyType    _aType      = Box;
        char            _chr        = ' ';
        bool            _visibility = true;
    };

};

#endif // CONSOLEENVIRONMENT_H