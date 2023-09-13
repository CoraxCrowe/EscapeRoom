#include <iostream>

#include "Main.h"

int main()
{

  Room* room1 = new Room(1);
  Room* room2 = new Room(2);

  Door* door = new Door(room1, room2);

  std::cout << door->sourceRoom->roomNumber;

  return 0;
}