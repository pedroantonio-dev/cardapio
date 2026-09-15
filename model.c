// "Model"
#define NUM_DE_ITENS 12
#define MAX_TEXTO 40

void montarMenu(Pedido pedidos[NUM_DE_ITENS], char lista[NUM_DE_ITENS][MAX_TEXTO], int quantidade){
	int i,j;
	for(i = 0; i < quantidade; i++)
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
