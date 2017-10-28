/*
 * Queue.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: Altin & Erick
 */

#include <iostream>
#include <string>
#include "Queue.h"
//#include "Stack.h"
#include <cstdlib>
#include <assert.h>

//Function Prototypes
void Queue::dequeue() {
	assert(!s1.empty()); // stack one must not be empty
	assert(s2.empty()); // stack two must be emtpy
	if (s1.getSize()== 1) // if stack one == 1
		s1.pop(); // call pop
	else { // else
		while (s1.getSize() != 1) { // until top is at bottom of stack
			s2.push(s1.peek()); //push top of list one into list two
			s1.pop(); // pop top from list 1
		}
		s1.pop(); // to remove front of the line
		while (s2.getSize() != 0) { //same loop as above except in reverse
			s1.push(s2.peek());
			s2.pop();
		}
	}

}
/***
void Queue::enqueue(string data) {
	assert(s2.empty());
	cout << "pushing data"<< endl;
	s1.push(data);
}
*/
string Queue::getFront() {
	assert(s2.empty());
	assert(!s1.empty());
	string temp = "";
	if (s1.getSize() == 1) // if stack one == 1
		temp = s1.peek(); // temp value for top
	else { // else
		while (s1.getSize() != 1) { // until top is at last one from bottom of stack
			s2.push(s1.peek()); //push top of list one into list two
			s1.pop(); // pop top from list 1
		}
		temp = s1.peek(); // sets temp to tops data
		while (s2.getSize() != 0) { //same loop as above except in reverse
			s1.push(s2.peek());
			s2.pop();
		}
	}
	return temp;
}
