//
//  Game.hpp
//  Tetris
//
//  Created by Шисыр Мухаммед Шарипович on 13.12.17.
//  Copyright © 2017 Шисыр Мухаммед Шарипович. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Figures.hpp"
#include <vector>
#include <queue>
#include "AbstractMenu.hpp"
#include <fstream>

class Game: public AbstractMenu{
public:
    Game(sf::RenderWindow& win);
    void draw();
    void nextFigure();
    void deleteFigure();
    bool isEndOfGame();
    void controlFigure();
    void newFigure();
    void initScreen();
    int run();
    void drawScreen();
    void updateScore();
    
private:
    sf::Text maxScore;
    std::ifstream rScore;
    sf::Text textScore;
    sf::Font fontScore;
    sf::Clock clock;
    int score;
    bool isExit;
    int W = 10;
    int H = 20;
    int windowX = 1200;
    int windowY = 900;
    sf::RectangleShape screen[20][10];
    int screenY = 0;
    int screenX;
    float sizeScreen;
    int Thinkness = 2;
    float delay = 0;
    std::vector<sf::RectangleShape> form;
    std::vector<Figures> f;
    std::queue<Figures> f1;
    std::vector<sf::RectangleShape> r;
};
#endif /* Game_hpp */
