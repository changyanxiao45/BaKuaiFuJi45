/*最小生成树*/
#include <iostream>
using namespace std;

#define TEMP_PRINT

#define MAX_V (100+1)
#define MAX_I 20000000

int CaseNum, V, E;
int Closest[MAX_V] = {0,};
int Lowcost[MAX_V] = {0,};
int Matrix[MAX_V][MAX_V] = {{0,},};
bool Visit[MAX_V] = {false,};

void TempPrint()
{
  int i, j;
  for(i = 1; i <= V; ++i){
    for(j = 1; j <=V; ++j){
      cout<<Matrix[i][j]<<' ';
    }
    cout<<endl;
  }
  cout<<endl;
}

void InitBaseData()
{
  int i, j;
  cin>>V>>E;
  for(i = 1; i <= V; ++i){
    for(j = 1; j <= V; ++j){
      Matrix[i][j] = MAX_I;
    }
    Closest[i] = 1;
    Lowcost[i] = 0;
    Visit[i] = false;
  }
}

void CreateMatrix()
{
  int i, j;
  int u, v, w;
  for(i = 1; i <= E; ++i){
    cin>>u>>v>>w;
    Matrix[u][v] = w;
  };
  for(j = 1; j <= V; ++j){
    Lowcost[j] = Matrix[1][j];
  }
  Visit[1] = true;
}
void PrimMST()
{
  int i,k;
  for(i = 1; i < V; ++i)
  {
    int j = 2;
    int min = MAX_I;
    for(k = 2; k <= V; ++k){
      if(!Visit[j] && Lowcost[k]<min){
        min = ;
        j = k;
      }
    }
    Visit[j] = true;
    cout<<'('<<Closest[j]<<','<<j<<')'<<endl;
    for(k = 2; k <= V; ++k){
      if(!Visit[k] && Matrix[j][k]<Lowcost[k]){
        Lowcost[k] = Matrix[j][k];
        Closest[k] = j;
      }
    }
  }
}
  
void examFunc()
{
  InitBaseData();
  CreateMatrix();
  PrimMST();
}

int main()
{
  int testCase;
  cin>>CaseNum;
  for(testCase = 1; testCase <= CaseNum; ++testCase ){
    
    cout<<"Case# "<<testCase<<endl;
    examFunc();
  }
}
