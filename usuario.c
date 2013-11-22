#include "usuario.h"
#include "lista.h"

////////////////////////////////////////////////////////////////////////////////
//                                MENU USUARIO                                //
////////////////////////////////////////////////////////////////////////////////
// Função    : Pega a tecla digitada, chama a função para desenhar o menu com //
//             a seleção e chama a função selecionada no menu.                //
// Parametro : Estrutura do usuario e a quantidade de usuarios.               //
// Retorno   : Nenhum.                                                        //
////////////////////////////////////////////////////////////////////////////////

void menu_usuario(int *VMenu, Cadastro_Usuario *Usuario, int *Quantid){
    // Declaracoes
    int menu = 0;
    No * lista;
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
                cadastro_usuario(Usuario, Quantid);
                break;
            case 2://modificar
                //modificar_usuario(Usuario);
                break;
            case 3://excluir
                exclusao_usuario(Usuario);
                break;
            case 4://listar
                percorrer(lista, listar_usuario);
                break;
            case 5:
                break;
            default:
                printf("Opcao Invalida!");
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
//                            CADASTRO USUARIO                                //
////////////////////////////////////////////////////////////////////////////////
// Função    : Cadastrar um novo usuario com NOME, CPF, ENDEREÇO, CIDADE,     //
//             ESTADO, CEP e TELEFONE. Receber do sistema um código para      //
//             definir o usuario.                                             //
// Parâmetro : Estrutura do usuario e a quantidade de usuario.                //
// Retorno   : Em caso de cancelamento retornar nada.                         //
////////////////////////////////////////////////////////////////////////////////

void cadastro_usuario(Cadastro_Usuario *Usua, int *QtUsu){
// Declaracoes
   //char numero[5];
   No *lista;
   int salvar;
// Instrucoes
   /* Lê NOME */
   system("cls");
   printf("Digite o nome completo do cliente.  Max. de 50 caracteres.\n");
   printf("Nome: ");
   lerString(Usua->nome, 50);
   /* Lê CPF */
   printf("\nDigite o CPF do cliente sem pontos e nem traco.\n");
   printf("CPF: ");
   lerString(Usua->cpf, 11);
   /* Lê LOGRADOURO */
   printf("\nDigite a parte inicial do endereco.  Max. de 17 caracteres.\n");
   printf("Logradouro: ");
   lerString(Usua->logradouro, 17);
   /* Lê NUMERO */
   printf("\nDigite o numero do endereco.  Max. de 04 digitos.\n");
   printf("Numero: ");
   Usua->numero = lerInteiro();
   /* Lê COMPLEMENTO */
   printf("\nDigite o complemento do endereco.  Max. de 20 caracteres.\n");
   printf("Complemento: ");
   lerString(Usua->complemento, 20);
   /* Lê CIDADE */
   printf("\nDigite o nome da cidade.  Max. de 30 caracteres.\n");
   printf("Cidade: ");
   lerString(Usua->cidade, 30);
   /* Lê ESTADO */
   printf("\nDigite o estado.  Max. de 02 caracteres.\n");
   printf("Estado: ");
   lerString(Usua->estado, 2);
   /* Lê CEP */
   printf("\nDigite o CEP sem traco.  Max. de 09 caracteres.\n");
   printf("CEP: ");
   Usua->cep == lerInteiro();
   /* Lê TELEFONE */
   printf("\nDigite o telefone.Max. de 11 caracteres.\n");
   printf("Telefone: ");
   lerString(Usua->telefone, 13);
   /* Cria o codigo */
   printf("Verifique o codigo do cliente.\n");
   printf("Codigo do Usuario: ");
   lerString(Usua->codigo, 13);
   /* Pergunta se deseja salvar */
   printf("Deseja concluir cadastro de usuario?");
   printf("Tecle: 1=Sim/2-Nao ");
   salvar = lerInteiro();
   if(salvar == 1){
      inserir(lista,Usua);
      }
   (*QtUsu)++;
}

////////////////////////////////////////////////////////////////////////////////
//                               LISTAR USUARIO                               //
////////////////////////////////////////////////////////////////////////////////
// Função    : Lista todos os usuarios gravados na lista.                     //
// Parâmetro : Estrutura de usuario.                                          //
// Retorno   : N/A                                                            //
////////////////////////////////////////////////////////////////////////////////
void listar_usuario(void *dados){
// Declaracoes
    Cadastro_Usuario *Usuario = (Cadastro_Usuario *)dados;
    printf("\nCodigo: %d", Usuario->codigo);
    printf("\nNome: %s", Usuario->nome);
    printf("\nTelefone: %s", Usuario->telefone);
    printf("\nEndereco: %s %d %d", Usuario->logradouro, Usuario->numero, Usuario->complemento);
}

////////////////////////////////////////////////////////////////////////////////
//                                 GRAVA USUARIO                              //
////////////////////////////////////////////////////////////////////////////////
// Função    : Gravar a estrutura no arquivo. Se a posição for -1 ele grava   //
//             no fim do arquivo, senão substitui a informação na posição     //
//             informada. substituir o arquivo tmp pelo original.             //
// Parâmetro : Estrutura a ser gravada e a posição do arquivo.                //
// Retorno   : N/A                                                            //
////////////////////////////////////////////////////////////////////////////////
void grava_usuario(Cadastro_Usuario *Usuari, int Posicao){
// Declaracao
   Cadastro_Usuario Temp;
   FILE *fusuario,*Tmp;

// Instrucoes
   /* Chama função para abrir arquivo */
   if ((fusuario = abrir_determinado_arquivo("usuario.txt","ab+")) == NULL)
      return;

   /* Se o arquivo estiver vazio somente gravar o dado */
   if (tamanho_arquivo(fusuario) == 0){
      fwrite(Usuari, sizeof(Cadastro_Usuario), 1, fusuario);
      if (fechar_determinado_arquivo(fusuario) == -1)
         return;
      return;
      }

   if (Posicao == -1){ // Se Posicao for -1 gravar o dado
      fwrite(Usuari, sizeof(Cadastro_Usuario), 1, fusuario);
      if (fechar_determinado_arquivo(fusuario) == -1)
         return;
      return;
      }else{
            /*Abrir arquivo temporario*/
            if ((Tmp = abrir_determinado_arquivo("usuario.txt","wb")) == NULL){
               if (fechar_determinado_arquivo(fusuario) == -1)
                  return;
               return;
               }
            rewind(fusuario);
            while (!feof(fusuario)){ // Senão enquanto não for fim do arquivo
                  if (ftell(fusuario) == Posicao){ // Se a posição informada for igual a do arquivo
                     fwrite(Usuari, sizeof(Cadastro_Usuario), 1, Tmp);
                     fread(&Temp, sizeof(Cadastro_Usuario), 1, fusuario);
                     }
                  if (fread(&Temp, sizeof(Cadastro_Usuario), 1, fusuario) != 0) // Se leitura não for igual a zero
                     fwrite(&Temp, sizeof(Cadastro_Usuario), 1, Tmp);
                  }
            }

   /* Fecha os arquivos, se conseguir */
   if (fechar_determinado_arquivo(fusuario) == -1){
      if (fechar_determinado_arquivo(Tmp) == -1)
         return;
      return;
      }

   if (fechar_determinado_arquivo(Tmp) == -1)
      return;

   /* Remove e renomia o arquivo */
   remove("usuario.txt");
   rename("usuario.tmp", "usuario.txt");
}

////////////////////////////////////////////////////////////////////////////////
//                           EXCLUIR USUARIO                                  //
////////////////////////////////////////////////////////////////////////////////
// Função    : Exclui os usuarios do arquivo.                                 //
// Parâmetro : Estrutura de cadastro de usuario.                              //
// Retorno   : N/A                                                            //
////////////////////////////////////////////////////////////////////////////////
void exclusao_usuario(Cadastro_Usuario *Usuario){
// Declaracoes
   int posicao;

// Instrucoes
   posicao = busca_usuario(); // Retorna a posição no arquivo

   /* Verifica se a operaão foi cancelada */
   if (posicao == -1)
      return; // Se cancelar retornar nada

   if (excluir() == -1) // Se excluir for -1 deletar dado
      apaga_usuario(Usuario, posicao);
}

////////////////////////////////////////////////////////////////////////////////
//                                   BUSCA                                    //
////////////////////////////////////////////////////////////////////////////////
// Função    : Pergunta o metodo de busca, chama a função para buscar no      //
//             arquivo.                                                       //
// Parâmetro : N/A                                                            //
// Retorno   : busca_usuario_arquivo                                          //
////////////////////////////////////////////////////////////////////////////////
int busca_usuario(void){
// Declaracoes
   int Ref = 0;
   char Busca[5];
   Cadastro_Usuario Resultado;

// Instrucoes
   while(Ref != 2){
   printf("Metodo de Busca\n");
   printf("1 - Nome\n");
   printf("2 - Codigo\n");
   printf("Escolha o método de busca desejado.");
   Ref = lerInteiro();
   switch(Ref){
       case 1:
           printf("Digite o nome a ser procurado.Max. de 50 caracteres.");
           printf("Nome: ");
           lerString(Busca, 50);
           //busca_usuario_arquivo(&Resultado, Busca, Ref);
           break;
       case 2:
           printf("Digite o código a ser procurado.Max. de 12 dígitos.");
           printf("Codigo: ");
           lerString(Busca, 12);
           //busca_usuario_arquivo(&Resultado, Busca, Ref);
   }
  }
}

////////////////////////////////////////////////////////////////////////////////
//                               APAGA USUARIO                                //
////////////////////////////////////////////////////////////////////////////////
// Função    : Apaga passando todos os dados para um arquivo temporario com   //
//             excessão da posição informada.                                 //
// Parâmetro : Estrutura do usuario e posição                                 //
// Retorno   : N/A                                                            //
////////////////////////////////////////////////////////////////////////////////
void apaga_usuario(Cadastro_Usuario *Usuari, int Posicao){
// Declaracao
   Cadastro_Usuario Temp;
   FILE *fusuario,*Tmp;

// Instrucoes
   /* Chama função para abrir arquivo */
   if ((fusuario = abrir_determinado_arquivo("usuario.txt","rb")) == NULL)
      return;
   /* Abrir arquivo temporario */
   if ((Tmp = abrir_determinado_arquivo("usuario.tmp","wb")) == NULL){
      if (fechar_determinado_arquivo(fusuario) == -1)
         return;
      return;
      }
   while (!feof(fusuario)){ // Senão enquanto não for fim do arquivo
         if (ftell(fusuario) == Posicao) // Se a posição informada for igual a do arquivo
            fread(&Temp, sizeof(Cadastro_Usuario), 1, fusuario);
         if (fread(&Temp, sizeof(Cadastro_Usuario), 1, fusuario) != 0) // Se leitura não for igual a zero
            fwrite(&Temp, sizeof(Cadastro_Usuario), 1, Tmp);
         }
   /* Fecha os arquivos, se conseguir */
   if (fechar_determinado_arquivo(fusuario) == -1){
      if (fechar_determinado_arquivo(Tmp) == -1)
         return;
      return;
      }
   if (fechar_determinado_arquivo(Tmp) == -1)
      return;

   /* Remove e renomia o arquivo */
   remove("usuario.txt");
   rename("usuario.tmp", "usuario.dat");
}

////////////////////////////////////////////////////////////////////////////////
// Objetivo: Perguntar se deseja excluir o dado.                              //
// Entrada : Teclas.                                                          //
// Saida   : 0 para não e -1 pra sim.                                         //
////////////////////////////////////////////////////////////////////////////////
int excluir(void){
// Declaracoes
   int Tecla=0, Excluir=0;

// Instrucoes
   while(Tecla != 2){
   printf("Exclusao\n");
   printf("1 - Sim\n");
   printf("2 - Nao\n");
   printf("Deseja excluir a informação?");
   Tecla = lerInteiro();
   switch(Tecla){
       case 1:
           Excluir --;
           break;
       case 2:
           Excluir ++;
           return 0;
           break;
   }
   }
}




