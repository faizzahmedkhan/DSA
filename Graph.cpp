#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Graph
{

public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);
        if (direction==0)
        {
            adj[v].push_back(u);
        }
    }

    void bfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,vector<int> &ans,int node){
        queue<int>q;
        q.push(node);
        visited[node]=true;
        while (!q.empty())
        {
            int front=q.front();
            q.pop();

            ans.push_back(front);

            for(auto i:adj[front]){
                if (!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }       
            }
        }
    }

    void BFS(int vertex){
        vector<int> ans;
        unordered_map<int,bool> visited;
        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])    
            {
                bfs(adj,visited,ans,i);
            }
            
        }
        for (auto i:ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    void dfs(int node, unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,vector<int> component){
        component.push_back(node);
        visited[node]=true;
        for(auto i:adj[node]){
            if (!visited[node])
            {
                dfs(i,adj,visited,component);
            }   
        }
        for (int i = 0; i < component.size(); i++)
        {
            cout << component[i] << " ";
        }
        cout << endl;
    }

    void DFS(int vertex){
        vector<vector<int>> ans;
        unordered_map<int,bool> visited;
        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])    
            {
                vector<int> component;
                dfs(i,adj,visited,component);
                ans.push_back(component);
            }
            
        }
    }
    
    bool CycleBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
    {
        unordered_map<int, int> parent;
        parent[src] = -1;
        visited[src] = 1;
        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto neighbour : adj[front])
            {
                if (visited[neighbour] == true && neighbour != parent[front])
                {
                    return true;
                }
                else if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    parent[neighbour] = front;
                }
            }
        }
        return false;
    }

    string CycleDet(int vertex)
    {
        unordered_map<int, bool> visited;
        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                bool ans = CycleBFS(i, visited, adj);
                if (ans==1)
                {
                    return "yes";
                }
                
            }
        }
        return "No";
    }
    
    void shortest(int s, int d){
        unordered_map<int, bool> visited;
        unordered_map<int,int> parent;
        queue<int>q;
        q.push(s);
        visited[s]=true;
        while (!q.empty())
        {
            int front=q.front();
            q.pop();

            for(auto i:adj[front]){
                if (!visited[i])
                {
                    visited[i]=true;
                    parent[i]=front;
                    q.push(i);
                }                
            }
        }
        
        vector<int>ans;
        int currN=d;
        ans.push_back(d);
        while (currN!=s)
        {
            currN=parent[currN];
            ans.push_back(currN);
        }
        reverse(ans.begin(),ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges: ";
    cin>>m;

    Graph g;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,false);
    }
    g.print();
    g.BFS(n);
    // g.DFS(n);
    string check = g.CycleDet(n);
    cout << check << endl;

    g.shortest(0,3);
}