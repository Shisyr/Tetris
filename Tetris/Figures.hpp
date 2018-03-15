//
//  Figures.hpp
//  Tetris
//
//  Created by Шисыр Мухаммед Шарипович on 15.11.17.
//  Copyright © 2017 Шисыр Мухаммед Шарипович. All rights reserved.
//

#ifndef Figures_hpp
#define Figures_hpp

#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>

class Figures{
protected:
    const int W = 10;
    const int H = 20;
    int squareX;
    int squareY;
    int outline;
    int sizeW;
    int sizeH;
    float sizeF;
    int typeOfFigure;
    int changeFigure;
    std::vector<sf::RectangleShape> row;
    std::vector<sf::RectangleShape> allFigures;
    std::vector< std::vector<int> > mainFig;
    std::vector< std::vector<int> > t{{1, 1, 1, 0},
                            {0, 1, 0, 0},};
    
    std::vector< std::vector<int> > fig1{{1, 1, 1, 0},
                               {1, 0, 0, 0}};
    
    std::vector< std::vector<int> > fig2{{1, 1, 0, 0},
                               {1, 1, 0, 0}};
    
    std::vector< std::vector<int> > fig3{{1, 1, 1, 0},
                               {0, 0, 1, 0}};
    
    std::vector< std::vector<int> > fig4{{1, 1, 1, 1},
                               {0, 0, 0, 0}};
    
    std::vector< std::vector<int> > fig5{{1, 1, 0, 0},
                               {0, 1, 1, 0}};
    
    std::vector< std::vector<int> > fig6{{0, 1, 1, 0},
                               {1, 1, 0, 0}};
    
public:
    Figures(int screenX, int screenY, int thinkness, float sizeFigure, std::vector<sf::RectangleShape> allF);
    Figures();
    void setTypeOfFigure(int type);
    int getTypeOfFigure();
    std::vector<sf::RectangleShape> getFullForm();
    void setFullForm(std::vector<sf::RectangleShape> v);
    void chooseFigure();
    void init();
    void moveRight();
    void moveLeft();
    void moveDown();
    void turnFigure();
    bool isPossibleDown();
    std::vector<sf::RectangleShape> getFigures();
    void setFigures(std::vector<sf::RectangleShape> f);
private:
    void turnFig0();
    void turnFig1();
    void turnFig3();
    void turnFig4();
    void turnFig5();
    void turnFig6();
    bool isPossibleRight();
    bool isPossibleLeft();
    bool isPossibleTurn(sf::RectangleShape s, int x, int y);
    
};

#endif /* Figures_hpp */
