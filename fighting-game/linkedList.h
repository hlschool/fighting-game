#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class type>
class node {
public:
	type info;
	node<type>* link;
};

template <class type>
class linkedList {
public:
	linkedList();
	~linkedList();
	node<type>* build(int);
	int length() const;
	bool isEmpty() const;
	void destroy();
	type& getHead() const;
	type& getLast() const;
	type& get(int) const;
	void deleteItem(int);

	const linkedList<type>& operator=(const linkedList<type>&);

	template<class type2>
	friend ostream& operator<<(ostream&, const linkedList<type2>&);

	virtual bool search(const type& searchItem) const = 0;
	virtual void insertFirst(const type& newItem) = 0;
	virtual void insertLast(const type& newItem) = 0;
	virtual void deleteNode(const type& deleteItem) = 0;
	virtual void insertItem(int, const type& item) = 0;


	node<type>* head;
	node<type>* last;

	int size;
};

template <class type>
linkedList<type>::linkedList() {
	head = NULL;
	last = NULL;
	size = 0;
}

template <class type>
linkedList<type>::~linkedList() {
	this->destroy();
}

template <class type>
node<type>* linkedList<type>::build(int l) {
	node<type>* newNode;
	head = NULL;
	for (int i = 0; i < l; i++) {
		newNode = new node<type>;
		newNode->info = 0;
		newNode->link = head;
		head = newNode;
		if (i == 0) {
			last = newNode;
		}
	}
	size = l;
	return head;
}
template <class type>
int linkedList<type>::length() const {
	return this->size;
}
template <class type>
bool linkedList<type>::isEmpty() const {
	return this->size == 0;
}
template <class type>
void linkedList<type>::destroy() {
	node<type>* current = this->head;
	node<type>* trail_current = NULL;
	for (int i = 0; i < this->size; i++) {
		trail_current = current;
		current = current->link;
		delete trail_current;
	}
	this->head = NULL;
	this->last = NULL;
	size = 0;
}
template <class type>
type& linkedList<type>::getHead() const {
	return this->head->info;
}
template <class type>
type& linkedList<type>::getLast() const {
	return this->last->info;
}
template <class type>
type& linkedList<type>::get(int n) const {
	node<type> *current = this->head;
	for (int i = 0; i < n; i++) {
		current = current->link;
	}
	return current->info;
}
template <class type>
void linkedList<type>::deleteItem(int n) {
	node<type>* current = this->head;
	node<type>* trail_current = this->head;
	for (int i = 0; i <= n; i++) {
		if (i == n) {
			if (i == 0) {
				this->head = current->link;
			}
			else {
				trail_current->link = current->link;
			}
			this->size--;
			return;
		}
		trail_current = current;
		current = current->link;
	}
}

template <class type>
ostream& operator<<(ostream& out, const linkedList<type>& l) {
	out << "head -> ";
	node<type>* next = l.head;
	if (next == NULL) {
		out << "NULL";
	}
	for (int i = 0; i < l.size; i++) {
		out << "[" << (next->info) << "]";
		if (i != l.size - 1) {
			out << " -> ";
		}
		next = next->link;
	}
	return out;
}

template <class type>
class unorderedLinkedList : public linkedList<type> {
public:
	bool search(const type&) const;
	void insertFirst(const type&);
	void insertLast(const type&);
	void deleteNode(const type&);
	void insertItem(int, const type&);
};

template <class type>
bool unorderedLinkedList<type>::search(const type& searchItem) const {
	node<type>* current = linkedList<type>::head;
	for (int i = 0; i < linkedList<type>::size; i++) {
		if (current->info == searchItem) {
			return true;
		}
		current = current->link;
	}
	return false;
}

template <class type>
void unorderedLinkedList<type>::insertFirst(const type& firstItem) {
	node<type>* newNode = new node<type>;
	newNode->info = firstItem;
	newNode->link = this->head;
	this->head = newNode;
	this->size++;
}
template <class type>
void unorderedLinkedList<type>::insertLast(const type& lastItem) {
	node<type>* current = this->head;
	node<type>* trail_current = NULL;
	for (int i = 0; i < this->size; i++) {
		trail_current = current;
		current = current->link;
	}
	node<type>* newNode = new node<type>;
	newNode->info = lastItem;
	newNode->link = current;
	trail_current->link = newNode;
	this->size++;
}

template <class type>
void unorderedLinkedList<type>::deleteNode(const type& deleteItem) {
	node<type>* current = this->head;
	node<type>* trail_current = this->head;
	for (int i = 0; i < this->size; i++) {
		if (current->info == deleteItem) {
			if (i == 0) {
				this->head = current->link;
			}
			else {
				trail_current->link = current->link;
			}
			this->size--;
			return;
		}
		trail_current = current;
		current = current->link;
	}
}

template<class type>
void unorderedLinkedList<type>::insertItem(int n, const type& item) {
	node<type>* current = this->head;
	node<type>* trail_current = NULL;
	for (int i = 0; i < n; i++) {
		trail_current = current;
		current = current->link;
	}
	node<type>* newNode = new node<type>;
	newNode->info = item;
	newNode->link = current;
	if (trail_current == NULL) {
		this->head = newNode;
	}
	else {
		trail_current->link = newNode;
	}
	this->size++;
}

template <class type>
class orderedLinkedList : public linkedList<type> {
public:
	bool search(const type&) const;
	void insert(const type&);
	void deleteNode(const type&);
private:
	void insertFirst(const type&);
	void insertLast(const type&);
	void insertItem(int, const type&);
};

template <class type>
bool orderedLinkedList<type>::search(const type& searchItem) const {
	node<type>* current = this->head;
	for (int i = 0; i < this->size; i++) {
		if (current->info == searchItem) {
			return true;
		}
		current = current->link;
	}
	return false;
}

template <class type>
void orderedLinkedList<type>::insert(const type& item) {
	if (this->isEmpty()) {
		insertItem(0, item);
		return;
	}
	node<type>* current = this->head;
	for (int i = 0; i < this->size; i++) {
		if (item < current->info) {
			insertItem(i, item);
			return;
		}
		current = current->link;
	}
}

template <class type>
void orderedLinkedList<type>::deleteNode(const type& deleteItem) {
	node<type>* current = this->head;
	node<type>* trail_current = this->head;
	for (int i = 0; i < this->size; i++) {
		if (current->info == deleteItem) {
			if (i == 0) {
				this->head = current->link;
			}
			else {
				trail_current->link = current->link;
			}
			this->size--;
			return;
		}
		trail_current = current;
		current = current->link;
	}
}

template <class type>
void orderedLinkedList<type>::insertFirst(const type& item) {

}
template <class type>
void orderedLinkedList<type>::insertLast(const type& item) {

}
template<class type>
void orderedLinkedList<type>::insertItem(int n, const type& item) {
	node<type>* current = this->head;
	node<type>* trail_current = NULL;
	for (int i = 0; i < n; i++) {
		trail_current = current;
		current = current->link;
	}
	node<type>* newNode = new node<type>;
	newNode->info = item;
	newNode->link = current;
	if (trail_current == NULL) {
		this->head = newNode;
	}
	else {
		trail_current->link = newNode;
	}
	this->size++;
}

#endif
