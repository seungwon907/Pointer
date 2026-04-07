#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;
    printf("정수 N을 입력하세요: ");
    scanf("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        *(arr + i) = rand() % (N + 1);
    }

    printf("처음부터 끝까지 출력:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    printf("뒤에서부터 처음까지 출력:\n");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    int sum = 0;
    int max = *(arr);
    int min = *(arr);

    for (int i = 0; i < N; i++) {
        sum += *(arr + i);
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
    }

    printf("총합: %d\n", sum);
    printf("최대값: %d\n", max);
    printf("최소값: %d\n", min);

    free(arr);
    return 0;
}
