#include <stdlib.h>
#include <stdio.h>

struct Node {
	int data; //tipos de datos permitidos
	struct Node* next; //puntero al siguiente elemento de la lista
};

//Imprimir lista
void printList(struct Node* node){

	while (node != NULL){
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("\n");
}
//Liberar memoria
void freeList(struct Node* head) {
	struct Node* current = head;
	struct Node* next;

	while (current != NULL) {
		next = current->next; //guardanos la informacion para poder liberarla
		free(current);
		current = next;
	}

}


//Insertar nodo al principio de la lista
void insertar(int data, struct Node** head) {

	struct Node* nuevo = (struct Node*)malloc(sizeof(struct Node));
	nuevo->data = data;
	nuevo->next = (*head);
	(*head) = nuevo;
	printf("Elemento %d agregado a la lista\n", data);
}


int main() {
	
	struct Node* head = NULL; //Apunta al primer elemento de la lista
	insertar(21, &head);//Se envia el nuevo valor de lista, puntero doble para modificar el valor y simple para imprimir
	printList(head);
	insertar(34, &head);
	printList(head);
	insertar(57, &head);
	printList(head);
	freeList(head);
}
