#include <stdio.h>
#include <string.h>

int A[50001];
int B[50001];
char BB[50001];

int main(void) {
    int T, test_case;
    int n, t;

    freopen("round1_2_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        scanf("%d %d", &n, &t);
        scanf("%s", BB);
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        for (int i = 1; i <= n; i++) {
            B[i] = BB[i-1] - '0';
        }
        if (n > t*2) {
            int x = t + 1;
            while (x <= n-t) {
                A[x] = B[x-t] & B[x+t];
                x++;
            }
            x = 1;
           int y = 2*t;
            for (x = 1; x <= t; x++) {
                if (x + y >= n) A[x] = B[x+t];
                A[x] = B[x+t] ^ A[x+y];
            }
            for (x = n; x > n - t; x--) {
                if (x - y <= 0) A[x] = B[x-t];
                A[x] = B[x-t] ^ A[x-y];
            }
        } else {
            for (int i = 1; i <= n - t; i++) {
                A[t+i] = B[i];
                A[i] = B[t+i];
            }
            for (int i = n - t + 1; i <= t; i++) {
                A[i] = 0;
            }
        }
        printf("Case #%d\n", test_case + 1);
        for (int i = 1; i <= n; i++) {
            printf("%d",A[i]);
        }
        printf("\n");
    }
    return 0;
}