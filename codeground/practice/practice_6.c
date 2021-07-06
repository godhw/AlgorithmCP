// first, we need to know if the room number is increasing or decreasing.
// location is used to find room number.
// we can't use nXn array, because it must overflow.
// if x+y >= N, we use different method with x+y<N.
// more information is in code.



#include <stdio.h>
#include <stdlib.h>

long long Answer;

int main(void) {
    int T, test_case;
    int N, K;
    int x, y;
    int sum, dec;

    freopen("practice_6_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++) {
        scanf("%d %d", &N, &K);
        char* str = (char*)malloc(sizeof(char)*(K+1)); //NULL pointer error 
        x = y = 0;
        Answer = 1;
        sum = 0;
        
       
        scanf("%s", str);
        

        for (int i = 0; i < K; i++) {
            switch (str[i])
            {
            case 'U':
                x--;
                dec = 1;
                break;
            case 'D':
                x++;
                dec = 0;
                break;
            case 'L':
                y--;
                dec = 1;
                break;
            case 'R':
                y++;
                dec = 0;
                break;
            }

            if (x + y < N) {
                if (dec) sum -= x + y + 1;
                else sum += x + y;
                if (((x + y)%2) == 0) Answer += sum + 1 + y;
                else Answer += sum + 1 + x;
            } else {
                if (dec) sum -= 2 * N - (x + y + 1);
                else sum += 2 * N - (x + y);
                if (((x + y)%2) == 0) Answer += sum + N - x;
                else Answer += sum + N - y;
            }
        }

        printf("Case #%d\n", test_case+1);
        printf("%lld\n", Answer);
        free(str);
    }
    return 0;
}