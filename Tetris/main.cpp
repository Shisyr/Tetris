
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Figures.hpp"
//#include "AbstractMenu.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include "Menu.hpp"
#include "About.hpp"
#include "Speed.hpp"
#include <string>
#include <fstream>
#include "Game.hpp"

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

using namespace sf;
using namespace std;

//bool isChosingSpeed;
//bool isPlayGame = true;
//bool isAbout;
//bool isMenu;
//int score = 0;
//Text textScore;
//float delay = 0;
//const int Thinkness = 2;
//vector<RectangleShape> form;
//int changeToSecond = 900;
//Text text[5];
//const int W = 10;
//const int H = 20;
int windowX = 1200;
int windowY = 900;
RenderWindow window(VideoMode(windowX, windowY), "SFML window");
//Menu menu(window, window.getSize().x, window.getSize().y);
//About about(window, window.getSize().x, window.getSize().y);
//Speed speed(window, window.getSize().x, window.getSize().y);
//RectangleShape screen[H][W];
//int screenY = 0;
//int screenX = windowX / 2 - (windowX / 5);
//float sizeScreen = (windowY - 2) / H;
//vector<Figures> f;
//vector<RectangleShape> r;
//Figures f1(screenX, screenY, Thinkness, sizeScreen, form);
//
//
//void init();
//void drawScreen();
//void drawFigure(vector<RectangleShape> figure);
//void deletefullRow();
//bool isEndOfGame();
//bool isCheckButton(Event& event, Text sp);
//void playGame();
//void mainView(Event &event);
//void drawMain();
//void moveToMenu();
//void nextFigure();
//void updateScore(){
//    textScore.setString("Score: " + to_string(score));
//}

int main(int, char const**)
{
    int prevIndex = 0;
    int index = 0;
    vector<AbstractMenu*> games;
    games.push_back(new Menu(window, window.getSize().x, window.getSize().y));
    games.push_back(new Speed(window, window.getSize().x, window.getSize().y));
    games.push_back(new About(window, window.getSize().x, window.getSize().y));
    games.push_back(new Game(window));
    while(index != -1){
        index = games[index]->run();
        if(index == 3){
            prevIndex = 3;
        }
        else{
            if(prevIndex == 3){
                games.pop_back();
                games.push_back(new Game(window));
                prevIndex = 0;
            }
        }
    }
    
    
//    Game* game = new Game(window);
//    game->run();
//    Font f;
//    if(!f.loadFromFile("/Users/Mukhamed/Downloads/fonts/Bold.ttf")){
//        //error
//    }
//    playGame();
//    textScore.setFont(f);
//    textScore.setFillColor(Color::White);
//    textScore.setString("Score: " + to_string(score));
//    textScore.setPosition(window.getSize().x / 6, window.getSize().y / 4);
//    srand(time(0));
//    init();
//    Clock clock;
    
//        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
//        Start the game loop
//    
//    while (window.isOpen())
//    {
//        float time = clock.getElapsedTime().asMicroseconds();
//        clock.restart();
//        time /= changeToSecond;
//        delay += time;
//        
//        Event event;
//        while (window.pollEvent(event))
//        {
//            
//            // Close window: exit
//            if (event.type == Event::Closed) {
//                window.close();
//            }
//            mainView(event);
//        }
//        window.clear();
//        drawMain();
//        window.display();
//    }
    return EXIT_SUCCESS;
}

//
//void init(){
//    float sY = screenY + Thinkness;
//    for(int i = 0;i < H;i++){
//        float sX = screenX + Thinkness;
//        for(int j = 0;j < W;j++){
//            RectangleShape s1(Vector2f(sizeScreen, sizeScreen));
//            s1.setPosition(sX, sY);
//            s1.setFillColor(Color::Black);
//            s1.setOutlineThickness(Thinkness);
//            s1.setOutlineColor(Color::White);
//            screen[i][j] = s1;
//            sX += sizeScreen;
//        }
//        sY += sizeScreen;
//        windowX = sX;
//    }
//    windowY = sY;
//}
//
//void drawScreen(){
//    for(int i = 0;i < H;i++){
//        for(int j = 0;j < W;j++){
//            window.draw(screen[i][j]);
//        }
//    }
//    for(int i = 0;i < form.size();i++){
//        window.draw(form[i]);
//    }
//}
//
//void drawFigure(vector<RectangleShape> figure){
//    for(int i = 0;i < figure.size();i++){
//        window.draw(figure[i]);
//    }
//}

