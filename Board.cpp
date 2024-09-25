#include <Board.h>
#include <cstdlib>
#include <ctime>
#include <iostream>



Board::Board(int inputSize, Player* player)
{
    this->player = player;
    size = inputSize * 2 + 1;

    score = 1;

    map = new Tile[(size + 1) * size];
    map[(size + 1) * (size - 1) + size]
        = Tile::Null;


    srand((time(0)));
    Init();
}


Board::~Board()
{
    delete[] map;
}


void Board::Init()
{
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            if (x == 0 || x == size - 1 || y == 0 || y == size - 1)
                this->Get_Tile(x, y) = Tile::Wall;
            else
                this->Get_Tile(x, y) = Tile::Empty;
        }
    }
}

#include <GameManager.h>

void Board::Render()
{
    using namespace std;

    GameManager::Clear();

    Get_Tile(player->Get_X(), player->Get_Y()) = Tile::Player;
    std::cout << (char*)map << "\033[0m\n"; 
    Get_Tile(player->Get_X(), player->Get_Y()) = Tile::Empty;

    cout << "====================" << '\n';
    cout << "Score: " << score << '\n';
    cout << "====================" << '\n';
}

void Board::Generate()
{
    for (int y = 1; y < size - 1; y += 2)
    {
        int count = 1;

        for (int x = 1; x < size - 1; x += 2)
        {
            if (x == size - 2 && y == size - 2)
                continue;

            if (y == size - 2)
            {
                Get_Tile(x + 1, y) = Tile::Empty;
                continue;
            }

            if (x == size - 2)
            {
                Get_Tile(x, y + 1) = Tile::Empty;
                continue;
            }

            if ((rand() & 1))
            {
                Get_Tile(x + 1, y) = Tile::Empty;
                count++;
            }
            else
            {
                int randomIndex = (rand() % count);
                this->Get_Tile(x - (randomIndex << 1), y + 1) = Tile::Empty;
                count = 1;
            }
        }
    }

    Generate_Portal();
}

void Board::ReachPortal()
{
    if (portalX == player->Get_X() && portalY == player->Get_Y())
    {
        score++;
        Init();
        Set_EvenTile();
        Generate();
        Render();
    }
}

void Board::Generate_Portal()
{
    do 
    {
        portalX = rand() % (size - 2) + 1;
        portalY = rand() % (size - 2) + 1;
    }
    while (this->Get_Tile(portalX, portalY).getType() != Tile::Empty);

    this->Get_Tile(portalX, portalY) = Tile::Portal;
}
