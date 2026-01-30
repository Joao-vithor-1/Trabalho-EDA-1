#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct carrinho{
    struct produto* produto_escolhido; 
    int qtd_comprada;
    struct carrinho* next_item; 
}carrinho;

typedef struct client{
    char cpf[12]; 
    char nome[50];
    char email[50];
    char data_de_nascimento[12];
    char telefone[20]; 
    struct carrinho* meu_carrinho; //aponta pro primeiro item do carrinho
    struct client* proximo_cliente; //aponta pro proximo cliente

}client;

typedef struct produto{
    char codigo[50]; 
    char nome[50];
    float preco;
    int quantidade;
    struct produto* proximo_produto; //aponta pro proximo produto

}produto;

#endif




