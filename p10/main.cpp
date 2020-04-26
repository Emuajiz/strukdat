#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAXNUM_VERTICES = 1000;
typedef pair<unsigned int, int> PII;
vector<PII> adj[MAXNUM_VERTICES];

unsigned int prim(int);
unsigned int dijkstra(int, int);

int main()
{
    bool undirected = 1;
    int n, k, x, y;
    unsigned int weight, minimumCost;

    // soal 1
    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        // soal 1
        cin >> x >> y >> weight;

        adj[x].push_back(make_pair(weight, y));

        // soal 2
        if(undirected)
            adj[y].push_back(make_pair(weight, x));

    }
    
    cout << prim(1) << endl;
    cout << dijkstra(1, 3) << endl;

    return 0;
}

unsigned int prim(int x)
{
    bool selected[MAXNUM_VERTICES] = {false};
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    unsigned int minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // soal 3
        p = Q.top();
        Q.pop();

        x = p.second;
        if(selected[x] == true) continue;

        minimumCost += p.first;
        selected[x] = true;

        for (int i = 0; i < adj[x].size(); i++)
        {
            y = adj[x][i].second;
            if(selected[y] == false)
                Q.push(make_pair(adj[x][i].first, y));
        }
        
    }
    return minimumCost;
}

unsigned int dijkstra(int s, int f)
{
    bool selected[MAXNUM_VERTICES] = {false};
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y, counter = 0;
    unsigned int jarak = 0;
    PII p;
    Q.push(make_pair(0, s));

    while(!Q.empty())
    {
        // soal 3
        counter++;
        p = Q.top();
        Q.pop();

        s = p.second;
        if(selected[s] == true) continue;

        jarak = p.first;
        selected[s] = true;

        cout << counter << " " << s << " " << f << endl;
        if (s == f) break;

        for (int i = 0; i < adj[s].size(); i++)
        {
            y = adj[s][i].second;
            if(selected[y] == false)
                Q.push(make_pair(adj[s][i].first + jarak, y));
        }
        
    }
    return jarak;
}