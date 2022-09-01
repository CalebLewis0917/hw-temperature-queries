#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList() {
	clear();
}

LinkedList::LinkedList(const LinkedList& source) {
	head = nullptr;
	tail = nullptr;
	Node* curr = source.head;
	while(curr!=nullptr){
		this->insert(curr->data.id, curr->data.year, curr->data.month, curr->data.temperature);
		curr = curr->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	this->clear();
	Node* curr = source.head;
	while(curr!=nullptr){
		this->insert(curr->data.id, curr->data.year, curr->data.month, curr->data.temperature);
		curr = curr->next;
	}
	return *this;
}


void LinkedList::insert(string location, int year, int month, double temperature) {
	Node* newNode = new Node(location, year, month, temperature);
	if(head==nullptr){
		head = newNode;
		tail = newNode;
	}
	else{
		if(*newNode < *head){
			newNode->next = head;
			head = newNode;
		}
		else{
			Node* curr = head;
			while(curr->next != nullptr){
				if(*newNode < *curr->next){
					newNode->next = curr->next;
					curr->next = newNode;
					return;
				}
				curr = curr->next;
			}
			tail->next = newNode;
			tail = newNode;
		}	
	}
	return;
}

void LinkedList::clear() {
	if(head!=nullptr){
		Node* curr = head;
		while(curr != nullptr){
			curr = curr->next;
			delete head;
			head = curr;
		}
		head = nullptr;
		tail = nullptr;
	}
}

Node* LinkedList::getHead() const {
	return head;
}

string LinkedList::print() const {
	string outputString;
	ostringstream outSS;
	Node* curr = head;
	while(curr != nullptr){
		outSS << curr->data.id << " " << curr->data.year << " " << curr->data.month << " " << curr->data.temperature << endl;
		curr = curr->next;
	}
	outputString = outSS.str();
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
