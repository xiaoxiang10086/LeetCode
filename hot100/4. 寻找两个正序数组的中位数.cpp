class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int tot = n + m;
        if (tot % 2 == 0) {
            int left = findKth(nums1, 0, n-1, nums2, 0, m-1, tot/2);
            int right = findKth(nums1, 0, n-1, nums2, 0, m-1, tot/2+1);
            return (left+right)/2.0;
        } else {
            return findKth(nums1, 0, n-1, nums2, 0, m-1, tot/2+1);
        }
    }

    int findKth(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2, int r2, int k) {
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        if (len1 > len2) return findKth(nums2, l2, r2, nums1, l1, r1, k);
        if (len1 == 0) return nums2[l2+k-1];

        if (k == 1) return min(nums1[l1], nums2[l2]);

        int i = l1 + min(len1, k/2) - 1;
        int j = l2 + min(len2, k/2) - 1;
        if (nums1[i] <= nums2[j]) {
            return findKth(nums1, i+1, r1, nums2, l2, r2, k-(i-l1+1));
        } else {
            return findKth(nums1, l1, r1, nums2, j+1, r2, k-(j-l2+1));
        }
    }
};
