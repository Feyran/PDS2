#ifndef _EVENT_H
#define _EVENT_H

#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

namespace UT_315{
  class Event {
  public:
    Event(string e_name = "", Date e_date = Date(),
	  string e_room = "", int e_capacity = 0){
      
      event_name = e_name; 
      event_date = e_date; 
      event_room = e_room;  
      event_capacity = e_capacity;
    }
    
    // ACCESSORS
    string get_name() const { return event_name; }
    Date get_date() const { return event_date; }
    string get_room() const { return event_room; }
    int get_capacity() const { return event_capacity; }
    
    // MUTATORS
    void set_name(const string& e_name) { event_name = e_name; }
    void set_date(const Date& e_date) { event_date = e_date; }
    void set_room(const string& e_room) { event_room = e_room; }
    void set_capacity(int e_capacity) { event_capacity = e_capacity; }

    bool operator==(const Event& E) const;
    bool operator<(const Event& E) const;
    bool operator>(const Event& E) const;

    friend ostream& operator<<(ostream& out, const Event& E);
    friend istream& operator>>(istream& in, Event& E);

  private:
    string event_name;
    Date event_date;
    string event_room;
    int event_capacity;
  };
}
#endif
