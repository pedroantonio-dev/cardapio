#ifndef INTERFACE_H
#define INTERFACE_H
#define NUM_DE_ITENS 12
#define MAX_TEXTO 40
#define BOX_PADDING 2

enum Colors {
	BLACK = 0, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
	LIGHTBLUE = 9, DARKGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

void linhaCol(int lin, int col, int hideCursorFlag) {
	COORD coord = {col - 1, lin - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	CONSOLE_CURSOR_INFO info = {100, !hideCursorFlag};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void textColor(int letra, int fundo) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo * 16);
}
void linhaCol(
	int lin, 
	int col, 
	int hideCursorFlag
);
void textColor(
	int letra, 
	int fundo
);
void box(
	int lin1, 
	int col1, 
	int lin2, 
	int col2
);
void desenhar_menu(
	Pedido pedidos[NUM_DE_ITENS], 
	int tamMaxitem, 
	int lin1, 
	int col1, 
	int qtd
);
int  desenhar_quantidade(
	Pedido pedidos, 
	int larguraCaixaQuantidade,
	int lin4, 
	int col1, 
	int col4, 
	int qtd
);
int  desenha_botom(
	int larguraCaixaQuantidade, 
	int lin2,
	int col1, 
	int col4, 
	int hover
);
void hover_opcao(
	Pedido pedidos,
	int linha, 
	int qtc, 
	int opc, 
	int col1
);
void montarMenu(
	Pedido pedidos[NUM_DE_ITENS],  
	int quantidade
);

#endif