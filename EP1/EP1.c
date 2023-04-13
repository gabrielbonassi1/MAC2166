/***************************************************************/
/**                                                           **/
/**   Gabriel Lujan Bonassi          11256816                 **/
/**   Exercício-Programa 01                                   **/
/**   Professor: Alair Pereira do Lago                        **/
/**   Turma: 01                                               **/
/**                                                           **/
/***************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main () {
    int k, c, npalpite, npalpitetotal, senha, ppretos, palpite, i, j, senhaum; /* senhaum serve apenas para facilitar a execução do programa */
    ppretos = 0;
    printf("Entre com o numero de digitos: \t");
    scanf("%d", &k);
    printf("\n Entre com o numero de cores: \t");
    scanf("%d", &c);
    printf("\n Entre com o numero maximo de palpites: \t");
    scanf("%d", &npalpitetotal);
    printf("\n Entre com a senha de %d digitos (0 para valor aleatorio): \t", k);
    scanf("%d",&senha);
    if (senha == 0) {
    srand(time(NULL));
    for (i=0; i<k; i++)
    senha = senha*10 + (rand() % c + 1);
    }
    npalpite = 1;
    while (npalpite < npalpitetotal && ppretos < k) {
        printf("\n Digite o seu palpite: \t");
        scanf("%d", &palpite);
        senhaum = senha;
        for (j=0; j<k; j++) {
            if(palpite%10 == senhaum%10){
                ppretos = ppretos + 1;
            }
            palpite = palpite / 10;
            senhaum = senhaum / 10;
        }
        printf("\n Pinos pretos: %d", ppretos);
        if (ppretos < 4){
            ppretos = 0;
        }
        npalpite = npalpite + 1;
    }
    if (npalpite == npalpitetotal){
        printf("\n Sinto muito, mas nenhum dos %d palpites acertaram a senha %d!",npalpitetotal, senha);
    }
    if (ppretos == k) {
        printf("\n Parabens! Voce descobriu a senha em %d tentativas.", npalpite);
    }

return 0;
}
