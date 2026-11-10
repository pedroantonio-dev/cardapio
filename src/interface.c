#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void box(int lin1, int col1, int lin2, int col2) {
    int i, j;

    // Canto superior esquerdo
    linhaCol(lin1, col1, 1); printf("%c", 218);
    // Canto superior direito
    linhaCol(lin1, col2, 1); printf("%c", 191);
    // Canto inferior esquerdo
    linhaCol(lin2, col1, 1); printf("%c", 192);
    // Canto inferior direito
    linhaCol(lin2, col2, 1); printf("%c", 217);

    // Linhas horizontais superior e inferior
    for (i = col1 + 1; i < col2; i++) {
        linhaCol(lin1, i, 1); printf("%c", 196);
        linhaCol(lin2, i, 1); printf("%c", 196);
    }

    // Linhas verticais esquerda e direita
    for (i = lin1 + 1; i < lin2; i++) {
        linhaCol(i, col1, 1); printf("%c", 179);
        linhaCol(i, col2, 1); printf("%c", 179);
    }

    // Preenche o interior da caixa
    for (i = lin1 + 1; i < lin2; i++) {
        for (j = col1 + 1; j < col2; j++) {
            linhaCol(i, j, 1); printf(" ");
        }
    }
}

//define e desenha a box do menu, definindo suas dimenss?es e sua cor

void desenhar_menu(Pedido pedidos[NUM_DE_ITENS], int tamMaxitem, int lin1, int col1, int qtd){
    // Ajuste da largura da caixa
    int larguraCaixaItens = tamMaxitem + BOX_PADDING * 2;
    int larguraCaixaQuantidade = 15;  // Largura da caixa de quantidades
    
    // Desenha a caixa superior
    int lin3 = lin1, lin4 = lin3 + 4, col3 = col1, col4 = col1 + larguraCaixaItens;
    int padding = (col4 - col3 - 8) / 2; 
    
    // Desenha a caixa
    text_color;
    setlocale(LC_ALL, "C");
    box(lin3, col3, lin4, col4 +19);
    setlocale(LC_ALL, "");
    linhaCol(lin3 + 2, col3 + padding +10, 1); printf("card?pio");
    int lin2 = lin4 + 1, linha = lin2 + 1;
    setlocale(LC_ALL, "C");
    box(lin2, col1, lin2 + (qtd * 1 + 2), col4); 
    setlocale(LC_ALL, "");
    desenhar_quantidade( pedidos, larguraCaixaQuantidade,lin4, col1, col4, qtd);
    desenha_botom( lin2, col1, col4,  larguraCaixaQuantidade, 0);
    
}

//desenha a quantidade, separada para melhor efici?ncia do projeto, pois quando tem alguma altera??o no movimento � atualizado s� o item da lista do menu, deixando hover

int desenhar_quantidade(Pedido pedidos[NUM_DE_ITENS],int larguraCaixaQuantidade, int lin4, int col1, int col4, int qtd){
    text_color;
    int lin2 = lin4 + 1, linha = lin2 + 1,i;
    setlocale(LC_ALL, "C");
    box(lin2, col4 + 1, lin2 + (qtd * 1 + 2), col4 + larguraCaixaQuantidade + 4);  
    setlocale(LC_ALL, "");
    for ( i = 0; i < qtd; i++) {
        linhaCol(linha, col1 + 2, 1);  
        printf("%-15s", pedidos[i].nome);
        
        linhaCol(linha, col4 + 4, 1);  
        printf("Quantidade: %d", pedidos[i].nome);

        linha++;
    }	
}

//desenha o bot?o com suas dimens?es, e altera a ordem das cores se ele estiver hover ou n?o

int desenha_botom(int larguraCaixaQuantidade, int lin2, int col1, int col4, int hover) {
    int alturaBotao = 2;  
    int lin5 = lin2 + 15;
    int lin6 = lin5 + alturaBotao; 
    int col5 = col1;
    int col6 = col5 + larguraCaixaQuantidade + 42; 
    setlocale(LC_ALL, "C");
    box(lin5, col5, lin6, col6);
    linhaCol(lin5 + 1, col5 + 23, 1);  
    printf("Fazer pedido");
}

void hover_opcao(Pedido pedidos[NUM_DE_ITENS], int linha, int qtd, int opc, int col1){
    int i;
	for ( i = 0; i < qtd; i++) {
        if (i == opc) {
            text_hover;  
        } else {
            text_color;  
        }
        linhaCol(linha + i + 5, col1 + 2, 1);  
        printf("%-15s", pedidos[i].nome); 
    }
}

void montarMenu(Pedido pedidos[NUM_DE_ITENS]){
    int i,j;
	for(i = 0; i < NUM_DE_ITENS; i++)
    {
        int nome_len = strlen(pedidos[i].nome);

        int qtd_pontos = 23 - nome_len;

        char pontos[30];

        for(j = 0; j < qtd_pontos; j++)
        {
            pontos[j] = '.';
        }

        pontos[qtd_pontos] = '\0';

        if(i < 9)
        {
            sprintf(lista[i],
                "0%d_%s%sR$ %d,00",
                i+1,
                pedidos[i].nome,
                pontos,
                pedidos[i].preco
            );
        }
        else
        {
            sprintf(lista[i],
                "%d_%s%sR$ %d,00",
                i+1,
                pedidos[i].nome,
                pontos,
                pedidos[i].preco
            );
        }
    }
}