#include "funcoes.h"


// Gerenciamento de Clientes

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
    printf("\n\tDigite a data de Nascimento (DD/MM/AAAA): ");
    scanf("%s", novo_cliente->data_de_nascimento);
    printf("\n\tDigite o email: ");
    scanf("%s", novo_cliente->email);

    novo_cliente->proximo_cliente = *lista;
    *lista = novo_cliente;
    
} 

void Listagem_Clientes_Recursiva(client* lista){
    client* aux = lista;

    if(aux == NULL){
        return;
    }

    
    printf("\n\t%-15s | %-30s | %-15s | %-15s | %-30s", aux->cpf, aux->nome, aux->telefone, aux->data_de_nascimento, aux->email);
    Listagem_Clientes_Recursiva(aux->proximo_cliente); 
    
}

client * Buscar_Cliente(client* lista, char *buscado){
    /*
    char buscado[12];
    printf("\n\tDigite o cpf a ser buscado: ");
    scanf("%s", buscado);*/

    client* aux = lista;

    while(aux != NULL){
        if(strcmp(buscado, aux->cpf) == 0){
            printf("\n\tCPF encontrado!");
            return aux;
        } else {
            aux = aux->proximo_cliente;
        }
    }

    if(aux == NULL){
        printf("\n\tCPF nao esta na lista!");
        return NULL;
    }
}

