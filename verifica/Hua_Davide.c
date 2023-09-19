#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// DAVIDE HUA 4E
// FILA 1

int main(int argc, char *argv[])
{
    // controllo l'argomento inserito, l'utente deve inserire il nome del file per fare l'operazione
    if (argc != 2)
    {
        //segnalo l'errore se l'utente non ha inserito da riga di comando un file da svolgere l'operazione
        printf("Errore nell'inserimento parametri\n");
        return -1;
    }

    // inizializzo i pipe e il pid
    int p1p2[2], p2p3[2], pid;

    // creo il pipe per il processo 1 e il processo 2
    pipe(p1p2);

    // istanzio il processo 1 attraverso fork
    pid = fork();

    // codice per il processo 1 che deve eseguire il cat del file e mandarlo al processo 2
    if (pid == 0)
    {
        close(p1p2[0]); // chiudo il canale che non mi serve, cioè quello di lettura
        close(1);       // chiudo lo standard output per reindizionarlo al pipe, in modo tale che lo invia al processo 2
        dup(p1p2[1]);   // duplico il canale di scrittura al posto dello standard output
        close(p1p2[1]); // chiudo il canale di scrittura dopo che lo ho duplicato

        // eseguo il comando cat attraverso execl
        execl("/usr/bin/cat", "cat", argv[1], NULL);
        return -1;
    }

    close(p1p2[1]); // il canale di scrittura del pipe p1p2 non serve al processo 2, perciò lo chiudo
    pipe(p2p3);     // creo lo pipe per il processo 2 e il processo 3
    pid = fork();   // istanzio il processo 2

    // codice per il processo 2 che deve eseguire il comando sort -r (ordinamento inverso) e mandare il risultato al processo 3
    if (pid == 0)
    {
        close(0);       // chiudo lo standard input per reindizionarlo al canale di lettura del pipe p1p2, in modo tale da leggere dal pipe
        dup(p1p2[0]);   // duplico il canale di lettura del pipe p1p2 al posto dello standard input
        close(p1p2[0]); // chiudo il canale di lettura che non mi serve più

        close(p2p3[0]); // chiudo il canale di lettura del pipe p2p3 che non serve
        close(1);       // chiudo lo standard output per reindizionarlo al pipe p2p3, in modo tale che lo invia al processo 3
        dup(p2p3[1]);   // duplico il canale di scrittura del pipe p2p3 al posto dello standard output
        close(p2p3[1]); // chiudo il canale di scrittura che non mi serve più

        // eseguo il comando sort -r attraverso execl
        execl("/usr/bin/sort", "sort", "-r", NULL);
        return -1;
    }

    close(p1p2[0]); // chiudo completamente il pipe p1p2 che non serve più
    close(p2p3[1]); // chiudo il canale di scrittura del pipe p2p3 che non serve al processo 3

    pid = fork(); // istanzio il processo 3

    // codice per il processo tre che deve eseguire il comando uniq(togliere ripetizioni) e stampare a video il risultato
    if (pid == 0)
    {
        close(0);       // chiudo lo standard input per reindizionarlo al canale di lettura del pipe p2p3, in modo tale di leggere dal pipe
        dup(p2p3[0]);   // duplico il canale di lettura del pipe p2p3 al posto dello standard input
        close(p2p3[0]); // chiudo il canale di lettura del pipe p2p3 che non serve più

        // eseguo il comando uniq attraverso execl
        execl("/usr/bin/uniq", "uniq", NULL);
        return -1;
    }

    close(p2p3[0]); // chiudo completamente il pipe p2p3 che non serve più

    return 0;
}