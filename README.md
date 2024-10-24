# lista_encadeada_SO

projeto feito por Diogo Fassina Garcia - RA:10417030

para responder a questão 3 e 6, foi necessário usar um sizeof de uma célula, e já que o meu sistema operacional é de 64 bits, cada célula tinha um tamanho de 16 bytes.

assim é possível calcular o número máximo teórico de células que eu posso ter nessa lista: é só dividir a minha memória total (256 gb) por 16 bytes. O que daria 16 000 000 000 celulas possíveis.

------------------------------------------------------------------------------------------------->
''código: 

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
''

	print_celulas(&list);

	return 0;
}

