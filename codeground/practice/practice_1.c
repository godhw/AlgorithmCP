// This code is the answer of codeground/practice/number 1.
// Other codes make time limit exceed.
// You must know bit operator ^.
// Doing XOR operation by even times makes same result at first times.
// So, you should not consider how many times number are repeated.
#include <stdio.h>

int Answer;

int main() {
    // T : number of test cases
    // test_case : what number is this testcase
    // N : number of numbers
    // num : tmp variable
    // flag : if it is not first value
    // i : for loop variable
    int T, test_case;
    int N;
    int num, flag, i;
    // Next comment uses to read testcase from text file.
    // This make the program will read from txt file instead of standard input.
    freopen("practice_1_Input.txt", "r", stdin);

    //unbuffered stream
    setbuf(stdout, NULL);
    scanf("%d", &T);
    
    for (test_case = 0; test_case < T; test_case++) {
        scanf("%d", &N);
        flag = 0;
        for (i = 0; i < N; i++) {
            scanf("%d", &num);
            if (flag == 0) {
                Answer = num;
                flag = 1;
            } else {
                Answer ^= num;
            } 
        }
        printf("Case#%d\n", test_case+1);
        printf("%d\n", Answer);
    }
    return 0;
}
