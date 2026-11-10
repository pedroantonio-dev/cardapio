#ifndef TECLADO_H
#define TECLADO_H
#define NUM_DE_ITENS 12
#define MAX_TEXTO 40

//nomeia as teclas do teclado
#define CIMA  72
#define BAIXO 80
#define ENTER 13
#define ESC 27
#define ESPECIAL 224

int menu_movimento(
	Pedido pedidos[NUM_DE_ITENS], 
	int lin1, 
	int col1, 
	int qtd, 
	int opc, 
	int sair
);

void mover_quantidade(
	Pedido pedidos[NUM_DE_ITENS],
	int quantidadeNova,
	int opc
);

#endif
