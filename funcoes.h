#ifndef FUNCOES_H
#define FUNCOES_H
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Gerenciamento de Clientes

void Cadastrar_Cliente(client** lista);
void Listagem_Clientes_Recursiva(client* lista);
void Buscar_Cliente(client* lista);
void Editar_Dados_Cliente(client** lista);
void Remover_Cliente(client** lista);

//Gerenciamento de produtos
void Cadastrar_Produto(produto** lista);
void Listagem_Produto_Recursiva(produto* lista);
void Editar_Dados_Produtos(produto** lista);
void Remover_Produto(produto** lista);
void Buscar_Produto(produto* lista);

//gerenciamento modo compra



//free listas

#endif


