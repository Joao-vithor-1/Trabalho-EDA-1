#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int temp = 100; //numero temporario ate o professor definir o tamanho da string
struct carrinho{
    char produtos[temp][50];

};
struct client{
    long int cpf; //não sei se uso char em vez de  long int, se quiser alterar so trocar na main
    char nome[temp];
    long int telefone;
    struct carrinho meu_carrinho;
 };
struct produto{
    long long int codico;
    char nome[temp];
    float preco;

};

