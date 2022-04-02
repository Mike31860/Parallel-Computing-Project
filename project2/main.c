#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int main(int argc, char *argv[])
{

  int players = 0;
  printf("Please add the number of players for the match:\n");
  scanf("%i", &players);
  // fgets(players, sizeof(players), stdin);
  printf("Players %i:\n", players);
  char size[256];
  printf("Please add the size of the table:\n");
  scanf("%s", &size);

  printf("Size %s:\n", size);

  Table *table = (Table *)malloc(sizeof(Table));
  printf("heigth %i weidth %i:\n", size[0], size[2]);

  table->height = 15;
  table->weidth = 15;

  char obstacules[256];
  printf("Please add the obstacules of the table:\n");

  scanf("%s", &obstacules);
  printf("OBSTACULES %s:\n", obstacules);

  char *obs = strtok(&obstacules, "");
  int i;

  int c = 0;
  char **arr = NULL;
  c = split(obs, '-', &arr);
  printf("found %d tokens.\n", c);
  // for (i = 0; i < c; i++)
  //    printf("string #%d: %s\n", i, arr[i]);

  int c2 = 0;
  char **scalars = NULL;
  c2 = split(arr[0], ',', &scalars);

   for (int j= 0; j < c2; j++)
      printf("Scalars #%d: %s\n", j, scalars[j]);

  int c3 = 0;
  char **snakes = NULL;
  c3 = split(arr[1], ',', &snakes);
   for (int m = 0; m < c3; m++)
     printf("Snakes #%d: %s\n", m, snakes[m]);

  printf("Size scalars: %i\n", sizeof scalars);
  printf("Size snakes: %i\n", sizeof snakes);
  for (int g = 0; g < 4; g++)
  {
    int l;
    int c4 = 0;
    char **xy = NULL;
    c4 = split(scalars[g], ':', &xy);
    //for (l = 0; l < c4; l++)
    //  printf("-------\n");
    insertObstacule(g, strtol(xy[0], NULL, 10), strtol(xy[1], NULL, 10), 'E');
  }
  printf("Size %i\n", obst->length);   
  for (int i = 0; i < 4; i++)
  {
    int h;
    int c4 = 0;
    char **xy = NULL;
    c4 = split(snakes[i], ':', &xy);
   // for (h = 0; h < c4; h++)
      //printf("--------\n");
    insertObstacule(i+4, strtol(xy[0], NULL, 10), strtol(xy[1], NULL, 10), 'E');
  }
  //printf("Elements %i:\n", obst->length);
  table->obstacul = obst;

  // Llenar el número de jugadores en el tablero

  for (int i = 0; i < players; i++)
  {
    insertPlayer(i, 0, 0);
  }

  table->listPlayers = listPlayers;

  //printf("Players in table %i:\n", table->listPlayers->length);

  int count = 0;

  while (count != table->listPlayers->length)
  {

    for (int l = 0; l < table->listPlayers->length; l++)
    {

      if (obtainPlayer(l)->player.win != 1)
      {
        // 3:11,10:12,9:18,6:17-4:14,8:19,20:22,16:24



        // 3:31,8:36,13:41,16:32,17:48,20:49,21:37,22:53,25:54,26:42,27:58,30:59,78:106,83:111,88:116,91:107,92:123,96:112,97:128,101:117,102:133,153:181,158:186,163:141,166:182,167:198,170:199,171:187,172:203,175:204,176:192,177:208,180:209-4:34,9:39,14:44,18:47,23:52,28:57,46:62,50:64,51:67,55:69,56:72,60:74,79:109,84:114,89:119,93:122,98:127,103:132,121:137,125:139,126:142,130:144,121:147,135:149,154:184,159:189,164:194,168:197,173:202,178:207,196:212,200:214,201:217,205:214,206:222,224:210
        int ju = l + 1;
        int random = (rand() % (6 - 1 + 1)) + 1;
        printf("Player %i throw the dice %i \n ", ju, random);
        int isInside = 0;
        int numObsta=table->obstacul->length;
        int i;
        for ( i= 0; i < numObsta && isInside == 0; i++)
        {

          Obstacule obstacu = obtainObstacule(i)->obstacule;
          int inferior = obstacu.button;
          int superior = obstacu.top;
          int result = (obtainPlayer(l)->player.position + random);
          if (inferior == result && obstacu.type == 'E')
          {
            editarJugador(l, superior, 0);
            isInside = 1;
            int positionnew = obtainPlayer(l)->player.position;
            printf("PLayer %i goes up for the scalar to square %i \n", ju, positionnew);
          }       
          if(inferior == result && obstacu.type == 'S')
          {
            editarJugador(l, inferior, 0);
            isInside = 1;
            int positionnew = obtainPlayer(l)->player.position;
            printf("PLayer %i goes down for the snake to square %i  \n", ju, positionnew);
          }
        }
       
        if (isInside == 0)
        {
          editarJugador(l, obtainPlayer(l)->player.position + random, 0);
          printf("Player %i goes to square %i \n ", ju, obtainPlayer(l)->player.position);
        }

        if (obtainPlayer(l)->player.position > (table->height * table->weidth))
        {
         
          int newPosition=obtainPlayer(l)->player.position -(obtainPlayer(l)->player.position - (table->height * table->weidth));
          int backwards=obtainPlayer(l)->player.position - (table->height * table->weidth);
          editarJugador(l, newPosition, 1);
          printf("Player %i goes back %i blocks \n ", ju, backwards);
          
        }
        if (obtainPlayer(l)->player.position == (table->height * table->weidth))
        {
          editarJugador(l, obtainPlayer(l)->player.position, 1);
          printf("Player %i win \n ", ju);
          count = count + 1;
        }
        




      }
    }
  }
}
