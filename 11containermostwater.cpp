/* 暴力法，时间复杂度太高*/
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int max = 0;int n = height.size(); 
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 int l = j-i;
//                 int h = (height[j]>height[i])?height[i]:height[j];
//                 int area = h*l;
//                 if(area > max){
//                     max = area;
//                 }
//             }
//         }
//         return max;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            while (i < j && h == height[i]) ++i;
            while (i < j && h == height[j]) --j;
        }
        return res;
    }
};