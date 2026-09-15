// "View"
#define NUM_DE_ITENS 12
#define MAX_TEXTO 40
#define BOX_PADDING 2

void linhaCol(int lin, int col, int hideCursorFlag) {
    COORD coord = {col - 1, lin - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    CONSOLE_CURSOR_INFO info = {100, !hideCursorFlag};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void textColor(int letra, int fundo) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo * 16);
}

//define e desenha a box, em que todos os elementos estão presentes

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

//define e desenha a box do menu, definindo suas dimenss�es e sua cor

void desenhar_menu(int lin1, int col1, int qtd, char lista[NUM_DE_ITENS][MAX_TEXTO], int quat[NUM_DE_ITENS], int tamMaxitem){
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
    linhaCol(lin3 + 2, col3 + padding +10, 1); printf("card�pio");
    int lin2 = lin4 + 1, linha = lin2 + 1;
    setlocale(LC_ALL, "C");
    box(lin2, col1, lin2 + (qtd * 1 + 2), col4); 
    setlocale(LC_ALL, "");
    desenhar_quantidade( lin4, col1, col4, qtd, lista, quat, larguraCaixaQuantidade);
    desenha_botom( lin2, col1, col4,  larguraCaixaQuantidade, 0);
    
}

//desenha a quantidade, separada para melhor efici�ncia do projeto, pois quando tem alguma altera��o no movimento é atualizado só o item da lista do menu, deixando hover

int desenhar_quantidade(int lin4, int col1, int col4, int qtd, char lista[NUM_DE_ITENS][MAX_TEXTO],int quat[NUM_DE_ITENS], int larguraCaixaQuantidade){
    text_color;
    int lin2 = lin4 + 1, linha = lin2 + 1,i;
    setlocale(LC_ALL, "C");
    box(lin2, col4 + 1, lin2 + (qtd * 1 + 2), col4 + larguraCaixaQuantidade + 4);  
    setlocale(LC_ALL, "");
    for ( i = 0; i < qtd; i++) {
        linhaCol(linha, col1 + 2, 1);  
        printf("%-15s", lista[i]);
        
        linhaCol(linha, col4 + 4, 1);  
        printf("Quantidade: %d", quat[i]);

        linha++;
    }	
}

//desenha o bot�o com suas dimens�es, e altera a ordem das cores se ele estiver hover ou n�o

int desenha_botom(int lin2, int col1, int col4, int larguraCaixaQuantidade, int hover) {
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

void hover_opcao(int qtd, int opc, int linha, int col1, char lista[NUM_DE_ITENS][MAX_TEXTO]){
    int i;
    for ( i = 0; i < qtd; i++) {
        if (i == opc) {
            text_hover;  
        } else {
            text_color;  
        }
        linhaCol(linha + i + 5, col1 + 2, 1);  
        printf("%-15s", lista[i]); 
    }
}
