//
// Created by Patryk on 04.06.2021.
//

#include "Snake.h"


Snake::Snake(Vector2f pos) {
    position=pos;
    field.setSize(Vector2f (20,20));
    field.setFillColor(Color::Green);
    field.setPosition(pos);
}

void Snake::update() {
    field.setPosition(position);
}

void Snake::setPosition(Vector2f position) {
    Snake::position = position;
}

const Vector2f &Snake::getPosition() const {
    return position;
}

RectangleShape Snake::getShape() {
    return field;
}


