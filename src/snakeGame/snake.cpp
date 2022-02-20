#include "../../include/ConsoleEngine.h"


void moveUp(CE::ConsoleEntity* entity){
    entity->moveUp(1);
}
void moveLeft(CE::ConsoleEntity* entity){
    entity->moveLeft(1);
}
void moveDown(CE::ConsoleEntity* entity){
    entity->moveDown(1);
}
void moveRight(CE::ConsoleEntity* entity){
    entity->moveRight(1);
}

void createBody(){

}

void changeMovement(int &direction, bool &inGame){
    while(inGame){
        char keyHit = _getwch();
        if(keyHit == 'w'){
            direction = 1;
        }else if(keyHit == 'a'){
            direction = 2;
        }else if(keyHit == 's'){
            direction = 3;
        }else if(keyHit == 'd'){
            direction = 4;
        }else if(keyHit == 'x'){
            inGame = false;
        }
    }
}

void moveSnakeBody(std::vector<CE::ConsoleEntity*> &entities){
    auto entitySize = entities.size();
    
    int head_pX = entities[0]->getPreviousX(),
        head_pY = entities[0]->getPreviousY();
    for(int i = 1; i < entitySize; ++i){
        // save the previous values
        int entity_pX = entities[i]->getPreviousX(),
            entity_pY = entities[i]->getPreviousY(),
            entity_cX = entities[i]->getCurrentX(),
            entity_cY = entities[i]->getCurrentY();
        // move the entity to the previous position of the head
        entities[i]->move(entity_cX, entity_cY, head_pX, head_pY);
        // make the index of the head be equal to the entities previous position
        head_pX = entity_pX;
        head_pY = entity_pY;
    }
}

void moveSnake(int &direction, bool &inGame, std::vector<CE::ConsoleEntity*> &entities){
    while(inGame){
        auto entitySize = entities.size();
        if(direction == 1){
            moveUp(entities[0]);
        }else if(direction == 2){
            moveLeft(entities[0]);
        }else if(direction == 3){
            moveDown(entities[0]);
        }else if(direction == 4){
            moveRight(entities[0]);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        //moveSnakeBody(entities);
    }
}


int main(){

    bool inGame = true;

    int _screenWidth = 20,
        _screenHeight = 10;
    int _direction = 4;

    CE::ConsoleScreen *_screen = new CE::ConsoleScreen(_screenWidth,_screenHeight,' ');
    CE::Observer *_headObserver = new CE::Observer(_screen);
    CE::Observer *_boundaryObserver = new CE::Observer(_screen);

    CE::ConsoleEntityHandler _boundariesHandler;
    { // creating boundaries
        for(int i = 0; i < _screenWidth; ++i){
        CE::ConsoleEntity *_tempTopEntity = new CE::ConsoleEntity(_boundaryObserver,'#', i, 0);
        _boundariesHandler.attach(_tempTopEntity);
        }
        for(int i = 1; i < _screenHeight-1; ++i){
            CE::ConsoleEntity *_tempLeftEntity = new CE::ConsoleEntity(_boundaryObserver,'#',0, i);
            CE::ConsoleEntity *_tempRightEntity = new CE::ConsoleEntity(_boundaryObserver,'#',_screenWidth-1, i);
            _boundariesHandler.attach(_tempLeftEntity);
            _boundariesHandler.attach(_tempRightEntity);
        }
        for(int i = 0; i < _screenWidth; ++i){
            CE::ConsoleEntity *_tempTopEntity = new CE::ConsoleEntity(_boundaryObserver,'#', i, _screenHeight-1);
            _boundariesHandler.attach(_tempTopEntity);
        }
    }

    CE::ConsoleEntity *_head = new CE::ConsoleEntity(_headObserver, 'P',2,1);
    std::vector<CE::ConsoleEntity*> _entities = {_head};

    // threads
    {
        std::thread changeMovementThread(changeMovement, std::ref(_direction), std::ref(inGame));
        changeMovementThread.detach();
        std::thread moveSnakeThread(moveSnake, std::ref(_direction), std::ref(inGame), std::ref(_entities));
        moveSnakeThread.detach();
    }

    while(inGame){
        _screen->print();
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        system("cls");
    }
    return 0;
}