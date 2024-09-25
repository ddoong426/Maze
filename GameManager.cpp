#include <GameManager.h>
#include <iostream>
#include <Windows.h>

void GameManager::Clear()
{
	std::cout << "\033[H";
}