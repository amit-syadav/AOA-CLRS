#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next[20];

 /*calculate our next array
 */
void compute_prefix_function(char *pattern)
{
	int m = strlen(pattern);
	next[0]=0;
	int k = 0;
	int q;

	for(q = 1;q < m;q++)
	{
		while(k > 0 && (pattern[k] != pattern[q]) )
			k = next[k-1];
		if (pattern[k] == pattern[q])
			k++;
		next[q] = k;
	}
	printf("Prefix table is \n"); // displays wrong table but gives correct answer
	
	for(int i=1;i<m;i++)
	        printf("%d",next[i]);

}

void KMP_match(char *text,char *pattern)
{
	int n = strlen(text);
	int m = strlen(pattern);
	compute_prefix_function(pattern);
	int q = 0;
	int i;

	for(i = 0;i < n;i++)
	{
		while(q > 0 && (pattern[q] != text[i]) )
			q = next[q-1];
		if (pattern[q] == text[i])
			q++;
		if(q == m)
			printf("offset is %d\n", i+1-m);
	}
	
}


int main()
{
	char pat[30],text[30];

	
	printf("Enter text \n");
	scanf("%s",text);
	
	printf("Enter pattern \n");
	scanf("%s",pat);
	
	KMP_match(text,pat);
	
	system("Pause");
	return 0;
}
