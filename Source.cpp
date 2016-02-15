#include "Tree.h"
using namespace std;

int main()
{
	NodePtr node;

	Tree GeneralTree;
	GeneralTree.Create();
	GeneralTree.PostTravel();
	//GeneralTree.clear();
	node=GeneralTree.GetRoot();
	node=node->firstchild->sibling;
	GeneralTree.NodeRemove(node);

	system("pause");
	return 0;
}