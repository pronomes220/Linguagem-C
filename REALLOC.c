#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void realoc(int *vetor[], int qtd)//e necessario abrir colchete para recebr os indiices da main
{
    int qtdprint = qtd;
    printf("informe o novo tamanho do vetor: ");
    scanf("%d", &qtd);
    vetor = realloc(vetor, qtd);
    for (int i = 0; i < qtd ; i++)
    {
        printf("%d\n", vetor[i]); 
    }
    printf("voce tem mais 10 espaços para preencher.");
    
}

int main()
{
    int *vetor;
    int qtdbloco;
    printf("informe o tamanho do bloco de memoria que deseja alocar: ");
    scanf("%d", &qtdbloco);
    

    vetor = calloc(qtdbloco, sizeof(int));
    if (vetor == NULL)
    {
        printf("erro ao alocar memoria");
        return 1;
    }
    else
    {
        printf("MEMORIA ALOCADA COM SUCESSO!\n");
        for (int i = 0; i < qtdbloco; i++)
        {
            printf("informe os valores para o vetor: ");
            scanf("%d", &vetor[i]);
        }
    }
    realoc(vetor, qtdbloco);//para passar um array em formato de ponteiro nao precisa declarar os indices no parametros apenas no da funcao criada para receber
    free(vetor);
    return 0;
}