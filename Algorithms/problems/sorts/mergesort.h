#include <vector>

#ifndef MERGESORT_H
#define MERGESORT_H

class MergeSort
{
public:
    void sortArray(std::vector<int>& nums) {
        mergesort(nums, 0, static_cast<int>(nums.size()) - 1);
    }

    static void mergesort(std::vector<int>& nums, int l, int h)
    {
        if (0 <= l && l < h && h < nums.size())
        {
            int middle = (l + h) / 2;
            mergesort(nums, l, middle);
            mergesort(nums, middle + 1, h);
            merge(nums, l, middle, h);
        }
    }

    static void merge(std::vector<int>& nums, int l, int m, int h)
    {
        std::vector<int> l_arr(nums.begin() + l, nums.begin() + m + 1);
        std::vector<int> r_arr(nums.begin() + m + 1, nums.begin() + h + 1);

        l_arr.push_back(std::numeric_limits<int>::max());
        r_arr.push_back(std::numeric_limits<int>::max());

        int l_idx = 0;
        int r_idx = 0;

        for (int k = l; k <= h; ++k)
        {
            if (l_arr[l_idx] <= r_arr[r_idx])
            {
                nums[k] = l_arr[l_idx++];
            } else
            {
                nums[k] = r_arr[r_idx++];
            }
        }
    }
};
#endif //MERGESORT_H
