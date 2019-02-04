class Solution {
/*
这里用到了动态规划，基本的表达式: area = min(height[i], height[j]) * (j - i) 使用两个指针，值小的指针向内移动，这样就减小了搜索空间 
因为面积取决于指针的距离与值小的值乘积，如果值大的值向内移动，距离一定减小，而求面积的另外一个乘数一定小于等于值小的值，
因此面积一定减小，而我们要求最大的面积，因此值大的指针不动，而值小的指针向内移动遍历
*/
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
        int l=0;
        int r=height.size()-1;
        while(l<r){
            maxarea=max(maxarea,min(height[l],height[r])*(r-l));
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxarea;
    }
};
