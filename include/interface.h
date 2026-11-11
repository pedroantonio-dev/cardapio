#ifndef INTERFACE_H
#define INTERFACE_H

enum Colors {
	BLACK = 0, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
	LIGHTBLUE = 9, DARKGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

#define text_color textColor(RED, YELLOW)
#define text_hover textColor(YELLOW, RED)

void linhaCol(
	int lin, 
	int col, 
	int hideCursorFlag
);
void textColor(
	int letra, 
	int fundo
);

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
	Pedido pedidos[NUM_DE_ITENS]
);

#endif