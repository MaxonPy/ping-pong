#include <stdio.h> 
#include <stdbool.h>


#define width       80 // ширина 
#define height      25 // высота 

#define LEFT_WALL   0
#define RIGHT_WALL  79 
#define TOP_WALL    0
#define BOTTOM_WALL 24

typedef struct Paddle Paddle;
typedef struct Player Player;
typedef struct Ball Ball;
typedef struct Direction Direction;


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

const char hor = '-';
const char ver = '|'; 
const char ball1 = '*';

void draw_field(Paddle paddle1, Paddle paddle2, Ball ball) { 
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (row == TOP_WALL || row == BOTTOM_WALL)
                printf("%c", hor);
            else if (col == LEFT_WALL || col == RIGHT_WALL)
                printf("%c", ver);
            else if ((col == paddle1.x && row >= paddle1.y && row < paddle1.y + 3) ||
                (col == paddle2.x && row >= paddle2.y && row < paddle2.y + 3))
                printf("%c", ver);
            else if ((col == ball.x) && (row == ball.y)) 
                printf("%c", ball1);
            else
                printf(" ");
        }
        printf("\n");
    }   
}

Player player1, player2;

Ball ball = {.x = 10, .y = 10, .dir={.dx = 1, .dy = 1}}; 
void init_game() { 
    player1.score = 0;
    player1.paddle.x = 1;
    player1.paddle.y = 10;

    player2.score = 0;
    player2.paddle.x = 78;
    player2.paddle.y = 10;
    
}

int main() { 
    init_game(); 
    draw_field(player1.paddle, player2.paddle, ball);
    return 0; 
}


