#include <iostream>
#include <string>

using namespace std;

class LinkedList{

private:
	struct Node{
		int data;
		Node* next;
	};

	Node* head;
	Node* tail;

public:
	LinkedList();
	void insertAtBeginning(const int addData);
	void bSortList();
	void sortBySwappingPointers();
	void reverseList();
	bool checkIfIdentical(LinkedList l2);

	// we will overload << operator to print linked lists :)
	friend ostream& operator<<(ostream& os, const LinkedList& ll);

};

// initialize head and tail pointers to nullptr
LinkedList::LinkedList(){

	head = nullptr;
	tail = nullptr;
}

// to add a node at the beginning, we have two cases:
// 1. Empty list and 2. Non-empty list.
// if the list is empty we need to update both pointers head and tail.

void LinkedList::insertAtBeginning(const int addData){

	Node* newNode = new Node;
	newNode->data = addData;
	newNode->next = nullptr;

	if(head == nullptr){
		head = newNode;
		tail = newNode;
	}
	else{
		newNode->next = head;
		head = newNode;
	}

}


// sort using bubble sort -- swapping contents
void LinkedList::bSortList()
{
	Node *i, *j;
	int tempInt;

	for(i=head ; i != NULL ; i=i->next)
		for(j=head ; j->next != NULL ; j=j->next){
			if(j->data > j->next->data){

				// swap contents of the nodes
				tempInt = j->data;
				j->data = j->next->data;
				j->next->data = tempInt;
			}
		}
}

// another version of Bubble sort algorithm
void LinkedList::sortBySwappingPointers() {
	Node* a;
	Node* b;
	Node* prev = nullptr;


	//double for loop to set two pointers that will go throught the list
	for (a = head; a != NULL; a = a->next) {
		for (b = head; b->next != NULL; b = b->next) {
			//if the data on pointer b is greater than the data on pointer a
			if (b->data > b->next->data) {
				//if the first two pointers need to be swapped.
				if (prev == nullptr) {
					//moves to next pointer and swaps the two
					head = b->next;
					b->next = head->next;
					head->next = b;
				}

				// checks the other elements in the array
				else {
					prev->next = b->next;
					b->next = prev->next->next;
					prev->next->next = b;
				}
			}
			//updates the previous node
			prev = b;
		}
		//clears the previous node when needed.
		prev = nullptr;
	}


}

// reverse the nodes order of a linked list
void LinkedList::reverseList(){

	// Pointers needed in the function
	Node* curr = head;
	Node *prev = NULL;
	Node *next = NULL;


	while (curr != NULL) {

		next = curr->next;
		curr->next = prev;

		//swaps values
		prev = curr;
		curr = next;
	}
	head = prev;

}

// check if two lists are identical
bool LinkedList::checkIfIdentical(LinkedList l2){
	

	//creates pointers set to the heads of each list
	Node* l2curr = l2.head;
	Node* curr = head;
	

	//only runs when there is a list still
	while (curr != NULL && l2curr != NULL) {
		//if the data on either list are not equal, the function returns false.
		if (curr->data != l2curr->data)
			return false;

		//increments the pointers through the list.
		curr = curr->next;
		l2curr = l2curr->next;
	}
	//if they are equal, returns true.
	return(curr == NULL && l2curr == NULL);


}


// overloading << operator to print a linked list
// os variable is output stream
ostream& operator<<(ostream& os, const LinkedList& ll)
{
	// Node structure is defined inside LinkedList class, we need
	// to use the resolution operator :: to access it.
	// Thats why we defined this function as a friend function, so
	// we can access the Node struct and all private members.

	LinkedList::Node* curr = ll.head;

	while( curr != nullptr){
		os<<"("<<curr->data<<") -> ";
		curr = curr->next;
	}
	os<<"00"<<endl;

	return os;
}


int main(){

	LinkedList myList1, myList2;

	// testing checkIfIdentical function with two empty lists
	cout<<"List 1: "<<myList1; // using the overloaded operator
	cout<<"List 2: "<<myList2;
	cout<<"Test 1: checking identical lists"<<endl;
	if(myList1.checkIfIdentical(myList2)){
		cout<<"Empty lists are identical ..."<<endl;
	}
	else{
		cout<<"Empty lists are NOT identical !!!"<<endl;
	}


	myList1.insertAtBeginning(20);
	myList1.insertAtBeginning(10);
	myList1.insertAtBeginning(25);

	myList2.insertAtBeginning(20);
	myList2.insertAtBeginning(10);
	myList2.insertAtBeginning(25);

	// testing checkIfIdentical function
	cout<<"List 1: "<<myList1;
	cout<<"List 2: "<<myList2;
	cout<<"Test 2: checking identical lists"<<endl;
	if(myList1.checkIfIdentical(myList2)){
		cout<<"Lists are identical ..."<<endl;
	}
	else{
		cout<<"Lists are NOT identical ..."<<endl;
	}

	myList2.insertAtBeginning(101);


	// testing checkIfIdentical function
	cout<<"List 1: "<<myList1;
	cout<<"List 2: "<<myList2;
	cout<<"Test 3: checking identical lists"<<endl;
	if(myList1.checkIfIdentical(myList2)){
		cout<<"Lists are identical ..."<<endl;
	}
	else{
		cout<<"Lists are NOT identical ..."<<endl;
	}


	// testing reverseList function
	cout<<"Test 4: checking reversal function"<<endl;
	cout<<"List 1 before reversal ..."<<endl;
	cout<<"List 1: "<<myList1;
	myList1.reverseList();
	cout<<"List 1 after reversal ..."<<endl;
	cout<<"List 1: "<<myList1;


	//testing soring function
	cout<<"Test 5: checking sorting function"<<endl;
	cout<<"List 1 before sorting ..."<<endl;
	cout<<"List 1: "<<myList1;
	myList1.sortBySwappingPointers();
	cout<<"List 1 after sorting ..."<<endl;
	cout<<"List 1: "<<myList1;



	return 0;
}
