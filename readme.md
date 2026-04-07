# Laboratorio: Strings en C

**Nombre:** ___________________________
**Legajo:** ___________________________
**Fecha:**  ___________________________

---

## Antes de empezar

Para trabajar local necesitás GCC y Make:
- **Linux:** `sudo apt install gcc make`
- **macOS:** `xcode-select --install`
- **Windows:** WSL con Ubuntu recomendado

Sin instalar nada: **GitHub Codespaces** → botón verde `<> Code` → pestaña `Codespaces`.

Verificá que el proyecto compila desde el estado inicial:

```bash
make test
make all
```

Deberías ver que todo compila sin errores.

---

## Restricciones — leer antes de arrancar

Aplican a **todo** el laboratorio sin excepción:

| Restricción | Ejemplo ❌ | Ejemplo ✅ |
|---|---|---|
| No usar `<string.h>` | `strlen(s)` | `GetLength(s)` |
| No usar `<stdlib.h>` para conversión | `atoi(s)` | `ToInteger(s)` |
| Usar `const` donde el parámetro no se modifica | `int f(char *s)` | `int f(const char *s)` |
| Tests con literales, no variables | `char *s="x"; assert(f(s)==1)` | `assert(f("x")==1)` |
| Tests sin salida a stdout | `printf("ok\n")` en test | solo `assert(...)` |
| Iterar con puntero en Parte III | `for (int i=1; i<argc; i++)` | `for (char **arg=argv+1; ...)` |

---

## Parte I — Análisis Comparativo

Comparación de strings en C vs otro lenguaje de tu elección. Completá cada ítem.

**Lenguaje elegido para comparar:** ___________________________

---

### 1. ¿El tipo es parte del lenguaje en algún nivel?

**C:**

> (respuesta)

**___ (otro lenguaje):**

> (respuesta)

---

### 2. ¿El tipo es parte de la biblioteca?

**C:**

> (respuesta)

**___:**

> (respuesta)

---

### 3. ¿Qué alfabeto usa?

**C:**

> (respuesta)

**___:**

> (respuesta)

---

### 4. ¿Cómo se resuelve la alocación de memoria?

**C:**

> (respuesta)

**___:**

> (respuesta)

---

### 5. ¿El tipo tiene mutabilidad o es inmutable?

**C:**

> (respuesta)

**___:**

> (respuesta)

---

### 6. ¿El tipo es un *first class citizen*?

**C:**

> (respuesta)

**___:**

> (respuesta)

---

### 7. ¿Cuál es la mecánica para ese tipo cuando se los pasa como argumentos?

**C:**

> (respuesta)

**___:**

> (respuesta)

---

### 8. ¿Y cuando son retornados por una función?

**C:**

> (respuesta)

**___:**

> (respuesta)

---

### 9. ¿Qué nivel de soporte tiene para ASCII, Unicode y UTF-8?

**C:**

> (respuesta)

**___:**

> (respuesta)

---

### Conclusión

> (síntesis comparativa — al menos un párrafo)

---

## Parte II — Biblioteca String

### ¿Cómo funcionan los tests?

Los tests están en `StringTest.c` y usan `assert`:

- Si el assert **pasa**: silencio.
- Si el assert **falla**: el programa imprime la línea que falló y aborta.
- Al final, si todo pasó: `./StringTest` termina sin salida y con exit code 0.

Para correr los tests:

```bash
make test
```

---

### Función 0: `IsEmpty` — ya implementada, leerla

Abrí `String.c`. `IsEmpty` ya está implementada y es la referencia de estilo:

```c
int IsEmpty(const char *s) {
    return *s == '\0';
}
```

`*s` desreferencia el puntero: accede al primer carácter. Un string en C termina siempre con el carácter nulo `'\0'`. Si el primero ya es `'\0'`, la cadena está vacía.

Los tests de `IsEmpty` ya están activos en `StringTest.c`. Corré `make test` y verificá que pasan.

**P1** — `IsEmpty` podría haberse escrito también como `return s[0] == '\0'`. ¿Son equivalentes? ¿Por qué?

> R:

---

### Función 1: `GetLength`

#### Tests

Abrí `StringTest.c` y **descomentá** el bloque de `GetLength`:

```c
/* ── GetLength ──────────────────────────────────────────────────────────── */
assert(GetLength("") == 0);
assert(GetLength("a") == 1);
assert(GetLength("hola") == 4);
assert(GetLength("hola mundo") == 10);
```

Corré los tests:

```bash
make test
```

Van a fallar porque `GetLength` todavía devuelve `-1`. Eso es lo esperado.

#### Especificación

Antes de implementar, completá en `String.md` la especificación matemática de `GetLength`. Ya está el caso base y el caso recursivo como referencia — revisá que los entendés.

#### Implementación

