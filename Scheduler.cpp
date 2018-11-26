/*
 * This file name: Scheduler.cpp
 *
 * This file contains the implementation of the methods associated
 * with the Scheduler class.
 *
 */

#include "List.h"
#include "Event.h"
#include "Room.h"
#include "Scheduler.h"

namespace UT_315 {
  //////////////////// DO NOT MODIFY THESE TWO FUCTIONS //////////////////////
  /*
   * Prints all events in the system in chronological order,
   * starting with the first room.
   */
   void Scheduler::print_events_forward(ostream& out){
     for (List_Iterator<Room> iter = room_list.first();
	 iter.has_data();
	 iter.next()){
       out << iter.get_data();
       out << endl;
     }
   }
   
  /*
   * Prints all events in the system in chronological order,
   * starting with the last room.
   */
   void Scheduler::print_events_backward(ostream& out){
     for (List_Iterator<Room> iter = room_list.last();
	  iter.has_data();
	  iter.prev()){
       out << iter.get_data();
       out << endl;
     }
   }
  /////////////////////////////////////////////////////////////////////////////



  //////////////// START ADDING YOUR CODE FROM THIS POINT ON /////////////////
  
  /*
   * Default constuctor used to create an empty list of rooms.
   */
  Scheduler::Scheduler(){

    // ADD YOUR CODE HERE
	room_list = List<Room>(); //basic constructor
  }

  /*
   * This function is used to add new event to the syste (if possible).
   * The function looks at all rooms that can fit a given event based
   * the event and room capacities. If a room has enough room, the 
   * function tries to put the room there. If this fails, it tries
   * the next room. As soon, as the event is added to a room, the 
   * function terminates and returns true. If no room is found, then
   * the function returns false.
   * Parameter: the_event - the new event to be added.
   * Returns: true if the event is added, or false is no room can 
   * be found to schedule the event.
   */
 
  bool Scheduler::add_event(Event& the_event){ 

    // ADD YOUR CODE HERE
	List_Iterator<Room> TBAdded = room_list.find(the_event.get_room()); //temp value holding the event to be added
	cout << "Add event accesed" << endl;
	if (TBAdded.has_data()){
		for (; TBAdded.has_data(); TBAdded.next()){ //loop to verify through nodes
			if (TBAdded.get_data().get_capacity() >= the_event.get_capacity()){ //verifying if capacity does not return any issues
				if (TBAdded.get_data().add_event(the_event)) {
					return true;
				}
			}
		}
	}
	else {
		for (TBAdded = room_list.first(); TBAdded.has_data(); TBAdded.next()){ //loop to verify through nodes
			if (TBAdded.get_data().get_capacity() >= the_event.get_capacity()){ //verifying room capacity
				if (TBAdded.get_data().add_event(the_event)) {
					return true;
				}
			}
		}
	}
	cout << "No room found!" << endl;
	return false;
	}

  /*
   * Removes an event from the system. This funciton looks at all
   * events in the system until it finds the target event, which is 
   * then erased. 
   * Parameter: the_event - the target event to be deleted.
   * Returns: true if the event if found and erased, or false otherwise.
   */
  bool Scheduler::remove_event(const Event& the_event){

    // ADD YOUR CODE HERE
	List_Iterator<Room> TBDeleted = room_list.find(the_event.get_room()); //stores temp value of room to be deleted

	for (TBDeleted = room_list.first(); TBDeleted.has_data(); TBDeleted.next()) { //loop to go through nodes
		if (TBDeleted.get_data().remove_event(the_event)) {
			return true; //succesfully deleted event
		}
		else {
			return false; //event was never found
		}
	}

  }
  

  /*
   * Finds the information about an scheduled event based on the event number.
   * If the event is found, the function fill in the information about the 
   * event in the second parameter, and then returns true. Otherwise, it
   * returns false.
   * Parameter: event_name - the name of the event to be searched.
   * Parameter: the_event - object where the event information needs to be 
   * stored.
   * Returns: true if the event is found, or false otherwise.
   */

  //verify
  bool Scheduler::find_event(const string& event_name, 
			     Event& the_event) const {
    
    // ADD YOUR CODE HERE
	List_Iterator<Room> room = room_list.first(); 

	for (; room.has_data(); room.next()){ // loop thru rooms
		//Room &tempR = room.get_data();
		List_Iterator<Event> event = room.get_data().first_event(); 

		for (; event.has_data(); event.next()){ //loop thru events
			Event &temp = event.get_data(); 
				if (temp.get_name() == event_name){  //values are same
				the_event = temp;
				return true;
			}
		}
	}
    return false;
    
  }

  /*
   * Finds the information about an scheduled event based on whole event 
   * information.
   * If the event is found, the function fill in the information about the 
   * event in the second parameter, and then returns true. Otherwise, it
   * returns false.
   * Parameter: event_name - the name of the event to be searched.
   * Parameter: the_event - object where the event information needs to be 
   * stored.
   * Returns: true if the event is found, or false otherwise.
   */

