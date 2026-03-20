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

---

## Aplicación 3: `wzip` y `wunzip`

Pareja de programas para comprimir y descomprimir archivos usando el algoritmo **Run-Length Encoding (RLE)**. `wzip` reemplaza secuencias de caracteres repetidos por un entero de 4 bytes (el conteo) seguido del carácter correspondiente. `wunzip` realiza la operación inversa.

Por ejemplo, la cadena `aaaaaaaaaabbbb` se comprime como `10a4b` (en formato binario: `[10][a][4][b]`).

---

### `wzip`

#### `main(int argc, char *argv[])`

**Descripción:** Itera sobre cada archivo pasado y asigna la compresión a `comprimir()`. Además, conserva el carácter actual y su conteo entre archivos, de modo que si una secuencia de caracteres continúa de un archivo a otro, se trate como una sola y se comprima correctamente.

**Parámetros:**
- `argc` — Número total de argumentos recibidos (incluyendo el nombre del programa).
- `argv[]` — Arreglo de strings con los argumentos. `argv[1]` en adelante son los nombres de los archivos a comprimir.

**Comportamiento:**
- Si no se pasan archivos (`argc == 1`), imprime `"wzip: file1 [file2 ...]"` y termina con código de salida `1`.
- Si algún archivo no puede abrirse, imprime `"wzip: cannot open file"` y termina con código de salida `1`.
- Mantiene las variables `char_actual` y `conteo` compartidas entre todos los archivos, permitiendo fusionar rachas que crucen el límite entre archivos.
- Al terminar todos los archivos, escribe la última racha pendiente a `stdout`.
- Toda la salida comprimida se escribe en `stdout`, por lo que se usa redirección (`>`) para guardarla en un archivo.

**Retorna:** `0` en caso de éxito.

---

#### `comprimir(FILE *fp, int *char_actual, int *conteo)`

**Descripción:** Lee el archivo carácter por carácter y aplica compresión RLE: cuenta cuántas veces se repite un mismo carácter de forma consecutiva. Cuando la secuencia cambia, escribe el conteo y el carácter en `stdout` en formato binario (un entero de 4 bytes seguido de 1 byte del carácter).

**Parámetros:**
- `fp` — Puntero al archivo abierto que se va a comprimir.
- `char_actual` — Puntero al carácter de la racha en curso. Se comparte entre llamadas para manejar rachas entre archivos.
- `conteo` — Puntero al conteo acumulado de la racha en curso. Se comparte entre llamadas por la misma razón.

**Comportamiento:**
- Lee el archivo carácter por carácter con `fgetc()`.
- Si el carácter leído es igual a `*char_actual`, incrementa `*conteo`.
- Si es distinto, escribe la racha anterior con `fwrite()` en formato binario y comienza una nueva racha con el carácter actual.
- La última racha no se escribe aquí sino en `main()`, para garantizar que no se escriba prematuramente al pasar de un archivo al siguiente.

**Retorna:** `void`

---

### `wunzip`

#### `main(int argc, char *argv[])`

**Descripción:** itera sobre cada archivo comprimido pasado y asigna la descompresión a `descomprimir()`.

**Parámetros:**
- `argc` — Número total de argumentos recibidos (incluyendo el nombre del programa).
- `argv[]` — Arreglo de strings con los argumentos. `argv[1]` en adelante son los nombres de los archivos comprimidos.

**Comportamiento:**
- Si no se pasan archivos (`argc == 1`), imprime `"wunzip: file1 [file2 ...]"` y termina con código de salida `1`.
- Si algún archivo no puede abrirse, imprime `"wunzip: cannot open file"` y termina con código de salida `1`.
- Llama a `descomprimir()` por cada archivo en el orden recibido, escribiendo todo a `stdout`.

**Retorna:** `0` en caso de éxito.

---

#### `descomprimir(FILE *fp)`

**Descripción:** Lee un archivo comprimido en formato RLE binario, interpretando cada bloque de 5 bytes como un par (conteo, carácter), e imprime el carácter el número de veces indicado por el conteo.

**Parámetros:**
- `fp` — Puntero al archivo comprimido que se va a descomprimir.

**Comportamiento:**
- Lee bloques de 5 bytes usando `fread()`: primero un entero de 4 bytes (`conteo`) y luego un carácter de 1 byte (`c`).
- Por cada bloque leído, imprime `c` exactamente `conteo` veces con `printf()`.
- Repite hasta llegar al final del archivo.

**Retorna:** `void`

# Pruebas realizadas
### Crear archivo de prueba
echo -n "aaaaaaaaaabbbb" > file.txt

### Comprimir
./wzip file.txt > file.z

#### Descomprimir y verificar que el resultado es igual al original
./wunzip file.z

### Prueba con múltiples archivos (las rachas se fusionan entre archivos)
echo -n "aaa" > f1.txt
echo -n "aabbb" > f2.txt

./wzip f1.txt f2.txt > combined.z
./wunzip combined.z  # debe imprimir: aaaaaabbb  → 5a3b

### Sin argumentos
./wzip    # debe imprimir: wzip: file1 [file2 ...]
./wunzip  # debe imprimir: wunzip: file1 [file2 ...]

<img width="1040" height="438" alt="image" src="https://github.com/user-attachments/assets/080ad732-6a85-4cf8-931a-32ce83169099" />

--- 

## Manifiesto de transparencia

Durante el desarrollo de esta práctica se hizo uso de IA generativa (Claude de Anthropic) como herramienta de apoyo en los siguientes puntos:

### `wcat`
No se utilizó IA generativa en el desarrollo de este programa. La implementación fue realizada de forma completamente independiente.

### `wgrep`
Se consultó IA generativa de forma puntual para entender el uso de dos funciones de la librería estándar de C:
- `getline()` — para comprender cómo manejar líneas de longitud arbitraria de forma dinámica, como alternativa a `fgets()`.
- `strstr()` — para entender cómo verificar si una cadena contiene un término de búsqueda dentro de ella.
- lectura desde `stdin` que al final no resultó un desafio

La lógica del programa (estructura general, manejo de argumentos y desde archivos) fue desarrollada e integrada de forma propia.

### `wzip` y `wunzip`
Se recurrió a IA generativa con mayor medida en el desarrollo de estos programas, dado que el algoritmo RLE en formato binario representaba un concepto nuevo. El punto de mayor dificultad fue entender que la salida debía escribirse en formato binario usando `fwrite()` con bloques de 4 bytes para el entero y 1 byte para el carácter, en lugar de una representación en texto.

No obstante, una vez obtenido el código, este fue estudiado en detalle: se analizó la lógica de compresión carácter por carácter, el manejo del estado compartido entre archivos para fusionar rachas entre ficheros consecutivos, y el mecanismo de lectura por bloques en `wunzip` con `fread()`. El resultado fue una comprensión completa de la implementación antes de incluirla en la entrega.





