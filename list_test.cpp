/*
 * This file: list_test.cc
 * This file contains the implementation of a test program 
 * for the linked list class container.
 */

#include <iostream>
#include <string>
#include "List.h"

using namespace std;
using namespace UT_315;

void empty_test(const List<string>& L);
void find_test(const List<string>& L, const string& name);

int main(){
  List<string> L;
  string  name;
  
  empty_test(L);

  name = "Bob Smith";
  cout << "Adding name: " << name << endl;
  L.insert(name);

  name = "Kelly Zim";
  cout << "Adding name: " << name << endl;
  L.insert(name);
  
  name = "Tim Newport";
  cout << "Adding name: " << name << endl;
  L.insert(name);

  name = "Carlos Garcia";
  cout << "Adding name: " << name << endl;
  L.insert(name);
  
  cout << "Printing list forward: " << endl;
  L.print_forward(cout);
  
  cout << "Printing list backward: " << endl;
  L.print_backward(cout);
  
  name = "Bob Bellis";
  find_test(L, name);
  
  name = "Carlos Garcia";
  find_test(L, name);

  name = "Kelly Zim";
  L.erase(name);

  name = "Tim Newport";
  L.erase(name);
  
  name = "Jose Mendez";
  L.insert(name);
  
  cout << endl;
  empty_test(L);
  cout << endl;

  cout << "Printing list forward: " << endl;
  L.print_forward(cout);
  
  cout << "Printing list backward: " << endl;
  L.print_backward(cout); 
 
  L.make_empty();
  empty_test(L);
  cout << "Done!" << endl;
}

void empty_test(const List<string>& L){
  if (L.is_empty()){
    cout << "No elements in the list." << endl;
  }
  else {
    cout << "Some data on the list" << endl;
  }
}

void find_test(const List<string>& L, const string& name) {
  cout << "Finding name: " << name << endl;
  List_Iterator<string> iter = L.find(name);
  if (iter.has_data()){
    cout << "Name: " << name << " was found." << endl;
  }
  else {
    cout << "Name: " << name << " was not found." << endl;
  }  
}
