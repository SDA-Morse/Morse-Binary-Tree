/* --------------------------------------------------------------------------------------------------- 
Program          	 :morse.c
Deskripsi       	 :Body dari header file (morse.h) pada ADT morse
Author  	   		 :
Referensi			 :https://phitchuria.wordpress.com/2018/04/04/algorithm-c-morse-code-binary-tree/
Versi / tanggal  	 :01/16 Mei 2020
Compiler  		 	 :Dev-C++ 5.11
------------------------------------------------------------------------------------------------------*/
#include "binarytreedinamis.h"
#include "morse.h"

BTree createMorseBTree(BTree morseBtree)
{
	address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF;
	address nodeG, nodeH, nodeI, nodeJ, nodeK, nodeL;
	address nodeM, nodeN, nodeO, nodeP, nodeQ, nodeR;
	address nodeS, nodeT, nodeU, nodeV, nodeW, nodeX;
	address nodeY, nodeZ, nodeSpace;
	
	
	createTree(&morseBtree);
	
	morseBtree.root = insertRoot(&morseBtree, '^');
	morseBtree.root->left = insertLeft(&morseBtree, 'e', morseBtree.root); nodeE = morseBtree.root->left;
	morseBtree.root->right = insertRight(&morseBtree, 't', morseBtree.root); nodeT = morseBtree.root->right;
	
	nodeE->left = insertLeft(&morseBtree, 'i', nodeE); nodeI = nodeE->left;
	nodeE->right = insertRight(&morseBtree, 'a', nodeE); nodeA = nodeE->right;
	nodeT->left = insertLeft(&morseBtree, 'n', nodeT); nodeN = nodeT->left;
	nodeT->right = insertRight(&morseBtree, 'm', nodeT); nodeM = nodeT->right;
	
	nodeI->left = insertLeft(&morseBtree, 's', nodeI); nodeS = nodeI->left;
	nodeI->right = insertRight(&morseBtree, 'u', nodeI); nodeU = nodeI->right;
	nodeA->left = insertLeft(&morseBtree, 'r', nodeA); nodeR = nodeA->left;
	nodeA->right = insertRight(&morseBtree, 'w', nodeA); nodeW = nodeA->right;
	nodeN->left = insertLeft(&morseBtree, 'd', nodeN); nodeD = nodeN->left;
	nodeN->right = insertRight(&morseBtree, 'k', nodeN); nodeK = nodeN->right;
	nodeM->left = insertLeft(&morseBtree, 'g', nodeM); nodeG = nodeM->left;
	nodeM->right = insertRight(&morseBtree, 'o', nodeM); nodeO = nodeM->right;
	
	nodeS->left = insertLeft(&morseBtree, 'h', nodeS); nodeH = nodeS->left;
	nodeS->right = insertRight(&morseBtree, 'v', nodeS); nodeV = nodeS->right;
	nodeU->left = insertLeft(&morseBtree, 'f', nodeU); nodeF = nodeU->left;
	nodeU->right = insertRight(&morseBtree, '\0', nodeU); nodeSpace = nodeU->right;
	nodeR->left = insertLeft(&morseBtree, 'l', nodeR); nodeL = nodeR->left;
	nodeR->right = insertRight(&morseBtree, '\0', nodeR); 
	nodeW->left = insertLeft(&morseBtree,'p', nodeW); nodeP = nodeW->left;
	nodeW->right = insertRight(&morseBtree, 'j', nodeW); nodeJ = nodeW->right;
	nodeD->left = insertLeft(&morseBtree, 'b', nodeD); nodeB = nodeD->left;
	nodeD->right = insertRight(&morseBtree, 'x', nodeD); nodeX = nodeD->right;
	nodeK->left = insertLeft(&morseBtree, 'c', nodeK); nodeC = nodeK->left;
	nodeK->right = insertRight(&morseBtree, 'y', nodeK); nodeY = nodeK->right;
	nodeG->left = insertLeft(&morseBtree, 'z', nodeG); nodeZ = nodeG->left;
	nodeG->right = insertRight(&morseBtree, 'q', nodeG); nodeQ = nodeG->right;
	nodeO->left = insertLeft(&morseBtree, '\0', nodeO);
	nodeO->right = insertRight(&morseBtree, '\0', nodeO);
	
	nodeH->left = insertLeft(&morseBtree, '5', nodeH);
	nodeH->right = insertRight(&morseBtree, '4', nodeH);
	nodeV->right = insertRight(&morseBtree, '3', nodeV);
	nodeSpace->right = insertRight(&morseBtree, '2', nodeSpace);
	nodeR->right->left = insertLeft(&morseBtree, ' ', nodeR->right);
	nodeJ->right = insertRight(&morseBtree, '1', nodeJ);
	nodeB->left = insertLeft(&morseBtree, '6', nodeB);
	nodeB->right = insertRight(&morseBtree, '=', nodeB);
	nodeX->left = insertLeft(&morseBtree, '/', nodeX);
	nodeZ->left = insertLeft(&morseBtree, '7', nodeZ);
	nodeO->left->left = insertLeft(&morseBtree, '8', nodeO->left);
	nodeO->right->left = insertLeft(&morseBtree, '9', nodeO->right);
	nodeO->right->right = insertRight(&morseBtree, '0', nodeO->right);
	
	return morseBtree;
}

void insertCodeMorse(BTree *tree)
{
	if((*tree).root != NULL)
	{
		insertCodeMorseRecursive(NULL, tree->root, '1');
	}
}

