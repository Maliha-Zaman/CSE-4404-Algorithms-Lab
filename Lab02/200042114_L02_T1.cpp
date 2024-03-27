#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
int level[8][8];
int visited[8][8];
int BFS(string src,string des)
{
    vector<pair<int,int>> moves=
    {
    {1,2},
    {1,-2},
    {-1,2},
    {-1,-2},
    {2,1},
    {2,-1},
    {-2,1},
    {-2,-1}
    };
    int srcX= src[0]-'a';
    int srcY=src[1]-'1';
    int desX=des[0]-'a';
    int desY=des[1]-'1';
    queue<pair<int,int>>knight;
    knight.push({srcX,srcY});
    visited[srcX][srcY]=1;
      level[srcX][srcY]=0;
    while(!knight.empty())
    {
        pair<int,int> v= knight.front();
        int x=v.first;
        int y=v.second;

        knight.pop();
        for(auto moves:moves)
        {
            int nextX=x+ moves.first;
            int nextY=y+moves.second;
            if(nextX>=0 && nextY>=0 && nextY<8 && nextX<8)
            {
                if(!visited[nextX][nextY])
                {
                    knight.push({nextX,nextY});
                    level[nextX][nextY]= level[x][y]+1;
                    visited[nextX][nextY]=1;
                }
            }

        }

    }
    return level[desX][desY];
}
    int main()
    {
        string source,des;
        cin>>source>>des;
        cout<< "To get from"<<" "<<source<<" "<<"to"<<" "<<des<<" "<<"takes"<<" "<<BFS(source,des)<<" "<<"knight moves";
        return 0;
    }

