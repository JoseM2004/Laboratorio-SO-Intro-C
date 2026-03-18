# Laboratorio-SO-Intro-C

## Aplicación 1: `wcat`

Programa que lee uno o más archivos pasados como argumentos e imprime su contenido en la salida estándar, imitando el comportamiento básico del comando `cat` de UNIX.

---

### `main(int argc, char *argv[])`

**Descripción:** Punto de entrada del programa. Verifica los argumentos recibidos desde la línea de comandos e itera sobre cada archivo pasado, delegando la lectura e impresión a `leer_archivo()`.

**Parámetros:**
- `argc` — Número total de argumentos recibidos (incluyendo el nombre del programa).
- `argv[]` — Arreglo de strings con los argumentos. `argv[0]` es el nombre del programa; `argv[1]` en adelante son los nombres de los archivos.

**Comportamiento:**
- Si no se pasan archivos (`argc == 1`), el programa termina inmediatamente con código de salida `0`.
- Si se pasan uno o más archivos, llama a `leer_archivo()` por cada uno en el orden recibido.

**Retorna:** `0` en caso de éxito.

---

### `leer_archivo(char *path)`

**Descripción:** Abre un archivo, lee su contenido línea por línea usando un buffer e imprime cada línea en la salida estándar. Cierra el archivo al terminar.

**Parámetros:**
- `path` — Ruta o nombre del archivo a leer.

**Comportamiento:**
- Abre el archivo en modo lectura (`"r"`) con `fopen()`.
- Si el archivo no puede abrirse (por ejemplo, no existe o no hay permisos), imprime el mensaje `"wcat: cannot open file"` y termina el programa con código de salida `1`.
- Lee el archivo línea por línea usando `fgets()` con un buffer de 100 caracteres e imprime cada línea con `printf()` sin agregar caracteres adicionales.
- Cierra el archivo con `fclose()` al terminar la lectura.

**Retorna:** `void`
