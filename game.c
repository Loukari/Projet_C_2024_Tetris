#include "game.h"
#include "mino.h"

static int update =1;

static void game_board_update(Game *g)
{
  int i;
  int j;
  int z;

  SDL_SetRenderDrawColor(g->ren, 0x2b, 0x2a, 0x33, 0xff);
  SDL_RenderClear(g->ren);
  

  /* TODO : afficher le plateau de jeu */
  
  // Colorer le fond du plateau en noir
  SDL_Color black = {0,0,0,255};
  SDL_SetRenderDrawColor(g->ren,black.r,black.g,black.b,black.a);
  SDL_RenderClear(g->ren);

  /*Bordure du plateau de jeux*/
  SDL_Color orange = {255,165.75,0,255};
  SDL_SetRenderDrawColor(g->ren,orange.r,orange.g,orange.b,orange.a);
  SDL_RenderDrawLine(g->ren,300,600,300,0);

  //Dessine un rectangle en haut à droite
  SDL_SetRenderDrawColor(g->ren,orange.r,orange.g,orange.b,orange.a);
  SDL_Rect r={330,30,151,151};
  SDL_RenderDrawRect(g->ren,&r);


  /* static int save_type; */
  /* if(g->tet->current_type == 0) */
  /*   { */
  /*     save_type=0; */
  /*   } */
  /* else if (g->tet->current_type == 1) */
  /*   { */
  /*     save_type=1; */
  /*   } */
  /* else if (g->tet->current_type == 2) */
  /*   { */
  /*     save_type=2; */
  /*   } */
  /* else if (g->tet->current_type == 3) */
  /*   { */
  /*     save_type=3; */
  /*   } */
  /* else if (g->tet->current_type == 4) */
  /*   { */
  /*     save_type=4; */
  /*   } */
  /* else if (g->tet->current_type ==5) */
  /*   { */
  /*     save_type=5; */
  /*   } */
  /* else if (g->tet->current_type == 6) */
  /*   { */
  /*     save_type=6; */
  /*   } */

  //Affichage des minos dans le plateau de jeux pour avoir un visuel de la matrix.
  for(i=0;i<20;i++)
    {
      for(j=0;j<10;j++)
	{
	  if(g->tet->matrix[i][j]=='1')
	    {
	      mino_display(g,g->tet->current_type,i,j);
	    }
	}
    }

  //Affichage du tetrimino actuelle, qui est  présent dans le buffer. 
  if(g->tet->current_type==0)
    {//Tetrimino I
      if(g->tet->current_rotation==0)
	{//Rotation 0
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+2);
	}
      else if(g->tet->current_rotation==1)
	{//Rotation 1
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+2,g->tet->current_column);
	}
      else if(g->tet->current_rotation==2)
	{//Rotation 2
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-2);
	}
      else if(g->tet->current_rotation==3)
	{//Rotation 3
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line-2,g->tet->current_column);
	}
    }
  else if(g->tet->current_type==1)
    {//Tetrimino J
      if(g->tet->current_rotation==0)
	{//Rotation 0
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	}
      else if(g->tet->current_rotation==1)
	{//Rotation 1
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column+1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	}
      else if(g->tet->current_rotation==2)
	{//Rotation 2
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column+1);
	}
      else if(g->tet->current_rotation==3)
	{//Rotation 3
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	}
    }
  else if(g->tet->current_type==2)
    {//Tetrimino L
      if (g->tet->current_rotation==0)
	{//Rotation 0
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column+1);
	}
      else if (g->tet->current_rotation==1)
	{//Rotation 1
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column+1);
	}
      else if (g->tet->current_rotation==2)
	{//Rotation 2
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column-1);
	}
      else if (g->tet->current_rotation==3)
	{//Rotation 3
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column-1);
	}
    }
  else if(g->tet->current_type==3)
    {//Tetrimino O, pour toutes les rotations
      mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
      mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
      mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
      mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column+1);
    }
  else if(g->tet->current_type==4)
    {//Tetrimino S
      if(g->tet->current_rotation==0)
	{//Rotation 0
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column+1);
	}
      else if(g->tet->current_rotation==1)
	{//Rotation 1
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column+1);
	}
      else if(g->tet->current_rotation==2)
	{//Rotation 2
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column-1);
	}
      else if(g->tet->current_rotation==3)
	{//Rotation 3
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column-1);
	}
    }
  else if(g->tet->current_type==5)
    {//Tetrimino T
      if(g->tet->current_rotation==0)
	{//Rotation 0
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	}
      else if(g->tet->current_rotation==1)
	{//Rotation 1
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	}
      else if(g->tet->current_rotation==2)
	{//Rotation 2
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	}
      else if(g->tet->current_rotation==3)
	{//Rotation 3
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	}
    }
  else if(g->tet->current_type==6)
    {//Tetrimino Z
      if(g->tet->current_rotation==0)
	{//Rotation 0
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	}
      else if (g->tet->current_rotation==1)
	{//Rotation 1
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column+1);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column+1);
	}
      else if (g->tet->current_rotation==2)
	{//Rotation 2
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column+1);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	}
      else if (g->tet->current_rotation==3)
	{//Rotation 3
	  mino_display(g,g->tet->current_type,g->tet->current_line-1,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column);
	  mino_display(g,g->tet->current_type,g->tet->current_line,g->tet->current_column-1);
	  mino_display(g,g->tet->current_type,g->tet->current_line+1,g->tet->current_column-1);
	}
    }

  
 
  /* TODO : afficher le prochain tetrimino */
  
  if(g->tet->next_type==0)
    {//I
      //Déclaration d'un variable Color qui point vers les valeur rouge, vert et bleu d'une couleur.
      Color *color_I;
      
      //Allocation de mémoir pour la variable couleur.
      color_I = calloc(31,sizeof(Color));

      //Teste si l'allocation c'est bien passé.
      if(!color_I)
	return;

      //Affectation de la couleur à la variable. Pour l'obtenir on calcule le pourcentage de 255 et on soustrait par i*8.5 pour avoir 30 couleur différente. 30 pour le nombre de pixel.
      for(i=0;i<30;i++)// 255/30=8.5
	{
	  color_I[i].r=0;
	  color_I[i].g=255-(i*8.5);
	  color_I[i].b=255-(i*8.5);
	}

      //Affichage de chaque mino, en haut à droite, en fonction de leur position en pixel.
      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_I[i].r,color_I[i].g,color_I[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,360+j,90+i);
	      SDL_RenderDrawPoint(g->ren,390+j,90+i);
	      SDL_RenderDrawPoint(g->ren,420+j,90+i);
	      SDL_RenderDrawPoint(g->ren,450+j,90+i);
	      
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,360+i,90+z);
	      SDL_RenderDrawPoint(g->ren,390+i,90+z);
	      SDL_RenderDrawPoint(g->ren,420+i,90+z);
	      SDL_RenderDrawPoint(g->ren,450+i,90+z);
	    }

	}
    }
  else if(g->tet->next_type==1)
    {
      Color *color_J;
      color_J = calloc(31,sizeof(Color));
      if(!color_J)
	return;

      for(i=0;i<30;i++)
	{
	  color_J[i].r=0;
	  color_J[i].g=0;
	  color_J[i].b=255-i*8.5;
	}
      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_J[i].r,color_J[i].g,color_J[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,360+j,60+i);
	      SDL_RenderDrawPoint(g->ren,360+j,90+i);
	      SDL_RenderDrawPoint(g->ren,390+j,90+i);
	      SDL_RenderDrawPoint(g->ren,420+j,90+i);
	      
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,360+i,60+z);
	      SDL_RenderDrawPoint(g->ren,360+i,90+z);
	      SDL_RenderDrawPoint(g->ren,390+i,90+z);
	      SDL_RenderDrawPoint(g->ren,420+i,90+z);
	    }

	}
    }
  else if(g->tet->next_type==2)
    {
      Color *color_L;
      color_L = calloc(31,sizeof(Color));
      if(!color_L)
	return;

      for(i=0;i<30;i++)
	{
	  color_L[i].r=255-i*8.5;
	  color_L[i].g=165.75-i*5.525;
	  color_L[i].b=0;
	}
      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_L[i].r,color_L[i].g,color_L[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,360+j,90+i);
	      SDL_RenderDrawPoint(g->ren,390+j,90+i);
	      SDL_RenderDrawPoint(g->ren,420+j,90+i);
	      SDL_RenderDrawPoint(g->ren,420+j,60+i);
	      
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,360+i,90+z);
	      SDL_RenderDrawPoint(g->ren,390+i,90+z);
	      SDL_RenderDrawPoint(g->ren,420+i,90+z);
	      SDL_RenderDrawPoint(g->ren,420+i,60+z);
	    }

	}
    }
  else if(g->tet->next_type==3)
    {
      Color *color_O;
      color_O = calloc(31,sizeof(Color));
      if(!color_O)
	return;

      for(i=0;i<30;i++)
	{
	  color_O[i].r=255-i*8.5;
	  color_O[i].g=255-i*8.5;
	  color_O[i].b=0;
	}
      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_O[i].r,color_O[i].g,color_O[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,390+j,90+i);
	      SDL_RenderDrawPoint(g->ren,420+j,90+i);
	      SDL_RenderDrawPoint(g->ren,390+j,120+i);
	      SDL_RenderDrawPoint(g->ren,420+j,120+i);
	      
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,390+i,90+z);
	      SDL_RenderDrawPoint(g->ren,420+i,90+z);
	      SDL_RenderDrawPoint(g->ren,390+i,120+z);
	      SDL_RenderDrawPoint(g->ren,420+i,120+z);
	    }
	}
      
    }
  else if(g->tet->next_type==4)
    {
      Color *color_S;
      color_S = calloc(31,sizeof(Color));
      if(!color_S)
	return;

      for(i=0;i<30;i++)
	{
	  color_S[i].r=0;
	  color_S[i].g=127.5-i*4.25;
	  color_S[i].b=0;
	}
      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_S[i].r,color_S[i].g,color_S[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,360+j,90+i);
	      SDL_RenderDrawPoint(g->ren,390+j,90+i);
	      SDL_RenderDrawPoint(g->ren,390+j,60+i);
	      SDL_RenderDrawPoint(g->ren,420+j,60+i);
	      
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,360+i,90+z);
	      SDL_RenderDrawPoint(g->ren,390+i,90+z);
	      SDL_RenderDrawPoint(g->ren,390+i,60+z);
	      SDL_RenderDrawPoint(g->ren,420+i,60+z);
	    }
	}
    }
  else if(g->tet->next_type==5)
    {
      Color *color_T;
      color_T = calloc(31,sizeof(Color));
      if(!color_T)
	return;

      for(i=0;i<30;i++)
	{
	  color_T[i].r=237.15-i*7.905;
	  color_T[i].g=130.05-i*4.335;
	  color_T[i].b=237.15-i*7.905;
	}
      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_T[i].r,color_T[i].g,color_T[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,360+j,90+i);
	      SDL_RenderDrawPoint(g->ren,390+j,90+i);
	      SDL_RenderDrawPoint(g->ren,390+j,60+i);
	      SDL_RenderDrawPoint(g->ren,420+j,90+i);
	      
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,360+i,90+z);
	      SDL_RenderDrawPoint(g->ren,390+i,90+z);
	      SDL_RenderDrawPoint(g->ren,390+i,60+z);
	      SDL_RenderDrawPoint(g->ren,420+i,90+z);
	    }
	}
      
    }
  else if(g->tet->next_type==6)
    {
      Color *color_Z;
      color_Z = calloc(31,sizeof(Color));
      if(!color_Z)
	return;

      for(i=0;i<30;i++)
	{
	  color_Z[i].r=255-i*8.5;
	  color_Z[i].g=0;
	  color_Z[i].b=0;
	}
      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_Z[i].r,color_Z[i].g,color_Z[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,360+j,60+i);
	      SDL_RenderDrawPoint(g->ren,390+j,60+i);
	      SDL_RenderDrawPoint(g->ren,390+j,90+i);
	      SDL_RenderDrawPoint(g->ren,420+j,90+i);
	      
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,360+i,60+z);
	      SDL_RenderDrawPoint(g->ren,390+i,60+z);
	      SDL_RenderDrawPoint(g->ren,390+i,90+z);
	      SDL_RenderDrawPoint(g->ren,420+i,90+z);
	    }
	}
    }

  
  /* TODO : afficher le score, le niveau et le nombre de lignes eliminees */

  //Déclaration cnécessaire:
  //Variable de la donnée
  int score = g->tet->score;
  //Tableau contenant la donnée
  char buffer_s[20]={'\0'};
  
  int level = g->tet->level;
  char buffer_l[2]={'\0'};
  
  int nbr_lines = g->tet->nbr_lines;
  char buffer_nl[10]={'\0'};

  //Tableau contenant la donnée et un texte
  char final_buffer_s[26]={'\0'};
  char final_buffer_l[8]={'\0'};
  char final_buffer_nl[20]={'\0'};

  // Ici on déclare des surfaces qui permetrons d'écrire le texte,
  // à l'aide de la fonction TTF_RenderText_Solid().
  SDL_Surface * text_s= NULL;
  SDL_Surface * text_l= NULL;
  SDL_Surface * text_nl= NULL;

  //Ici nous déclarons des texture dans lesquelles seront copiées les surfaces.
  SDL_Texture * texture_s = NULL;
  SDL_Texture * texture_l = NULL;
  SDL_Texture * texture_nl = NULL;

  //Il s'agit ici de réctangle représentant la surface dans laquelle il y aura le texte.
  SDL_Rect rect_s = {300,210,210,30};
  SDL_Rect rect_l = {300,240,210,30};
  SDL_Rect rect_nl = {300,270,210,30};

  // On une couleur
  SDL_Color white = {255,255,255,255};  
  

  // Ici itoa transforme une valeur numérique en une chaine de carractère et on la mets dans le tableau.
  itoa(score,buffer_s,10);
  itoa(level,buffer_l,10);
  itoa(nbr_lines,buffer_nl,10);

  //Avec strcpy on copie "score:" dans le buffer final.
  strcpy(final_buffer_s,"Score:");
  //Avec strcat on concatène les tableau de carractère.
  strcat(final_buffer_s,buffer_s);
  
  strcpy(final_buffer_l,"level:");
  strcat(final_buffer_l,buffer_l);
  
  strcpy(final_buffer_nl,"nbr_lines:");
  strcat(final_buffer_nl,buffer_nl);

  
  //Ici on "met" dans la surface les chaine de caractère et on teste l'erreur.
  text_s = TTF_RenderText_Solid(g->font, final_buffer_s,white);
  if(!text_s)
    {
      //En cas d'erreur on libert toutes les allocation de mémoire.
      SDL_FreeSurface(text_s);
      TTF_CloseFont(g->font);
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      SDL_DestroyRenderer(g->ren);
      SDL_DestroyWindow(g->win);
      TTF_Quit();
      SDL_Quit();
      return;
    }

  text_l = TTF_RenderText_Solid(g->font, final_buffer_l,white);
  if(!text_l)
    {
      SDL_FreeSurface(text_l);
      TTF_CloseFont(g->font);
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      SDL_DestroyRenderer(g->ren);
      SDL_DestroyWindow(g->win);
      TTF_Quit();
      SDL_Quit();
      return;
    }

  text_nl = TTF_RenderText_Solid(g->font, final_buffer_nl,white);
  if(!text_nl)
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      SDL_FreeSurface(text_nl);
      TTF_CloseFont(g->font);
      SDL_DestroyRenderer(g->ren);
      SDL_DestroyWindow(g->win);
      TTF_Quit();
      SDL_Quit();
      return;
    }

  //Ensuite on créer des texture à partir des surface, car la texture nous permetra d'avoir l'affichage souhaité.
  texture_s = SDL_CreateTextureFromSurface(g->ren,text_s);
  SDL_FreeSurface(text_s);
  //On teste l'erreur.
  if((!texture_s) || (SDL_QueryTexture(texture_s,NULL,NULL,&rect_s.w,&rect_s.h) !=0) )
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      TTF_CloseFont(g->font);
      SDL_DestroyTexture(texture_s);
      SDL_DestroyRenderer(g->ren);
      SDL_DestroyWindow(g->win);
      TTF_Quit();
      SDL_Quit();
      return;
    }
     
  texture_l = SDL_CreateTextureFromSurface(g->ren,text_l);
  SDL_FreeSurface(text_l);
  if((!texture_l) || (SDL_QueryTexture(texture_l,NULL,NULL,&rect_l.w,&rect_l.h) !=0))
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      TTF_CloseFont(g->font);
      SDL_DestroyTexture(texture_l);
      SDL_DestroyRenderer(g->ren);
      SDL_DestroyWindow(g->win);
      TTF_Quit();
      SDL_Quit();
      return;
    }
  
  texture_nl = SDL_CreateTextureFromSurface(g->ren,text_nl);
  SDL_FreeSurface(text_nl);
  if((!texture_nl) || (SDL_QueryTexture(texture_nl,NULL,NULL,&rect_nl.w,&rect_nl.h) !=0))
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      TTF_CloseFont(g->font);
      SDL_DestroyTexture(texture_nl);
      SDL_DestroyRenderer(g->ren);
      SDL_DestroyWindow(g->win);
      TTF_Quit();
      SDL_Quit();
      return;
    }

  //On va afficher le texte en associant la texture au renderer pour avoir un affichage.
  if (SDL_RenderCopy(g->ren, texture_s,NULL,&rect_s) != 0)
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      TTF_CloseFont(g->font);
      SDL_DestroyTexture(texture_s);
      SDL_DestroyTexture(texture_l);
      SDL_DestroyTexture(texture_nl);
      SDL_DestroyRenderer(g->ren);
      SDL_DestroyWindow(g->win);
      TTF_Quit();
      SDL_Quit();
      return;
    }
  
  if (SDL_RenderCopy(g->ren, texture_l,NULL,&rect_l) != 0)
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      TTF_CloseFont(g->font);
      SDL_DestroyTexture(texture_s);
      SDL_DestroyTexture(texture_l);
      SDL_DestroyTexture(texture_nl);
      SDL_DestroyRenderer(g->ren);
      SDL_DestroyWindow(g->win);
      TTF_Quit();
      SDL_Quit();
      return;
    }

  if (SDL_RenderCopy(g->ren, texture_nl,NULL,&rect_nl) != 0)
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      TTF_CloseFont(g->font);
      SDL_DestroyTexture(texture_s);
      SDL_DestroyTexture(texture_l);
      SDL_DestroyTexture(texture_nl);
      SDL_DestroyRenderer(g->ren);
      SDL_DestroyWindow(g->win);
      TTF_Quit();
      SDL_Quit();
      return;
    }

  //On affecte aux pointeur de texture les texture d'affichage.
  g->tex_s=texture_s;
  g->tex_l=texture_l;
  g->tex_nl=texture_nl;

  //On détruit les texture d'affichage inutile.
  SDL_DestroyTexture(texture_s);
  SDL_DestroyTexture(texture_l);
  SDL_DestroyTexture(texture_nl);

  //Affichage du résultat.
  SDL_RenderPresent(g->ren);

  update = 0;
  
}

