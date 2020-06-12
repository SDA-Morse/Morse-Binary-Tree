/* ------------------------------------------------------------------------------------ 
Program          	 :binarytreedinamis.c
Deskripsi       	 :Body dari header file (binarytreedinamis.h) pada ADT binarytreedinamis
Author  	   		 :
Versi / tanggal  	 :01/16 Mei 2020
Compiler  		 	 :Dev-C++ 5.11
---------------------------------------------------------------------------------------*/
#include "binarytreedinamis.h"

/*=============== Konstruktor ===============*/
void createTree(BTree *tree)
{
	(*tree).root = NULL;
}

address createNode(datatype dat)
{
	address newNode;
	
	newNode = (address)malloc(sizeof(nodeBTree));
	if(newNode != NULL)
	{
		newNode->data = dat;
		newNode->parent = NULL;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	else
	{
		printf("Node baru tidak dapat dimasukkan");
	}
}

address insertRoot(BTree *tree, datatype dat)
{
	address newNode;
	
	if(isEmpty(*tree))
	{
		newNode = createNode(dat);
		
		((*tree).root) = newNode;
		
	}
	else
	{
		printf("Root pada Binary Tree telah terdefinisi");
	}
	
	return newNode;
}

address insertLeft(BTree *tree, datatype dat, address parent)
{
	address newNode;
	
	if(isEmpty(*tree))
	{
		printf("Masukkan nilai root terlebih dahulu");
	}
	else
	{
		newNode = createNode(dat);
		parent->left = newNode;
		newNode->parent = parent;
	}
	
	return newNode;
}

address insertRight(BTree *tree, datatype dat, address parent)
{
	address newNode;
	
	if(isEmpty(*tree))
	{
		printf("Masukkan nilai root terlebih dahulu");
	}
	else
	{
		newNode = createNode(dat);
		parent->right = newNode;
		newNode->parent = parent;
	}
	
	return newNode;
}

/*=============== Validasi ===============*/
boolean isEmpty(BTree tree)
{
	return (tree.root == NULL);
}

/*=============== Getter & Setter ===============*/
address getLeft(address node)
{
	address left;
	
	if(node != NULL)
	{
		left = node->left;
	}
	
	return left;
}

address getRight(address node)
{
	address right;
	
	if(node != NULL)
	{
		right = node->right;
	}
	
	return right;
}

/*=============== Destructor ===============*/
void deallocNode(address *newNode)
{
	(*newNode)->left = NULL;
	(*newNode)->right = NULL;
	free(*newNode);
}

void deleteNode(address *node)
{
	if(*node != NULL)
	{
		deleteNode((*node)->left);
		deleteNode((*node)->right);
		deallocNode(node);
	}
}

void deleteTree(BTree *tree)
{
	if(!isEmpty(*tree))
	{
		deleteNode((*tree).root);
		free(tree);
	}
}

/*=============== Transversal Tree ===============*/
void preorder(address temp)
{
	if(temp != NULL)
	{
		printf("%c ", temp->data);
		preorder(getLeft(temp));
		preorder(getRight(temp));
	}
}

void inorder(address temp)
{
	if(temp != NULL)
	{
		inorder(getLeft(temp));
		printf("%c ", temp->data);
		inorder(getRight(temp));
	}
}

void postorder(address temp)
{
	if(temp != NULL)
	{
		postorder(getLeft(temp));
		postorder(getRight(temp));
		printf("%c ", temp->data);
	}
}

/*=============== Read and Write ===============*/
