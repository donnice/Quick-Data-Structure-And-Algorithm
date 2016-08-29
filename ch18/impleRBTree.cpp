struct node *grandparent(struct node *n)
{
	if((n!=NULL) && (n->parent != NULL))
		return n->parent->parent;
	else
		return NULL;
}

struct node *uncle(struct node *n)
{
	struct node *g = grandparent(n);
	if(g == NULL)
		return NULL; // No grandparent
	if(n->parent == g->left)
		return g->right;
	else
		return g->left;
}

// the current node N is at the root of the tree
// repainted black to satisfy p2(root is black)

void insert_case1(struct node* n)
{
	if(n->parent == NULL)
		n->color=BLACK;
	else
		insert_case2(n);
}

// the current node's parent P is black
// so (both child of every red are black) is not invalidated
// all path.. same # of black nodes is not threatened
// bacause current node N has 2 black leaf children
// and N is red

void insert_case2(struct node* n)
{
	if(n->parent->color == BLACK)
		return;
	else
		insert_case3(n);
}

