#ifndef CONSOLE_ENTITY_H
#define CONSOLE_ENTITY_H

#include "observer.h"
#include <string>


namespace CE{
    class AbstractConsoleEntity{
    public: // move function
        virtual void move(int pX, int pY, int nX, int nY) = 0;
        virtual void moveUp(int num) = 0;
        virtual void moveLeft(int num) = 0;
        virtual void moveDown(int num) = 0;
        virtual void moveRight(int num) = 0;
    };
    class ConsoleEntity : AbstractConsoleEntity{
    public:
        typedef std::string::size_type sType;
    public: // constructor
        ConsoleEntity(Observer *observer, char character, int x = 0, int y = 0): _observer(observer), _character(character), _pX(x), _pY(y), _cX(x), _cY(y){
            _observer->notifyInitialPosition(x,y,character);
        }
    public: // movement
        void move(int pX, int pY, int nX, int nY){
            _pX = pX;
            _pY = pY;
            _cX = nX;
            _cY = nY;
            _observer->notifyPosition(pX, pY, nX, nY);
        }
        void movePre(int pX, int pY, int nX, int nY){
            _pX = pX;
            _pY = pY;
            _cX = nX;
            _cY = nY;
            _observer->notifyPrePosition(pX, pY, nX, nY);
        }
        void moveUp(int num){
            move(_cX, _cY, _cX, _cY-num);
        }
        void moveLeft(int num){
            move(_cX, _cY, _cX-num, _cY);
        }
        void moveDown(int num){
            move(_cX, _cY, _cX, _cY+num);
        }
        void moveRight(int num){
            move(_cX, _cY, _cX+num, _cY);
        }
    
    public: // getters
        sType getPreviousX(){
            return _pX;
        }
        sType getPreviousY(){
            return _pY;
        }
        sType getCurrentX(){
            return _cX;
        }
        sType getCurrentY(){
            return _cY;
        }
    private:
        sType _pX, _pY;
        sType _cX, _cY;
        CE::Observer *_observer;
        char _character;
    };

    // handles bunch of ConsoleEntity (TO BE IMPLEMENTED);
    class ConsoleEntityHandler : AbstractConsoleEntity{
    public: // utility
        void attach(ConsoleEntity *entity){
            _entities.push_back(entity);
        }
    public: // ConsoleEntity Stuffs
        void move(int pX, int pY, int nX, int nY){
            auto entitySize = _entities.size();
            for(int i = 0; i < entitySize; ++i){
                _entities[i]->move(pX,pY,nX,nY);
            }
        }
        void moveUp(int num){
            auto entitySize = _entities.size();
            for(int i = 0; i < entitySize; ++i){
                _entities[i]->moveUp(num);
            }
        }
        void moveLeft(int num){
            auto entitySize = _entities.size();
            for(int i = 0; i < entitySize; ++i){
                _entities[i]->moveLeft(num);
            }
        }
        void moveDown(int num){
            auto entitySize = _entities.size();
            for(int i = 0; i < entitySize; ++i){
                _entities[i]->moveDown(num);
            }
        }
        void moveRight(int num){
            auto entitySize = _entities.size();
            for(int i = 0; i < entitySize; ++i){
                _entities[i]->moveRight(num);
            }
        }
    private:
        std::vector<ConsoleEntity*> _entities;
    };
}
#endif // CONSOLE_ENTITY_H