#include <stdlib.h>
#include <stdio.h>

struct Node {
	int data; //tipos de datos permitidos
	struct Node* next; //puntero al siguiente elemento de la lista
};
//Buscar nodo por su valor
void findList(int valor, struct Node *node){
	 struct Node* current = node;

 	 //Buscar el nodo
        while (current != NULL && current -> data != valor){
                current = current->next;
	}
	//Nodo no encontrado
        if (current == NULL){
                printf("No existe el valor %d en la lista\n", valor);
                return;
        }
        //Nodo existe
        printf("Existe %d en la lista\n", valor);

}

//Eliminar nodo por valor
void deleteNode(int valor, struct Node **node){
	struct Node* current = *node;
	struct Node* prev = NULL;
	//ELiminar primer elemento
	if (current != NULL && current->data == valor){
		*node = current->next;
		free(current);
		printf("Se ha eliminado el elemento %d\n", valor);
		return;
	}
	
	//Buscar el nodo
	while (current != NULL && current -> data != valor){
		prev = current;
		current = current->next;
	}

	//Nodo encontrado o se llego al final de la lista
	if (current == NULL){
		printf("Nodo no encontrado\n");
		return;
	}
	//ELiminar nodo
	prev->next = current->next;
	free(current);
	printf("Se ha eliminado el elemento %d\n", valor);
}

// Imprimir nodo por su posicion

void posicion(int posicion, struct Node* node){
	int i = 0;
	if (node != NULL){
		for (i = 0; i < posicion; i ++){
			if (node != NULL){
				node = node->next;
			}else{
				printf("No existe valor en la posicion %d\n", posicion);
				return;
			}
		}
		printf("El valor en la posicion %d es: %d\n", posicion, node->data);
	}
}
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
//Insertar nodo al final de la lista
void insertarFinal(int data, struct Node** head) {
        struct Node* nuevo = (struct Node*)malloc(sizeof(struct Node));
        nuevo->data = data;
	nuevo->next = NULL;
        
	if (*head == NULL){
		*head = nuevo;
	} else {
		struct Node* current = *head;
		while (current->next != NULL){
		current = current->next;	
		}
		current->next = nuevo;
	}
        printf("Elemento %d agregado a la lista al final\n", data);
}
//Insertar nodo al principio de la lista (es el mismo que insertar)
void insertarInicio(int data, struct Node** head) {

        struct Node* nuevo = (struct Node*)malloc(sizeof(struct Node));
        nuevo->data = data;
	nuevo->next = (*head);
        (*head) = nuevo;
        printf("Elemento %d agregado a la lista al inicio\n", data);
}

//Insertar a la lista
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
	insertar(90, &head);
	printList(head);
	insertarInicio(11, &head);
	printList(head);
	insertarFinal(12, &head);
	printList(head);
	findList(12, head);
	findList(78, head);
	posicion(0, head);
	posicion(80, head);
	deleteNode(89, &head);
	deleteNode(34, &head);
	printList(head);
	freeList(head);
}
