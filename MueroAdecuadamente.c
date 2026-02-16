/*
Programa que captura la señal Ctrl+C y efectua 
tareas de cierre para que el proceso no se vea afectado.
*/
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Se cierra el proceso al al detectar la señal
  en este procedimiento se puede manejar cualquier
  actividad de cierre que sea apropiada
*/
void manejador (int signo) {
  const char *mensaje_1 = "\nSe recibió SIGINT (Ctrl+C)\n";
  const char *mensaje_2 = "\nTerminando el programa limpiamente...\n";

  if (signo == SIGINT) {
    write(STDOUT_FILENO, mensaje_1, strlen(mensaje_1));
    write(STDOUT_FILENO, mensaje_2, strlen(mensaje_2));
    exit(0);
  }
}

int main()  {

  struct sigaction sa;
  sa.sa_handler = manejador;

  // Inicializar conjunto de señales capturadas/bloqueadas
  sigemptyset(&sa.sa_mask);

  //Opciones -> 0 = comportamiento estándar 
  sa.sa_flags = 0;
  
  //Registrar la acción para SIGINT 
  if(sigaction(SIGINT, &sa, NULL) == -1) {
    perror("Error al registrar sigaction");
    exit(1);
  }

  while (1) {
    printf("Desperdiciando ciclos de procesador %d\n", getpid());
    sleep(1);
  }

  return 0;
}