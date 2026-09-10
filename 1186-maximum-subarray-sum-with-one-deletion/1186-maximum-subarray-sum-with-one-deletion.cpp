class Solution { 
public: 
    int maximumSum(vector<int>& arr) { 
        int nodel = arr[0]; 
        int onedel = -1000000000; 
        int answer = arr[0]; 
 
        for(int i = 1; i < arr.size(); i++) { 
            int prevnodel = nodel; 
 
            onedel = max(prevnodel, onedel + arr[i]); 
 
            nodel = max(arr[i], prevnodel + arr[i]); 
 
            answer = max(answer, max(nodel, onedel)); 
        } 
 
        return answer; 
    } 
};