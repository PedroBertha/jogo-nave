#include <stdio.h>      // biblioteca de entrada e saída (printf, scanf)
#include <stdlib.h>     // biblioteca para funções gerais (rand, system)
#include <time.h>       // usada para gerar números aleatórios baseados no tempo
#include <conio.h>      // permite capturar tecla sem pressionar ENTER (getch, kbhit)
#include <windows.h>    // permite usar Sleep para controlar velocidade do jogo

// tamanho da tela do jogo
#define ALTURA 20
#define LARGURA 30

// estrutura que representa a nave do jogador
struct Nave {
    int x; // posição horizontal da nave
};

// matriz que representa a tela do jogo
char tela[ALTURA][LARGURA];

// variável que guarda o recorde de pontuação
int recorde = 0;

// limpa a tela do terminal
void limparTela() {
    system("cls");
}

// inicializa a matriz da tela preenchendo com espaços vazios
void inicializarTela() {
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            tela[i][j] = ' ';
        }
    }
}

// desenha a borda superior ou inferior do jogo
void desenharBorda() {
    for (int i = 0; i < LARGURA + 2; i++) {
        printf("#");
    }
    printf("\n");
}

// desenha toda a tela do jogo
void desenharTela(struct Nave nave) {

    // coloca a nave na última linha da matriz
    tela[ALTURA-1][nave.x] = '^';

    // percorre toda a matriz imprimindo os caracteres
    for (int i = 0; i < ALTURA; i++) {

        printf("#"); // borda esquerda

        for (int j = 0; j < LARGURA; j++) {
            printf("%c", tela[i][j]);
        }

        printf("#\n"); // borda direita
    }

    // remove a nave da matriz para evitar duplicação no próximo frame
    tela[ALTURA-1][nave.x] = ' ';
}

// move todos os obstáculos uma linha para baixo
void moverObstaculos() {

    for (int i = ALTURA-1; i > 0; i--) {
        for (int j = 0; j < LARGURA; j++) {
            tela[i][j] = tela[i-1][j];
        }
    }

    // limpa a primeira linha da tela
    for (int j = 0; j < LARGURA; j++) {
        tela[0][j] = ' ';
    }
}

// gera novos obstáculos aleatórios no topo da tela
void gerarObstaculos() {

    // define quantos obstáculos aparecerão (0 ou 1)
    int quantidade = rand() % 2;

    for (int i = 0; i < quantidade; i++) {

        // escolhe posição aleatória na largura da tela
        int pos = rand() % LARGURA;

        // coloca obstáculo apenas se a posição estiver vazia
        if (tela[0][pos] == ' ')
            tela[0][pos] = 'O';
    }
}

// verifica se a nave colidiu com um obstáculo
int verificarColisao(struct Nave nave) {

    if (tela[ALTURA-1][nave.x] == 'O') {
        return 1; // colisão detectada
    }

    return 0; // nenhuma colisão
}

// espera o jogador pressionar alguma tecla
void esperarTecla() {
    printf("\nPressione qualquer tecla...");
    getch();
}

// mostra o menu inicial do jogo
void mostrarMenu() {

    limparTela();

    printf("================================\n");
    printf("        JOGO DA NAVE            \n");
    printf("================================\n\n");

    printf("1 - Jogar\n");
    printf("2 - Sair\n\n");

    printf("Escolha: ");
}

// função principal do jogo
void jogar() {

    struct Nave nave;

    // posição inicial da nave no centro da tela
    nave.x = LARGURA / 2;

    int pontuacao = 0;  // pontuação atual
    int velocidade = 200; // velocidade do jogo (delay)
    int jogo = 1; // controla se o jogo continua rodando

    inicializarTela();

    // loop principal do jogo
    while (jogo) {

        limparTela();

        // move obstáculos existentes
        moverObstaculos();

        // gera novos obstáculos
        gerarObstaculos();

        // verifica colisão com a nave
        if (verificarColisao(nave)) {

            // atualiza recorde se necessário
            if (pontuacao > recorde) {
                recorde = pontuacao;
            }

            printf("\n########### GAME OVER ###########\n");
            printf("Pontuacao: %d\n", pontuacao);
            printf("Recorde: %d\n", recorde);

            esperarTecla();
            break;
        }

        // desenha a tela do jogo
        desenharBorda();
        desenharTela(nave);
        desenharBorda();

        // mostra informações do jogo
        printf("\nPontuacao: %d\n", pontuacao);
        printf("Recorde: %d\n", recorde);

        printf("\nA = esquerda | D = direita | Q = sair\n");

        // verifica se alguma tecla foi pressionada
        if (kbhit()) {

            char comando = getch();

            // move nave para esquerda
            if (comando == 'a' || comando == 'A') {
                if (nave.x > 0) nave.x--;
            }

            // move nave para direita
            if (comando == 'd' || comando == 'D') {
                if (nave.x < LARGURA-1) nave.x++;
            }

            // sai do jogo
            if (comando == 'q' || comando == 'Q') {
                jogo = 0;
            }
        }

        // aumenta pontuação com o tempo
        pontuacao++;

        // aumenta dificuldade diminuindo o tempo entre frames
        if (pontuacao % 20 == 0 && velocidade > 60) {
            velocidade -= 10;
        }

        // controla a velocidade do jogo
        Sleep(velocidade);
    }
}

// função principal do programa
int main() {

    // inicializa gerador de números aleatórios
    srand(time(NULL));

    int opcao;

    // loop infinito do menu
    while (1) {

        mostrarMenu();

        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                jogar(); // inicia o jogo
                break;

            case 2:
                printf("Saindo...\n");
                return 0;

            default:
                printf("Opcao invalida\n");
                esperarTecla();
        }
    }

    return 0;
}