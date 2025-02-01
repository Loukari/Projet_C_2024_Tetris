#include "tetris.h"

char tetriminos[7][4][5][5]={
  {/*Tetrimino I*/
    {/*Rotation 0 */
      {'0','0','0','0','0'},
      {'0','0','0','0','0'},
      {'0','1','1','1','1'},
      {'0','0','0','0','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 1*/
      {'0','0','0','0','0'},
      {'0','0','1','0','0'},
      {'0','0','1','0','0'},
      {'0','0','1','0','0'},
      {'0','0','1','0','0'}
    },
    {/*Rotation 2*/
      {'0','0','0','0','0'},
      {'0','0','0','0','0'},
      {'1','1','1','1','0'},
      {'0','0','0','0','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 3*/
      {'0','0','1','0','0'},
      {'0','0','1','0','0'},
      {'0','0','1','0','0'},
      {'0','0','1','0','0'},
      {'0','0','0','0','0'}
    }
  },
  {/*Tetrimino J*/
    {/*Rotation 0 */
      {'0','0','0','0','0'},
      {'0','1','0','0','0'},
      {'0','1','1','1','0'},
      {'0','0','0','0','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 1*/
      {'0','0','0','0','0'},
      {'0','0','1','1','0'},
      {'0','0','1','0','0'},
      {'0','0','1','0','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 2*/
      {'0','0','0','0','0'},
      {'0','0','0','0','0'},
      {'0','1','1','1','0'},
      {'0','0','0','1','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 3*/
      {'0','0','0','0','0'},
      {'0','0','1','0','0'},
      {'0','0','1','0','0'},
      {'0','1','1','0','0'},
      {'0','0','0','0','0'}
    }
  },
  {/*Tetrimino L*/
    {/*Rotation 0*/
      {'0','0','0','0','0'},
      {'0','0','0','1','0'},
      {'0','1','1','1','0'},
      {'0','0','0','0','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 1 */
      {'0','0','0','0','0'},
      {'0','0','1','0','0'},
      {'0','0','1','0','0'},
      {'0','0','1','1','0'},
      {'0','0','0','0','0'}
    },
    {/*rotation 2 */
      {'0','0','0','0','0'},
      {'0','0','0','0','0'},
      {'0','1','1','1','0'},
      {'0','1','0','0','0'},
      {'0','0','0','0','0'}
    },
    {/* Rotation 3 */
      {'0','0','0','0','0'},
      {'0','1','1','0','0'},
      {'0','0','1','0','0'},
      {'0','0','1','0','0'},
      {'0','0','0','0','0'}
    }
  },
  {/*Tetrimino O */
    {/* Rotation 0 */
      {'0','0','0','0','0'},
      {'0','0','0','0','0'},
      {'0','0','1','1','0'},
      {'0','0','1','1','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 1 */
      {'0','0','0','0','0'},
      {'0','0','0','0','0'},
      {'0','0','1','1','0'},
      {'0','0','1','1','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 2 */
      {'0','0','0','0','0'},
      {'0','0','0','0','0'},
      {'0','0','1','1','0'},
      {'0','0','1','1','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 3 */
      {'0','0','0','0','0'},
      {'0','0','0','0','0'},
      {'0','0','1','1','0'},
      {'0','0','1','1','0'},
      {'0','0','0','0','0'}
    },
  },
  {/* Tetrimino S */
    {/* Rotation 0*/
      {'0','0','0','0','0'},
      {'0','0','1','1','0'},
      {'0','1','1','0','0'},
      {'0','0','0','0','0'},
      {'0','0','0','0','0'}
    },
    {/* Rotation 1*/
      {'0','0','0','0','0'},
      {'0','0','1','0','0'},
      {'0','0','1','1','0'},
      {'0','0','0','1','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 2*/
      {'0','0','0','0','0'},
      {'0','0','0','0','0'},
      {'0','0','1','1','0'},
      {'0','1','1','0','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 3 */
      {'0','0','0','0','0'},
      {'0','1','0','0','0'},
      {'0','1','1','0','0'},
      {'0','0','1','0','0'},
      {'0','0','0','0','0'}
    }
  },
  {/*Tetrimino T */
    {/* Rotation 0 */
      {'0','0','0','0','0'},
      {'0','0','1','0','0'},
      {'0','1','1','1','0'},
      {'0','0','0','0','0'},
      {'0','0','0','0','0'}
    },
    {/* Rotation 1 */
      {'0','0','0','0','0'},
      {'0','0','1','0','0'},
      {'0','0','1','1','0'},
      {'0','0','1','0','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 2 */
      {'0','0','0','0','0'},
      {'0','0','0','0','0'},
      {'0','1','1','1','0'},
      {'0','0','1','0','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 3 */
      {'0','0','0','0','0'},
      {'0','0','1','0','0'},
      {'0','1','1','0','0'},
      {'0','0','1','0','0'},
      {'0','0','0','0','0'}
    }
  },
  {/* Tetrimino Z */
    {/* Rotation 0 */
      {'0','0','0','0','0'},
      {'0','1','1','0','0'},
      {'0','0','1','1','0'},
      {'0','0','0','0','0'},
      {'0','0','0','0','0'}
    },
    {/*Rotation 1 */
      {'0','0','0','0','0'},
      {'0','0','0','1','0'},
      {'0','0','1','1','0'},
      {'0','0','1','0','0'},
      {'0','0','0','0','0'}
    },
    {/* Rotation 2 */
      {'0','0','0','0','0'},
      {'0','0','0','0','0'},
      {'0','1','1','0','0'},
      {'0','0','1','1','0'},
      {'0','0','0','0','0'}
    },
    {/* Rotation 3 */
      {'0','0','0','0','0'},
      {'0','0','1','0','0'},
      {'0','1','1','0','0'},
      {'0','1','0','0','0'},
      {'0','0','0','0','0'}
    }
  }
};



float tab2[15]={1.0,0.793,0.618,0.473,0.355,0.262,0.190,0.135,0.094,0.064,0.043,0.028,0.0018,0.011,0.007};


//Initialisation d'un générateur d'aléatoire
void init_alea()
{
  srand(time(NULL));
}

//Renvoie un nombre aléatoire entre 0 et 6.
int alea()
{
  return rand()%7;;
}

//Initialisation d'un nouveau jeux
Tetris *tetris_new()
{
  Tetris *t;
  int i;
  int j;

  //Allocation dans la mémoire
  t=malloc(sizeof(Tetris));
  if(t==NULL)
    return NULL;

  //Remplissage du buffer et de la matrice de '0'.
  for (i=0;i<20;i++)
    {
      for(j=0;j<10;j++)
	{
	  t->matrix[i][j]='0';
	  t->buffer[i][j]='0';
	}
    }

  //Choix d'un premier type aléatoire
  t->current_type=alea();

  //Positionnement sur la premiere ligne en fonction du type
  if(t->current_type==0||t->current_type==3)
    {
      t->current_line=0;
    }
  else
    {
      t->current_line=1;
    }

  //Posistionnement sur le colonne 4 pour centrer le tetrimino
  t->current_column=4;


  t->current_rotation=0;

  t->next_type=alea();

  t->level=1;
  t->score=0;
  t->nbr_lines=0;

  for(i=0;i<15;i++)
    {
      //Remplir le tableau par des valeurs prédéfinies est plus intéressant que de faire les calcules pour des questions de vitesse.
      t->drop_speed[i]=tab2[i];
    }
  return t;
}
  
void tetris_del(Tetris *tet)
{
  free(tet);
}

/* met en place le nouveau tetrimino */
void tetris_reset(Tetris *tet)
{
  int i;
  int j;

  tet->current_type=tet->next_type;
  tet->next_type=alea();
  tet->current_column=4;
  tet->current_rotation=0;

  //Remise du buffer à '0'
  for (i=0;i<20;i++)
    {
      for(j=0;j<10;j++)
	{
	  tet->buffer[i][j]='0';
	}
    }

  //Positionnement du tetrimino dans le buffer en fonction de son type
  if(tet->current_type==0||tet->current_type==3)
    {
      tet->current_line=0;
      for(i=2;i<=4;i++)
	{
	  for(j=0;j<=4;j++)
	    {
	      tet->buffer[i-2][j+2]=tetriminos[tet->current_type][tet->current_rotation][i][j];
	    }
	}
    }
  else
    {
      tet->current_line=1;
      for(i=1;i<=4;i++)
	{
	  for(j=0;j<=4;j++)
	    {
	      tet->buffer[i-1][j+2]=tetriminos[tet->current_type][tet->current_rotation][i][j];
	    }
	}
    }
}


int tetris_can_go_left(Tetris *tet)
{
  int i;
  int j;

  for(i=0;i<5;i++)
    {
      for(j=0;j<5;j++)
	{
	  //On cherche les case remplis par tetrimino
	  if(tetriminos[tet->current_type][tet->current_rotation][i][j] == '1')
	    {
	      //ici on teste si la colonne à gauche du mino est toujours dans le tableau et on teste si la case à gauche du mino est remplis ou non
	      //le calcule "current_column + j - 2" nous permet d'avoir la position du mino
	      if(tet->current_column + j-3 <0 || tet->matrix[tet->current_line + i -2][tet->current_column + j-3] == '1')
		return 0;
	    }
	}
    }
  return 1;
}


int tetris_can_go_right(Tetris *tet)
{
  int i;
  int j;

  for(i=0;i<5;i++)
    {
      for(j=0;j<5;j++)
	{
	  if(tetriminos[tet->current_type][tet->current_rotation][i][j] == '1')
	    {
	      if((tet->current_column + j - 1 >=10) || (tet->matrix[tet->current_line +i -2][tet->current_column + j -1] == '1'))
		return 0;
	    }
	}
    }
  return 1;
}

int tetris_can_rotate_h(Tetris *tet)
{
  int i;
  int j;

  for(i=0;i<5;i++)
    {
      for(j=0;j<5;j++)
	{
	  /* Teste spécifique pour revenir à la rotation 0 */
	  if(tet->current_rotation + 1 == 4)
	    {
	      if(tetriminos[tet->current_type][0][i][j]=='1')
		{
		  //On teste si des minos bloquent la rotation, ou si le tetrimino dépasse les limites du jeux.
		  if(tet->matrix[tet->current_line +i -2][tet->current_column + j -2]=='1' ||tet->current_column +j-2 < 0 || tet->current_column+j-2>=10 || tet->current_line +i-2 >=20 ||tet->current_line +i-2 <0 )
		    return 0;
		}
	    }
	
	      
	  else if(tetriminos[tet->current_type][tet->current_rotation+1][i][j]=='1')
	    {
	      if(tet->matrix[tet->current_line +i -2][tet->current_column + j -2]=='1' ||tet->current_column +j-2 < 0 || tet->current_column+j-2>=10 || tet->current_line +i-2 >=20 ||tet->current_line +i-2 <0 )
		return 0;
	    }
	}
    }
  return 1;
}

//Même fonction que la rotation horaire mais dans le sense anti-horaire.
int tetris_can_rotate_ah(Tetris *tet)
{
  int i;
  int j;

  for(i=0;i<5;i++)
    {
      for(j=0;j<5;j++)
	{
	  if(tet->current_rotation - 1 == -1)
	    {
	      if(tetriminos[tet->current_type][3][i][j]=='1')
		{
		  if(tet->matrix[tet->current_line +i -2][tet->current_column + j -2]=='1' ||tet->current_column +j-2 < 0 || tet->current_column+j-2>=10 || tet->current_line +i-2 >=20||tet->current_line +i-2 <0 )
		    return 0;
		}
	    }
	      
	  if(tetriminos[tet->current_type][tet->current_rotation-1][i][j]=='1')
	    {
	      if(tet->matrix[tet->current_line +i -2][tet->current_column + j -2]=='1' ||tet->current_column +j-2 < 0 || tet->current_column+j-2>=10 || tet->current_line +i-2 >=20||tet->current_line +i-2 <0 )
		return 0;
	    }
	}
    }
  return 1;
}

int tetris_can_go_down(Tetris *tet)
{
  int i;
  int j;

  for(i=0;i<5;i++)
    {
      for(j=0;j<5;j++)
	{
	  if(tetriminos[tet->current_type][tet->current_rotation][i][j]=='1')
	    {
	      //On teste si un mino est en dessous du tetrimino ou si le tetrimino dépasse le terrain.
	      if((tet->current_line + i -1 >= 20)  || (tet->matrix[tet->current_line +i -1][tet->current_column + j -2]=='1'))
		return 0;
	    }
	}
    }
  return 1;
}

double tetris_get_drop_speed(Tetris *tet)
{
  return pow(0.8-((tet->level -1)*0.007),tet->level -1);
}

//Permet de sauvegarder le tetrimino dans la matrice.
void tetris_matrix_update(Tetris *tet)
{
  int i;
  int j;
  for(i=0;i<5;i++)
    {
      for(j=0;j<5;j++)
	{
	  if(tetriminos[tet->current_type][tet->current_rotation][i][j]=='1')
	    {
	      tet->matrix[tet->current_line+i-2][tet->current_column+j-2]=tetriminos[tet->current_type][tet->current_rotation][i][j];
	    }
	}
    }
}


//Permet de faire descendre les lignes supérieurs, à l'issue d'une élimination de ligne.
void tetris_shift_board(Tetris *tet)
{
  int i;
  int j;
  int k;
  int count;
 
for(i=0;i<20;i++)
  {
    count=0;
    for(j=0;j<10;j++)
	{
	  if(tet->matrix[i][j]=='1')
	    {
	      count+=1;
	    }
	}
    //Teste si une ligne est complis
      if(count == 10)
	{
	  //Remplit la ligne de '0'
	  for(j=0;j<10;j++)
	    {
	      tet->matrix[i][j]='0';
	    }
	  //Parcourt le tableau de bas en haut
	  for(k=i;k>0;k--)
	    {
	      //Colonne par colonne
	      for(j=0;j<10;j++)
		{
		  //Affecte la ligne du dessus à la ligne du dessous
		  tet->matrix[k][j]=tet->matrix[k-1][j];
		}
	    }
	  //Necessaire dans le cas ou la premiers ligne est remplis de mino.
	  //Car la ligne 0 n'est pas affécté à la ligne 1;
	  for(j=0;j<10;j++)
	    {
	      tet->matrix[0][j]='0';
	    }
	}
    }
}
