/*最小生成树*/
#define USE_CXX 1

#ifdef USE_CXX
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

#else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge
{
  int u, v, w;
};
typedef struct Graph
{
  int V, E;
  typedef struct Edge *edge;
};
typedef struct Subset
{
  int parent;
  int rank;
};
#endif





void examFunc()
{
  
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
