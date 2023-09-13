#include "Door.h"
#include "Room.h"

Door::Door(Room *sourceRoom, Room *targetRoom)
{
  this->sourceRoom = sourceRoom;
  this->targetRoom = targetRoom;
}