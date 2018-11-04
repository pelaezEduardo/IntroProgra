// GenericStructures.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "MyLinkedList.h"
#include "MyLinkedList.cpp"
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "Student.h"

using namespace std;
int main() {	
	BinaryTree<int> *myTree = new BinaryTree<int>();
	for (size_t i = 0; i < 100; i++)
	{
		myTree->add(i + 1, i);
	}	

	myTree->preOrder(myTree->root);
}