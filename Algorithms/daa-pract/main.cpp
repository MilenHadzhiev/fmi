#include <iostream>

void bubble_sort(int* nums, int n);

void print(int* nums, int n);

int main() {
    int n;
    std::cin >> n;
    int* nums = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }
    bubble_sort(nums, n);
    delete[] nums;
    return 0;
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