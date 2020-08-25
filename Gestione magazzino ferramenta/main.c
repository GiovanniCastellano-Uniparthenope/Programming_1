#include "magazzinoheader.h"                                                                        //Header personale
void main()
{
    int choice, breaker=0, i;
    Prodotto product[20]={{816541, "Nastro isolante", "elettronica", 7, 4.30F},
                          {816732, "Scatola viti", "elettronica", 13, 3.10F},
                          {816991, "Martello", "muratura", 23, 11.99F},
                          {816874, "Scatola chiodi", "muratura", 17, 2.99F},
                          {816222, "Sacco calce", "muratura", 3, 5.50F},
                          {816969, "Trapano", "muratura", 4, 45.99F},
                          {816332, "Tubatura interni", "idraulica", 120, 10.40F},
                          {816333, "Tubatura esterni", "idraulica", 70, 19.80F},
                          {816441, "Filo di rame", "elettronica", 40, 8.70F},
                          {816989, "Tagliaerba", "giardinaggio", 0, 340.00F},
                          {816442, "Kit giardiniere", "giardinaggio", 14, 13.80F},
                          {816184, "Kit idraulico", "idraulica", 12, 56.70F},
                          {816533, "Kit elettricista", "elettronica", 11, 48.20F},
                          {816323, "Kit muratore", "muratura", 18, 44.80F},
                          {816887, "Stagno", "elettronica", 32, 4.50F},
                          {816395, "Pennelli", "muratura", 5, 6.20F},
                          {816889, "Carta vetrata", "muratura", 23, 2.20F},
                          {816278, "Cavo elettrico", "elettronica", 0, 24.99F},
                          {816384, "Spago", "giardinaggio", 43, 1.90F},
                          {816483, "Prato sintetico", "giardinaggio", 70, 5.40F}};
    do
    {
    printf("Gestione magazzino ferramenta\nGiovanni Castellano\n0124001514\n\n"
           "Codice           Nome\n\n");
    for(i=0; i<20; i++)                                                                             //Mostra la lista di prodotti con i relativi codici
        printf("%-16d %s\n", product[i].identificativo, product[i].nome);

        printf("\nScegliere quale operazione eseguire:\n"
               "1) Cerca un prodotto con codice per modificarne la quantita' o il prezzo\n"
               "2) Visualizza dati dei prodotti sotto scorta\n"
               "3) Acquista un prodotto\n"
               "4) Dato un settore, visualizza tutti i prodotti compatibili\n"
               "5) Esce dal programma\n"
               "Inserire l'operazione scelta (1,2,3,4 o 5 per uscire): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1 : gestione(product); break;                                                          //Richiama la funzione per variare quantità e prezzo dei prodotti
        case 2 : scorte(product); break;                                                            //Richiama la funzione per stampare tutti i prodotti sotto scorta
        case 3 : acquisto(product); break;                                                          //Richiama la funzione per aquistare un prodotto
        case 4 : settore(product); break;                                                           //Richiama la funzione per mostrare tutti i prodotti per settore
        case 5 : breaker = 1; break;                                                                //Ferma il ciclo senza trocarlo
        default: printf("Si prega di inserire una delle opzioni indicate.\n"); break;
        }
        if(breaker !=1)
            system("PAUSE");
            system("CLS");
    }while(breaker != 1);
}
