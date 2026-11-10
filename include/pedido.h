#ifndef PEDIDO_H
#define PEDIDO_H

typedef struct {
    char nome[40];
    int preco;
    int quantidade;
} Pedido;


void atualizarQuantidade(
	Pedido pedidos[NUM_DE_ITENS], 
	int lin1, 
	int col1 , 
	int opc
);

#endif
