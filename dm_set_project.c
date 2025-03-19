#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>

//function decalaration
void isdisjoint();
void power_set();
void complement_set();
void cartesian_product();
char *input_array(char str[] );
char *pop_dup(char str[]);


void main(){
    int m,n,ch,i,j,flag,u_size;
    char a[100],b[100],U[100];
    do
    {
        printf("-----MENU-----\n");
        printf("1.Disjoint set\n2.Power set\n3.Complement of a set\n4.Cartesian product of sets\n5.EXIT\n");
        printf("enter your choice (1/2/3/4/5)\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:isdisjoint();
                    break;
            case 2:power_set();
                    break;
            case 3:complement_set();
                    break;
            case 4:cartesian_product();
                    break;
            case 5:printf("Exiting......");
                    exit(0);
            default:printf("Invalid input try again the choices (1/2/3/4/5)\n");
        }
     }while (ch!=5); 
}

void isdisjoint(){

    int i,j;
    char a[100],b[100],m,n,flag=0;
    printf("1.Disjoint set\nYow will need to enter TWO sets to check if they are disjoint sets\n");
                
                //enter elements to the array
                    
                   printf("enter elements to the FIRST set one by one or use space between them (terminate press !)\n");
                   strcpy(a,input_array(a));

                   printf("enter elements to the SECOND set one by one or use space between them (terminate press !)\n");
                   strcpy(b,input_array(b));
                

                   flag=0;
                   for(i=0;i<strlen(a);i++)
                   {
                    for(j=0;j<strlen(b);j++)
                    {
                        if(a[i]==b[j])
                        {
                            printf("these two sets are NOT disjoint\n");
                            flag=1;
                            goto out;
                        }
                    }
                   }
                   out:
                   if(flag==0)
                    printf("The two sets are DISJOINT\n");
                    
}
void power_set(){

    int i,j;
    printf("2.Power set\nyou will need to enter one set\n");

                    char a[100];
                    
                   //enter elements to the array
                   printf("enter elements to the set one by one or use space in between them(terminate press !)\n");
                   strcpy(a,input_array(a));
                   
                   int m=strlen(a);
                   int power_set_size=pow(2,m);
                   printf("Power set :\n");
                   printf("{ ");
                   for(i=0;i<power_set_size;i++)
                   {
                    printf("{ ");
                    for(j=0;j<m;j++)
                    {
                        if(i&(1<<j))
                        {
                            printf("%c ",a[j]);
                        }
                    }
                    printf("}");
                   }
                   printf(" }\n");
}
void complement_set(){

    int i,j;
    char a[100],U[100];
    printf("3.Complement of a set\n");
                   printf("You need a UNIVERSAl set\nEnter elements for the universal set(terminate press !)\n");
                   strcpy(U,input_array(U));
                   
        
                   //inputting elements to set A
                   printf("Enter elements to set A\n(terminate press !)\n");
                   strcpy(a,input_array(a));

                   int u_size=strlen(U);
                   int a_size=strlen(a);
                    //compliment
                    printf("Complement of A (A'):\n{ ");
                    for(i=0;i<u_size;i++)
                    {
                        int found=0;
                        for(j=0;j<a_size;j++)
                        {
                            if(U[i]==a[j])
                            {
                                found=1;
                                break;
                            }
                        }
                        if(found==0)
                        {
                            printf("%c ",U[i]);
                        }
                    }
                    printf("}\n");
}
void cartesian_product(){

    int i,j;
    char a[100],b[100];
    printf("4.Cartesian product of sets\nYou will need two sets\n");
                   
                //inputting elements to the array
                   printf("enter elements to the FIRST set one by one or use space between them(terminate press !)\n");
                   strcpy(a,input_array(a));

                   printf("enter elements to the SECOND set one by one or use space between them(terminate press !)\n");
                   strcpy(b,input_array(b));

                   int a_size=strlen(a);
                   int b_size=strlen(b);

                   
                   printf("Cartesian product\n");
                   printf("{ ");
                   for(i=0;i<a_size;i++)
                   {
                    for(j=0;j<b_size;j++)
                    {
                        printf("(%c,%c),",a[i],b[j]);
                    }
                   }
                   printf("\b }\n");
}
char *input_array(char str[]){

    int i,j;
    char ch;
    i=0;
    
    do{
        scanf(" %c",&ch);
        if(ch=='!'){
            break;
        }
        else{
            str[i]=ch;
        }
        i++;
    }while(ch!='!');

    str[i] = '\0';
    
    return pop_dup(str);
}
char *pop_dup(char str[]){
    
    int len=strlen(str);
    for(int i=0;i<len;i++){

        for(int j=i+1;j<len;){
            if(str[i]==str[j]){
                for(int k=j;k<len;k++)
                    str[k]=str[k+1];
                len--;
            }
            else
                j++;
        }
    }
    str[len]='\0';
    printf("{ ");
    for(int i=0;i<len;i++){
        printf("%c ",str[i]);
    }
    printf("}\n");
    return str;
}
