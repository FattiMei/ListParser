# ListParser
Parsing a list of numbers separated by commas

# Specifica
Il programma prende una stringa di caratteri e, se non sono presenti errori, restituisce una lista di numeri.
In caso contrario segnala ogni errore (grammatico e sintattico) con relativa posizione.

# Il problema che il progetto intende risolvere
Ad alcuni programmi in C (tipicamente con finalità didattica) viene richiesto di fare delle elaborazioni su una lista di numeri, come l'ordinamento o la ricerca di massimi/minimi. Il problema risiede nell'interazione con l'utente: siccome la grandezza dell'input non è definita a priori, la soluzione di chiedere la dimensione dell'input e poi acquisire singolarmente ogni entrata non è così elegante, perciò ho deciso di seguire questo progetto.

# Applicazioni future
Questo progetto è propedeutico alla realizzazione di un parser per l'acquisizione di matrici come questa: [[1, 2, 3],[4, 5, 6]]

# Come si può migliorare il codice
Si potrebbe eliminare la ricorsione di listParser utilizzando un ciclo, quindi migliorando l'efficienza del progetto.
