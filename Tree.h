#ifndef _TREE_H
#define _TREE_H

#include<iostream>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>

using namespace std;

typedef char ElemType;

typedef struct Node
{
	ElemType data;
	Node* parent;
	Node* sibling;
	Node* firstchild;
	int children_num;
}Node,*NodePtr;

class Tree
{
public:
	Tree();
	~Tree();
	void Create();
	void CreateFirstChild(NodePtr current,NodePtr& firstchild,int& Numchildren,int level);
	void CreateSibling(NodePtr& parent,NodePtr& Nextsibling,int& Numsibling,int level);
	void clear();
	void clear(NodePtr& current);
	void NodeRemove(NodePtr node);
	bool isLeaf(NodePtr node);
	bool isFirstChild(NodePtr node);
	void ChildrenRemove(NodePtr parent);
	void PreTravel();
	void PreTravel(NodePtr current);
	void InorderTravel();
	void InorderTravel(NodePtr current);
	void PostTravel();
	void PostTravel(NodePtr current);
	NodePtr GetRoot();
private:
	NodePtr root;
};

#endif