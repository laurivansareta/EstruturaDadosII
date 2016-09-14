#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

using namespace std;


	int main(void){

		Node* tree = CreateEmptyTree();
		bool _exit = false;
		int value;

		while(!_exit){
			cin >> value;
			CreateNode(value, &tree);
			tree = Balance(tree);
			printTree(tree, 0);
		}


		cout << "Altura: " << GetHeight(tree) << "\n";
	}