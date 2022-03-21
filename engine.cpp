//
// Created by Patryk on 04.06.2021.
//

#include "engine.h"

Engine::Engine(){
    window.create(VideoMode(800,600),"Snake",Style::Default);
    window.setFramerateLimit(60);
    font.loadFromFile("../arial.ttf");

    title.setString("S n a k e");
    title.setFont(font);
    title.setFillColor(Color::Blue);
    title.setCharacterSize(20);
    title.setStyle(Text::Bold);

    title.setPosition(400-title.getLocalBounds().width,-5);

    scoreText.setFont(font);
    scoreText.setFillColor(Color::Blue);
    scoreText.setCharacterSize(20);
    scoreText.setPosition(0,-5);

    border.setPosition(0,0);
    border.setSize(Vector2f(800,20));
    border.setFillColor(Color::White);

    head.setRadius(10);
    head.setFillColor(Color::Green);
    startGame();

}

void Engine::run() {
    Clock clock;
    while (window.isOpen()){
        Time dt = clock.restart();
        if(state == State::lose || state== State::won){
            draw();
            input();
        }
        else {
            input();
            update();
            draw();
        }
        timeSinceLastMove+=dt;
    }

}

void Engine::draw() {
    window.clear(Color::Black);
    window.draw(border);
    window.draw(title);
    scoreText.setString("Score "+to_string(score));
    window.draw(scoreText);

    if(state==State::running) {
        for (auto &s : snake) {
            window.draw(s.getShape());
        }

        window.draw(eat.getField());

    }
    if(state==State::lose){


        string s1 = "GAMEOVER! Your score was "+ to_string(score)+ "\n";
        string s2 = "Press ENTER to play again!";
        Text text1(s1,font,20);
        Text text2(s2,font,20);
        text1.setFillColor(Color::Red);
        text2.setFillColor(Color::Red);
        text1.setPosition(300,250);
        text2.setPosition(300,280);

        window.draw(text1);
        window.draw(text2);

    }
    if(state==State::won){
        string s1 = "Congratulations! You score 100 points!";
        string s2 = "Press ENTER to play again!";
        Text text1(s1,font,20);
        Text text2(s2,font,20);
        text1.setFillColor(Color::Red);
        text2.setFillColor(Color::Red);
        text1.setPosition(240,250);
        text2.setPosition(260,280);

        window.draw(text1);
        window.draw(text2);

    }
    window.display();

}

void Engine::input() {
    Event event{};

    while(window.pollEvent(event)){
        if(event.type == Event::Closed){
            window.close();
        }
        if(event.type==Event::KeyPressed){

            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
            }
            if(Keyboard::isKeyPressed(Keyboard::Right)){
                if(getDir()==direction::up || getDir() == direction::down) {
                    setDir(direction::right);

                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Left)){
                if(getDir()==direction::up || getDir() == direction::down) {
                    setDir(direction::left);

                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Up)){
                if(getDir()==direction::right || getDir() == direction::left) {
                    setDir(direction::up);

                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Down)){
                if(getDir()==direction::right || getDir() == direction::left) {
                    setDir(direction::down);

                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Enter)){
                startGame();
            }
            if(Keyboard::isKeyPressed(Keyboard::LShift)){
                turbo= !turbo;
            }


        }



    }

}

direction Engine::getDir() const {
    return dir;
}

void Engine::setDir(direction dir) {
    Engine::dir = dir;
}

void Engine::growUp() {
    Vector2f newPos = snake[snake.size()-1].getPosition();
    snake.emplace_back(newPos);
}

void Engine::randEatPos() {
    Vector2f newPos;
    srand(time(NULL));
    bool badPos = false;
    do{
        badPos = false;
        newPos.x = (float)(1+rand()%38) * 20;
        newPos.y = (float)(1+rand()%28) * 20;

        for(auto &s: snake){
            if(s.getShape().getGlobalBounds().intersects(Rect<float>(newPos.x,newPos.y,20,20))) {
                badPos = true;
                break;
            }
        }

    } while (badPos);

    eat.setPosition(newPos);


}

void Engine::startGame() {
    snake.clear();
    snake.emplace_back(Vector2f(100,100));
    snake.emplace_back(Vector2f(80,100));
    snake.emplace_back(Vector2f(60,100));
    state = State::running;
    dir=direction::right;
    speed=2;
    score=0;
    timeSinceLastMove = Time::Zero;
}

