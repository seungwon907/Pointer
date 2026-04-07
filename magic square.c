#pragma warning(disable:4996)                                                                                                                                                                                                                                                                                                pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void fillMagicSquare(int N) {
    int** magicSquare = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        magicSquare[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            magicSquare[i][j] = 0; 
        }
    }

    int row = 0, col = N / 2;
    for (int num = 1; num <= N * N; num++) {
        magicSquare[row][col] = num;
        row--;
        col++;

        if (num % N == 0) {
            row += 2; 
            col--; 
        }
        else {
            if (col == N) col -= N; 
            if (row < 0) row += N; 
        }
    }

    printf("홀수 마방진 출력:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", magicSquare[i][j]);
        }
        printf("\n");
    }

    int magicSum = N * (N * N + 1) / 2; 
    printf("모든 가로/세로/대각선의 합은: %d\n", magicSum);

    for (int i = 0; i < N; i++) {
        free(magicSquare[i]);
    }
    free(magicSquare);
}

int main() {
    int N;
    printf("홀수 정수 N을 입력하세요: ");
    scanf("%d", &N);

    if (N % 2 == 0) {
        printf("N은 홀수여야 합니다.\n");
        return 1;
    }

    fillMagicSquare(N);
    return 0;
}
