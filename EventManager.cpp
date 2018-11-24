/*
 * This file: EventManager.cpp
 * 
 * This file constains the main program for the Event Management
 * application.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "List.h"
#include "Date.h"
#include "Event.h"
#include "Room.h"
#include "Scheduler.h"
#include "EventManager.h"

using namespace std;
using namespace UT_315;

int main() {
  int opt = 0;
  Scheduler event_scheduler;
  
  cout << "Welcome to the Event Management Application Program." << endl;
  do {
    print_menu();
    opt = get_option();
    switch(opt){
    case ADD_EVENT:
      add_event(event_scheduler);
      break;
    case REMOVE_EVENT:
      remove_event(event_scheduler);
      break;
    case FIND_EVENT:
      find_event_by_name(event_scheduler);
      break;
    case FIND_EVENT_DATE:
      find_events_date(event_scheduler);
      break;
    case FIND_EVENT_ROOM:
      find_events_room(event_scheduler);
      break;
    case FIND_EVENT_PERIOD:
      find_events_byperiod(event_scheduler);
      break;
    case REMOVE_EVENTS_ROOM:
      remove_all_events(event_scheduler);
      break;
    case ADD_ROOM_INFO:
      add_room_info(event_scheduler);
      break;
    case PRINT_EVENTS_FOR:
      print_events_order(event_scheduler);
      break;
    case PRINT_EVENTS_BAC:
      print_events_rev_order(event_scheduler);
      break;
    case EXIT_MNGR:
      // Exit the operations loop
      break;
    default:
      cout << "Unknown option: " << opt << endl;
    }
  }
  while(opt != EXIT_MNGR);
  cout << "Thanks for using the Event Management Application Program." << endl;
  return EXIT_SUCCESS;
}


void print_menu(){
  cout << "********************************" << endl;
  cout << "Available Operations:"<< endl;
  cout << "\t 1.  Add event" << endl;
  cout << "\t 2.  Remove Event" << endl;
  cout << "\t 3.  Find event by name" << endl;
  cout << "\t 4.  Find events by date " << endl;
  cout << "\t 5.  Find events by room " << endl;
  cout << "\t 6.  Find events by time period " << endl;
  cout << "\t 7.  Remove events in a room " << endl;
  cout << "\t 8.  Add room information " << endl;
  cout << "\t 9.  Print events in order" << endl;
  cout << "\t 10. Print events in reverse order" << endl;
  cout << "\t 11. Exit" << endl;
  cout << "********************************" << endl;
}

int get_option(){
  int num = 0;
  cout << "Enter your option number: ";
  cin >> num;
  if (num == 11){
    return 0;
  }
  else {
    return num;
  }
}


void add_event(Scheduler& event_scheduler){
  Event new_event;
  
  cout << "Enter the event information: " << endl;
  cin >> new_event;
  cout << "Adding Event:" << endl;
  cout << new_event;
  
  if (event_scheduler.add_event(new_event)){
    cout << "\nEvent was added. Here is the information: " << endl;
    cout << new_event;
  }
  else {
    cout << "Event could not be added due to scheduling conflicts." << endl;
  }
}


void remove_event(Scheduler& event_scheduler){
  Event the_event;
  
  cout << "Enter the information for the event to be removed: " << endl;
  cin >> the_event;
  
  cout << "Removing event: " << endl;
  cout << the_event;

  if (event_scheduler.remove_event(the_event)){
    cout << "Event was removed." << endl;
  }
  else {
    cout << "Event was not found." << endl;
  }
}

void find_event_by_name(Scheduler& event_scheduler){
  string event_name;
  Event the_event;

  cout << "Enter the event name: ";
  cin >> event_name;
  cout << "Searching for event named: " << event_name << endl;
  if (event_scheduler.find_event(event_name, the_event)){
    cout << "Event information: " << endl;
    cout << the_event;
  }
  else {
    cout << "No event was found." << endl;
  }
}

void find_event(Scheduler& event_scheduler){
  Date event_date;
  string room_number;
  Event the_event;

  cout << "Enter the date for the event to be found: " << endl;
  cin >> event_date;
  cout << "Enter the room number for this event: " << endl;
  cin >> room_number;
  
  cout << "Finding event scheduled on : " << event_date  << " at room : " 
       << room_number << endl;

  if (event_scheduler.find_event(event_date, room_number, the_event)){
    cout << "Event information:" << endl;
    cout << the_event;
  }
  else {
    cout << "No event was found." << endl;
  }  
}


void find_events_date(Scheduler& event_scheduler){
  Date the_date;
  List<Event> event_list;
  
  cout << "Enter the date for the events: " << endl;
  cin >> the_date;
  
  cout << "Searching for events on: " << the_date << endl;
  event_list = event_scheduler.find_events_date(the_date);
  if (event_list.is_empty()){
    cout << "No events were found for date: " << the_date << endl;
  }
  else {
    cout << "Events scheduled for date: " << the_date << endl;
    event_list.print_forward(cout);
  }
}

void find_events_room(Scheduler& event_scheduler){
  string the_room;
  List<Event> event_list;
  
  cout << "Enter the room for the events: " << endl;
  cin >> the_room;
  
  cout << "Searching for events in room: " << the_room << endl;
  event_list = event_scheduler.find_events_room(the_room);
  if (event_list.is_empty()){
    cout << "No events were found for room: " << the_room << endl;
  }
  else {
    cout << "Events scheduled for room: " << the_room << endl;
    event_list.print_forward(cout);
  }
}

void find_events_byperiod(Scheduler& event_scheduler){
  Date start_date, end_date;
  List<Event> event_list;
  
  cout << "Enter the start date for the events: " << endl;
  cin >> start_date;
  cout << "Enter the end date for the events: " << endl;
  cin >> end_date;
  
  cout << "Searching for events between " << start_date << 
    " and " << end_date << endl;
  
  event_list = event_scheduler.find_events_byperiod(start_date, end_date);
  if (event_list.is_empty()){
    cout << "No events were found between " << start_date <<
      " and " << end_date << endl;
  }
  else {
    cout << "Events scheduled between " << start_date <<
      " and " << end_date << ": " << endl;
    event_list.print_forward(cout);
  }
}

void remove_all_events(Scheduler& event_scheduler){
  string room_number;
  
  cout << "Enter the room number whose events will be cleared: ";
  cin >> room_number;
  cout << "Clearing events in room: " << room_number << endl;
  if (event_scheduler.clear_events_room(room_number)){
    cout << "All events scheduled for room " << room_number << 
      " have been cleared." << endl;
  }
  else {
    cout << "Room " << room_number << " was not found. " << endl;
  }
}

void add_room_info(Scheduler& event_scheduler){
  string room_number;
  int room_capacity;
  Room new_room;
  
  cout << "Enter the room number: " << endl;
  cin >> room_number;
  cout << "Enter the room capacity: " << endl;
  cin >> room_capacity;
  new_room = Room(room_number, room_capacity);
  cout << "Adding room: " << endl;
  cout << new_room;
  if (event_scheduler.add_room(new_room)){
    cout << "Room information was added." << endl;
  }
  else {
    cout << "Room was not added because a room with number: " << 
      room_number << " is already in the system." << endl;
  }
}

void print_events_order(Scheduler& event_scheduler){
  cout << "List of events (in order): " << endl;
  event_scheduler.print_events_forward(cout);
}

void print_events_rev_order(Scheduler& event_scheduler){
  cout << "List of events (in reverse order): " << endl;
  event_scheduler.print_events_backward(cout);
}