//void deletefullRow(){
//    for(int i = 0;i < form.size();i++){
//        int numberOfSimilar = 1;
//        int formX = form[i].getPosition().x;
//        int formY = form[i].getPosition().y;
//        for(int j = 0;j < form.size();j++){
//            if(formX != form[j].getPosition().x and formY == form[j].getPosition().y){
//                numberOfSimilar++;
//            }
//        }
//        if(numberOfSimilar == 10){
//            for(int j = 0;j < form.size();j++){
//                if(form[j].getPosition().y == formY){
//                    form.erase(form.begin() + j, form.begin() + j + 1);
//                    j--;
//                }
//            }
//            for(int j = 0;j < form.size();j++){
//                if(form[j].getPosition().y < formY){
//                    form[j].move(0, sizeScreen);
//                }
//            }
//            score += 10;
//            updateScore();
//        }
//    }
//}

//bool isEndOfGame(){
//    for(int i = 0;i < form.size();i++){
//        int count = 1;
//        int formX = form[i].getPosition().x;
//        int formY = form[i].getPosition().y;
//        for(int j = 0;j < form.size();j++){
//            int fX = form[j].getPosition().x;
//            int fY = form[j].getPosition().y;
//            if(fX == formX){
//                count++;
//            }
//        }
//        if(count >= 20){
//            return true;
//        }
//    }
//    return false;
//}

//bool isCheckButton(Event& event, Text sp){
//    int eX = event.mouseMove.x;
//    int eY = event.mouseMove.y;
//    int sX = sp.getPosition().x;
//    int sY = sp.getPosition().y;
//    int size = sp.getCharacterSize();
//    if(eX >= sX and eX <= sX + (size * sp.getString().getSize()) and eY >= sY and eY <= sY + size){
//        return true;
//    }
//    eX = event.mouseButton.x;
//    eY = event.mouseButton.y;
//    if(eX >= sX and eX <= sX + (size * sp.getString().getSize()) and eY >= sY and eY <= sY + size){
//        return true;
//    }
//    return false;
//}

