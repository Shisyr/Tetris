//
//  About.cpp
//  Tetris
//
//  Created by Шисыр Мухаммед Шарипович on 10.12.17.
//  Copyright © 2017 Шисыр Мухаммед Шарипович. All rights reserved.
//

#include "About.hpp"

using namespace sf;

About::About(sf::RenderWindow& win, float width, float height) : AbstractMenu(win, width, height){
    menu.setFont(font);
    menu.setFillColor(sf::Color::White);
    menu.setString("This game is to connect different figures in one glass.\nCreator of this game is Shisyr Mukhamed");
    menu.setPosition(width / 4, height / 2);
}
int About::run(){
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed) {
                window.close();
            }
            if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Escape){
                    return 0;
                }
            }
            
        }
        window.clear();
        draw();
        window.display();
    }
    return -1;
}

void About::draw(){
    window.draw(s);
    window.draw(menu);
}
