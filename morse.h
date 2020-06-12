/* --------------------------------------------------------------------------------------------------------
Program          	 :morse.h
Deskripsi       	 :Header dari body file (morse.c) pada ADT morse
Author  	   		 :
Referensi			 :https://phitchuria.wordpress.com/2018/04/04/algorithm-c-morse-code-binary-tree/
Versi / tanggal  	 :01/16 Mei 2020
Compiler  		 	 :Dev-C++ 5.11
-----------------------------------------------------------------------------------------------------------*/
#ifndef morse_H
#define morse_H

// Deskripsi        :Mendefinisikan Binary Tree baru untuk code morse menggunakan functions pada BTreeDinamis.h
// I.S		        :Binary tree morse belum terdefinisi
// F.S		        :Binary tree morse telah terdefinisi
BTree createMorseBTree(BTree morseBTree);

// Deskripsi        :Menambahkan code morse dari setiap alphabet,
// 					 dengan memanggil modul insertCodeMorseRecursive
// I.S		        :Code morse belum ditambahkan ke dalam Binary Tree 
// F.S		        :Code morse telah ditambahkan ke dalam Binary Tree 
void insertCodeMorse(BTree *tree);

// Deskripsi        :Procedure recursive untuk menambahkan code morse dari setiap alphabet
// I.S		        :Code morse pada Binary Tree belum terbentuk secara rekursif 
// I.S		        :Code morse pada Binary Tree telah terbentuk secara rekursif
void insertCodeMorseRecursive(address parent, address temp, char flag);

// Deskripsi        :
// I.S		        :
// F.S		        :
void WordToMorse(BTree *tree, char *kalimat);

// Deskripsi        :
// I.S		        :
// F.S		        :
void wordToMorseRecursive(address temp, char huruf);

// Deskripsi        :
// I.S		        :
// F.S		        :
void printWordtoMorse(BTree *tree, char *kalimat);

// Deskripsi        :
// I.S		        :
// F.S		        :
void MorseToWord(BTree *tree, char *morse);

// Deskripsi        :
// I.S		        :
// F.S		        :
void MorseToWordRecursive(address temp, char *dotDash);

// Deskripsi        :
// I.S		        :
// F.S		        :
void printMorseToWord(BTree *morseBTree, char *morse);

// Deskripsi        :
// I.S		        :
// F.S		        :
void translateWordToMorseUserInput(BTree tree);

// Deskripsi        :
// I.S		        :
// F.S		        :
void translateMorsetoWordUserInput(BTree tree);

// Deskripsi        :
// I.S		        :
// F.S		        :
FILE* open_file(char file_name[], char mode[]);

// Deskripsi        :
// I.S		        :
// F.S		        :
void read_text(FILE* fp);

// Deskripsi        :
// I.S		        :
// F.S		        :
void translateWordToMorseFileInput(BTree tree);

// Deskripsi        :
// I.S		        :
// F.S		        :
void translateMorseToWordFileInput(BTree tree);

#endif
