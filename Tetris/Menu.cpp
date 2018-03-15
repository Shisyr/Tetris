//
//  Menu.cpp
//  Tetris
//
//  Created by Шисыр Мухаммед Шарипович on 10.12.17.
//  Copyright © 2017 Шисыр Мухаммед Шарипович. All rights reserved.
//

#include "Menu.hpp"
#include <iostream>

using namespace sf;
using namespace std;

Menu::Menu(sf::RenderWindow& win, float width, float height) : AbstractMenu(win, width, height){
    
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(width / 3 + (width / 9), height / 2 + menu[0].getCharacterSize());
    
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("About Tetris");
    menu[1].setPosition(width / 3 + (width / 9), height / 2 + (menu[1].getCharacterSize() * 3));
    
    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(width / 3 + (width / 9), height / 2 + (menu[2].getCharacterSize() * 5));
}


int Menu::run(){
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed) {
                window.close();
            }
            int c = control();
            if(c != -1){
                return c + 1;
            }
        }
        window.clear();
        draw();
        window.display();
    }
    return -1;
}


int Menu::control(){
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::Escape){
            window.close();
        }
        if(event.key.code == Keyboard::Down){
            MoveDown();
        }
        if(event.key.code == Keyboard::Up){
            MoveUp();
        }
        if(event.key.code == Keyboard::Return){
            if(menu[selectedItemIndex].getString() == "Exit"){
                window.close();
            }
            return selectedItemIndex;
        }
    }
    
    if(event.type == Event::MouseMoved){
        for(int i = 0;i < menu.size();i++){
            menu[i].setFillColor((isCheckButton(menu[i])) ? Color::Red : Color::White);
        }
    }
    
    if(event.type == Event::EventType::MouseButtonPressed){
        for(int i = 0;i < menu.size();i++){
            if(isCheckButton(menu[i])){
                string s = menu[i].getString();
                if(s == "Play"){
                    selectedItemIndex = 0;
                }
                else if(s == "About Tetris"){
                    selectedItemIndex = 1;
                }
                else if(s == "Exit"){
                    window.close();
                }
                return selectedItemIndex;
            }
        }
    }
    return -1;
}



bool Menu::isCheckButton(Text sp){
    int eX = event.mouseMove.x;
    int eY = event.mouseMove.y;
    int sX = sp.getPosition().x;
    int sY = sp.getPosition().y;
    int size = sp.getCharacterSize();
    if(eX >= sX and eX <= sX + (size * sp.getString().getSize()) and eY >= sY and eY <= sY + size){
        return true;
    }
    eX = event.mouseButton.x;
    eY = event.mouseButton.y;
    if(eX >= sX and eX <= sX + (size * sp.getString().getSize()) and eY >= sY and eY <= sY + size){
        return true;
    }
    return false;
}

void Menu::draw(){
    window.draw(s);
    for(int i = 0;i < MAX_NUMBER_OF_ITEMS;i++){
        window.draw(menu[i]);
    }
}
void Menu::MoveDown(){
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveUp(){
    if(selectedItemIndex - 1 >= 0){
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
