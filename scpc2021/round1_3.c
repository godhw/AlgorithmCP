#include <stdio.h>
#include <string.h>

int graph[501][501];
int vis[501];
int flag;
void dfs(int i, int n) {
    vis[i] = 1;
    for (int j = 1; j <= n; j++) {
        if (graph[i][j] != 0) {
            if(vis[j] == 1) {
                flag = 1;
                return;
            }
            dfs(j, n);
        }
    }
}

int main(void) {
    int T, test_case;
    int N, M, K;
    int x, y;
    int ans;
    int next;
    freopen("round1_3_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        scanf("%d %d %d", &N, &M, &K);
        memset(graph, 0, sizeof(graph));
        char sol[K];
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &x, &y);
            graph[x][y]++;
        }
        for (int i = 0; i < K; i++) {
            scanf("%d %d", &x, &y);
            graph[x][y]++;
            memset(vis, 0, sizeof(vis));
            flag = 0;
            dfs(x, N);

            if (flag) {
                graph[x][y]--;
                graph[y][x]++;
                sol[i] = '1';
            } else sol[i] = '0';
        }


        printf("Case #%d\n", test_case + 1);
        printf("%s\n", sol);
        
    }
    return 0;
}