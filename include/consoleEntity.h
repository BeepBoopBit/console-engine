#ifndef CONSOLE_ENTITY_H
#define CONSOLE_ENTITY_H

#include "consoleScreen.h"
namespace CE{
    class ConsoleEntity{ // to be implemented
    private:
        typedef long long lSize;
    
    private: // variables
        lSize _x = 0;
        lSize _y = 0;
        lSize _prevX = 0;
        lSize _prevY = 0;
        char _chr = ' ';
        bool visibility = true;
        std::string color = "\033[0m"; // default color
        ConsoleScreen *_screen = nullptr;
    };
}

#endif