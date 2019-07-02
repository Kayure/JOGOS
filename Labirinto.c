
// CODIGO DESENVOLVIDO POR LUCCAS KAYURE CRISANTO 
// ANALISE E DESENVOLVIMENTO DE SISTEMAS - IFPR CAMPUS PARANAGUÁ
// PROGRAMAÇÃO DE COMPUTADORES
// COM PONTUAÇÃO E PASSOS



#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

#define CHAO 0
#define PAREDE 1
#define VOCE 2
#define PESSOA 3
#define FALSO 4
  
#define LIMPARTELA "clear"



int getch(void); 
 int getch(void)
     {

         struct termios oldattr, newattr;
         int ch;

         tcgetattr( STDIN_FILENO, &oldattr);
         newattr = oldattr;
         newattr.c_lflag &= ~( ICANON | ECHO);
         tcsetattr( STDIN_FILENO, TCSANOW, &newattr);
         ch = getchar();
         tcsetattr( STDIN_FILENO, TCSANOW, &oldattr);

        return ch;
     }

int main()
{

    int inicio, escolha, escolha0, voltar;
    
    char movimento;
    char jogada;   

    int EscolhaDificuldade;
    int Coluna_Atual = 2, Linha_Atual = 2;

    int LinhaFacil, ColunaFacil;
    int PontosFacil=1, PassosFacil=0;

    int LinhaMedio, ColunaMedio;
    int PontosMedio=2, PassosMedio=0;

    int LinhaDificil, ColunaDificil;
    int PontosDificil=3, PassosDificil=0;



    int MapaFacil[10][30] = 
    { 
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,1,1,1,0,1,1,0,1,1,1,1,1,0,0,0,1,1,0,1,1,1,1,0,1,1,
        1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,
        1,0,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0,0,0,0,1,1,0,1,1,1,0,0,1,1,
        1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
        1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,0,0,0,0,0,0,0,1,
        1,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
 

    int MapaMedio[20][40] = 
    { 
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,
        1,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,1,
        1,1,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,1,
        1,0,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,4,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
        1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,
        1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,
        1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,
        1,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,0,1,1,1,
        1,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,
        1,0,1,1,0,1,1,1,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,
        1,0,1,1,0,1,1,1,0,1,0,1,1,0,1,1,0,1,1,1,1,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,1,1,0,1,1,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,0,1,
        1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,0,1,
        1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,0,0,0,1,1,1,0,1,
        1,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,4,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,3,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,           
    };


    int MapaDificil[30][40] = 
    { 
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,
        1,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,1,
        1,1,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,1,
        1,0,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,
        1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
        1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,
        1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,
        1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,
        1,1,0,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,0,1,1,1,
        1,4,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,
        1,0,1,1,0,1,1,1,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,
        1,0,1,1,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,4,1,
        1,0,1,1,0,1,1,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,0,1,
        1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,0,1,
        1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,0,0,0,1,1,1,0,1,
        1,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,
        1,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0,0,1,0,1,1,0,0,0,0,1,1,1,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,
        1,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,1,
        1,1,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,1,
        1,0,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
        1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,0,1,
        1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,4,0,0,0,0,0,0,0,1,1,0,1,1,1,0,1,1,1,0,0,3,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,          
     };

        printf("\n##################### L A B I R I N T O #####################################");
        printf("\n");
        printf("\n \t\t 1 - 🤔 Como jogar 🤔 "); // FEITO
        printf("\n \t\t 2 - 🏅 Creditos  🏅 ");
        printf("\n \t\t 3 - 🏁 Jogar 🏁\n"); //FEITO
        printf("\n \t\tPressione ""X"" para SAIR\n"); //FEITO
        printf("\n#############################################################################\n");

        scanf("%i",&escolha0 );
        fflush(stdin);
        
        //primeiro little & switch
        switch (escolha0) 
        {

            case 1:
             {

            
                 system(LIMPARTELA);
                 printf("\n*Escolha uma dificuldade no menu antes de iniciar o jogo\n\n\n");

                 printf("\nNIVEL FACIL: \n");
                 printf("\n*1 PONTO POR ESCOLHER A DIFICULDADE FÁCIL*\n");
                 printf("\n*1 PONTO QUANDO ASSUSTAR A VITIMA*\n");                
                 printf("\n*1 ARMADILHA PRA DESPISTAR O FANTASMA *\n");
                 printf("\n* ASSUSTAR EM MENOS DE 50 PASSOS*\n\n\n");

                 printf("\nNIVEL MÉDIO\n");
                 printf("\n*2 PONTOS POR ESCOLHER A DIFICULDADE MÉDIA*\n");
                 printf("\n*1 PONTO QUANDO ASSUSTAR A VITIMA*\n");                
                 printf("\n*4 ARMADILHAS PRA DESPISTAR O FANTASMA *\n"); 
                 printf("\n* ASSUSTAR EM MENOS DE 60 PASSOS*\n\n\n");

                 printf("\nNIVEL DIFICIL\n");
                 printf("\n*3 PONTOS POR ESCOLHER A DIFICULDADE MÉDIA*\n");
                 printf("\n*1 PONTO QUANDO ASSUSTAR A VITIMA*\n");
                 printf("\n*5 ARMADILHAS PRA DESPISTAR O FANTASMA *\n");
                 printf("\n* ASSUSTAR EM MENOS DE 75 PASSOS *\n\n\n");

                 
                 
                 printf("\n Use para se mover:\n");
                 printf("\n\n  (W)\n(A)+(D)\n  (S)\n");
                 printf("\nPressione ENTER para voltar\n");

                 __fpurge(stdin);
                 getchar();
                 system(LIMPARTELA);
                 main();

                 break;
            }

            case 2: //CREDITOS
            {
    
                 system(LIMPARTELA);
                 printf("\n\n JOGO DESENVOLVIDO POR: LUCCAS KAYURE CRISANTO\n");
                 printf("\n\n IFPR PARANAGUÁ\n");
                 printf("\n\n PROFESSOR: GIL EDUARDO DE ANDRADE\n");
                 printf("\n\n PROGRAMAÇÃO DE COMPUTADORES - 2019\n");
                
                 printf("\nPressione ENTER para voltar\n");

                 __fpurge(stdin);
                 getchar();
                 system(LIMPARTELA);
                 main();

                 
                 
            }


            case 3:
            {

                 system(LIMPARTELA);
                 //ESCOLHER DIFICULDADE DO JOGO
                 printf("\n##################### L A B I R I N T O #####################################\n");
                 printf("\n\n  (W)\n(A)+(D)\n  (S)\n"); /* Imprime as direcoes */
                 printf("\n");
                 printf("\n 1 - Modo Fácil (1 ponto)");
                 printf("\n 2 - Modo Intermédiario (2 pontos)");
                 printf("\n 3 - Modo Dificil (3 pontos)\n");
                 printf("\nPressione ""X"" para SAIR\n");
                 printf("\n#############################################################################\n");

                 __fpurge(stdin);
                 scanf("%i",&EscolhaDificuldade);
                
            }
         } 

                //segundo little & switch
                switch (EscolhaDificuldade) 
                {

                     case 1:
                     {

                
                        system(LIMPARTELA);
                        printf("\n\n LABIRINTO FACIL // MAXIMO 50 JOGADAS\n\n");
    

                        while ((movimento != 'x') && (movimento != 'X')) 
                         {
                             for (LinhaFacil=0;LinhaFacil<10;LinhaFacil++) 
                             {
                                 for (ColunaFacil=0;ColunaFacil<30;ColunaFacil++) 
                                  {
                                     if ((LinhaFacil == Linha_Atual) && (ColunaFacil == Coluna_Atual)) 
                                      {
                                         printf("👻");  //👻
                                         continue;
                                       }
                                         if (MapaFacil[LinhaFacil][ColunaFacil] == CHAO)
                                         printf("  ");
                                         if (MapaFacil[LinhaFacil][ColunaFacil] == PAREDE)
                                         printf("⬛");
                                         if (MapaFacil[LinhaFacil][ColunaFacil] == PESSOA)
                                         printf("😕"); 
                                         if (MapaFacil[LinhaFacil][ColunaFacil] == FALSO)
                                         printf("😕");                                 
	                             }
                                        
                                        printf("\n");
                             }           
                                        __fpurge(stdin);
                                        movimento = getch();
                                        PassosFacil++;                                        
                                     if(PassosFacil >= 50)
                                      {
                                         system(LIMPARTELA);
                                         printf("\n##################### voce perdeu ###########################################\n");
                                         printf("\npressione ENTER pra voltar ao menu principal\n");
                                         __fpurge(stdin);
                                         getch();
                                         system(LIMPARTELA);
                                         return main();
                                        }
                                                    
                                        system(LIMPARTELA);                                  
                                                             

                                     if ((movimento == 'w') || (movimento == 'W')) 
                                     {
                                         Linha_Atual = Linha_Atual - 1;
                                        /* Se não for chao ou grama ele volta pra posicao anterior */

                                          if (MapaFacil[Linha_Atual][Coluna_Atual] == PAREDE ) 
                                         {
                                             Linha_Atual = Linha_Atual + 1;
                                             __fpurge(stdin);
                                             movimento = getch();
                                             PassosFacil++;
                                             if(PassosFacil >= 50)
                                                {
                                                    system(LIMPARTELA);
                                                    printf("\n##################### voce perdeu ###########################################\n");
                                                    printf("\npressione ENTER pra voltar ao menu principal\n");
                                                    __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                    return main();
                                                    }
                                             
                                         }
                                          if(MapaFacil[Linha_Atual][Coluna_Atual] == PESSOA)
                                             {
                                                 PontosFacil++;
                                                 system(LIMPARTELA);
                                                 printf("\n\t🏆FIM DE JOGO🏆\n\t ");
                                                 printf("\n🥉 sua pontuação foi de :%i🥉\n",PontosFacil);                                                
                                                 printf("\n🥉 voce deu :%i passos🥉\n",PassosFacil);                                         
                                                 printf("\nPressione ENTER para voltar\n");
                                                 getchar();
                                                 system(LIMPARTELA);
                                                 main();                                                
                                             }
                                     }


                                     if ((movimento == 's') || (movimento == 'S')) 
                                     {
                                        Linha_Atual = Linha_Atual + 1;
                                        /* Se não for chao ou grama ou saida ele volta pra posicao anterior */

                                          if (MapaFacil[Linha_Atual][Coluna_Atual] == PAREDE)  
                                           {
                                                 Linha_Atual = Linha_Atual - 1;                                    
                                                 __fpurge(stdin);
                                                 movimento = getch();
                                                 PassosFacil++;
                                                 if(PassosFacil >= 50)
                                                {
                                                    system(LIMPARTELA);
                                                    printf("\n##################### voce perdeu ###########################################\n");
                                                    printf("\npressione ENTER pra voltar ao menu principal\n");
                                                    __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                    main();
                                                    }
                                             
                                            }

                                          if(MapaFacil[Linha_Atual][Coluna_Atual] == PESSOA)
                                           {
                                                 PontosFacil++;
                                                 system(LIMPARTELA);
                                                 printf("\n\t🏆FIM DE JOGO🏆\n\t ");
                                                 printf("\n🥉 sua pontuação foi de :%i🥉\n",PontosFacil);                                                
                                                 printf("\n🥉 voce deu :%i passos🥉\n",PassosFacil);                                         
                                                 printf("\nPressione ENTER para voltar\n");
                                                 getchar();
                                                 system(LIMPARTELA);
                                                 main();        
                                             }
                                     }


                                     if ((movimento == 'd') || (movimento == 'D')) 
                                     {
                                        Coluna_Atual = Coluna_Atual + 1;
                                        /* Se não for chao ou grama ou saida ele volta pra posicao anterior */
                                            if (MapaFacil[Linha_Atual][Coluna_Atual] == PAREDE ) 
                                            {
                                                 Coluna_Atual = Coluna_Atual - 1;                                            
                                                 __fpurge(stdin);
                                                 movimento = getch();   
                                                 PassosFacil++;    

                                                 if(PassosFacil>= 50)
                                                {   
                                                   system(LIMPARTELA);
                                                    printf("\n##################### voce perdeu ###########################################\n");
                                                    printf("\npressione ENTER pra voltar ao menu principal\n");
                                                    __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                    main();
                                                    }                                      
                                             }

                                            if(MapaFacil[Linha_Atual][Coluna_Atual] == PESSOA)
                                            {   
                                                 PontosFacil++;
                                                 system(LIMPARTELA);
                                                 printf("\n\t🏆FIM DE JOGO🏆\n\t ");
                                                 printf("\n🥉 sua pontuação foi de :%i🥉\n",PontosFacil);                                                
                                                 printf("\n🥉 voce deu :%i passos🥉\n",PassosFacil);                                         
                                                 printf("\nPressione ENTER para voltar\n");
                                                 getchar();
                                                 system(LIMPARTELA);
                                                 main();        
                                             }
                                     }


                                     if ((movimento == 'a') || (movimento == 'A')) 
                                     {
                                            Coluna_Atual = Coluna_Atual - 1;
                                            /* Se não for chao ou grama ou saida ele volta pra posicao anterior */
                                            if (MapaFacil[Linha_Atual][Coluna_Atual] == PAREDE ) 
                                             {
                                                 Coluna_Atual = Coluna_Atual + 1;
                                            
                                                 __fpurge(stdin);
                                                 movimento = getch();
                                                 PassosFacil++;

                                                 if(PassosFacil >= 50)
                                                 {  
                                                     system(LIMPARTELA);
                                                     printf("\n##################### voce perdeu ###########################################\n");
                                                     printf("\npressione ENTER pra voltar ao menu principal\n");
                                                     __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                     main();
                                                 }
                                             
                                             }
                                            if(MapaFacil[Linha_Atual][Coluna_Atual] == PESSOA)
                                            {
                                                 PontosFacil++;
                                                 system(LIMPARTELA);
                                                 printf("\n\t🏆FIM DE JOGO🏆\n\t ");
                                                 printf("\n🥉 sua pontuação foi de :%i🥉\n",PontosFacil);                                                
                                                 printf("\n🥉 voce deu :%i passos🥉\n",PassosFacil);                                         
                                                 printf("\nPressione ENTER para voltar\n");
                                                 getchar();
                                                 system(LIMPARTELA);
                                                 main();        
                                             }
                                     }
                                   
                         }
                     }

                     case 2:
                     {
                            PontosMedio ++;
                                system(LIMPARTELA);
                                printf("\n\n LABIRINTO MEDIO // MAXIMO 60 PASSOS\n\n");
                                while ((movimento != 'x') && (movimento != 'X')) 
                                {
                                for (LinhaMedio=0;LinhaMedio<20;LinhaMedio++) 
                                 {
                                     for (ColunaMedio=0;ColunaMedio<40;ColunaMedio++) 
                                    {   
                                        if ((LinhaMedio == Linha_Atual) && (ColunaMedio == Coluna_Atual)) 
                                         {
                                             printf("👻");  //👻
                                            continue;
                                         }
                                            if (MapaMedio[LinhaMedio][ColunaMedio] == CHAO)
                                            printf("  ");
                                            if (MapaMedio[LinhaMedio][ColunaMedio] == PAREDE)
                                            printf("⬛");
                                            if (MapaMedio[LinhaMedio][ColunaMedio] == PESSOA)
                                            printf("😕");
                                            if (MapaMedio[LinhaMedio][ColunaMedio] == FALSO)
                                            printf("😕"); 
                                     }
                                         printf("\n");
                                 }
                                      
                                        __fpurge(stdin);
                                        movimento = getch();
                                        system(LIMPARTELA); 
                                        PassosMedio++;

                            
                                     if ((movimento == 'w') || (movimento == 'W')) 
                                     {
                                         Linha_Atual = Linha_Atual - 1;
                                         /* Se não for chao ou grama ele volta pra posicao anterior */
                                            if ((MapaMedio[Linha_Atual][Coluna_Atual] == PAREDE) ) 
                                            {
                                                 Linha_Atual =  Linha_Atual + 1;
                                                 __fpurge(stdin);
                                                 movimento = getch();
                                                 PassosMedio++;

                                                 if(PassosMedio >= 60)
                                                {  
                                                     system(LIMPARTELA);
                                                     printf("\n##################### voce perdeu ###########################################\n");
                                                     printf("\npressione ENTER pra voltar ao menu principal\n");
                                                     __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                     main();
                                                    }
	     
                                            }

                                             if(MapaMedio[Linha_Atual][Coluna_Atual] == PESSOA)
                                            {
                                                 PontosMedio++;
                                                 system(LIMPARTELA);
                                                 printf("\n\t🏆FIM DE JOGO🏆\n\t ");
                                                 printf("\n🥉 sua pontuação foi de :%i🥉\n",PontosMedio);                                                
                                                 printf("\n🥉 voce deu :%i passos🥉\n",PassosMedio);                                         
                                                 printf("\nPressione ENTER para voltar\n");
                                                 getchar();
                                                 system(LIMPARTELA);
                                                 main(); 
                                                
                                            }
                                     }



                                    if ((movimento == 's') || (movimento == 'S')) 
                                     {
                                        Linha_Atual = Linha_Atual + 1;
                                         /* Se não for chao ou grama ou saida ele volta pra posicao anterior */
                                        if ((MapaMedio[Linha_Atual][Coluna_Atual] == PAREDE))
                                         {
                                             Linha_Atual = Linha_Atual - 1;
                                             __fpurge(stdin);
                                             movimento = getch();    
                                             PassosMedio++;

                                                 if(PassosMedio >= 60)
                                                {  
                                                     system(LIMPARTELA);
                                                     printf("\n##################### voce perdeu ###########################################\n");
                                                     printf("\npressione ENTER pra voltar ao menu principal\n");
                                                     __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                     main();
                                                    }
                                         }
                                         if((MapaMedio[Linha_Atual][Coluna_Atual] == PESSOA))
                                            {
                                                {
                                                 PontosMedio++;
                                                 system(LIMPARTELA);
                                                 printf("\n\t🏆FIM DE JOGO🏆\n\t ");
                                                 printf("\n🥉 sua pontuação foi de :%i🥉\n",PontosMedio);                                                
                                                 printf("\n🥉 voce deu :%i passos🥉\n",PassosMedio);                                         
                                                 printf("\nPressione ENTER para voltar\n");
                                                 getchar();
                                                 system(LIMPARTELA);
                                                 main(); 
                                                
                                            }                                                
                                            }
                                     }


                                     if ((movimento == 'd') || (movimento == 'D')) 
                                     {
                                         Coluna_Atual = Coluna_Atual + 1;
                                         /* Se não for chao ou grama ou saida ele volta pra posicao anterior */
                                         if ((MapaMedio[Linha_Atual][Coluna_Atual] == PAREDE))
                                         {
                                             Coluna_Atual = Coluna_Atual - 1;
                                             __fpurge(stdin);
                                             movimento = getch();
                                             PassosMedio++;

                                                 if(PassosMedio >= 60)
                                                 {  
                                                     system(LIMPARTELA);
                                                     printf("\n##################### voce perdeu ###########################################\n");
                                                     printf("\npressione ENTER pra voltar ao menu principal\n");
                                                     __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                     main();
                                                    }
	 
                                         }
                                            if((MapaMedio[Linha_Atual][Coluna_Atual] == PESSOA))
                                            {
                                                
                                                 PontosMedio++;
                                                 system(LIMPARTELA);
                                                 printf("\n\t🏆FIM DE JOGO🏆\n\t ");
                                                 printf("\n🥉 sua pontuação foi de :%i🥉\n",PontosMedio);                                                
                                                 printf("\n🥉 voce deu :%i passos🥉\n",PassosMedio);                                         
                                                 printf("\nPressione ENTER para voltar\n");
                                                 getchar();
                                                 system(LIMPARTELA);
                                                 main();                                                                           
                                            }
                                     }


                                     if ((movimento == 'a') || (movimento == 'A')) 
                                     {
                                          Coluna_Atual = Coluna_Atual - 1;
                                         /* Se não for chao ou grama ou saida ele volta pra posicao anterior */
                                          if ((MapaMedio[Linha_Atual][Coluna_Atual] == PAREDE)) 
                                           {   
                                             Coluna_Atual = Coluna_Atual + 1;
                                             __fpurge(stdin);
                                             movimento = getch();	  
                                             PassosMedio++;

                                                 if(PassosMedio >= 60)
                                                {  
                                                     system(LIMPARTELA);
                                                     printf("\n##################### voce perdeu ###########################################\n");
                                                     printf("\npressione ENTER pra voltar ao menu principal\n");
                                                     __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                     main();
                                                    }
                                          }
                                          if((MapaMedio[Linha_Atual][Coluna_Atual] == PESSOA))
                                            {
                                                
                                                 PontosMedio++;
                                                 system(LIMPARTELA);
                                                 printf("\n\t🏆FIM DE JOGO🏆\n\t ");
                                                 printf("\n🥉 sua pontuação foi de :%i🥉\n",PontosMedio);                                                
                                                 printf("\n🥉 voce deu :%i passos🥉\n",PassosMedio);                                         
                                                 printf("\nPressione ENTER para voltar\n");
                                                 getchar();
                                                 system(LIMPARTELA);
                                                 main(); 
                                                
                                                                                          
                                            }
                                     } 

                         }
   
                     } 


       
                     case 3:
                     {
                         PontosDificil ++;
                         system(LIMPARTELA);
                         printf("\n\n LABIRINTO DIFICIL // MAXIMO 75 PASSOS\n\n");                            
                         
                         while ((movimento != 'x') && (movimento != 'X')) 
                         {                                 
                                
                            for (LinhaDificil=0;LinhaDificil<30;LinhaDificil++) 
                            {
                                for (ColunaDificil=0;ColunaDificil<40;ColunaDificil++) 
                                {
                                 if ((LinhaDificil == Linha_Atual) && (ColunaDificil == Coluna_Atual)) 
                                  {
                                     printf("👻");  //👻
                                     continue;
                                 }
                                        if (MapaDificil[LinhaDificil][ColunaDificil] == CHAO)
                                        printf("  ");
                                        if (MapaDificil[LinhaDificil][ColunaDificil] == PAREDE)
                                        printf("⬛");
                                        if (MapaDificil[LinhaDificil][ColunaDificil] == PESSOA)
                                        printf("😕");
                                         if (MapaDificil[LinhaDificil][ColunaDificil] == FALSO)
                                         printf("😕"); 
	    
                                 }
                                    printf("\n");
                             }                                     

                                        __fpurge(stdin);
                                        movimento = getch();
                                        PassosDificil++;

                                        if(PassosDificil >= 75)
                                            {
                                                    system(LIMPARTELA);
                                                    printf("\n##################### voce perdeu ###########################################\n");
                                                    printf("\npressione ENTER pra voltar ao menu principal\n");
                                                    __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                    return main();
                                                    }
                                                                        
                                if ((movimento == 'w') || (movimento == 'W')) 
                                 {
                                    Linha_Atual = Linha_Atual - 1;
                                    /* Se não for chao ou grama ele volta pra posicao anterior */                                }   
                                    if ((MapaDificil[Linha_Atual][Coluna_Atual] == PAREDE))
                                     { 
                                         Linha_Atual =  Linha_Atual + 1;
                                         __fpurge(stdin);
                                         movimento = getch();
                                         PassosDificil++;

                                        if(PassosDificil >= 75)
                                            {
                                                    system(LIMPARTELA);
                                                    printf("\n##################### voce perdeu ###########################################\n");
                                                    printf("\npressione ENTER pra voltar ao menu principal\n");
                                                    __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                    return main();
                                                    }
                                    }  
                                    if((MapaDificil[Linha_Atual][Coluna_Atual] == PESSOA))
                                     {     
                                         PontosDificil++;
                                                 system(LIMPARTELA);
                                                 printf("\n\t🏆FIM DE JOGO🏆\n\t ");
                                                 printf("\n🥉 sua pontuação foi de :%i🥉\n",PontosDificil);                                                
                                                 printf("\n🥉 voce deu :%i passos🥉\n",PassosDificil);                                         
                                                 printf("\nPressione ENTER para voltar\n");
                                                 getchar();
                                                 system(LIMPARTELA);
                                                 main(); 
                                                
                                     }     
                 
                                 if ((movimento == 's') || (movimento == 'S')) 
                                 {
                                    Linha_Atual = Linha_Atual + 1;
                                    /* Se não for chao ou grama ou saida ele volta pra posicao anterior */                                 }
                                     if ((MapaDificil[Linha_Atual][Coluna_Atual] == PAREDE))
                                    {
                                         Linha_Atual = Linha_Atual - 1;
                                         __fpurge(stdin);
                                          movimento = getch();
                                          PassosDificil++;

                                        if(PassosDificil >= 75)
                                            {
                                                    system(LIMPARTELA);
                                                    printf("\n##################### voce perdeu ###########################################\n");
                                                    printf("\npressione ENTER pra voltar ao menu principal\n");
                                                    __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                    return main();
                                                    }
                                    }   
                                    if((MapaDificil[Linha_Atual][Coluna_Atual] == PESSOA))
                                    {      
                                         PontosDificil++;
                                                 system(LIMPARTELA);
                                                 printf("\n\t🏆FIM DE JOGO🏆\n\t ");
                                                 printf("\n🥉 sua pontuação foi de :%i🥉\n",PontosDificil);                                                
                                                 printf("\n🥉 voce deu :%i passos🥉\n",PassosDificil);                                         
                                                 printf("\nPressione ENTER para voltar\n");
                                                 getchar();
                                                 system(LIMPARTELA);
                                                 main(); 
                                                
                                     }                                            
                                                                 
                                if ((movimento == 'd') || (movimento == 'D')) 
                                {
                                    Coluna_Atual = Coluna_Atual + 1;
                                    /* Se não for chao ou grama ou saida ele volta pra posicao anterior */
                                     if ((MapaDificil[Linha_Atual][Coluna_Atual] == PAREDE))
                                    { 
                                         Coluna_Atual = Coluna_Atual - 1;
                                         __fpurge(stdin);
                                         movimento = getch();
                                         PassosDificil++;

                                        if(PassosDificil >= 50)
                                            {
                                                    system(LIMPARTELA);
                                                    printf("\n##################### voce perdeu ###########################################\n");
                                                    printf("\npressione ENTER pra voltar ao menu principal\n");
                                                    __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                    return main();
                                                    }
                                     }
                                    if((MapaDificil[Linha_Atual][Coluna_Atual] == PESSOA))
                                    {       
                                         PontosDificil++;
                                                 system(LIMPARTELA);
                                                 printf("\n\t🏆FIM DE JOGO🏆\n\t ");
                                                 printf("\n🥉 sua pontuação foi de :%i🥉\n",PontosDificil);                                                
                                                 printf("\n🥉 voce deu :%i passos🥉\n",PassosDificil);                                         
                                                 printf("\nPressione ENTER para voltar\n");
                                                 getchar();
                                                 system(LIMPARTELA);
                                                 main(); 
                                                
                                     }
                                 }
            
                                 if ((movimento == 'a') || (movimento == 'A'))  
                                     {
                                        Coluna_Atual = Coluna_Atual - 1;
                                        /* Se não for chao ou grama ou saida ele volta pra posicao anterior */
                                        if ((MapaDificil[Linha_Atual][Coluna_Atual] == PAREDE))
                                         { 
                                             Coluna_Atual = Coluna_Atual + 1;
                                             __fpurge(stdin);
                                             movimento = getch(); 
                                             PassosDificil++;

                                        if(PassosDificil >= 75)
                                            {
                                                    system(LIMPARTELA);
                                                    printf("\n##################### voce perdeu ###########################################\n");
                                                    printf("\npressione ENTER pra voltar ao menu principal\n");
                                                    __fpurge(stdin);
                                                     getch();
                                                     system(LIMPARTELA);
                                                    return main();
                                                    }
                                        }

                                        if((MapaDificil[Linha_Atual][Coluna_Atual] == PESSOA))
                                        {      
                                                PontosDificil++;
                                                 system(LIMPARTELA);
                                                 printf("\n\t🏆FIM DE JOGO🏆\n\t ");
                                                 printf("\n🥉 sua pontuação foi de :%i🥉\n",PontosDificil);                                                
                                                 printf("\n🥉 voce deu :%i passos🥉\n",PassosDificil);                                         
                                                 printf("\nPressione ENTER para voltar\n");
                                                 getchar();
                                                 system(LIMPARTELA);
                                                 main(); 
                                                
                                         }
                                    }                     
                         }
                     }   
                 }     

}





       
        
         


                    
        

        
                     
        

        
        
    
