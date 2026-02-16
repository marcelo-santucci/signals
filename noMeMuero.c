
/*

Programa que captura la señal Ctrl+C y por tanto se rehusa a dejar que lo cierren.

*/
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void manejador () {
  write(STDOUT_FILENO, "Me reuso a morir\n", strlen("Me reuso a morir\n"));
}

int main()  {

  //Ctrl + c
  signal(SIGINT, manejador);

  /*
  Enviada a través de kill
  kill -TERM PID
  kill -9 PID
  */
  signal(SIGTERM, manejador);

  while (1) {
    printf("Desperdiciando ciclos de procesador %d\n",getpid());
    sleep(1);
  }
}