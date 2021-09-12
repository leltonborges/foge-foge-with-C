#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "foge.h"
#include "mapa.h"

void encontramapa(MAPA *m, POSICAO *p, char c) {
    for (int i = 0; i < m->linhas; ++i) {
        for (int j = 0; j < m->colunas; ++j) {
            if (m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

void liberamapa(MAPA *m) {
    for (int i = 0; i < m->linhas; ++i) {
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void lermapa(MAPA *m) {
    FILE *f;
    f = fopen("mapa.txt", "r");
    if (f == 0) {
        printf("erro na leitura do mapa\n");
        exit(1);
    }
    fscanf(f, " %d %d", &(m->linhas), &(m->colunas));
    alocamapa(m);

    for (int i = 0; i < 5; ++i) {
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void alocamapa(MAPA *m) {
    m->matriz = malloc(sizeof(char *) * m->linhas);
    for (int i = 0; i < m->linhas; ++i) {
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}

void imprirmapa(MAPA *m) {
    for (int i = 0; i < 5; ++i) {
        printf("%s\n", m->matriz[i]);
    }
}

int ehvalida(MAPA *m, int x, int y) {

    if (x >= m->linhas)
        return 0;
    if (y >= m->colunas)
        return 0;

    return 1;
}

int ehvazia(MAPA *m, int x, int y) {
    return m->matriz[x][y] == VAZIO;
}

void andanomapa(MAPA *m, int xorigem, int yorigem, int xdestido, int ydestido) {
    char personagem = m->matriz[xorigem][yorigem];
    m->matriz[xdestido][ydestido] = personagem;
    m->matriz[xorigem][yorigem] = VAZIO;
}

void copiamapa(MAPA* destino, MAPA* origem) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;
    alocamapa(destino);
    for(int i = 0; i < origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}