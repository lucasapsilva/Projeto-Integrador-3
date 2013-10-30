#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[51];
    char codigo[13];
    float peso;
    int estoque;
    float preco;
    int indice;
} Cadastro_Produto;

void apaga_produto(Cadastro_Produto *Produto, int Posicao);
int busca_produto(void);
int busca_produto_arquivo(Cadastro_Produto *busca, char Busca[51], int Ref);
void cadastro_produto(Cadastro_Produto *Produto, int *QtPro);
void desenha_busca_produto(int Ref);
void desenha_busca_escolha_produto(int Ref);
void desenha_cadastro_produto(int Ref);
void desenha_resultado(void);
void estoque_produto(void);
void exclusao_produto(Cadastro_Produto *Produto);
void grava_produto(Cadastro_Produto *Produt, int Posicao);
void ler_arquivo_produto(Cadastro_Produto *Produto, long int posicao);
void listar_produto(Cadastro_Produto *Produtos);
void modificar_produto(Cadastro_Produto *Produto);
void top_5_produto(void);
int valida_codigo_produto(char *Cod);
