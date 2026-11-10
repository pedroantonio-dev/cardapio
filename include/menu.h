#ifndef MENU_H
#define MENU_H

void menu_executar(
	Pedido pedidos[NUM_DE_ITENS]
);

void menu_atualizar(
	Pedido pedidos[NUM_DE_ITENS], 
	int lin1, 
	int col1,  
	int opc
);

#endif
