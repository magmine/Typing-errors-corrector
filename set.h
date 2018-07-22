//set.h
#ifndef H_HASHTABLE
#define H_HASHTABLE
typedef struct hashNode hashNode;
struct hashNode{
	char *str;
	hashNode *next;
};
//Le tableau de hashage
hashNode **hashTable;

int  tailleTab;

//Calcule le nombre des mots dans un fichier
int sizeOfHashTable(char *nomFichier);

//Initialize le tableau de hashage ave NULL
void initHashTable();

//Supprime le tableau de hashage;
void deleteHashTable();

//Calcule le hash code pour le mott;
int calculeHash(char *mot);

//Insére un mot dans le tableau de hashage;
void ajoutMot(char *mot);

//Enregistre les données d'un fichier dans un tableau de hashage;
void mappingToHashTable(char *nomFichier);


#endif
