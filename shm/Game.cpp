#include "Game.hpp"

class Map;

Game::Game(size_t money, size_t gameDays, size_t finalGoal)
    : money_(money)
    , gameDays_(gameDays)
    , finalGoal_(finalGoal)
    {

    }

void Game::startGame()
{
    printTitle();
    setPlayer();
    //menu();
}

void Game::printTitle()
{
    std::cout << "Project SHM" << '\n';
}

void Game::setPlayer()
{
    Time *time_ptr = new Time();
    Map mapa;
    

    std::cout << "Set your name captain!:" << '\n';
    std::string playerName;
    std::cin >> playerName;
    std::cout << "Welcome on board captain " << playerName << '\n';
    Player playerOne (std::make_unique<Ship>(20, 300, 2, "Uboot", 3, time_ptr), 1000, 1000);
    std::cout << "Your's ship Uboot is waiting! Good Luck!" << '\n';
    std::cout << "You are in start point. Current coordinates: (0,0). Choose Your next move!" << '\n';

    addMap(mapa);
}

// void Game::menu()
// {
//     auto i=0;
//     std::cin << i;
//     islands_[i];
// }

void Game::addMap(Map &map)
{   
    map.DebugPrintIsland();
}

void Game::travel()
{


}

// void Map::addIsland(Coordinates coordinate)
// {
//     addIsland(coordinate);
// }