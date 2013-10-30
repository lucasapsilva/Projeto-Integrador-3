#include "compra.h"

////////////////////////////////////////////////////////////////////////////////
//                                MENU COMPRA                                 //
////////////////////////////////////////////////////////////////////////////////
// Função    : Pega a tecla digitada, chama a função para desenhar o menu com //
//             a seleção e chama a função selecionada no menu.                //
// Parametro : Estrutura do usuario e a estrutura do produto.                 //
// Retorno   : Nenhum.                                                        //
////////////////////////////////////////////////////////////////////////////////

void menu_compra(int *VMenu, Cadastro_Usuario *Usuario, Cadastro_Produto *Produto) {
    // Declaracoes
    int menu = 0;
    // Instrucoes
    while (menu != 3){
    system("cls");
    printf ("\n\t |---------------------------------------------------|");
    printf ("\n\t |----------------- COMPRA - OPCOES -----------------|");
    printf ("\n\t |---------------------------------------------------|");
    printf ("\n\t | 1 | CAIXA - - - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t | 2 | HISTORICO - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t | 3 | VOLTAR - - - - - - - - - - - - - - - - - - - -|");
    printf ("\n\t |---------------------------------------------------|");
    printf ("\n\t | Informe a opcao:   -------------------------------|");

    menu = lerInteiro();
        switch (menu) {
            case 1:
                //compra(Usuario, Produto);
                break;
            case 2:
                //historico_compra();
                break;
            case 3:
                break;
            default:
                printf("Opcao Invalida!");
        }
    }
}
