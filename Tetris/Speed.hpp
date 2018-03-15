//
//  Speed.hpp
//  Tetris
//
//  Created by Шисыр Мухаммед Шарипович on 10.12.17.
//  Copyright © 2017 Шисыр Мухаммед Шарипович. All rights reserved.
//

#ifndef Speed_hpp
#define Speed_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "AbstractMenu.hpp"

#define NUMBER_SPEED 3
class Speed: public AbstractMenu{
public:
    Speed(sf::RenderWindow& win, float width, float height);
    void draw();
    int run();
    int control();
    int getSpeed();
    bool isCheckButton(sf::Text text);
    void moveDown();
    void moveUp();
    
private:
    int changeToSecond = 900;
    int selectedSpeed = 0;
    std::vector< sf::Text > menu{NUMBER_SPEED};
};
#endif /* Speed_hpp */
