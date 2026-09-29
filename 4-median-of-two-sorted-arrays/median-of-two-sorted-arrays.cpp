class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();

        if(s1 > s2) return findMedianSortedArrays(nums2, nums1);

        int total = s1 + s2;
        int ps = (total)/2;

        int low = 0;
        int high = s1;

        while(low <= high){
            int mid1 = low + (high - low)/2;
            int mid2 = ps - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == s1) ?  INT_MAX : nums1[mid1];
            int r2 = (mid2 == s2) ? INT_MAX : nums2[mid2];

            if(l1 <= r2 && l2 <= r1){
                if(total % 2) return std::min(r1,r2);
                else return (std::max(l1,l2) + std::min(r1,r2))/2.0;
            }

            if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;

        }

        return 0.0;
    }
};