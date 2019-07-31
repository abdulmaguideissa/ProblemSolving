class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(nums1.empty()){
            return MedianOfOneArr(nums2);
        }
        else if(nums2.empty()){
            return MedianOfOneArr(nums1);
        }
        else{
            double median = 0.0;
            
            if(nums1[n1 - 1] > nums2[n2 - 1]){
                nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
                sort(nums1.begin(), nums1.end());
                median = MedianOfOneArr(nums1);
            }
            else{
                nums2.insert(nums2.begin(), nums1.begin(), nums1.end());
                sort(nums2.begin(), nums2.end());
                median = MedianOfOneArr(nums2);
            }
            return median;
        }
    }
    
    double MedianOfOneArr(vector <int> arr){
        int n = arr.size();
        
        if(n % 2 == 0){  // length is even
            return (double)(arr[n / 2] + arr[(n - 1) / 2]) / 2.0;
        }
        else{            // length is odd
            return (double)arr[n / 2];
        }
    }
};
