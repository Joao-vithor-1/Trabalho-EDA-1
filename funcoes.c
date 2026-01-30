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

void Buscar_Cliente(client* lista){

    printf("\n\t%-15s | %-30s | %-15s | %-15s | %-30s", "CPF", "NOME", "TELEFONE", "NASCIMENTO", "EMAIL");
    Listagem_Clientes_Recursiva(lista);

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
        printf("\n\tCPF nao esta na lista!\n");
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
    char *cpf = malloc(20*sizeof(char));
    printf("\nEscolha um Cliente: ");
    Listagem_Clientes_Recursiva(lista_client);
    scanf("%s",cpf);

    client *aux = Buscar_Cliente(lista_client,cpf);
    //verificar se o cpf existe e se o head existe tambem
    free(cpf);
    if(aux!=NULL){
        if(aux->meu_carrinho==NULL) aux->meu_carrinho = novo_carrinho;
    }
    else{
        free(novo_carrinho);
        return;
    }
    novo_carrinho ->next_item = *lista_carrinho;
    *lista_carrinho = novo_carrinho;
}

void Adicionar_Produtos_No_Carrinho(client** lista_clientes, produto* lista_produtos){client* aux_cliente = *lista_clientes;
    char cpf_cliente[12];

    printf("\n\t%-15s | %-30s | %-15s | %-15s | %-30s", "CPF", "NOME", "TELEFONE", "NASCIMENTO", "EMAIL");

    Listagem_Clientes_Recursiva(aux_cliente);

    printf("\n\tCPF do cliente para fazer a compra: ");
    scanf("%s", cpf_cliente);

    while (aux_cliente != NULL && strcmp(cpf_cliente, aux_cliente->cpf) != 0){
        aux_cliente = aux_cliente->proximo_cliente;
    }

    if(aux_cliente == NULL){
        printf("\n\tCPF nao cadatrado!");
        return;
    }

    produto* aux_produto = lista_produtos;

    printf("\n\t%-30s | %-13s | %-10s | %-10s", "NOME", "PRECO", "CODIGO", "QUANTIDADE");

    Listagem_Produto_Recursiva(lista_produtos);

    char codigo_do_novo_produto[11];
    printf("\n\tCodigo do produto a ser colocado no Carrinho: ");
    scanf("%s", codigo_do_novo_produto);

    while(aux_produto != NULL && strcmp(codigo_do_novo_produto, aux_produto->codigo) != 0){
        aux_produto = aux_produto->proximo_produto;
    }

    if(aux_produto == NULL){
        printf("\n\tProduto Nao Encontrado!\n");
        return;
    }

    
    int quantidade_adicionadas;
    printf("\n\tQuantidade de %s serao colocados? (Max: %d)", aux_produto->nome, aux_produto->quantidade);
    printf("\n\tQtd: ");
    scanf("%d", &quantidade_adicionadas);

    int maximo = aux_produto->quantidade;

    aux_produto->quantidade = maximo - quantidade_adicionadas;

    if(aux_produto->quantidade < 0){
        printf("\n\tNao foi possivel adicionar ao carrinho!");
        printf("\n\tExcedeu o limite do produto!");

        aux_produto->quantidade = maximo;

        return;
    }
    
    carrinho* novo_item_do_carrinho = malloc(sizeof(carrinho));

    novo_item_do_carrinho->qtd_comprada = quantidade_adicionadas; // coloca no carrinho numero x do item

    novo_item_do_carrinho->produto_escolhido = aux_produto; // o item adicionado é o produto identificado pelo codigo

    novo_item_do_carrinho->next_item = aux_cliente->meu_carrinho; //aponta para o meu ultimo item adicionado

    aux_cliente->meu_carrinho = novo_item_do_carrinho; // o novo topo da lista é o item adicionado

}

