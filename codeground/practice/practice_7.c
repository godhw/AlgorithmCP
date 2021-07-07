
#include <stdio.h>
#include <stdlib.h>

int Answer;

int main(void) {
    int T, test_case;
    int N;
    int* Arr;
    int* Sum = (int*)malloc(sizeof(int)*400001);

    //freopen("practice_7_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;
        scanf("%d", &N);

        for (int i = 0; i < 400001; i++) Sum[i] = 0;

        Arr = (int*)malloc(sizeof(int)*N);

        for (int i = 0; i < N; i++) {
            scanf("%d", &Arr[i]);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if(!Sum[Arr[i-1] + Arr[j] + 200000]) Sum[Arr[i-1] + Arr[j] + 200000] = 1;
            }

            for(int j = 0; j < i; j++) {
                if(Sum[Arr[i] - Arr[j] + 200000]) {
                    Answer++;
                    break;
                }
            }

        }
        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);
        free(Arr);
    }
    free(Sum);

    return 0;
}