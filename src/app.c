#include <locale.h>

#include "app.h"
#include "pedido.h"
#include "menu.h"
#include "interface.h"
#include "teclado.h"

void app_iniciar(void) {

    setlocale(LC_ALL, "Portuguese");

    // Inicialização dos produtos
    Pedido pedidos[NUM_DE_ITENS] = {
        {"x-infarto", 30, 0},
        {"x-ratao", 26, 0},
        {"x-tudo", 24, 0},
        {"x-quase tudo", 20, 0},
        {"x-bacon egg", 19, 0},
        {"x-bacon", 16, 0},
        {"x-nada", 10, 0},
        {"x-salada", 3, 0},
        {"agua da pia", 3, 0},
        {"Dolly", 7, 0},
        {"guarana jesus", 8, 0}
    };

    // Inicia o menu
    menu_executar(pedidos);
}