//
//  Figures.cpp
//  Tetris
//
//  Created by Шисыр Мухаммед Шарипович on 15.11.17.
//  Copyright © 2017 Шисыр Мухаммед Шарипович. All rights reserved.
//

#include "Figures.hpp"
#include <cmath>

using namespace sf;
using namespace std;


Figures::Figures(int screenX, int screenY, int thinkness, float sizeFigure, vector<RectangleShape> allF)
{
    squareX = screenX;
    squareY = screenY;
    outline = thinkness;
    sizeF = sizeFigure;
    allFigures = allF;
    sizeH = sizeF * H + squareY + outline;
    sizeW = sizeF * W + squareX + outline;
    changeFigure = 0;
    init();
}
Figures::Figures(){
    
}

void Figures::chooseFigure(){
//    srand(time(0));
    int r = rand() % 6;
    switch(r){
        case 0:
            mainFig = t;
            break;
        case 1:
            mainFig = fig1;
            break;
        case 2:
            mainFig = fig2;
            break;
        case 3:
            mainFig = fig3;
            break;
        case 4:
            mainFig = fig4;
            break;
        case 5:
            mainFig = fig5;
            break;
        case 6:
            mainFig = fig6;
            break;
    }
    typeOfFigure = r;
}
int Figures::getTypeOfFigure(){
    return typeOfFigure;
}
void Figures::setTypeOfFigure(int type){
    typeOfFigure = type;
}
vector<RectangleShape> Figures::getFullForm(){
    return allFigures;
}
void Figures::setFullForm(vector<RectangleShape> v){
    allFigures = v;
}
void Figures::init(){
//    srand(time(0));
    int red = rand() % 255;
    int g = rand() % 255;
    int b = rand() % 255;
    Color color(red, g, b);
    chooseFigure();
    int sizeX = sizeF - (outline * 3);
    int sizeY = sizeF - (outline * 3);
    float sY = outline + outline;
    for(int i = 0;i < mainFig.size();i++){
        float sX = (squareX + (squareX / 2));
        for(int j = 0;j < mainFig[i].size();j++){
            if(mainFig[i][j] == 1){
                RectangleShape s(Vector2f(sizeX, sizeY));
                s.setPosition(sX, sY);
                s.setFillColor(color);
                s.setOutlineThickness(2);
                s.setOutlineColor(Color::Red);
                row.push_back(s);
            }
            sX += sizeF;
        }
        sY += sizeF;
    }
}


