//
//  AbstractMenu.cpp
//  Tetris
//
//  Created by Шисыр Мухаммед Шарипович on 11.12.17.
//  Copyright © 2017 Шисыр Мухаммед Шарипович. All rights reserved.
//

#include "AbstractMenu.hpp"


AbstractMenu::AbstractMenu(sf::RenderWindow& win, float w, float h) : window(win), width(w), height(h){
    
    img.loadFromFile("/Users/Mukhamed/Downloads/logo/logo_5.png");
    t.loadFromImage(img);
    s.setTexture(t);
    s.setPosition(width / 5 + (width / 12), 0);
    
    if(!font.loadFromFile("/Users/Mukhamed/Downloads/fonts/Bold.ttf")){
        //error
    }
}
