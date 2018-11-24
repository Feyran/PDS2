/*
 * This file: Scheduler.h
 * 
 * This file contains the declaration of the interface 
 * for an event scheduler. This scheduler has a list of 
 * room capable of accomodating events.
 */

#ifndef _SCHEDULER_H
#define _SCHEDULER_H

#include "List.h"
#include "Event.h"
#include "Room.h"
#include "Date.h"

namespace UT_315 {
  
  /*
   * Class for scheduling events in a group of room.
   */
  class Scheduler {
  public:
    // Default constructor
    Scheduler();
    // Adds a new event into the system
    bool add_event(Event& the_event);

    // Removes an event from the system
    bool remove_event(const Event& the_event);

    // Finds an existing event by name
    bool find_event(const string& event_name, Event& the_event) const;

    // Finds an existing event by full event information
    bool find_event(const Date& event_date, string event_room, 
		    Event& the_event) const;

    // Finds all events that occur on a given date.
    List<Event> find_events_date(const Date& the_date) const;

    // Finds all events that occur in a given room.
    List<Event> find_events_room(const string& room_number) const;

    // Finds all event that occur on a given time period.
    List<Event> find_events_byperiod(const Date& start_date,
				     const Date& end_date);

    // Clears all the events that are scheduled on a given room.
    bool clear_events_room(const string& room);

    // Adds a new room to the system.
    bool add_room(const Room& the_room);

    // Prints all events in chronological order, starting with those
    // in the first room
    void print_events_forward(ostream& out);

    // Prints all events in chronological order, starting with those
    // in the least room 
    void print_events_backward(ostream& out);

  private:
    // List of Rooms.
    List<Room> room_list;
  };
}
#endif
