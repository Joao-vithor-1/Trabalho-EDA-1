#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int temp = 100; //numero temporario ate o professor definir o tamanho da string
typedef struct carrinho{
    struct produto* produto_escolhido; 
    struct carrinho* next_item; //aponta p proximo item do carrinho
}carrinho;

typedef struct client{
    char cpf[12]; 
    char nome[temp];
    char telefone[20]; 
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

    client* aux = *lista;
    
     novo_cliente->meu_carrinho = NULL;

    printf("\n\tDigite o cpf do cliente: ");
    scanf("%s", novo_cliente->cpf);

    while(aux != NULL){
        if(strcmp(novo_cliente->cpf, aux->cpf) == 0){
            printf("\n\tCPF ja cadastrado!");
            free(novo_cliente);
            return;
        } else {
            aux = aux->proximo_cliente;
        }
    }
    
    printf("\n\tDigite o nome do cliente: ");
    scanf(" %[^\n]", novo_cliente->nome);
    printf("\n\tDigite o telefone do cliente: ");
    scanf("%s", novo_cliente->telefone); 

    novo_cliente->proximo_cliente = *lista;
    *lista = novo_cliente;
    
} 

void Listagem_Clientes_Recursiva(client* lista){
    client* aux = lista;

    if(aux == NULL){
        return;
    }

    while(aux != NULL){
        printf("\n\t%-15s | %-30s | %-15s", aux->cpf, aux->nome, aux->telefone);
        Listagem_Clientes_Recursiva(aux->proximo);
    }
}

void Buscar_Cliente(client* lista){
    char buscado[12];
    printf("\n\tDigite o cpf a ser buscado: ");
    scanf("%s", buscado);

    client* aux = lista;

    while(aux != NULL){
        if(strcmp(buscado, aux->cpf) == 0){
            printf("\n\tCPF encontrado!");
            return;
        } else {
            aux = aux->proximo_cliente;
        }
    }

    if(aux == NULL){
        printf("\n\tCPF nao esta na lista!");
    }

}

int main(){
    int opcao;



    do{
        printf("\n\t1 - Gerenciamento de Clientes");
        printf("\n\t2 - Gerenciamento de Produtos");
        printf("\n\t3 - Compras");
        printf("selecione uma das opções acima: ");
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

