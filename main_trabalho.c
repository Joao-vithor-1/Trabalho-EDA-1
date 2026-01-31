#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int opcao;
    client * lista_client = NULL;
    produto *lista_produto = NULL;



    do{
        printf("\n\t1 - Gerenciamento de Clientes");
        printf("\n\t2 - Gerenciamento de Produtos");
        printf("\n\t3 - Compras");
        printf("selecione uma das opcoes acima: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: {
                int opcao_cliente;
                printf("\n\tCadastro de Clientes - 1");
                printf("\n\tListagem de Clientes - 2 ");
                printf("\n\tBuscar Cliente - 3");
                printf("\n\t Editar Dados - 4");
                printf("\n\tRemover Cliente - 5");
                printf("\n\tselecione uma das opcoes acima: ");
                scanf("%d", &opcao_cliente);
                switch(opcao_cliente){
                    case 1: Cadastrar_Cliente(&lista_client); break;
                    case 2: Listagem_Clientes_Recursiva(lista_client); break;
                    case 3: 
                    char *buscado = malloc(12*sizeof(char));
                    printf("\n\tDigite o cpf a ser buscado: ");
                    scanf("%s", buscado);
                    Buscar_Cliente(lista_client,buscado); 
                    free(buscado);
                    break;
                    case 4 : Editar_Dados_Cliente(&lista_client); break;
                    case 5 : Remover_Cliente(&lista_client); break;
                    default: break;
                }
            case 2:{
                int opcao_produto;
                printf("\n\tCadastro de Produtos - 1");
                printf("\n\tListagem dos Produtos - 2 ");
                printf("\n\tBuscar Produto - 3");
                printf("\n\t Editar Dados - 4");
                printf("\n\tRemover Produto - 5");
                printf("\n\tselecione uma das opcoes acima: ");
                scanf("%d",&opcao_produto);
                switch(opcao_produto){
                    case 1 : Cadastrar_Produto(&lista_produto); break;
                    case 2 : Listagem_Produto_Recursiva(lista_produto); break;
                    case 3: 
                    char *buscado = malloc(12*sizeof(char));
                    printf("\n\tCodigo do produto buscado: ");
                    scanf("%s", buscado);
                    Buscar_Produto(lista_produto,buscado); 
                    free(buscado);
                    break;
                    case 4: Editar_Dados_Produtos(&lista_produto); break;
                    case 5: Remover_Produto(&lista_produto); break;
                    default: break;
                }

            }
            }
            
        }
    }while(opcao != 0);/*pensei de colocar uma opcao de saida do programa, 
                tipo, quando for 0, o programa encerra*/
}



