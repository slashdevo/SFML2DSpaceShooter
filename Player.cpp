//
// Created by devassassin on 6/6/18.
//

#include "Player.h"

Player::Player(int _id ,std::string textureName)
{
id=_id;
texture.loadFromFile("art/"+textureName);
setTexture(texture);
Bullet::texture.loadFromFile("art/Bullet.png");
shoot=true;
}

Player::~Player()
{
}

void Player::setHealth(int h)
{
    health = h;

}

int Player::getHealth() const
{
    return health;
}

void Player::setSpeed(double s)
{
    speed = s;
}

double Player::getSpeed() const
{
    return speed;
}

void Player::MoveInput()
{

    if (id == 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            if (getPosition().y > minY) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    if (getPosition().x < maxX)
                        move(sf::Vector2f(speed, -speed));
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    if (getPosition().x > minX)
                        move(sf::Vector2f(-speed, -speed));
                } else

                    move(sf::Vector2f(0, -speed));
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            if (getPosition().y < maxY) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    if (getPosition().x < maxX)
                        move(sf::Vector2f(speed, speed));
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    if (getPosition().x > minX)
                        move(sf::Vector2f(-speed, speed));
                } else
                    move(sf::Vector2f(0, speed));
            }
        }
        if (getPosition().x < maxX) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                move(sf::Vector2f(speed, 0));
            }
        }
        if (getPosition().x > minX) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                move(sf::Vector2f(-speed, 0));
            }
        }


    } else if (id == 2) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
            if (getPosition().y < maxY) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {
                    if (getPosition().x < maxX)
                        move(sf::Vector2f(speed, speed));
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {
                    if (getPosition().x > minX)
                        move(sf::Vector2f(-speed, speed));
                } else
                    move(sf::Vector2f(0, speed));
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) {
            if (getPosition().y > minY) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {
                    if (getPosition().x < maxX)
                        move(sf::Vector2f(speed, -speed));
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {
                    if (getPosition().x > minX)
                        move(sf::Vector2f(-speed, -speed));
                } else
                    move(sf::Vector2f(0, -speed));
            }
        }
        if (getPosition().x < maxX) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {
                move(sf::Vector2f(speed, 0));
            }
        }
        if (getPosition().x > minX) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {
                move(sf::Vector2f(-speed, 0));
            }
        }

    }
}

void Player::ShootInput()
{
    if(shoot) {
        if (id == 1) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                bullets.push_back(Bullet(&Bullet::texture, getPosition(), 180));
                shoot=false;
                c.restart();
            }
        } else if (id == 2) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
                bullets.push_back(Bullet(&Bullet::texture, getPosition(), 0));
                shoot=false;
                c.restart();
            }

        }
    }


    if(!shoot) {
        if (c.getElapsedTime().asSeconds() > 0.3) {
        shoot=true;
        c.restart();
        }
    }
   // std::cout<<c.getElapsedTime().asSeconds()<<"\n";

}

bool Player::isHit(Bullet& bullet)
{

    return getGlobalBounds().intersects(bullet.getGlobalBounds());

}