`GetLength` es el candidato para la implementación **recursiva**. Abrí `String.c`, encontrá `GetLength` y **reemplazá** todo el cuerpo de la función con:

```c
int GetLength(const char *s) {
    if (IsEmpty(s))
        return 0;
    return 1 + GetLength(s + 1);
}
```

Corré los tests:

```bash
make test
```

**P2** — ¿Qué hace `s + 1`? ¿Por qué avanza al siguiente carácter y no al siguiente byte?

> R:

**P3** — Si llamaras a `GetLength(NULL)`, ¿qué pasaría? ¿Por qué las precondiciones del contrato dicen `s != NULL`?

> R:

```
GETLENGTH_PASA=
```
_(escribí SI cuando todos los tests de GetLength pasen)_

---

### Función 2: `AreEqual`

#### Tests

Los tests de `AreEqual` ya están activos en `StringTest.c`. Corré `make test` — algunos van a fallar.

#### El bug

Abrí `String.c` y mirá la implementación de `AreEqual`:

```c
int AreEqual(const char *s1, const char *s2) {
    while (!IsEmpty(s1) && !IsEmpty(s2)) {
        if (*s1 != *s2)
            return 0;
        s1++;
        s2++;
    }
    return 1;  /* <-- acá está el bug */
}
```

El `while` termina cuando alguna de las dos cadenas llega a `'\0'`. Después devuelve `1` sin verificar nada más.

**P4** — ¿Qué dos casos están mal cubiertos por `return 1`? Describí un ejemplo para cada uno.

> R:

#### Corrección

Reemplazá la última línea de `AreEqual` en `String.c`:

```c
    return IsEmpty(s1) && IsEmpty(s2);
```

Corré los tests:

```bash
make test
```

```
AREEQUAL_PASA=
```
_(escribí SI cuando todos los tests de AreEqual pasen)_

---

### Función 3: `AreDecimalDigits`

#### Tests

Los tests de `AreDecimalDigits` ya están activos en `StringTest.c`. Corré `make test`.

Corré `make test`. Tres tests van a pasar pero uno va a fallar.

#### El bug

Abrí `String.c` y mirá `AreDecimalDigits`:

```c
int AreDecimalDigits(const char *s) {
    if (IsEmpty(s)) return 1;  /* <-- acá está el bug */
    for (const char *p = s; !IsEmpty(p); p++)
        if (*p < '0' || *p > '9')
            return 0;
    return 1;
}
```

**P5** — ¿Por qué la cadena vacía no debería considerarse un conjunto de dígitos decimales? Pensalo desde la especificación matemática.

> R:

#### Corrección

Corregí el valor de retorno para el caso de cadena vacía en `String.c`.

```bash
make test
```

```
AREDECIMALDIGITS_PASA=
```
_(escribí SI cuando todos los tests de AreDecimalDigits pasen)_

---

### Función 4: `Contains`

Esta función la implementás completamente vos.

#### Especificación

Completá en `String.md` la especificación de `Contains`.

#### Tests

Escribí al menos 4 tests en `StringTest.c` en el bloque de `Contains`. Incluí al menos un caso borde.

#### Implementación

Implementá `Contains` en `String.c`. No hay guía de estructura — usá lo aprendido de las funciones anteriores.

```bash
make test
```

```
CONTAINS_PASA=
```
_(escribí SI cuando todos los tests de Contains pasen)_

---

### Función 5: Operación libre

Elegí e implementá una operación de principio a fin:

1. Especificación matemática en `String.md`
2. Prototipo con pre/postcondiciones en `String.h`
3. Tests en `StringTest.c`
4. Implementación en `String.c`

Ideas: `Reverse`, `ToUpperCase`, `StartsWith`, `Trim`, `IndexOf`, `Repeat`.

**P6** — ¿Qué operación elegiste? ¿Por qué?

> R:

```
OPERACION_LIBRE=
```
_(nombre de la función)_

---

## Parte II.b — Módulo Conversion

Antes de implementar, discutí con tu equipo:

> ¿Tiene sentido que `ToInteger` sea parte de la biblioteca `String`?
> ¿O es correcto tenerla en un módulo separado `Conversion`?

**P7** — Conclusión de la discusión:

> R:

---

### Función: `ToInteger`

#### Tests

Los tests de `ToInteger` ya están activos en `ConversionTest.c`. Corré `make test` — todos van a fallar.

#### El bug

Abrí `Conversion.c` y mirá `ToInteger`:

```c
int ToInteger(const char *s) {
    int signo     = 1;
    int resultado = 0;
    if (*s == '-') { signo = -1; s++; }
    for (; *s != '\0'; s++)
        resultado = resultado * 10 + (*s - '0');
    return signo;  /* <-- acá está el bug */
}
```

**P8** — El loop acumula correctamente el valor en `resultado`. ¿Qué está mal en el `return`?

