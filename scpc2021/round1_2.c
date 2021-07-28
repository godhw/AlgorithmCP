#include <stdio.h>
#include <string.h>

int A[50001];
int AA[50001];
int B[50001];
char BB[50001];

int main(void) {
    int T, test_case;
    int n, t;
    int x, y;

    freopen("round1_2_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        scanf("%d %d", &n, &t);
        memset(AA, 0, sizeof(int)*(n+1));
        scanf("%s", BB);
        for (int i = 1; i <= n; i++) {
            B[i] = BB[i-1] - '0';
        }

        int sol = t;
        int sol2 = n - 2*t;
        while (sol - t < t) {
            A[sol+1] = B[sol + 1 -t];
            A[n - sol] = B[n - sol + t];
            AA[sol+1] = AA[n - sol] = 1;
            if (B[sol + 1] == 0) {
                A[sol + 1 - t] = 0;
                A[sol + 1 + t] = 0;
                AA[sol + 1 - t] = 1;
                AA[sol + 1 + t] = 1;
            }
            if (B[n - sol] == 0) {
                A[n - sol - t] = 0;
                A[n - sol + t] = 0;
                AA[n - sol - t] = 1;
                AA[n - sol + t] = 1;
            }
            sol++;
        }
        sol = 1;
        while (sol <= t) {
            if (B[sol + t] == 1) {
                if(AA[sol + t - t] == 0 && AA[sol + t + t] == 0) {
                    A[sol + t - t] = 0;
                    A[sol + t + t] = 1;
                    AA[sol + t - t] = 1;
                    AA[sol + t + t] = 1;
                } else if (AA[sol + t + t] == 1 && A[sol + t + t] == 0) {
                    A[sol + t - t] = 1;
                    AA[sol + t - t] = 1;
                } else if (AA[sol + t + t] == 1 && A[sol + t + t] == 1) {
                    A[sol + t - t] = 0;
                    AA[sol + t - t] = 1;
                }
            }
            if (B[sol2 + sol] == 1) {
                x = AA[sol2 + sol - t];
                y = AA[sol2 + sol + t];
                if(x == 0 && y == 0) {
                    A[sol2 + sol - t] = 0;
                    A[sol2 + sol + t] = 1;
                    AA[sol2 + sol - t] = 1;
                    AA[sol2 + sol + t] = 1;
                } else if (x == 1 && A[sol2 + sol - t] == 1) {
                    A[sol2 + sol + t] = 0;
                    AA[sol2 + sol + t] = 1;
                } else if (x == 1 && A[sol2 + sol - t] == 0) {
                    A[sol2 + sol + t] = 1;
                    AA[sol2 + sol + t] = 1;
                }
            }
            sol++;
        }    

        printf("Case #%d\n", test_case + 1);
        for (int i = 1; i <= n; i++) {
            printf("%d",A[i]);
        }
        printf("\n");
    }
    return 0;
}