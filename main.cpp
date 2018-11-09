#include <iostream>
#include <TGUI/TGUI.hpp>
#include "Game_Manager.h"

#include "Player.h"

int main() {

Game_Manager manager;
manager.CreateWindow();
manager.StartGame();
manager.UpdateLoop();

  // Game_Manager::CreateWindow();
   //Game_Manager::StartGame();
  // Game_Manager::UpdateLoop();
    return 0;
}