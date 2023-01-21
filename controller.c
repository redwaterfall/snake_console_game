
#include "controller.h"
void controller(int *dir){
    
    if (kbhit()) {
        char keyPressed = getch(); 
        //UP
        if(keyPressed == 'w'){
            *dir = -7;
        }
        //UP
        if(keyPressed == 's'){
            *dir = 7;
        }
        //LEFT
        if(keyPressed == 'a'){
            *dir = -1;
        }
        //RIGHT
        if(keyPressed == 'd'){
            *dir = 1;
        }
        // switch (getch())
        // {
        // case 'w':
        //     direction = -7;
        //     break;
        // case 's':
        //     direction = 7;
        //     break;
        // case 'a':
        //     direction = -1;
        //     break;
        // case 'd':
        //     direction = 1;
        //     break;
        // }
    }
    
}