#include "stdafx.h"
#include "MyLinkedListCpp.h"
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{		
	MyLinkedListCpp *myList = new MyLinkedListCpp();
	Console::WriteLine("MOSTRANDO ELEMENTOS DE LA LISTA ENLAZDA");	
	for(int i = 0; i < 100; i++)
	{
		myList->addLast(i + 1);
	}

		myList->showElements();				
	return 0;
}
