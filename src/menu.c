#include <stdio.h>

void menu_atualizar(Pedido pedidos[NUM_DE_ITENS],int lin1, int col1, int opc) {
    int tamMaxitem = 0,i;
    for (i = 0; i < NUM_DE_ITENS; i++) {
        int len = strlen(lista[i]);
        if (len > tamMaxitem) tamMaxitem = len;
    }
    desenhar_menu(lin1, col1, NUM_DE_ITENS, pedidos, tamMaxitem);
}


