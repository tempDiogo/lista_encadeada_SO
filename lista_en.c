#include <stdlib.h>
#include <stdio.h>

typedef struct reg {
	int conteudo;
	struct reg *prox;
} Celula;

typedef struct list {
	Celula *head;
} LinkedList;

Celula *criar_cel(int c) {
	Celula *nova_cel = (Celula *)malloc(sizeof(Celula));

	if (nova_cel != NULL) {
		nova_cel->conteudo = c;
		nova_cel->prox = NULL;
	}

	return nova_cel;
}

void print_celulas(LinkedList *list) {
	Celula *current = list->head;

	printf("\nnumeros digitados: \n");

	while (current != NULL) {

		printf("%d, ", current->conteudo);

		current = current->prox;
	}
}

void delete_celula(LinkedList *list, int valor) {
	Celula *current = list->head;
	Celula *prev = NULL;


	if (current != NULL && current->conteudo == valor) {
		list->head = current->prox;
		free(current);
		return;
	}


	while (current != NULL && current->conteudo != valor) {
		prev = current;
		current = current->prox;
	}


	if (current == NULL) {
		printf("Valor %d nC#o encontrado na lista.\n", valor);
		return;
	}


	prev->prox = current->prox;


	free(current);
	printf("Valor %d removido da lista.\n", valor);
}

int main(void) {

	Celula *head = NULL;

	int c = 0;

	Celula *current_i;

	LinkedList list;

	int x;

	for (int i = 0; i < 3; i++) {




		printf("digite o %d item da lista: ", i+1);

		scanf("%d", &c);

		if (i == 0) {
			head = criar_cel(c);
			current_i = head;
		}
		else {
			current_i->prox = criar_cel(c);
			current_i = current_i->prox;
		}

	}

	list.head = head;

	print_celulas(&list);

	printf("\nDigite o valor para deletar da lista: ");

	scanf("%d", &x);

	delete_celula(&list, x);

	print_celulas(&list);

	return 0;
}
