/***************************************************************/
/**                                                           **/
/**   Gabriel Lujan Bonassi          11256816                 **/
/**   Exercício-Programa 03                                   **/
/**   Professor: Alair Pereira do Lago                        **/
/**   Turma: 01                                               **/
/**                                                           **/
/***************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MMAX 90
#define NMAX 90

int linhas, colunas, minas, semente;
char tabuleirominas[MMAX][NMAX], tabuleirojogo[MMAX][NMAX];

void tabuleiro_de_minas()
{
    int m, n, i, j, c1, numero;
    for(m = 0; m < linhas; m++){
        for(n = 0; n < colunas; n++){
            tabuleirominas[m][n] = '.';
        }
    }

    srand(semente);
    for (c1 = 0; c1 < minas; c1++)
    {
        numero = rand();
        i = numero % (linhas - 2 ) + 1;
        j = (numero / (colunas - 2)) % (linhas - 2) + 1;
        if (tabuleirominas[i][j] != '@')
        {
            tabuleirominas[i][j] = '@';
        }
        else
        {
            c1 = c1 - 1;
        }
    }
}
void tabuleiro_de_jogo()
{
    int m, n;
    for(m = 0; m < linhas; m++){
        for(n = 0; n < colunas; n++){
            tabuleirojogo[m][n] = '.';
        }
    }
}
void imprimir_tabuleiro()
{
    int m, n, i, j;
    printf("      ");
    for(i = 1; i <= colunas - 2; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");
    for(m = 1; m <= linhas - 2; m++)
    {
        j = m;
        printf("%d  ", j);
        for(n = 0; n <= colunas - 1; n++)
        {
            if (n == 0 || n == colunas - 1)
            {
                printf("|  ");
            }
            else
            {
                printf("%c  ", tabuleirojogo[m][n]);
            }
        }
        printf("%d  ", j);
        printf("\n");
    }
    printf("      ");
    for(i = 1; i <= colunas - 2; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");
}
void imprimir_tabuleiro_de_minas()
{
    int m, n, i, j;
    printf("      ");
    for(i = 1; i <= colunas - 2; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");
    for(m = 1; m <= linhas - 2; m++)
    {
        j = m;
        printf("%d  ", j);
        for(n = 0; n <= colunas - 1; n++)
        {
            if (n == 0 || n == colunas - 1)
            {
                printf("|  ");
            }
            else
            {
                printf("%c  ", tabuleirominas[m][n]);
            }
        }
        printf("%d  ", j);
        printf("\n");
    }
    printf("      ");
    for(i = 1; i <= colunas - 2; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");
}
int achar_minas_adjacentes(int poslinha, int poscoluna)
{
    int minas1 = 0;

    if(tabuleirominas[poslinha - 1][poscoluna] == '@')
        {
            minas1++;
        }
    if(tabuleirominas[poslinha + 1][poscoluna] == '@')
        {
            minas1++;
        }
    if(tabuleirominas[poslinha][poscoluna - 1] == '@')
        {
            minas1++;
        }
    if(tabuleirominas[poslinha][poscoluna + 1] == '@')
        {
            minas1++;
        }
    if(tabuleirominas[poslinha - 1][poscoluna + 1] == '@')
        {
            minas1++;
        }
    if(tabuleirominas[poslinha - 1][poscoluna - 1] == '@')
        {
            minas1++;
        }
    if(tabuleirominas[poslinha + 1][poscoluna + 1] == '@')
        {
            minas1++;
        }
    if(tabuleirominas[poslinha + 1][poscoluna - 1] == '@')
        {
            minas1++;
        }

    return minas1;
}
void abre_casas_adjacentes(int poslinha, int poscoluna)
{
    int minasproximas = 0;
    int k = 0;

        minasproximas = achar_minas_adjacentes(poslinha, poscoluna);
        tabuleirojogo[poslinha][poscoluna] = (char)(((int)'0') + minasproximas);

        minasproximas = 0;
        while(minasproximas < 1 && k < poslinha)
        {
            minasproximas = achar_minas_adjacentes(poslinha - k, poscoluna);
            tabuleirojogo[poslinha - k][poscoluna] = (char)(((int)'0') + minasproximas);
            k++;
        }
        k = 0;
        minasproximas = 0;
        while(minasproximas < 1 && poslinha + k < linhas - 2)
        {
            minasproximas = achar_minas_adjacentes(poslinha + k, poscoluna);
            tabuleirojogo[poslinha + k][poscoluna] = (char)(((int)'0') + minasproximas);
            k++;
        }
        k = 0;
        minasproximas = 0;
        while(minasproximas < 1 && k < poscoluna)
        {
            minasproximas = achar_minas_adjacentes(poslinha, poscoluna - k);
            tabuleirojogo[poslinha][poscoluna - k] = (char)(((int)'0') + minasproximas);
            k++;
        }
        k = 0;
        minasproximas = 0;
        while(minasproximas < 1 && poscoluna + k < colunas - 2)
        {
            minasproximas = achar_minas_adjacentes(poslinha, poscoluna + k);
            tabuleirojogo[poslinha][poscoluna + k] = (char)(((int)'0') + minasproximas);
            k++;
        }
        k = 0;
        minasproximas = 0;
        while(minasproximas < 1 && poscoluna + k < colunas - 2 && k < poslinha)
        {
            minasproximas = achar_minas_adjacentes(poslinha - k, poscoluna + k);
            tabuleirojogo[poslinha + k][poscoluna + k] = (char)(((int)'0') + minasproximas);
            k++;
        }
        k = 0;
        minasproximas = 0;
        while(minasproximas < 1 && k < poslinha && k < poslinha && k < poscoluna)
        {
            minasproximas = achar_minas_adjacentes(poslinha - k, poscoluna - k);
            tabuleirojogo[poslinha - k][poscoluna - k] = (char)(((int)'0') + minasproximas);
            k++;
        }
        k = 0;
        minasproximas = 0;
        while(minasproximas < 1 && poslinha + k < linhas - 2 && poscoluna + k < colunas - 2)
        {
            minasproximas = achar_minas_adjacentes(poslinha + k, poscoluna + k);
            tabuleirojogo[poslinha + k][poscoluna + k] = (char)(((int)'0') + minasproximas);
            k++;
        }
        k = 0;
        minasproximas = 0;
        while(minasproximas < 1 && poslinha + k < linhas - 2 && k < poscoluna)
        {
            minasproximas = achar_minas_adjacentes(poslinha + k, poscoluna - k);
            tabuleirojogo[poslinha + k][poscoluna - k] = (char)(((int)'0') + minasproximas);
            k++;
        }
}
int ja_ganhou ()
{
    int c2, c3;
        for(c2 = 1; c2 < linhas - 1; c2++)
        {
            for(c3 = 1; c3 < colunas - 1; c3++)
            {
                if(tabuleirojogo[c2][c3] == '.' && tabuleirominas[c2][c3] != '@')
                {
                    return 1;
                }
            }
        }
        return 0;
}

int main()
{
    int MINASMAX, linhapalpite, colunapalpite, derrota;
    char letra;
    /* Inicio da leitura das linhas */
    printf("De o numero de linhas do tabuleiro do jogo:");
    scanf("%d", &linhas);
    if (linhas >= 3 && linhas <= MMAX)
    {
        linhas = linhas;
    }
    else
    {
        while (linhas < 3 || linhas > MMAX)
        {
            printf("O numero de linhas esta fora do intervalo permitido. O intervalo permitido e (3 <= m <= 90) \n");
            printf("De o numero de linhas do tabuleiro do jogo:");
            scanf("%d", &linhas);
        }
    }
    linhas = linhas + 2;
    /* Fim da leitura das linhas */

    /* Inicio da leitura das colunas */
    printf("De o numero de colunas do tabuleiro do jogo:");
    scanf("%d", &colunas);
    if (colunas >= 3 && colunas <= MMAX)
    {
        colunas = colunas;
    }
    else
    {
        while (colunas < 3 || colunas > MMAX)
        {
            printf("O numero de colunas esta fora do intervalo permitido. O intervalo permitido e (3 <= n <= 90) \n");
            printf("De o numero de colunas do tabuleiro do jogo:");
            scanf("%d", &colunas);
        }
    }
    colunas = colunas + 2;
    /* Fim da leitura das colunas */
    /* Inicio da leitura das minas */
    printf("De o numero de minas:");
    scanf("%d", &minas);
    MINASMAX = (linhas * colunas) - 1;
    if (minas >= 1 && minas <= MINASMAX)
    {
        minas = minas;
    }
    else
    {
        while (minas < 1 || minas > MINASMAX)
        {
            printf("O numero de minas esta fora do intervalo permitido. O intervalo permitido e (1 <= z <= %d) \n", MINASMAX);
            printf("De o numero de minas do tabuleiro do jogo:");
            scanf("%d", &minas);
        }
    }
    /* Fim da leitura das minas */
    /* Inicio da leitura da semente */
    printf("De a semente:");
    scanf("%d", &semente);
    if (semente >= 1 && semente <= 12345)
    {
        semente = semente;
    }
    else
    {
        while (semente < 1 || semente > 12345)
        {
            printf("O numero da semente esta fora do intervalo permitido. O intervalo permitido e (1 <= s <= 12345) \n");
            printf("De a semente:");
            scanf("%d", &semente);
        }
    }
    /* Fim da leitura da semente */
    printf("Numero de linhas (3 <= m <= 90): %d \n", linhas - 2);
    printf("Numero de colunas (3 <= n <= 90): %d \n", colunas - 2);
    printf("Numero de minas (1 <= z <= %d): %d \n", MINASMAX, minas);
    printf("Semente (1 <= s <= 12345): %d \n", semente);
    printf("Bem vindo ao Caca-Minas! \n");
    tabuleiro_de_minas();
    tabuleiro_de_jogo();
    imprimir_tabuleiro();
    derrota = 2;
    while (derrota != 1)
    {
        printf("Proximo chute:");
        scanf("%c %d %d", &letra, &linhapalpite, &colunapalpite);
        printf("\n");
        if (letra == 'a'){

            if (tabuleirominas[linhapalpite][colunapalpite] == '@')
            {
                printf("BOOOOM! Voce acaba de pisar numa mina!");
                printf("\n");
                imprimir_tabuleiro_de_minas();
                derrota = 1;
            }
            else
            {
                abre_casas_adjacentes(linhapalpite, colunapalpite);
                imprimir_tabuleiro();
            }
        }
        if (letra == 'm')
        {
            if (tabuleirojogo[linhapalpite][colunapalpite] == '.')
            {
                tabuleirojogo[linhapalpite][colunapalpite] = '*';
                imprimir_tabuleiro();
            }
            else
            {
                printf("Sem Efeito");
                printf("\n");
            }
        }
        if (letra == 'd')
        {
            if (tabuleirojogo[linhapalpite][colunapalpite] == '*')
            {
                tabuleirojogo[linhapalpite][colunapalpite] = '.';
                imprimir_tabuleiro();
            }
            else
            {
                printf("Sem Efeito");
                printf("\n");
            }
        }
        if (ja_ganhou() == 0)
        {
            derrota = 1;
        }
    }
    if (ja_ganhou() == 0)
    {
        printf("voce ganhou uau");
        printf("\n");
    }
    return 0;
}
