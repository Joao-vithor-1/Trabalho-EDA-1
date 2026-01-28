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
    char cpf[12]; //não sei se uso char em vez de  long int, se quiser alterar so trocar na main
    char nome[temp];
    char telefone[20]; // é melhor usar char aqui, não?
    struct carrinho* meu_carrinho; // aponta pro primeiro item do carrinho dele
    struct client* proximo_cliente; 

}client;

typedef struct produto{
    char codigo[temp]; // é melhor usar char aqui, não?
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
    scanf("%ld", &novo_cliente->telefone); //deixei ld pq telefone ta long int

    novo_cliente->proximo_cliente = *lista;
    *lista = novo_cliente;
    
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

