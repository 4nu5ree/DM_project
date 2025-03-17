#include<stdio.h>
#include<math.h>
#include<stdlib.h>
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
            case 1:printf("1.Disjoint set\nYow will need to enter two sets to check if they are disjoint sets\n");
                //inputting size of array
                   printf("specify the size of first set\n");
                   scanf("%d",&m);
                   printf("specify the size of second set\n");
                   scanf("%d",&n);
                //enter elements to the array
                   printf("enter %d elements to the FIRST set one by one or use space between them\n",m);
                   for(i=0;i<m;i++)
                   {
                    scanf(" %c",&a[i]);
                   }

                   printf("enter %d elements to the SECOND set one by one or use space between them\n",n);
                   for(i=0;i<n;i++)
                   {
                    scanf(" %c",&b[i]);
                   }

                   flag=0;
                   for(i=0;i<m;i++)
                   {
                    for(j=0;j<n;j++)
                    {
                        if(a[i]==b[j])
                        {
                            printf("these two sets are NOT disjoint");
                            flag=1;
                            goto out;
                        }
                    }
                   }
                   out:
                   if(flag==0)
                    printf("The two sets are DISJOINT\n");
                    break;

            case 2:printf("2.Power set\nyou will need to enter one set\n");
                   printf("specify the size of set\n");
                   scanf("%d",&m);
                   //enter elements to the array
                   printf("enter %d elements to the set one by one or use space in between them\n",m);
                   for(i=0;i<m;i++)
                   {
                    scanf(" %c",&a[i]);
                   }
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
                   break;
            case 3:printf("3.Complement of a set\n");
                   printf("You need a UNIVERSAl set\nEnter the size for the universal set\n");
                   //inputting size for universal set
                   scanf("%d",&u_size);
                   printf("Enter %d elements for the universal set\n",u_size);
                   //inputting elements to universal array
                   for(i=0;i<u_size;i++)
                   {
                    scanf(" %c",&U[i]);
                   }
                   //inputting size of set A
                   printf("Enter the number of elements in set A:\n");
                   scanf("%d", &m);
                   //inputting elements to set A
                   printf("Enter %d elements to set A\n",m);
                   for (i = 0; i < m; i++)
                    {
                        scanf(" %c", &a[i]);
                    }
                    //compliment
                    printf("Complement of A (A'):\n{ ");
                    for(i=0;i<u_size;i++)
                    {
                        int found=0;
                        for(j=0;j<m;j++)
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
                    break;
            case 4:printf("4.Cartesian product of sets\nYou will need two sets\n");
                   //inputting size of array
                   printf("specify the size of first set\n");
                   scanf("%d",&m);
                   printf("specify the size of second set\n");
                   scanf("%d",&n);
                //enter elements to the array
                   printf("enter %d elements to the FIRST set one by one or use space between them\n",m);
                   for(i=0;i<m;i++)
                   {
                    scanf(" %c",&a[i]);
                   }

                   printf("enter %d elements to the SECOND set one by one or use space between them\n",n);
                   for(i=0;i<n;i++)
                   {
                    scanf(" %c",&b[i]);
                   }
                   printf("Cartesian product\n");
                   printf("{ ");
                   for(i=0;i<m;i++)
                   {
                    for(j=0;j<n;j++)
                    {
                        printf("(%c,%c),",a[i],b[j]);
                    }
                   }
                   printf("\b }\n");
                   break;
            case 5:printf("Exiting......");
                    exit(0);
            default:printf("Invalid input try again the choices (1/2/3/4/5)\n");           
        }
    } while (ch!=5);    
}