Game *game_new(int x, int y)
{
  int w=510;
  int h=600;
  Game *g;
  g=malloc(sizeof(Game));

  if(!g)
    return NULL;

  //On affecte les textures à NULL, car elle ne sont utile que dans la fonction game_board_update.
  g->tex_s=NULL;
  g->tex_l=NULL;
  g->tex_nl=NULL;

  g->tet_offset_x=x;

  g->tet_offset_y=y;

  //Affectation d'un nouvelle fenêtre.
  g->win = SDL_CreateWindow("Tetris",g->tet_offset_x,g->tet_offset_y , w, h, SDL_WINDOW_SHOWN);
  //On teste l'erreur.
  if (!g->win)
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      SDL_Quit();
      TTF_Quit();
      return NULL;
    }
  
  //Affectation d'un renderer.
  g->ren = SDL_CreateRenderer(g->win, -1, SDL_RENDERER_ACCELERATED);
  if(!g->ren)
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      SDL_DestroyWindow(g->win);
      SDL_Quit();
      TTF_Quit();
      return NULL;
    }

  //Affectation de la bibliothèque "arial" à g->font
  g->font =  TTF_OpenFont("font/arial.ttf",25);
  if(!g->font)
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error : %s\n", SDL_GetError());
      TTF_CloseFont(g->font);
      TTF_Quit();
      SDL_Quit();
      return NULL;
    }
      

  g->tet = tetris_new();


  g->mino_size=30;

  //Permet d'avoir la valeur du conteur de haute résolution en seconde
  g->freq = SDL_GetPerformanceFrequency();
  //Permet d'avoir la valeur du conteur de haute résolution
  g->count = SDL_GetPerformanceCounter();
  
  return g;
}

