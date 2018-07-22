#include <stdio.h>
#include <stdlib.h>
#include"set.h"
#include "algorithm3.h"

int main(int argc, char *argv[]) {
	char nomFichier[]="Fichier100";//"listeF.txt";
	char **tabSansDoub;
	int i=0;
	int tailleTabSansDoub;
	tailleTab=sizeOfHashTable(nomFichier);
	hashTable=(hashNode**)malloc(tailleTab* sizeof(hashNode*));
	tabSansDoub=(char**)malloc(tailleTab*sizeof(char*));
	initHashTable();
	mappingToHashTable(nomFichier);
	//printf("*******Avant Elimination des doublons*******\n");
	tailleTabSansDoub=setPurge(tabSansDoub);
	//printf("*******Apres Elimination des doublons*******\n");
	//affichage de nombre d'elements non doublons
	afficherHashTable();
	//system("pause");
	return 0;
}
