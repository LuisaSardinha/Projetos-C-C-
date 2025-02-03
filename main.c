#include <stdio.h>

void exibirMenu() {
    printf("\n Seja bem vindo ao mercado Fruta Doce! \n");
    printf("\n Itens disponiveís: \n");
    printf("1. Maçã - R$ 3.50 a unidade\n");
    printf("2. Kiwi - R$ 4.80 a unidade\n");
    printf("3. Laranja - R$ 4.00 a unidade\n");
    printf("4. Uva - R$ 5.00 a caixa\n");
    printf("5. Abacaxi - R$ 6.50 a unidade\n");
    printf("0. Finalizar compras\n");
    printf("Escolha uma fruta de 1 a 5, de acordo com a lista acima ou digite 0 para finalizar e receber o total: ");
}

void calcularTotal(int escolha, int quantidade, float *total, FILE *arquivo) {
    float preco;
    const char *fruta;

    switch (escolha) {
        case 1:
            preco = 3.50;
            fruta = "Maçã";
            break;
        case 2:
            preco = 4.80;
            fruta = "Kiwi";
            break;
        case 3:
            preco = 4.00;
            fruta = "Laranja";
            break;
        case 4:
            preco = 5.00;
            fruta = "Uva";
            break;
        case 5:
            preco = 6.50;
            fruta = "Abacaxi";
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }

    *total += preco * quantidade;
    printf("Você comprou %d unidade(s) de %s e o valor total agora é: R$ %.2f\n", quantidade, fruta, *total);


    fprintf(arquivo, "Fruta: %s, Quantidade: %d, Subtotal: R$ %.2f\n", fruta, quantidade, preco * quantidade);
}

int main() {
    int escolha, quantidade;
    float total = 0.0;

    
    FILE *arquivo = fopen("compras.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        return 1;
    }

    while (1) {
        exibirMenu();  
        scanf("%d", &escolha);  

        if (escolha == 0) {
            break;
        }

        if (escolha >= 1 && escolha <= 5) {
            printf("Digite a quantidade de unidades que deseja comprar: ");
            scanf("%d", &quantidade);

            if (quantidade > 0) {
                calcularTotal(escolha, quantidade, &total, arquivo);
            } else {
                printf("Quantidade inválida! Digite um número maior que 0.\n");
            }
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    
    fprintf(arquivo, "Total das compras: R$ %.2f\n", total);
    fprintf(arquivo, "------------------------------\n");

    
    fclose(arquivo);

    printf("\nTotal das compras: R$ %.2f\n", total);
    printf("Obrigado por comprar no mercado Fruta Doce! Tenha um bom dia e volte sempre!\n");

    return 0;
}

// código feito por Luisa Sardinha e Piter Cavalcanti; turma C