#include <stdio.h>
#include <stdlib.h>

int Answer;

int main(void) {
    int T, test_case;
    int N;

    freopen("practice_8_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        scanf("%d", &N);
        int* arr = (int*)malloc(sizeof(int)*(N+2));
        arr[0] = arr[N+1] = 0;
        for(int i = 1; i <= N; i++) scanf("%d", &arr[i]);

        for (int i = 1; i <= N; i++) {
            if (arr[i-1] + 1 < arr[i]) arr[i] = arr[i-1] + 1;
        }
        for (int i = N; i >= 1; i--) {
            if (arr[i + 1] + 1 < arr[i]) arr[i] = arr[i + 1] + 1;
        }
        Answer = arr[1];

        for (int i = 2; i <= N; i++) {
            if (Answer < arr[i]) Answer = arr[i]; 
        }
        
        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);
        free(arr);
    }
    return 0;
}