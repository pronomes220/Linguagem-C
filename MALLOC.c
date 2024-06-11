#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct caixa
{
    int *quantia;
} tipo_caixa;
tipo_caixa blocos;

int main()
{
    tipo_caixa *entrada;

    
int qtdmemoria;
printf("quantos blocos:  ");
scanf("%d", &qtdmemoria);
getchar();
entrada = calloc(qtdmemoria, sizeof(int));
if (entrada == NULL)
{
    printf("erro ao alocar");
    return 1;
}
entrada -> quantia = calloc(qtdmemoria,  sizeof(int));
if (entrada -> quantia == NULL)
{
    printf("erro ao alocar memoria");
    return 1;
}
for (int i = 0; i < qtdmemoria; i++)
{
    printf("preencha os espaços o %d espaço: ", i+1);
    scanf("%d", &entrada->quantia[i]);
}

for (int i = 0; i < qtdmemoria; i++)
{
    printf("valores: %d \n", entrada->quantia[i]);
}
free(entrada);
getch();
return 0;

}

