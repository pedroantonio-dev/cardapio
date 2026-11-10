#ifndef MENU_H
#define MENU_H

#include "interface.h"

#define NUM_DE_ITENS 12
#define MAX_TEXTO 40

void menu_atualizar(
	Pedido pedidos[NUM_DE_ITENS], 
	int lin1, 
	int col1,  
	int opc
);

#endif
