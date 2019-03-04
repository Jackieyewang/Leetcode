// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
//         int num= n+m;
//         int mid = num/2;
//         int cho = num%2;
//         vector<double> nums;
//         int i,j,k; 
//         double result;
//         for(i=0,j=0,k=0;i<n,j<m,k<=mid;k++){
//             if(nums1[i]<=nums2[j]){
//                 nums[k] = nums1[i];
//                 i++;
//             }
//             else{
//                 nums[k] = nums2[j];
//                 j++;
//             }
//         }
//         if(k<mid+1){
//             if(i<n){
//                 for(j=i;j<n;j++,k++){
//                     nums[k] = nums1[j];
//                 }
//             }
//             if(j<m){
//                 for(i=j;i<m;i++,k++){
//                     nums[k] = nums2[i];
//                 }
//             }
//         }

//         result = nums[mid];
//         return result;
//     }
// };


public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        if (m < n) return findMedianSortedArrays(nums2, nums1);
        if (n == 0) return (nums1[(m - 1) / 2] + nums1[m / 2]) / 2.0;
        int left = 0, right = 2 * n;
        while (left <= right) {
            int mid2 = (left + right) / 2;
            int mid1 = m + n - mid2;
            double L1 = mid1 == 0 ? Double.MIN_VALUE : nums1[(mid1 - 1) / 2];
            double L2 = mid2 == 0 ? Double.MIN_VALUE : nums2[(mid2 - 1) / 2];
            double R1 = mid1 == m * 2 ? Double.MAX_VALUE : nums1[mid1 / 2];
            double R2 = mid2 == n * 2 ? Double.MAX_VALUE : nums2[mid2 / 2];
            if (L1 > R2) left = mid2 + 1;
            else if (L2 > R1) right = mid2 - 1;
            else return (Math.max(L1, L2) + Math.min(R1, R2)) / 2;
        }
        return -1;
    }
}