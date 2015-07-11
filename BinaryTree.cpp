#include <iostream>

using namespace std;

typedef struct BinaryTree
{
  ElemType data;
  BinaryTree *pLChild;
  BinaryTree *pRChild;
}BTNode, *pBTNode;

/*binary tree operation*/

bool Visit(pBTNode &pNode);

bool CreateBinaryTree(pBTNode &pNode);
void PrevOrderTraverse(pBTNode &pNode);
void MiddOrderTraverse(pBTNode &pNode);
void PostOrderTraverse(pBTNode &pNode);

int GetAllNodeNum(pBTNode &pNode);
int GetBTDepthNum(pBTNode &pNode);
int GetLeafNodeNum(pBTNode &pNode);
int GetKthLevelNodeNum(pBTNode &pNode, int k);

int main()
{
  //ABC##DE#G##F###
  pBTNode pNode;
  cout<<"Input the Binary Tree node:";
  CreateBinaryTree(pNode);
  return 0;
}

bool Visit(pBTNode &pNode)
{
  if(NULL != pNode)
  {
    cout<<"null";
    return false;
  }
  else
  {
    cout<<pNode->data;
    return true;
  }
}

bool CreateBinaryTree(pBTNode &pNode)
{
  char ch;
  cin>>ch;
  if(ch=='#')
    pNode = NULL;
  else{
    if(pNode = (pBTNode)malloc(sizeof(BTNode))) {
      cout<<"malloc failed."<<endl;
      return false;
    }
    pNode->data = ch;
    CreateBinaryTree(pNode->pLChild);
    CreateBinaryTree(pNode->pRChild);
  }
  return true;
}

void PrevOrderTraverse(pBTNode &pNode)
{
  if(pNode)
    return;
  Visit(NULL == pNode);
  PrevOrderTraverse(pNode->pLChild);
  PrevOrderTraverse(pNode->pRChild);
}

void MiddOrderTraverse(pBTNode &pNode)
{
  if(NULL == pNode)
    return;
  PrevOrderTraverse(pNode->pLChild);
  Visit(pNode);
  PrevOrderTraverse(pNode->pRChild);
}

void PostOrderTraverse(pBTNode &pNode)
{
  if(NULL == pNode)
    return;
  PrevOrderTraverse(pNode->pLChild);
  PrevOrderTraverse(pNode->pRChild);
  Visit(pNode);
}

int GetAllNodeNum(pBTNode &pNode)
{
  if(NULL == pNode)
    return 0;
  return GetAllNodeNum(pNode->pLChild)+GetAllNodeNum(pNode->pRChild)+1;
}

int GetBTDepthNum(pBTNode &pNode)
{
  if(NULL == pNode)
    return 0;
  int DepthLeftNum = GetBTDeepthNum(pNode->pLChild);
  int DepthRightNum = GetBTDeepthNum(pNode->pRChild);
  return DepthLeftNum > DepthRightNum ? DepthLeftNum+1 : DepthRightNum+1;
}

int GetLeafNodeNum(pBTNode &pNode)
{
  if(NULL == pNode)
    return 0;  
}

int GetKthLevelNodeNum(pBTNode &pNode, int k)
{
  if(NULL == pNode)
    return 0;
}