void Editar_Dados_Cliente(client** lista){
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
            printf("\n\t0 - Sair \n\t1 - Nome \n\t2 - Telefone \n\t3 - CPF \n\t4 - Telefone \n\t5 - Email");
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
                case 4:
                    printf("\n\tDigite o novo Telefone: ");
                    scanf("%s", aux->telefone);
                    break;
                case 5:
                    printf("\n\tDigite o novo Email: ");
                    scanf("%s", aux->email);
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

void Remover_Cliente(client** lista){
   client* aux = *lista;
   client* rastro = NULL;
   
   if(aux == NULL){
        printf("\n\tLista Vazia!");
        return;
    }

   char removido[12];
   printf("\n\tDigite o CPF do cliente a ser removido: ");
   scanf("%s", removido);

    if(strcmp(aux->cpf, removido) == 0){
        printf("\n\tCliente Removido!");
        *lista = aux->proximo_cliente;
        free(aux);
        return;
    }

    while(aux !=  NULL && strcmp(aux->cpf, removido) != 0){
        rastro = aux;
        aux = aux->proximo_cliente;
    }
        
    if(strcmp(aux->cpf, removido) == 0 && aux != NULL){
        printf("\n\tCliente Removido!");
        rastro->proximo_cliente = aux->proximo_cliente;
        free(aux);
        return;
    }

    printf("\n\tCliente nao Encontrado!");
    

}
//Gerenciamento de produtos

void Cadastrar_Produto(produto** lista){
    produto* novo_produto = malloc(sizeof(produto));

    if(novo_produto == NULL){
        printf("\n\tSem espaco na memoria!");
        return;
    }

    printf("\n\tNome do produto a ser cadastrado: ");
    scanf(" %[^\n]", novo_produto->nome); 

    printf("\n\tCodigo do produto a ser cadastrado: ");
    scanf("%s", novo_produto->codigo);
    
    produto* aux = *lista;

    while(aux != NULL){
        if(strcmp(aux->codigo, novo_produto->codigo) == 0 || strcmp(aux->nome, novo_produto->nome) == 0){
            printf("\n\tProduto ja Cadastrado!");
            free(novo_produto);
            return;
            
        } else {
            aux = aux->proximo_produto;
        }
    }
    printf("\n\tQuantidade do produto a ser cadastrada: ");
    scanf("%d",&novo_produto->quantidade);

    

    aux = *lista;

    while(aux != NULL){
        if(strcmp(aux->nome, novo_produto->nome) == 0 || strcmp(aux->codigo, novo_produto->codigo) == 0){
            printf("\n\tProduto ja cadastrado!");
            free(novo_produto);
            return;
        } else {
            aux = aux->proximo_produto;
        }
    }
    printf("\n\tPreco do produto (em reais): ");
    scanf("%f", &novo_produto->preco);

    novo_produto->proximo_produto = *lista;
    *lista = novo_produto;
}

void Listagem_Produto_Recursiva(produto* lista){
    produto* aux = lista;

    if(aux == NULL) return;

    printf("\n\t%-30s | %-10.2f R$ | %-10s | %-10d", aux->nome, aux->preco, aux->codigo, aux->quantidade);
    Listagem_Produto_Recursiva(aux->proximo_produto);
}

produto *Buscar_Produto(produto* lista, char* buscado){
    produto* aux = lista;

    if(aux == NULL){
        printf("\n\tLista vazia!");
        return NULL;
    }

    /*char buscado[11];

    printf("\n\tCodigo do produto buscado: ");
    scanf("%s", buscado);*/

    while(aux != NULL){
        if(strcmp(buscado, aux->codigo) == 0){
            printf("\n\tProduto encontrado!");
            return aux;

        } else {
            aux = aux->proximo_produto;
        }
    }

    printf("\n\tCodigo nao cadastrado!");
}

void Editar_Dados_Produtos(produto** lista){
  char buscado[11];
  printf("\n\tCodigo do produto a ser editado: ");
  scanf("%s", buscado);

  produto* aux = *lista;

  while(aux != NULL && strcmp(aux->codigo, buscado) != 0){
        aux = aux->proximo_produto;
    }

    int escolha;

    if(aux != NULL){
        do{
            printf("\n\t0 - Sair \n\t1 - Nome \n\t2 - Preco \n\t3 - Codigo \n\t4 - Quantidade \n\tOpcao: ");
            scanf("%d", &escolha);
            switch(escolha){
                case 0:
                    break;
                case 1:
                    printf("\n\tNovo nome: ");
                    scanf("%s", aux->nome);
                    break;
                case 2:
                    printf("\n\tNovo preco: ");
                    scanf("%f", &aux->preco);
                    break;
                case 3:
                    printf("\n\tNovo codigo: ");
                    scanf("%s", aux->codigo);
                    break;
                case 4:
                    printf("\n\tNova quantidade");
                    scanf("%d",&aux->quantidade);
                    break;

                default:
                    printf("\n\tOpcao Invalida!");
                    break;
            }
        }while(escolha != 0);
    } else {
        printf("\n\tCodigo Nao Cadastrado");
    }             
}

void Remover_Produto(produto** lista){
    produto* aux = *lista;

    if(aux == NULL){
        printf("\n\tA lista esta vazia!");
        return;
    }

    char removido[11];
    printf("Digite o codigo do produto a ser removido: ");
    scanf("%s", removido);

    if(strcmp(aux->codigo, removido) == 0){ /*primeiro da fila é quem vai ser removido*/
        printf("\n\tProduto Removido!");
        *lista = aux->proximo_produto;
        free(aux);
        return;
    }

    produto* rastro = NULL;

    while(aux != NULL && strcmp(aux->codigo, removido) != 0){ //percorre a lista ate achar quem vai ser removido
        rastro = aux;                                            //ou dar NULL
        aux = aux->proximo_produto;
    } 

    if(aux != NULL && strcmp(aux->codigo, removido) == 0){
        printf("\n\tProduto Removido!");
        rastro->proximo_produto = aux->proximo_produto;
        free(aux);
        return;
    }
    printf("\n\tProduto nao Cadastrado!");    
}
void Cadastrar_Produto_Carrinho(carrinho  **lista_carrinho, produto *lista_produto, client * lista_client){
    carrinho *novo_carrinho = malloc(sizeof(carrinho));
    char *codico = malloc(50*sizeof(char));
    printf("\n\tselecione um produto dos  listados abaixo: ");
    Listagem_Produto_Recursiva(lista_produto);
    scanf("%s", codico);

    novo_carrinho ->produto_escolhido = Buscar_Produto(lista_produto,codico);
    free(codico);
    if(novo_carrinho->produto_escolhido ==NULL){
        printf("Produto escolhido não existe");
        free(novo_carrinho);
        return;
    }
    char *cpf = malloc(50*sizeof(char));
    printf("\nEscolha um Cliente: ");
    scanf("%s",cpf);
    client *aux = Buscar_Cliente(lista_client,cpf);
    //chegaem se o cpf existe e se o head existe tambem
    free(cpf);
    if(aux!=NULL){
        if(aux->meu_carrinho==NULL) aux->meu_carrinho = novo_carrinho;
    }
    else{
        return;
    }
    novo_carrinho ->next_item = *lista_carrinho;
    *lista_carrinho = novo_carrinho;


    





}







