#ifndef JEU_H
#define JEU_H

typedef struct {
    int x, y;
	
} Position;

typedef struct {
    Position *corps;
    int longueur;
} Serpent;

typedef struct {
  int x,y;
}Obstacle;

 

void initialiserS( Serpent *serpent);
void dessinerS(const Serpent *serpent);
void deplacerS(Serpent *serpent, int direction );
void genererP(Position *pommes ,Serpent *serpent );
void dessinerP( Position *pommes);
void mangerPomme( Serpent *serpent, Position *pommes , int* score);
int collisionAvecP(Serpent *serpent, const Position *pommes);
int collisionAvecP(Serpent *serpent, const Position *pommes);
int collisionAvecBordures( Serpent *serpent);
void gestionCollision( Serpent *serpent, Position *pommes,int* score , int time[2]);
void initialiserObstacles(Obstacle *obstacles);
void dessinerObstacles( Obstacle *obstacles);
int collisionAvecObstacles(Serpent *serpent,  Obstacle *obstacles);

#endif
