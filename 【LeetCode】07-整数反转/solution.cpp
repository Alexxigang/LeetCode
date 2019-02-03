class Solution {
/*
如果 number>INT_MAX/10那么 number=number*10+x%10 一定会溢出。
如果 number==INT_MAX/10，那么只要(x%10)>7，number=number*10+x%10 就会溢出。
*/
public:
    int reverse(int x) {
        bool minus=false;
        if(x<0){
            minus=true;
            x=-x;
        }
       
        int number=0;
        while(x){
            if(number>INT_MAX/10||(number==INT_MAX/10&&(x%10)>7)){
                return 0;
            }
            if(number<INT_MIN/10||(number==INT_MIN/10&&(x%10)<-8)){
                return 0;
            }
            number=number*10+x%10;
            x/=10;
        }
        return minus==false?number:(-number);
    }
};
