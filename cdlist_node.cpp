/*
 * This file: cdlist_node.cpp
 *
 * This file contains the implementation of the class cdlist_node
 * which represents a node in circular-doubly linked list. 
 * It also contains the implementations of a series of functions
 * that implemented a sorted circular-doublu linked list,
 * where nodes are inserted or deleted under the constrain
 * that a certain order must be maintained. The template parameter
 * Item is the type of object to be stored in the node. It is assumed 
 * that the object type stored in the nodes has overloaded the relational
 * comparison operators in order to determine the relative 
 * order of each item.
 */

#include "cdlist_node.h"

namespace UT_315 {

  
  /*
   * Removes a given element from the list. The argument is the 
   * pointer to the element to be removed from the list.
   * Parameter: target_ptr - pointer to target node (assumed not NULL)
   */
  template <typename Item>
  void list_remove(cdlist_node<Item>* target_ptr){

    // ADD YOUR CODE HERE!

	  //isolate node
	target_ptr -> get_prev() -> set_next(target_ptr -> get_next());
	target_ptr -> get_next() -> set_prev(target_ptr -> get_prev());

	delete target_ptr;
  }
  
  /*
   * Inserts a new item into the linked list BEFORE the node pointed to
   * by the target_ptr paramter.
   * Parameter: obj - new object to be added into the list.
   * Parameter: target_ptr - pointer to a node, the new element will be added 
   *            before it. This pointer is assumed not NULL.
   */
  template <typename Item>
  void list_insert(cdlist_node<Item>* target_ptr, const Item& obj){

    // ADD YOUR CODE HERE!

	  //create new node and ptr
	cdlist_node<Item> *node = NULL; //new pointer
	node = new cdlist_node<Item>; //creates new node

	//connecting new node to list
	node -> set_data(obj); 
	node -> set_next(target_ptr); 
	node -> set_prev(target_ptr->get_prev());

	//connecting to the new node
	target_ptr -> get_prev() -> set_next(node); 
	target_ptr -> set_prev(node);
  }

  /*
   * Copy all elements from linked list into another linked list. This
   * is a deep copy operation.
   * NOTE: The destination list is assumed to be empty!!! Both pointers
   * are assumed not NULL.
   * Parameter: src_head_ptr - constant pointer to the head of source list.
   * Parameter: dst_head_ptr - pointer to the head of the target list.
   */
  template <typename Item>
  void list_copy(cdlist_node<Item>* src_head_ptr, 
		 cdlist_node<Item>* dst_head_ptr){
   // ADD YOUR CODE HERE!
	cdlist_node<Item> *temp1 = NULL, *temp2 = NULL; 

	temp1 = src_head_ptr->get_next(); 
	temp2 = dst_head_ptr;

	while (temp1 != src_head_ptr){  //loop until header

		list_insert(temp2, temp1->get_data()); //copy onto	

		//update temps
		temp1 = temp1 -> get_next(); 
		temp2 = temp2 -> get_next();
	}
	return;
  }

  /*
   * Removes all elements from the list, leaving it with only 
   * the header node. The parameter is the header of the list
   * to be cleared. 
   * NOTE: head_ptr is assumed to be non-NULL
   * Parameter: head_ptr - pointer to the header of the list
   */
  template <typename Item>
  void list_clear(cdlist_node<Item>* head_ptr){

   // ADD YOUR CODE HERE!
	  if (head_ptr->get_next() == head_ptr) //if next is header, dont clear
		  return;
	  else {
		  while (head_ptr->get_next() != head_ptr) { 
			  list_remove(head_ptr->get_next()); //remove element
		  }
	  }
	}
  

  /*
   * Returns the length of this list. The parameter is the header
   * of the list. 
   * NOTE: head_ptr is assumed to be non-NULL
   * Parameter: head_ptr - pointer to the head of the list
   */ 
  template <typename Item>
  std::size_t list_length(cdlist_node<Item> *head_ptr){
     
    // ADD YOUR CODE HERE!
	size_t count = 0;

	cdlist_node<Item> *curr = NULL; 
	curr = head_ptr->get_next(); //set to start after header

	for (; curr != head_ptr; curr = curr->get_next()) {//cycle thru nodes
		count++;
	}
	return count;
  }
  
  /*
   * Finds and returns the pointer to the node containing a given
   * object. The function receives the header of the list and the 
   * object to be found.
   * Parameter: head_ptr - pointer to the header of the list
   * Parameter: obj - the object to be found
   * NOTE: obj must have its operator == overloaded, and head_ptr is 
   * assumed to be non-NULL.
   */
  template <typename Item>
  cdlist_node<Item>* list_search(cdlist_node<Item> *head_ptr, 
				 const Item& obj){
     
     // ADD YOUR CODE HERE!
	cdlist_node<Item> *node = NULL; //new node
	for (node = head_ptr->get_next(); node != head_ptr; node = node->get_next()) {  //loop until temp = header
		if (node->get_data() == obj) { //data found
			return node;
		}
	}
	return NULL; //data was never found
  }
  
  /*
   * Finds and returns constant pointer to the node containing a given
   * object. The function receives the header of the list and the 
   * object to be found.
   * Parameter: head_ptr - pointer to the header of the list
   * Parameter: obj - the object to be found
   * NOTE: obj must have its operator == overloaded, and head_ptr is 
   * assumed to be non-NULL.
   */
 
  template <typename Item>
  const cdlist_node<Item>* list_search(const cdlist_node<Item> *head_ptr, 
				       const Item& obj){

    // ADD YOUR CODE HERE!
	cdlist_node<Item> *node = NULL; //new node
	for (node = head_ptr -> get_next(); node != head_ptr; node = node -> get_next()){  //loop until temp = header
		if (node -> get_data() == obj){ //data found
			return node;
		}
	}
    return NULL; //data was never found
  }


  /*
   * Finds the location where a new element should go in order to 
   * keep an increasing sorted order. Returns the pointer to this
   * location.
   * Parameter: head_ptr - pointer to the head of the list
   * Parameter: obj - element which we want to location a position for
   * NOTE: obj must have its operators == and > overloaded, and
   * head_ptr cannot be NULL.
   */
  template <typename Item>
  cdlist_node<Item> *list_locate(cdlist_node<Item>* head_ptr,
				 const Item& obj){

    // ADD YOUR CODE HERE!
	cdlist_node<Item> *node = NULL; //new node

	for (node = head_ptr->get_next(); node != head_ptr; node = node->get_next()){ //loop thru nodes
		if (node -> get_data() > obj) { 
			return node; //returns found node
		}
	}
	return node; //didnt locate
  }
	
}
		