#include "Usuario.h"
#include "Produto.h"

////////////////////////////////////////////////////////////////////////////////
//                                    MENU                                    //
////////////////////////////////////////////////////////////////////////////////
// Função    : Mostrar o sub-menu.                                            //
// Parâmetro : O valor do menu a ser mostrado.                                //
// Retorno   : Imagem do sub-menu na tela.                                    //
////////////////////////////////////////////////////////////////////////////////

void menu(int *QtUsu, int *QtPro) {
    // Declaracoes
    int menu = 0;
    Cadastro_Usuario Usuario;
    Cadastro_Produto Produto;
    // Instucoes
    while (menu != 4){
    system("cls");
    printf ("\n\t |---------------------------------------------------|");
    printf ("\n\t |---------------- CAIXA - OPCOES -------------------|");
    printf ("\n\t |---------------------------------------------------|");
    printf ("\n\t | 1 | USUARIO - - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t | 2 | PRODUTO - - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t | 3 | COMPRA - - - - - - - - - - - - - - - - - - - -|");
    printf ("\n\t | 4 | ENCERRA - - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t |---------------------------------------------------|");
    printf ("\n\t | Informe a opcao:   -------------------------------|");
    menu = lerInteiro();
        switch (menu) {
            case 1: /* USUARIOS */
                menu_usuario(&menu, &Usuario, QtUsu);
                break;
            case 2: /* PRODUTOS */
                menu_produto(&menu, &Produto, QtPro);
                break;
            case 3: /* COMPRAR */
                menu_compra(&menu, &Usuario, &Produto);
                break;
            case 4: /* SAIR */
                break;
            default:
                printf("Elemento Invalido!");
        }
    }
}
