#include <iostream>

using namespace std;

typedef struct BinaryTree
{
  ElemType data;
  BinaryTree *pLChild;
  BinaryTree *pRChild;
}BTNode, *pBTNode;

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

int main()
{
  //ABC##DE#G##F###
  pBTNode pNode;
  cout<<"Input the Binary Tree node:";
  CreateBinaryTree(pNode);
  return 0;
}
