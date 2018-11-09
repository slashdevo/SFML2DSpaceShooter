//
// Created by devassassin on 6/6/18.
//

#ifndef OOP_PROJECT_GAME_MANAGER_H
#define OOP_PROJECT_GAME_MANAGER_H

#include <TGUI/TGUI.hpp>
#include "Player.h"
#include "UI.h"

class Game_Manager
{
public:
    Game_Manager();
    ~Game_Manager();

     void CreateWindow();
     void UpdateLoop();
     void StartGame();
    static tgui::Gui gui;
     static  double windowHeight;
     static  double windowWidth;

private :
    static sf::RenderWindow window;
    static Player p1;
    static Player p2;
     UI ui;
    static bool isover;
};


#endif //OOP_PROJECT_GAME_MANAGER_H
