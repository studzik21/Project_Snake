//
// Created by Patryk on 04.06.2021.
//

#ifndef SNAKE_EAT_H
#define SNAKE_EAT_H


#include <SFML/Graphics.hpp>

using namespace sf;

class Eat{
    RectangleShape field;
public:
    Eat();
    void setPosition(Vector2f pos);
    RectangleShape getField();

};





#endif //SNAKE_EAT_H
