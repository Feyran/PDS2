#include "Event.h"

namespace UT_315 {
 
  bool Event::operator==(const Event& E) const {
    return (this->get_date() == E.get_date()) &&
      (this->get_room() == E.get_room());
  }

  bool Event::operator<(const Event& E) const {
    return this->get_date() < E.get_date();
  }
  
  bool Event::operator>(const Event& E) const {
    return !(*this == E) && !(*this < E);
  }
  
  ostream& operator<<(ostream& out, const Event& E){
    out << "Event Name: " << E.get_name() << endl;
    out << "Event Date: " << E.get_date() << endl;
    out << "Event Room: " << E.get_room() << endl;
    out << "Event Capacity: " << E.get_capacity() << endl;
    return out;
  }

  istream& operator>>(istream& in, Event& E) {
    string e_name = "NONE",  e_room = "NONE";
    int e_capacity = 0;
    Date e_date = Date();
    
    cout << "Event Name: ";
    in >> e_name;
    cout << "Event Date: ";
    in >> e_date;
    cout << "Event Room: ";
    in >> e_room;
    cout << "Event Capacity: ";
    in >> e_capacity;
    E = Event(e_name, e_date, e_room, e_capacity);
    return in;
  }
}
