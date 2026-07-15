class Solution {
   public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int i = low;
        int j = mid + 1;
        while (i <= mid && j <= high) {
            if (nums[i] < nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= high) {
            temp.push_back(nums[j]);
            j++;
        }
        int in=0;
        for (int i = low; i <=high; i++) {
            nums[i] = temp[in];
            in++;
        }
        return;
    }
    void mergesort(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        mergesort(nums, low, mid);
        mergesort(nums, mid + 1, high);
        merge(nums, low, mid, high);
        return;
    }
    vector<int> sortArray(vector<int>& nums) { 
    mergesort(nums, 0, nums.size()-1);
    return nums; }
};