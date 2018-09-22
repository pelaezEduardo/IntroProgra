#include "stdafx.h"
#include "MyLinkedListCpp.h"
#include "LinkedStackCpp.h"
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{	
	MyLinkedListCpp *myList = new MyLinkedListCpp();
	LinkedStackCpp *myStack = new LinkedStackCpp();
	myList->addFirst(1);
	myList->addFirst(2);
	myList->addFirst(3);
	myList->addFirst(4);
	myList->addFirst(5);
	myList->addLast(0);	

	myStack->push(5);
	myStack->push(4);
	myStack->push(3);
	myStack->push(2);
	myStack->push(1);
	myStack->push(0);
	int size = myList->size();

	Console::WriteLine("ELEMENTOS DE LA LISTA ENLAZDA");
	for (int i = 0; i < size; i++)
	{
		Console::WriteLine(myList->removeFirst());
	}	

	Console::WriteLine("ELEMENTOS DE LA PILA");
	for (int i = 0; i < size; i++)
	{
		Console::WriteLine(myStack->pop());
	}
	return 0;
}
