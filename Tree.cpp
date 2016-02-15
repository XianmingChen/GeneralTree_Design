#include "Tree.h"

Tree::Tree()
{
	root=NULL;
}

Tree::~Tree()
{
	clear();
}

NodePtr Tree::GetRoot()
{
	return root;
}

void Tree::clear()
{
	ChildrenRemove(root);
	delete root;
	root=NULL;
}

void Tree::NodeRemove(NodePtr node)
{
	NodePtr PreSibling;

	if(node==NULL)
		return;

	if(node==root)
		return;

	if(node->children_num>0)
	{
		ChildrenRemove(node);
	}

	if(isFirstChild(node)==true)
	{
		node->parent->firstchild=node->sibling;
	}
	else
	{
		PreSibling=node->parent->firstchild;
		while(PreSibling->sibling!=node)
			PreSibling=PreSibling->sibling;

		PreSibling->sibling=node->sibling;
	}
	node->parent->children_num--;
	delete node;
}

void Tree::ChildrenRemove(NodePtr parent)
{
	NodePtr tmp;
	queue<NodePtr> offspring;

	if(parent==NULL)
		return;

	tmp=parent->firstchild;

	if(tmp!=NULL)
		offspring.push(tmp);

	while(!offspring.empty())
	{
		tmp=offspring.front();
		if(tmp->firstchild!=NULL)
			offspring.push(tmp->firstchild);

		if(tmp->sibling!=NULL)
			offspring.push(tmp->sibling);

		offspring.pop();
		delete tmp;
	}
}


bool Tree::isFirstChild(NodePtr node)
{
	if(node==NULL)
		return false;

	if(node->parent->firstchild==node)
		return true;
	else
		return false;
}

bool Tree::isLeaf(NodePtr node)
{
	if(node==NULL)
		return false;

	if(node->firstchild==NULL)
		return true;
	else
		return false;
}

void Tree::Create()
{
	char temp;

	cout<<"Please input the value for the root node."<<endl;
	cin>>temp;

	if(temp=='#')
	{
		return;
	}
	else
	{
		root=new Node;
		root->data=temp;
		root->parent=NULL;
		root->sibling=NULL;
		root->firstchild=NULL;
		root->children_num=0;
		
		CreateFirstChild(root,root->firstchild,root->children_num,1);
	}
}

void Tree::CreateFirstChild(NodePtr current,NodePtr& firstchild,int& Numchildren,int level)
{
	char temp;
	NodePtr tmpnode;

	cout<<"Please input the value for the node 0 of level "
		<<level<<endl;

	cin>>temp;

	if(temp=='#')
	{
		CreateSibling(current->parent,current->sibling,current->parent->children_num,level-1);
	}
	else
	{
		tmpnode=new Node;
		tmpnode->data=temp;
		tmpnode->parent=current;
		tmpnode->sibling=NULL;
		tmpnode->firstchild=NULL;
		tmpnode->children_num=0;

		firstchild=tmpnode;
		Numchildren++;

		CreateFirstChild(tmpnode,tmpnode->firstchild,tmpnode->children_num,level+1);
	}
}

void Tree::CreateSibling(NodePtr& parent,NodePtr& Nextsibling,int& Numsibling,int level)
{
	char temp;
	NodePtr tmpnode;

	if(level<1)
		return;

	cout<<"Please input the value for the node "<<Numsibling<<" of level "
		<<level<<endl;

	cin>>temp;
	if(temp=='#')
	{
		CreateSibling(parent->parent,parent->sibling,parent->parent->children_num,level-1);
	}
	else
	{
		tmpnode=new Node;
		tmpnode->data=temp;
		tmpnode->parent=parent;
		tmpnode->sibling=NULL;
		tmpnode->firstchild=NULL;
		tmpnode->children_num=0;

		Nextsibling=tmpnode;
		Numsibling++;

		CreateFirstChild(tmpnode,tmpnode->firstchild,tmpnode->children_num,level+1);
	}	
}

void Tree::PreTravel()
{
	PreTravel(root);
}

void Tree::PreTravel(NodePtr current)
{
	NodePtr sibling;

	if(current==NULL)
		return;

	cout<<current->data<<endl;	
	if(current->firstchild!=NULL)
	{	
		PreTravel(current->firstchild);
		sibling=current->firstchild->sibling;
		while(sibling!=NULL)
		{
			PreTravel(sibling);
			sibling=sibling->sibling;
		}
	}
}

void Tree::InorderTravel()
{
	InorderTravel(root);
}

void Tree::InorderTravel(NodePtr current)
{
	NodePtr sibling;

	if(current==NULL)
		return;
	
	if(current->firstchild!=NULL)
	{	
		InorderTravel(current->firstchild);
	}
	cout<<current->data<<endl;

	if(current->firstchild!=NULL)
	{
		sibling=current->firstchild->sibling;
		while(sibling!=NULL)
		{
			InorderTravel(sibling);
			sibling=sibling->sibling;
		}
	}
}

void Tree::PostTravel()
{
	PostTravel(root);
}

void Tree::PostTravel(NodePtr current)
{
	NodePtr sibling;

	if(current==NULL)
		return;
	
	if(current->firstchild!=NULL)
	{	
		PostTravel(current->firstchild);
	}

	if(current->firstchild!=NULL)
	{
		sibling=current->firstchild->sibling;
		while(sibling!=NULL)
		{
			PostTravel(sibling);
			sibling=sibling->sibling;
		}
	}

	cout<<current->data<<endl;
}