class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1;
        int max = *std::max_element(piles.begin(),piles.end()); 
        while(min <= max){
            int mid = min + (max - min)/2;

            int time = h;
            int i = 0;

            while(time > -1 && i < piles.size()){
                time -= piles[i] / mid;
                time -= (piles[i] % mid) ? 1 : 0; 
                i++;
            }
            if(time >= 0) max = mid - 1;

            else min = mid + 1;
        };
        
        return min;
    }
};