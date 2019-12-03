#include <stdio.h>
#include <string.h>
#define BOOK_SIZE 100
#define VALUE_SIZE 25


char names[BOOK_SIZE][VALUE_SIZE];
    
char numbers[BOOK_SIZE][VALUE_SIZE];

int main(){
    
    
    char userChoice[1];
    char *n;
    char *p;
    FILE *infile;

    infile = fopen("phonebook.txt", "a+");

    char line[VALUE_SIZE*2];
    int count = 0;
    while(1){
        
        if(fgets(line, VALUE_SIZE*2, infile) == NULL){
                break;
            }
        n = strtok(line, ":");
        p = strtok(NULL, ":");
        strtok(n, "\n");
        strtok(p, "\n");
        
        strcpy(names[count], n);
        strcpy(numbers[count], p);
        count++;
            
        }
    fclose(infile);
        
   
    
    
    
   while(1){ 
        printf("--- MENU ---\n1. Add new\n2. Update\n"
          "3. Lookup\n4. Delete\n5. List all\n6. Exit\n"
          "Enter a choice: ");
        scanf("%s", userChoice);
       
        if (strcmp(userChoice, "1") == 0){
        
             char userInput[VALUE_SIZE];
             char numberInput[VALUE_SIZE];
        
        
             printf("Please insert a name: ");
             scanf("%s", userInput);
        
             printf("Please enter a phone number: ");
             scanf("%s", numberInput);
             
             int status = 0;
             for (int i = 0; i < BOOK_SIZE; i++){
                 
                 if(strcmp(names[i], "") == 0){
                     
                        strcpy(names[i], userInput);
                        strcpy(numbers[i], numberInput);
                        printf("%s has been added, their number is %s\n", names[i], numbers[i]);
                        status = 1;
                        break;
                 }
                 
                if(status = 0){
                    
                        printf("Sorry, the phonebook is full\n");
               }
                 
                 
             }
             
         
              main();
        
     }
    
        if (strcmp(userChoice, "2") == 0){
            
             char userInput2[VALUE_SIZE];
             char numberInput2[VALUE_SIZE];
             
             
             for (int i = 0; i < BOOK_SIZE; i++){
                    
                    if (strcmp(names[i], userInput2) == 0){
                             printf("Please choose a name to update: ");
                             scanf("%s", userInput2);
                             printf("Please enter the new number for %s: ", userInput2);
                             scanf("%s", numberInput2);
                             strcpy(numbers[i], numberInput2);
                        
                             printf("Their number has been updated to %s\n", numbers[i]);
                             
                             main();
                        }
                        
                    else {
                        
                        continue;
                    }
                        
                        
             }
             
             
        
             
          
     }  
        if (strcmp(userChoice, "3") == 0){
             char userInput3[VALUE_SIZE];
             printf("Please enter the name of the person you're searching for: ");
             scanf("%s", userInput3);
https://moodle.plattsburgh.edu/mod/vpl/forms/edit.php?id=1227454&userid=184625#vpl_file0             
             for(int i = 0; i < BOOK_SIZE; i++){
                 
                 if(strcmp(names[i], userInput3) == 0){
                     
                     printf("%s's number is %s\n", names[i], numbers[i]);
                     main();
                 }
                 
                 
             }
             
             
             
            
        
      }  
        if (strcmp(userChoice, "4") == 0){
               char userInput4[VALUE_SIZE];
               
               printf("Please enter the name of the contact you wish to delete: ");
               scanf("%s", userInput4);
               
               for (int i = 0; i < BOOK_SIZE; i++){
                   if(strcmp(names[i], userInput4) == 0){
                       FILE *fp;
                       fp = fopen("phonebook.txt", "w");
                       strcpy(names[i], "");
                       strcpy(numbers[i], "");
                       fclose(fp);
                       
                   }
                   
               }
        
             main();
        
      }  
        if (strcmp(userChoice, "5") == 0){
        
             for(int i = 0; i < BOOK_SIZE; i++){
                 if(strcmp(names[i], "") != 0){
                 printf("%s, their number is %s\n", names[i], numbers[i]);
               }
             }
        
             continue;
        }
        
       
        if (strcmp(userChoice, "6") == 0){
        
                printf("Exiting program!\n");
                FILE *fp;
                fp = fopen("phonebook.txt", "w");
                for(int i = 0; i < BOOK_SIZE; i++){
                    if(strcmp(names[i], "") != 0){
                    fprintf(fp, "%s:%s\n", names[i], numbers[i]);
                    }
                    }
                    
                    fclose(fp);
                exit(0);
        
      }
    
   }
    
}