//Fichier set.c: implementation des fonctions declarées
//en set.h
#include<stdio.h>
#include<stdlib.h>
#include "set.h"
#include<string.h>
int calculeHash(char *mot){
	int i=0;
	int sum=0;
	while(mot[i]!='\0' && mot[i]!='\n'){
		sum+= mot[i];
		i++;
	}
	return(sum%tailleTab);
}

void ajoutMot(char *mot){
	int hashCode=0;
	hashCode=calculeHash(mot);
	hashNode *nouveau=(hashNode*)malloc(sizeof(hashNode));
	nouveau->str=(char *)malloc(100*sizeof(char));
	if(nouveau==NULL|| nouveau->str==NULL) exit(0);
	strcpy(nouveau->str,mot);
	//On ajoute le nouveau element dans la tête de la liste chaine
	//situé dans la case hashTable[hashCode];
	nouveau->next=hashTable[hashCode];
	hashTable[hashCode]=nouveau;
}
void initHashTable(){
	int i=0;
	for(i=0;i<tailleTab;i++){
		hashTable[i]=NULL;
	}
}
int sizeOfHashTable(char *nomFichier){
	FILE *f;int i=0;
	f=fopen(nomFichier,"r");
	char c[100];
	if(f!=NULL){
		while(!feof(f)){
			fgets(c,100,f);
			i++;
		}
	}else{
		printf("Impossible d'ouvrir le fichier\n");
		exit(0);
	}
	fclose(f);
	printf("La taille de tableau de hashage: %d\n",i);
	return (i);
}
void mappingToHashTable(char *nomFichier){
	FILE *f;
	int i=0;
	char mot[100];
	f=fopen(nomFichier,"r");
	//Ajout des mots
	if(f!=NULL){
		while(i<tailleTab && !feof(f)){
			fgets(mot,100,f);
				ajoutMot(mot);
				i++;
			
		}	
	}else{
		printf("Impossible d'ouvrir le fichier\n");
		exit(0);
	}
	fclose(f);
}
