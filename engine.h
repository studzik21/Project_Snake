//
// Created by Patryk on 04.06.2021.
//

#ifndef SNAKE_ENGINE_H
#define SNAKE_ENGINE_H


#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <deque>
#include "Snake.h"
#include "Eat.h"

using namespace sf;
using namespace std;

enum direction{
    right =0,
    down =1,
    left =2,
    up = 3
};
enum State{
    running = 0,
    lose = 1,
    won =2
};

class Engine {
    RenderWindow window;
    vector<Snake> snake;
    direction dir = direction::right;
    Time timeSinceLastMove;
    bool add=false;
    State state;
    float speed;
    int score;

    Font font;
    Text title;
    Text scoreText;
    RectangleShape border;
    CircleShape head;

    Eat eat;

public:
    Engine();

    void run();

    void draw();

    void input();

    void growUp();

    void update();

    void randEatPos();

    void startGame();

    direction getDir() const;

    void setDir(direction dir);

};

#endif //SNAKE_ENGINE_H
