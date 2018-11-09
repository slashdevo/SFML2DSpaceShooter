//
// Created by devassassin on 6/6/18.
//

#ifndef OOP_PROJECT_PLAYER_H
#define OOP_PROJECT_PLAYER_H

#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Bullet.h"
class Player : public sf::Sprite
{
public:
    Player(int id, std::string textureName);
    ~Player();
    void setHealth(int h);
    int getHealth() const;
    void setSpeed(double s);
    double getSpeed() const;
    void MoveInput();
    void ShootInput();
    bool isHit(Bullet& bullet);
    std::vector<Bullet> bullets;
private:
    int health = 100;
    double speed=0.5;
    int id = 0;
    const double maxX=1220;
    const double minX=30;
    const double maxY=660;
    const double minY=50;
sf::Texture texture;
sf::Sound sound;
bool shoot;
sf::Clock c;
};

#endif //OOP_PROJECT_PLAYER_H
