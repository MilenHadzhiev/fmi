#ifndef SORT_H
#define SORT_H

#include <iostream>

// On the first row you will get an integer N, N < 100. On the second line you will get N integers.
// Write a program that will output them in ascending order with spaces in between
// Input:
// 5
// 6 3 2 9 4
// Output
// 2 3 4 6 9

void sort(int* numbers, size_t numbers_count) {
    for(size_t i = 0; i < numbers_count; i++) {
        for(size_t j = i; j < numbers_count; j++) {
            if (numbers[i] > numbers[j]) {
                numbers[i] += numbers[j];
                numbers[j] = numbers[i] - numbers[j];
                numbers[i] -= numbers[j];
            }
        }
    }
}


void insertion_sort(int* arr, size_t size)
{
    if (size <= 1) return;
    for (size_t i = 1; i < size; ++i)
    {
        size_t j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j--] = temp;
        }
    }
}
// On the first row you will get an integer N, N < 100. On the second line you will get N integers.
// Sort the numbers with the selection method - On each of N - 1 steps we find the i-th smallest element
// and put it in its place. On separate rows print the result of each step

void selection_sort(int* numbers, size_t numbers_count)
{
    for(size_t i = 0; i < numbers_count - 1; i++) {
        int min = numbers[i];
        size_t min_idx = i;
        for(unsigned short j = i; j < numbers_count; j++) {
            if(numbers[j] < min) {
                min = numbers[j];
                min_idx = j;
            }
        }
        if (i != min_idx) {
            numbers[i] += min;
            numbers[min_idx] = numbers[i] - min;
            numbers[i] -= numbers[min_idx];
        }
    }
}

void bubble_sort(int* nums, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

// merge and mergesort
void merge(int* arr, size_t l, size_t mid, size_t h)
{
    size_t n1 = mid - l;
    size_t n2 = h - mid;
    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];
    for (size_t i = 0; i < n1; ++i)
    {
        L[i] = arr[i + l];
    }
    for (size_t i = 0; i < n2; ++i)
    {
        R[i] = arr[i + mid];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    size_t i = 0, j = 0;
    for (size_t k = l; k < h; ++k)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i++];
        } else
        {
            arr[k] = R[j++];
        }
    }

    delete[] L;
    delete[] R;
}


void print(int* nums, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";
}
#endif //SORT_H