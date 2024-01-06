/*
Hard
Topics
Companies
Hint
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:



Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
Example 3: */


class Solution {
public:
int n;
int t[50001];
     int findNextIdx(vector<vector<int>>&arr, int l,int target){
         int r=n-1;
         int ans=n+1;
         while(l<=r){
             int mid=l+(r-l)/2;
             if(arr[mid][0]>=target){
                 ans=mid;
                 r=mid-1;
             }
             else{
               l=mid+1;
             }
         }
return ans;
     }
    int solve(vector<vector<int>>&arr,int idx){
        if(idx>=n)return 0;
        if(t[idx]!=-1)return t[idx];
        int next=findNextIdx(arr,idx+1,arr[idx][1]);
        int taken=arr[idx][2]+solve(arr,next);
        int not_taken=solve(arr,idx+1);
        return t[idx]= max(taken,not_taken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
       n=startTime.size();
       vector<vector<int>>arr(n,vector<int>(3,0));
       for(int i=0;i<n;i++){
           arr[i][0]=startTime[i];
           arr[i][1]=endTime[i];
           arr[i][2]=profit[i];
       }
       sort(arr.begin(),arr.end());
       memset(t,-1,sizeof(t));
       return solve(arr,0);
    }
};



Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