vector<sf::RectangleShape> Figures::getFigures(){
    return row;
}
void Figures::setFigures(std::vector<sf::RectangleShape> f){
    row = f;
}
bool Figures::isPossibleDown(){
    for(int j = 0;j < row.size();j++){
        int rX = row[j].getPosition().x;
        int rY = row[j].getPosition().y;
        for(int i = 0;i < allFigures.size();i++){
            int fX = allFigures[i].getPosition().x;
            int fY = allFigures[i].getPosition().y;
            if(rY + sizeF == fY and rX == fX){
                return false;
            }
        }
        if(rY + sizeF >= sizeH){
            return false;
        }
    }
    return true;
}
bool Figures::isPossibleLeft(){
        for(int j = 0;j < row.size();j++){
            int rX = row[j].getPosition().x;
            int rY = row[j].getPosition().y;
            for(int i = 0;i < allFigures.size();i++){
                int fX = allFigures[i].getPosition().x;
                int fY = allFigures[i].getPosition().y;
                if(rX - sizeF == fX and rY == fY){
                    return false;
                }
            }
            if(rX - sizeF <= squareX){
                return false;
            }
        }
    return true;
}
bool Figures::isPossibleRight(){
        for(int j = 0;j < row.size();j++){
            int rX = row[j].getPosition().x;
            int rY = row[j].getPosition().y;
            for(int i = 0;i < allFigures.size();i++){
                int fX = allFigures[i].getPosition().x;
                int fY = allFigures[i].getPosition().y;
                if(rX + sizeF == fX and rY == fY){
                    return false;
                }
            }
            if(rX + sizeF >= sizeW){
                return false;
            }
        }
    return true;
}
void Figures::moveDown(){
    if(isPossibleDown()){
        for(int i = 0;i < row.size();i++){
            row[i].move(0, sizeF);
        }
    }
}
void Figures::moveRight(){
    if(isPossibleRight()){
        for(int i = 0;i < row.size();i++){
            row[i].move(sizeF, 0);
        }
    }
}
void Figures::moveLeft(){
    if(isPossibleLeft()){
        for(int i = 0;i < row.size();i++){
            row[i].move(-sizeF, 0);
        }
    }
}
void Figures::turnFigure(){
    if(typeOfFigure == 0){
        turnFig0();
    }
    if(typeOfFigure == 1){
        turnFig1();
    }
    if(typeOfFigure == 3){
        turnFig3();
    }
    if(typeOfFigure == 4){
        turnFig4();
    }
    if(typeOfFigure == 5){
        turnFig5();
    }
    if(typeOfFigure == 6){
        turnFig6();
    }
}
bool Figures::isPossibleTurn(RectangleShape s, int x, int y){
    int sX = s.getPosition().x + x;
    int sY = s.getPosition().y + y;
    for(int j = 0;j < allFigures.size();j++){
        int fX = allFigures[j].getPosition().x;
        int fY = allFigures[j].getPosition().y;
        if(sX == fX and sY == fY){
            return false;
        }
    }
    if(sX >= sizeW or sX <= squareX or sY >= sizeH){
        return false;
    }
    return true;
}
void Figures::turnFig0(){
    if(changeFigure == 0){
        if(isPossibleTurn(row[2], -sizeF, -sizeF)){
            row[2].move(-sizeF, -sizeF);
            changeFigure = 1;
        }
    }
    else if(changeFigure == 1){
        if(isPossibleTurn(row[3], sizeF, -sizeF)){
            row[3].move(sizeF, -sizeF);
            changeFigure = 2;
        }
    }
    else if(changeFigure == 2){
        if(isPossibleTurn(row[0], sizeF, sizeF)){
            row[0].move(sizeF, sizeF);
            changeFigure = 3;
        }
    }
    else if(changeFigure == 3){
        if(isPossibleTurn(row[2], sizeF, sizeF) and isPossibleTurn(row[3], -sizeF, sizeF) and isPossibleTurn(row[0], -sizeF, -sizeF))
        {
            row[2].move(sizeF, sizeF);
            row[3].move(-sizeF, sizeF);
            row[0].move(-sizeF, -sizeF);
            changeFigure = 0;
        }
        
        
    }
}

