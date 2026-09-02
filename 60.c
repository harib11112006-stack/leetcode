#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAL 20001
#define ITERATIONS 25 

typedef struct {
    int* arr;
    int arrSize;
    int* posList[MAX_VAL];
    int posSize[MAX_VAL];
} MajorityChecker;

int lower_bound(int* arr, int size, int target) {
    int low = 0, high = size;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) high = mid;
        else low = mid + 1;
    }
    return low;
}

int upper_bound(int* arr, int size, int target) {
    int low = 0, high = size;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target) high = mid;
        else low = mid + 1;
    }
    return low;
}

MajorityChecker* majorityCheckerCreate(int* arr, int arrSize) {
    MajorityChecker* obj = (MajorityChecker*)malloc(sizeof(MajorityChecker));
    obj->arr = arr;
    obj->arrSize = arrSize;
    
    memset(obj->posSize, 0, sizeof(obj->posSize));
    
    for (int i = 0; i < arrSize; i++) {
        obj->posSize[arr[i]]++;
    }
    
    for (int i = 0; i < MAX_VAL; i++) {
        if (obj->posSize[i] > 0) {
            obj->posList[i] = (int*)malloc(obj->posSize[i] * sizeof(int));
        } else {
            obj->posList[i] = NULL;
        }
    }
    
    int tempIdx[MAX_VAL] = {0};
    for (int i = 0; i < arrSize; i++) {
        int val = arr[i];
        obj->posList[val][tempIdx[val]++] = i;
    }
    
    return obj;
}

int majorityCheckerQuery(MajorityChecker* obj, int left, int right, int threshold) {
    int len = right - left + 1;
    
    for (int i = 0; i < ITERATIONS; i++) {
        int randIdx = left + rand() % len;
        int candidate = obj->arr[randIdx];
        
        int totalOccurrences = upper_bound(obj->posList[candidate], obj->posSize[candidate], right) - 
                               lower_bound(obj->posList[candidate], obj->posSize[candidate], left);
        
        if (totalOccurrences >= threshold) {
            return candidate;
        }
    }
    
    return -1;
}

void majorityCheckerFree(MajorityChecker* obj) {
    if (obj) {
        for (int i = 0; i < MAX_VAL; i++) {
            if (obj->posList[i]) {
                free(obj->posList[i]);
            }
        }
        free(obj);
    }
}
