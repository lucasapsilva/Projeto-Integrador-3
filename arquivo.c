#include "arquivo.h"

////////////////////////////////////////////////////////////////////////////////
//                               ABRIR ARQUIVO                                //
////////////////////////////////////////////////////////////////////////////////
// Função    : Abrir os arquivos e contar os usuarios e produtos cadastrados. //
// Parâmetro : Quantidade de usuarios e produtos.                             //
// Retorno   : Nenhum.                                                        //
////////////////////////////////////////////////////////////////////////////////

void abrir_arquivo(int *QtUsu, int *QtPro) {
    // Declaracoes
    Cadastro_Usuario Usuario;
    Cadastro_Produto Produto;
    int Valida;
    int Contador = 0;
    FILE *fusuario, *fproduto, *fcompra;

    // Instrucoes

    //////////////////////////////////////////
    // GOTO reiniciar o arquivo de usuarios //
    //inicio_abrir_arquivo_usuario:         //
    //////////////////////////////////////////

    /* Abrir o arquivo somente leitura */
    fusuario = fopen("usuario.dat", "rb");

    /* Verificar se abriu os arquivos */
    if (fusuario == NULL) {
        printf("Erro ao abrir ou arquivo de usuarios nao encontrado para leitura.\n");
        printf("Deseja criar o arquivo? (1=S/2=N)");
        do {
            Valida = lerInteiro();
            if (Valida == '1')
                fusuario = fopen("usuario.dat", "ab+");
        } while ((Valida != '1') && (Valida != '2')); // Enquanto a tecla S ou N não for apertada
        if (Valida == '2') {
            system("CLS");
            printf("   Tentativa numero %d...\n", Contador + 1);
            Contador++;
            if (Contador == 3) {
                printf("\n   Nao e possivel continuar.\n\n");
                printf("   Pressione qualquer tecla para sair...");
                lerInteiro();
                exit(0);
            }
            //else goto inicio_abrir_arquivo_usuario; // Recarregar os arquivos
        }
    } else {
        if (tamanho_arquivo(fusuario) != 0)
            while (!feof(fusuario)) { // Enquanto não for o fim do arquivo
                if (fread(&Usuario, sizeof (Cadastro_Usuario), 1, fusuario) != 0)
                    (*QtUsu)++;
            }
        if (fclose(fusuario) != 0)
            exit(1);
    }

    Contador = 0;

    //////////////////////////////////////////
    // GOTO reiniciar o arquivo de produtos //
    //inicio_abrir_arquivo_produto: //
    //////////////////////////////////////////

    /* Abrir o arquivo somente leitura */
    fproduto = fopen("produto.dat", "rb");

    if (fproduto == NULL) {
        printf("Erro ao abrir ou arquivo de produtos n%co encontrado para leitura. \n\n");
        printf("Deseja criar o arquivo? (1=S/2=N)");
        do {
            Valida = lerInteiro();
            if (Valida == '1')
                fproduto = fopen("produto.dat", "ab+");
        } while ((Valida != '1') && (Valida != '2')); // Enquanto a tecla S ou N não for apertada
        if (Valida == '2') {
            system("CLS");
            printf("   Tentativa numero %d...\n", Contador + 1);
            Contador++;
            if (Contador == 3) {
                printf("Nao e possivel continuar.\n\n");
                printf("Pressione qualquer tecla para sair...");
                lerInteiro();
                exit(0);
            } //else goto inicio_abrir_arquivo_produto; // Recarregar os arquivos
        }
    } else {
        if (tamanho_arquivo(fproduto) != 0)
            while (!feof(fproduto)) { // Enquanto não for fim do arquivo
                if (fread(&Produto, sizeof (Cadastro_Produto), 1, fproduto) != 0)
                    (*QtPro)++;
            }
        if (fclose(fproduto) != 0)
            exit(1);
    }

    /* Abrir o arquivo somente leitura */
    fcompra = fopen("compra.tmp", "rb");

    /* Verificar se abriu os arquivos */
    if (fcompra != NULL) {
        if (fechar_determinado_arquivo(fcompra) == -1)
            return;
        remove("compra.tmp");
    }
}

////////////////////////////////////////////////////////////////////////////////
//                        ABRIR DETERMINADO ARQUIVO                           //
////////////////////////////////////////////////////////////////////////////////
// Função    : Abrir um determinado arquivo para outra função.                //
// Parametro : Ponteiro do arquivo, referencia de qual arquivo deve ser aberto//
//             e a permissão que o arquivo deve ter.                          //
// Retorno   : 1 para abertura com sucesso e NULL para falha.                 //
////////////////////////////////////////////////////////////////////////////////

FILE *abrir_determinado_arquivo(const char *nome_arquivo, char *Per) {
    // Declarações
    FILE *file;
    int i;

    // Instruções
    file = fopen(nome_arquivo, Per);
    if (file != NULL)
        return file;
    else {
        for (i = 0; i <= 7; i++) {
            printf("  Erro ao abrir o arquivo ou arquivo não encontrado.");
            sleep(300);
        }
        return NULL;
    }
}

////////////////////////////////////////////////////////////////////////////////
//                       FECHAR DETERMINADO ARQUIVO                           //
////////////////////////////////////////////////////////////////////////////////
// Função    : Fechar determinado arquivo e informar se houve algum erro.     //
// Parâmetro : Ponteiro do arquivo.                                           //
// Retorno   : -1 para falha e 1 para sucesso.                                //
////////////////////////////////////////////////////////////////////////////////

int fechar_determinado_arquivo(FILE *file) {
    // Declarações
    int i;

    // Instruções
    if (file != NULL)
        if (fclose(file) == EOF) {
            for (i = 0; i <= 7; i++) {
                printf("  Erro ao fechar o arquivo.");
                sleep(300);
            }
            return -1;
        } else return 1;
}

long tamanho_arquivo(FILE *file){
// Declaracoes
   long int atual, tamanho;

// Instrucoes
   atual = ftell(file); // Posição atual
   fseek(file, 0L, SEEK_END); // fim do arquivo
   tamanho = ftell(file); // Posição do fim que equivale ao tamanho do arquivo
   fseek(file, atual, SEEK_SET); // Colocar na posição inicial
   return tamanho;
}
