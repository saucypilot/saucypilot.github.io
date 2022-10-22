#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void time_travel(char msg[100],int y,char fn[50],char ln[50],char t[50])
{
    char cmd[100];
    clock_t start;
    double c_t;
    int i=1;
    start=clock();
    while(i==1)
    {
        c_t=(double)(clock()-start)/CLOCKS_PER_SEC;
        if(c_t==y)
        {
            //printf("%d",c_t);
            printf("You've got a message from the past from %s %s\n",fn,ln);
            printf("%s",msg);
            i=0; 
            //sendmail(t);
            //system( "/usr/lib/sendmail -t < message.txt" );
            //system(mutt -s "Email subject" t < message.txt);
            //system ("mail -s test to < message.txt");
        }
    }
    printf("\n");
}

void userInput()
{
    char usersCapsule[100]={};
    char FName[50]={};
    char LName[50]={};
    char username[50]={};
    char email[50]={};
    char tf[100]={};
    int year;
    int curr_year=2022;
    strcpy(tf,"message.txt");
    printf("Enter Your First Name:");
    //scanf("%s",FName);
    fgets(username,50,stdin);
    printf("Enter your Last Name:");
    //scanf("%s",LName);
    fgets(username,50,stdin);
    printf("Enter your User Name:");
    //scanf("%s",username);
    fgets(username,50,stdin);
    //email not having permissions rn
    printf("Enter email:");
    fgets(email,50,stdin);
    printf("Write anything down for your capsule you want to see in the future.");
    printf("\n");     
    fgets(usersCapsule, 100, stdin);
    usersCapsule[strlen(usersCapsule) - 1] = '\0';
    FILE *fp = fopen(tf,"a"); 
    fprintf(fp,"%s\n",usersCapsule);        
    fclose(fp);   
    printf("When do you want to recieve the message: \n");
    scanf("%d",&year);
    printf("See you in %d years\n",year-curr_year);
    time_travel(usersCapsule,year-curr_year,FName,LName,email);
    
}

int main(int argc, char *argv[]) 
{
    printf("Good Evening, Welcome to the Digital TimeCapsule\n");
    userInput();
}