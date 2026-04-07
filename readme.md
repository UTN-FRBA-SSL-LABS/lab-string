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

Verificá que todo compila desde el estado inicial:

```bash
make test
make all
```

Si no hay errores, estás listo para empezar.

---

## Restricciones (leer antes de arrancar)

Aplican a todo el laboratorio:

- **No usar `<string.h>`** ni funciones como `strlen`, `strcmp`, `strcpy`
- **No usar `<stdlib.h>`** para conversiones (`atoi`, `strtol`)
- Usar **`const`** en parámetros que no se modifican
- Al menos **una función** de `String.c` debe implementarse con **recursividad**
- Los tests usan **`assert`** — sin `printf`, sin salida de ningún tipo
- Los tests usan **literales de cadena**, no variables
  ✅ `assert(GetLength("hola") == 4)`
  ❌ `char *s = "hola"; assert(GetLength(s) == 4)`
- Los programas de la Parte III iteran con **puntero** (`char **arg`), no con índice entero

---

## Parte I — Análisis Comparativo

Abrí `AnalisisComparativo.md` y completá la comparación de strings en C versus un lenguaje de tu elección. El archivo ya tiene las 9 preguntas con espacio para responder.

Podés hacerlo en cualquier momento del laboratorio.

---

## Parte II — Biblioteca String

Para cada operación el ciclo es siempre el mismo:

```
1. Especificación matemática en String.md
2. Descomentar los tests en StringTest.c  →  make test  (va a fallar)
3. Implementar en String.c               →  make test  (tiene que pasar)
```

### Cómo correr los tests

```bash
make test
```

Si todos los `assert` pasan: silencio total y exit 0. Si alguno falla: el programa imprime en qué línea falló y aborta.

---

### Operación 1: `GetLength`

#### 1.1 Especificación

La especificación matemática de `GetLength` ya está en `String.md`. Leela antes de continuar.

#### 1.2 Tests

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

Deberían fallar porque la implementación todavía devuelve `0`.

#### 1.3 Implementación

`GetLength` es el candidato natural para la implementación **recursiva**. Completá los blancos en `String.c`:

```c
int GetLength(const char *s) {
    if (IsEmpty(s))
        return ____;               /* caso base: cadena vacía tiene longitud 0 */
    return 1 + GetLength(s + ____); /* avanzar un caracter y contar */
}
```

**P1** — ¿Por qué `s + 1` avanza un carácter en vez de acceder al índice 1?

> R:

Corré los tests de nuevo:

```bash
make test
```

```
GETLENGTH_PASA=
```
_(SI o NO)_

---

### Operación 2: `AreEqual`

#### 2.1 Especificación

Completá en `String.md` la especificación de `AreEqual`. Tené en cuenta los casos:
- ¿Qué pasa si las dos cadenas son vacías?
- ¿Qué pasa si tienen distinta longitud?
- ¿Qué pasa si difieren en un caracter?

#### 2.2 Tests

Descomentá el bloque de `AreEqual` en `StringTest.c`:

```c
/* ── AreEqual ───────────────────────────────────────────────────────────── */
assert(AreEqual("", "") == 1);
assert(AreEqual("abc", "abc") == 1);
assert(AreEqual("abc", "abd") == 0);
assert(AreEqual("abc", "ab") == 0);
assert(AreEqual("ab", "abc") == 0);
```

Corré `make test` — va a fallar.

#### 2.3 Implementación

Completá `AreEqual` en `String.c`. Podés usar un `for` o recursividad.

Pista: si los primeros caracteres son iguales y el resto también lo es, las cadenas son iguales.

Corré `make test`.

```
AREEQUAL_PASA=
```
_(SI o NO)_

---

### Operación 3: `AreDecimalDigits`

#### 3.1 Especificación

Completá en `String.md`. Recordá que un dígito decimal es un caracter entre `'0'` y `'9'`, y que la cadena vacía no es un conjunto de dígitos decimales.

#### 3.2 Tests

Descomentá el bloque de `AreDecimalDigits` en `StringTest.c`:

```c
/* ── AreDecimalDigits ───────────────────────────────────────────────────── */
assert(AreDecimalDigits("0") == 1);
assert(AreDecimalDigits("123") == 1);
assert(AreDecimalDigits("12a") == 0);
assert(AreDecimalDigits("") == 0);
```

#### 3.3 Implementación

Completá `AreDecimalDigits` en `String.c`.

Pista: un caracter `c` es un dígito si `c >= '0' && c <= '9'`. Iterá con un `for` basado en puntero.

**P2** — ¿Por qué la cadena vacía devuelve `0` y no `1`?

> R:

Corré `make test`.

```
AREDECIMALDIGITS_PASA=
```
_(SI o NO)_

---

### Operación 4: `Contains`

Esta operación la escribís completamente vos.

#### 4.1 Especificación

Completá en `String.md`.

#### 4.2 Tests

Escribí al menos 4 tests en `StringTest.c` para `Contains`. Incluí casos borde.

#### 4.3 Implementación

Implementá `Contains` en `String.c`.

Corré `make test`.

```
CONTAINS_PASA=
```
_(SI o NO)_

---

### Operación 5: Libre

