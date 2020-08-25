#include "golfheader.h"
int traiettoria(int seed, int *c1, int *c2, int *c3) //Funzione che sceglie automaticamente se deviare la traiettoria
{/*c1, c2 e c3 sono tre variabili passate per riferiento utili per far variare i valori generati dalla funzione
   rand(), la quale ha il difetto di generare numeri pseudocasuali in sequenza crescente, e dato che la funzione è richiamata
   ad ogni turno, e l'inizio del turno è deciso dall'utente, si possono avere potenziali chiamate in tempi molto brevi, facendo
   quindi emergere il difetto della funzione. Le tre varaibili, i cui valori sono conservati nel main(), garantiscono che all'
   occorrenza della terza ripetizione della stessa scelta di deviazione, si scelga una delle altre due differenti.*/
    int mira;
    srand(seed);
    if(*c1 < 3 && *c2 < 3 && *c3 < 3)
    {
        mira = 1+rand()%100;
    } else if(*c1 >= 3) //c1 indica "diritto", quindi ha il 50% di possibilità di incrementarsi (da 1 a 50).
      {
          mira = 51+rand()%49; //quindi se c1 è 3 (terza occorrenza), mira sarà un numero maggiore di 50.
          *c1 = 0;
      } else if(*c2 >= 3)
        {
            mira = 76+rand()%24; //c2 (sinistra) ha un 25% di possibilità di incrementarsi, e alla terza occorrenza, sceglie c3 (destra).
            *c2 = 0;
        } else if(*c3 >= 3)
            {
                mira = 1+rand()%75; //anche c3 (destra) ha 25% di possibilità, e alla terza occorrenza, sceglie una delle altre due opzioni.
                *c3 = 0;
            }
    /*A questo punto è stata scelta la direzione modificata, e si ritorna la stessa in base ai valori generati precedentemente
      e si incrementano le variabili di controllo, in base alla direzione scelta. Laddove si fosse scelto di deviare la
      traiettoria, si avvisa l'utente che in quel turno si avrà la deviazione con la printf("||TIRA UN FORTE VENTO||\n\n")*/
    if(mira <= 50)
    {
        *c1 = *c1 + 1;
        return diritto;
    } else if (mira > 50 && mira <= 75)
        {
            *c2 = *c2 + 1;
            printf("||TIRA UN FORTE VENTO||\n\n");
            return sinistra;
        }else if (mira > 75)
            {
                *c3 = *c3 + 1;
                printf("||TIRA UN FORTE VENTO||\n\n");
                return destra;
            }
    return 0;//return in caso di errore
}


int calcolorimbalzo(int seed, int *r1, int *r2) //Funzione che sceglie automaticamente se far rimbalzare la palla arrivata a terra.
{/*La funzione, in questo caso, per aumentare la variabilità della funzione rand(), all'occorrenza della soddisfazione della
   condizione if(prob < *r2 && prob > *r1), incrementa r1 e r2 di 10, in modo tale che solo ogni 5-10 secondi circa avvenga il
   rimbalzo, pur prevedendo un utente che scorre i turni molto velocemente. Date le regole del golf, se la potenza, generata
   dalla funzione int forza(int), è 1, equivalente alla mazza di materiale putter, non avvenga il rimbalzo, dato che il
   putter non ha angoli di applicazione della forza e la forza viene quindi applicata parallelamente al terreno.*/
    int rimbalzo, prob;
    srand(seed);
    prob = 1+rand()%100;
    if(prob < *r2 && prob > *r1)
    {
        srand(seed);
        rimbalzo = 1+rand()%8;
        if(*r2 <= 90)
        {
            *r1 = *r1 + 10;
            *r2 = *r2 + 10;

        } else
            {
                *r1 = 0;
                *r2 = 10;
            }
        return rimbalzo;
    }
    else
    {
        return 0;
    }
}

void campo(char *field, int n, int m)//Funzione che stampa il campo
{/*Il campo è circondato dai bordi, creati con i simboli della tabella ASCII, mentre la parte vuota è il terreno di gioco.
   La "P" indica il player, la "O" indica la hole.*/
    int i, j;
    for(i=0; i<n; i++)
    {
        printf("\n");
        for(j=0; j<m; j++)
        {
            printf("%c", *(field+m*i+j));
        }
    }
    printf("\n");
}

