#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

#define NODE_NUM 205
#define INF_NUM 1000000000

struct Edge{
    int from, to, cap, flow;
    Edge(int a, int b, int c, int d){
        from = a;to = b;cap = c;flow = d;
    }
};

vector<Edge> edges;
vector<int> G[NODE_NUM];

void insertEdge(int from, int to, int cap){
    Edge e1(from,to,cap,0);
    Edge e2(to,from,0,0);
    edges.push_back(e1);
    edges.push_back(e2);
    int m = (int)edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
}

int s, t;
int vis[NODE_NUM];
int dis[NODE_NUM];
int cur[NODE_NUM];

bool BFS(){
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    vis[s] = 1;
    dis[s] = 0;
    q.push(s);
    while(q.empty() == false){
        int x = q.front();q.pop();
        for(int i = 0; i < G[x].size(); i++){
            Edge e = edges[G[x][i]];
            if (!vis[e.to] && e.cap > e.flow){
                vis[e.to] = 1;
                dis[e.to] = dis[x] + 1;
                q.push(e.to);
            }
        }
    }
    return vis[t] != 0;
}

int DFS(int x, int a){
    if (x == t || a == 0)
        return a;
    int flow = 0, f;
    for (int& i = cur[x]; i < G[x].size(); i++){
        Edge& e = edges[G[x][i]];
        if (dis[e.to] == dis[x] + 1){
            int tmp = e.cap - e.flow;
            tmp = a < tmp ? a : tmp;
            f = DFS(e.to, tmp);
            if (f <= 0)
                continue;
            flow += f;
            a -= f;
            e.flow += f;
            edges[G[x][i]^1].flow -= f;
            if (a <= 0)
                break;
        }
    }
    return flow;
}

int nwFlow(){
    int flow = 0;
    while(BFS()){
        memset(cur, 0, sizeof(cur));
        flow += DFS(s, INF_NUM);
    }
    return flow;
}

int main(int argc, const char * argv[]) {
    int n, m;
    while(cin >> n >> m){
        s = 1;t = m;
        memset(dis, 0, sizeof(dis));
        edges.clear();
        for (int i = 0; i <= m; i++) {
            G[i].clear();
        }
        while(n--){
            int from, to, cap;
            cin >> from >> to >> cap;
            insertEdge(from, to, cap);
        }
        cout << nwFlow() << endl;
    }
    return 0;
}
