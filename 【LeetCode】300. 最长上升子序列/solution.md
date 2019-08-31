#### 解法一：  
首先来看一种动态规划 Dynamic Programming 的解法，这种解法的时间  复杂度为 O(n2)，类似 brute force 的解法，维护一个一维 dp 数组，  其中 dp[i] 表示以 nums[i] 为结尾的最长递增子串的长度，对于每一个   nums[i]，从第一个数再搜索到i，如果发现某个数小于 nums[i]，更新   dp[i]，更新方法为 dp[i] = max(dp[i], dp[j] + 1)，即比较当前   dp[i] 的值和那个小于 num[i] 的数的 dp 值加1的大小，就这样不断的  更新 dp 数组，到最后 dp 数组中最大的值就是我们要返回的 LIS 的长  度，参见代码如下：  

```

	class Solution {
	public:
	    int lengthOfLIS(vector<int>& nums) {
	        vector<int> dp(nums.size(), 1);
	        int res = 0;
	        for (int i = 0; i < nums.size(); ++i) {
	            for (int j = 0; j < i; ++j) {
	                if (nums[i] > nums[j]) {
	                    dp[i] = max(dp[i], dp[j] + 1);
	                }
	            }
	            res = max(res, dp[i]);
	        }
	        return res;
	    }
	};
    

```

#### 解法二：  
面来看一种优化时间复杂度到 O(nlgn) 的解法，这里用到了二分查找法，  所以才能加快运行时间哇。思路是，先建立一个数组 ends，把首元素放进  去，然后比较之后的元素，如果遍历到的新元素比 ends 数组中的首元素小  的话，替换首元素为此新元素，如果遍历到的新元素比 ends 数组中的末尾  元素还大的话，将此新元素添加到 ends 数组末尾(注意不覆盖原末尾元  素)。如果遍历到的新元素比 ends 数组首元素大，比尾元素小时，此时用  二分查找法找到第一个不小于此新元素的位置，覆盖掉位置的原来的数字，  以此类推直至遍历完整个 nums 数组，此时 ends 数组的长度就是要求的  LIS的长度，特别注意的是 ends 数组的值可能不是一个真实的 LIS，比如  若输入数组 nums 为 {4, 2， 4， 5， 3， 7}，那么算完后的 ends 数  组为 {2， 3， 5， 7}，可以发现它不是一个原数组的 LIS，只是长度相  等而已，千万要注意这点。参见代码如下：     

```

	class Solution {
	public:
	    int lengthOfLIS(vector<int>& nums) {
	        if (nums.empty()) return 0;
	        vector<int> ends{nums[0]};
	        for (auto a : nums) {
	            if (a < ends[0]) ends[0] = a;
	            else if (a > ends.back()) ends.push_back(a);
	            else {
	                int left = 0, right = ends.size();
	                while (left < right) {
	                    int mid = left + (right - left) / 2;
	                    if (ends[mid] < a) left = mid + 1;
	                    else right = mid;
	                }
	                ends[right] = a;
	            }
	        }
	        return ends.size();
	    }
	};

```


    
