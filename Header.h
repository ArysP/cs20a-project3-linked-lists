// C++ program to create the Generic Double linked list class
// list.h

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>
using namespace std;

// Node class
template <class Type>
class Node
{
private:
	Type data;
	Node<Type>* next;
	Node<Type>* prev;

public:
	Node(Type _data, Node<Type>* _prev = NULL, Node<Type>* _next = NULL);
	void setData(Type _data);
	void setNext(Node<Type>* _next);
	void setPrev(Node<Type>* _prev);
	Type getData();
	Node<Type>* getNext();
	Node<Type>* getPrev();
};

// constructor
template <class Type>
Node<Type>::Node(Type _data, Node<Type>* _prev, Node<Type>* _next) : data(_data), prev(_prev), next(_next)
{}

// setter
template <class Type>
void Node<Type>::setData(Type _data)
{
	data = _data;
}

template <class Type>
void Node<Type>::setNext(Node<Type>* _next)
{
	next = _next;
}

template <class Type>
void Node<Type>::setPrev(Node<Type>* _prev)
{
	prev = _prev;
}

// getter
template <class Type>
Type Node<Type>::getData()
{
	return data;
}

template <class Type>
Node<Type>* Node<Type>::getNext()
{
	return next;
}

template <class Type>
Node<Type>* Node<Type>::getPrev()
{
	return prev;
}

// List class
template <class Type>
class List
{
private:
	Node<Type>* head, * tail;
	int num_elements;
public:
	List();
	List(const List<Type>& other);
	List<Type>& operator=(const List<Type>& other);
	~List();
	void print() const;
	bool empty() const;
	void push_front(const Type& item);
	void push_back(const Type& item);
	void add(int index, const Type& item);
	Type front() const;
	Type rear() const;
	Type get_at(int index) const;
	int size() const;
	int find(const Type& item);
	bool pop_front();
	bool pop_rear();
	bool pop_at(int index);
};

// constructor
template<class Type>
List<Type>::List()
{
	head = NULL;
	tail = NULL;
	num_elements = 0;
}

// copy constructor
template <class Type>
List<Type>::List(const List<Type>& other)
{
	head = NULL;
	tail = NULL;
	num_elements = 0;

	Node<Type>* curr = other.head;

	while (curr != NULL)
	{
		push_back(curr->getData());
		curr = curr->getNext();
	}
}

// overloaded assignment operator
template <class Type>
List<Type>& List<Type>::operator=(const List<Type>& other)
{
	// delete the existing list
	if (head != NULL)
	{
		Node<Type>* temp = head;
		head = head->getNext();
		delete(temp);
	}

	//copy the other list
	head = NULL;
	tail = NULL;
	num_elements = 0;

	Node<Type>* curr = other.head;

	while (curr != NULL)
	{
		push_back(curr->getData());
		curr = curr->getNext();
	}

}

// destructor
template <class Type>
List<Type>::~List()
{
	while (head != NULL)
	{
		Node<Type>* temp = head;
		head = head->getNext();
		delete(temp);
	}

	tail = NULL;
}

// display the elements of the list
template <class Type>
void List<Type>::print() const
{
	Node<Type>* curr = head;

	while (curr != NULL)
	{
		if (curr->getNext() != NULL)
			cout << curr->getData() << " ";
		else
			cout << curr->getData();
		curr = curr->getNext();
	}

	cout << endl;
}

// returns true if the list is empty else false
template <class Type>
bool List<Type>::empty() const
{
	return (head == NULL);
}

// inserts the item at the head
template <class Type>
void List<Type>::push_front(const Type& item)
{
	Node<Type>* node = new Node<Type>(item);
	node->setNext(head);
	node->setPrev(NULL);
	if (head != NULL)
		head->setPrev(node);
	else
		tail = node;
	head = node;
	num_elements++;
}

// inserts the item at the tail
template <class Type>
void List<Type>::push_back(const Type& item)
{
	Node<Type>* node = new Node<Type>(item);
	node->setNext(NULL);
	node->setPrev(tail);

	if (tail != NULL)
		tail->setNext(node);
	else
		head = node;
	tail = node;
	num_elements++;
}

// inserts the item at the given index
template <class Type>
void List<Type>::add(int index, const Type& item)
{
	// insert at head
	if (index <= 0)
		push_front(item);
	else if (index >= size()) // insert at tail
		push_back(item);
	else // insert in the middle
	{
		Node<Type>* node = new Node<Type>(item);
		Node<Type>* curr = head;
		int i = 0;
		// loop to get the node currently at index
		while (i < index)
		{
			curr = curr->getNext();
			i++;
		}
		// update the pointers to insert node at index
		node->setPrev(curr->getPrev());
		curr->getPrev()->setNext(node);
		node->setNext(curr);
		curr->setPrev(node);
		num_elements++;
	}
}

// return the data at head
template <class Type>
Type List<Type>::front() const
{
	assert(size() > 0);
	return head->getData();
}

// return the data at tail
template <class Type>
Type List<Type>::rear() const
{
	assert(size() > 0);
	return tail->getData();
}

// return the data at index
template <class Type>
Type List<Type>::get_at(int index) const
{
	assert(index >= 0 && index < size());
	if (index == 0) // head data
		return front();
	else if (index == size() - 1) // tail data
		return rear();
	else
	{
		// data at the middle of the list
		int i = 0;
		Node<Type>* curr = head;
		// loop to get the node at index
		while (i < index)
		{
			curr = curr->next;
			i++;
		}

		return curr->getData();
	}
}

// return number of elements of the list
template <class Type>
int List<Type>::size() const
{
	return num_elements;
}

// returns the index of item in the list
template <class Type>
int List<Type>::find(const Type& item)
{
	int i = 0;
	Node<Type>* curr = head;
	// loop to find the item in the list
	while (curr != NULL)
	{
		if (curr->getData() == item)
			return i;
		i++;
		curr = curr->getNext();
	}

	return -1; // item not found
}

// remove the data at the head
template <class Type>
bool List<Type>::pop_front()
{
	if (head != NULL)
	{
		Node<Type>* temp = head;
		head = head->getNext();
		if (head == NULL)
			tail = NULL;
		delete(temp);
		num_elements--;
		return true;
	}

	return false;
}

// remove the data at the tail
template <class Type>
bool List<Type>::pop_rear()
{
	if (tail != NULL)
	{
		Node<Type>* temp = tail;
		tail = tail->getPrev();
		if (tail == NULL)
			head = NULL;
		delete(temp);
		num_elements--;
		return true;
	}

	return false;
}

// remove the data at index
template <class Type>
bool List<Type>::pop_at(int index)
{
	if (index >= 0 && index < size())
	{
		if (index == 0)
			return pop_front();
		else if (index == num_elements - 1)
			return pop_rear();
		else
		{
			int i;
			Node<Type>* curr = head;
			// loop to get the node at the index
			while (i < index)
			{
				curr = curr->getNext();
				i++;
			}
			// update the pointers
			curr->getPrev()->setNext(curr->getNext());
			curr->getNext()->setPrev(curr->getPrev());
			num_elements--;
			delete(curr);
			return true;
		}
	}

	return false;
}

#endif
//end of list.h