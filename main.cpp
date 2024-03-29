// Choose which run to compile
#define RUN0 //RUN1 RUN2 RUN3 RUN4


#ifdef RUN0 

#include"list.h"
#include"studentinfo.h"
#include<iostream>
#include<string>




int main() {

	std::cout << StudentInfo::name() << std::endl;
	std::cout << StudentInfo::id() << std::endl;

	List<std::string> red; //List of integers

	red.push_back("orange");
	red.push_back("2");
	red.add(4, "yellow");
	red.add(4, "red");
	red.add(6, "blue");




	red.pop_front();
	red.pop_rear();
	red.pop_at(1);
	red.size();
	cout << "size: " << red.m_size << endl;
	cout << "front: " << red.front() << endl;
	cout << "getat: " << red.get_at(1) << endl;
	cout << "find: " << red.find("red") << endl;

	red.print();
	//List<std::string> blue = red;
	//cout << "blue print";
	//blue.print();

	//red.push_back("Hello");
	//red.push_front("world");
	//red.push_front("bob");
	//red.push_front("2");
	//red.push_back("blue");
	//red.add(6, "yellow");
	//red.pop_front();
	//red.pop_rear();
	//red.pop_at(0);


	//red.print(); // 2 Bob World Hello

	//cout << endl << "size is: " << red.size() << endl;
	//cout <<  "head item: " << red.front() << endl;
	//cout <<  "tail item: " << red.rear() << endl;
	//cout << "Whatever item: " << red.get_at(2) << endl;
	//cout << "index of whatever: " << red.find("Hello") << endl;

	////List<std::string> blue = red;
	//blue = red;
	//red.print();
	//blue.print();

	//cout << endl << "size is: " << red.size() << endl;
	//cout << endl << "size is: " << blue.size() << endl;


	//red.push_back("Hello");
	//red.push_front("world");
	//red.push_front("bob");

	//blue.push_back("Helloblue");
	//blue.push_front("worldblue");
	//blue.push_front("bobblue");

	//red.print();
	//blue.print();

	//cout << endl << "size is: " << red.size() << endl;
	//cout << endl << "size is: " << blue.size() << endl;


	//red = blue;
	//List<std::string> yellow = blue;

	//red.print();
	//blue.print();
	//yellow.print();

	//cout << endl << "size is: " << red.size() << endl;
	//cout << endl << "size is: " << blue.size() << endl;
	//cout << endl << "size is: " << yellow.size() << endl;

	//red.push_back("Hello");
	//red.push_front("world");
	//red.push_front("bob");
	//red.push_front("2");
	//red.push_back("blue");

	//red.print();
	//blue.print();
	//yellow.print();

	//cout << endl << "size is: " << red.size() << endl;
	//cout << endl << "size is: " << blue.size() << endl;
	//cout << endl << "size is: " << yellow.size() << endl;

	//blue.push_back("3");
	//blue.push_front("5");
	//blue.push_front("6");


	//yellow = red;

	//red.print();
	//blue.print();
	//yellow.print();

	//cout << endl << "size is: " << red.size() << endl;
	//cout << endl << "size is: " << blue.size() << endl;
	//cout << endl << "size is: " << yellow.size() << endl;

	//yellow = red = blue;


	//red.print();
	//blue.print();
	//yellow.print();

	//cout << endl << "size is: " << red.size() << endl;
	//cout << endl << "size is: " << blue.size() << endl;
	//cout << endl << "size is: " << yellow.size() << endl;

	//List<std::string> orange;
	//orange.empty();
	//orange = red;
	//orange.print();
	//cout << endl << "size is: " << orange.size() << endl;


	return 0;
}

#elif defined RUN1
#define MAKE_MEMBERS_PUBLIC
#include"list.h"
#include<assert.h>

//Unit test example for push_font on initially empty list

int main() {

	// Step 1: Initial state
	// Assume that constructor implemented properly
	// If you're not sure if the constructor is 
	// implemented properly, STOP, go back and make
	// sure. Luckily ther default constructor is 
	// done for you.  But the point remains, never,
	// ever, use a function in a test that isn't itself
	// verified to function to spec.
	List<int> l;


	// Step 2: Execute the function to test
	l.push_front(99);

	// Step 3: Verify what you expect to observe.
	// You must know what is suppose to happen in
	// order to analyze for correctness. Generally, 
	// you must permute all possible combinations
	// of all member variables.
	assert(l.head != nullptr);
	assert(l.tail != nullptr);
	assert(l.num_elements == 1);
	assert(l.head->prev == nullptr);
	assert(l.head->next == nullptr);
	assert(l.head->item == 99);


}


#elif defined RUN2
#define MAKE_MEMBERS_PUBLIC
#include"list.h"
#include<assert.h>
#include<string>

//Unit test example for push_font on initially non empty list

int main() {

	// Step 1: Initial state
	// Same as above, except we must first populate the list
	// However, since we are testing push_front, we cannot
	// use it to generate the initial state of our list
	// to test.  So we have to manually set the initial state
	// in this case we are creating a list with three nodes.
	List<std::string>::Node* first = new List<std::string>::Node;
	List<std::string>::Node* second = new List<std::string>::Node;
	List<std::string>::Node* third = new List<std::string>::Node;

	// We have to manually linked everything together:
	first->item = "first";
	first->prev = nullptr;
	first->next = second;

	second->item = "second";
	second->prev = first;
	second->next = third;

	third->item = "third";
	third->prev = second;
	third->next = nullptr;

	// Now we create  List object and inject the initial control state:
	List<std::string> l;
	l.m_head = first;
	l.m_tail = third;
	l.m_size = 3;

	// Step 2: Now with the list given a complete and correct starting state
	// We can test various member functions for correctness.
	// For example we can use this as one test for push_front;
	l.push_front("Zero");

	// Step 3: Verify:  Technically, we should examine all 
	// member variables, and all nodes' item, next, prev pointers
	// to ensure that the push_front didn't mangle any of the
	// internal nodes.  But, this is mostly just to illustrate
	// how you might develop your own tests.  
	assert(l.m_size == 4);
	assert(l.m_head->prev == nullptr);
	assert(l.m_head == first->prev);
	assert(l.m_head->next == first);
	assert(l.m_head->item == "Zero");
	assert(l.m_tail == third);
}

#else

#endif