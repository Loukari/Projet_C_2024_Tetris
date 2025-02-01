#ifndef GAME_H
#define GAME_H
#include "tetris.h"

typedef struct
{
  //Texture pour écrire "score", "nbr_lines" et "level"
  SDL_Texture *tex_s;
  SDL_Texture *tex_l;
  SDL_Texture *tex_nl;
  
  SDL_Window *win;
  SDL_Renderer *ren;
  TTF_Font *font;
  
  Tetris *tet;
  
  int tet_offset_x;
  int tet_offset_y;
  int mino_size;
  
  Uint64 freq;
  Uint64 count;
} Game;

//Affichage du jeu
static void game_board_update(Game *g);

//Création d'une nouvelle partie
Game *game_new(int x, int y);

//Boucle infini contenant également les différent évènement du jeux
void game_run(Game *g);

//Libération de la mémoire, quite SDL et TTF
void game_del(Game *g);

#endif
