/*
 * This file: List.cpp
 * 
 * This file contains the implementation of the interface for a 
 * List container class. This list will be implemented as 
 * Sorted Circular Doubly Linked List using the code associated
 * with the Circular Doubly Linked List toolkit. It also implements
 * the methods for an iterator that can be used to traverse 
 * the list.
 *
 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "List.h"

namespace UT_315 {

//////////////////////// DO NOT MODIFY THESE 2 FUNCTIONS /////////////////

  /*
   * Prints the contents of the list in the forward direction.
   * This method is mainly for debugging purposes.
   * Paramter: out - output stream to print the contents of the list.
   */
  template <typename Item>
  void List<Item>::print_forward(ostream& out) const {
    for (List_Iterator<Item> iter = this->first(); 
	 iter.has_data(); 
	 iter.next()){
    cout << iter.get_data() << endl;
    }
  }
  
  /*
   * Prints the contents of the list in the backward direction.
   * This method is mainly for debugging purposes.
   * Paramter: out - output stream to print the contents of the list.
   */
  template <typename Item>
  void List<Item>::print_backward(ostream& out) const {
    for (List_Iterator<Item> iter = this->last(); 
	 iter.has_data(); 
	 iter.prev()){
      cout << iter.get_data() << endl;
    }
  }
  //////////////////////////////////////////////////////////////////////////
  
  
  /******************** START ADDING YOUR CODE FROM THIS POINT ON **********/
  
  //////////////////// BEGIN LIST CONTAINER CLASS //////////////////////////
  
  /*
   * Default constructor used to create an empty list. This list consist of 
   * a single node, whose next and prev links point to itself.
   */
  template <typename Item>
  List<Item>::List() {
    // ADD YOUR CODE HERE!
	  //basic constructor
	head = new cdlist_node<Item>; //new node
	head -> set_next(head);//set next
	head -> set_prev(head);//set previous
  }
  
  /*
   * Constructor used to create a new list by making a deep copy of another
   * list L.
   * Parameter: L - the source list to make the copy
   */
  template <typename Item>
  List<Item>::List(const List<Item>& L){
    // ADD YOUR CODE HERE!
	  //new node
	cdlist_node<Item> *node = new cdlist_node<Item>;

	//set next/prev
	node -> set_next(node);
	node -> set_prev(node);

	list_copy(L.head, node);
	head = node;
  }
  
  /*
   * Destructor used to clear all memory allocated to the list.
   */
  template <typename Item>
  List<Item>::~List(){

    // ADD YOUR CODE HERE!
	make_empty(); //clear list
	delete head; //clear header
  }
  
  /*
   * Copy assignment operator used to re-assign the value of the 
   * the list by making a deep copy of another list L.
   * Parameter: L - the source list to make the copy
   */
  template <typename Item>

  const List<Item>& List<Item>::operator=(const List<Item>& L){

    // ADD YOUR CODE HERE!
	list_clear(head);
	list_copy(L.head, head); //copy onto L
    return *this;
  }
  
  /*
   * Determines if the list is empty or not. An empty list has only one
   * with its prev and next links pointing to itself.
   * Returns: true if the list is empty, or false otherwise.
   */
  template <typename Item>
  bool List<Item>::is_empty() const {

    // ADD YOUR CODE HERE!
	if (head->get_next() == head) { //verify for contents
		return true;
	}
	else {
		return false;
	}
  }
  
  /*
   * Removes all elements from the list, making it an empty list.
   */
  template <typename Item>
  void List<Item>::make_empty(){

    // ADD YOUR CODE HERE!
	list_clear(head); //simple clear command
  }

  /*
   * Returns an iterator to the first element of the list.
   * Returns: iterator object with current position at first element of list 
   */
  template <typename Item>
  List_Iterator<Item> List<Item>::first() const {
    
    // ADD YOUR CODE HERE!
    return List_Iterator<Item>(head, head, true);
  }
  
  /*
   * Returns an iterator to the last element of the list.
   * Returns: iterator object with current position at last element of list 
   */
  template <typename Item>
  List_Iterator<Item> List<Item>::last() const {
    
    // ADD YOUR CODE HERE!
    return List_Iterator<Item>(head, head, false);
  }

  /*
   * Finds an element in the list, and returns an iterator to it.
   * If the element is found, the iterator will have its current position 
   * set to the node where the element resides. Otherwise, an empty
   * iterator is returned.
   * Parameter: obj - the element to found.
   * Returns: iterator to the element 
   */
  template <typename Item>
  List_Iterator<Item> List<Item>::find(const Item& obj) const {

    // ADD YOUR CODE HERE!
	  cdlist_node<Item> *node = list_search(head, obj);

	  if (node != NULL) {
		  cout << "list cpp found!" << endl;
		  return List_Iterator<Item>(node, node, true);
	  }
	  else {
		  cout << "list cpp found failure!" << endl;
		  return List_Iterator<Item>(node, node, false);
	  }

  }

  /*
   * Inserts a new element into the list at its proper position
   * based on the sorted order.
   * Parameter: obj - the new element to be added.
   */
  template <typename Item>
  void List<Item>::insert(const Item& obj) {
    
    // ADD YOUR CODE HERE!
	list_insert(head, obj); //al head le asigna la data que el usuario ingreso como objeto 
	return;
  }

  /*
   * Removes an element from the list, and maintains the sorted
   * order.
   * Paramter: obj - the element to be removed from the list
   * Returns: true - if the element is found and deleted, or false 
   * otherwise.
   */
  template <typename Item>
  bool List<Item>::erase(const Item& obj) {

    // ADD YOUR CODE HERE!
	cdlist_node<Item> *node = list_search(head, obj);

	if (node == head) {//empty list, nothing to erase
		return false;
	}
	else {
		list_remove(node); 
		return true;
	}
  }

  /*
   * Returns the number of elements currently stored in the list.
   * Return: number of elements in the list.
   */
 template <typename Item>
 typename List<Item>::size_type List<Item>::size() const {
    // ADD YOUR CODE HERE!
	  return list_length(head);
  }
  
  //////////////////////////////////////////////////////////////////////////
  
  ///////////////////// BEGIN ITERATOR CLASS ///////////////////////////////
  
  
  /*
   * Creates a new iterator based on the first and last element over
   * which the iterator shall occurs. Both argument are assumed to be
   * non-NULL.
   * 
   * NOTE: This method is the method that the appropriate methods 
   * is class List must call in order to create iterators.
   */
  template <typename Item>
  List_Iterator<Item>::List_Iterator
  (cdlist_node<Item> *init_head, cdlist_node<Item> *init_tail,
   bool go_forward){
    // DO NOT MODIFY THIS FUNCTION!!!!
    head = init_head;
    tail = init_tail;
    
    assert(init_head != NULL);
    assert(init_tail != NULL);

    if (go_forward){
      forward_iter = true;
      current = head->get_next();
    }
    else {
      forward_iter = false;
      current = head->get_prev();
    }
  }
  
  /*
   * Determines if the iterator has any data left. The iterator 
   * is empty if either:
   * a) The iterator is declared as a forward iterator, and the 
   *    current position is the tail.
   * b) The iterator is delcared as a backward iterator, and the
   *    current position is the head.
   */
  template <typename Item>
  bool List_Iterator<Item>::has_data() const {
    // ADD YOUR CODE HERE
	if (forward_iter && current == head){
		return false;
	}
	else if (!forward_iter && current == tail){
		return false;
	}
	return true;
  }

  /*
   * Returns a reference to the object stored at the node currently
   * being pointed to by the iterator (current iterator position).
   * Return: reference to object at the current iterator position.
   */
  template <typename Item>
  Item& List_Iterator<Item>::get_data(){
    // DO NOT MODIFY THIS FUNCTION
    assert(this->has_data());
    return current->get_data();
  }
  

  /*
   * Moves the iteratiot from its current position to the next one.
   * This means that the internal pointer for current position is
   * moved to the next node. 
   * NOTE: This operation only works when the iterator is declared as
   * a forward iterator. Otherwise, the operation does nothing.
   */
  template <typename Item>
  //if foward???
  void List_Iterator<Item>::next() {

    // ADD YOUR CODE HERE!
	current = current->get_next();
  }

  /*
   * Moves the iteration from its current position to the previous one.
   * This means that the internal pointer for current position is
   * moved to the previous node. 
   * NOTE: This operation only works when the iterator is declared as
   * a backward iterator. Otherwise, the operation does nothing.
   */

  template <typename Item>
  //if previous??
  void List_Iterator<Item>::prev(){

    // ADD YOUR CODE HERE
	current = current->get_prev();
  }
  
  //////////////////////////////////////////////////////////////////////////
}
