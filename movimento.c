// Movimento
#define NUM_DE_ITENS 12
#define MAX_TEXTO 40

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
    linhaCol(lin1 + opc + 6, col1 + 42, 20);  // Mover para o item espec�fico
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
                if (quantidadeNova > 100) {  // Limite m�ximo de 100
                    quantidadeNova = 99;
                }
            } else if (tecla == BAIXO && quantidadeNova > 0) {  
                quantidadeNova--;
            }
        }
        quat[opc] = quantidadeNova;

        // Redesenha apenas o item alterado
        linhaCol(lin1 + opc + 6, col1 + 42, 20);  // Mover para o item espec�fico
        printf("Quantidade: %d", quantidadeNova); 
    }
}
