#include <iostream>
#include <vector>
#include <limits>

// merge sorted arrays - https://leetcode.com/problems/merge-sorted-array/?envType=problem-list-v2&envId=sorting
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int current_start_idx = 0;
        for (int i = 0; i < n; ++i)
        {
            while (current_start_idx < m)
            {
                if (nums2[i] < nums1[current_start_idx])
                {
                    nums1.insert(nums1.begin() + current_start_idx, nums2[i]);
                    nums1.pop_back();
                    current_start_idx++;
                    break;
                }
                current_start_idx++;
            }
        }
    }
};

int main()
{
    std::vector<int> a = {1, 2, 3, 0, 0, 0};
    std::vector<int> b = {2, 5, 6};

    Solution s;
    s.merge(a, 3, b, 3);
    for (int num : a)
    {
        std::cout << num << '\n';
    }

    return 0;
}