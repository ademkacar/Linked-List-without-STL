
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
	int data;
	struct node* next;
};
struct node* head, * tail;


void add(int x) {
	 
	//boşsa
	if (head == NULL) {
		struct node* temp = new struct node;

		temp->data = x;
		head, tail = NULL;
		head = tail = temp;
	}
	//doluysa
	else {
		struct node* temp = new struct node;
		temp->data = x;
		tail->next = temp;
		tail = temp;
	}
}



void yazdir() {
	struct node* index = new struct node;
	index = head;

	while (index) {
		cout << index->data << endl;
		index = index->next;
	}

}

void terstenEkle(int x) {
	
	//boşsa
	if (head == NULL) {
		struct node* temp = new struct node;
		temp->data = x;

		tail = NULL;
		head = tail = temp;
	}
	//doluysa 
	else {
		struct node* temp = new struct node;
		temp->data = x;

		temp->next = head;
		head = temp;

	}

}





// Delete Node  
void deleteNode(int data) {

	struct node* prev = NULL;
	struct node* index = head;

	// Linked List is empty
	if (head == NULL) {
		printf("Linked List is empty \n");
		return ;
	}

	// Delete Head Node
	if (head->data == data) {
		struct node* t = head;
		head = head->next;
		free(t);
		return ;
	}

	// Search in Linked List
	while (index != NULL && index->data != data) {
		prev = index;
		index = index->next;
	}

	// Data not found
	if (index == NULL) {
		printf("Data not found. \n");
		
		return;
	}

	// Data found
	prev->next = index->next;

	// Delete Tail Node
	if (tail->data == data) {
		tail = prev;
	}

	// Clean Memory
	free(index);

	
}


void silme(int x) {
	struct node* prev = new struct node;
	struct node* index = head;

	//list boşsa
	if (head == NULL) {
		cout << "bos" << endl;
	}

	//silinecek eleman head ise
	if (head->data == x) {
		head = head->next;
	}

	//standart silme işlemi
	while (index != NULL && index->data != x) {
		prev = index;
		index = index->next;
	}
	prev->next = index->next;
}






int main() {
	add(10),add(20),add(85),add(1),terstenEkle(4);
	
	//deleteNode(1);

	silme(10);
	silme(20);
	yazdir();


	return 0;
}