#include <stdio.h>

// Constantes para número de movimentos
#define MOV_BISPO 5
#define MOV_TORRE 5
#define MOV_RAINHA 8

// ---------------- NÍVEL NOVATO ----------------

void moverBispo() {
    printf("♗ Movimentação do Bispo (Diagonal Superior Direita):\n");
    for (int i = 0; i < MOV_BISPO; i++) {
        printf("Cima + Direita\n");
    }
    printf("\n");
}

void moverTorre() {
    printf("♖ Movimentação da Torre (Direita):\n");
    for (int i = 0; i < MOV_TORRE; i++) {
        printf("Direita\n");
    }
    printf("\n");
}

void moverRainha() {
    printf("♕ Movimentação da Rainha (Esquerda):\n");
    for (int i = 0; i < MOV_RAINHA; i++) {
        printf("Esquerda\n");
    }
    printf("\n");
}

// ---------------- NÍVEL AVENTUREIRO ----------------

void moverCavaloL() {
    printf("♘ Movimentação do Cavalo em L (Baixo + Esquerda):\n");

    for (int i = 0; i < 2; i++) { // Cavalo anda 2 para uma direção
        printf("Baixo\n");
        int j = 0;
        while (j < 1) {           // E depois 1 para a outra
            printf("Esquerda\n");
            j++;
        }
    }

    printf("\n");
}

// ---------------- NÍVEL MESTRE ----------------

// Funções recursivas para movimentação simples

void moverBispoRecursivo(int passos) {
    if (passos == 0) return;
    printf("Cima + Direita\n");
    moverBispoRecursivo(passos - 1);
}

void moverTorreRecursiva(int passos) {
    if (passos == 0) return;
    printf("Direita\n");
    moverTorreRecursiva(passos - 1);
}

void moverRainhaRecursiva(int passos) {
    if (passos == 0) return;
    printf("Esquerda\n");
    moverRainhaRecursiva(passos - 1);
}

void moverCavaloL_Mestre() {
    printf("♘ Movimentação Avançada do Cavalo (L para cima e direita):\n");

    for (int i = 2; i > 0; i--) {
        if (i == 1) continue; // pula o segundo passo na vertical
        printf("Cima\n");

        for (int j = 0; j < 2; j++) {
            if (j == 1) break; // só executa um passo na horizontal
            printf("Direita\n");
        }
    }

    printf("\n");
}

// ---------------- MAIN ----------------

int main() {
    printf("Desafio de Xadrez - MateCheck\n\n");

    // Nível Novato
    moverBispo();
    moverTorre();
    moverRainha();

    // Nível Aventureiro
    moverCavaloL();

    // Nível Mestre
    printf("♜ Versão Mestre com Recursividade:\n");
    printf("\n♗ Bispo:\n");
    moverBispoRecursivo(MOV_BISPO);

    printf("\n♖ Torre:\n");
    moverTorreRecursiva(MOV_TORRE);

    printf("\n♕ Rainha:\n");
    moverRainhaRecursiva(MOV_RAINHA);

    printf("\n♘ Cavalo com múltiplas condições:\n");
    moverCavaloL_Mestre();

    return 0;
}
