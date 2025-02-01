#include "game.h"

int main(int argc, char *argv[])
{
  // Initialisation de la SDL qui est obligatoire pour utiliser la SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      //Gérer l'erreur
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      return 0;
    }
  //Initialisation de la bibliothèque TTF
  if(TTF_Init() < 0)
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      return 0;
    }
    
  Game *g;
  // Ces deux variable donne la position x et y du coin supérieur gauche de la fêtre
  int pos_x = SDL_WINDOWPOS_CENTERED;
  int pos_y = SDL_WINDOWPOS_CENTERED;
  
  g = game_new(pos_x, pos_y);
  
  if (!g)
    return 1;


      game_run(g);
  
      game_del(g);

  return 0;

  (void)argc;
  (void)argv;
}
