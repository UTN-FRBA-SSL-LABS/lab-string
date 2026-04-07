# Especificación de la Biblioteca String

## Notación

| Símbolo | Significado |
|---|---|
| `s`, `t` | cadena (tipo String) |
| `c` | carácter (tipo Char) |
| `ε` | cadena vacía `""` |
| `\|s\|` | longitud de la cadena `s` |
| `s[i]` | i-ésimo carácter de `s` (base 0) |
| `s[1..]` | subcadena de `s` desde la posición 1 hasta el final |
| `𝔹` | Boolean = {0, 1} |
| `ℕ₀` | naturales incluyendo el 0 |

---

## IsEmpty

**Signatura:** `IsEmpty : String → 𝔹`

**Especificación:**
```
IsEmpty(s) = 1   si s = ε
IsEmpty(s) = 0   si s ≠ ε
```

---

## GetLength

**Signatura:** `GetLength : String → ℕ₀`

**Especificación:**
```
GetLength(ε)   = 0
GetLength(s)   = 1 + GetLength(s[1..])   si s ≠ ε
```

---

## AreEqual

**Signatura:** `AreEqual : String × String → 𝔹`

**Especificación:** (completar)

```
AreEqual(s, t) = ...
```

---

## AreDecimalDigits

**Signatura:** `AreDecimalDigits : String → 𝔹`

**Especificación:** (completar)

```
AreDecimalDigits(s) = ...
```

---

## Contains

**Signatura:** `Contains : String × Char → 𝔹`

**Especificación:** (completar)

```
Contains(s, c) = ...
```

---

## Operación libre

**Nombre:** (definir)

**Signatura:** (completar)

**Especificación:** (completar)
