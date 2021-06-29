// This code is the answer of codeground/practice/number 4.
// You must know about math header file.
// I use sqrt function and atan2 function in this code.
// sqrt function is used to find square root.
// atan2 function is arctangent, and it's return value is radian.
// Degree is radian*180/PI.
// In this, degree could be negative. If it is so, add 360.
// positive range of x-axis will degree 0; so score array must start 6, 13, ...
// each score's range is 18 degree.

#include <stdio.h>
#include <math.h>

// PI is constant.
const double PI = 3.1415926;

int Answer;
// score array
int score[20] = {6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10};

int main(void) {
    // variables are same with problem. 
    int T, test_case;
    int A, B, C, D, E;
    int N;
    int x, y;

    // sum : used for square y plus square x.
    // mid : score that is not multiple 3 or 2.
    int sum, mid;

    // Next code uses to read testcase from text file.
    // This make the program will read from txt file instead of standard input.
    freopen("practice_4_input.txt", "r", stdin);

    //unbuffered stream
    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;
        scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%d %d", &x, &y);
            sum = y*y + x*x;

            // it is used for range of triple or double etc.
            double length = (double)sqrt((double)sum);

            // it is used for what score it is in this time.
            // Because the range of array's first is from -9 to +9 degree, add 9 makes from 0 to 18.
            double degree = atan2(y, x)*180/PI + 9;
            //correct negative degree.
            if (degree < 0) degree += 360;

            mid = score[(int)degree/18];

            // same condition with problem.
            if (length <= A) Answer += 50;
            else if (B <= length && length <= C) Answer += mid * 3;
            else if (D <= length && length <= E) Answer += mid * 2;
            else if (length > E) continue;
            else Answer += mid;
        }
        printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
    }
    return 0;
}