#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include <string>
#include "Node.h"

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	// Default constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// Copy constructor
	LinkedList(const LinkedList& other);

	// Assignment constructor
	LinkedList& operator=(const LinkedList& other);

	// Insert a record to the linked list
	void insert(std::string location, int year, int month, double temperature);

	// Clear the content of this linked list
	void clear();

	friend std::ostream& operator<<(std::ostream&, const LinkedList&);

	// The functions below are written already. Do not modify them.
	void print() const;
	void print(std::ostream&) const;
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);
#endif
