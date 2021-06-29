// This code is the answer of codeground/practice/number 3.
// You must know about qsort function.
// I use ascending sort.
// The result is sum of scores from the highest point to the Kth.
// Other solution is allocating array size of 101, and count the number of specific scores.
// Next, using nested for loop, count same machanism.
#include <stdio.h>
#include <stdlib.h>

// compare function is used in qsort function.
int compare(const void *a, const void *b){ 
    int aa = *(int *)a;
    int bb = *(int *)b;

    if (aa < bb) return -1; // aa before bb
    if (aa > bb) return 1; // aa after bb
    return 0; // same
}

int Answer;

int main(void) {
    // T : number of testcases
    // test_case : what number is this case
    // N : number of subjects
    // K : number of subjects that Jeong woo can study.
    int T, test_case;
    int N, K;

	// Next code uses to read testcase from text file.
    // This make the program will read from txt file instead of standard input.
    freopen("practice_3_input.txt", "r", stdin);

    //unbuffered stream
    setbuf(stdout, NULL);

    scanf("%d", &T);
    for (test_case = 0; test_case < T; test_case++) {
        scanf("%d %d", &N, &K);
        Answer = 0;
        // allocate Heap memory for array of size N
        int* array = (int*)malloc(sizeof(int)*N);

        // insert scores
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }

        // quick sort function
        qsort(array, N, sizeof(int), compare);

        // j : count K
        int j = 0;
        for (int i = N - 1; j < K; i--) {
            Answer += array[i];
            j++;
        }

        printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
    }
    return 0;
}