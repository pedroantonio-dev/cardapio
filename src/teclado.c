#include <stdio.h>
#include <conio.h>
#include "teclado.h"

int menu_movimento(Pedido pedidos[NUM_DE_ITENS], int lin1, int col1, int opc, int sair){
    int linha = lin1 + 1;  
    while (1) {
        int hoverBotao = 0;  

        hover_opcao(pedidos, linha, NUM_DE_ITENS, opc, col1);

        int tecla = getch();

        switch (tecla){

            case ESC:
                sair = 0;
                return sair;
                break;

            case ENTER:
                if (opc == NUM_DE_ITENS+1)return sair = 0;
                return opc;
                break;

            case ESPECIAL:
                tecla = getch(); 

                // Seta para cima 

                if (tecla == CIMA && opc > 0) {  
                    opc--;
                    hoverBotao = 0;
                    desenha_botom(lin1 + 5, col1, col1 + 38, 15, 1);
                }

                //seta para baixo 

                if (tecla == BAIXO && opc < NUM_DE_ITENS) {  
                    opc++;
                }
                if (opc == NUM_DE_ITENS && tecla == BAIXO) {
                    hoverBotao = 1;  
                }
                if (opc == NUM_DE_ITENS) {
                    if (hoverBotao==1) {
                        desenha_botom(lin1 + 5, col1, col1 + 38, 15, 0);  
                    } else if(hoverBotao==0){
                        desenha_botom(lin1 + 5, col1, col1 + 38, 15, 1);  
                    }
                }

                break;
        }
    }
}

Pedido * mover_quantidade(Pedido pedidos[NUM_DE_ITENS], int quantidadeNova,int opc){
    while (1) {
        int tecla;
        tecla = getch();

        if (tecla == ENTER) {  
            pedidos[opc].quantidade = quantidadeNova; 
            return pedidos;  

        } else if (tecla == ESPECIAL) { 
            tecla = getch();
            if (tecla == CIMA) {  
                quantidadeNova++;
                if (quantidadeNova > 100) {  // Limite m?ximo de 100
                    quantidadeNova = 99;
                }
            } else if (tecla == BAIXO && quantidadeNova > 0) {  
                quantidadeNova--;
            }
        }
        pedidos[opc].quantidade = quantidadeNova;

        // Redesenha apenas o item alterado
        linhaCol(lin1 + opc + 6, col1 + 42, 20);  // Mover para o item espec?fico
        printf("Quantidade: %d", quantidadeNova); 
    }
}