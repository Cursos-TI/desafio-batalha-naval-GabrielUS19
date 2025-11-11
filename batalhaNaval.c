#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LADO 10

int insertShip(int tabuleiro[LADO][LADO], int ship[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (ship[0][i] >= LADO || ship[1][i] >= LADO) {
            printf("Coordenada ultrapassou os limites do tabuleiro, tente novamente\n");
            return 0;

        }

        if (tabuleiro[ship[0][i]][ship[1][i]] == 3) {
            printf("Coordenada já cadastrada, tente novamente!\n");
            return 0;

        } 
        
        tabuleiro[ship[0][i]][ship[1][i]] = 3;
    }

    return 1;
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    

    int linha1 = 1, coluna1 = 4, linha2 = 5, coluna2 = 6, erroInput = 0;

    int tabuleiro[LADO][LADO] = {0};

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
        for (int i = 0; i < LADO; i++) {
            for (int j = 0; j < LADO; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    printf("\n");

    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    int matrizAventureiro[LADO][LADO] = {0};
    int coordenadaCone[2] = {2, 6};
    int coordenadaCruz[2] = {5, 3};
    int coordenadaOcta[2] = {7, 6};

    int navios[4][2][3] = {
        // Navio 1
        {
            {2, 3, 4},
            {4, 4, 4}
        },
        // Navio 2
        {
            {9, 9, 9},
            {1, 2, 3}
        },
        // Navio 3
        {
            {5, 6, 7},
            {5, 6, 7}
        },
        // Navio 4
        {
            {6, 5, 4},
            {3, 4, 5}
        }
    };

    for (int i = 0; i < 4; i++) {
        if (insertShip(matrizAventureiro, navios[i])) {
            printf("Navio %d inserido com sucesso!\n", i + 1);

        } else {
            return 0;

        }
    }

    // Habilidade do Cone
    for (int i = coordenadaCone[0]; i < coordenadaCone[0] + 3; i++) {
        for (int j = coordenadaCone[1]; j < coordenadaCone[1] + 5; j++) {
            int column = i - coordenadaCone[0];
            int line = j - coordenadaCone[1];

            switch (column)
            {
            case 0:
                if (line == 2 && i < 10 && j < 10) matrizAventureiro[i][j] = 1;

                break;
            case 1:
                if (line == 1 || line == 2 || line == 3 && i < 10 && j < 10) matrizAventureiro[i][j] = 1;

                break;
            case 2:
                if (i < 10 && j < 10) matrizAventureiro[i][j] = 1;

                break;
            default:
                break;
            }
        }
    }

    // Habilidade da Cruz
    for (int i = coordenadaCruz[0]; i < coordenadaCruz[0] + 3; i++) {
        for (int j = coordenadaCruz[1]; j < coordenadaCruz[1] + 5; j++) {
            int column = i - coordenadaCruz[0];
            int line = j - coordenadaCruz[1];

            switch (column)
            {
            case 0:
                if (line == 2 && j < 10 && i < 10) matrizAventureiro[i][j] = 1;
                
                break;
            case 1:
                if (j < 10 && i < 10) matrizAventureiro[i][j] = 1;

                break;

            case 2:
                if (line == 2 && j < 10 && i < 10) matrizAventureiro[i][j] = 1;

                break;
            default:
                break;
            }
        }
    }

    // Habilidade do Octaedro
    for (int i = coordenadaOcta[0]; i < coordenadaOcta[0] + 3; i++) {
        for (int j = coordenadaOcta[1]; j < coordenadaOcta[1] + 5; j++) {
            int column = i - coordenadaOcta[0];
            int line = j - coordenadaOcta[1];

            switch (column)
            {
            case 0:
                if (line == 2 && j < 10 && i < 10) matrizAventureiro[i][j] = 1;
                
                break;
            case 1:
                if (line == 1 || line == 2 || line == 3 && i < 10 && j < 10) matrizAventureiro[i][j] = 1;

                break;

            case 2:
                if (line == 2 && j < 10 && i < 10) matrizAventureiro[i][j] = 1;

                break;
            default:
                break;
            }
        }
    }

    // Mostra o tabuleiro no terminal
    printf("TABULEIRO AVENTUREIRO\n");
    for (int i = 0; i < LADO; i++) {
        for (int j = 0; j < LADO; j++) {
            printf("%d ", matrizAventureiro[i][j]);
        }
        printf("\n");
    }

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
