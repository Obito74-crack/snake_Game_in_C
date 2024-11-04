#ifndef ___FONCTION__H__
#define ___FONCTION__H__
#define WIDTH 60
#define HEIGHT 50

/*DIRECTION ET CONTROLE DU SERPENT*/
enum Direction {HAUT,BAS,GAUCHE,DROITE};

/*position de l'objet serpent*/
struct point{
    int x;
    int y;
}point;
typedef struct point Point;

void init_jeu(Point *snake,int *snake_l,Point*n,enum Direction *dir);
void CONSOLE(Point *snake,int snake_l,Point n);
int collision(Point *snake,int snake_l);
void direction_s(Point *snake,int *snake_l,Point *n,enum Direction dir);

#endif
