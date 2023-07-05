#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print(int *a, int s, int t)
{
    if(a[t] != -1 && t != s)
        print(a, s, a[t]);
    cout << t << endl;
}

struct LinkNode{
    int val;
    LinkNode *pre;
    LinkNode *next;

    void add(int val);
    int get(int i);
};

void LinkNode::add(int val)
{
    LinkNode *tmpL = new LinkNode;
    tmpL->next = NULL;
    tmpL->val = val;

    LinkNode *tmp = this;
    while(tmp->next)
    {
        tmp = tmp->next;
    }

    tmp->next = tmpL;
    tmpL->pre = tmp;
}

int LinkNode::get(int i)
{
    int cnt = 0;
    LinkNode *tmp = this;
    while(tmp)
    {
        if(cnt == i)
        {
            return this->val;
        }
        cnt++;
        tmp = tmp->next;
    }
    return -1;
}

struct LinkList
{
    int val;
    LinkNode *node;
};

class graph
{
public:
    int num;
    LinkList *adj;

public:
    graph(int num);
    ~graph();

    void addEdge(int s, int t);
    void bfs(int s, int t);
    void dfs(int s, int t);
    void recurDfs(int s, int t, vector<bool> &visited, int *pre);
};

graph::graph(int n)
{
    num = n;
    adj = new LinkList[num];
    for(int i=0;i < num; i++)
    {
        adj[i].val = -1;
        adj[i].node = new LinkNode;
    }
}

graph::~graph()
{
    delete [] adj;
}

void graph::addEdge(int s, int t)
{
    if(!adj)
        return;

    for(int i =0; i < num; i++)
    {
        if(adj[i].val == s)
        {
            adj[i].node->add(t);
            break;
        }
        else if(adj[i].val == -1)
        {
            adj[i].val = s;
            adj[i].node->add(t);
            break;
        }

    }

    for(int j = 0; j < num; j++)
    {
        if(adj[j].val == t)
        {
            adj[j].node->add(s);
            break;
        }else if(adj[j].val == -1)
        {
            adj[j].val = t;
            adj[j].node->add(s);
            break;
        }
    }
}

void graph::bfs(int s, int t)
{
    if(s == t)
        return;

    std::vector<bool> visited(num);
    visited[s] = true;
    int *pre = new int[num];
    for(int i =0;i<num;i++)
    {
        pre[i] = -1;
    }
    queue<int>que;
    que.push(s);

    while(que.size()!=0)
    {
        int w = que.front();
        que.pop();
        for(int i =0; i<num ; i++)
        {
            if(adj[i].val == w)
            {
                LinkNode *tmp = adj[i].node->next;
                while(tmp)
                {
                    if(!visited[tmp->val])
                    {
                        pre[tmp->val] = w;
                        if(t == tmp->val)
                        {
                            print(pre, s, t);
                            /*
                            for(int j=0;j<num;j++)
                            {
                                cout << pre[j]<<endl;
                            }*/
                            return;
                        }
                        visited[tmp->val] = true;
                        que.push(tmp->val);
                    }
                    tmp =tmp->next;
                }
                break;
            }
        }
    }
    

}

bool found = false;

void graph::recurDfs(int s, int t, vector<bool> &visited, int *pre)
{
    if(found)
        return;

    visited[s] = true;
    if(s==t)
    {
        found = true;
        return;
    }

    for(int i=0; i< num; i++)
    {
        if(adj[i].val==s)
        {
            LinkNode *tmp = adj[i].node->next;
            while(tmp)
            {
                if(!visited[tmp->val])
                {
                    pre[tmp->val] = s;
                    recurDfs(tmp->val, t, visited, pre);
                }
                tmp=tmp->next;
            }
        }
    }
}

void graph::dfs(int s, int t)
{
    std::vector<bool>visited(num);
    int *pre = new int[num];
    for(int i=0;i<num;i++)
    {
        pre[i]=-1;
    }

    recurDfs(s, t, visited, pre);
    print(pre, s, t);
}

int main()
{
    graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 7);

    for(int i=0; i < g.num; i++)
    {
        cout << "*****************"<<endl;
        cout << g.adj[i].val << endl;
        cout << "edge" << endl;
        LinkNode *tmp = g.adj[i].node->next;
        while(tmp)
        {
            cout << tmp->val << endl;
            tmp = tmp->next;
        }
        cout << "*****************"<<endl;
    }

    g.bfs(0, 7);
    g.dfs(0, 7);
    return -1;
}
