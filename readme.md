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

---

## Estructura del proyecto

```
lab-string/
├── String.h          ← interfaz de la biblioteca (prototipos + contratos)
├── String.c          ← implementación (completar)
├── StringTest.c      ← pruebas con assert (completar)
├── Conversion.h      ← interfaz del módulo de conversión
├── Conversion.c      ← implementación (completar)
├── ConversionTest.c  ← pruebas con assert (completar)
├── enlineas.c        ← programa completo (referencia)
├── longitudes.c      ← programa (completar)
├── mayorlongitud.c   ← programa (completar)
├── todosiguales.c    ← programa (completar)
├── suma.c            ← programa (completar)
├── Makefile
├── String.md         ← especificación matemática (completar)
└── AnálisisComparativo.md  ← análisis (completar)
```

---

## Restricciones generales

Estas restricciones aplican a todo el laboratorio:

- **No usar `<string.h>`** ni funciones estándar de cadenas (`strlen`, `strcmp`, etc.)
- **No usar `<stdlib.h>`** para conversiones (`atoi`, `strtol`, etc.)
- Usar **`const`** en parámetros que no se modifican
- Al menos **una función** de `String.c` debe implementarse con **recursividad**
- Los tests usan **`assert`** — sin `printf`, sin salida a ningún flujo
- Los tests usan **literales de cadena**, no variables (`assert(GetLength("hola") == 4)`)
- Los programas de la Parte III iteran con **puntero** (`char **arg`), no con índice entero

---

## Parte I — Análisis Comparativo

Completá `AnálisisComparativo.md` comparando strings en C con otro lenguaje a elección.

El archivo ya tiene las 9 preguntas. Respondé cada una para ambos lenguajes y agregá una conclusión al final.

---

## Parte II — Biblioteca String

El orden de desarrollo para **cada operación** es:

```
1. Especificación matemática en String.md
2. Prototipo + pre/postcondiciones en String.h
3. Tests en StringTest.c  (primero los tests — aunque fallen)
4. Implementación en String.c
5. make test  →  verificar que pasa
```

### Referencia: IsEmpty

`IsEmpty` ya está implementada. Usala como referencia para entender la estructura.

**String.h** define el contrato:
```c
/* IsEmpty: String -> Boolean
 * Pre:  s != NULL
 * Post: devuelve 1 si s es la cadena vacia, 0 si no */
int IsEmpty(const char *s);
```

**StringTest.c** verifica el contrato con literales:
```c
assert(IsEmpty("") == 1);
assert(IsEmpty("a") == 0);
```

**String.c** implementa:
```c
int IsEmpty(const char *s) {
    return *s == '\0';
}
```

### Operaciones a implementar

En este orden:

1. **`GetLength`** — usá recursividad aquí
2. **`AreEqual`**
3. **`AreDecimalDigits`**
4. **`Contains`**
5. **Una operación libre** — definila vos (ejemplos: `Reverse`, `ToUpper`, `StartsWith`, `Trim`)

Para cada una: especificación en `String.md` → prototipo en `String.h` → tests en `StringTest.c` → implementación en `String.c`.

### Correr los tests

```bash
make test
```

Si todos los assert pasan: silencio y exit 0. Si alguno falla: el programa imprime en qué línea y hace abort.

### Nota sobre Conversion

`ToInteger` está separada en `Conversion.h` / `Conversion.c` porque convierte entre tipos distintos (String → Integer). Antes de implementarla, discutí con tu equipo:

> ¿Es correcto que `ToInteger` sea parte de la biblioteca de Strings?
> ¿O tiene más sentido separarla? ¿Por qué?

Escribí la conclusión de la discusión acá:

> R: (respuesta del equipo)

---

## Parte III — Programas con argumentos

### Referencia: enlineas

`enlineas.c` está completo. Leelo antes de arrancar con los demás:

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

### Programas a implementar

| Programa | Descripción | Usa |
|---|---|---|
| `longitudes` | longitud de cada argumento, una por línea | `GetLength` |
| `mayorlongitud` | argumento con mayor longitud | `GetLength` |
| `todosiguales` | `1` si todos iguales, `0` si no | `AreEqual` |
| `suma` | suma de los argumentos como enteros | `ToInteger` |

Compilar y probar todos:

```bash
make all
./longitudes hola mundo      # → 4 / 5
./mayorlongitud corto largo  # → largo
./todosiguales a a a         # → 1
./todosiguales a b           # → 0
./suma 1 2 3                 # → 6
```

---

## Entrega

- [ ] `AnálisisComparativo.md` completo (9 preguntas respondidas + conclusión)
- [ ] `String.md` con especificación matemática de todas las operaciones
- [ ] `String.h` con prototipos, pre y postcondiciones
- [ ] `String.c` con todas las operaciones implementadas (al menos una recursiva)
- [ ] `StringTest.c` con tests descomentados y pasando
- [ ] `Conversion.h`, `Conversion.c`, `ConversionTest.c` completos
- [ ] Los 5 programas implementados y funcionando
- [ ] `make test` pasa sin errores
- [ ] `make all` compila sin errores ni warnings
- [ ] Push a `main`

```bash
git add .
git commit -m "Implementacion completa del laboratorio strings"
git push
```
