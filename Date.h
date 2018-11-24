#ifndef _DATE_H
#define _DATE_H

#include <iostream>

using namespace std;

namespace UT_315 {

  class Date {
  public:
    Date(int the_year = 1970, int the_month = 1, int the_day = 1, 
	 int hour=0);
    bool operator==(const Date& D) const;
    bool operator<(const Date& D) const;
    bool operator>(const Date& D) const;
    
    // Read the value for this 
    friend istream& operator>>(istream& input, Date &target);
    // Write the value this this Date
    friend ostream& operator<<(ostream& output, const Date &src);
    
  private:
    int year;
    int month;
    int day;
    int hour;
  };
}
#endif
