#include "usuario.h"
#include "produto.h"

void menu_compra(int *VMenu, Cadastro_Usuario *Usuario, Cadastro_Produto *Produto);
void desenha_menu_compra(int menu);
int cancelar_compra(void);
void compra(Cadastro_Usuario *Usuario, Cadastro_Produto *Produto);
void computar_compra(char *codigo, int *Ref, int *Tela, float *Total);
void desenha_finalizar_compra(int Ref);
int finalizar_compra(void);
void historico_compra(void);
void mostra_dado_compra(char *cod);
void pagar_compra(void);
int troco_compra(void);
