#include "funcoes.h"

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
