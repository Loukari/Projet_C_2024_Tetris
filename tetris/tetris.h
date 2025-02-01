#ifndef TETRIS_H
#define TETRIS_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


typedef enum
  {
    TYPE_I,
    TYPE_J,
    TYPE_L,
    TYPE_O,
    TYPE_S,
    TYPE_T,
    TYPE_Z
  } Type;

typedef struct Tetris
{
  char matrix[20][10];
  char buffer[20][10];

  Type current_type;
  int current_line;
  int current_column;
  int current_rotation;

  Type next_type;

  int level;
  int score;
  int nbr_lines;
  float drop_speed[15]; /* in s*/
} Tetris;


/*crée la structure tétris pour une nouveau jeu */
Tetris *tetris_new();

/* libère les ressources */
void tetris_del(Tetris *tet);

/* met en place le nouveau tetrimino */
void tetris_reset(Tetris *tet);

/* tests des évènements du tetrimino */
int tetris_can_go_left(Tetris *tet);
int tetris_can_go_right(Tetris *tet);
int tetris_can_rotate_h(Tetris *tet);
int tetris_can_rotate_ah(Tetris *tet);
int tetris_can_go_down(Tetris *tet);

/*renvoie la vitesse de déscente du tétrimino */
double tetris_get_drop_speed(Tetris *tet);

/*Nombre aléatoire entre 0 et 7 */
int alea();

//Initialise un générateur d'aléatoire
void init_alea();

//Met le tetrimino dans la matrice
void tetris_matrix_update(Tetris *tet);

// Permet de mettre à jours le plateau de jeux avec les lines en détruites en moin
void tetris_shift_board(Tetris *tet);


#endif
