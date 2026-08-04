#ifndef UNIT_H
#define UNIT_H

#include "Position.h"

class Unit {
public:
    Unit(int id, int hp, int x, int y, int speed) : m_id(id), m_hp(hp), m_position(x, y), m_speed(speed) {
        m_isAlive = (hp > 0) ? true : false;
    };

    void move();

    // Getters and Setters
    int getID() const { return m_id; }
    int getHp() const { return m_hp; }
    void setHp(int hp) {
        m_hp = hp;
        m_isAlive = (hp > 0) ? true : false;
    }
    int getX() const { return m_position.getX(); }
    void setX(int x) { m_position.setX(x); }
    int getY() const { return m_position.getY(); }
    void setY(int y) { m_position.setY(y); }
    int getSpeed() const { return m_speed; }
    void setSpeed(int speed) { m_speed = speed; }
    bool isAlive() const { return m_isAlive; }

private:
    int m_id;
    int m_hp;
    Position m_position;
    int m_speed;
    bool m_isAlive;
};

#endif // UNIT_H
