#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H

#include "CommandInterface.h"
#include "Position.h"

class MoveCommand : public CommandInterface {
public:
    MoveCommand(int id, Position pos) : m_id(id), m_position(pos) {}

private:
    int m_id;
    Position m_position;
};

#endif // MOVE_COMMAND_H