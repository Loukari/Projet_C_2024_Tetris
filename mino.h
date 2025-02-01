#ifndef MINO_H
#define MINO_H

//Définition du strucutre Color afin d'affecter les couleurs à chaques pixels
typedef struct Color
{
  char r;
  char g;
  char b;
}Color;

void mino_display(Game *g, Type t, int l, int c);

#endif