void Figures::turnFig1(){
    if(changeFigure == 0){
        if(isPossibleTurn(row[0], 0, -sizeF) and isPossibleTurn(row[2], -sizeF, -sizeF) and isPossibleTurn(row[3], sizeF, 0))
        {
            row[0].move(0, -sizeF);
            row[2].move(-sizeF, -sizeF);
            row[3].move(sizeF, 0);
            changeFigure = 1;
        }
    }
    else if(changeFigure == 1){
        if(isPossibleTurn(row[0], 0, sizeF) and isPossibleTurn(row[2], sizeF, 0) and isPossibleTurn(row[3], sizeF, -sizeF))
        {
            row[0].move(0, sizeF);
            row[2].move(sizeF, 0);
            row[3].move(sizeF, -sizeF);
            changeFigure = 2;
        }
    }
    else if(changeFigure == 2){
        if(isPossibleTurn(row[0], sizeF, sizeF) and isPossibleTurn(row[2], -sizeF, 0) and isPossibleTurn(row[3], 0, sizeF))
        {
            row[0].move(sizeF, sizeF);
            row[2].move(-sizeF, 0);
            row[3].move(0, sizeF);
            changeFigure = 3;
        }
    }
    else if(changeFigure == 3){
        if(isPossibleTurn(row[0], -sizeF, -sizeF) and isPossibleTurn(row[2], sizeF, sizeF) and isPossibleTurn(row[3], -(sizeF * 2), 0))
        {
            row[0].move(-sizeF, -sizeF);
            row[2].move(sizeF, sizeF);
            row[3].move(-(sizeF * 2), 0);
            changeFigure = 0;
        }
    }
}
void Figures::turnFig3(){
    if(changeFigure == 0){
        if(isPossibleTurn(row[0], sizeF, -sizeF) and isPossibleTurn(row[2], 0, -sizeF) and isPossibleTurn(row[3], -sizeF, 0))
        {
        row[0].move(sizeF, -sizeF);
        row[2].move(0, -sizeF);
        row[3].move(-sizeF, 0);
        changeFigure = 1;
        }
    }
    else if(changeFigure == 1){
        if(isPossibleTurn(row[0], -sizeF, 0) and isPossibleTurn(row[2], 0, sizeF) and isPossibleTurn(row[3], -sizeF, -sizeF))
        {
        row[0].move(-sizeF, 0);
        row[2].move(0, sizeF);
        row[3].move(-sizeF, -sizeF);
        changeFigure = 2;
        }
    }
    else if(changeFigure == 2){
        if(isPossibleTurn(row[0], sizeF, 0) and isPossibleTurn(row[2], -sizeF, sizeF) and isPossibleTurn(row[3], 0, sizeF))
        {
        row[0].move(sizeF, 0);
        row[2].move(-sizeF, sizeF);
        row[3].move(0, sizeF);
        changeFigure = 3;
        }
    }
    else if(changeFigure == 3){
        if(isPossibleTurn(row[0], -sizeF, sizeF) and isPossibleTurn(row[2], sizeF, -sizeF) and isPossibleTurn(row[3], sizeF * 2, 0))
        {
        row[0].move(-sizeF, sizeF);
        row[2].move(sizeF, -sizeF);
        row[3].move(sizeF * 2, 0);
        changeFigure = 0;
        }
    }
}
void Figures::turnFig4(){
    if(changeFigure == 0){
        if(isPossibleTurn(row[0], sizeF * 2, sizeF * 2) and isPossibleTurn(row[1], sizeF, sizeF) and isPossibleTurn(row[3], -sizeF, -sizeF))
        {
        row[0].move(sizeF * 2, sizeF * 2);
        row[1].move(sizeF, sizeF);
        row[3].move(-sizeF, -sizeF);
        changeFigure = 1;
        }
    }
    else if(changeFigure == 1){
        if(isPossibleTurn(row[0], -(sizeF * 2), -sizeF * 2) and isPossibleTurn(row[1], -sizeF, -sizeF) and isPossibleTurn(row[3], sizeF, sizeF))
        {
        row[0].move(-(sizeF * 2), -(sizeF * 2));
        row[1].move(-sizeF, -sizeF);
        row[3].move(sizeF, sizeF);
        changeFigure = 0;
        }
    }
}
void Figures::turnFig5(){
    if(changeFigure == 0){
        if(isPossibleTurn(row[3], 0, -sizeF * 2) and isPossibleTurn(row[0], sizeF * 2, 0))
        {
        row[3].move(0, -(sizeF * 2));
        row[0].move(sizeF * 2, 0);
        changeFigure = 1;
        }
    }
    else if(changeFigure == 1){
        if(isPossibleTurn(row[3], 0, sizeF * 2) and isPossibleTurn(row[0], -sizeF * 2, 0))
        {
        row[3].move(0, sizeF * 2);
        row[0].move(-(sizeF * 2), 0);
        changeFigure = 0;
        }
    }
}
void Figures::turnFig6(){
    if(changeFigure == 0){
        if(isPossibleTurn(row[2], 0, -sizeF * 2) and isPossibleTurn(row[1], -sizeF * 2, 0))
        {
        row[2].move(0, -(sizeF * 2));
        row[1].move(-(sizeF * 2), 0);
        changeFigure = 1;
        }
    }
    else if(changeFigure == 1){
        if(isPossibleTurn(row[2], 0, sizeF * 2) and isPossibleTurn(row[1], sizeF * 2, 0))
        {
        row[2].move(0, (sizeF * 2));
        row[1].move((sizeF * 2), 0);
        changeFigure = 0;
        }
    }
}

