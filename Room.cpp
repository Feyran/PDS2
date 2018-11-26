/*
 * This file: Room.cpp
 *
 * This file constains the implementation of the methods
 * associated with the Room class.
 */

#include "Room.h"

namespace UT_315{

  ///////// DO NOT MODIFY THE FOLLOWING FUNCTION /////////////////////////

  /*
   * Prints the information about this room to an output file.
   * Parameter: out - the output stream
   * Parameter: R - the room to be printed
   * Returns: the reference to the parameter output stream.
   */
  ostream& operator<<(ostream& out, const Room& R){
    out << "Room Number: " << R.get_number() << endl;
    out << "Room Capacity: " << R.get_capacity() << endl;
    out << "Room Events: " << endl;
    for (List_Iterator<Event> iter = R.room_events.first();
	 iter.has_data();
	 iter.next()){
      out << iter.get_data();
    }
    return out;
  }
  ///////////////////////////////////////////////////////////////////////////


  //////////////////// START ADDING YOUR CODE FROM HERE /////////////////////

  /*
   * Constuctor used to create a new Room object from a room number
   * and a room capacity. The list of events in the room is initially
   * set to be an empty list.
   * Parameter: the_number - room number
   * Parameter: the_capacity - room capacity
   */ 

  Room::Room(string the_number, int the_capacity){

    // ADD YOUR CODE HERE!
	//basic constructor
	room_number = the_number; 
	room_capacity = the_capacity; 
	this -> room_events = List<Event>();
  }
  
  /*
   * Adds a new event into the room, as long as there are no conflicts
   * with existing events. This method receives an event whose capacity
   * is known to be smaller or equal than the room capacity. If there
   * is no event in this room with the same name, date, room number
   * and capacity, then the event is added, and a value true is 
   * returned. Otherwise, the event is not added, and a value of 
   * false is returned.
   * Parameter: E - the new event to added.
   * Returns: true if the event is added or false otherwise.
   */

  bool Room::add_event(Event& E){
    Event new_event(E.get_name(), E.get_date(), this->room_number,
	       E.get_capacity());
    
    // ADD YOUR CODE HERE!
	E = new_event;	
	List_Iterator<Event> temp = room_events.find(E);

	if (!temp.has_data()) {//verify if temp already had data at specified node
		room_events.insert(E);
		cout << "Event succesfully added!" << endl;
		return true;
	}
	else { //there was data in 
		cout << "Error! No room for event to be added!" << endl;
		return false;
	}
  }
  
  /*
   * Removes an existing event from the current room. This method
   * determines if an event equal to the parameter is currently
   * in the event list, and if so, removes that event. This method
   * returns true if the event is removed, or false otherwise.
   * Parameter: E - the event to be removed.
   * Returns: true if the event is removed, or false otherwise.
   */

  bool Room::remove_event(const Event& E) {
    
    // ADD YOUR CODE HERE!
	  List_Iterator<Event> temp = room_events.find(E);

	  if (temp.has_data()) {//verify if there are any events to be deleted
		  for (temp = room_events.first(); temp.has_data(); temp.next()) {//for loop to find desired event
			  if (temp.get_data() == E) {//event found
				  room_events.erase(E); //delete
				  return true;
			  }
		  }
	  }
	  else {
		  return false; //no events were found to be deleted
	  }
  }
  
  /*
   * Returns an iterator to the first event in the list of 
   * events scheduled for this room.
   * Returns: iterator to the first event in the list of events
   * scheduled for this room.
   */

  List_Iterator<Event> Room::first_event(){
    // DO NOT MODIFY THIS FUNCTION
    return this->room_events.first();
  }

  /*
   * Removes all the events from the list of events scheduled
   * for this room.
   */
  void Room::clear_events(){
    // ADD YOUR CODE HERE!
	room_events.make_empty();
  }
  
  /*
   * Determines if another room R has a the same room number as this
   * room.
   * Parameter: R - room to be compared.
   * Returns: true if R has the same room number as this one, or 
   * false otherwise.
   */

  bool Room::operator==(const Room& R) const {
    // ADD YOUR CODE HERE!
	  if (get_number() == R.get_number()) {
		  return true;
	  }
	  else {
		  return false;
	  }
  }
  
  /*
   * Determines if this room has a room number that is smaller than that of 
   * another room R.
   * Parameter: R - room to be compared.
   * Returns: true if this room  has a room number less than the that of R, or
   * false otherwise.
   */

  bool Room::operator<(const Room& R) const {
    // ADD YOUR CODE HERE!
	  if (get_number() < R.get_number()) {
		  return true;
	  }
	  else {
		  return false;
	  }
  }

  /*
   * Determines if this room has a room number that is greater than that of 
   * another room R.
   * Parameter: R - room to be compared.
   * Returns: true if this room  has a room number greater than the that of R,
   * or false otherwise.
   */

  bool Room::operator>(const Room& R) const {
    // ADD YOUR CODE HERE!
	  if (get_number() > R.get_number()) {
		  return true;
	  }
	  else {
		  return false;
	  }

  }

  //////////////////////////////////////////////////////////////////////////  
}
