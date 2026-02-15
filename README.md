# Señales

Programas de ejemplo de manejo de señales por parte de procesos.

+ noMemuero.c  es un programa que atrapa la señal enviada desde el teclaco con ctrl+c, evitando que lo cierren.

Para enviar una señal a un proceso se puede hacer uso de kill:

| Señal   | Significado            | Se puede capturar | Nombre uso |
| ------- | ---------------------- | ----------------- |------------|
| SIGINT  | Interrupción (Ctrl+C)  | Sí                |            |
| SIGTERM | Terminación solicitada | Sí                |    TERM    |
| SIGKILL | Terminación forzada    | ❌ No             |    KILL   |
| SIGSEGV | Violación de segmento  | Sí                |            |

```c
kill -TERM PID
```
