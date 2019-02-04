class Solution {
public:
    int myAtoi(string str) {
        int flag=0;
        int len =str.size();
        long result=0;//保证能检测到上溢下溢
        for(int i=0;i<len;i++){
            if(flag==0){
                if(str[i]=='+')flag=1;
                else if(str[i]=='-')flag=-1;
                else if(str[i]==' ')continue;
                else if(str[i]>='0'&&str[i]<='9'){
                    result=str[i]-'0';
                    flag=1;
                }else{
                    return 0;
                }
            }
            else{
                if(str[i]>='0'&&str[i]<='9'){
                    result=result*10+(str[i]-'0');
                    if(result*flag<INT_MIN)return INT_MIN;
                    if(result*flag>INT_MAX)return INT_MAX;
                }else if(result!=0){
                    break;
                }else{
                    return 0;
                }
            }
        }
        return result*flag;
    }
};
