class Solution {
/*
思路：和前面求众数一样，利用计数器，因为出现次数超过n/3，所以一个数组中最多只能出现两个要求的众数，所以设置两个值，然后按照前面的方法遍历数组，最后在验
证出现次数是否超过n/3，使用投票法的核心是找出两个候选众数进行投票，需要两遍遍历，第一遍历找出两个候选众数，第二遍遍历重新投票验证这两个候选众数是否为众
数即可，选候选众数方法和前面那个Majority Element 
求众数一样，由于之前那题题目中限定了一定会有众数存在，故而省略了验证候选众数的步骤，这道题却没有这种限定，即满足要求的众数可能不存在，所以要有验证
*/
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int resm=0,resn=0,cntM=0,cntN=0;
        for(auto &num:nums){
            if(num==resm)++cntM;
            else if(num==resn)++cntN;
            else if(cntM==0){
                resm=num;
                cntM++;
            }else if(cntN==0){
                resn=num;
                cntN++;
            }else{
                cntM--;
                cntN--;
            }
        }
        int cntm=0,cntn=0;
        for(auto &num:nums){
            if(num==resm){
                cntm++;
            }
            else if(num==resn){
                cntn++;
            }
        }
        int len=nums.size();
        if(cntm>len/3){
            res.push_back(resm);
        }
        if(cntn>len/3){
            res.push_back(resn);
        }
        return res;
    }
};
