#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct carrinho{
    struct produto* produto_escolhido; 
    struct carrinho* next_item; 
}carrinho;

typedef struct client{
    char cpf[12]; 
    char nome[50];
    char telefone[20]; 
    struct carrinho* meu_carrinho; 
    struct client* proximo_cliente; 

}client;

typedef struct produto{
    char codigo[50]; 
    char nome[50];
    float preco;
    struct produto* proximo_produto;

}produto;

#endif
