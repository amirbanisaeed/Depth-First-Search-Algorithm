#include <iostream>
#include <vector>

using std::pair;
using std::vector;
using namespace std;

void explore(vector<vector<int>>& w, vector<bool>& visited, int node, int& destination, bool& succeeded, int& cnt)
{
    //cout << "Node " << node << "  Desti: " << endl;
    cnt++;


    // cout << "Hey";
    if (node == destination && cnt != 1)
    {
        //cout << "Node: " <<node << "Cnt: " << cnt << endl;
        succeeded = true;
        return;
    }

    if (visited[node])
    {
        return;
    }

    else
    {
        visited[node] = true;
        for (size_t i = 0; i < w[node].size(); i++)
        {
            // if (!visited[w[node][i]])
            // {
                // cout << "Next Node: " << w[node][i]<< endl;
            explore(w, visited, w[node][i], destination, succeeded, cnt);
            // cout << "Node " << node << "  Desti: " << endl;
       // }
        }
    }
}

int reach(vector<vector<int>>& adj, int n)
{
    vector<bool> visited;
    visited.resize(adj.size());

    //   for (size_t i = 0; i < visited.size(); i++)
     //  {
      //     visited[i] = false;
       //}

       // cout << visited.size() << "   " << adj.size();

    bool succeeded = false;
    int x = 0;
    int cnt = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < visited.size(); j++)
        {
            visited[j] = false;
        }

        x = i;
        cnt = 0;
        explore(adj, visited, i, x, succeeded, cnt);
        if (succeeded)
        {
            return 1;
        }
    }


    //write your code here
    return 0;
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    for (size_t i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        //adj[y - 1].push_back(x - 1);
    }
    /*
        for (size_t i = 0; i < adj.size(); i++)
        {
            for (size_t j = 0; j < adj[j].size(); j++)
            {
                cout << adj[i][j] << endl;
            }


        }
        cout << "finish" << endl;
    */
    //int x, y;
    //std::cin >> x >> y;
    std::cout << reach(adj, adj.size());
}
