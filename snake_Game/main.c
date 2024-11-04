# include <stdio.h>
# include <ncurses.h>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
#include "fonction.h"
/*DEFINITION DE LA FENÊTRE*/

 


int main(){
    Point snake[100];//taille max du serpent
    int snake_l;
    Point n;
    enum Direction dir;
    int GAME_OVER=0;
    /*initialisation de la fenêtre ncurses :-)*/
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    keypad(stdscr,TRUE);
    timeout(100);//vitesse du jeu
    /*fin init_f*/
    //====================================

    /*initialisation du jeu*/
    init_jeu(snake,&snake_l,&n,&dir);
    while(!GAME_OVER){
        CONSOLE(snake,snake_l,n);
        //lecture des touche
         int ch =getch();
         switch(ch){
            case KEY_UP:if(dir !=BAS) dir=HAUT;break;
            case KEY_DOWN:if(dir !=HAUT) dir=BAS;break;
            case KEY_LEFT:if(dir !=DROITE) dir=GAUCHE;break;
            case KEY_RIGHT:if(dir !=GAUCHE) dir=DROITE;break;
         }
         direction_s(snake,&snake_l,&n,dir);
         if(snake[0].x<=0 ||snake[0].x>=WIDTH-1|| snake[0].y<=0||snake[0].y>=HEIGHT-1||collision(snake,snake_l)){
            GAME_OVER =1;
         }
         usleep(100);
    } 
    clear();
    mvprintw(HEIGHT/2,WIDTH/2 -5,"GAME OVER! :-)");
     usleep(10000);
    refresh();
    getch();
    
    /*fin init_jeu*/
// FIN NCURSES
endwin();
    return 0;
}
