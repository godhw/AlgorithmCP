// This code is the answer of codeground/practice/number 2.
// You must know about qsort function.
// I use ascending sort.
// Because smallest number must get N points and largest one must get 1.
// Add points in this order to find the maximum value.

#include <stdio.h>
#include <stdlib.h> //for quick sort and malloc and free function

int Answer;

// compare function is used in qsort function.
int compare(const void *a, const void *b){ 
    int aa = *(int *)a;
    int bb = *(int *)b;

    if (aa < bb) return -1; // aa before bb
    if (aa > bb) return 1; // aa after bb
    return 0; // same
}

int main(void)
{
    // T : number of testcases
    // test_case : what number is this case
    // N : number of people
	int T, test_case;
    int N; 
    
	// Next code uses to read testcase from text file.
    // This make the program will read from txt file instead of standard input.
	freopen("practice_2_input.txt", "r", stdin);

    //unbuffered stream
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
        // max : max number
        int max = 0;
        Answer = 0;
        
        scanf("%d", &N);
        // allocate Heap memory for array
        int* array = (int*)malloc(sizeof(int)*N);
        // insert number
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }
        //quick sort
        qsort(array, N, sizeof(int), compare);
        // explain in line 4-5
        for (int i = 0; i < N; i++) {
            if (max < array[i] + N - i) max = array[i] + N - i;
        }
        // if array[i] has maximum points and it is at least max, Answer++;
        for (int i = 0; i < N; i++) {
            if (max <= array[i] + N) Answer++;
        }

		printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        free(array);
	}

	return 0;
}