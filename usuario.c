#include "Usuario.h"

////////////////////////////////////////////////////////////////////////////////
//                                MENU USUARIO                                //
////////////////////////////////////////////////////////////////////////////////
// Função    : Pega a tecla digitada, chama a função para desenhar o menu com //
//             a seleção e chama a função selecionada no menu.                //
// Parametro : Estrutura do usuario e a quantidade de usuarios.               //
// Retorno   : Nenhum.                                                        //
////////////////////////////////////////////////////////////////////////////////

void menu_usuario(int *VMenu, Cadastro_Usuario *Usuario, int *Quantid) {
    // Declaracoes
    int menu = 0;
    // Instrucoes
    while (menu != 5){
    system("cls");
    printf ("\n\t |------------------------------------------------------|");
    printf ("\n\t |------------------ USUARIO - OPCOES ------------------|");
    printf ("\n\t |------------------------------------------------------|");
    printf ("\n\t | 1 | CADASTRO - - - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t | 2 | MODIFICACAO - - - - - - - - - - - - - - - - - - -|");
    printf ("\n\t | 3 | EXCLUSAO - - - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t | 4 | LISTAR - - - - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t | 5 | VOLTAR - - - - - - - - - - - - - - - - - - - - - |");
    printf ("\n\t |------------------------------------------------------|");
    printf ("\n\t | Informe a opcao:   ----------------------------------|");
    menu = lerInteiro();
        switch (menu) {
            case 1: //cadastro
                //cadastro_usuario(Usuario, Quantid);
                break;
            case 2://modificar
                //modificar_usuario(Usuario);
                break;
            case 3://excluir
                //exclusao_usuario(Usuario);
                break;
            case 4://listar
                //listar_usuario(Usuario);
                break;
            case 5:
                break;
            default:
                printf("Opcao Invalida!");
        }
    }
}
