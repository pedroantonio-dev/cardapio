#include <stdio.h>
#include <string.h>
#include "menu.h"

void menu_executar(Pedido pedidos[NUM_DE_ITENS]) {

    int opc = 0;

    while (1) {

        // Navegação do menu

        if (/* usuário pressionou ESC */) {
            return 0;
        }

        if (/* usuário confirmou o pedido */) {
            return 1;
        }
    }
}

void menu_atualizar(Pedido pedidos[NUM_DE_ITENS],int lin1, int opc) {
    int tamMaxitem = 0,i;
    for (i = 0; i < NUM_DE_ITENS; i++) {
        int len = strlen(pedidos[i].nome);
        if (len > tamMaxitem) tamMaxitem = len;
    }
    desenhar_menu(pedidos,tamMaxitem,lin1, NUM_DE_ITENS);
}
