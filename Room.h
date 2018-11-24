/*
 * This file: Room.h
 *
 * This file contains the declaration of the interface 
 * for the Room class. This class is used to represet 
 * a record of information about a Room in which events
 * can be scheduled. 
 */

#ifndef _ROOM_H
#define _ROOM_H

#include <string>
#include <iostream>
#include "Date.h"
#include "Event.h"
#include "List.h"

namespace UT_315 {
  /*
   * Declaration of the Room class, which stores a room number,
   * room capacity and a list of events scheduled in the room.
   * 
   * NOTE: Copy constuctors, Copy assignment operators and 
   * destructor do not need to implemented. The default ones
   * provide by C++ are sufficient.
   */
  class Room {
  public:
    // Default constructor
    Room(string the_number = "000", int the_capacity = 0);

    // Adds a new event to this room
    bool add_event(Event& E);

    // Removes an existing event from this room
    bool remove_event(const Event& E);

    // Returns an iterator to the first event scheduled in this room.
    List_Iterator<Event> first_event();

    // Removes all events scheduled in this room.
    void clear_events();

    // Returns the room number
    string get_number() const {return room_number;}
    
    // Returns the room capacity
    int get_capacity() const { return room_capacity; }

    // Determines if two rooms are the same, based on room number.
    bool operator==(const Room& R) const;

    // Determines if this room has a room number smaller than another room.
    bool operator<(const Room& R) const;

    // Determines if this room has a room number larger than another room.    
    bool operator>(const Room& R) const;
    
    // Prints the information about this room to an output stream.
    friend ostream& operator<<(ostream& out, const Room& R);
  private:
    // Number for the room
    string room_number;
    // Capacity for the room
    int room_capacity;
    // List with the events for this room
    List<Event> room_events;
  };
}
#endif
