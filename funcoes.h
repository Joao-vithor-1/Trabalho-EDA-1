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
void Buscar_Cliente_void(client* lista);
void Editar_Dados_Cliente(client** lista);
void Remover_Cliente(client** lista);

//Gerenciamento de produtos
void Cadastrar_Produto(produto** lista);
void Listagem_Produto_Recursiva(produto* lista);
produto *Buscar_Produto(produto* lista, char* buscado);
void Editar_Dados_Produtos(produto** lista);
void Remover_Produto(produto** lista,client* lista_client);
void Buscar_Produto_void(produto* lista);

//gerenciamento modo compra
void Cadastrar_Produto_Carrinho(carrinho ** lista_carrinho, produto *lista_produto, client *lista_client);
void Adicionar_Produtos_No_Carrinho(client** lista_clientes, produto* lista_produtos);
void Itens_no_Carrinho(client* lista);
void Custo_Total_do_Carrinho(client* lista_de_clientes);
void Remover_do_Carrinho(client** lista_cliente, produto* lista_produtos);
void Remover_do_carrinho_produtos(client* lista_clientes,produto *removido);


//free listas
void Free_produto(produto* lista);
void Free_carrinho(carrinho *lista);
void Free_client(client *lista);



#endif




