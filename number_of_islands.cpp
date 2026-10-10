#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
 void bfs(int r,int c, vector<vector<int>>&vis , vector<vector<char>>&grid){int n = grid.size();
 int m = grid[0].size();
     vis[r][c]=1;
     queue<pair<int,int>>q;
     q.push({r,c});
     while(!q.empty()){
     int r=q.front().first;
     int c = q.front().second ;

        q.pop();
        // traverse neighbours and mark them if they are land 
       int delrow[] = {-1, 1, 0, 0};
int delcol[] = {0, 0, -1, 1};

for (int k = 0; k < 4; k++) {
    int nrow = r + delrow[k];
    int ncol = c + delcol[k];

    if (nrow >= 0 && nrow < n &&
        ncol >= 0 && ncol < m &&
        !vis[nrow][ncol] &&
        grid[nrow][ncol] == '1') {

        vis[nrow][ncol] = 1;
        q.push({nrow, ncol});
    }
}
        

             }
     }
    int numIslands(vector<vector<char>>& grid) {
         int cnt =0;
          
        int n = grid.size();
        int m = grid[0].size();

       vector< vector<int>>vis(n,vector<int>(m,0));
       
       for(int row =0;row<n;row++)
{
    for(int col =0 ;col<m;col++){
        if(!vis[row][col] && grid[row][col]=='1'){
            cnt++;
            bfs(row,col,vis,grid);
        }
    }
}       
      return cnt ;
    }
};