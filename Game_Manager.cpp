//
// Created by devassassin on 6/6/18.
//

#include "Game_Manager.h"

Game_Manager::Game_Manager()
{

}


Game_Manager::~Game_Manager()
{
}

void Game_Manager::StartGame()
{
    p1.setScale(0.3,0.3);
    p1.setRotation(180);
    p1.setPosition(500,100);
    p1.setSpeed(0.5);

    p2.setScale(0.5,0.5);
    p2.setSpeed(0.5);
    p2.setPosition(500,600);
    p2.setRotation(0);

    ui.GameUI();
    ui.p1text->setText("Player 1 Health \n"+std::to_string(p1.getHealth()));
    ui.p2text->setText("Player 2 Health \n "+std::to_string(p2.getHealth()));

}
void Game_Manager::CreateWindow()
{
    window.create(sf::VideoMode(windowWidth, windowHeight), "Game");
    gui.setWindow(window);

}

void Game_Manager::UpdateLoop()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();


            gui.handleEvent(event);
        }
if(!isover) {
    p1.MoveInput();
    p1.ShootInput();
    p2.ShootInput();
    p2.MoveInput();


    window.clear();
    gui.draw();
    for (int i = 0; i < p1.bullets.size(); i++) {
        window.draw(p1.bullets[i]);
        p1.bullets[i].move(0, 4);
        if (p2.isHit(p1.bullets[i])) {
            p2.setHealth(p2.getHealth() - 1);
            ui.p2text->setText("Player 2 Health \n" + std::to_string(p2.getHealth()));
            std::cout << "P2 Health " << p2.getHealth() << "\n";
            p1.bullets.pop_back();
        }
        if (p1.bullets[i].getPosition().y > windowWidth) {
            // std::cout<<"Before Pop "<<p1.bullets.size()<<"\n";
            p1.bullets.pop_back();
            // std::cout<<"after Pop "<<p1.bullets.size()<<"\n";
        }
    }
    for (int i = 0; i < p2.bullets.size(); i++) {
        window.draw(p2.bullets[i]);
        p2.bullets[i].move(0, -4);
        if (p1.isHit(p2.bullets[i])) {
            p1.setHealth(p1.getHealth() - 1);
            ui.p1text->setText("Player 1 Health \n" + std::to_string(p1.getHealth()));
            p2.bullets.pop_back();
        }
        if (p2.bullets[i].getPosition().y < 0) {
            p2.bullets.pop_back();
        }
    }

    window.draw(p1);
    window.draw(p2);
    if(p1.getHealth()<=0)
    {
        ui.Lose("Player 2 Wins ");
        isover= true;
    }
    if(p2.getHealth()<=0)
    {
        ui.Lose("Player 1 Wins ");
        isover= true;
    }
} else
    gui.draw();

        window.display();
    }
}




sf::RenderWindow Game_Manager::window;
tgui::Gui Game_Manager::gui;
Player Game_Manager::p1(1,"ship6.png");
Player Game_Manager::p2(2,"ship5.png");
double Game_Manager::windowHeight=720;
double Game_Manager::windowWidth=1280;
bool Game_Manager::isover=false;