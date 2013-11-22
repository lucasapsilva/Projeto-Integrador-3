#include <stdio.h>

void abrir_arquivo(int *QtUsu, int *QtPro);
FILE *abrir_determinado_arquivo(const char *nome_arquivo, char *Per);
int fechar_determinado_arquivo(FILE *file);
long tamanho_arquivo(FILE *stream);
