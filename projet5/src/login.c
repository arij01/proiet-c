#include "login.h"
#include <stdio.h>
#include <string.h>

int check_user(char inpt_login[], char inpt_mdp[],int n){

    int r = -1;
    FILE* f;
    char test_login[150]; char test_mdp[150];
    f=fopen("/home/amine/Projets/projet5/src/users.txt","r");
    if (f!=NULL) {
      /* code */
      while(fscanf(f,"%s %s\n", test_login,test_mdp)!=EOF){
          if ((strcmp(test_login,inpt_login)==0) && (strcmp(test_mdp, inpt_mdp)==0))
              r = 0;
      }
    fclose(f);
    }
    else{
      printf("Error: missing file users.txt");
    }

    return r;

}
