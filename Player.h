#if !defined(Player_h)
#define Player_h

class Player;

#include "Board.h"

enum class Key
{
    UP = 72,
    LEFT = 75,
    RIGHT = 77,
    DOWN = 80
};

class Player
{
private:
    int x, y;
    Board* board;

public:
    constexpr Player(int x, int y, Board* board): x(x), y(y), board(board) { }
    constexpr int Get_X() { return x; }
    constexpr int Get_Y() { return y; }
    constexpr void SetBoard(Board* board) { this->board = board; }

    bool Input(Key key);
};
#endif // !defined(Player_h)
 