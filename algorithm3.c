#include "algorithm3.h"
#include "set.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int minimum(int a,int b,int c){
	if(a<=b && a<=c) return a;
	if(b<=a && b<=c) return b;
	else return c;
}
int max(int a,int b){
	if(a>b){
		return a;
	}else return b;
}

int distanceLevenshtein(char *s1, char *s2) {
    unsigned int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int matrice[s2len+1][s1len+1];
    matrice[0][0] = 0;
    for (x = 1; x <= s2len; x++)
        matrice[x][0] = matrice[x-1][0] + 1;
    for (y = 1; y <= s1len; y++)
        matrice[0][y] = matrice[0][y-1] + 1;
    for (x = 1; x <= s2len; x++)
        for (y = 1; y <= s1len; y++){
        	if(s1[y-1]==s2[x-1]){
        		matrice[x][y]=minimum(matrice[x-1][y] + 1, matrice[x][y-1] + 1,matrice[x-1][y-1]);
			}else{
				matrice[x][y]=minimum(matrice[x-1][y] + 1, matrice[x][y-1] + 1,matrice[x-1][y-1]+1);
			}
		}

    return(matrice[s2len][s1len]);
}

int setPurge(char **tabSansDoub){
	hashNode *temp1,*temp2,*preced, *aSupprimer;
	int k=0;
	//temp2: variable auxilier pour parcourir les 5 case de hashTable
	//temp1: le node qui contient la chaine que on veut verifier
	//       s'il posséde des doublons.
	//preced et aSupprimer: deux node auxilieres pour supprime un doublon
	
	int dLivenshtein=0;
	int i=0,j=0;
	for(i=0;i<tailleTab;i++){
		if(hashTable[i]!=NULL){
			temp1=hashTable[i];
			while(temp1!=NULL){
				tabSansDoub[k]=(char *)malloc(100*sizeof(char));
				strcpy(tabSansDoub[k],temp1->str);
				k++;
				preced=temp1;
				for(j=i;j<i+6 && j<tailleTab;j++){
					//On parcours les 6 cases de la hashTable
					if(i==j){
						temp2=temp1->next;
					}else{
						temp2=hashTable[j];
					} 
					
					while(temp2!=NULL){
						//on parcour la liste dans la case j;
						//printf("		Le comparer avec %s",temp2->str);
						dLivenshtein=distanceLevenshtein(temp1->str,temp2->str);
						if(dLivenshtein<=(double)((double)max(strlen(temp1->str),strlen(temp2->str))/5)){
							
							aSupprimer=temp2;
							if(preced->next==NULL){
								
								hashTable[j]=temp2->next;
								free(aSupprimer);
								temp2=hashTable[j];
								
							}else{
								preced->next=temp2->next;
								free(aSupprimer);
								temp2=preced->next;
							}
							
						}else{
							preced=temp2;
							temp2=temp2->next;							
						}
					}	
				}
				temp1=temp1->next;
			}
		}
	}
	return k;
}
void afficherHashTable(void){
	int i=0,j=0;
	hashNode *temp;
	for(i=0;i<tailleTab;i++){
		temp=hashTable[i];
		if(temp!=NULL){
			while(temp!=NULL){
				
				temp=temp->next;
				j++;
			}
		}
	}
	printf("Le nombre des mots non doublons restants est: %d\n",j);
}
