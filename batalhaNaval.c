#include <stdio.h>
#define TAMANHO 8

void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n  ");
    for (int x = 0; x < TAMANHO; x++) {
        printf("%d ", x);
    }
    printf("\n");
    
    for (int y = 0; y < TAMANHO; y++) {
        printf("%d ", y);
        for (int x = 0; x < TAMANHO; x++) {
            if (tabuleiro[y][x] == 1) {
                printf("N "); // Navio
            } else {
                printf(". "); // Água
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa com 0 (água)
    
    // Navio horizontal (3 posições)
    int navio_horizontal_x = 2, navio_horizontal_y = 3;
    for (int i = 0; i < 3; i++) {
        tabuleiro[navio_horizontal_y][navio_horizontal_x + i] = 1;
    }
    
    // Navio vertical (2 posições)
    int navio_vertical_x = 5, navio_vertical_y = 1;
    for (int i = 0; i < 2; i++) {
        tabuleiro[navio_vertical_y + i][navio_vertical_x] = 1;
    }
    
    printf("=== BATALHA NAVAL - NÍVEL NOVATO ===\n");
    printf("Navio horizontal: linha %d, colunas %d a %d\n", 
           navio_horizontal_y, navio_horizontal_x, navio_horizontal_x + 2);
    printf("Navio vertical: coluna %d, linhas %d a %d\n", 
           navio_vertical_x, navio_vertical_y, navio_vertical_y + 1);
    
    printf("\nRepresentação do tabuleiro:\n");
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}