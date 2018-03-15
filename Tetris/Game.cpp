//
//  Game.cpp
//  Tetris
//
//  Created by Шисыр Мухаммед Шарипович on 13.12.17.
//  Copyright © 2017 Шисыр Мухаммед Шарипович. All rights reserved.
//

#include "Game.hpp"

using namespace sf;
using namespace std;
Game::Game(RenderWindow& win) : AbstractMenu(win, windowX, windowY){
    rScore.open("score.txt.rtf", ios_base::out);
    screenX = window.getSize().x / 2 - (window.getSize().y / 6);
    sizeScreen = (window.getSize().y - 2) / 20;
    initScreen();
    f1.push(Figures(screenX, screenY, Thinkness, sizeScreen, form));
    newFigure();
   
    if(!fontScore.loadFromFile("/Users/Mukhamed/Downloads/fonts/Bold.ttf")){
        //error
    }
    string scoreOfFile;
    rScore >> scoreOfFile;
    rScore.close();
    maxScore.setFont(fontScore);
    maxScore.setFillColor(Color::White);
    maxScore.setPosition(window.getSize().x / 12, window.getSize().y / 4);
    maxScore.setString("Maximum score: " + scoreOfFile);
    textScore.setFont(fontScore);
    textScore.setFillColor(Color::White);
    textScore.setPosition(window.getSize().x / 6, window.getSize().y / 5);
    updateScore();
    
//    f.push_back(Figures(screenX, screenY, Thinkness, sizeScreen, form));
}
void Game::updateScore(){
    textScore.setString("Score: " + to_string(score));
}

int Game::run(){
    
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= speed;
        delay += time;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed) {
                window.close();
            }
            if(event.type == Event::KeyPressed and event.key.code == Keyboard::Escape){
                return 0;
            }
            controlFigure();
        }
        window.clear();
        if(isEndOfGame() or isExit){
            ofstream f("score.txt.rtf", ios_base::app);
            if(f.is_open()){
                string conv1 = maxScore.getString();
                string conv = textScore.getString();
                f << conv[conv.size() - 1];
                f.close();
            }
            return 0;
        }
        if(delay > speed){
            f.front().moveDown();
            delay = 0;
        }
        window.draw(textScore);
        window.draw(maxScore);
        nextFigure();
        drawScreen();
        draw();
        window.display();
    }
}
void Game::initScreen(){
    float sY = screenY + Thinkness;
    for(int i = 0;i < H;i++){
        float sX = screenX + Thinkness;
        for(int j = 0;j < W;j++){
            RectangleShape s1(Vector2f(sizeScreen, sizeScreen));
            s1.setPosition(sX, sY);
            s1.setFillColor(Color::Black);
            s1.setOutlineThickness(Thinkness);
            s1.setOutlineColor(Color::White);
            screen[i][j] = s1;
            sX += sizeScreen;
        }
        sY += sizeScreen;
        windowX = sX;
    }
    windowY = sY;
}

void Game::drawScreen(){
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            window.draw(screen[i][j]);
        }
    }
    for(int i = 0;i < form.size();i++){
        window.draw(form[i]);
    }
}

void Game::draw(){
    for(int i = 0;i < f.front().getFigures().size();i++){
        window.draw(f.front().getFigures()[i]);
    }
    for(int i = 0;i < r.size();i++){
        window.draw(r[i]);
    }
}
void Game::nextFigure(){
    if(not f.front().isPossibleDown()){
        for(int i = 0;i < f.front().getFigures().size();i++){
            sf::RectangleShape s = f.front().getFigures()[i];
            form.push_back(s);
        }
        f.clear();
        deleteFigure();
        newFigure();
    }
}
void Game::newFigure(){
    f.push_back(f1.front());
    f1.pop();
    f1.push(Figures(screenX, screenY, Thinkness, sizeScreen, form));
    f.front().setFullForm(f1.front().getFullForm());
    r = f1.front().getFigures();
    for(int i = 0;i < r.size();i++){
        r[i].setPosition(r[i].getPosition().x + (window.getSize().x / 4), r[i].getPosition().y + (window.getSize().y / 2));
    }
}
void Game::deleteFigure(){
    for(int i = 0;i < form.size();i++){
        int numberOfSimilar = 1;
        int formX = form[i].getPosition().x;
        int formY = form[i].getPosition().y;
        for(int j = 0;j < form.size();j++){
            if(formX != form[j].getPosition().x and formY == form[j].getPosition().y){
                numberOfSimilar++;
            }
        }
        if(numberOfSimilar == 10){
            for(int j = 0;j < form.size();j++){
                if(form[j].getPosition().y == formY){
                    form.erase(form.begin() + j, form.begin() + j + 1);
                    j--;
                }
            }
            for(int j = 0;j < form.size();j++){
                if(form[j].getPosition().y < formY){
                    form[j].move(0, sizeScreen);
                }
            }
            score += 10;
            updateScore();
        }
    }
}
bool Game::isEndOfGame(){
    for(int i = 0;i < form.size();i++){
        int count = 1;
        int formX = form[i].getPosition().x;
        int formY = form[i].getPosition().y;
        for(int j = 0;j < form.size();j++){
            int fX = form[j].getPosition().x;
            int fY = form[j].getPosition().y;
            if(fX == formX){
                count++;
            }
        }
        if(count >= 20){
            isExit = true;
            return true;
        }
    }
    return false;
}
void Game::controlFigure(){
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::Down){
            f.front().moveDown();
        }
        if(event.key.code == Keyboard::Right){
            f.front().moveRight();
        }
        if(event.key.code == Keyboard::Left){
            f.front().moveLeft();
        }
        if(event.key.code == Keyboard::Up){
            f.front().turnFigure();
        }
        if(event.key.code == Keyboard::Escape){
            isExit = true;
        }
    }
}
