
#include <iostream>

#include "cargo.hpp"
#include "coordinates.hpp"
#include "island.hpp"
#include "Map.hpp"
#include "player.hpp"
#include "ship.hpp"

int main()
{
    Cargo bananas("banany", 15, 150);
    Cargo kryptonite("banany", 15, 150);
    Cargo onion("cebula", 250, 1);
    std::cout << (onion == bananas) << " " << (bananas == kryptonite) << " " << (onion == kryptonite) << std::endl;
    std::cout << bananas.getAmount() << " " << bananas.getBasePrice() << " " << onion.getName() << std::endl;

    bananas -= 100;

    Coordinates miami(125.f, 174.f);
    Coordinates breslau(180.f, 115.f);
    Coordinates chicago(125.f, 174.f);
    std::cout << (breslau == miami) << " " << (chicago == breslau) << " " << (miami == chicago) << std::endl;

    Ship Titanic(20, 90, 1);
    Titanic.addCargo(&bananas);
    std::cout << "Vector size: " << Titanic.getCargo().size() << '\n';
    std::cout << "Titanic cargo: " << Titanic.getCargo()[0]->getName() << '\n';

    std::cout << Titanic.getCargo()[0]->getAmount() << std::endl;

    auto ship = std::make_unique<Ship>(20, 1, 2, "titanic", 3);
    ship->addCargo(&bananas);    
    size_t shipCargoSize = ship->getCargo().size();
    Player player (std::move(ship), 1, 1);
    std::cout << "Vector size: " << shipCargoSize << '\n';
    std::cout << "Player's ship speed: " <<  player.getShip()->getSpeed() << '\n';
    std::cout << "Player's ship cargo: " << player.getCargo(0)->getName() << '\n';
    std::cout << "Available space: " << player.getAvailableSpace() << '\n';

    Map map;
    map.DebugPrintIsland();
    
    map.addIsland(miami);
    Island* is = map.getIsland(miami);
    std::cout << is->getPosition().GetPositionX() << " " << is->getPosition().GetPositionY() << '\n';
}