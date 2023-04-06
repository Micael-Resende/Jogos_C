#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//#define TENTATIVAS 5

int main() {
    
    system("cls");
    
    printf("=======================================================================================\n");
    printf("*  ######   #######  ##   ##           ##   ##   ####    ##   ##  #####     #####     *\n");
    printf("*   ##  ##   ##   #  ### ###           ##   ##    ##     ###  ##   ## ##   ##   ##    *\n");
    printf("*   ##  ##   ## #    #######            ## ##     ##     #### ##   ##  ##  ##   ##    *\n");
    printf("*   #####    ####    #######            ## ##     ##     ## ####   ##  ##  ##   ##    *\n");
    printf("*   ##  ##   ## #    ## # ##             ###      ##     ##  ###   ##  ##  ##   ##    *\n");
    printf("*   ##  ##   ##   #  ##   ##             ###      ##     ##   ##   ## ##   ##   ##    *\n");
    printf("*  ######   #######  ##   ##              #      ####    ##   ##  #####     #####     * \n");
    printf("=======================================================================================\n");

    int segundos = time(0);
    srand(segundos);//s - seed

    //int ganhou = 0;
    //int TENTATIVAS = 5;
    double numerogrande = rand() % 100;
    double numeroSecreto = numerogrande;
    int chute;
    int tentativa = 1;
    double pontos = 1000.0;
    int acertou = 0;
    int numeroTentativas;
    int nivel;

    printf("ESCOLHA O NIVEL DE DIFICULDADE: \n");
    printf("[1]FACIL [2]MEDIO [3]DIFICIL\n");
    scanf("%d", &nivel);

    switch(nivel){
        case 1:
            numeroTentativas = 20;
        break;

        case 2:
            numeroTentativas = 10;
        break;

        case 3:
            numeroTentativas = 5;
        break;
    
    default:
        printf("------------------\n");
        printf("| OPCAO INVALIDA! |\n");
        printf("------------------\n");
        printf("ESCOLHA O NIVEL DE DIFICULDADE CORRESPONDETE\n");
        printf("[1]FACIL\n[2]MEDIO\n[3]DIFICIL\n");
        printf("ESCOLHA: ");
        scanf("%d", &nivel);
        break;
    }

    //while(1){
    for(int i = 1; i <= numeroTentativas; i++){    //ganhou ==  0
        printf("=================\n");
        printf("| Tentativa %d   |\n",tentativa);
        printf("=================\n");
        
        printf("Informe seu chute: ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0){
            printf("==============================================\n");
            printf("| Valor invalido, informe valores positivos!  |\n");
            printf("==============================================\n");
            //i--;
            continue;//Continua a execução do loop FOR, partindo para a próxima iteração.
        }


        acertou = (numeroSecreto == chute);
        int maior = (chute > numeroSecreto); 
        int menor = (chute < numeroSecreto);

        if(acertou){
            //printf("Parabens voce acertou.\n", numeroSecreto);
            break;
            /* Quebra todo o código que temos no escopo abaixo, finalizando e sai do loop FOR
               ganhou = 1; Se atribuirmos um valor que ao ser comparado no loop der falso também quebramos o laço 
            */ 

        }else if(maior){
                printf("O numero > secreto\n");
            }else if(menor){
                //int teste; Esta variável existira somente neste escopo
                printf("O numero < secreto\n");
            }
        
         tentativa++;

        //pontos = pontos - ((numeroSecreto - chute) / 2);
        double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;
        pontos = pontos - pontosPerdidos;

    }

    printf("FIM DE JOGO\n");
    if(acertou){
        printf("================================\n");
        printf("| Voce acertou em %d tentativas |\n", tentativa);
        printf("================================\n");
        printf("Voce obeteve um total de %.2lf pontos\n\n", pontos);

        printf("                    __ooooooooo__                    \n");
        printf("              oOOOOOOOOOOOOOOOOOOOOOo                \n");
        printf("          oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo            \n");
        printf("       oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo         \n");
        printf("     oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo       \n");
        printf("   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo     \n");
        printf("  oOOOOOOOOOOO*  *OOOOOOOOOOOOOO*  *OOOOOOOOOOOOo    \n");
        printf(" oOOOOOOOOOOO      OOOOOOOOOOOO      OOOOOOOOOOOOo   \n");
        printf(" oOOOOOOOOOOOOo  oOOOOOOOOOOOOOOo  oOOOOOOOOOOOOOo   \n");
        printf("oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo \n");
        printf("oOOOO     OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     OOOOo \n");
        printf("oOOOOOO OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO OOOOOOo \n");
        printf(" *OOOOO  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  OOOOO*   \n");
        printf(" *OOOOOO  *OOOOOOOOOOOOOOOOOOOOOOOOOOOOO*  OOOOOO*   \n");
        printf("  *OOOOOO  *OOOOOOOOOOOOOOOOOOOOOOOOOOO*  OOOOOO*    \n");
        printf("   *OOOOOOo  *OOOOOOOOOOOOOOOOOOOOOOO*  oOOOOOO*     \n");
        printf("     *OOOOOOOo  *OOOOOOOOOOOOOOOOO*  oOOOOOOO*       \n");
        printf("       *OOOOOOOOo  *OOOOOOOOOOO*  oOOOOOOOO*         \n");  
        printf("          *OOOOOOOOo           oOOOOOOOO*            \n");    
        printf("              *OOOOOOOOOOOOOOOOOOOOO*                \n");       
        printf("                    ""ooooooooo""                    \n");
        printf("\n\n");
        
    }else{
        printf("================================\n");
        printf("| VOCE PERDEU! TENTE NOVAMENTE  |\n");
        printf("================================\n\n");

        printf("                                                           ..           \n");
        printf("                                ,,,                         MM .M       \n");
        printf("                            ,!MMMMMMM!,                     MM MM  ,.   \n");
        printf("    ., .M                .MMMMMMMMMMMMMMMM.,          'MM.  MM MM .M'   \n");
        printf("  . M: M;  M          .MMMMMMMMMMMMMMMMMMMMMM,          'MM,:M M'!M'    \n");
        printf(" ;M MM M: .M        .MMMMMMMMMMMMMMMMMMMMMMMMMM,         'MM'...'M      \n");
        printf("  M;MM;M :MM      .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.       .MMMMMMMM      \n");
        printf("  'M;M'M MM      MMMMMM  MMMMMMMMMMMMMMMMM  MMMMMM.    ,,M.M.'MMM'      \n");
        printf("   MM'MMMM      MMMMMM @@ MMMMMMMMMMMMMMM @@ MMMMMMM.'M''MMMM;MM'       \n");
        printf("  MM., ,MM     MMMMMMMM  MMMMMMMMMMMMMMMMM  MMMMMMMMM      '.MMM        \n");
        printf("  'MM;MMMMMMMM.MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.      'MMM        \n");
        printf("   ''.'MMM'  .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM       MMMM       \n");
        printf("    MMC      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.      'MMMM      \n");
        printf("   .MM      :MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM''MMM       MMMMM     \n");
        printf("   MMM      :M  'MMMMMMMMMMMMM.MMMMM.MMMMMMMMMM'.MM  MM:M.    'MMMMM    \n");
        printf("  .MMM   ...:M: :M.'MMMMMMMMMMMMMMMMMMMMMMMMM'.M''   MM:MMMMMMMMMMMM'   \n");
        printf(" AMMM..MMMMM:M.    :M.'MMMMMMMMMMMMMMMMMMMM'.MM'     MM''''''''''''     \n");
        printf(" MMMMMMMMMMM:MM     'M'.M'MMMMMMMMMMMMMM'.MC'M'     .MM                 \n");
        printf("  '''''''''':MM.       'MM!M.'M-M-M-M'M.'MM'        MMM                 \n");   
        printf("             MMM.            'MMMM!MMMM'            .MM                 \n");
        printf("              MMM.             '''   ''            .MM'                 \n");
        printf("               MMM.                               MMM'                  \n");
        printf("                MMMM            ,.J.JJJJ.       .MMM'                   \n");
        printf("                 MMMM.       'JJJJJJJ'JJJM   CMMMMM                     \n");
        printf("                   MMMMM.    'JJJJJJJJ'JJJ .MMMMM'                      \n");
        printf("                     MMMMMMMM.'  'JJJJJ'JJMMMMM'                        \n");
        printf("                       'MMMMMMMMM'JJJJJ JJJJJ'                          \n");
        printf("                          ''MMMMMMJJJJJJJJJJ'                           \n");
        printf("                                  'JJJJJJJJ'                            \n");   
        printf("\n\n");
    }
   
    return 0;
}