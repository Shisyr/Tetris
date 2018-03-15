//
//  AbstractMenu.hpp
//  Tetris
//
//  Created by Шисыр Мухаммед Шарипович on 11.12.17.
//  Copyright © 2017 Шисыр Мухаммед Шарипович. All rights reserved.
//

#ifndef AbstractMenu_hpp
#define AbstractMenu_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class AbstractMenu{
    public:
    AbstractMenu(sf::RenderWindow& win, float w, float h);
        virtual void draw() = 0;
        virtual int run() = 0;
    protected:
        int speed = 600;
        sf::Event event;
        int width;
        int height;
        sf::RenderWindow& window;
        sf::Image img;
        sf::Texture t;
        sf::Sprite s;
        sf::Font font;
};
#endif /* AbstractMenu_hpp */
