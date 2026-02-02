#include <stdio.h> 
#include <stdbool.h>


#define width       80 // ширина 
#define height      25 // высота 

#define LEFT_WALL   0
#define RIGHT_WALL  79 
#define TOP_WALL    0
#define BOTTOM_WALL 24

struct Direction{ 
    int dx; 
    int dy; 
}; 

struct Ball { 
    int x;
    int y; 
    struct Direction dir; 
};

struct Paddle {
    int x; 
    int y; 
};

struct Player {
    int score; 
    struct Paddle paddle; 
};

struct GameState { 
    bool type_state; 
};

char hor = '-';
char ver = '|'; 


void draw_field() { 
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (row == TOP_WALL || row == BOTTOM_WALL)
                printf("%c", hor);
            else if (col == LEFT_WALL || col == RIGHT_WALL)
                printf("%c", ver);
            else
                printf(" ");
        }
        printf("\n");
    }   
}

int main() { 
    draw_field();
    return 0; 
}