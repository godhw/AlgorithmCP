//what;
#include <stdio.h>
#include <stdlib.h>

int sol[3001][3001];
int cnti[3001];
int cntj[3001];

void clear() {
    sol[0][0] = 1;
    sol[1][0] = 0;
    sol[0][1] = 0;
    sol[1][1] = 1;
}

typedef struct solsol {
    int cnti;
    int cntj;
} solsol;

int main(void) {
    int T, test_case;
    int n, k, i, j, sumj, sumi, indexj, indexi;
    int tmpi, tmpj;
    int* X = (int*)malloc(sizeof(int)*3001);
    int* Y = (int*)malloc(sizeof(int)*3001);

    clear();

    freopen("scpc6_tryout2_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        int fir = 2;
        int sec = 2;

        scanf("%d %d", &n, &k);
        for (i = 1; i <= n; i++) {
            scanf("%d", &X[i]);
            sumi = 0;
            cnti[i] = 0;
            indexi = i;
            while (indexi > 0 && sumi + X[indexi] <= k) {
                sumi += X[indexi--];
                cnti[i]++;
            }
        }
        for (j = 1; j <= n; j++) {
            scanf("%d", &Y[j]);
            sumj = 0;
            cntj[j] = 0;
            indexj = j;
            while (indexj > 0 && (sumj + Y[indexj] <= k)) {
                sumj += Y[indexj--];
                cntj[j]++;
            }
        }

        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n; j++) {
                if (i <= 1 && j <= 1) continue;
                sol[i][j] = 0;
                tmpi = cnti[i];
                tmpj = cntj[j];
                
                while (tmpj > 0) {
                    if (sol[i][j - tmpj] == 0) {
                        sol[i][j] = 1;
                        break;
                    }
                    tmpj--;
                }
                while (tmpi > 0) {
                    if (sol[i - tmpi][j] == 0) {
                        sol[i][j] = 1;
                        break;
                    }
                    tmpi--;
                }
                if (sol[i][j] == 1) fir++;
                else sec++;
            }
        }
        
        printf("Case #%d\n", test_case + 1);
        printf("%d %d\n", fir, sec);
    }

    free(X);
    free(Y);

    return 0;
}