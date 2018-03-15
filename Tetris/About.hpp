//
//  About.hpp
//  Tetris
//
//  Created by Шисыр Мухаммед Шарипович on 10.12.17.
//  Copyright © 2017 Шисыр Мухаммед Шарипович. All rights reserved.
//

#ifndef About_hpp
#define About_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "AbstractMenu.hpp"

class About: public AbstractMenu{
public:
    About(sf::RenderWindow& win, float width, float height);
    void draw();
    int run();
    void allEvents();
private:
    sf::Text menu;
};
#endif /* About_hpp */
