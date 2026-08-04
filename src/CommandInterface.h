#ifndef COMMAND_INTERFACE_H
#define COMMAND_INTERFACE_H

// enum class CommandType {
//     Move,
//     Attack
// };

class CommandInterface {
public:
    virtual ~CommandInterface() = default;
};

#endif // COMMAND_INTERFACE_H

// m ID x y   - move
// c ID w     - carry
// s ID       - show status
// g          - go
// z s        - zoom
// o x y      - original
// r s        - resize
// n c x y    - new
// v          - save
// l          - load
// a id1 id2  - attack
// q          - quit
