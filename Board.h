#if !defined(Board_h)
#define Board_h
class Board;
#include "Player.h"

struct Tile
{
    enum Type 
    {
        Empty = ' ',
        Wall = 'O',
        Portal = 'b', 
        Return = '\n',
        Null = 0,
        Player = 'c'
    };

    enum Colour 
    {
        PortalType = '4',
        PlayerType = '3',
        DefaultType = '7'
    };

    char buffer[5 + 3];

    constexpr int getType()
    {
        if (buffer[5] == ' ')
        {
            return buffer[7];
        }
    
        union _ 
        {
            char d[4];
            int _a;

            constexpr _(char a, char b, char c, char d) : d{ a, b, c, d } { }
        } d = { buffer[5], buffer[6], buffer[7], 0 };
    
        return d._a;
    }

    constexpr Tile(enum Type a = Return) : buffer{0, }
    {
        buffer[0] = '\033';
        buffer[1] = '[';
        buffer[2] = '3';

        switch (a) 
        {
        case Type::Player:
            buffer[3] = PlayerType;
            break;
        case Type::Portal:
            buffer[3] = PortalType; 
            break;
        case Type::Wall:
        default:
            buffer[3] = Colour::DefaultType;
        }
        buffer[4] = 'm';


        buffer[5] = ' ';
        buffer[6] = ' ';

        if (a < 255)
            buffer[7] = a;
        else
            buffer[7] = Null;
    }
};

class Board
{
private:
    Player* player;
    Tile* map;
    int score;
    int size;
    int portalX, portalY;

public:
    Board(int inputSize, Player* player);
    ~Board();

    constexpr Tile& Get_Tile(int x, int y) { return map[y * (size + 1) + x]; }

    void Init();
    void Render();
    void Generate();
    void ReachPortal();

    constexpr void SetPlayer(Player* player) { this->player = player; }
    constexpr void Set_EvenTile()
    {
        for (int y = 0; y < size; y++)
        {
            for (int x = 0; x < size; x++)
            {
                if (x % 2 == 0 || y % 2 == 0)
                    this->Get_Tile(x, y) = Tile::Wall; 
            }
        }
    }
    constexpr int Size() { return size; }
    constexpr int Score() { return score; }
private:
    void Generate_Portal();
};

#endif // !defined(Board_h)
