/*
  Desenvovido por:
  Laurivan Sareta : laurivan_sareta@hotmail.com
  Fabio Bacin : fabio.bacin@unochapeco.edu.br
*/
  
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int valor;
  struct node *esq, *dir;
}raiz;


int menu(){
  int op;
  printf("Selecione uma opção:\n");
  printf("1 - Inserir elemento na arvore\n");
  printf("2- Imprimir arvore\n");
  printf("3- Remover elemento\n");
  printf("4- Sair\n");
  printf("Op: "); scanf("%d", &op);
  return op;
}

void imprimePonto(int n){
  int i;
  for (i = 0; i < n; i++) printf(".");
}

int lerValor(){
  int valor;
  printf("Informe o valor: ");
  scanf("%d", &valor);
  return valor;
}

void inserirFolha(raiz **arvore, int valor){
  if (*arvore == NULL){
    (*arvore) = (raiz *)malloc(sizeof(raiz));
    (*arvore)->valor = valor;
    (*arvore)->esq = (*arvore)->dir = NULL;
    return ;
  }
  if (valor < (*arvore)->valor){ inserirFolha(&(*arvore)->esq, valor); return ; }
  inserirFolha(&(*arvore)->dir, valor);
}



void imprimeArvore(raiz *arvore, int nivel){
  if (arvore == NULL) return ;
  imprimePonto(nivel * 2 + 2);
  printf("%d\n", arvore->valor);
  imprimeArvore(arvore->esq, nivel + 1);
  imprimeArvore(arvore->dir, nivel+1);
}

void finalizaArvore(raiz **arvore){
  if (*arvore == NULL) return ;
  finalizaArvore(&(*arvore)->esq);
  finalizaArvore(&(*arvore)->dir);
  *arvore = NULL;
}

raiz* maiorEsquerda(raiz *arvore){
  raiz *temp;
  if (arvore == NULL) return NULL;
  if (arvore->esq == NULL && arvore->dir == NULL){
      return arvore;
    }
    if (arvore->dir == NULL){
      return arvore; 
    }
  return maiorEsquerda(arvore->dir);
}

raiz* remover(raiz *arvore, int num){
  raiz *remTemp, *esqTemp, *dirTemp;
  if(arvore == NULL) return NULL;

  //Caso 1
  if(arvore->esq == NULL && arvore->dir == NULL){
    if (arvore->valor == num){
      free(arvore);  
      return NULL;
    }
    return arvore;    
  }

  //caso 2
  if(arvore->esq != NULL && arvore->dir == NULL){
    remTemp = arvore->esq;
    if (arvore->valor == num){
      free(arvore);
      return remTemp; 
    }else{
      arvore->esq = remover(arvore->esq, num);
      return arvore;
    }
  }

  //caso 2
  if(arvore->dir != NULL && arvore->esq == NULL){
    remTemp = arvore->dir;
    if (arvore->valor == num){
      free(arvore);
      return remTemp; 
    }else{
      arvore->dir = remover(arvore->dir, num);
      return arvore;
    }
  }

  if (arvore->valor != num){
    arvore->esq = remover(arvore->esq, num);
    arvore->dir = remover(arvore->dir, num);
  }else{
    //caso 3
    esqTemp = arvore->esq;
    dirTemp = arvore->dir;
    remTemp = maiorEsquerda(esqTemp);
    arvore->valor = remTemp->valor;
    esqTemp = remover(esqTemp, arvore->valor);
    arvore->esq = esqTemp;
    arvore->dir = dirTemp;
    return arvore;
  }

}

int main(void){
  int op, num;
  raiz *arvore = NULL;
  
  inserirFolha(&arvore, 5);
  inserirFolha(&arvore, 10);
  inserirFolha(&arvore, 20);
  inserirFolha(&arvore, 3);
  inserirFolha(&arvore, 1);
  inserirFolha(&arvore, 4);
	
  while (op = menu(), op != 4){
    switch(op){
      case 1:

      num = lerValor();
      inserirFolha(&arvore, num);
      printf("ELEMENTO INSERIDO COM SUCESSO!\n\n");
      break;
      case 2:

      printf("ARVORE IMPRESSA:\n");
      imprimeArvore(arvore, 0);
      printf("\n");
      break;
      case 3:

      num = lerValor();
      arvore = remover(arvore, num);      
      break;
    }
  }
  finalizaArvore(&arvore);
  return 0;
}