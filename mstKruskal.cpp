/*Minimum Spanning Tree*/

#include <iostream>
#include <cstring>
using namespace std;

struct Edge
{
  int u,v,w;
  void set(int a, int b, int c) {u = a; v = b; w = c;}
};

struct Graph
{
  int V, E;
  struct Edge *edge;
};

struct Subset
{
  int parent;
  int rank;
};

int find(struct Subset subsets[], int index)
{
  if(subsets[index].parent != index)
    subsets[index].parent = find(subsets, subsets[index].parent);
  return subsets[index].parent;
}

int myComp(const void *a, const void *b)
{
  struct Edge *ea = (struct Edge *)a;
  struct Edge *eb = (struct Edge *)b;
  return ea->w - eb->w;
}

void Union(struct Subset subsets[], int x, int y)
{
  int xroot = find(subsets,x);
  int yroot = find(subsets,y);
  
  if(subsets[xroot].rank < subsets[yroot].rank){
    subsets[xroot].parent = yroot;
  }
  else if(subsets[xroot].rank > subsets[yroot].rank){
    subsets[yroot].parent = xroot;
  }
  else{
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

struct Graph * CreateGraph(struct Graph * graph)
{
  int V,E;
  cin>>V>>E;
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = v;
  graph->E = E;
  graph->edge = (struct Edge*)malloc(graph->E * (struct Edge));
  
  int u,v,w;
  for(int e = 1; e <= E; ++e){
    cin>>u>>v>>w;
    graph->edge[e].set(u,v,w);
  }
  return graph;
}

void Kruskal(struct Graph * graph)
{
  int e = 0;
  int i = 0;
  struct Graph * result = (struct Graph *)malloc(graph->E * sizeof(struct Graph));
  qsort();
  struct Subset * subsets = (struct Subset *)malloc(graph->V * sizeof(struct Subset));
  for(int v = 1; v <= V; ++v){
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }
  while(e < graph->V-1){
    struct Edge next = graph->edge[i++];
    int x = find();
    int y = find();
    if(x!=y){
      result[e++] = next;
      Union(subsets,x,y);
    }
  }  
  
  for(int i = 0; i < e; ++i){
   cout<<result[i].u<<','<<result[i].v<<','<<result[i].w<<endl;
  }

void examFunc()
{
  struct Graph * graph;
  CreateGraph(graph);
  Kruskal(graph);
}

int main()
{
  int CaseNum;
  int testCase;
  cin>>CaseNum;
  for(testCase = 1; testCase <= CaseNum; ++testCases){
    examFunc();
  }
  return 0;
}

/*
1
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
*/
