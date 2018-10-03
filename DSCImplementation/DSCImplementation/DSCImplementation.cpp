#include "stdafx.h"
#include "MyLinkedListCpp.h"
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{		
	MyLinkedListCpp *myList = new MyLinkedListCpp();
	Console::WriteLine("MOSTRANDO ELEMENTOS DE LA LISTA ENLAZDA");	
	for(int i = 0; i < 200; i++)
	{
		myList->addLast(i + 1);
	}

		myList->showElements();	

		Console::WriteLine("\n\n" + myList->searchElement(3));
		Console::WriteLine(myList->searchElement(15));
		Console::WriteLine(myList->searchElement(20));
		Console::WriteLine(myList->searchElement(200));
		Console::WriteLine(myList->searchElement(500));
	return 0;
}
