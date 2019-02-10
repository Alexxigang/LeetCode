class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty()){//对于输入为[]的判断，防止出现空指针错误
            return {};
        }
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> result; 
        int left=0,right=cols-1,top=0,down=rows-1;
        while(left<=right&&top<=down){
            for(int i=left;i<=right;i++){//从左往右
                result.push_back(matrix[top][i]);
            }
            for(int j=top+1;j<=down;j++){//从上往下
                result.push_back(matrix[j][right]);
            }
            if(top!=down){//这里判断上下是否重叠，避免重复上面的遍历
                for(int i=right-1;i>=left;i--){//从右往左
                    result.push_back(matrix[down][i]);
                }
            }
            if(left!=right){//这里判断左右是否重叠，避免重复上面的遍历
                for(int j=down-1;j>top;j--){//从下往上
                    result.push_back(matrix[j][left]);
                }
            }
            left++,top++,down--,right--;
        }
        return result;
    }
};
