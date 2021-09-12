#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou();

int ehdirecao(char direcao);

void move(char dicecao);

void fantasma();
int paraondefantasmavai(int xatual, int yatual, int *xdestino, int *ydestino);