void posizione(int *x, int *y, int potenza, int vento, int rimbalzo, int direzione)//La funzione calcola la nuova posizione
{/*La funzione è il cuore del programma dato che, in base a tutti i valori calcolati in precedenza dalle altre funzioni,
    stabilisce le nuove coordinate del player P nella matrice field.*/
    switch (vento)
    {//In base al vento e alla direzione decisa a priori, decide quale direzione prendere di conseguenza.
        case sinistra : if(direzione < 8){direzione = direzione + 1;}else{direzione = 1;} break;
        case destra : if(direzione > 1){direzione = direzione - 1;}else{direzione = 8;} break;
        default: break;
    }
    switch (direzione)
    {//Dopo aver deciso la direzione, modifica le variabili delle coordinate
        case N : *y = *y - potenza; break;
        case NE : *x = *x + potenza; *y = *y - potenza; break;
        case E : *x = *x + potenza; break;
        case SE : *x = *x + potenza; *y = *y + potenza; break;
        case S : *y = *y + potenza; break;
        case SW : *x = *x - potenza; *y = *y + potenza; break;
        case W : *x = *x - potenza; break;
        case NW : *x = *x - potenza; *y = *y - potenza; break;
        default: printf("C'e' stato un errore nel calcolo della nuova posizione"); exit(-1);
    }
    if(potenza > 1)
    {//Solo se non si sta usando il putter (potenza == 1)
        switch (rimbalzo)
        {//Modifica le coordinate in base al rimbalzo
            case N : *y = *y - 1; break;
            case NE : *x = *x + 1; *y = *y - 1; break;
            case E : *x = *x + 1; break;
            case SE : *x = *x + 1; *y = *y + 1; break;
            case S : *y = *y + 1; break;
            case SW : *x = *x - 1; *y = *y + 1; break;
            case W : *x = *x - 1; break;
            case NW : *x = *x - 1; *y = *y - 1; break;
            default: break;
        }
    }
    //I seguenti controlli, riposizionano la palla e il player P ai bordi del campo, laddove siano andati fuori campo
    if(*x > 48)
    {
       *x = 48;
    }else if(*x < 1)
        {
            *x = 1;
        }
    if(*y > 48)
    {
       *y = 48;
    }else if(*y < 1)
        {
            *y = 1;
        }
}

int direzione(int xp, int yp, int xh, int yh) //La funzione sceglie una direzione tra le 8 disponibili, in base alle coordinate
{/*Le variabili della funzione indicano le coordinate del player (xp, yp) e le coordinate della hole (xh, yh).
   La direzione è scelta in modo tale da puntare sempre verso la buca, e la scelta avviene grazie al confronto tra le
   coordinate del player e le coordinate della buca, in base a quale delle 8 condizioni soddisfano. La prima condizione
   è la Sud-Est per via che il player parte sempre da 1/1 e la buca si trova in posizioni maggiori di 25/25, facendo della
   condizione Sud-Est la più utilizzata, quantomeno nelle prime fasi di gioco.*/
    if(yh > yp && xh > xp)
        return SE;
    else if(yh < yp && xh == xp)
        return N;
    else if(yh < yp && xh > xp)
        return NE;
    else if(yh == yp && xh > xp)
        return E;
    else if(yh > yp && xh == xp)
        return S;
    else if(yh > yp && xh < xp)
        return SW;
    else if(yh == yp && xh < xp)
        return W;
    else if(yh < yp && xh < xp)
        return NW;
    return 0;//return in caso di errore
}


int forza(int seed) //Funzione che calcola la potenza del colpo e di conseguenza la mazza da utilizzare
{/*Non vi sono accorgimenti per la rand(), dato che non è un problema se la potenza del tiro si ripete tra i turni*/
    int potenza;
    srand(seed);
    potenza = 1+rand()%4;
    return potenza;
}

void inizializza(char *field, Coordinate *giocatore, Coordinate *buca) //Funzione che inizializza i valori della matrice field
{//La funzione inizializza le coordinate del player P e genera le coordinate della hole O.
    int seed;
    *(field+(giocatore->y)*50+(giocatore->x))=' ';
    *(field+(buca->y)*50+(buca->x))=' ';
    seed = time(NULL);
    srand(seed);
    giocatore->x = 1;
    giocatore->y = 1;
    buca->x = 25+rand()%23;
    buca->y = 25+rand()%23;
    *(field+(giocatore->y)*50+(giocatore->x))='P';
    *(field+(buca->y)*50+(buca->x))='O';
}

void stamparisultati(int *array) //Funzione che stampa i risultati delle 10 partite eseguite
{/*La funzione utilizza l'algoritmo di ordinamento per selezione di minimo per ordinare l'array dei risultati
   mostrando quindi, tramite printf(), i risultati delle 10 simulazioni in ordine crescente a partire dalla partita
   andata meglio fino alle partite andate peggio o finite per eccesso di turni. Tramite operatore ?, la funzione scrive
   "Partita finita per eccesso di turni" laddove si siano superati i 50 turni (50 escluso)*/
    int i, j, minimo, appoggio;
    for(i=0; i<10; i++)
    {
        minimo=i;
        for(j=i; j<10; j++)
        {
            if(*(array+minimo)>*(array+j))
                minimo=j;
        }
        appoggio=*(array+minimo);
        *(array+minimo)=*(array+i);
        *(array+i)=appoggio;
    }
    for(i=0; i<10; i++)
    {
        (*(array+i)<=50)?printf("Punteggio %d: %d\n", i+1, *(array+i)):printf("Punteggio %d: %d (partita finita per eccesso turni)\n", i+1, *(array+i));
    }
}
