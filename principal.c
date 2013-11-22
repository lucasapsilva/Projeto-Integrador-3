#include "arquivo.h"

int lerInteiro() {
    char entrada[20];
    int n;
    fgets(entrada,20,stdin);
    n = atoi(entrada);
    return n;
}

void lerString(char *str, int n){
    int pos;
    fgets(str,n,stdin);
    pos = strlen(str);
    str[pos-1]='\n';
}
////////////////////////////////////////////////////////////////////////////////
//                          PROGRAMA PRINCIPAL                                //
////////////////////////////////////////////////////////////////////////////////
// Função    : Inicializar as variaveis principais, abrir os arquivos do pro- //
//             grama para verificar erros e chamar o menu principal.          //
// Parâmetro : nenhum.                                                        //
// Retorno   : nenhum.                                                        //
////////////////////////////////////////////////////////////////////////////////

int main(void){
// Declaracoes
   int Quantidade_Usuario=0, Quantidade_Produto=0;
// Instrucoes
   abrir_arquivo(&Quantidade_Usuario, &Quantidade_Produto);
   menu(&Quantidade_Usuario, &Quantidade_Produto);
}
