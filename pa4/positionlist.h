// Alex Henry
// CS 215, Spring 2013
// Programming assignment 4
// 17 April, 2013
//
//Header file for the PositionList class
#ifndef POSITIONLIST_H_INCLUDED
#define POSITIONLIST_H_INCLUDED

#include "position.h"

// Class representing a node in a PostionList.  This class
// is intended to be used only by PositionList.
class Node
{
public:
	// Create a new node with no next node and position p.

	//int Node::Node(Postion P) const
	//	initialize a node object
	//
	//Description:
	// Create a new node with no next node and position p.
	//
	//Inputs:
	//	A position P for the node
	//
	//Outputs:
	//	none, modifies the position pos member
	Node(Position p);

private:
	// A pointer to the next node in the linked list.
	Node *next;

	// The Position being stored in this node.
	Position pos;

	// The Node class is intended for the internal use of
	// PositionList, so give that class access to our
	// private data members.
	friend class PositionList;
};

// Class representing a position on a two-dimensional board.
// Stores an x and y coordinate, with methods to return and
// set each coordinate, and a method to test whether the
// position falls within a given width and height.
class PositionList
{
public:
	//PositionList::PositionList()
	//	create a PositionList object
	//
	//Description:
	// Initialize an empty list.
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	None, initializes the first private member with NULL
	PositionList();

	// Initialize a list as a deep copy of another.

	//PositionList::PositionList(const PositionList &original)
	//	create a PositionList object
	//
	//Description:
	// Initialize a list as a deep copy of another.
	//
	//Inputs:
	//	A positionList you want to deep copy from
	//
	//Outputs:
	//	None, initializes the first private member and posssibly next
	PositionList(const PositionList &original);

	//PositionList::~PositionList()
	//	PositionList destructor
	//
	//Description:
	// Clean up this list by freeing all its nodes.
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	None
	~PositionList();

	// Deep copy the contents of another list into this one.  Replace the old
	// contents of this list, freeing those nodes.  Returns the implicit
	// parameter by reference (return *this;)
	//
	// This method implements assignment:   poslist = otherposlist;

	//PositionList::&operator=(const PositionList &other)
	//	'=' operator assignment
	//
	//Description:
	// Deep copy the contents of another list into this one.  Replace the old
	// contents of this list, freeing those nodes.  Returns the implicit
	// parameter by reference (return *this;)
	//
	//Inputs:
	//	Another positionList object to deep copy into the implicit object
	//
	//Outputs:
	//	None, modifies the node private data
	PositionList &operator=(const PositionList &other);

	//bool PositionList::empty()
	//	test if empty
	//
	//Description:
	// Returns true if this list is empty.
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	A bool, true if this list is empty
	bool empty() const;

	//int PositionList::size()
	//	find the size
	//
	//Description:
	// Tells what size the implicit list is
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	An int representing the number of nodes
	int size() const;
	
	// Find and return the index-th element in the list, counting from 0.
	// If the index was out of bounds, return the Position (-1, -1).

	//Position PositionList::get(int index) const
	//	return the element at index in the list
	//
	//Description:
	// Find and return the index-th element in the list, counting from 0.
	// If the index was out of bounds, return the Position (-1, -1).
	//
	//Inputs:
	//	int index - the position of the element you want
	//
	//Outputs:
	//	A position object that was located at the index
	Position get(int index) const;

	//Position PositionList::push_front(Position pos)
	//	add to list
	//
	//Description:
	// Add a new Position object to the beginning of the list.
	//
	//Inputs:
	//	Position pos - Position object to add to the list
	//
	//Outputs:
	//	none, modifies the list
	void push_front(Position pos);

	//Position PositionList::pop_front()
	//	remove item from the list
	//
	//Description:
	// Remove the first element, freeing its node.
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	none, modifies the list by deleting the first item
	void pop_front();

private:
	// Recursively make a deep copy of a node and all the nodes that follow.
	// Returns the copy.  The input may be NULL, in which case nothing is
	// copied and the function returns NULL.
	// This function will be used by the copy constructor and by operator= .

	//Node* PositionList::copy_nodes(const Node *in) const
	//	remove item from the list - private function
	//
	//Description:
	// Recursively make a deep copy of a node and all the nodes that follow.
	// Returns the copy.  The input may be NULL, in which case nothing is
	// copied and the function returns NULL.
	// This function will be used by the copy constructor and by operator= .
	//
	//Inputs:
	//	const Node *in - node to begin the deep copying at
	//
	//Outputs:
	//	A node that is the first node in the new linked list of nodes
	Node *copy_nodes(const Node *in) const;

	Node *first;
};

#endif
