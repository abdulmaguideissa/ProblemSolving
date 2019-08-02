/*
  Find the kth largest element in an unsorted array. Note that it is the kth largest element 
  in the sorted order, not the kth distinct element.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = k - 1;
        
        quick_sort(nums, 0, nums.size() - 1);
        return (nums[index]);
    }
    
    void swap(int& left, int& right){
        left ^= right;
        right ^= left;
        left ^= right;
    }
    
    int arr_partition(vector <int>& arr, int beg, int end){
        bool flag = false;
        int location = beg;
        int left  = beg;
        int right = end;
        
        while(!flag){
            while(arr[location] >= arr[right] && location != right){
                right--;
            }
            if(location == right){
                flag = true;
            }
            else if(arr[location] < arr[right]){
                swap(arr[location], arr[right]);
                location = right;
            }
            if(!flag){
                while(arr[location] <= arr[left] && location != left){
                    left++;
                }
                if(location == left){
                    flag = true;
                }
                else if(arr[location] > arr[left]){
                    swap(arr[location], arr[left]);
                    location = left;
                }
            }
        }
        return location;
    }
    
    void quick_sort(vector <int>& arr, int beg, int end){
        int static location;
        
        if(beg < end){
            location = arr_partition(arr, beg, end);
            quick_sort(arr, beg, location - 1);
            quick_sort(arr, location + 1, end);
        }
    }
};
