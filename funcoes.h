#ifndef FUNCOES_H
#define FUNCOES_H
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Gerenciamento de Clientes

void Cadastrar_Cliente(client** lista);
void Listagem_Clientes_Recursiva(client* lista);
client *Buscar_Cliente(client* lista, char*buscado);
void Buscar_Cliente(client* lista);
void Editar_Dados_Cliente(client** lista);
void Remover_Cliente(client** lista);

//Gerenciamento de produtos
void Cadastrar_Produto(produto** lista);
void Listagem_Produto_Recursiva(produto* lista);
produto *Buscar_Produto(produto* lista, char* buscado);
void Editar_Dados_Produtos(produto** lista);
void Remover_Produto(produto** lista);
void Buscar_Produto(produto* lista);

//gerenciamento modo compra
void Cadastrar_Produto_Carrinho(carrinho ** lista_carrinho, produto *lista_produto, client *lista_client);
void Adicionar_Produtos_No_Carrinho(client** lista_clientes, produto* lista_produtos);
void Itens_no_Carrinho(client* lista);
void Custo_Total_do_Carrinho(client* lista_de_clientes);


//free listas
void Free_produto(produto* lista);
void Free_client(client *lista);
void Free_carrinho(carrinho *lista);


#endif



