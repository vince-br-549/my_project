//============================================================================
// Name        : myCodeschoolDobuleLinkedList.cpp
// Author      : Vincent Herried
// Version     :
// Copyright   : Vincent Herried
// Description :  see https://www.youtube.com/watch?v=B31LgI4Y4DQ&t=6213s
// Double linked list
//============================================================================

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct Node {
	int data;
	Node* prev;
	Node* next;
};
Node* head;

Node* GetNewNode(int x) {
	Node* newNode = new Node();
	newNode->data = x;
	newNode->prev = nullptr;
	newNode->next = nullptr;
	return newNode;
}

void InsertAtHead(int x) {
	Node* newNode = GetNewNode(x);
	if ( head == nullptr) {
		head = newNode;
		return;
	}
	head -> prev = newNode;
	newNode->next = head;
	head = newNode;

}
void InsertAtTail(int data) {
	Node* newNode = GetNewNode(data);
	if ( head == nullptr ) {  // empty list
		head = newNode;
		return;
	}
	Node* temp = head;
	// go to end of the list
	while ( temp->next != nullptr) temp = temp->next;
	newNode->prev = temp;
	temp->next = newNode;
}

void Print(Node* p) {
	if ( p->next ==  nullptr ) {
		cout << p->data << endl;
		return;
	}
	cout << p->data<< " " ;
	Print(p->next);
}
void ReversePrint(Node* p) {
	Node* temp = head;
	if (temp == nullptr) return; // list empty exit
	// get to the end of the list
	while ( temp -> next != nullptr ) {
		temp = temp->next;
	}
	// traversing backwards in the list
	cout << "Reverse: ";
	while ( temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
}

void Reverse() {

}

int main(int argc, char **arg)
{

	cout << "Doublely linked list" << endl;
	head = nullptr;  // initialize it !
	int count,data;
        cout << "You will be prompted to enter the data for each element." << endl;
	cout << "Enter number of elements to insert at beginning of the list:" ;
	cin >> count;

	for (int i=0; i<count; i++ )
	{
		cin >> data;
		InsertAtHead(data);
	}
	cout << "print the list" << endl;
	Print(head);
	cout << "print the list again" << endl;
	ReversePrint(head);

	cout << "add some some numbers at the end of the list.. .just a few" << endl;
	InsertAtTail(99);
	InsertAtTail(98);
	Print(head);
	return 0;
}


