//
//void playGame(){
//    nextFigure();
//    isPlayGame = true;
//}
//void mainView(Event &event){
//    if(isPlayGame){
//        if(event.type == Event::KeyPressed){
//            if(event.key.code == Keyboard::Down){
//                f.front().moveDown();
//            }
//            if(event.key.code == Keyboard::Right){
//                f.front().moveRight();
//            }
//            if(event.key.code == Keyboard::Left){
//                f.front().moveLeft();
//            }
//            if(event.key.code == Keyboard::Up){
//                f.front().turnFigure();
//            }
//            if(event.key.code == Keyboard::Escape){
//                moveToMenu();
//                score = 0;
//                updateScore();
//            }
//        }
//    }
//    else if(isChosingSpeed){
//        if(event.type == Event::EventType::MouseMoved){
//            vector<Text> sp = speed.getTexts();
//            for(int i = 0;i < sp.size();i++){
//                sp[i].setFillColor((isCheckButton(event, sp[i])) ? Color::Red : Color::White);
//            }
//            speed.setTexts(sp);
//        }
//        if(event.type == Event::KeyPressed and event.key.code == Keyboard::Escape){
//            moveToMenu();
//            score = 0;
//        }
//        if(event.type == Event::KeyPressed and event.key.code == Keyboard::Down){
//            speed.moveDown();
//        }
//        if(event.type == Event::KeyPressed and event.key.code == Keyboard::Up){
//            speed.moveUp();
//        }
//        if(event.type == Event::KeyPressed and event.key.code == Keyboard::Return){
//            string s = speed.getTexts()[speed.getSpeed()].getString();
//            changeToSecond = (s == "Level: 1")? 900 : changeToSecond;
//            changeToSecond = (s == "Level: 2")? 600 : changeToSecond;
//            changeToSecond = (s == "Level: 3")? 300 : changeToSecond;
//            
//            f.clear();
//            form.clear();
//            playGame();
//        }
//        if(event.type == Event::EventType::MouseButtonPressed){
//            vector<Text> sp = speed.getTexts();
//            for(int i = 0;i < sp.size();i++){
//                if(isCheckButton(event, sp[i])){
//                    string s = sp[i].getString();
//                    cout << s << endl;
//                    changeToSecond = (s == "Level: 1")? 900 : changeToSecond;
//                    changeToSecond = (s == "Level: 2")? 600 : changeToSecond;
//                    changeToSecond = (s == "Level: 3")? 300 : changeToSecond;
//                    f.clear();
//                    form.clear();
//                    playGame();
//                }
//            }
//            speed.setTexts(sp);
//        }
//    }
//    else if(isAbout){
//        if(event.type == Event::KeyPressed and event.key.code == Keyboard::Escape){
//            moveToMenu();
//        }
//    }
//    else{
//        if(event.type == Event::KeyPressed){
//            if(event.key.code == Keyboard::Escape){
//                window.close();
//            }
//            if(event.key.code == Keyboard::Down){
//                menu.MoveDown();
//            }
//            if(event.key.code == Keyboard::Up){
//                menu.MoveUp();
//            }
//            if(event.key.code == Keyboard::Return){
//                if(menu.GetPressedItem() == 0){
//                    isChosingSpeed = true;
//                }
//                if(menu.GetPressedItem() == 1){
//                    isAbout = true;
//                    isPlayGame = false;
//                }
//                if(menu.GetPressedItem() == 2){
//                    window.close();
//                }
//            }
//        }
//        if(event.type == Event::MouseMoved){
//            vector<Text> sp = menu.getTexts();
//            for(int i = 0;i < sp.size();i++){
//                sp[i].setFillColor((isCheckButton(event, sp[i])) ? Color::Red : Color::White);
//            }
//            menu.setTexts(sp);
//        }
//        if(event.type == Event::EventType::MouseButtonPressed){
//            vector<Text> sp = menu.getTexts();
//            for(int i = 0;i < sp.size();i++){
//                if(isCheckButton(event, sp[i])){
//                    string s = sp[i].getString();
//                    if(s == "Play"){
//                        isChosingSpeed = true;
//                    }
//                    else if(s == "About Tetris"){
//                        isAbout = true;
//                        isPlayGame = false;
//                    }
//                    else if(s == "Exit"){
//                        window.close();
//                    }
//                }
//            }
//            menu.setTexts(sp);
//        }
//    }
// }
//void drawMain(){
//    if(isPlayGame){
//        if(isEndOfGame()){
//            window.close();
//        }
//        else{
//            if(not f.front().isPossibleDown()){
//                for(int i = 0;i < f.front().getFigures().size();i++){
//                    RectangleShape s = f.front().getFigures()[i];
//                    form.push_back(s);
//                }
//                f.clear();
//                deletefullRow();
//                nextFigure();
//            }
//        }
//        if(delay > changeToSecond){
//            f.front().moveDown();
//        }
//        drawScreen();
//        drawFigure(f.front().getFigures());
//        drawFigure(r);
//        window.draw(textScore);
//        delay = (delay > changeToSecond) ? 0 : delay;
//        
//    }
//    else if(isChosingSpeed){
//        speed.draw(window);
//    }
//    else if(isAbout){
//        about.draw(window);
//    }
//    else{
//        menu.draw(window);
//    }
// }
//void moveToMenu(){
//    isPlayGame = false;
//    isChosingSpeed = false;
//    isAbout = false;
//}
//
//void nextFigure(){
//    f.push_back(f1);
//    Figures fn(screenX, screenY, Thinkness, sizeScreen, form);
//    f1.setFigures(fn.getFigures());
//    f1.setFullForm(fn.getFullForm());
//    f1.setTypeOfFigure(fn.getTypeOfFigure());
//    f.front().setFullForm(f1.getFullForm());
//    r = f1.getFigures();
//    for(int i = 0;i < r.size();i++){
//        r[i].setPosition(r[i].getPosition().x + (window.getSize().x / 4), r[i].getPosition().y + (window.getSize().y / 2));
//    }
//}