void Itens_no_Carrinho(client* lista){

    Listagem_Clientes_Recursiva(lista);

    client* aux = lista;

    if(aux == NULL){
        printf("\n\tSem Clientes Cadastrados!\n");
        return;
    }

    char dono_do_carrinho[12];
    printf("\n\tCPF do cliente que deseja ver o carrinho: ");
    scanf("%s", dono_do_carrinho);

    while(aux != NULL && strcmp(dono_do_carrinho, aux->cpf) != 0) aux = aux->proximo_cliente;

    if(aux == NULL){
        printf("\n\tCPF nao cadastrado!\n");
        return;
    }

    carrinho* auxiliar_carro = aux->meu_carrinho; //evita que o carrinho original que seja alterado

    if(auxiliar_carro == NULL){
        printf("\n\tSem Itens no carrinho!\n");
        return;
    }

    char produto_nome[50];

    int p = 0;

    while(auxiliar_carro->produto_escolhido->nome[p] != '\0'){
        produto_nome[p] = auxiliar_carro->produto_escolhido->nome[p];
        p++;
    }

    p = 0;

    char produto_codigo[11];

    while(auxiliar_carro->produto_escolhido->codigo[p] != '\0'){
        produto_codigo[p] = auxiliar_carro->produto_escolhido->codigo[p];
        p++;
    }

    float produto_preco = auxiliar_carro->produto_escolhido->preco;    

    int produto_quantidade = auxiliar_carro->qtd_comprada;

    while(auxiliar_carro != NULL){
        printf("\n\t%-40s | %-12s | %-12s | %-11s", "NOME", "PRECO", "CODIGO", "QUANTIDADE");
        printf("\n\t%-40s | %-10.2f R$| %-12s | %-11d\n", produto_nome, produto_preco, 
            produto_codigo, produto_quantidade);
        auxiliar_carro = auxiliar_carro->next_item;
    }
}


void Custo_Total_do_Carrinho(client* lista_de_clientes){
    printf("\n\t%-15s | %-30s | %-15s | %-15s | %-30s", "CPF", "NOME", "TELEFONE", "NASCIMENTO", "EMAIL");
    Listagem_Clientes_Recursiva(lista_de_clientes);

    char cpf_correto[12];
    printf("\n\tCPF do carrinho do cliente: ");
    scanf("%s", cpf_correto);

    client* achador_de_pessoa = lista_de_clientes;

    while(achador_de_pessoa != NULL && strcmp(achador_de_pessoa->cpf, cpf_correto) != 0){
        achador_de_pessoa = achador_de_pessoa->proximo_cliente;
    }

    if(achador_de_pessoa == NULL){ // ve se o cpf foi cadastrado
        printf("\n\tCPF nao cadastrado!\n"); 
        return;
    }

    carrinho* auxiliar_de_conta = achador_de_pessoa->meu_carrinho;

    if(auxiliar_de_conta == NULL) { //checa se o carrinho ta vazio
        printf("\n\tCarrinho Vazio!\n");
        return;
    }

    float total_a_pagar = 0;

    while(auxiliar_de_conta != NULL){
        total_a_pagar+= auxiliar_de_conta->produto_escolhido->preco * auxiliar_de_conta->qtd_comprada; // total a pagar é o preço * qntd
        auxiliar_de_conta = auxiliar_de_conta->next_item; // passa para o novo item do carrinho
    }

    printf("\n\tO preco total a ser paho eh: %.2f R$\n", total_a_pagar);


//free


void Free_produto(produto* lista){
    produto *aux;
    while(lista!=NULL){
        aux = lista;
        lista = lista->proximo_produto;
        free(aux);
    }
}
void Free_client(client *lista){
    client *aux;
    while(lista!=NULL){
        aux = lista;
        Free_carrinho(aux->meu_carrinho);
        lista = lista->proximo_cliente;
        free(aux);

    }

}
void Free_carrinho(carrinho *lista){
    carrinho *aux;
    while(lista!=NULL){
        aux = lista;
        lista = lista->next_item;
        free(aux);
        
    }

}













