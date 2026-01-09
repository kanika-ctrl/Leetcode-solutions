class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int min=arr[0];
        int smin=INT_MAX;
        for(int i=1;i<arr.size();i++){
           if(min>=arr[i]){
            min=arr[i];
           }
           else if(smin>arr[i]){
            smin=arr[i];
           }
           else if(arr[i]>smin&&arr[i]>min){
            return true;
           }
           }
        
        return false;
    }
};