Elegí una operación e implementala de principio a fin:
- Especificación en `String.md`
- Prototipo + contrato en `String.h`
- Tests en `StringTest.c`
- Implementación en `String.c`

Algunas ideas: `Reverse`, `ToUpperCase`, `StartsWith`, `Trim`, `IndexOf`.

**P3** — ¿Qué operación elegiste y por qué?

> R:

```
OPERACION_LIBRE=
```
_(nombre de la función)_

---

## Parte II.b — Módulo Conversion

Antes de implementar, discutí con tu equipo:

> ¿Es correcto que `ToInteger` sea parte de la biblioteca de Strings?
> ¿O tiene más sentido en un módulo separado? ¿Por qué?

**P4** — Conclusión de la discusión:

> R:

### `ToInteger`

#### Tests

Abrí `ConversionTest.c` y **descomentá** el bloque de `ToInteger`:

```c
/* ── ToInteger ──────────────────────────────────────────────────────────── */
assert(ToInteger("0") == 0);
assert(ToInteger("1") == 1);
assert(ToInteger("42") == 42);
assert(ToInteger("-7") == -7);
assert(ToInteger("100") == 100);
```

Corré `make test` — va a fallar.

#### Implementación

Completá `ToInteger` en `Conversion.c`.

Pista: iterá sobre los dígitos, acumulando el resultado. Para convertir un dígito carácter a entero: `c - '0'`.

```c
int ToInteger(const char *s) {
    int signo = 1;
    int resultado = 0;
    if (*s == '-') { signo = ____; s++; }
    for (; *s != '\0'; s++)
        resultado = resultado * ____ + (*s - '0');
    return signo * resultado;
}
```

Corré `make test`.

```
TOINTEGER_PASA=
```
_(SI o NO)_

---

## Parte III — Programas con argumentos

### Referencia: `enlineas`

`enlineas.c` está completo. Leelo antes de seguir:

```c
int main(int argc, char *argv[]) {
    (void)argc;
    for (char **arg = argv + 1; *arg != NULL; arg++)
        printf("%s\n", *arg);
    return 0;
}
```

Puntos clave:
- `argv[0]` es el nombre del ejecutable; los argumentos reales empiezan en `argv[1]`
- `argv` termina con un puntero `NULL` — se puede iterar sin usar `argc`
- `char **arg = argv + 1` apunta al primer argumento real
- `arg++` avanza al siguiente; `*arg != NULL` detecta el fin

Probalo:

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

**P5** — En `enlineas`, `(void)argc` suprime un warning de compilación. ¿Por qué `argc` no se usa si el programa recibe argumentos?

> R:

---

### Programa: `longitudes`

Imprime la longitud de cada argumento, una por línea.

Copiá este código en `longitudes.c` (reemplazando el TODO):

```c
int main(int argc, char *argv[]) {
    (void)argc;
    for (char **arg = argv + 1; *arg != NULL; arg++)
        printf("%d\n", GetLength(____));  /* completar */
    return 0;
}
```

Compilá y probá:

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

Imprime el argumento con mayor longitud. En caso de empate, el primero.

Estructura sugerida para `mayorlongitud.c`:

```c
int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    char *mayor = argv[1];
    for (char **arg = argv + 2; *arg != NULL; arg++)
        if (GetLength(*arg) > GetLength(mayor))
            mayor = ____;     /* completar */
    printf("%s\n", mayor);
    return 0;
}
```

Compilá y probá:

```bash
make mayorlongitud
./mayorlongitud corto largo
./mayorlongitud uno dos tres
```

```
MAYORLONGITUD_PASA=
```
_(SI o NO)_

---

### Programa: `todosiguales`

Imprime `1` si todos los argumentos son iguales, `0` si no.

Escribí `todosiguales.c` completo. Usá `AreEqual` de `String.h`.

```bash
make todosiguales
./todosiguales igual igual igual   # → 1
./todosiguales uno dos             # → 0
```

```
TODOSIGUALES_PASA=
```
_(SI o NO)_

---

### Programa: `suma`

Imprime la suma de todos los argumentos interpretados como enteros.

Escribí `suma.c` completo. Usá `ToInteger` de `Conversion.h`.

```bash
make suma
./suma 1 2 3    # → 6
./suma -5 10    # → 5
```

```
SUMA_PASA=
```
_(SI o NO)_

---

## Preguntas de reflexión

**P6** — En C, un string es un arreglo de `char` terminado en `'\0'`. ¿Qué problema tendría `GetLength` si una cadena no terminara en `'\0'`?

> R:

**P7** — `IsEmpty` y `GetLength` resuelven el mismo problema de forma diferente: `IsEmpty("") == 1` y `GetLength("") == 0`. ¿Podrías implementar `IsEmpty` usando `GetLength`? ¿Tiene sentido hacerlo?

> R:

**P8** — `AreDecimalDigits` podría implementarse usando `Contains` repetido para cada dígito. ¿Por qué esa implementación sería incorrecta?

> R:

---

## Entrega

```bash
git add .
git commit -m "Implementacion completa del laboratorio strings"
git push
```

El CI corre automáticamente. En la pestaña **Actions** podés ver qué checks pasan y cuáles fallan.
