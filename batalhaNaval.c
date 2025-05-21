#include <stdio.h>
#define TAMANHO 10

void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n  ");
    for (int x = 0; x < TAMANHO; x++) {
        printf("%2d ", x);
    }
    printf("\n");
    
    for (int y = 0; y < TAMANHO; y++) {
        printf("%2d ", y);
        for (int x = 0; x < TAMANHO; x++) {
            printf("%2d ", tabuleiro[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa com 0 (água)
    
    // Navio horizontal (4 posições)
    for (int i = 0; i < 4; i++) {
        tabuleiro[2][3 + i] = 3; // Linha 2, colunas 3-6
    }
    
    // Navio vertical (3 posições)
    for (int i = 0; i < 3; i++) {
        tabuleiro[5 + i][7] = 3; // Coluna 7, linhas 5-7
    }
    
    // Navio diagonal direita (3 posições)
    for (int i = 0; i < 3; i++) {
        tabuleiro[1 + i][1 + i] = 3; // Diagonal principal
    }
    
    // Navio diagonal esquerda (2 posições)
    for (int i = 0; i < 2; i++) {
        tabuleiro[6 + i][8 - i] = 3; // Diagonal secundária
    }
    
    printf("=== BATALHA NAVAL - NÍVEL AVENTUREIRO ===\n");
    printf("Tabuleiro 10x10 com 4 navios:\n");
    printf("3 = Navio, 0 = Água\n");
    
    printf("\nNavios posicionados:");
    printf("\n- Horizontal: Linha 2, Colunas 3-6");
    printf("\n- Vertical: Coluna 7, Linhas 5-7");
    printf("\n- Diagonal direita: (1,1) a (3,3)");
    printf("\n- Diagonal esquerda: (6,8) a (7,7)");
    
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}