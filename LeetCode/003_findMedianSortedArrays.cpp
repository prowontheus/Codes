//
// Created by 丁月星 on 2020/8/7.
//
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        while(m > 0 && n > 0)
        {
            if(nums1.[m/2] > nums1.[n/2])
            {
                m /= 2;
                n /= 2;
            }
            else if(nums1.[m/2] > nums1.[n/2])
            {}
            else
            {
                return nums1.[m/2];
            }
        }
    }
};