#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    float x[121];
    float quad[121];
    float menor, maior, media, d_padrao, somat;
    int count;
}vetor;

vetor temp()
{
    char arquivo[] = "temperaturaAtual.txt";
    vetor vetor;
    int i = 0;
    FILE *arq;
    arq = fopen(arquivo, "r");
    if(arq == NULL)
    {
        printf("Erro 404");
    }
    else
    {
        while( (fscanf(arq," %f\n", &vetor.x[i])) != EOF)
        {
            i++;
        }
    }
    fclose(arq);
    /*for(i = 0; i < 121; i++)
    {
        printf("\n%.02f", vetor.x[i]);
    }*/
    return vetor;
}

vetor ordenacao()
{
    vetor vetor;
    int i, j, r;
    int tamanho = 121;
    int aux;
    vetor = temp();
    for(i=tamanho-1; i >= 1; i--) 
    {
        for(j=0; j < i ; j++) 
        {
            if(vetor.x[j]>vetor.x[j+1])
            {
                aux = vetor.x[j];
                vetor.x[j] = vetor.x[j+1];
                vetor.x[j+1] = aux;
            }
            
        }
        
    }
    /*for(r = 0; r <= 29; ++r)
    {
        printf("%.02f\n",vetor.x[r]);
        
    }*/
    return vetor;
}

vetor estat()
{
    int i;
    vetor dados;
    dados = ordenacao();
    dados.menor = dados.x[0];
    dados.maior = dados.x[120];
    dados.media = 0;
    dados.count = 0;
    for(i = 0; i < 121; i++)
    {
        dados.media += dados.x[i];
    }
    dados.media = dados.media / 121;
    for(i = 0; i < 121; i++)
    {
        dados.quad[i] = dados.x[i] - dados.media;
    }
    for(i = 0; i < 121; i++)
    {
        dados.somat += pow(dados.quad[i],2);
    }
    dados.somat = dados.somat / 121;
    dados.d_padrao = sqrt(dados.somat);
    for(i = 0; i < 121; i++)
    {
        if( dados.x[i] > dados.media)
        {
            dados.count++;
        }
    }
    return dados;
}

void show_Screen(vetor show)
{
    if(show.menor < 16.2 || show.maior > 45)
    {
        printf("\n\nErro 666 }:)  | Temperatura menor que 16.2 ou maior que 45 graus inserida!");
    }
    else
    {
        printf("\nMenor Temperatura:                         %.02f", show.menor);
        printf("\nMaior Temperatura:                         %.02f", show.maior);
        printf("\nTemperatura media:                         %.02f", show.media);
        printf("\nDesvio Padrao:                             %.02f", show.d_padrao);
        printf("\nNumero de dias acima da temperatura media: %d", show.count);
    }
    printf("\n\n");
}

int main()
{
    vetor func;
    func = estat();
    show_Screen(func);
    return 0;
}