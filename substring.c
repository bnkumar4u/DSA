main()
{
	printf("enter a string\n");

	char s[100], substring[100];
	gets(s);
	//printf("%s\n",s );
	printf("enter the substring to search\n");
	gets(substring);

	int l=strlen(s),i,j;
	int m=strlen(substring);

	for(i=0,j=0;i<l&&j<m;i++)
	{
		if(s[i]==substring[j])
		{
			j++;
		}
		else
		{
			j=0;
		}
			
	}

	if(j==m)
		printf("True\nthe substringis present in the string\n");
	else
		printf("false\n");
		


}