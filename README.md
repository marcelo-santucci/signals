# Señales

Programas de ejemplo de manejo de señales por parte de procesos.

+ noMemuero.c  es un programa que atrapa la señal enviada con ctrl+c, evitando que lo cierren.

Señal    Teclado  
SIGINT   Ctrl + c  


Para enviar una señal a un proceso se puede hacer uso de kill:

```c
kill -TERM PID
```

| Señal   | Significado            | Se puede capturar |
| ------- | ---------------------- | ----------------- |
| SIGINT  | Interrupción (Ctrl+C)  | Sí                |
| SIGTERM | Terminación solicitada | Sí                |
| SIGKILL | Terminación forzada    | ❌ No             |
| SIGSEGV | Violación de segmento  | Sí                |
