#include <stdio.h>

int Answer;

int main(void) {
    int T, test_case;

    freopen("practice_7_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);
    }
    return 0;
}