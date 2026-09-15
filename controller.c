// "Controller"
#define NUM_DE_ITENS 12
#define MAX_TEXTO 40	

void menu_atualizar(int lin1, int col1, int qtd, char lista[NUM_DE_ITENS][MAX_TEXTO], int opc, int quat[NUM_DE_ITENS]) {
    int tamMaxitem = 0,i;
    for (i = 0; i < qtd; i++) {
        int len = strlen(lista[i]);
        if (len > tamMaxitem) tamMaxitem = len;
    }
    desenhar_menu(lin1, col1, qtd, lista, quat, tamMaxitem);
}

