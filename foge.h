#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

int acabou();

int ehdirecao(char direcao);

void move(char dicecao);

void fantasma();

int paraondefantasma(int xatual, int yatual, int *xdestino, int *ydestino);
void explodepilula();
void explodepiluladirecao(int x, int y, int somax, int somay, int qtd);