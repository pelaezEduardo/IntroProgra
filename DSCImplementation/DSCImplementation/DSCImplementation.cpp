#include "stdafx.h"
#include "MyLinkedListCpp.h"
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{		
	MyLinkedListCpp *myList = new MyLinkedListCpp();
	myList->addLast(1);
	myList->addLast(2);
	myList->addLast(3);
	myList->addLast(4);
	myList->addLast(5);
	myList->addFirst(0);
	int cont = myList->size();
	Console::WriteLine("ELEMENTOS DE LA LISTA ENLAZDA");	
	for(int i = 0; i < cont; i++)
	{
		std::cout << myList->removeFirst() << std::endl;
	}
	return 0;
}
