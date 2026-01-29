#include "funcoes.h"
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
        Listagem_Clientes_Recursiva(aux->proximo_cliente); //troquei proximo para proximo_cliente
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

void Editar_Dados(client** lista){
    char buscado[12];
    printf("\n\tDigite o cpf do cliente cujos dados serao edtados: ");
    scanf("%s", buscado);

    client* aux = *lista;
    
    while(aux != NULL && strcmp(buscado, aux->cpf) != 0){
        aux = aux->proximo_cliente;
    }

    if(aux != NULL){
        
        int escolha;
        
        do {
            printf("\n\tQual dado deseja editar?");
            printf("\n\t0 - Sair \n\t1 - Nome \n\t2 - Telefone \n\t3 - CPF");
            printf("\n\topcao: ");
            scanf("%d", &escolha);
            switch (escolha){
                case 1:
                    printf("\n\tDigite o novo Nome: ");
                    scanf("%s", aux->nome);
                    break;
                case 2:
                    printf("\n\tDigite o novo Telefone: ");
                    scanf("%s", aux->telefone);
                    break;
                case 3:
                    printf("\n\tDigite o novo CPF: ");
                    scanf("%s", aux->cpf);
                    break;
                case 0:
                    break;
                default:
                    printf("\n\tValor Invalido!");
                    break;
            }
        }while(escolha != 0);       
    } else {
        printf("\n\tCPF nao cadastrado!");
    }
}
