#include "produto.h"

////////////////////////////////////////////////////////////////////////////////
//                                MENU PRODUTO                                //
////////////////////////////////////////////////////////////////////////////////
// Função    : Pega a tecla digitada, chama a função para desenhar o menu com //
//             a seleção e chama a função selecionada no menu.                //
// Parametro : Estrutura do produto e a quantidade de produtos.               //
// Retorno   : Nenhum.                                                        //
////////////////////////////////////////////////////////////////////////////////

void menu_produto(int *VMenu, Cadastro_Produto *Produto, int *QtPro) {
    // Declaracoes
    int menu = 0;
    // Instrucoes
    while (menu != 7){
    system("cls");
    printf ("\n\t |------------------------------------------------------|");
    printf ("\n\t |------------------ PRODUTO - OPCOES ------------------|");
    printf ("\n\t |------------------------------------------------------|");
    printf ("\n\t | 1 | CADASTRO - - - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t | 2 | MODIFICACAO - - - - - - - - - - - - - - - - - - -|");
    printf ("\n\t | 3 | EXCLUSAO - - - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t | 4 | ESTOQUE - - - - - - - - - - - - - - - - - - - - -|");
    printf ("\n\t | 5 | LISTAR - - - - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t | 6 | TOP 5 - - - - - - - - - - - - - - - - - - - - - -|");
    printf ("\n\t | 7 | VOLTAR - - - - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t |------------------------------------------------------|");
    printf ("\n\t | Informe a opcao:   ----------------------------------|");
    menu = lerInteiro();
        switch (menu) {
            case 1:
                //cadastro_produto(Produto, QtPro);
                break;
            case 2:
                //modificar_produto(Produto);
                break;
            case 3:
                //exclusao_produto(Produto);
                break;
            case 4:
                //estoque_produto();
                break;
            case 5:
                //listar_produto(Produto);
                break;
            case 6:
                //top_5_produto();
                break;
            case 7:
                break;
            default:
                printf("Opcao Invalida!");
        }
    }
}
