#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADArbol.h"

void Initialize(Tree *t)
{
	*t = NULL;

	return;
}

void Destroy(Tree *t)
{
	if((*t)->right != NULL)
		Destroy(&((*t)->right));
	if((*t)->left != NULL)
		Destroy(&((*t)->left));

	free(*t);

	return;
}

void NewRightSon(Tree *t, Position p, element e)
{
	if(Empty(t))
	{	
		*t = malloc(sizeof(node));
		(*t)->e = e;
		(*t)->right = NULL;
		(*t)->left = NULL;
		(*t)->middle_right = NULL;		
		(*t)->middle_left = NULL;				
	}
	else
	{
		p->right = malloc(sizeof(node));
		p->right->e = e;
		p->right->right = NULL;
		p->right->left = NULL;
		p->right->middle_right = NULL;
		p->right->middle_left = NULL;
	}

	return;
}

void NewLeftSon(Tree *t, Position p, element e)
{
	if(Empty(t))
	{	
		*t = malloc(sizeof(node));
		(*t)->e = e;
		(*t)->right = NULL;
		(*t)->left = NULL;
		(*t)->middle_right = NULL;		
		(*t)->middle_left = NULL;
	}
	else
	{
		p->left = malloc(sizeof (node));
		p->left->e = e;
		p->left->right = NULL;
		p->left->left = NULL;
		p->left->middle_right = NULL;
		p->left->middle_left = NULL;
	}

	return;
}

void DeleteRightSon(Position p)
{
	Destroy(&(p->right));
	p->right = NULL;
	return;
}

void DeleteLeftSon(Position p)
{
	Destroy(&(p->left));
	p->left = NULL;
	return;
}

void DeleteNode(Tree *t, Position p)
{
	Position father = Father(t, p);
	
	if (father->right == p)
		father->right = NULL;
	else 
		if (father->left == p)
			father->left = NULL;

	Destroy(&p);

	return;
}

void ReplaceNode(Position p, element e)
{
    p->e = e;

	return;
}

Position Root(Tree *t)
{
	return *t;
}

Position Father(Tree *t, Position p)
{
	Position father = NULL;

	if((*t)->right == p || (*t)->middle_right == p || (*t)->middle_left == p || (*t)->left == p)
		return *t;

	if((*t)->right != NULL)
		father = Father(&((*t)->right), p);

	if((*t)->middle_right != NULL && father == NULL)
		father = Father(&((*t)->middle_right), p);

	if((*t)->middle_left != NULL && father == NULL)
		father = Father(&((*t)->middle_left), p);

	if((*t)->left != NULL && father == NULL)
		father = Father(&((*t)->left), p);

	return father;	
}

Position RightSon(Position p)
{
	return p->right;	
}

Position LeftSon(Position p)
{
	return p->left;
}

Position Search(Tree *t, element e)
{
	Position p = NULL;

	if (memcmp(&((*t)->e), &e, sizeof(element)) == 0)
		return *t;
	if((*t)->right != NULL)
		p = Search(&((*t)->right), e);
	if((*t)->left != NULL && p == NULL)
		p = Search(&((*t)->left), e);
	if((*t)->middle_left != NULL && p == NULL)
		p = Search(&((*t)->middle_left), e);
	if((*t)->middle_right != NULL && p == NULL)
		p = Search(&((*t)->middle_right), e);

	return p;
}


bool Empty(Tree *t)
{
	if(*t != NULL)
		return false;
	else
		return true;	
}

bool NullNode(Tree *t, Position position)
{
	bool b = true; 

	if (*t == position)
		return false;
	if((*t)->right != NULL)
		b = NullNode(&((*t)->right), position);
	if((*t)->middle_right != NULL && b == true)
		b = NullNode(&((*t)->middle_right), position);
	if((*t)->middle_left != NULL)
		b = NullNode(&((*t)->middle_left), position);
	if((*t)->left != NULL && b == true)
		b = NullNode(&((*t)->left), position);

	return b;
}

element ReadNode(Position p)
{
  return p->e;
}

