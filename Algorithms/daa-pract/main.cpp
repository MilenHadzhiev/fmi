#include <iostream>
#include <climits>

void merge(int* arr1, size_t l, size_t mid, size_t h);

int main() {
    size_t n1, n2, total;
    std::cin >> n1;
    std::cin >> n2;
    total = n1 + n2;
    int* nums = new int[total];
    for (size_t i = 0; i < n1; ++i)
    {
        std::cin >> nums[i];
    }
    for (size_t i = 0; i < n2; ++i)
    {
        std::cin >> nums[i + n1];
    }
    merge(nums, 0,n1, total);
    for (int i = 0; i < total; ++i)
    {
        std::cout << nums[i] << ' ';
    }
    delete[] nums;
    return 0;
}

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