void insertCodeMorseRecursive(address parrent, address temp, char flag)
{
	if(temp != NULL)
	{
		if(flag == '1') // '1' means root 
		{
			strcpy(temp->codeOfMorse,"");
		}
		else
		{
			strcpy(temp->codeOfMorse,parrent->codeOfMorse);
			
			if(flag == 'l') // l means left child
			{
				strcat(temp->codeOfMorse, ".");
			}
			else if(flag == 'r')
			{
				strcat(temp->codeOfMorse, "-");
			}
		}
		
		insertCodeMorseRecursive(temp, temp->left, 'l');
		insertCodeMorseRecursive(temp, temp->right, 'r');
	}
}

void WordToMorse(BTree *tree, char *kalimat)
{
	if ((&tree) != NULL && kalimat != NULL)
	{
		wordToMorseRecursive((*tree).root, kalimat);
	}
}

void wordToMorseRecursive(address temp, char huruf)
{
	int flag = false;
	
	if(temp != NULL && huruf != NULL)
	{
		if(temp->data == huruf)
		{
			printf("%s ", temp->codeOfMorse);
			flag = true;
		}
		
		if(flag == false)
		{
			wordToMorseRecursive(temp->left, huruf);
			wordToMorseRecursive(temp->right, huruf);
		}
	}
}

void printWordtoMorse(BTree *tree, char *kalimat)
{
	int i = 0;
	char c;
	char *delimit;
	
	if((&tree) != NULL && kalimat != NULL)
	{
		delimit = strtok(kalimat, "\n"); //delimiter the input that contain space
		
		while (delimit != NULL)
		{
			printf("\"%s\"->", kalimat);
			delimit = strtok(NULL, " ");
		}
		
		for(i = 0; kalimat[i]; i++)
		{
			kalimat[i] = tolower(kalimat[i]);
		}
		
		for(i = 0; i < strlen(kalimat); i++)
		{
			c = *(kalimat + i);
			
			if(c == '\morseBtree')
			{
				printf(" [whitespace] ");
			}
			WordToMorse(tree, c);
		}
		
		printf("\n");
	}
}

void MorseToWord(BTree *tree, char *morse)
{
	if((&tree) != NULL && morse != NULL)
	{
		MorseToWordRecursive((*tree).root, morse);
	}
}

void MorseToWordRecursive(address temp, char *dotDash)
{
	int flag = false;
	char c;
	
	if(temp != NULL && dotDash != NULL)
	{
		if(strcmp(temp->codeOfMorse, dotDash) == 0)
		{
			c = temp->data;
			printf("%c", c);
			flag = true;
		}
		
		if(flag == false)
		{
			MorseToWordRecursive(temp->left, dotDash);
			MorseToWordRecursive(temp->right, dotDash);
		}
	}
}

void printMorseToWord(BTree *morseBtree, char *morse)
{
	char kalimat [1000] = "";
	char *c = NULL;
	
	if((&morseBtree) != NULL && morse != NULL)
	{
		strcpy(kalimat, morse); //copying the input into kalimat
		printf("%s -> ", kalimat);
		c = strtok(kalimat, " "); //delimiter the input that contain space
		
		while (c != NULL)
		{
			MorseToWord(morseBtree, c);
			c = strtok(NULL, " ");
		}
		printf("\n");
	}
}

void translateWordToMorseUserInput(BTree tree)
{
	char input[50];
	
	system("cls");
	printf("Please Insert For Less Than 50 Characters\n");
	printf("--------------------------------------------\n");
	printf("Word / Sentence : ");
	
	scanf(" %[^\n]s", &input);
	
	printWordtoMorse(&tree, input);
	
	backToMenu(tree);
}

void translateMorsetoWordUserInput(BTree tree)
{
	char input[50];
	
	system("cls");
	printf("Please Insert For Less Than 50 Characters\n");
	printf("--------------------------------------------\n");
	printf("Morse Code : ");
	
	scanf(" %[^\n]s", &input);
	
	printMorseToWord(&tree, input);
	
	backToMenu(tree);
}

FILE* open_file(char file_name[], char mode[]){
	FILE *fp = fopen(file_name, mode);
	
	if(fp == NULL){
		perror("File tidak dapat titemukan.\n");
		exit(EXIT_FAILURE);
	}
	
	return fp;
}

void read_text(FILE* fp){
	char ch[512];
	while((fgets(ch, 512, fp)) != NULL){
		printf("%s", ch);
	}
}

void translateWordToMorseFileInput(BTree tree)
{
	FILE *file;
//	char fileName[30];
	char fileMaterial[1000];
	
	system("cls");
	printf("--------------------------------");
	printf("\nlirik.txt after converting");
	printf("\n--------------------------------\n");
	
	file = open_file("lirik.txt", "r");
	read_text(file);
	fclose(file);
	
	printf("\n\n");
	
	file = open_file("lirik.txt", "r");
	while(fgets(fileMaterial, 1000, file) != NULL)
	{
		printWordtoMorse(&tree, fileMaterial);
	}
	fclose(file);
	
	backToMenu(tree);
}

void translateMorseToWordFileInput(BTree tree)
{
	FILE *file;
//	char fileName[30];
	char fileMaterial[1000];
	
	system("cls");
	printf("--------------------------------");
	printf("\nmorse.txt after converting");
	printf("\n--------------------------------\n");
	
	file = open_file("morse.txt", "r");
	read_text(file);
	fclose(file);
	
	printf("\n\n");
	
	file = open_file("morse.txt", "r");
	while(fgets(fileMaterial, 1000, file) != NULL)
	{
		printMorseToWord(&tree, fileMaterial);
	}
	fclose(file);
	
	backToMenu(tree);
}
