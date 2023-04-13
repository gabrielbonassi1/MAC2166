/***************************************************************/
/**                                                           **/
/**   Gabriel Lujan Bonassi          11256816                 **/
/**   Exercício-Programa 02                                   **/
/**   Professor: Alair Pereira do Lago                        **/
/**   Turma: 01                                               **/
/**                                                           **/
/***************************************************************/
#include <stdio.h>

int main()
{
    double teto, pontuacaojogador, pontuacaobanca, caixa, diferencaentrereranterior, ranterior, carta, numerodecaracteresasterisco, derrotas1, n1; /* As variáveis derrotas1 e n1
    foram criada para evitar um erro, onde ao calcular o número de asteriscos, o valor das variáveis "derrotas" e "n" eram perdidos */
    int c1, c2, c3, semente, semente1, numerodecartasjogador, numerodecartasbanca, derrotas, n; /* As variáveis c1, c2,..., cn são utilizadas para contagens */
    printf("Insira um valor de semente: \t");
    scanf("%d", &semente);
    semente1 = semente; /* a variável semente1 foi criada para realizar contas usando o valor da semente, sem que ele seja perdido */
    caixa = semente;
    derrotas = 0; /* é necessário colocar o valor das variáveis como 0, pois senão elas virão com valores aleatórios gerados pelo codeblocks */
    numerodecartasbanca = 0;
    numerodecartasjogador = 0;
    while (semente1 != 0){
        semente1 = semente1 / 10;
        caixa = caixa / 10;
    }

    /* Funções */

    int chao(double x){
        int y;
        y = x;
    return y;
    }

    double RaizCubica(double x1){
        double r, padrao;
        padrao = 0.00000001;
        r = x1;
        ranterior = r;
        diferencaentrereranterior = r - ranterior;
            while (diferencaentrereranterior > padrao){
                r = ((2/3)*ranterior)+((x1)/(3*(ranterior*ranterior)));
                diferencaentrereranterior = r - ranterior;
                ranterior = r;
            }
    return r;
    }
    double NovaCaixa(double caixa1){
        double rifa;
        rifa = 9821.0 * RaizCubica(caixa) + 0.211327;
        caixa1 = rifa - chao(rifa);
    return caixa1;
    }

    /* Execução do jogo */

    for (teto=0.5; teto<=7.5; teto=teto+0.5){
        for (n=0; n<10000; n++){
            while (pontuacaojogador < teto){
                caixa = NovaCaixa(caixa);
                carta = chao(caixa*10 + 1);
                if(carta==8 || carta==9 || carta==10){
                    carta = 0.5;
                }
                pontuacaojogador = pontuacaojogador + carta;
                numerodecartasjogador = numerodecartasjogador + 1;
            }
            if (pontuacaojogador<=7.5){
                while (pontuacaobanca < pontuacaojogador){
                    caixa = NovaCaixa(caixa);
                    carta = chao(caixa*10 + 1);
                    if (carta==8 || carta==9 || carta==10){
                        carta = 0.5;
                    }
                    pontuacaobanca = pontuacaobanca + carta;
                    numerodecartasbanca = numerodecartasbanca + 1;
                }
            }
            if (pontuacaobanca>7.5){
                derrotas = derrotas + 1;
            }
            if (pontuacaojogador>pontuacaobanca && pontuacaojogador<=7.5){
                derrotas = derrotas + 1;
            }
            if (pontuacaobanca == pontuacaojogador && numerodecartasjogador<numerodecartasbanca){
                derrotas = derrotas + 1;
            }
            pontuacaobanca = 0;
            pontuacaojogador = 0;
            numerodecartasbanca = 0;
            numerodecartasjogador = 0;
        }

        /* Início da impressão */

        numerodecaracteresasterisco = 0;
        derrotas1 = derrotas;
        n1 = n;
        numerodecaracteresasterisco = chao( 100*(derrotas1/n1) + 0.5 );
        printf("%.1f", teto);
        printf("\t %d", derrotas);
        for(c3=0; c3<numerodecaracteresasterisco; c3 ++){
            printf("*");
        }
        printf("\n");
        derrotas = 0;
        numerodecaracteresasterisco = 0;
        derrotas1 = 0;
        n1 = 0;
    }

    return 0;
}
