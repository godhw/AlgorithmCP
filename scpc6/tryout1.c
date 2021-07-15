#include <stdio.h>
#include <stdlib.h>
int Answer;

int compare(const void *a, const void *b){ 
    int aa = *(int *)a;
    int bb = *(int *)b;

    if (aa < bb) return -1; // aa before bb
    if (aa > bb) return 1; // aa after bb
    return 0; // same
}

int main(void) {
    int T, test_case;
    int N, K;
    int* A = (int*)malloc(sizeof(int)*200000);
    int* B = (int*)malloc(sizeof(int)*200000);
    int* S = (int*)malloc(sizeof(int)*200000);
    
    freopen("scpc6_tryout1_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        scanf("%d %d", &N, &K);
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);     
        for (int i = 0; i < N; i++) scanf("%d", &B[i]);
        qsort(A, N, sizeof(int), compare);
        qsort(B, N, sizeof(int), compare);
        for (int i = 0; i < K; i++) S[i] = A[i] + B[K-1-i];

        Answer = S[0];
        for (int i = 1; i < K; i++) {
            if (S[i] > Answer) Answer = S[i];
        }

        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);
    }
    free(A);
    free(B);
    free(S);
    return 0;
}