// Alex Henry
// CS 215, Spring 2013
// Programming assignment 4
// 17 April, 2013
//
//Implementation of the PositionList class
#include <cstdlib>
#include "positionlist.h"
using namespace std;

// Initialize a node with no next node and the given position.
Node::Node(Position p)
	: next(NULL), pos(p)
{}

// Default constructor: initialize an empty list.
PositionList::PositionList()
{
	first = NULL;
}


// Test whether the list is empty.
bool PositionList::empty() const
{
	if (first == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Calculate the size of the list.
int PositionList::size() const 
{
	int i = 0;
	for (Node *curr = first; curr != NULL; curr = curr->next) {
		i++;
	}
	return i;
}

// Return the Position at the given index.  If the index is out of
// bounds, return Position(-1, -1).
Position PositionList::get(int index) const
{
	Node *curr = first;
	for (int i = 0; i < index; i++)
	{
		//Check if the current index is in bounds
		if (curr == NULL)
		{
			return Position(-1, -1);
		}

		curr = curr->next;
	}

	if (curr == NULL)
	{
		return Position(-1, -1);
	}

	return curr->pos;
}

// Add a new Position object to the beginning of the list.
void PositionList::push_front(Position pos)
{
	//Be careful of order or else could end up in an infite loop
	Node *to_insert = new Node(pos);
	to_insert->next = first;
	first = to_insert;
}

// Remove the first element, freeing its node.
void PositionList::pop_front()
{
	//Bec careful of order, don't want any hanging pointer errors
	Node *to_del = first;
	first = to_del->next;
	delete to_del;
}

// Initialize a copy of a list using the copy_nodes helper function.
PositionList::PositionList(const PositionList &original)
{
	first = copy_nodes(original.first);
}

// Helper function: recursively copy "in" and all the nodes that follow.
// As a base case, "copying" NULL should return NULL (and not copy anything).
Node *PositionList::copy_nodes(const Node *in) const
{
	if (in == NULL)
	{
		return NULL;
	}

	Node *copy = new Node(in->pos);
	copy->next = copy_nodes(in->next);
	return copy;
}

// Clean up this list by freeing all its nodes.
PositionList::~PositionList()
{
	while (!empty())
	{
		pop_front();
	}
}

PositionList &PositionList::operator=(const PositionList &other)
{
	if (this == &other)
		return *this;

	while (!empty())
	{
		pop_front();
	}
	
	first = copy_nodes(other.first);
}
