#include <iostream>

#include "Main.h"


/*Room *rooms[3]{new Room(0), new Room(1), new Room(2)};
Door *doors[][3]{
    {new Door(rooms[0], rooms[1]), nullptr, nullptr},
    {new Door(rooms[1], rooms[0]), new Door(rooms[1], rooms[2]), nullptr},
    {new Door(rooms[2], rooms[1]), nullptr, nullptr}};

*/
int main()
{
  CurrentRoom* currentRoom = new CurrentRoom(1);
  currentRoom->checkLegalMoves();
  currentRoom->printRoomStatus();
  currentRoom->optionSelect();
  
  return 0;
}