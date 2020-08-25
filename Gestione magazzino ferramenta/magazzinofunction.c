#include "magazzinoheader.h"
void gestione(Prodotto *prodotti)//Funzione principale per la gestione del magazzino
{/*La funzione chiede di inserire un codice dalla lista tra quelli mostrati e permette di modificare la quantità o il prezzo
    del prodotto scelto.*/
    int i, scelta, stop=0;
    codice identificatore;
    do
    {
    printf("Inserire il codice del prodotto: ");
    scanf("%ld", &identificatore);
    for(i=0; i<20; i++)
    {
        if(prodotti[i].identificativo == identificatore)
        {
            stop = 1;
            printf("\nCodice prodotto: %ld\n"
                   "Nome prodotto: %s\n"
                   "Utilizzo prodotto: %s\n"
                   "Quantita' prodotto: %d\n"
                   "Prezzo prodotto: %3.2f Euro\n\n", prodotti[i].identificativo, prodotti[i].nome, prodotti[i].utilizzo, prodotti[i].pezzi, prodotti[i].costo);
            printf("\nScegliere cosa fare:\n"
                   "1) Cambia la quantita'\n"
                   "2) Cambia il prezzo\n"
                   "3) Torna indietro\n"
                   "Operazione scelta: ");
            do{
            scanf("%d", &scelta);
            if(scelta != 1 && scelta != 2 && scelta != 3)
                printf("Si prega di inserire una delle operazioni sopra elencate.\nOperazione scelta: ");
            }while(scelta != 1 && scelta != 2 && scelta != 3);
            switch (scelta)
            {
                case 1 : printf("Inserire la nuova quantita': "); scanf("%d", &prodotti[i].pezzi); printf("\nLa quantita' e' stata cambiata.\n"); printf("\nCodice prodotto: %ld\nNome prodotto: %s\nUtilizzo prodotto: %s\nQuantita' prodotto: %d\nPrezzo prodotto: %3.2f Euro\n\n", prodotti[i].identificativo, prodotti[i].nome, prodotti[i].utilizzo, prodotti[i].pezzi, prodotti[i].costo); break;
                case 2 : printf("Inserire il nuovo prezzo: "); scanf("%f", &prodotti[i].costo); printf("\nIl prezzo e' stato cambiato.\n"); printf("\nCodice prodotto: %ld\nNome prodotto: %s\nUtilizzo prodotto: %s\nQuantita' prodotto: %d\nPrezzo prodotto: %3.2f Euro\n\n", prodotti[i].identificativo, prodotti[i].nome, prodotti[i].utilizzo, prodotti[i].pezzi, prodotti[i].costo); break;
                case 3 : break;
                default: break;
            }
        }
    }
    if(stop != 1)
        printf("\nSi prega di inserire un codice dalla lista soprastante.\n");
    }while(stop != 1);
}

void scorte(Prodotto *prodotti)//Funzione che mostra i prodotti sotto scorta
{/*I prodotti sotto scorta hanno il numero di pezzi o di metri sotto le 5 unità. La funzione mostra tutti i prodotti con tale
   caratteristica, e il suo output varia se varia la quantità pezzi a causa delle funzioni gestione(Prodotto *) o
   acquisto(Prodotti *).*/
    int i;
    printf("\nI seguenti prodotti scarseggiano nel magazzino (numero scorte minore o uguale a 5).\n");
    for(i=0; i<20; i++){
        if(prodotti[i].pezzi <= 5)
        {
            printf("\nCodice prodotto: %ld\n"
                   "Nome prodotto: %s\n"
                   "Utilizzo prodotto: %s\n"
                   "Quantita' prodotto: %d\n"
                   "Prezzo prodotto: %3.2f Euro\n\n", prodotti[i].identificativo, prodotti[i].nome, prodotti[i].utilizzo, prodotti[i].pezzi, prodotti[i].costo);
        }
    }
}

void acquisto(Prodotto *prodotti)//La funzione permette l'acquisto di una o più unità del prodotto scelto
{/*La funzione richiede l'inserimento del codice del prodotto e i pezzi/metri da acquistare. La funzione modifica il numero
   pezzi disponibili al termine della transazione ed in output mostra quanto si è speso per l'acquisto completo. L'acquisto
   è annullato se in input si chiedono più unità di quante ne sono disponibili in magazzino.*/
    int i, quantita;
    float totale;
    codice identificatore;
    printf("Inserire il codice del prodotto da acquistare: ");
    scanf("%ld", &identificatore);
    printf("Inserire la quantita' di prodotti da acquistare (o metri di prodotto): ");
    scanf("%d", &quantita);
    for(i=0; i<20; i++){
        if(prodotti[i].identificativo == identificatore){
        if(prodotti[i].pezzi >= quantita)
        {
            totale = quantita * prodotti[i].costo;
            prodotti[i].pezzi = prodotti[i].pezzi - quantita;
            printf("\nSono stati acquistati %d pezzi del prodotto %s con\nun costo di %4.2f Euro; le scorte rimanenti sono %d\n\n", quantita,prodotti[i].nome, totale, prodotti[i].pezzi);
        }
        else if(prodotti[i].pezzi == 0)
            printf("\nLe scorte del prodotto %s sono esaurite\n\n", prodotti[i].nome);
        else if(prodotti[i].pezzi < quantita)
            printf("\nNon vi sono abbastanza scorte in magazzino per completare la transizione.\n\n");

        }

    }
}


void settore(Prodotto *prodotti)//Funzione che mostra tutti i prodotti appartenenti ad un dato settore
{/*La funzione chiede in input una stringa che contenga il nome del settore di cui si vogliono sapere i prodotti. Verranno
   mostrati tutti i dati dei prodotti eccetto il settore, che è dato in input e risulterebbe ridondante.*/
    int i;
    char ambito[15];
    printf("Inserire un settore tra idraulica, elettronica, muratura e giardinaggio.\nSettore scelto: ");
    fflush(stdin);
    do
    {
    gets(ambito);
    strlwr(ambito);//accorgimento per dare più libertà all'utente in fase di inserimento della stringa, potendo scrivere maiuscolo, minuscolo o misto.
    if(strcmp(ambito, "muratura")!=0 && strcmp(ambito, "idraulica")!=0 && strcmp(ambito, "elettronica")!=0 && strcmp(ambito, "giardinaggio")!=0)
        printf("Il campo inserito non esiste, si prega di riprovare.\n");
    }while(strcmp(ambito, "muratura")!=0 && strcmp(ambito, "idraulica")!=0 && strcmp(ambito, "elettronica")!=0 && strcmp(ambito, "giardinaggio")!=0);
        printf("Tutti i prodotti dell'ambito %s:\n\n", ambito);
        for(i=0; i<20; i++)
        {
            if(strcmp(ambito, prodotti[i].utilizzo)==0)
            {
                printf("Codice prodotto: %ld\n"
                       "Nome prodotto: %s\n"
                       "Quantita' prodotto: %d\n"
                       "Prezzo prodotto: %3.2f Euro\n\n", prodotti[i].identificativo, prodotti[i].nome, prodotti[i].pezzi, prodotti[i].costo);
            }
        }
}
