#include <stdio.h>
#include <stdlib.h>
#include "structures.h"


List obst;
ListPlayers listPlayers;

int main(int argc, char *argv[]) {

    int players;
    printf("Please add the number of players for the match:");
    fgets(players, sizeof(players), stdin);

    char size[256];
    printf("Please add the size of the table:");
    fgets(size, sizeof(players), stdin);

    Table* table= (Table *) malloc(sizeof(Table));
    table->height = size[0];
    table->weidth = size[2];

     char obstacules[256];
    printf("Please addd the obstacules of the table:");
    fgets(obstacules, sizeof(obstacules), stdin);
    
     char * obs = strtok(obstacules, "-");
     char * scalars = strtok(obs[0], ",");
     char * snakes = strtok(obs[1], ",");
    

    for (int i = 0; i < sizeof scalars; i++) {
			char* xy =strtok(scalars[i], ":");
            insertObstacule(xy[0]-'0' , xy[1]-'0',  'E');
		}

    for (int i = 0; i < sizeof snakes; i++) {
			char* xy =strtok(snakes[i], ":");
            insertObstacule(xy[0]-'0' , xy[1]-'0',  'S');
		}

    table ->  obstacul =  obst;
    
    //Llenar el número de jugadores en el tablero
	
		for (int i = 0; i < players; i++) {
			insertPlayer(i, 0, 0);
		}
    
    table -> listPlayers = listPlayers;
    
    
    
    int count=0;

    while(count!= table -> listPlayers.length )
    {

            for (int l = 0; l <  table -> listPlayers.length; l++) {

                    if (obtainPlayer(l).win!=1) {

                         int ju=l+1;
                         int random = (rand ()% (6 - 1 + 1)) + 1;
                        printf("Player %i throw the dice %i \n ", ju, random);
                        int isInside=0;
                        for (int i = 0; i < table-> obstacul.length && isInside==0; i++) {
                                Obstacule obstacu=obtainObstacule(i);
                                Obstacule obs2==obtainObstacule(l);
                                int inferior= obstacu.button;
                                int superior=  obstacu.top;
                                if(inferior == (obtainPlayer(l).position + random) && Obstacule.type=='E'){
                                    
                                    editarJugador(listPlayers, l , superior, 0);
                                    isInside=true;
                                    int positionnew=(obtainPlayer(l).position;
                                    printf("PLayer %i goes up for the scalar to square %i \n", ju. positionnew);

                                }

                                else if(inferior == (obtainPlayer(l).position + random) && Obstacule.type=='S' ){

                                    editarJugador(listPlayers, l , inferior, 0);
                                    isInside=true;
                                    printf("PLayer %i goes down for the snake to square %i  \n", ju. positionnew);

                                }



                        }

                        if(!isInside){
                            editarJugador(listPlayers, l , obtainPlayer(l).position + random, 0);
                            printf("PLayer %i goes to square %i \n ", ju. obtainPlayer(l).position);

                        }

                        if(obtainPlayer(l).position == (table->height*table->weidth))
                        {
                            editarJugador(listPlayers, l , obtainPlayer(l).position, 1);
                             printf("PLayer %i win \n ", ju);
                             count=count+1;
                        }

                    }


            }

    }
}




Nodo* CreateObstacule(int top , int button, char type){
    Nodo* nodo= (Nodo*) malloc(sizeof(Nodo));
    nodo-> obstacule.top = top;
    nodo-> obstacule.button = button;
    nodo-> obstacule.type = type;
    nodo->next = NULL;
    return nodo;   
}


Nodo2* CreatePlayer(int id , int position, int win){
    Nodo2* nodo= (Nodo2*) malloc(sizeof(Nodo2));
    nodo-> player.id = id;
    nodo-> player.position = position;
    nodo-> player.win = win;
    nodo->next = NULL;
    return nodo;   
}


void deleteNodo(Nodo* nodo){
    free(nodo);
}



void insertObstacule( List listt, int top , int button, char type){
  
    Nodo* nodo= CreateObstacule( top, button, type);
    if(listt==NULL){
        listt= (List*) malloc(sizeof(List));
        listt->length=0;
        listt->head=NULL;
    }
    if(listt->head==NULL){
        listt->head=nodo;
        listt->length++;
    }
    else{
        Nodo* point = listt-> head;
        while(point-> next) {
            point= point->next;
        }
        point-> next=nodo;
        listt->length++;
        
    }
}

Obstacule obtainObstacule(int id){
   
    if(obst->head == NULL){
        return NULL;
        }
    else{
        Nodo* point = obst->head;
       while(point){
           if(point-> obstacule.id == id)
           {   
               return point-> obstacule;
           }
           else{
    
            point = point->next;
           }
      
        }
            
            return point->obstacule;
    }
}

void editarJugador(ListPlayers* lista, int id , int position, int win){ 
    Nodo2* nodo=  CreatePlayer(id , position, win);
    if(lista->cabeza == NULL)
        lista->cabeza = nodo;
    else{
        Nodo2 *puntero = lista->cabeza;
        int posicion = 0;
        while(posicion < id && puntero->next->player.id!=id){
            puntero = puntero->next;
            posicion++;
        }
        Nodo2* puntero2=puntero->next
        nodo->next = puntero2->next;
        puntero->next = nodo;
    }
    lista->longitud++;
}
void printList(){
     Nodo* point = stack2->head;
     printf("Prefix={ ");
        while(point){
            printf("%s ", point-> variable.structure);
            point = point->next;
      
        }
         printf("}\n");
}

void insertPlayer( int id , int position, int win){
  
    Nodo2* nodo=  CreatePlayer(id , position, win);
    if(listPlayers==NULL){
        listPlayers= (ListPlayers*) malloc(sizeof(ListPlayers));
        listPlayers->length=0;
        listPlayers->head=NULL;
    }
    if(listPlayers->head==NULL){
        listPlayers->head=nodo;
        listPlayers->length++;
    }
    else{
        Nodo2* point = listPlayers-> head;
        while(point-> next) {
            point= point->next;
        }
        point-> next=nodo;
        listPlayers->length++;
        
    }
}

Player obtainPlayer(int id){
   
    if(listPlayers->head == NULL){
        return NULL;
        }
    else{
        Nodo2* point = listPlayers->head;
       while(point){
           if(point-> player.id==id)
           {   
               return point-> player;
           }
           else{
    
            point = point->next;
           }
      
        }
            
            return point->player;
    }
}
