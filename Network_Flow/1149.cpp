#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

#define NODE_NUM 1105
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
    if (flow == 0){
        dis[x] = 0;
    }
    return flow;
}

int nwFlow(){
    int flow = 0;
    while(BFS()){
        int fl = 1;
        while(fl){
            memset(cur, 0, sizeof(cur));
            fl = DFS(s, INF_NUM);
            flow += fl;
        }
    }
    return flow;
}

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> m >> n;
    int p, q;
    int vst[1005] = {0};
    s = 1;t = m+n+2;
    for (int i = 1; i <= m; i++){
        cin >> p;
        insertEdge(s, s+i, p);
    }
    for (int i = 1; i <= n; i++) {
        cin >> p;
        for (int j = 0; j < p; j++){
            cin >> q;
            if (vst[q] == 0){
                vst[q] = m+i+1;
                insertEdge(q+1, m+i+1, INF_NUM);
            }
            else{
                insertEdge(vst[q], m+i+1, INF_NUM);
            }
        }
        cin >> q;
        insertEdge(m+i+1, t, q);
    }
    cout << nwFlow() << endl;
    return 0;
}