//|+|+|+|+|+|+|+|+|+|RECENTLY CREATED
Position NextSon(Position father, Position position, bool *son_visited)
{
	if(father->middle_right != position && son_visited[0] != true)
	{
		son_visited[0] = true;
		return father->middle_right;
	}
	else if(father->middle_left != position && son_visited[1] != true)
	{
		son_visited[1] = true;
		return father->middle_left;
	}
	else if(father->left != position && son_visited[2] != true)
	{
		son_visited[2] = true;
		return father->left;
	}

	return NULL;
}

Position SearchNonVisited(Tree *t, int levels)
{
	Position position = NULL;

	if ((*t)->e.visited == false && (*t)->e.level == levels)
		return *t;
	if((*t)->right != NULL)
		position = SearchNonVisited(&((*t)->right), levels);
	if((*t)->middle_right != NULL && position == NULL)
		position = SearchNonVisited(&((*t)->middle_right), levels);
	if((*t)->middle_left != NULL && position == NULL)
		position = SearchNonVisited(&((*t)->middle_left), levels);
	if((*t)->left != NULL && position == NULL)
		position = SearchNonVisited(&((*t)->left), levels);

	return position;
}

Position SearchInLevel(Tree *t, int levels)
{
	Position position = NULL;

	if ((*t)->e.level == levels)
		return *t;

	if((*t)->right != NULL)
		position = SearchInLevel(&((*t)->right), levels);

	if((*t)->middle_right != NULL && position == NULL)
		position = SearchInLevel(&((*t)->middle_right), levels);

	if((*t)->middle_left != NULL && position == NULL)
		position = SearchInLevel(&((*t)->middle_left), levels);

	if((*t)->left != NULL && position == NULL)
		position = SearchInLevel(&((*t)->left), levels);

	return position;
}

void NewMiddleRightSon(Tree *t, Position p, element e)
{
	if(Empty(t))
	{	
		*t = malloc(sizeof(node));
		(*t)->e = e;
		(*t)->right = NULL;
		(*t)->left = NULL;
		(*t)->middle_right = NULL;		
		(*t)->middle_left = NULL;				
	}
	else
	{
		p->middle_right = malloc(sizeof(node));
		p->middle_right->e = e;
		p->middle_right->right = NULL;
		p->middle_right->left = NULL;
		p->middle_right->middle_right = NULL;
		p->middle_right->middle_left = NULL;
	}

	return;
}

void NewMiddleLeftSon(Tree *t, Position p, element e)
{
	if(Empty(t))
	{	
		*t = malloc(sizeof(node));
		(*t)->e = e;
		(*t)->right = NULL;
		(*t)->left = NULL;
		(*t)->middle_right = NULL;		
		(*t)->middle_left = NULL;
	}
	else
	{
		p->middle_left = malloc(sizeof (node));
		p->middle_left->e = e;
		p->middle_left->right = NULL;
		p->middle_left->left = NULL;
		p->middle_left->middle_right = NULL;
		p->middle_left->middle_left = NULL;
	}

	return;
}

bool IsSon(Position father, Position position)
{
	if(father->right == position || father->middle_right == position || father->middle_left == position || father->left == position)
		return true;

	return false;	
}

Position MiddleRightSon(Position position)
{
	return position->middle_right;	
}

Position MiddleLeftSon(Position position)
{
	return position->middle_left;
}

void PreOrder(Tree *t, Position position)
{
	element e;
	if(!NullNode(t, position))
	{
		e = ReadNode(position);
		printf(" %c", e.c);
		PreOrder(t, LeftSon(position));
		PreOrder(t, MiddleLeftSon(position));
		PreOrder(t, MiddleRightSon(position));
		PreOrder(t, RightSon(position));
	}
	return;
}

Position SearchNode(Tree *t, char ch, int levels)
{
	Position p = NULL;

	if(ch == 'A')
	{
		if((*t)->e.level == levels)
			return *t;
	}
	else if((*t)->e.level == levels && (*t)->e.c == ch)
	{
		return *t;
	}

	if((*t)->right != NULL)
		p = SearchNode(&((*t)->right), ch, levels);

	if((*t)->middle_right != NULL && p == NULL)
		p = SearchNode(&((*t)->middle_right), ch, levels);

	if((*t)->middle_left != NULL && p == NULL)
		p = SearchNode(&((*t)->middle_left), ch, levels);

	if((*t)->left != NULL && p == NULL)
		p = SearchNode(&((*t)->left), ch, levels);

	return p;
}