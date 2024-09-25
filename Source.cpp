#include <iostream>
#include <Random.h>
#include <Board.h>
#include <Player.h>
#include <conio.h>
#include <GameManager.h>

using namespace std;

int key;

#define ESCAPE 27

void GameQuit(int score);


int main()
{
    int size;   

    cout << "난이도를 입력하세요: ";
    cin >> size;

    Board maze = Board(size, nullptr);
    Player player(1, 1, &maze);


    maze.SetPlayer(&player);

    maze.Set_EvenTile();
    maze.Generate();

#if 1
    maze.Render();

    while (key != ESCAPE)
    {
        if (_kbhit())
        {
            key = _getch();

            if (key == 0 || key == -32)
                key = _getch();

            if (player.Input((Key)key))
            {
                maze.Render();
                maze.ReachPortal();
            }
        }
    }

    GameQuit(maze.Score());
#endif // 0


    return 0;
}


void GameQuit(int score)
{
    GameManager::Clear();
    cout << "=======================" << '\n';
    cout << "게임종료. 최종 점수:" << score << '\n';
    cout << "=======================" << '\n';
}