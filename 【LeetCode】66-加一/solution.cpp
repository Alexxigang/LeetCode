class Solution {
//从最后一位判断，如果是9，则加一之后又进位，所以变为0，然后前面的加一再做判断，如果第一位也变成了0，则要在第一位前面添加1
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
            }else{
                digits[i]+=1;
                return digits;
            }
        }
        if(digits.front()==0)digits.insert(digits.begin(),1);
        return digits;
    }
};
