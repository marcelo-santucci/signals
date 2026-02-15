# Señales

Programas de ejemplo de manejo de señales por parte de procesos.

+ noMemuero.c  es un programa que atrapa la señal enviada con ctrl+c, evitando que lo cierren.

Para enviar una señal a un proceso se puede hacer uso de kill:

```c
kill -TERM PID
```
