#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

using namespace std;

int printMenu(){
	int option = 0;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n---------OPÇÕES----------\n");
	printf("\n 1 - Inserir\n");
	printf(" 2 - Remover\n");
	printf(" 3 - Imprimir\n");
	printf("\n -99 - SAIR\n");
	printf("-------------------------\n");
	cin >> option;
	return option;
}
int main(void){

	Node* tree = CreateEmptyTree();

	for(int option = printMenu(); option != -99; option = printMenu()){
		int value = 0;
		switch (option){
			case 1:
				printf("\n Digite um numero:\n");
				cin >> value;
				CreateNode(value, &tree);
				tree = Balance(tree);
			break;
			case 2:
				printf("\nDigite um valor a ser removido\n");
				cin >> value;
				tree = remove(value, tree);
			break;
			case 3:
				printTree(tree, 0);
			break;
			case -99:
				return 0;
		}
	}

	cout << "Altura: " << GetHeight(tree) << "\n";
}