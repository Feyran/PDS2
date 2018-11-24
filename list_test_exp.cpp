/*
 * This file: list_text_exp.cpp
 *
 * DO NOT MODIFY THIS FILE.
 */
#include <string>
#include "cdlist_node.cpp"
#include "List.cpp"

using namespace std;
using namespace UT_315;


// Explicit binding of templates

// Node of strings

template class cdlist_node<string>;

// List of strings
template class List<string>;

// Iterator of strings
template class List_Iterator<string>;