  //verify
  bool Scheduler::find_event(const Date& event_date, string event_room, 
			    Event& the_event) const{
    
    // ADD YOUR CODE HERE
	List_Iterator<Room> room = room_list.first();
	for (;room.has_data(); room.next()){ //loop thru rooms
	// Room &tempR = room.get_data(); //asigna room.get_data al nuevo pointer llamado tempR
		List_Iterator<Event> event = room.get_data().first_event(); //temp room

		for (; event.has_data(); event.next()){ //loop thru events
			Event &temp = event.get_data(); //temp event	

			if (temp.get_date() == event_date && temp.get_room() == event_room){ //event found
				the_event = temp;
				cout << "Event found!" << endl;
				return true;
			}
		}
	}
  cout << "No event found!" << endl;
  return false;
    
  }
  
  /*
   * Finds all event in the system that occur on a given data, and returns
   * a new list with those events. The argument is the date for the 
   * events.
   * Parameter: the_data - the date for the events.
   * Returns: a new list with all the evenst that happen on a given date.
   */

  //verify
  List<Event> Scheduler::find_events_date(const Date& the_date) const{

    // ADD YOUR CODE HERE
	List<Event> date;
	List_Iterator<Room> room = room_list.first();

	for (; room.has_data(); room.next()){ //loop thru rooms
		List_Iterator<Event> event = room.get_data().first_event();
		for ( ;event.has_data(); event.next()){ //loop thru events
			Event &tempDate = event.get_data();
			if (tempDate.get_date() == the_date){ //event date found
				date.insert(tempDate); 
			}
		}
	  }
    return date; //return date????????????????????????????????????

   }
     
  /*
   * Finds all event in the system that occur on a given room, and returns
   * a new list with those events. The argument is the room for the 
   * events.
   * Parameter: room_number - the room number for the events.
   * Returns: a new list with all the events that happen on a given room.
   */

  List<Event> Scheduler::find_events_room(const string& room_number) const {

     
    // ADD YOUR CODE HERE
	List_Iterator<Room> room = room_list.find(room_number);
	if (room.has_data()){
		  List<Event> LoE = List<Event>(); //construct object to be returned
		  List_Iterator<Event> event = room.get_data().first_event();
		  for (; event.has_data(); event.next()){ //loop verifies thru all nodes
			  LoE.insert(event.get_data()); //copy events into new object
		  }
		  return LoE;
	  }
	else {
		return List<Event>();
	}
   }
   
  /*
   * Finds all event in the system that occur between a given time
   * period, and returns a new list with those events. The arguments 
   * are the dates forming the period in which the  events must occur.
   * Parameter: start_date - initial date in the period.
   * Parameter: end_date - final date in the period.
   * Returns: a new list with all the events that happen on a given period.
   */


   List<Event> Scheduler::find_events_byperiod(const Date& start_date,
					       const Date& end_date){

    // ADD YOUR CODE HERE
	List<Event> time;
	List_Iterator<Room> room = room_list.first(); //room iterator

	for (; room.has_data(); room.next()) {//loop for rooms
		List_Iterator<Event> event = room.get_data().first_event();
		for (; event.has_data(); event.next()) { //loop for events within room
			Event &temp = event.get_data();
			if (temp.get_date() > start_date && temp.get_date() < end_date){
				time.insert(temp); //succesfully found time with distinct dates
			}
		}
	}
	return time;
   }

  /*
   * Clears all the events scheduled for a given room. The function
   * returns true if the room is found, and its events are cleared.
   * If the room is not found, it returns false.
   * Parameter: room_number - the number for the room whose events will be 
   * cleared.
   * Returns: true if the room is found, and its events cleared, or 
   * false if the room is not found.
   */

   bool Scheduler::clear_events_room(const string& room_number){
     
     // ADD YOUR CODE HERE
	 List_Iterator<Room> temp = room_list.first();
	 for (; temp.has_data(); temp.next()){//verifies thru all nodes for given room
		if (temp.get_data().get_number() == room_number){ //compare room #
			temp.get_data().clear_events(); //clears all events within room
			cout << "Room succesfully cleared of all events!" << endl;
			return true;
		}
	 }
	return false; // no room was found 
   }

  /*
   * Adds a new room to the system (if possible). The function
   * determines if another room with the same room number already 
   * exists. If not, the new room is added into the system, and 
   * return true. Otherwise, the room number is already is use, 
   * so the function rejects the new room and returns false.
   * Parameter: the_room - the new room to be added.
   * Retunrs: true if the room is added to the system, or false otherwise.
   */

   bool Scheduler::add_room(const Room& the_room){

     // ADD YOUR CODE HERE
	List_Iterator<Room> temp = room_list.find(the_room); //storing temp value

	if (!temp.has_data()){ 
		room_list.insert(the_room); //space for room found!
		cout << "Room succesfully inserted!" << endl;
		return true;
	}
	else{
		cout << "No space found for room!" << endl;
		return false;
	}
	}
  
  //////////////////////////////////////////////////////////////////////////
}


