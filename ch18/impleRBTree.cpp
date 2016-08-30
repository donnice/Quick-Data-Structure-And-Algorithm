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

// P is red but U is black
// N is the right child of P and P in turn is left child of G
// a left rotation on P switch the N and P can be performed
// P need a case five to solve property 4
// "all paths from any given to its leaf nodes contains the same #
// of black nodes" is not violated

void insert_case4(struct node *n)
{
	struct node *g = grandparent(n);

	if((n == n->parent->right) && n->parent == g->left){
		rotate_left(n->parent);

		n = n->left;

	} else if((n == n->parent->left)&&(n->parent == g->right)){
		rotate_right(n->parent);
		n = n->right;
	}
	insert_case5(n);
}

// a right rotation of G is performed
void insert_case5(struct node *n)
{
	struct node *g = grandparent(n);

	n->parent->color = BLACK;
	g->color = RED;
	if(n == n->parent->left)
		rotate_right(g);
	else
		rotate_left(g);
}

struct node *sibling(struct node *n)
{
	if((n == NULL) || (n->parent == NULL))
		return NULL;

	if(n == n->parent-left)
		return n->parent->right;
	else
		return n->parent->pleft;
}

void delete_one_child(struct node *n)
{
	struct node *child = is_leaf(n->right)? n->left:n->right;

	replace_node(n,child);
	if(n->color == BLACK)
	{
		if(child->color == RED)
			child->color = BLACK;
		else
			delete_case1(child);
	}
	free(n);
}

// case 1: N is a new root
// we removed one black node and the new root is black

void delete_case1(struct node *n)
{
	if(n->parent != NULL)
		delete_case2(n);
}

// N is the left child of P
// S(silbing) is red
// reverse the colors of P and S and left rotate left at P
// turning S into N's grandparent
// P has to be black as it had a red child

void delete_case2(struct node *n)
{
	struct node *s = sibling(n);

	if(s->color == RED)
	{
		n->parent->color = RED;
		s->color = BLACK;
		if(n == n->parent->left)
			rotate_left(n->parent);
		else
			rotate_right(n->parent);
	}
	delete_case3(n);
}

// P,S and S's Children are black
// repaint S into red

void delete_case3(struct node *n)
{
	struct node *s = sibling(n);

	if((n->parent->color == BLACK) &&
	   (s->color == BLACK) &&
	   (s->left->color == BLACK) &&
	   (s->right->color == BLACK))
	{
		s->color = RED;
		delete_case1(n->parent);
	} else
		delete_case4(n);
}

// S and S's Children are balck, but P is red
// change S and P's color
void delete_case4(struct node *n)
{
	struct node *s = sibling(n);

	if((n->parent->color == RED)&&
	   (s->color == BLACK) &&
	   (s->left->color == BLACK) &&
	   (s->right->color == BLACK)){
		s->color = RED;
		n->parent->color=BLACK;
	} else
		delete_case5(n);
}

// S is black, and S's left child is red while right is black
// N is left child of parent
// rotate right at S
// but now N has a black Sibling whose right child is red
// to case 6

void delete_case5(struct node *n)
{
	struct node *s = sibling(n);

	if(s->color == BLACK) {
		if((n == n->parent->left) &&
		   (s->right->color == BLACK) &&
		   (s->left->color == RED)){
			s->color = RED;
			s->left->color = BLACK;
			rotate_right(s);
		} else if((n == n->parent->right) &&
				  (s->left->color == BLACK) &&
				  (s->right->color == RED)){
		      s->color = RED;
			  s->right->color = BLACK;
			  rotate_left(s);
		}
	}
	delete_case6(n);
}


	}
}
