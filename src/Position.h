#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    Position() = default;
    Position(int x, int y) : m_x(x), m_y(y) {}

    int getX() const noexcept { return m_x; }
    int getY() const noexcept { return m_y; }

    void setX(int x) noexcept { m_x = x; }
    void setY(int y) noexcept { m_y = y; }

private:
    int m_x;
    int m_y;
};

#endif // POSITION_H