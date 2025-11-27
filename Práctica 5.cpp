#include <stdio.h>

typedef struct {
    int datos[5];
    int tope;
} Pila;


typedef struct {
    int datos[5];
    int frente;
    int final;
} Cola;

/* PUSH */
void push(Pila *p, int x) {
    if (p->tope == 4) {
        printf("Pila llena.\n");
        return;
    }
    p->datos[++(p->tope)] = x;
}

/* POP */
int pop(Pila *p, int *x) {
    if (p->tope == -1) {
        printf("Pila vacia.\n");
        return 0;
    }
    *x = p->datos[(p->tope)--];
    return 1;
}

/* ENQUEUE */
void enqueue(Cola *c, int x) {
    if (c->final == 4) {
        printf("Cola llena.\n");
        return;
    }
    c->datos[++(c->final)] = x;
}

/* DEQUEUE */
int dequeue(Cola *c, int *x) {
    if (c->frente > c->final) {
        printf("Cola vacia.\n");
        return 0;
    }
    *x = c->datos[(c->frente)++];
    return 1;
}

int main() {

    Pila pila;
    Cola cola;
    int n, cant, valor, extraido;
    int i;

    /* Paso 1. Crear una pila */
    pila.tope = -1;
    printf("Pila inicializada vacia\n");

    /* Paso 2. Insertar elementos (PUSH) */
    printf("\nCuantos elementos quieres apilar (Maximo 5)? ");
    scanf("%d", &n);
    if (n > 5) n = 5;

    for (i = 0; i < n; i++) {
        printf("Valor a apilar [%d]: ", i);
        scanf("%d", &valor);
        push(&pila, valor);

        printf("Pila: ");
        if (pila.tope == -1) printf("vacia");
        else for (int j = pila.tope; j >= 0; j--) printf("%d ", pila.datos[j]);
        printf("\n");
    }

    /* Paso 3. Extraer elementos (POP) */
    printf("\nCuantos elementos quieres desapilar? ");
    scanf("%d", &cant);

    for (i = 0; i < cant; i++) {
        if (pop(&pila, &extraido)) {
            printf("Elemento desapilado: %d\n", extraido);
            printf("Pila: ");
            if (pila.tope == -1) printf("vacia");
            else for (int j = pila.tope; j >= 0; j--) printf("%d ", pila.datos[j]);
            printf("\n");
        } else break;
    }

    /* Paso 4. Crear una cola */
    cola.frente = 0;
    cola.final = -1;
    printf("\nCola inicializada vacia\n");

    /* Paso 5. Insertar elementos (ENQUEUE) */
    printf("\nCuantos elementos quieres encolar (max 5)? ");
    scanf("%d", &n);
    if (n > 5) n = 5;

    for (i = 0; i < n; i++) {
        printf("Valor a encolar [%d]: ", i);
        scanf("%d", &valor);
        enqueue(&cola, valor);

        printf("Cola: ");
        if (cola.frente > cola.final) printf("vacia");
        else for (int j = cola.frente; j <= cola.final; j++) printf("%d ", cola.datos[j]);
        printf("\n");
    }

    /* Paso 6. Extraer elementos (DEQUEUE) */
    printf("\nCuantos elementos quieres desencolar? ");
    scanf("%d", &cant);

    for (i = 0; i < cant; i++) {
        if (dequeue(&cola, &extraido)) {
            printf("Elemento desencolado: %d\n", extraido);
            printf("Cola: ");
            if (cola.frente > cola.final) printf("vacia");
            else for (int j = cola.frente; j <= cola.final; j++) printf("%d ", cola.datos[j]);
            printf("\n");
        } else break;
    }

    /* Paso 7. Comparación */
    printf("\nResumen:\n");
    printf("Pila -> LIFO (ultimo en entrar, primero en salir).\n");
    printf("Cola -> FIFO (primero en entrar, primero en salir).\n");

    return 0;
}
