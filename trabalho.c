#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int temp = 100; //numero temporario ate o professor definir o tamanho da string
typedef struct carrinho{
    //char produtos[temp][50];
    struct produto* produto_escolhido; 
    struct carrinho* next_item; //aponta p proximo item do carrinho
}carrinho;

typedef struct client{
    char cpf[12]; 
    char nome[temp];
    char telefone[20]; // alterei para char
    struct carrinho* meu_carrinho; // aponta pro primeiro item do carrinho dele
    struct client* proximo_cliente; 

}client;

typedef struct produto{
    char codigo[temp]; 
    char nome[temp];
    float preco;
    struct produto* proximo_produto;

}produto;

void Cadastrar_Cliente(client** lista){ 

    client* novo_cliente = malloc(sizeof(client));

    if(novo_cliente == NULL){
        printf("\n\tSem Espaco na Memoria!");
        return;
    }

     novo_cliente->meu_carrinho = NULL;

    printf("Digite o cpf do cliente: ");
    scanf("%s", novo_cliente->cpf);
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", novo_cliente->nome);
    printf("Digite o telefone do cliente: ");
    scanf("%s", novo_cliente->telefone); 

    novo_cliente->proximo_cliente = *lista;
    *lista = novo_cliente;
    
} 

void Listagem_Clientes(client* lista){
    client* aux = lista;

    if(aux == NULL){
        printf("\n\tLista Vazia!\n");
        return;
    }

    printf("\n\t%-15s | %-30s | %-15s", "CPF", "NOME", "TELEFONE");

    while(aux != NULL){
        printf("\n\t%-15s | %-30s | %-15s", aux->cpf, aux->nome, aux->telefone);
        aux = aux->proximo_cliente;
    }
}

int main(){
    int opcao;



    do{
        printf("\n\t1 - Gerenciamento de Clientes");
        printf("\n\t2 - Gerenciamento de Produtos");
        printf("\n\t3 - Compras");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: {
                int opcao_2;
                printf("\n\tCadastro de Clientes");
                printf("\n\tListagem de Clientes");
                printf("\n\tBuscar Cliente");
                printf("\n\t Editar Dados");
                printf("\n\tRemover Cliente");
                scanf("%d", &opcao_2);
            }
        }
    }while(opcao != 0);/*pensei de colocar uma opcao de saida do programa, 
                tipo, quando for 0, o programa encerra*/
}

