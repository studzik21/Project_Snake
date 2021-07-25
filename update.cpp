//
// Created by Patryk on 04.06.2021.
//
#include "engine.h"

void Engine::update() {
    if(timeSinceLastMove.asSeconds()>=seconds(1.f / speed).asSeconds()){
        Vector2f currentPos = snake[0].getPosition();
        Vector2f lastPos= currentPos;

        if(add) {
            growUp();
            add=false;
        }
        switch(dir){
            case direction::right:
                snake[0].setPosition(Vector2f((float)((int)(currentPos.x+20+800)%800),currentPos.y));
                break;
            case direction::left:
                snake[0].setPosition(Vector2f((float)((int)(currentPos.x-20+800)%800),currentPos.y));
                break;
            case direction::up:
                snake[0].setPosition(Vector2f(currentPos.x,(float)((int)(currentPos.y-20+600)%600)));
                break;
            case direction::down:
                snake[0].setPosition(Vector2f(currentPos.x,(float)((int)(currentPos.y+20+600)%600)));
                break;

        }

        for(int i=1;i<snake.size();i++){
            currentPos = snake[i].getPosition();
            snake[i].setPosition(lastPos);
            lastPos=currentPos;
        }

        for(auto &s : snake)
            s.update();

        if(snake[0].getShape().getGlobalBounds().intersects(eat.getField().getGlobalBounds())) {
            randEatPos();
            add= true;
            speed+=0.3;
            score+=5;
        }
        if(score==100) state=State::won;
        else {
            for (int i = 1; i < snake.size(); i++) {
                if (snake[0].getShape().getGlobalBounds().intersects(snake[i].getShape().getGlobalBounds()))
                    state = State::lose;
            }
        }

        timeSinceLastMove = Time::Zero;
    }


}
