#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

#define NUM_DE_ITENS 12
#define MAX_TEXTO 40
#define BOX_PADDING 2

//nomeia as teclas do teclado
#define CIMA  72
#define BAIXO 80
#define ENTER 13
#define ESC 27
#define ESPECIAL 224

//abrevia a mudança de cores 
#define text_color textColor(RED, YELLOW)
#define text_hover textColor(YELLOW, RED)

// Chamada
void linhaCol(int lin, int col, int hideCursorFlag);
void textColor(int letra, int fundo);
void box(int lin1, int col1, int lin2, int col2);
void menu_atualizar(int lin1, int col1, int qtd, char lista[][MAX_TEXTO], int opc, int quat[NUM_DE_ITENS]);
int  menu_movimento(int lin1, int col1, int qtd, char lista[][MAX_TEXTO], int opc, int quat[NUM_DE_ITENS], int sair);
void atualizarQuantidade(int lin1, int col1, int qtd, char lista[][MAX_TEXTO], int opc, int quat[NUM_DE_ITENS]);
int  desenhar_quantidade(int lin4, int col1, int col4, int qtd, char lista[][MAX_TEXTO],int quat[NUM_DE_ITENS], int larguraCaixaQuantidade);
int  desenha_botom(int lin2,int col1, int col4, int larguraCaixaQuantidade, int hover);
void hover_opcao(int qtc, int opc, int linha, int col1, char lista[][MAX_TEXTO]);

// Definindo as cores com um enum para clareza
enum Colors {
    BLACK = 0, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHTBLUE = 9, DARKGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

typedef struct{
    char nome[40];
    int preco;
    int quantidade;
} Pedido;

// "View"
	void linhaCol(int lin, int col, int hideCursorFlag) {
	    COORD coord = {col - 1, lin - 1};
	    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	
	    CONSOLE_CURSOR_INFO info = {100, !hideCursorFlag};
	    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	}
	
	void textColor(int letra, int fundo) {
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo * 16);
	}
	
    //define e desenha a box, em que todos os elementos estÃ£o presentes

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

    //define e desenha a box do menu, definindo suas dimenssões e sua cor

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
        linhaCol(lin3 + 2, col3 + padding +10, 1); printf("cardápio");
        int lin2 = lin4 + 1, linha = lin2 + 1;
        setlocale(LC_ALL, "C");
        box(lin2, col1, lin2 + (qtd * 1 + 2), col4); 
        setlocale(LC_ALL, "");
        desenhar_quantidade( lin4, col1, col4, qtd, lista, quat, larguraCaixaQuantidade);
        desenha_botom( lin2, col1, col4,  larguraCaixaQuantidade, 0);
        
    }
    
    //desenha a quantidade, separada para melhor eficiência do projeto, pois quando tem alguma alteração no movimento Ã© atualizado sÃ³ o item da lista do menu, deixando hover

    int desenhar_quantidade(int lin4, int col1, int col4, int qtd, char lista[NUM_DE_ITENS][MAX_TEXTO],int quat[NUM_DE_ITENS], int larguraCaixaQuantidade){
        text_color;
        int lin2 = lin4 + 1, linha = lin2 + 1;
        setlocale(LC_ALL, "C");
        box(lin2, col4 + 1, lin2 + (qtd * 1 + 2), col4 + larguraCaixaQuantidade + 4);  
        setlocale(LC_ALL, "");
        for (int i = 0; i < qtd; i++) {
            linhaCol(linha, col1 + 2, 1);  
            printf("%-15s", lista[i]);
            
            linhaCol(linha, col4 + 4, 1);  
            printf("Quantidade: %d", quat[i]);
    
            linha++;
        }	
    }

    //desenha o botão com suas dimensões, e altera a ordem das cores se ele estiver hover ou não

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
        for (int i = 0; i < qtd; i++) {
            if (i == opc) {
                text_hover;  
            } else {
                text_color;  
            }
            linhaCol(linha + i + 5, col1 + 2, 1);  
            printf("%-15s", lista[i]); 
        }
    }

// "Controller"
	
    void menu_atualizar(int lin1, int col1, int qtd, char lista[NUM_DE_ITENS][MAX_TEXTO], int opc, int quat[NUM_DE_ITENS]) {
        int tamMaxitem = 0;
        for (int i = 0; i < qtd; i++) {
            int len = strlen(lista[i]);
            if (len > tamMaxitem) tamMaxitem = len;
        }
        desenhar_menu(lin1, col1, qtd, lista, quat, tamMaxitem);
    }

