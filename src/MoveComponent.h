#ifndef MOVE_COMPONENT_H
#define MOVE_COMPONENT_H

class Unit;

class MoveComponent {
public:
    MoveComponent(Unit& unit) : m_unit(unit) {};

private:
    Unit& m_unit;
};

#endif // MOVE_COMPONENT_H