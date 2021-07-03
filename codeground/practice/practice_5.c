// I cant solve at first.
#include <stdio.h>
#include <stdlib.h>
const long long MOD = 1000000007;
const int MAX = 2000002;
int Answer;

long long what(long long x) {
    long long rem = 1;
    long long pow = MOD - 2;

    while (pow > 0) {
        if (pow % 2) rem = ((rem * x) % MOD);
        x = ((x * x) % MOD);
        pow = pow / 2;
    }
    return rem;
}

int main(void) {
    int T, test_case;
    int N, M, f;
    long long* fac = (long long*)malloc(sizeof(long long)*(MAX+1));
    //long long* invfac = (long long*)malloc(sizeof(long long)*(MAX+1));
    fac[0] = 1;
    //invfac[0] = 1;

    for (int i = 1; i <= MAX; i++) {
        fac[i] = (i * fac[i-1]) % MOD;
    }


    freopen("practice_5_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        scanf("%d %d", &N, &M);

        Answer = what((fac[N+1] * fac[M+1])%MOD);
        Answer = (Answer*fac[N+M+2])%MOD;
        Answer = Answer-1;
        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);
    }
    free(fac);
    //free(invfac);
    return 0;
}