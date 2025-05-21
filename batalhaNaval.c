#include <stdio.h>
#define TAMANHO 10
#define HAB_TAM 5  // Tamanho das matrizes de habilidade

// Função para imprimir o tabuleiro principal
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

// Função para imprimir uma matriz de habilidade
void imprimirHabilidade(int matriz[HAB_TAM][HAB_TAM]) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para criar padrão de cone
void criarCone(int matriz[HAB_TAM][HAB_TAM]) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (j >= (HAB_TAM/2 - i/2) && j <= (HAB_TAM/2 + i/2) && i <= HAB_TAM/2 + 1) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para criar padrão de cruz
void criarCruz(int matriz[HAB_TAM][HAB_TAM]) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (i == HAB_TAM/2 || j == HAB_TAM/2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para criar padrão de octaedro
void criarOctaedro(int matriz[HAB_TAM][HAB_TAM]) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if ((i == HAB_TAM/2) || (j == HAB_TAM/2 && (i == HAB_TAM/2 - 1 || i == HAB_TAM/2 + 1))) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Tabuleiro principal
    
    // Posicionando alguns navios (como no nível aventureiro)
    for (int i = 0; i < 4; i++) tabuleiro[2][3 + i] = 3; // Navio horizontal
    for (int i = 0; i < 3; i++) tabuleiro[5 + i][7] = 3; // Navio vertical
    
    printf("=== BATALHA NAVAL - NÍVEL MESTRE ===\n");
    printf("=== HABILIDADES ESPECIAIS ===\n\n");
    
    // Criando e mostrando padrões de habilidades
    int cone[HAB_TAM][HAB_TAM] = {0};
    int cruz[HAB_TAM][HAB_TAM] = {0};
    int octaedro[HAB_TAM][HAB_TAM] = {0};
    
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
    
    printf("Padrão Cone:\n");
    imprimirHabilidade(cone);
    
    printf("\nPadrão Cruz:\n");
    imprimirHabilidade(cruz);
    
    printf("\nPadrão Octaedro:\n");
    imprimirHabilidade(octaedro);
    
    // Aplicando habilidades ao tabuleiro
    printf("\n=== APLICANDO HABILIDADES AO TABULEIRO ===\n");
    
    // Aplicando cone na posição (1,1)
    printf("\nAplicando Cone em (1,1):\n");
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (cone[i][j] == 1 && (1+i) < TAMANHO && (1+j) < TAMANHO) {
                tabuleiro[1+i][1+j] = 1;
            }
        }
    }
    
    // Aplicando cruz na posição (5,5)
    printf("\nAplicando Cruz em (5,5):\n");
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (cruz[i][j] == 1 && (5+i-HAB_TAM/2) >= 0 && (5+j-HAB_TAM/2) >= 0 && 
                (5+i-HAB_TAM/2) < TAMANHO && (5+j-HAB_TAM/2) < TAMANHO) {
                tabuleiro[5+i-HAB_TAM/2][5+j-HAB_TAM/2] = 1;
            }
        }
    }
    
    printf("\nTabuleiro Final (0=Água, 1=Habilidade, 3=Navio):\n");
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}