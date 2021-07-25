//
// Created by Patryk on 04.06.2021.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <SFML/Graphics.hpp>
using namespace sf;



class Snake{
    Vector2f position;
    RectangleShape field;

public:

public:
    void setPosition(Vector2f position);

public:
    explicit Snake(Vector2f pos);

    void update();

    const Vector2f &getPosition() const;

    RectangleShape getShape();

};




#endif //SNAKE_SNAKE_H
