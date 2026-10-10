#include<bits/stdc++.h>
using namespace std;
// problem statement
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.











class Solution {
public:
     void bfs(int start, vector<int>&vis , vector<vector<int>>list){
      vis[start]++;
      int n = list.size();
      queue<int>q;
      q.push(start);
      vector<int>bfs;
      while(!q.empty()){
         int node =  q.front();
         q.pop();
         bfs.push_back(node);
         for(auto it : list[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
         }
      }
        
     }
    int findCircleNum(vector<vector<int>>& isConnected) {  int cnt =0;
          
        int n=isConnected[0].size();
        vector<int>vis(n+1,0);
       vector<vector<int>>list(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 ){
                  list[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                bfs(i,vis,list);
            }
        }
      return cnt ;
        
    }
};