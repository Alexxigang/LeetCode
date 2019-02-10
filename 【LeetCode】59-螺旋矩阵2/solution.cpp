class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0){
            return {};
        }
        
        int cols=n,rows=n;
        int max=n*n;
        int left=0,right=n-1,top=0,bottom=n-1;
        int temp=1;
        vector<vector<int >>result(n,vector<int>(n,0));//这里提前初始化数组矩阵空间大小
        if(n==1){
            result[0][0]=1;
        }
        while(left<=right&&top<=bottom&&temp<=max){
            for(int i=left;i<=right;i++){
                result[top][i]=temp++;
            }
            for(int i=top+1;i<=bottom;i++){
                result[i][right]=temp++;
            }
            if(top!=bottom&&temp<=max){
                for(int i=right-1;i>=left;i--){
                    result[bottom][i]=temp++;
                }
            }
            if(left!=right&&temp<=max){
                for(int i=bottom-1;i>top;i--){
                    result[i][left]=temp++;
                }
            }
            left++,top++,right--,bottom--;
        }
        return result;
    }
};
