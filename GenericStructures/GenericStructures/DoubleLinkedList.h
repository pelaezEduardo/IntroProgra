#pragma once
#include <iostream>

template<class T>
class NodeD {
private:
	T element;
	NodeD<T> *prev;
	NodeD<T> *next;

public:
	NodeD(T t, NodeD<T> *previousNode, NodeD<T> *nextNode) {
		element = t;
		prev = previousNode;
		next = nextNode;
	}

	T getElement() {
		return element;
	}

	NodeD<T> *getPrev() {
		return prev;
	}

	void setPrev(NodeD<T> *previous) {
		prev = previous;
	}

	NodeD<T> *getNext() {
		return next;
	}

	void setNext(NodeD<T> *nextNode) {
		next = nextNode;
	}
};

template<class T>
class DoubleLinkedList
{
private:
	NodeD<T> *header;
	NodeD<T> *trailer;
	int listSize;
	void addBetween(T n, NodeD<T> *predecessor, NodeD<T> *successor);
	T remove(NodeD<T> *node);
public:
	DoubleLinkedList();
	int size();
	bool isEmpty();
	T first();
	T last();
	void addFirst(T n);
	void addLast(T n);
	T removeFirst();
	T removeLast();
	bool search(T reference);
	void purge();	
	~DoubleLinkedList();
};


