#include <stdio.h>
#include "pedido.h"

Pedido * atualizarQuantidade(Pedido pedidos[NUM_DE_ITENS], int lin1, int opc) {
    printf("\nSeta para cima: aumentar\nSeta para baixo: diminuir\n");
    int quantidadeNova = pedidos[opc].quantidade;  

    // Atualiza somente o item selecionado
    linhaCol(lin1 + opc + 6, MENU_COLUNA_INICIAL + 42, 20);  // Mover para o item espec?fico
    printf("Quantidade: %d", quantidadeNova);

    pedidos[opc].quantidade = mover_quantidade(quantidadeNova,opc,pedidos);
    return pedidos;
}
