#include<bits/stdc++.h>
using namespace std;    
class Solution {
    private:
    void bfs(int n,int m ,vector<vector<int>>&image,int sr,int sc,int color){
         vector<vector<int>>vis(n,vector<int>(m,0));
          int start  = image[sr][sc];
         queue<pair<int,int>>q;
         q.push({sr,sc});
          vis[sr][sc]=1;
         while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
             q.pop();
                   int delrow[] = {-1, 1, 0, 0};
            int delcol[] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++) {
                int nrow = r + delrow[k];
                int ncol = c + delcol[k];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] &&
                    image[nrow][ncol]==start) {
                        if(image[nrow][ncol]==start){
                            image[nrow][ncol]=color;
                        }

                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
         }
    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
                                      
        // code here
       
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc]==newColor)
        return image ;
        
        
        bfs(n,m,image,sr,sc,newColor);
        image[sr][sc]=newColor;
        return image ;
        
        
    }
};