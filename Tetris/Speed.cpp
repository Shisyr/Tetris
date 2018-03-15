//
//  Speed.cpp
//  Tetris
//
//  Created by Шисыр Мухаммед Шарипович on 10.12.17.
//  Copyright © 2017 Шисыр Мухаммед Шарипович. All rights reserved.
//

#include "Speed.hpp"
#include <iostream>

using namespace sf;
using namespace std;

Speed::Speed(sf::RenderWindow& win, float width, float height): AbstractMenu(win, width, height){
    for(int i = 0;i < NUMBER_SPEED;i++){
        menu[i].setFont(font);
        menu[i].setCharacterSize(50);
        menu[i].setFillColor(sf::Color::White);
        menu[i].setString("Level: " + std::to_string(i + 1));
        menu[i].setPosition(width / 3 + (width / 12), height / 2 + (menu[i].getCharacterSize() * i) + menu[i].getCharacterSize());
    }
    menu[0].setFillColor(sf::Color::Red);
}

int Speed::run(){
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed) {
                window.close();
            }
            int c = control();
            if(c != 1){
                return c;
            }
        }
        window.clear();
        draw();
        window.display();
    }
    return -1;
}

int Speed::control(){
    if(event.type == Event::EventType::MouseMoved){
        for(int i = 0;i < menu.size();i++){
            menu[i].setFillColor((isCheckButton(menu[i])) ? Color::Red : Color::White);
        }
    }
    if(event.type == Event::KeyPressed and event.key.code == Keyboard::Escape){
        return 0;
    }
    if(event.type == Event::KeyPressed and event.key.code == Keyboard::Down){
        moveDown();
    }
    if(event.type == Event::KeyPressed and event.key.code == Keyboard::Up){
        moveUp();
    }
    if(event.type == Event::KeyPressed and event.key.code == Keyboard::Return){
        string s = menu[selectedSpeed].getString();
        speed = (s == "Level: 1")? 900 : speed;
        speed = (s == "Level: 2")? 600 : speed;
        speed = (s == "Level: 3")? 300 : speed;
        return 3;
    }
    if(event.type == Event::EventType::MouseButtonPressed){
        for(int i = 0;i < menu.size();i++){
            if(isCheckButton(menu[i])){
                string s = menu[i].getString();
                speed = (s == "Level: 1")? 900 : speed;
                speed = (s == "Level: 2")? 600 : speed;
                speed = (s == "Level: 3")? 300 : speed;
                return 3;
            }
        }
    }
    return 1;
}

void Speed::moveDown(){
    if(selectedSpeed + 1 < NUMBER_SPEED){
        menu[selectedSpeed].setFillColor(sf::Color::White);
        selectedSpeed++;
        menu[selectedSpeed].setFillColor(sf::Color::Red);
    }
}
void Speed::moveUp(){
    if(selectedSpeed - 1 >= 0){
        menu[selectedSpeed].setFillColor(sf::Color::White);
        selectedSpeed--;
        menu[selectedSpeed].setFillColor(sf::Color::Red);
    }
}
void Speed::draw(){
    window.draw(s);
    for(int i = 0;i < NUMBER_SPEED;i++){
        window.draw(menu[i]);
    }
}

int Speed::getSpeed(){
    return changeToSecond;
}

bool Speed::isCheckButton(Text text){
    int eX = event.mouseMove.x;
    int eY = event.mouseMove.y;
    int sX = text.getPosition().x;
    int sY = text.getPosition().y;
    int size = text.getCharacterSize();
    if(eX >= sX and eX <= sX + (size * text.getString().getSize()) and eY >= sY and eY <= sY + size){
        return true;
    }
    eX = event.mouseButton.x;
    eY = event.mouseButton.y;
    if(eX >= sX and eX <= sX + (size * text.getString().getSize()) and eY >= sY and eY <= sY + size){
        return true;
    }
    return false;
}
