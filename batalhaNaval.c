#include <stdio.h>

#define TAMANHO 10

int main() {
    // 1. Inicialização do Tabuleiro
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // --- NÍVEL NOVATO & AVENTUREIRO: Posicionamento de Navios ---
    
    // Navio Horizontal (representado por 3)
    for (int j = 1; j <= 3; j++) tabuleiro[2][j] = 3;

    // Navio Vertical
    for (int i = 5; i <= 7; i++) tabuleiro[i][8] = 3;

    // Navios Diagonais
    // Diagonal Descendente
    for (int i = 0; i < 3; i++) tabuleiro[i][i] = 3;
    
    // Diagonal Ascendente
    for (int i = 0; i < 3; i++) tabuleiro[9-i][i] = 3;


    // --- NÍVEL MESTRE: Habilidades Especiais ---
    // Usaremos o valor 1 para representar a área de efeito das habilidades

    // 1. Habilidade em CONE
    // Baseado em um ponto de origem, expande a largura a cada linha
    int coneOrigemX = 1, coneOrigemY = 4;
    for (int i = 0; i < 3; i++) { // Altura do cone
        for (int j = -i; j <= i; j++) {
            tabuleiro[coneOrigemX + i][coneOrigemY + j] = 1;
        }
    }

    // 2. Habilidade em CRUZ
    int cruzCentroX = 5, cruzCentroY = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) { // Cria a linha e coluna central
                tabuleiro[cruzCentroX + i - 2][cruzCentroY + j - 2] = 1;
            }
        }
    }

    // 3. Habilidade em OCTAEDRO (Losango)
    int octCentroX = 8, octCentroY = 5;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Lógica de distância de Manhattan: preenche se não for um canto
            if ((i == 1) || (j == 1)) {
                tabuleiro[octCentroX + i - 1][octCentroY + j - 1] = 1;
            }
        }
    }

    // --- EXIBIÇÃO DO RESULTADO FINAL ---
    printf("TABULEIRO BATALHA NAVAL - MESTRE\n");
    printf("(0: Água | 3: Navio | 1: Habilidade)\n\n");

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}