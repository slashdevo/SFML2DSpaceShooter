//
// Created by devassassin on 6/9/18.
//

#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture,sf::Vector2f pos,float rot)
{
    setTexture(*texture);
    setPosition(pos);
    setScale(sizeX,sizeY);
    setRotation(rot);
    this->texture.loadFromFile("art/Bullet.png");
}

Bullet::~Bullet()
{

}


void Bullet::PlaySound()
{

}



sf::Texture Bullet::texture;
