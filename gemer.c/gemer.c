#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRID_SIZE 5

// Função para limpar a tela (compatível com Windows e Unix-like)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Função para exibir o grid
void displayGrid(char grid[GRID_SIZE][GRID_SIZE], int playerX, int playerY) {
    clearScreen();
    printf("+");
    for (int i = 0; i < GRID_SIZE; i++) printf("--");
    printf("+\n");

    for (int i = 0; i < GRID_SIZE; i++) {
        printf("|");
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("P "); // Representa o jogador
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("|\n");
    }

    printf("+");
    for (int i = 0; i < GRID_SIZE; i++) printf("--");
    printf("+\n");
}

int main() {
    // Inicialização do grid
    char grid[GRID_SIZE][GRID_SIZE] = {
        {' ', ' ', ' ', ' ', ' '},
        {' ', 'C', ' ', ' ', ' '},
        {' ', ' ', 'C', ' ', ' '},
        {' ', ' ', ' ', 'C', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };

    int playerX = 0, playerY = 0; // Posição inicial do jogador
    int score = 0;                // Pontuação inicial
    char input;                   // Entrada do jogador

    while (true) {
        // Exibe o grid e informações do jogo
        displayGrid(grid, playerX, playerY);
        printf("Score: %d\n", score);
        printf("Use W (cima), A (esquerda), S (baixo), D (direita) para mover. Pressione Q para sair.\n");

        // Lê entrada do jogador (com validação para sistemas multiplataforma)
        input = getchar();
        while (getchar() != '\n'); // Limpa o buffer de entrada

        // Movimentação do jogador
        if (input == 'w' || input == 'W') {
            if (playerX > 0) playerX--;
        } else if (input == 's' || input == 'S') {
            if (playerX < GRID_SIZE - 1) playerX++;
        } else if (input == 'a' || input == 'A') {
            if (playerY > 0) playerY--;
        } else if (input == 'd' || input == 'D') {
            if (playerY < GRID_SIZE - 1) playerY++;
        } else if (input == 'q' || input == 'Q') {
            break; // Sai do jogo
        } else {
            printf("Entrada inválida! Use apenas W, A, S, D ou Q.\n");
            continue; // Recomeça o loop sem atualizar o grid
        }

        // Verifica se o jogador coletou uma moeda
        if (grid[playerX][playerY] == 'C') {
            score++;
            grid[playerX][playerY] = ' '; // Remove a moeda coletada
        }
    }

    // Finaliza o jogo
    printf("Jogo encerrado! Sua pontuação final: %d\n", score);
    return 0;
}

