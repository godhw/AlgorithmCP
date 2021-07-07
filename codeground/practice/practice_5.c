// I cant solve at first.
//${{N+M+2}\choose{N+1}}-1$
//this is what we find.
//we must calculate factorial, but it must bring about time over.
//MOD = 1000000007, we use distributive law of the modulo.
//$\left( \left( (N+M+2)! \right) \%P \times \left( ((N+1)!(M+1)!)^{-1} \right) \% P -1 \right) \%P$
//(((N+M+2)!)%MOD * (((N+1)!(M+1)!)^-1)%MOD -1)%MOD
//MOD is prime number, so we use fermat's little theorem.
// By fermat's little theorem, (a*a^(m-2))%m = 1.
//so, a^(-1)%m = a^(m-2)%m
#include <stdio.h>
#include <stdlib.h>
// MAX : maximum of N+M+2
const long long MOD = 1000000007;
const int MAX = 2000002;
int Answer;

//find ((N+1)!(M+1)!)^(MOD-2)%MOD
//use distributive law and fermat's little theorem.
//x^p %m => if(p%2), ((x%m)*(x^2%m)^(p/2))%m
//result = (result*x)%m == solution
long long Exp_mod_via_repeated_squaring(long long x) {
    long long result = 1;
    long long pow = MOD - 2;

    while (pow > 0) {
        if (pow % 2) result = ((result * x) % MOD);
        x = ((x * x) % MOD);
        pow = pow / 2;
    }
    return result;
}

int main(void) {
    int T, test_case;
    int N, M, f;
    long long* fac = (long long*)malloc(sizeof(long long)*(MAX+1));
    fac[0] = 1;
    
    //find factorial mod MOD 0 to MAX
    for (int i = 1; i <= MAX; i++) {
        fac[i] = (i * fac[i-1]) % MOD;
    }

    freopen("practice_5_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        scanf("%d %d", &N, &M);

        Answer = Exp_mod_via_repeated_squaring((fac[N+1] * fac[M+1])%MOD);
        Answer = (Answer*fac[N+M+2])%MOD;
        //this is just -1, so we have not did %MOD.
        Answer = Answer-1;
        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);
    }
    free(fac);
    //free(invfac);
    return 0;
}