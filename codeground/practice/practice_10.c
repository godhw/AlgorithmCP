//tq
#include <stdio.h>
#include <stdlib.h>


typedef unsigned long long ull;
struct kk {
    int x;
    int y;
}kk;
typedef struct kk node;

const ull MOD = 1000000007;

ull fac[200005];

int compare (const void *a, const void *b) { 
	node* ptra = (node*)a;
	node* ptrb = (node*)b;

	return (ptra->x > ptrb->x || ( ptra->x == ptrb->x && ptra->y > ptrb->y));
}

void init_fac() {
	int i;
	fac[0] = 1;
	for (i = 1; i < 200005; i++)
	{
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	return;
}

ull Exp_mod_via_repeated_squaring(ull x) {
    ull result = 1;
    ull pow = MOD - 2;

    while (pow > 0) {
        if (pow % 2) result = ((result * x) % MOD);
        x = ((x * x) % MOD);
        pow = pow / 2;
    }
    return result;
}

ull combi(int x, int y) {
    if (y <= 0 && x <= 0) return 0;
    
    ull result = Exp_mod_via_repeated_squaring((fac[x] * fac[y])%MOD);
    result = (result * fac[x + y]) % MOD;
    return result;
}

int main(void) {
    int T, test_case;
    
    

    init_fac();

    freopen("practice_10_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        int N, M, K;
        int x, y, i, j;
        scanf ("%d %d %d", &N, &M, &K);
        node* arr = (node*)malloc(sizeof(node)*(K + 2));
        ull* sol = (ull*)malloc(sizeof(ull)*(K + 2));
        arr[0].x = 1;
        arr[0].y = 1;
        arr[K + 1].x = N;
        arr[K + 1].y = M;
        for (i = 1; i <= K; i++) {
            scanf("%d %d", &x, &y);
            if (x <= N && y <= M) {
                arr[i].x = x;
                arr[i].y = y;
            }
        } 
        qsort(arr, K + 1, sizeof(node), compare);

        
        sol[K+1] = 0;
        for (i = K; i >= 0; i--) {
            sol[i] = combi(arr[K + 1].x - arr[i].x, arr[K + 1].y - arr[i].y);
    
            for (j = i + 1; j <= K; j++) {
                if (arr[j].y >= arr[i].y && arr[j].x >= arr[i].x) {
                    ull tmp = combi(arr[j].x - arr[i].x, arr[j].y - arr[i].y);
                    if (sol[i] >= (tmp * sol[j]) % MOD)
                        sol[i] -= (tmp * sol[j]) % MOD;
                    else sol[i] -= (tmp * sol[j]) % MOD - MOD;
                }
            }
        }
        printf("Case #%d\n", test_case + 1);
        printf("%lld\n", sol[0]);
        free(arr);
        free(sol);

    }
    return 0;
}