void game_del(Game *g)
{
  //on libert toute la mémoire allouer par nos fonctions et on quite la TTF puis SDL.
  //l'ordre est important
  
  tetris_del(g->tet);
  
  SDL_DestroyTexture(g->tex_s);
  SDL_DestroyTexture(g->tex_l);
  SDL_DestroyTexture(g->tex_nl);

  TTF_CloseFont(g->font);
  
  SDL_DestroyRenderer(g->ren);
  
  SDL_DestroyWindow(g->win);
  
  free(g);

  TTF_Quit();

  SDL_Quit();
}
	

void game_run(Game *g)
{
  SDL_Event events;
  int running;
  int i;
  int j;

  running =1;

  while (running)
    {
      Uint64 c;

      while(SDL_PollEvent(&events))
	{
	  switch(events.type)
	    {
	    case SDL_QUIT:
	      {
		running =0;
		break;
	      }
	    case SDL_KEYDOWN:
	      {
		switch (events.key.keysym.sym)
		  {
		  case SDLK_q:
		    {
		      running = 0;
		      break;
		    }
		  case SDLK_ESCAPE:
		    {
		      running = 0;
		      break;
		    }
		  case SDLK_SPACE:
		    {
		      /*descendre immédiatement le tetrimino tout en bas et mettre à jour, si c'est possible. */
		      for(i=0;i<20;i++)
			{
			  if(tetris_can_go_down(g->tet)==1)
			    {
			      g->tet->current_line+=1;
			    }
			}
		      game_board_update(g);
		      break;
		    }
		  case SDLK_LEFT:
		    {
		      /* déplacer le tétrimino à gauche et mettre à jour, si c'est possible.*/
		      if(tetris_can_go_left(g->tet)==1)
			{
			  g->tet->current_column -= 1;
			  game_board_update(g);
			  break;
			}
		      else
			{
			  break;
			}
		    }
		  case SDLK_RIGHT:
		    {
		      /*déplacer le tétrimino à droite et mettre à jour, si c'est possible. */
		      if(tetris_can_go_right(g->tet)==1)
			{
			  g->tet->current_column += 1;
			  game_board_update(g);
			  break;
			}
		      else
			{
			  break;
			}
		    }
		  case SDLK_DOWN:
		    {
		      /* déscendre de une case le tétrimino et mettre à jour, si c'est possible. */
		      if(tetris_can_go_down(g->tet)==1)
			{
			  g->tet->current_line += 1;
			  game_board_update(g);
			  break;
			}
		      else
			{
			  break;
			}
		    }
		  case SDLK_UP:
		    {
		      /* faire pivoter le tétrimino dans le sens horaire et mettre à jour, si c'est possible. */
		      if(tetris_can_rotate_h(g->tet)==1)
			{
			  if(g->tet->current_rotation +1 == 4)
			    {
			      g->tet->current_rotation =0;
			    }
			  else
			    {
			      g->tet->current_rotation += 1;
			    }
			  game_board_update(g);
			  break;
			}
		      else
			{
			  break;
			}
		    }
		  case SDLK_n:
		    {
		      /* faire pivoter dans le sens anti_horaire et mettre à jour, si c'est possible. */
		      if(tetris_can_rotate_ah(g->tet)==1)
			{
			  if(g->tet->current_rotation -1 == -1)
			    {
			      g->tet->current_rotation =3;
			    }
			  else
			    {
			      g->tet->current_rotation -= 1;
			    }
			  game_board_update(g);
			  break;
			}
		      else
			{
			  break;
			}
		    }
		  }
		break;
	      }
	    }
	}
      c= SDL_GetPerformanceCounter();

      if (update)
	game_board_update(g);

      if ((float)(c - g->count)/g->freq > tetris_get_drop_speed(g->tet))
	{
	  g->count = c;
	  if (tetris_can_go_down(g->tet))
	    {
	      //Permet de faire desendre le tétriminos chaque seconde.
	      g->tet->current_line+=1;
	      game_board_update(g);
	    }

	  //Permet de mettre fin à la boucle infini et donc du jeux.
	  else if((!tetris_can_go_down(g->tet) && g->tet->current_line == 0) ||(!tetris_can_go_down(g->tet) && g->tet->current_line == 1))
	  {
	    running=0;
	  }

	  else
	    {
	      /*
	       * detecter si une ou plusieurs lignes doivent etre retirees
	       * si c’est le cas, mettre a jour le score, le niveau
	       * et le nombre de lignes
	       */
	      //Variable de contage
	      int count;
	      int count_lines=0;
	      int count_lvl=1;

	      //(Peut aider pour sauvegarder les couleur des tetriminos)
	      //Permet de sauvegarder les tetrimino dans matrix.
	      tetris_matrix_update(g->tet);

	      //Compte si un ligne est remplis de mino.
	      for(i=-2;i<=2;i++)
		{
		  count=0;
		  for(j=0;j<10;j++)
		    {
		      if(g->tet->matrix[g->tet->current_line-i][j] =='1')
			{
			  count+=1;
			  if(count==10)
			    count_lines+=1;
			}
		    }
		}
	      
	      if(count_lines==0)
		{
		  //Label vers la fin de la fonction
		  goto exit;
		}
	      //Si des lignes sont remplies
	      else if(count_lines!=0)
		{
		  //Mise à jour du score
		  if(count_lines == 1)
		    {
		      g->tet->score += 100*g->tet->level;
		    }
		  else if(count_lines == 2)
		    {
		      g->tet->score += 300*g->tet->level;
		    }
		  else if(count_lines == 3)
		    {
		      g->tet->score += 500*g->tet->level;
		    }
		  else if(count_lines == 4)
		    {
		      g->tet->score += 800*g->tet->level;
		    }
		  
		  //Mise à jour de nbr_lines
		  g->tet->nbr_lines += count_lines;
		  
		  //Boucle pour détécter le niveau
		  for(i=1;i<=15;i++)
		    {
		      if(g->tet->nbr_lines >= i*10)
			count_lvl+=1;
		    }
		  //Mise à jour du niveau
		  g->tet->level = count_lvl;
		}
	      
	      // actualisation du plateau de jeux après l'élimination des lignes
	      tetris_shift_board(g->tet);
	    exit:
	      /*nouveau tetrimino */
	      tetris_reset(g->tet);
	      game_board_update(g);
	    }
	}
    }
}


