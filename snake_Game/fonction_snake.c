# include <stdio.h>
# include <ncurses.h>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
#include "fonction.h"
/*DEFINITION DE LA FENÊTRE*/

#define WIDTH 60
#define HEIGHT 50

/*INITIALISATION DU JEU*/
void init_jeu(Point *snake,int *snake_l,Point*n,enum Direction *dir){
    *snake_l = 1;
    snake[0].x=WIDTH/2;
    snake[0].y=HEIGHT/2;
    snake[1].x=snake[0].x-1;
    snake[1].y=snake[0].y;
    snake[2].x=snake[1].x-1;
    snake[2].y=snake[0].y;

    *dir=DROITE;
    /*generation de la nourriture de maniere aleatoire*/
    srand(time(0));
    n -> x = rand()%(WIDTH - 2);
    n -> y = rand()%(HEIGHT - 2);
}
/*AFFICHAGE DE LA CONSOLE DE JEU(BORDURE ETC)*/
void CONSOLE(Point *snake,int snake_l,Point n){
    clear();
    //bordures
    for(int i =0;i<WIDTH;i++){
        mvprintw(0,i,"#");
        mvprintw(HEIGHT-1,i,"#");

    }
    for(int i=0;i<HEIGHT;i++){
        mvprintw(i,0,"#");
        mvprintw(i,WIDTH-1,"#");
      
    }
    //serpent
    for(int i =0;i<snake_l;i++){
        mvprintw(snake[i].y,snake[i].x,"@");
        refresh();
    }
    //nouriture
    mvprintw(n.x,n.y,"X");
    refresh();
}
/*verif si serpent se mord*/
int collision(Point *snake,int snake_l){
    for(int i=1;i<snake_l;i++){ 
     if(snake[0].x == snake[i].x && snake[0].y==snake[i].y){return 1 ;/*collision*/}
  }
  return 0;
}
/*direction*/
void direction_s(Point *snake,int *snake_l,Point *n,enum Direction dir){
      /*corp_dep*/
      Point ntail=snake[*snake_l - 1];
      for(int i=*snake_l;i>0;i--){
        snake[i]=snake[i-1];
      }
      /*tete_dep*/
      switch(dir){
        case HAUT:snake[0].y--;break;
        case BAS:snake[0].y++;break;
        case GAUCHE:snake[0].x--;break;
        case DROITE:snake[0].x++;break;
      }
      /*verif serpent mange*/
      if(snake[0].x == n->x && snake[0].y== n->y){
        (*snake_l)++;
        snake[*snake_l +1]=ntail;
     
      //nouvelle nourriture
      n->x =rand()%(WIDTH-2);
      n->y =rand()%(HEIGHT-2);
          }
 }


