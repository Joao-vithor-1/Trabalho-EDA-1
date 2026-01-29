#ifndef FUNCOES_H
#define FUNCOES_H
#include "structs.h"
#include <stdio.h>


//Gerenciamento de Clientes

void Cadastrar_Cliente(client** lista);
void Listagem_Clientes_Recursiva(client* lista);
void Buscar_Cliente(client* lista);
void Editar_Dados_Cliente(client** lista);
void Remover_Cliente(client** lista);

//Gerenciamento de produtos
void Cadastrar_Produto(produto** lista);
void Listagem_produto_R(produto* lista);
void Editar_Dados_Produtos(produto** lista);
void Remover_Produto(produto** lista);
void Buscar_produto(produto* lista);

//gerenciamento modo compra



//free listas

#endif


