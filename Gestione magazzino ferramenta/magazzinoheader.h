#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef float euro;
typedef long int codice;
struct prodotto{codice identificativo; char nome[20]; char utilizzo[15]; int pezzi; euro costo;};
typedef struct prodotto Prodotto;
void gestione (Prodotto *);
void scorte (Prodotto *);
void acquisto (Prodotto *);
void settore(Prodotto *);
