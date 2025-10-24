#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int linha1 = 1, coluna1 = 4, linha2 = 5, coluna2 = 6, erroInput = 0;

    int tabuleiro[10][10] = {0};

    // Verifica se é possível posicionar o navio da base para cima
    int paraCima = (linha1 - 2) < 0 ? 0 : 1;

    // Posiciona o navio para cima ou para baixo dependendo da variavel paraCima
    for (int i = 0; i < 3; i++) {
        if (paraCima) {
            tabuleiro[linha1 - i][coluna1] = 3;

        } else {
            tabuleiro[linha1 + i][coluna1] = 3;

        } 
    }

    // Verifica se é possível posicionar o navio da base para a esquerda
    int paraEsquerda = (coluna2 - 2) < 0 ? 0 : 1;

    // Posiciona o navio para esquerda ou para a dineita dependendo da variavel paraEsquerda
    for (int i = 0; i < 3; i++) {
        if (paraEsquerda) {
            if (tabuleiro[linha2][coluna2 - i] == 3) {
                erroInput = 1;
                printf("Coordenada do navio 2 sobreescreveu o navio 1, mude o tente novamente\n");
                break;

            } else {
                tabuleiro[linha2][coluna2 - i] = 3;
            }

        } else {
            if (tabuleiro[linha2][coluna2 + i] == 3) {
                erroInput = 1;
                printf("Coordenada do navio 2 sobreescreveu o navio 1, mude o tente novamente\n");
                break;

            } else {
                tabuleiro[linha2][coluna2 + i] = 3;

            }

        } 
    }

    if (!erroInput) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }
    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
