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

void sort() {
    unsigned short numbers_count;
    std::cin >> numbers_count;
    int numbers[numbers_count];
    for(unsigned short i = 0; i < numbers_count; i++) {
        std::cin >> numbers[i];
    }
    for(unsigned short i = 0; i < numbers_count; i++) {
        for(unsigned short j = i; j < numbers_count; j++) {
            if (numbers[i] > numbers[j]) {
                numbers[i] += numbers[j];
                numbers[j] = numbers[i] - numbers[j];
                numbers[i] -= numbers[j];
            }
        }
    }
    for(int& num : numbers) {
        std::cout << num << ' ';
    }
}

// On the first row you will get an integer N, N < 100. On the second line you will get N integers.
// Sort the numbers with the selection method - On each of N - 1 steps we find the i-th smallest element
// and put it in its place. On separate rows print the result of each step

void selection_sort()
{
    unsigned short numbers_count;
    std::cin >> numbers_count;
    int numbers[numbers_count];
    for(unsigned short i = 0; i < numbers_count; i++) {
        std::cin >> numbers[i];
    }
    int min;
    unsigned short min_idx;
    for(unsigned short i = 0; i < numbers_count - 1; i++) {
        min = numbers[i];
        min_idx = i;
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
        for(unsigned short j = 0; j < numbers_count; j++) {
            std::cout << numbers[j];
            if (j < numbers_count - 1) {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
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
        print(nums, n);
    }
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
