//
// Created by Patryk on 04.06.2021.
//

#include "eat.h"

Eat::Eat() {
    Vector2f startPos(400,300);
    field.setSize(Vector2f (20,20));
    field.setFillColor(Color::Red);
    field.setPosition(startPos);

}

void Eat::setPosition(Vector2f pos) {
    field.setPosition(pos);
}

RectangleShape Eat::getField() {
    return field;
}



