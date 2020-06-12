/* -------------------------------------------------------------------------------------
Program          	 :main.c
Deskripsi       	 :Merupakan main dari ADT Implementasi Morse Binary Tree Dinamis
Author  	   		 :
Versi / tanggal  	 :01/16 Mei 2020
Compiler  		 	 :Dev-C++ 5.11
--------------------------------------------------------------------------------------*/
#include <windows.h>

#include "binarytreedinamis.h"
#include "morse.h"

int main() {
	BTree morseBTree;
	
	morseBTree = createMorseBTree(morseBTree);
	insertCodeMorse(&morseBTree);
	
	menu(morseBTree);
	
	return 0;
}

void menu(BTree tree)
{
	setcolor(11);
	int userChoice;
	
	printf(" ______________________________________\n");
	printf("|                                      |\n");
	printf("|            Scout Translator          |\n");
	printf("|         ======================       |\n");
	printf("|  1. Translate To Morse (User Input)  |\n");
	printf("|  2. Translate To Word  (User Input)  |\n");
	printf("|  3. Translate To Morse (File Input)  |\n");
	printf("|  4. Translate To Word  (File Input)  |\n");
	printf("|--------------------------------------|\n");
	printf("|         Type (1 / 2/ 3 / 4)          |\n");
	printf("|______________________________________|\n");
	
	printf("\nEnter your choice : ");
	scanf("%d", &userChoice);
	
	switch (userChoice)
	{
		case 1 :
			setcolor(14);
			translateWordToMorseUserInput(tree);
			break;	
		case 2:
			setcolor(14);
			translateMorsetoWordUserInput(tree);
			break;
		case 3:
			setcolor(14);
			translateWordToMorseFileInput(tree);
			break;
		case 4:
			setcolor(14);
			translateMorseToWordFileInput(tree);
			break;
		default:
			menu(tree);
			break;
			
	}
}

void backToMenu(BTree tree)
{
	setcolor(11);
	printf("\n--------------------------------");
	printf("\nPress Enter To Back To Menu");
	printf("\n--------------------------------");
	getch();
	
	system("cls");
	menu(tree);
}

void setcolor(unsigned short color) { 
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
} // Merubah Warna Teks Pada C++ https://49012032sehatsempurna.wordpress.com/2012/04/06/merubah-warna-teks-pada-c/
