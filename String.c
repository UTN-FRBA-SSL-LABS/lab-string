#include "String.h"

/*
 * String.c — Implementacion de la biblioteca String
 *
 * Restriccion: no usar funciones de <string.h>
 * Recordatorio: al menos una funcion debe implementarse con recursividad.
 */

/* IsEmpty esta implementada como referencia.
 * Las demas son TODO. */

int IsEmpty(const char *s) {
    return *s == '\0';
}

int GetLength(const char *s) {
    /* TODO: implementar — sugerencia: usar recursividad */
    (void)s;
    return 0;
}

int AreEqual(const char *s1, const char *s2) {
    /* TODO */
    (void)s1; (void)s2;
    return 0;
}

int AreDecimalDigits(const char *s) {
    /* TODO */
    (void)s;
    return 0;
}

int Contains(const char *s, char c) {
    /* TODO */
    (void)s; (void)c;
    return 0;
}

/* TODO: implementar la operacion libre definida en String.h */
