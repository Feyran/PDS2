#include <cassert>
#include "Date.h"

namespace UT_315 {

  Date::Date(int the_year, int the_month, int the_day, int the_hour){
    assert((1<= the_month) && (the_month <= 12));
    assert((1 <= the_day) && (the_day <= 30));
    assert((0 <= the_hour) && (the_hour <= 23));
    
    this->year = the_year;
    this->month = the_month;
    this->day = the_day;
    this->hour = the_hour;
  }
  
  bool Date::operator==(const Date& D) const {
    return (this->year == D.year) && (this->month == D.month) &&
      (this->day == D.day) && (this->hour == D.hour);
  }
  
  bool Date::operator<(const Date& D) const {
    bool case1, case2, case3, case4;
    
    case1 = this->year < D.year;
    case2 = (this->year == D.year) && (this->month < D.month);
    case3 = (this->year == D.year) && (this->month == D.month) &&
      (this->day < D.day);
    case4 = (this->year == D.year) && (this->month == D.month) &&
      (this->day == D.day) && (this->hour < D.hour);
    
    return  case1 || case2 || case3 || case4;
  }
  
  bool Date::operator>(const Date& D) const {
    return (!(*this == D)) && (!(*this < D));
  }
  
  ostream& operator<<(ostream& out, const Date& D){
    out << D.hour << "-" << D.month << "/" << D.day << "/" << D.year;
    return out;
  }
  
  istream& operator>>(istream& in, Date& D){
    int year = 1970, month = 1, day = 1, hour = 0;
    
    cout << "Year: ";
    in >> year;
    cout << "Month: ";
    in >> month;
    cout << "Day: ";
    in >> day;
    cout << "Hour: ";
    in >> hour;
    
    D = Date(year, month, day, hour);
    return in; 
  }
}
