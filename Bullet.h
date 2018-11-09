//
// Created by devassassin on 6/9/18.
//

#ifndef OOP_PROJECT_BULLET_H
#define OOP_PROJECT_BULLET_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Bullet : public sf::Sprite
{
public :
    Bullet(sf::Texture* texture,sf::Vector2f pos,float rot);
~Bullet();
    static sf::Texture texture;
void PlaySound();

private:
  sf::Sound sound;
const float sizeX=0.5f;
const float sizeY=0.5f;


};


#endif //OOP_PROJECT_BULLET_H
