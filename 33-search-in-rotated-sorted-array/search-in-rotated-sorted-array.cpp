class Solution {
public:
    int search(vector<int>& arr, int target) {
        int numsSize = arr.size();
        int start = 0;
        int end = numsSize - 1;

        while(start < end){  
            int mid = start + (end - start)/2;
            if(arr[mid] > arr[end]){
                start = ++mid;
            }
            else{
                end = mid;
            }
        }
        
        if(target >= arr[end] && target <= arr[numsSize - 1]){
            end = numsSize - 1;
        }
        else{
            start = 0;
            end--;
        }
        
        while(start <= end){
            int mid = start + (end - start)/2;

            if(arr[mid] == target){
                return mid;
            }
            if(target > arr[mid]){
                start = ++mid;
            }
            else{
                end = --mid;
            }
        }
        return -1;
    }
};