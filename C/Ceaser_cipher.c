#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
	char str[100];
    int i, k;
    printf("Enter your text : ");
    gets(str);

    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i] = str[i] - 32;
        }
    }

    printf("\nUppercase string : %s",str);
    printf("\nEnter key:");
    scanf("%d",&k);
    
	if (k>26)	k=k%26;
	
    
    	for(i=0; str[i]!='\0'; i++)
    	{
    	str[i]=str[i]+k;
    	if(str[i]>'Z')
    	{
    	str[i]=str[i]-26;	
		}
		
    	
    }
	
	printf("\nEncrypted string is : %s", str);

	for(i=0; str[i]!='\0'; i++)
    	{
    	str[i]=str[i]-k;
    	if(str[i]<'A')
    	{
    	str[i]=str[i]+26;	
		}
    }
    printf("\n Decrypted string is : %s" , str );
	
	
    return 0;   
}
