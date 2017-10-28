/*
 * Stack.h
 *
 *  Created on: Oct 26, 2017
 *      Author: Ewreck
 */

 #ifndef STACK_H_
 #define STACK_H_

 #include <cstddef> //for NULL
 #include <iostream>
 #include <cstdlib>
 #include <assert.h>
 using namespace std;

 template <class stackdata>
 class stack {
 public:
 	/**constructors and destructors*/
 	stack();
 	//initializes an empty stack
 	//post condition: creates an empty stack
 	~stack();
 	//frees memory allocated to the stack
 	//postcondition: memory for stack has been freed
 	stack(const stack &S);
 	//copy constructor - initializes this stack to have same elements as S
     //postcondition: a copy of stack


 	/**manipulation procedures*/
 void pop();
 //removes the last item that entered the stack
 //precondition: (size != 0)
 //postcondition: an element has been removed from the top of the stack

 void push(stackdata data);
 //Adds a new node to the top of the stack.
 //postcondition: new node inserted at the top of the stack
      /**accessors**/
 stackdata peek();
 //returns value from the node at the top of the stack
 //precondition: (size != 0)
 // postcondition: returned value from top of stack

 bool operator==(const stack &S);
 //returns whether this stack is equal to another stack S

 int getSize ()const;
 //returns the number of nodes in the list

 bool empty()const;
 //determines weither the list is empty or not

 /****additional operations*****/
 void print()const;
 // //prints the elements in the stack each element separate by a blank space to stdout

 private:
 	struct Node{
 		stackdata data;
 		Node* link;

 		Node(stackdata data){ // node constructor
 			this->data = data;
 			link = NULL;
 		}
 	};

 	Node* top; //stack constructor will set these
 	int size;
 };

 #endif /* STACK_H_ */

 /**************************************/
 /* #include <iostream>
  * #include stack.h
  * #include <cstdlib>
  * #include <assert.h>
  *************************************/

 //Function Prototypes

 template<class stackdata>
 stack <stackdata>::stack(){
 	top = NULL;
 	size = 0;
 }

 template<class stackdata>
 stack<stackdata>::~stack()
 {
 	Node* temp = top;
 	while (temp!=NULL)
 	{
 		temp= temp->link;
 		delete top;
 		top = temp;
 	}
 		delete top;
 		delete temp;
 }

 template<class stackdata>
 stack<stackdata>::stack(const stack  &orig)
 {
 	if(orig.top == NULL){//if original is null initialize values to the defualt settings
 			top = NULL;
 		    size = 0;
 	}
 	else {
 	Node*temp = orig.top; //temp iterator pointing to the top of the list to be copied
 	Node*n = new Node(temp->data);
 	top = n;
 	Node *temp2 = top;
 	temp = temp->link;
 	while(temp != NULL) // while temp
 	{
 		Node*n = new Node(temp->data);
 		temp2->link = n;
 		temp2 = temp2->link;
 		temp = temp->link;
 		//n->link = top;
 		//top = n;
 	}
 	size = orig.size;
  }
 }
 template <class stackdata>
 bool stack <stackdata>::empty() const{
 		return size == 0;
 }

 template <class stackdata>
 void stack <stackdata>::pop(){
 	assert (size != 0);
 	if (size == 1)
 	{
 		delete top;
 		top = NULL;
 		size = 0;
 	}
 	else{
 		Node*temp = top;
 		top = top->link;
 		delete temp;
 		size--;
 	}
 }

 template <class stackdata>
 void stack<stackdata>::push(stackdata data)
 {
 	Node* n = new Node(data);
 	if(empty())
 	{
 		top = n;
 		top->link = NULL;
 	}

 	else {
 		n->link = top;
 		top = n;
 	}
    size++;
 }

 template <class stackdata>
 stackdata stack<stackdata>::peek(){
 	assert (!empty());
 			return (top->data);
 }

 template <class stackdata>
 bool stack<stackdata>::operator==(const stack& Other){
 	if (Other.size != size){
 		return false;
 	}
 	   Node* temp1 = top; //set to start of first list
 	    Node* temp2 = Other.top; // set to start of second
 	    while(temp1 != NULL) //while first temp iterator is not NULL
 	    {
 	        if(temp1->data != temp2->data) { // check if they are not equal
 	        	return false;
 	        }
 	        temp1 = temp1->link; // if they arent continue to the next node to compare
 	        temp2 = temp2->link;
 	    }
 	return true;
 }

 template <class stackdata>
 int stack<stackdata>::getSize() const{
 	return size;
 }
 template <class stackdata>
 void stack<stackdata>::print() const {

     Node* temp = top; //create a temporary iterator
     while (temp != NULL) {

        cout << temp->data << "  "; //prints data to console

     	temp = temp->link; // traverses the list
     }

     cout << endl; //what does this do?

 }
