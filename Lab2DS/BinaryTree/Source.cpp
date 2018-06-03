#include <iostream>
#include "problems.h"
#include "ClassTree.h"
#include "methods.h"
#include "deleteNode.h"
#include <iomanip>
#include <time.h>
#include <stdarg.h>


void main() {
	srand(time(NULL));

	BinaryTree<int> Numbers1;



	Numbers1.show();
	//Numbers1.fillRandom();
	Numbers1.push(5);
	Numbers1.push(0);
	Numbers1.push(5);
	Numbers1.push(10);
	Numbers1.push(4);
	Numbers1.push(7);
	Numbers1.push(9);
	Numbers1.push(16);
	Numbers1.push(9);
	Numbers1.push(89);
	Numbers1.show(); 
	cout << "--------------------------------\n";
std:vector<int>choosed = setVector();
	Numbers1.delete_choosen(choosed);
//	Numbers1.delete_choosen(choosed);
	//Numbers1.deleteNode(5);
	//Numbers1.deleteNode(7);
	//Numbers1.deleteNode(9);
	Numbers1.show();

	/*
	cout << "\nafter\n";

	Numbers1.deleteNode(10);
	Numbers1.deleteNode(5);
	Numbers1.deleteNode(9);
	Numbers1.show();
	
	cout << "\nafter\n";

	int *ArrayFromTree = new int[Numbers1.getSize()];
	Numbers1.maxCount(ArrayFromTree);
	Numbers1.minCount(ArrayFromTree);
	cout << "clear\n";
	Numbers1.clear();
	Numbers1.show();
	*/


	system("pause");
}