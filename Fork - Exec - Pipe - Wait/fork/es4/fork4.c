#include <stdio.h>
#include <stdlib.h>
//#define NRFIGLI 4gcc
void mettiSpazi(int quanti){   // per meglio vedere la gerarchia 
  int x;
  for (x = 0; x <= quanti; x++)
    printf(" ");
}

void faiFiglio (int quanti){
  int pid;
  pid = fork();                    // creo processo figlio 
  if (pid == 0){
    mettiSpazi(quanti);
    printf( "Sono il processo figlio con pid:%d.", getpid() );
    printf( "Il mio papi ha pid: %d\n", getppid());
    if (quanti > 0)
      faiFiglio(quanti-1);         // il figlio diventa il padre  
    else
      exit(0);
  }
  else{
    mettiSpazi(quanti);
    printf( "Sono il processo padre con pid:%d.\n", getpid() );
    sleep(1);  // altrimenti termina prima il padre dei processi figli 
  }
}
int main(){ 
  int NRFIGLI;
  printf( " Quanti processi figli devo generare ? ");
  scanf ("%d", &NRFIGLI);
  faiFiglio(NRFIGLI);
  printf( " Termine elaborazione processo con pid:%d.\n", getpid() ); 
  sleep(1);  // altrimenti termina prima delle alttre visualizzazioni  
  return 0;
} 