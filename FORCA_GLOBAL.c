#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

//GLOBAIS
char palavraSecreta[TAM_PALAVRA];
char chutes[26];
int chutesdados = 0;


int letraexiste(char letra) {

    for(int j = 0; j < strlen(palavraSecreta); j++) {
        if(letra == palavraSecreta[j]) {
            return 1;
        }
    }

    return 0;
}

int chutesErrados() {
    int erros = 0;

    for(int i = 0; i < chutesdados; i++) {

        if(!letraexiste(chutes[i])) {
            erros++;
        }
    }

    return erros;
}

int enforcou() {
    return chutesErrados() >= 5;
}

int ganhou(){
    for(int i = 0; i < strlen(palavraSecreta); i++){
        if(!jaChutou(palavraSecreta[i])){
            return 0;
        }
    }
    return 1;
}


void inicio(){
    printf("============================\n");
    printf("|      JOGO DA FORCA        |\n");
    printf("============================\n\n");
}

void chuta(){
    char chute;
    printf("Qual a letra? ");
    scanf(" %c", &chute);

    if(letraexiste(chute)) {
        printf("Voce acertou: a palavra tem a letra %c\n\n", chute);
    } else {
        printf("\nVoce errou: a palavra NAO tem a letra %c\n\n", chute);
    }

    chutes[chutesdados] = chute; 
    chutesdados++;                                                                            
}

int jaChutou(char letra){
            int achou = 0;

            for(int j = 0; j < chutesdados; j++){
                if(chutes[j] == letra){
                    achou = 1;
                    break;
                }
            }
     return achou;
}

void desenhaForca(){
        int erros = chutesErrados();

        printf("  _______       \n");
        printf(" |/      |      \n");
        printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
        printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
        printf(" |       %c     \n", (erros>=2?'|':' '));
        printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
        printf(" |              \n");
        printf("_|___           \n");
        printf("\n\n");
        for(int i = 0; i < strlen(palavraSecreta); i++){
            //int achou = jaChutou(palavraSecreta[i]);
            if(jaChutou(palavraSecreta[i])) {
                printf("%c ", palavraSecreta[i]);
            }else {
                printf("_ ");
            }
        }
            printf("\n");
}

void escolhePalavra(){        
       FILE *f;
       f = fopen("palavras.txt", "r");

       if(f == 0){
          printf("Erro detectado, banco de dados nao disponivel\n\n");
          exit(1);
       }
       
       int qtdpalavras;
       fscanf(f,"%d", &qtdpalavras);

       srand(time(0));
       int randomico = rand() % qtdpalavras;

       for(int i = 0; i <= randomico; i++){
            fscanf(f, "%s", palavraSecreta);
       }

       fclose(f);
}


void adicionapalavra(){
    char quer;

    printf("Voce deseja adicionar uma nova palavra no jogo? [S/N] ");
    scanf(" %c", &quer);

    if(quer == 'S' || quer == 's'){
        char novapalavra[TAM_PALAVRA];

        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra);

        FILE *f;

        f = fopen("palavras.txt", "r+");
        if(f == 0){
            printf("Erro detectado, banco de dados nao disponivel\n\n");
            exit(1);
        }

        int qtd;

        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}



int main(){
 
    inicio();
    escolhePalavra();

    do{
        desenhaForca();
        chuta();
         
    }while(!ganhou() && !enforcou());
        if(ganhou()){
        printf("        ##########################                  \n");
        printf("        ##########################                  \n");  
        printf("   #####################################            \n");
        printf(" #########################################          \n");
        printf("####      ######################       ####         \n");
        printf("###       ######################        ###         \n");         
        printf("##        ######################        ###         \n");
        printf("###     ##########################      ###         \n");
        printf("###    ############################    ####         \n");
        printf(" ###   ### #################### ###    ###          \n");            
        printf(" ####   ### ################## ####  ####           \n");
        printf("   ####  ######################### #####            \n");
        printf("    ######## ################ #########             \n");
        printf("      ######  ##############   ######               \n");
        printf("               ############                         \n");
        printf("                 ########                           \n");
        printf("                   ####                             \n");
        printf("                   ####                             \n");
        printf("                   ####                             \n");
        printf("                   ####                             \n");  
        printf("               ############                         \n");  
        printf("            ##################                      \n"); 
        printf("            ##################                      \n");       
        printf("            ###            ###                      \n");        
        printf("            ###            ###                      \n");    
        printf("            ###            ###                      \n");
        printf("            ##################                      \n");              
        printf("            ##################                      \n");
        printf("          ######################                    \n");
        printf("         ########################                   \n");
    }else{
        printf("                    @@@@@@@@@@@@@@@@@@@                   `          \n");
        printf("                  @@@@@@             @@@@@@@                         \n");
        printf("               @@@@                       @@@@                       \n");
        printf("              @@@                             @@                     \n");        
        printf("             @@                                @@                    \n");
        printf("            @@                     `           @@          `         \n");
        printf("           @@                                   @@                   \n");    
        printf("           @@ @@                             @@ @@                   \n");   
        printf("           @@ @@                             @@  @                   \n"); 
        printf("           @@ @@                             @@  @                   \n");    
        printf("           @@  @@                            @@ @@                   \n");  
        printf("           @@  @@                           @@  @@                   \n");
        printf("            @@ @@   @@@@@@@@     @@@@@@@@   @@ @@                    \n");
        printf("             @@@@ @@@@@@@@@@     @@@@@@@@@@ @@@@@                    \n");
        printf("              @@@ @@@@@@@@@@     @@@@@@@@@@ @@@                      \n");      
        printf("     @@@       @@  @@@@@@@@       @@@@@@@@@  @@      @@@@            \n");
        printf("    @@@@@     @@   @@@@@@@   @@@   @@@@@@@   @@     @@@@@@           \n");
        printf("   @@   @@    @@     @@@    @@@@@    @@@     @@    @@   @@           \n");
        printf("  @@@    @@@@  @@          @@@@@@@          @@  @@@@    @@@          \n");
        printf(" @@         @@@@@@@@       @@@@@@@       @@@@@@@@@        @@         \n");
        printf(" @@@@@@@@@     @@@@@@@@    @@@@@@@    @@@@@@@@      @@@@@@@@         \n");
        printf("   @@@@ @@@@@      @@@@@              @@@ @@     @@@@@@ @@@          \n");    
        printf("           @@@@@@  @@@  @@           @@  @@@  @@@@@@                 \n");
        printf("               @@@@@@ @@ @@@@@@@@@@@ @@ @@@@@@                       \n");
        printf("                   @@ @@ @ @ @ @ @ @ @ @ @@                          \n");
        printf("                 @@@@  @ @ @ @ @ @ @ @   @@@@@                       \n");
        printf("             @@@@@ @@   @@@@@@@@@@@@@   @@ @@@@@                     \n"); 
        printf("     @@@@@@@@@@     @@                 @@      @@@@@@@@@             \n");
        printf("    @@           @@@@@@@             @@@@@@@@          @@            \n");
        printf("     @@@     @@@@@     @@@@@@@@@@@@@@@     @@@@@     @@@             \n");
        printf("       @@   @@@           @@@@@@@@@           @@@   @@               \n");       
        printf("       @@  @@                                   @@  @@               \n");
        printf("        @@@@                                     @@@@                \n");
    }
    adicionapalavra();

}
