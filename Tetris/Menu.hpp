//
//  Menu.hpp
//  Tetris
//
//  Created by Шисыр Мухаммед Шарипович on 10.12.17.
//  Copyright © 2017 Шисыр Мухаммед Шарипович. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "AbstractMenu.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu: public AbstractMenu{
public:
    Menu(sf::RenderWindow& win, float width, float height);
    void draw();
    int run();
    bool isCheckButton(sf::Text sp);
    int control();
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    std::vector<sf::Text> getTexts();
    void setTexts(std::vector<sf::Text> sp);
    
    private:
    int selectedItemIndex;
    std::vector<sf::Text> menu{MAX_NUMBER_OF_ITEMS};
};

#endif /* Menu_hpp */
