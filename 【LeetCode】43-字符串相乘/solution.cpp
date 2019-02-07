class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int n1=num1.size(),n2=num2.size();
        int k=n1+n2-2;
        vector<int> temp(n1+n2,0);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                temp[k-i-j]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        int carray=0;
        for(int i=0;i<n1+n2;i++){
            temp[i]+=carray;
            carray=temp[i]/10;
            temp[i]%=10;
        }
        int i=n1+n2-1;
        while(temp[i]==0)i--;//结果中需要去掉前导0
        if(i<0)return "0";//还需要注意结果为0的情况
        while(i>=0){
            res.push_back(temp[i--]+'0');
        }
        return res;
    }
};
