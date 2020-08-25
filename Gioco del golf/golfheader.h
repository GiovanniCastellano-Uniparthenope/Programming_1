#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
typedef enum {N=1, NE, E, SE, S, SW, W, NW}Puntocardinale;
typedef enum {putter=1, ibrido, wedge, ferro, legno}Materiale;
typedef enum {diritto=1, sinistra, destra}Deviazione;
struct coordinata{int x; int y;};
typedef struct coordinata Coordinate;
int traiettoria(int, int *, int *, int *);
int calcolorimbalzo(int, int *, int *);
int direzione(int, int, int, int);
int forza(int);
void campo(char *, int, int);
void posizione(int *, int *, int, int, int, int);
void inizializza(char *, Coordinate *, Coordinate *);
void stamparisultati(int *);
