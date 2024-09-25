#include <Player.h>

bool Player::Input(Key key)
{
    switch (key)
    {
    case Key::UP:
        if (y - 1 >= 0 && board->Get_Tile(x, y - 1).getType() != Tile::Wall)
        {
            y--;
            return true;
        }
        break;
    case Key::LEFT:
        if (x - 1 >= 0 && board->Get_Tile(x - 1, y).getType() != Tile::Wall)
        {
            x--;
            return true;
        }
        break;
    case Key::RIGHT:
        if (x + 1 < board->Size() && board->Get_Tile(x + 1, y).getType() != Tile::Wall)
        {
            x++;
            return true;
        }
        break;
    case Key::DOWN:
        if (y + 1 < board->Size() && board->Get_Tile(x, y + 1).getType() != Tile::Wall)
        {
            y++;
            return true;
        }
        break;
    default:
        break;
    }

    return false;
}
