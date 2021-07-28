#include <stdio.h>
#include <string.h>

int Answer;
int group[100001];
int disjoint[100001];
int main(void) {
    int T, test_case;
    int N;

    freopen("round1_1_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;
        scanf("%d", &N);
        memset(group, 0, sizeof(group));
        disjoint[0] = 0;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &group[i]);
            disjoint[i] = -1;
        }
        for (int i = 1; i <= N; i++) {
            if (group[i] + i <= N) {
                if (disjoint[group[i] + i] == -1) disjoint[group[i] + i] = i;
                else {
                    int x = i;
                    while (disjoint[x] > 0) x = disjoint[x];
                    disjoint[x] = disjoint[group[i] + i];
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            if (disjoint[i] == -1) Answer++;
        }

        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);
    }
    return 0;
}