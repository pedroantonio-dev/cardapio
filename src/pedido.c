#include <stdio.h>

void atualizarQuantidade(Pedido pedidos[NUM_DE_ITENS], int lin1, int col1 , int opc) {
    printf("\nSeta para cima: aumentar\nSeta para baixo: diminuir\n");
    int quantidadeNova = pedidos[opc].quantidade;  

    // Atualiza somente o item selecionado
    linhaCol(lin1 + opc + 6, col1 + 42, 20);  // Mover para o item espec?fico
    printf("Quantidade: %d", quantidadeNova);

    mover_quantidade(quantidadeNova,opc,pedidos);
}
