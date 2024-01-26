#include <stdio.h>

int main() {
    printf("Reformulateur ID_ALERT | auteur : Jun | 26/01/2024\nLe resultat sera enregistre dans le fichier resultat.txt\n");

    char filepath[150];
    FILE *file, *resultFile;

    printf("Mettez le fichier .txt\n");
    scanf("%s", filepath);
    fflush(stdin);

    //printf("%s\n", filepath);

    file = fopen(filepath, "r");
    resultFile = fopen("resultat.txt", "w");
    if(file==NULL){
        printf("Je ne peux pas ouvrir le fichier.");
        return 1;
    }
/*
 //montrer le contenu du fichier txt
    char ch;
    while((ch=fgetc(file))!=EOF){
        printf("%c", ch);
    }
*/


    char id[9];
    int count = 0;

    while(fscanf(file, "%8s", id) == 1){
        if(count%10==0 && count!=0){
            fprintf(resultFile, "\n");
        }
        if(count%10 !=0 && count!=0){
            fprintf(resultFile, ",");
        }
        fprintf(resultFile, "'%s'", id);
        count++;
    }

    fclose(file);
    fclose(resultFile);

    printf("Nombre de ID_ALERT : %d\n", count);

    printf("\nAppuyez la touche d'entree pour fermer ce logiciel.");
    getchar();
    return 0;
}
