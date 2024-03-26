// Copyright 2021 NNTU-CS
#include <iostream>
#include <cstdint>
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (*(arr + j) + *(arr + i) == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value)  {
    int count = 0;
    int high = len - 1;
    while (*(arr + high) > value) {
        high -= 1;
    }
    for (int i = 0; i < high; i++) {
        for (int j = high; j > i; j--) {
            if (*(arr + i) + *(arr + j) == value) {
                count++;
            }
        }
    }
    return count;
}
int cbinsearch(int *arr, int size, int value) {
    int count = 0, low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < value) {
            low = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            count++;
            int left = mid - 1;
            int right = mid + 1;
            while (left >= 0 && arr[left] == value) {
                count++;
                left--;
            }
            while (right < size && arr[right] == value) {
                count++;
                right++;
            }
            break;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value)  {
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += cbinsearch(arr + i + 1, len - i - 1, value - *(arr + i));
    }
    return count;
}

