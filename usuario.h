#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[51];
    int cpf[11];
    char logradouro[18];
    int numero;
    int complemento;
    char cidade[31];
    char estado[3];
    int cep;
    char telefone[11];
    char codigo[13];
} Cadastro_Usuario;

void apaga_usuario(Cadastro_Usuario *Usuario, int Posicao);
int busca_usuario(void);
int busca_usuario_arquivo(Cadastro_Usuario *busca, char Busca[51], int Ref);
void desenha_busca_escolha_usuario(int Ref);
void desenha_busca_usuario(int Ref);
void cadastro_usuario(Cadastro_Usuario *usu, int *sai);
void criar_codigo(char *str, int *Qt);
void exclusao_usuario(Cadastro_Usuario *Usuario);
void grava_usuario(Cadastro_Usuario *Usuari, int Posicao);
int ler_arquivo_usuario(Cadastro_Usuario *Usuario, int posicao);
void listar_usuario(Cadastro_Usuario *Usuario);
void modificar_usuario(Cadastro_Usuario *Usuario);
