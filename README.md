# Laboratorio-SO-Intro-C

- Jose Miguel Monsalve Marin <br>
jmiguel.monsalve@udea.edu.co <br>
CC: 1038062019
- Miguel Angel Agudelo Vera <br>
miguel.agudelo2@udea.edu.co <br>
CC: 1039678287

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

# Pruebas realizadas
## Archivos de pruebas:
### texto.txt
<img width="433" height="139" alt="Captura de pantalla 2026-03-18 171708" src="https://github.com/user-attachments/assets/bb6d1f6d-706d-4852-a73f-655a77d64553" />

### archivo.txt
<img width="368" height="133" alt="image" src="https://github.com/user-attachments/assets/09459a4f-5581-4bf9-8890-a79083ce907d" />

## Probando la ejecución:
### archivo inválido: 
<img width="668" height="80" alt="image" src="https://github.com/user-attachments/assets/273abe58-449c-44ba-977e-c8e12c029fe2" />

### archivos válidos:
<img width="800" height="245" alt="image" src="https://github.com/user-attachments/assets/6f4f42c3-7428-4eee-97f8-a76cde9d6f9a" />

### archivos válidos e inválido:
<img width="869" height="181" alt="image" src="https://github.com/user-attachments/assets/e671921d-2dcf-4aeb-ab0c-c14a18d89456" />

### archivo diferente a un .txt:
<img width="664" height="728" alt="image" src="https://github.com/user-attachments/assets/6215bcd0-4f18-4cda-99f4-3d0aa24a142a" />

--- 
## Aplicación 2: `wgrep`

Programa que busca un término en uno o más archivos línea por línea e imprime únicamente las líneas que contienen dicho término, imitando el comportamiento básico del comando `grep` de UNIX.

---

### `main(int argc, char *argv[])`

**Descripción:** Valida los argumentos recibidos, determina la fuente de entrada (archivo o `stdin`) e itera sobre cada archivo pasado haciendo la búsqueda del termino mediante el llamado a `buscar_en_archivo()`.

**Parámetros:**
- `argc` — Número total de argumentos recibidos (incluyendo el nombre del programa).
- `argv[]` — Arreglo de strings con los argumentos. `argv[0]` es el nombre del programa, `argv[1]` es el término de búsqueda y `argv[2]` en adelante son los nombres de los archivos.

**Comportamiento:**
- Si no se pasa ningún argumento (`argc == 1`), imprime `"wgrep: searchterm [file ...]"` y termina con código de salida `1`.
- Si solo se pasa el término de búsqueda (`argc == 2`), llama a `buscar_en_archivo()` usando `stdin` como fuente de entrada y termina con código de salida `0`.
- Si se pasan uno o más archivos, itera sobre ellos llamando a `buscar_en_archivo()` por cada uno.
- Si algún archivo no puede abrirse, imprime `"wgrep: cannot open file"` y termina con código de salida `1`.

**Retorna:** `0` en caso de éxito.

---

### `buscar_en_archivo(char *termino, FILE *fp)`

**Descripción:** Lee un flujo de entrada línea por línea e
imprime en la salida únicamente las líneas que contienen el término de búsqueda. Soporta líneas de longitud arbitraria gracias al uso de `getline()`.

**Parámetros:**
- `termino` — String con el término a buscar dentro de cada línea.
- `fp` — Puntero al flujo de entrada a leer; puede ser un archivo abierto con `fopen()` o `stdin`.

**Comportamiento:**
- Lee el flujo línea por línea usando `getline()`, que gestiona dinámicamente la memoria necesaria para líneas de cualquier longitud.
- Por cada línea, usa `strstr()` para verificar si el término está contenido en ella. La comparación es **case-sensitive** (`"foo"` y `"Foo"` se tratan como términos distintos).
- Si la línea contiene el término, la imprime con `printf()` sin agregar caracteres adicionales.
- Al terminar, libera la memoria reservada por `getline()` con `free()`.

**Retorna:** `void`

# Pruebas realizadas
### Archivo de prueba:
<img width="743" height="246" alt="image" src="https://github.com/user-attachments/assets/be91cf21-eb8b-4b34-83e3-032d8ad285d3" />

- Tambien se usaran los archivos anteriores

### Búsqueda básica (término "archivo"):
<img width="748" height="74" alt="image" src="https://github.com/user-attachments/assets/e740064e-478b-40b4-a369-e06d30c08c85" />

### Case sensitive:
<img width="746" height="71" alt="image" src="https://github.com/user-attachments/assets/35d59958-2a06-44c0-8353-b318746eded7" />

### Múltiples archivos Sin argumentos:
<img width="941" height="166" alt="Captura de pantalla 2026-03-18 190344" src="https://github.com/user-attachments/assets/ccd50661-1de2-43ec-8aa8-be207f91fcb9" />

### Archivo inexistente y prueba con stdin (no se especifica el archivo pero si la palabra):
<img width="785" height="221" alt="image" src="https://github.com/user-attachments/assets/65400102-e3c9-45d2-a78e-9e09e9035341" />











