#include "game.h"
#include "mino.h"


void mino_display(Game *g, Type t, int l, int c)
{
  int i;
  int j;
  int z;
  
  //Conditionnement en fonction du type de tetrimino
  if(t==0)// I
    {
      Color *color_I;

      //Allocation de mémoire
      color_I = calloc(31,sizeof(Color));

      //Teste si la mémoire à bien été alloué.
      if(!color_I)
	return;

      //On remplir les pointeur de couleur, du plus claire au plus sombre
      for(i=0;i<30;i++)// 255/30=8.5
	{
	  //Cyan
	  color_I[i].r=0;
	  color_I[i].g=255-(i*8.5);
	  color_I[i].b=255-(i*8.5);
	}
      //On dessine le mino
      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_I[i].r,color_I[i].g,color_I[i].b,255);
	  //Les ligne horizontal
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+j,l*30+i);
	    }
	  //Les lignes verticale
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+i,l*30+z);
	    }

	}
      SDL_RenderPresent(g->ren);
    }
  else if(t==1)//J
    {
      Color *color_J;
      color_J = calloc(31,sizeof(Color));
      if(!color_J)
	return;

      for(i=0;i<30;i++)// 255/30=8.5
	{
	  //Bleu
	  color_J[i].r=0;
	  color_J[i].g=0;
	  color_J[i].b=255-i*8.5;
	}
      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_J[i].r,color_J[i].g,color_J[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+j,l*30+i);
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+i,l*30+z);
	    }
	    
	}
      SDL_RenderPresent(g->ren);
    }
  else if(t==2)//L
    {
      Color *color_L;
      color_L = calloc(31,sizeof(Color));
      if(!color_L)
	return;

      for(i=0;i<30;i++)// 255/30=8.5
	{
	  //Orange
	  color_L[i].r=255-i*8.5;
	  color_L[i].g=165.75-i*5.525;
	  color_L[i].b=0;
	}

      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_L[i].r,color_L[i].g,color_L[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+j,l*30+i);
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+i,l*30+z);
	    }
	    
	}
      SDL_RenderPresent(g->ren);
    }
  else if(t==3)//O
    {
      Color *color_O;
      color_O = calloc(31,sizeof(Color));
      if(!color_O)
	return;

      for(i=0;i<30;i++)// 255/30=8.5
	{
	  //Jaune
	  color_O[i].r=255-i*8.5;
	  color_O[i].g=255-i*8.5;
	  color_O[i].b=0;
	}

      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_O[i].r,color_O[i].g,color_O[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+j,l*30+i);
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+i,l*30+z);
	    }
	    
	}
      SDL_RenderPresent(g->ren);
    }
  else if(t==4)//S
    {
      Color *color_S;
      color_S = calloc(31,sizeof(Color));
      if(!color_S)
	return;

      for(i=0;i<30;i++)// 255/30=8.5
	{
	  //Vert
	  color_S[i].r=0;
	  color_S[i].g=127.5-i*4.25;
	  color_S[i].b=0;
	}

      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_S[i].r,color_S[i].g,color_S[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+j,l*30+i);
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+i,l*30+z);
	    }
	    
	}
      SDL_RenderPresent(g->ren);
    }
  else if(t==5)//T
    {
      Color *color_T;
      color_T = calloc(31,sizeof(Color));
      if(!color_T)
	return;

      for(i=0;i<30;i++)// 255/30=8.5
	{
	  //Violet
	  color_T[i].r=237.15-i*7.905;
	  color_T[i].g=130.05-i*4.335;
	  color_T[i].b=237.15-i*7.905;
	}

      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_T[i].r,color_T[i].g,color_T[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+j,l*30+i);
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+i,l*30+z);
	    }
	    
	}
      SDL_RenderPresent(g->ren);
    }
  else if(t==6)//Z
    {
      Color *color_Z;
      color_Z = calloc(31,sizeof(Color));
      if(!color_Z)
	return;

      for(i=0;i<30;i++)// 255/30=8.5
	{
	  //Rouge
	  color_Z[i].r=255-i*8.5;
	  color_Z[i].g=0;
	  color_Z[i].b=0;
	}

      for(i=0;i<30;i++)
	{
	  SDL_SetRenderDrawColor(g->ren,color_Z[i].r,color_Z[i].g,color_Z[i].b,255);
	  for(j=i;j<30;j++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+j,l*30+i);
	    }
	  for(z=i+1;z<30;z++)
	    {
	      SDL_RenderDrawPoint(g->ren,c*30+i,l*30+z);
	    }
	    
	}
      SDL_RenderPresent(g->ren);
    }
}
