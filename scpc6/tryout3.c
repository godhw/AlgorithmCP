#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b));
const int INF = 1e9;
int Answer;
int sol[1511][1511];
typedef struct line {
    int start_point;
    int end_point;
} line;
line link[2001];
line pair[100001];

int main(void) {
    int T, test_case;
    int N, k, m;
    freopen("scpc6_tryout3_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;
        scanf("%d %d %d", &N, &k, &m);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) sol[i][j] = INF;
        }
        for (int i = 1; i <= N; i++) sol[i][i] = 0;

        int x, y;
        int a, b;
        for (int i = 1; i <= k; i++) {
            scanf("%d %d", &x, &y);
            for (int j = 1; j <= N; j++) {
                a = sol[j][x]; b = sol[j][y];
                sol[j][x] = MIN(a + 1, b);
                sol[j][y] = MIN(b + 1, a);
            }
        }
        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            if(sol[u][v] == INF) Answer -= 1;
            else Answer += sol[u][v];
        }

        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);
    }
    return 0;
}