#include "raylib.h"
#include"Bricks.h"
#include"Player.h"
#include <iostream>
#include <stdio.h>  
#include <math.h> 
#include <vector>
#include <string>


using namespace std;

//Editor Variable
void Update();
void Draw();
void DrawUi();
void Start();
void Load();

//Setup la taille de l'écran
int const screenWidth = 800;
int const screenHeight = 600;

Player player = Player(25, 25, { 100,100 });

const float brickWidth{ 40.0 };
const float brickHeight{ 40.0 };
vector<Bricks> bricks;


const int collumnNb{ 20 };
const int rowsNb{ 15 };

int trackTile[collumnNb * rowsNb]{
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,
    1,0,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,
    1,0,0,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,1,1,
    1,0,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,0,1,1,
    1,0,0,1,1,1,1,1,0,0,1,0,1,0,0,0,1,1,1,1,
    1,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,
    1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,
    1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,
    1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};


void createHandTrack(int trackFileP[collumnNb*rowsNb] ) {
    for (int i = 0; i < rowsNb; i++) {
        for (int j = 0; j < collumnNb; j++) {

            Bricks brick = Bricks{ brickWidth-2 , brickHeight -2 ,{brickWidth * j,brickHeight * i } };
            int index = j + i *collumnNb;

            if (trackFileP[index] == 0) {
                brick.setIsHere(0);
            }
            bricks.emplace_back(brick);
            
        }
    }
}

/*void createBricks(int collumnP, int rowsP, float brickheightP) {



    for (int i = 0; i < rowsP; i++) {
        for (int j = 0; j < collumnP; j++) {
            Bricks brick = Bricks{ brickWidth - 5, brickheightP - 5 ,{brickWidth * j,brickheightP * i + brickHeight / 2} };
            bricks.emplace_back(brick);
        }
    }
}*/
void drawBricks() {
    for each (Bricks brick in bricks)
    {
        brick.draw();
    }
}

void collision() {
    int collumn = floor(player.getCenter().x / brickWidth);
    int rows = floor(player.getCenter().y / brickHeight);
    int index = collumn + rows * collumnNb;

    if (index < bricks.size()) {
        if (bricks[index].getIsHere() == 1 ) {
            bricks[index].setIsHere(0);

            float previousBallX = player.getCenter().x - player.getSpeed().x;
            float previousBallY = player.getCenter().y - player.getSpeed().y;
            int previousTileCol = floor(previousBallX / brickWidth);
            int previousTileRow = floor(previousBallY / brickHeight);

            if (previousTileCol != collumn) {
                player.reverseSpeed(1);
            }
            if (previousTileRow != rows) {
                player.reverseSpeed(2);
            }
        }
    }

}

int main(int argc, char* argv[])
{

    //Créer un écran et on met les fps à 60
    string windowName = "GameWindow";
    InitWindow(screenWidth, screenHeight, windowName.c_str());

    //ToggleFullscreen();
    SetWindowPosition(0, 10);
    SetTargetFPS(60);

    Load();
    Start();

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        Update();
        // Draw
        Draw();       

    }

    CloseWindow();

    return 0;


}

void Start() {

}

void Load()
{
    player.setSpeed({ -5,-5 });
    createHandTrack(trackTile);


}

void Update()
{
    //Ball wall collision
    if (player.getPos().x < 0) {
        player.reverseSpeed(1);
    }
    if (player.getPos().y < 0 + player.getHeight()) {
        player.reverseSpeed(2);
    }
    if (player.getPos().x > screenWidth - player.getWidth()) {
        player.reverseSpeed(1);
    }
    if (player.getPos().y > screenHeight) {
        player.reverseSpeed(2);
    }

    // ball stop
    if (IsKeyDown(KEY_SPACE)) {
        player.setSpeed({ 0,0 });

    }

    //player.update();
    collision();
}

void Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);


    drawBricks();
    //player.draw();

    

    DrawUi();
    EndDrawing();
}

void DrawUi()
{

}