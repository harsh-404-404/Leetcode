class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> final {};
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                final.push_back(nums1[i]);
                i++;
            }else{
                final.push_back(nums2[j]);
                j++;
            }
        }

        while(i < nums1.size()) final.push_back(nums1[i++]);
        while(j < nums2.size()) final.push_back(nums2[j++]);
        
        if(final.size() % 2){
            return final[(final.size()/2)];
        }else{
            int m = (final.size())/2;
            return (final[m] + final[m-1])/2.0;
        }
    }
};