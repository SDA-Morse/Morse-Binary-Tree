/* -------------------------------------------------------------------------------------
Program          	 :binarytreedinamis.h
Deskripsi       	 :Header dari body file (binarytreedinamis.c) pada ADT binarytreedinamis
Author  	   		 :
Versi / tanggal  	 :01/16 Mei 2020
Compiler  		 	 :Dev-C++ 5.11
---------------------------------------------------------------------------------------*/
#ifndef binarytreedinamis_H
#define binarytreedinamis_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

typedef char datatype;
typedef struct node *address;//address adalah variabel untuk menampung alamat dari pointer node

typedef struct node
{
	datatype data;//data adalah variabel untuk menampung data alphabet
	char codeOfMorse[1024];//codeOfMorse adalah variabel untuk menampung kode morse
	address parent;
	address left;
	address right;
}nodeBTree;

typedef struct
{
	address root;
}BTree;

/*=============== Konstruktor ===============*/
// Deskripsi        :Mendefinisikan Binary Tree baru
// I.S		        :Binary tree belum terdefinisi
// F.S		        :Binary tree telah terdefinisi
void createTree(BTree *tree);

// Deskripsi        :Mengalokasikan node baru pada  Binary Tree
// I.S		        :Node pada Binary tree belum terdefinisi
// F.S		        :Node pada Binary tree telah terdefinisi
address createNode(datatype dat);

// Deskripsi        :Mendefinisikan root baru pada  Binary Tree
// I.S		        :Root pada Binary tree belum terdefinisi
// F.S		        :Root pada Binary tree telah terdefinisi
address insertRoot(BTree *tree, datatype dat);

// Deskripsi        :Mendefinisikan left child baru pada node Binary Tree
// I.S		        :Left child pada node Binary tree belum terdefinisi
// F.S		        :Left child pada node Binary tree telah terdefinisi
address insertLeft(BTree *tree, datatype dat, address parent);

// Deskripsi        :Mendefinisikan right child baru pada node Binary Tree
// I.S		        :Right child pada node Binary tree belum terdefinisi
// F.S		        :Right child pada node Binary tree telah terdefinisi
address insertRight(BTree *tree, datatype dat, address parent);

/*=============== Validasi ===============*/
// Deskripsi        :Memeriksa apakah Binary Tree kosong atau tidak, jika kosong maka akan mengembalikan nilai true
// Input            :Binary Tree
// Output           :Status Binary Tree
boolean isEmpty(BTree tree);

/*=============== Getter & Setter ===============*/
// Deskripsi        :Mengirimkan nilai left pada Binay Tree
// Input            :Binary Tree
// Output           :Nilai left dari node pada Binary Tree
address getLeft(address node);

// Deskripsi        :Mengirimkan nilai right pada Binay Tree
// Input            :Binary Tree
// Output           :Nilai right dari node pada Binary Tree
address getRight(address node);

/*=============== Destructor ===============*/
// Deskripsi        :Melakukan dealloc pada node yang telah didefinisikan sebelumnya
// I.S		        :Node pada Binary tree telah terdefinisi
// F.S		        :Node pada Binary tree belum terdefinisi
void deallocNode(address *newNode);

// Deskripsi        :Menghapus node pada Binary Tree
// I.S 	            :Binary Tree dengan keadaan sembarang
// F.S 	            :Node pada Binary Tree telah terhapus
void deleteNode(address *node);

// Deskripsi        :Menghapus seluruh node pada Binary Tree
// I.S 	            :Binary Tree dengan keadaan sembarang
// F.S 	            :Seluruh node pada Binary Tree telah terhapus
void deleteTree(BTree *tree);

/*=============== Transversal Tree ===============*/
// Deskripsi        :Melakukan transversal tree secara preorder
// I.S 	            :Node pada Binary Tree belum tertampilkan di layar secara preorder
// F.S 	            :Node pada Binary Tree terdefinisi dan telah tertampilkan di layar secara preorder
void preorder(address temp);

// Deskripsi        :Melakukan transversal tree secara inorder
// I.S 	            :Node pada Binary Tree belum tertampilkan di layar secara inorder
// F.S 	            :Node pada Binary Tree terdefinisi dan telah tertampilkan di layar secara inorder
void inorder(address temp);

// Deskripsi        :Melakukan transversal tree secara postorder
// I.S 	            :Node pada Binary Tree belum tertampilkan di layar secara postorder
// F.S 	            :Node pada Binary Tree terdefinisi dan telah tertampilkan di layar secara postorder
void postorder(address temp);

/*=============== Read and Write ===============*/

#endif
