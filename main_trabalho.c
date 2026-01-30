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
        printf("\n\tSelecione uma das opcoes acima: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: {
                int opcao_cliente;
                printf("\n\t1 - Cadastro de Clientes");
                printf("\n\t2 - Listagem de Clientes ");
                printf("\n\t3 - Buscar Cliente");
                printf("\n\t4 - Editar Dados");
                printf("\n\t5 - Remover Cliente");
                printf("\n\tSelecione uma das opcoes acima: ");
                scanf("%d", &opcao_cliente);
                switch(opcao_cliente){
                    case 1: Cadastrar_Cliente(&lista_client); break;
                    case 2: 
                        printf("\n\t%-15s | %-30s | %-15s | %-15s | %-30s", "CPF", "NOME", "TELEFONE", "NASCIMENTO", "EMAIL");
                        Listagem_Clientes_Recursiva(lista_client); 
                        break;
                    case 3: Buscar_Cliente(lista_client); break;
                    case 4 : Editar_Dados_Cliente(&lista_client); break;
                    case 5 : Remover_Cliente(&lista_client); break;
                    default: break;
                }
            case 2:{
                int opcao_produto;
                printf("\n\t1 - Cadastro de Produtos");
                printf("\n\t2 - Listagem dos Produtos");
                printf("\n\t3 - Buscar Produto");
                printf("\n\t4 - Editar Dados");
                printf("\n\t5 - Remover Produto");
                printf("\n\tSelecione uma das opcoes acima: ");
                scanf("%d",&opcao_produto);
                switch(opcao_produto){
                    case 1 : Cadastrar_Produto(&lista_produto); break;
                    case 2 : 
                        printf("\n\t%-30s | %-13s | %-10s | %-10s", "NOME", "PRECO", "CODIGO", "QUANTIDADE");
                        Listagem_Produto_Recursiva(lista_produto); 
                        break;
                    case 3: Buscar_Produto(lista_produto); break;
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





