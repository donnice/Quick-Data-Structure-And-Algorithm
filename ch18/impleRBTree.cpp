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

// If both parent P and uncle U are red
// then both should be black and grandparent G becomes red
// the G may violate 2 and 4
// 2. the root is black
// 4. both children of every red are black
// 4 is violated becuase G may have red parent
// to fix, the entire procedure should be performed on G from case 1

void insert_case3(struct node *n)
{
	struct node *u = uncle(n), *g;
	if((u!=NULL) && (u->color == RED))
	{
		n->parent->color = BLACK;
		u->color = BLACK;
		g = grandparent(n);
		g->color = RED;
		insert_case1(g);
	} else {
		insert_case4(n);
	}
}


