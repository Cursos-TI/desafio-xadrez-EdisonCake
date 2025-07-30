#include <stdio.h>

// Constantes
#define MOV_BISPO 5
#define MOV_TORRE 5
#define MOV_RAINHA 8

// ----------- NÍVEL NOVATO (cada loop diferente) -----------

void moverTorre() {
    printf("Torre (Direita - com FOR):\n");
    for (int i = 0; i < MOV_TORRE; i++) {
        printf("Direita\n");
    }
    printf("\n");
}

void moverBispo() {
    printf("Bispo (Diagonal Cima + Direita - com WHILE):\n");
    int i = 0;
    while (i < MOV_BISPO) {
        printf("Cima + Direita\n");
        i++;
    }
    printf("\n");
}

void moverRainha() {
    printf("Rainha (Esquerda - com DO-WHILE):\n");
    int i = 0;
    do {
        printf("Esquerda\n");
        i++;
    } while (i < MOV_RAINHA);
    printf("\n");
}

// ----------- NÍVEL AVENTUREIRO (Cavalo com loops aninhados) -----------

void moverCavaloL() {
    printf("Cavalo (Baixo + Esquerda - com FOR + WHILE):\n");

    for (int i = 0; i < 2; i++) { // 2 movimentos para Baixo
        printf("Baixo\n");
        int j = 0;
        while (j < 1) {           // 1 movimento para Esquerda por iteração
            printf("Esquerda\n");
            j++;
        }
    }
    printf("\n");
}

// ----------- NÍVEL MESTRE (Recursividade + Cavalo com lógica complexa) -----------

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
    printf("Cavalo Mestre (2 Cima, 1 Direita - com FOR + condições múltiplas):\n");

    // Movimento vertical: 2 passos para cima
    for (int i = 0; i < 3; i++) {
        if (i == 2) break; // só queremos 2 "Cima"
        printf("Cima\n");
    }

    // Movimento horizontal: 1 para direita com continue e break
    for (int j = 0; j < 2; j++) {
        if (j == 1) continue; // ignora se for o segundo
        printf("Direita\n");
        break; // garante apenas UM "Direita"
    }

    printf("\n");
}

// ----------- MAIN -----------

int main() {
    printf("Desafio de Xadrez - Nível Mestre Completo\n\n");

    // Nível Novato
    moverTorre();
    moverBispo();
    moverRainha();

    // Nível Aventureiro
    moverCavaloL();

    // Nível Mestre
    printf("Recursividade - Torre:\n");
    moverTorreRecursiva(MOV_TORRE);

    printf("\nRecursividade - Bispo:\n");
    moverBispoRecursivo(MOV_BISPO);

    printf("\nRecursividade - Rainha:\n");
    moverRainhaRecursiva(MOV_RAINHA);

    printf("\nCavalo Mestre com condições especiais:\n");
    moverCavaloL_Mestre();

    return 0;
}
