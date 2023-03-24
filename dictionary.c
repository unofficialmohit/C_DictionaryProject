#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<dos.h>
///declear function///
char add_word(char x[],char y[]);
void search_word(char line3[]);
char display();
char del();
///call function in main function///
int main()
{
    char word[100],mean[100],k[100];
    int n,f;
    while(1)
    {
    	  system("cls");
        printf("\n\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~|");
        printf("\n\t\t\t\t\t| WELCOME TO MY DICTIONARY |");
        printf("\n\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
        printf("\n\t\t\t\t============= : MAIN MENU : =============\n\n");
        
        printf("\n\t\t\t\t\t====== DICTIONARY ======\n");
        printf("\n\t\t\t\t1.Add word\n");
        printf("\n\t\t\t\t2.Search word\n");
        printf("\n\t\t\t\t3.Show dictionary\n");
        printf("\n\t\t\t\t4.Deletion\n");
        printf("\n\t\t\t\t5.Exit\n");
        printf("\n\tEnter choice:");
        scanf(" %d",&n);     ///input case number///
   switch(n)
          {
        case 1:
            add_word(word,mean);///add word and meaning///


            break;

        case 2:///search word with meaning///
            printf("enter search word:");
            scanf(" %s",&k);
            printf("you enter: %s\n",k);
           search_word(k);
             printf("\nRETURN MAIN MENU PRESS 00:");
               scanf("%d",&f);
              if(f==00)
              {
                system("cls");
               }
            break;
        case 3:
              display();  ///print word with meaning line by line///
                printf("\nRETURN MAIN MENU PRESS 00:");
               scanf("%d",&f);
              if(f==00)
              {
                system("cls");///clear consol screen///
               }
            break;
        case 4:
            del();//delete
                break;
        case 5:
        	exit(0);
        default :
            printf("Wrong choice 'BRO'.\n");
              printf("\nRETURN MAIN MENU PRESS 00:");
               scanf("%d",&f);
              if(f==00)
              {
                system("cls");///if wrong choice then clear screen///
               }

          }

    }
    return 0;
}
///add word in file///
char add_word(char x[],char y[])
{ 
char abc[100];int i,p=1;
    FILE *fp,*fp1;///declear file///
    char a[100],b[100];
 fp=fopen("addfile1.txt","a+");///open addfile1.txt with append mode///
 printf("Enter word & stop press ^Z: ");
 while(scanf("%s",a)!=EOF)
 {	
 for(i=0;i<strlen(a);i++)
 {
 if(!isalpha(a[i]))
 	{
 		p=0;
	 }
 }
 if(p==1){
 for(i=0;i<10;i++)
 {abc[i]=a[i];}
     if(abc[0]==0)
      exit(100);
     printf("Enter meaning:");
     scanf(" %s",b);
      fprintf(fp,"%s = %s\n",a,b);
      printf("Enter word & stop press ^Z:");
}
else
{	printf("\nNUMERIC VALUE AND SYMBOLS NOT ALLOWED\n");
	
	system("pause");
	
	main();
}
}



 fclose(fp);


}

///search word in file///
void search_word(char line3[])
{

  FILE *fp1=NULL;
  char line1[100];
  int flag=0;

  fp1=fopen("addfile1.txt","r+");///read addfile1.txt///
  if(fp1==NULL)
  {
    printf("File doesn't open successfully.\n");
  }

  while(!feof(fp1))
  {
    fgets(line1,99,fp1);///read line by line in file///
    //if(stricmp(line1,line3,strlen(line3))==0)
    if(strstr(line1,line3)!=NULL)
    {
      printf("found:%s\n",line1);
    flag=1;
    }

  }
  if(flag==0)
  printf(" Word not found\n");
  fclose(fp1);
}
//show dictionary in file//
char display()
{
FILE *fp2=NULL;
char line4[100],c;
fp2=fopen("addfile1.txt","r+"); //read again in file
if(fp2==NULL)
{
printf("File doesn't open successfully.\n");
}
printf("\n\t\t\t~~~~~~~ SHOW DICTIONARY ~~~~~~~\n");
c=getc(fp2);
while(c!=EOF)
{
printf("%c",c);
c=fgetc(fp2);
}
fclose(fp2);
}

char del()
{
  int len;
  char delete_line[2048];
  char buffer[2048];
  int flag=1;int flag1=0;
  FILE *file, *temp;
  while ((getchar()) != '\n');
  printf("Delete Line: "); 
  fgets(delete_line, 2048, stdin);
  len=strlen(delete_line)-1;
  file = fopen("addfile1.txt", "r");
  temp = fopen("addfile2.txt", "w");
  if (file == NULL || temp == NULL)
  {
    printf("Error opening file(s).\n");
  }  
  do 
  {

    fgets(buffer, 2048, file);                                   
    if (feof(file)) flag = 0;
    else if (strncmp(buffer,delete_line,len)!=0)
    {	
		 fputs(buffer, temp);
	}
	else if(strncmp(buffer,delete_line,len)==0)
     	{
     		flag1=1;
		}
  } while (flag);
if(flag1==0)
{
	printf("WORD NOT FOUND");
}
printf("\n\nPress any key to continue");

getch();
  // close our access to the files
  fclose(file);
  fclose(temp);

  // delete the original file, give the temp file the name of the original file
  remove("addfile1.txt");
  rename("addfile2.txt", "addfile1.txt");

  return 0;
}
