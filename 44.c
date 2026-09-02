#include <stdlib.h>
#include <string.h>

int* prisonAfterNDays(int* cells, int cellsSize, int n, int* returnSize) {
    *returnSize = 8;
    int* result = (int*)malloc(8 * sizeof(int));
    int temp[8];

    // Simulation logic function block
    void simulate(int* src, int* dst) {
        dst[0] = 0; // First cell has no left neighbor
        dst[7] = 0; // Last cell has no right neighbor
        for (int i = 1; i < 7; i++) {
            dst[i] = (src[i - 1] == src[i + 1]) ? 1 : 0;
        }
    }

    // Step 1: Simulate Day 1
    simulate(cells, result);
    n--;

    // Step 2: Minimize tracking iterations with the 14-day cycle window
    n %= 14;

    // Step 3: Run the reduced simulation steps
    for (int day = 0; day < n; day++) {
        memcpy(temp, result, 8 * sizeof(int));
        simulate(temp, result);
    }

    return result;
}