// Movimento

    int menu_movimento(int lin1, int col1, int qtd, char lista[NUM_DE_ITENS][MAX_TEXTO], int opc, int quat[NUM_DE_ITENS], int sair) {
        int linha = lin1 + 1;  
        while (1) {
            int hoverBotao = 0;  

            hover_opcao(qtd, opc, linha, col1, lista);

            int tecla = getch();

            switch (tecla){

                case ESC:
                    sair = 0;
                    return sair;
                    break;

                case ENTER:
                    if (opc == qtd+1)return sair = 0;
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

                    if (tecla == BAIXO && opc < qtd) {  
                        opc++;
                    }
                    if (opc == qtd && tecla == BAIXO) {
                        hoverBotao = 1;  
                    }
                    if (opc == qtd) {
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

    void atualizarQuantidade(int lin1, int col1, int qtd, char lista[NUM_DE_ITENS][MAX_TEXTO], int opc, int quat[NUM_DE_ITENS]) {
        printf("\nSeta para cima: aumentar\nSeta para baixo: diminuir\n");
        int quantidadeNova = quat[opc];  

        // Atualiza somente o item selecionado
        linhaCol(lin1 + opc + 6, col1 + 42, 20);  // Mover para o item específico
        printf("Quantidade: %d", quantidadeNova);

        while (1) {
            int tecla;
            tecla = getch();

            if (tecla == ENTER) {  
                quat[opc] = quantidadeNova; 
                return;  

            } else if (tecla == ESPECIAL) { 
                tecla = getch();
                if (tecla == CIMA) {  
                    quantidadeNova++;
                    if (quantidadeNova > 100) {  // Limite máximo de 100
                        quantidadeNova = 99;
                    }
                } else if (tecla == BAIXO && quantidadeNova > 0) {  
                    quantidadeNova--;
                }
            }
            quat[opc] = quantidadeNova;

            // Redesenha apenas o item alterado
            linhaCol(lin1 + opc + 6, col1 + 42, 20);  // Mover para o item específico
            printf("Quantidade: %d", quantidadeNova); 
        }
    }
    
	// "Model"
	
	void montarMenu(Pedido pedidos[NUM_DE_ITENS], char lista[NUM_DE_ITENS][MAX_TEXTO], int quantidade){
	    for(int i = 0; i < quantidade; i++)
	    {
	        int nome_len = strlen(pedidos[i].nome);
	
	        int qtd_pontos = 23 - nome_len;
	
	        char pontos[30];
	
	        for(int j = 0; j < qtd_pontos; j++)
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


int main(void) {
	
    int quat[NUM_DE_ITENS] = {0};
    int opc = 0;
    int sair = 1;
    int lin4 = 9, col1 = 5, col4 = 43;
	int qtd = NUM_DE_ITENS;
	int larguraCaixaQuantidade = 15;
	
	Pedido pedidos[NUM_DE_ITENS] = {
	    {"x-infarto", 30},
	    {"x-ratao", 26}, 
	    {"x-tudo", 24},
	    {"x-quase tudo", 20},
	    {"x-bacon egg", 19},
	    {"x-bacon", 16},
	    {"x-nada", 10},
	    {"x-salada", 3},
	    {"agua da pia", 3},
	    {"Dolly", 7},
	    {"guarana jesus", 8},
	    {"tota tola", 12}
	};
	
    char lista[NUM_DE_ITENS][MAX_TEXTO];
    
    montarMenu(pedidos, lista, NUM_DE_ITENS);

    setlocale(LC_ALL, "");
    menu_atualizar(5, 5, NUM_DE_ITENS, lista, opc, quat);
    while (1) {
    	desenhar_quantidade( lin4, col1, col4, qtd, lista, quat, larguraCaixaQuantidade);
        opc = menu_movimento(5, 5, NUM_DE_ITENS, lista, opc, quat, sair);
        if (opc == 0) break;
        linhaCol(1, 1, 0);
        textColor(WHITE, RED);
        atualizarQuantidade(5, 5, NUM_DE_ITENS, lista, opc, quat);
        textColor(WHITE, BLACK);
    }
    textColor(WHITE, BLACK);
    linhaCol(24, 1, 0);
    return 0;
}
