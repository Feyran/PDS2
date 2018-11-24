/*
 * This file: explicit.cpp
 *
 *  DO NO MODIFY THIS FILE
 */
#include <string>
#include "Event.h"
#include "cdlist_node.cpp"
#include "List.cpp"
#include "Room.h"

using namespace std;
using namespace UT_315;


// Explicit binding of templates

// Node of Event
template class cdlist_node<Event>;

// List of Event
template class List<Event>;

// Iterator of Event
template class List_Iterator<Event>;


// Node of Room
template class cdlist_node<Room>;

// List of Room
template class List<Room>;

// Iterator of Room
template class List_Iterator<Room>;