> R:

#### Corrección

Corregí la última línea de `ToInteger` en `Conversion.c`.

```bash
make test
```

**P9** — La expresión `*s - '0'` convierte un carácter dígito al entero correspondiente. ¿Por qué funciona? ¿Qué devuelve `'3' - '0'`?

> R:

```
TOINTEGER_PASA=
```
_(escribí SI cuando todos los tests de ToInteger pasen)_

---

## Parte III — Programas con argumentos

### Cómo recibir argumentos en C

```c
int main(int argc, char *argv[]) { ... }
```

- `argc`: cantidad total de argumentos (incluye el nombre del programa)
- `argv[0]`: nombre del ejecutable
- `argv[1]` en adelante: los argumentos reales
- `argv[argc]` es siempre `NULL` — se puede usar para iterar sin `argc`

### Referencia: `enlineas` — ya implementado, leerlo

Abrí `enlineas.c`. Está completo y muestra el patrón a seguir:

```c
int main(int argc, char *argv[]) {
    (void)argc;
    for (char **arg = argv + 1; *arg != NULL; arg++)
        printf("%s\n", *arg);
    return 0;
}
```

- `argv + 1` apunta al primer argumento real (saltea `argv[0]`)
- `char **arg` es un puntero a puntero: cada `*arg` es un `char *` (un string)
- `arg++` avanza al siguiente string
- `*arg != NULL` detecta el fin del arreglo

Compilá y probá:

```bash
make enlineas
./enlineas hola mundo foo
```

Salida esperada:
```
hola
mundo
foo
```

**P10** — ¿Por qué `(void)argc` suprime un warning? ¿Cuándo sería necesario usar `argc`?

> R:

---

### Programa: `longitudes`

Abrí `longitudes.c`. La estructura del `for` ya está escrita — solo falta completar el `printf`:

```c
for (char **arg = argv + 1; *arg != NULL; arg++)
    printf("%d\n", 0); /* completar: reemplazar 0 */
```

Reemplazá el `0` con la llamada correcta a `GetLength`.

```bash
make longitudes
./longitudes hola mundo
```

Salida esperada:
```
4
5
```

```
LONGITUDES_PASA=
```
_(SI o NO)_

---

### Programa: `mayorlongitud`

Abrí `mayorlongitud.c`. La estructura está escrita — falta completar una línea:

```c
char *mayor = argv[1];
for (char **arg = argv + 2; *arg != NULL; arg++)
    if (GetLength(*arg) > GetLength(mayor))
        mayor = NULL; /* completar: ¿qué debería guardarse en mayor? */
printf("%s\n", mayor);
```

Reemplazá el `NULL` con el valor correcto.

```bash
make mayorlongitud
./mayorlongitud uno largo
./mayorlongitud uno dos tres cuatro
```

```
MAYORLONGITUD_PASA=
```
_(SI o NO)_

---

### Programa: `todosiguales`

Implementá `todosiguales.c` completo. Usá `AreEqual` de `String.h`.

La pista está en el comentario del archivo: comparar cada argumento contra `argv[1]`.

```bash
make todosiguales
./todosiguales igual igual igual
./todosiguales uno dos
```

```
TODOSIGUALES_PASA=
```
_(SI o NO)_

---

### Programa: `suma`

Implementá `suma.c` completo. Usá `ToInteger` de `Conversion.h`.

```bash
make suma
./suma 1 2 3
./suma -5 10
```

```
SUMA_PASA=
```
_(SI o NO)_

---

## Preguntas de reflexión

**P11** — `GetLength` es recursiva pero en C una llamada recursiva consume un stack frame. Si llamaras `GetLength` con un string de 1.000.000 de caracteres, ¿qué pasaría? ¿Cómo lo resolverías?

> R:

**P12** — En la Parte III, todos los programas usan `char **arg` para iterar en vez de un índice entero. ¿Qué ventaja tiene este estilo? ¿Cuándo sería preferible usar el índice?

> R:

**P13** — En C, `"hola"` es un literal de tipo `const char *`. Si intentaras modificar un carácter con `s[0] = 'H'`, el comportamiento es indefinido. ¿Por qué? ¿En qué parte de la memoria viven los literales?

> R:

---

## Entrega

- [ ] `AnalisisComparativo.md` completado
- [ ] `String.md` con especificaciones de todas las operaciones
- [ ] `String.c` con todas las funciones implementadas y tests pasando
- [ ] `Conversion.c` con `ToInteger` corregida y tests pasando
- [ ] `make test` sin errores
- [ ] Los 5 programas funcionando: `make all`
- [ ] Push a `main`

```bash
git add .
git commit -m "Implementacion completa del laboratorio strings"
git push
```

El CI corre automáticamente. En la pestaña **Actions** podés ver qué checks pasan y cuáles fallan.
