//Link to the problem:- https://www.interviewbit.com/problems/subset-sum-problem/
int Solution::solve(vector<int> &A, int sum) {
    
    bool dp[A.size()+1][sum+1];
    
    for(int i=0; i<sum+1; i++){
        dp[0][i]=0;
    }
    
    for(int i=0;i<A.size()+1; i++)
    {
        dp[i][0]=1;
    }
    
    
    for(int i=1;i<A.size()+1; i++){
        for(int j=1; j<sum+1; j++){
            
            if(A[i-1]<=j){
                dp[i][j]=((dp[i-1][j-A[i-1]])||(dp[i-1][j]));
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
        
    }    
        return dp[A.size()][sum];
    
}
