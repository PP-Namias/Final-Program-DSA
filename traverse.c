#include <stdio.h>
#include <conio.h>
#define pf printf
#define sf scanf

void traverse();

int a[50][50], m, n;
main()
{
int i, j;
printf("\n ENTER NUMBER OF ROWS AND COLUMNS: ");
scanf("%d%d", &m, &n);

printf("\n INPUT ELEMENTS OF 2-D ARRAY:\n");
for(i=0; i<m; i++)
for(j=0; j<n; j++)
{
scanf("%d", &a[i][j]);
}

printf("\n\n 2-D ARRAY BEFORE TRAVERSING:\n\n");
for(i=0; i<m; i++)
{
for(j=0; j<n; j++)
printf("\t%d", a[i][j]);
printf("\n\n");
}

traverse();

printf("\n\n 2-D ARRAY AFTER TRAVERSING:\n\n");
for(i=0; i<m; i++)
{
for(j=0; j<n; j++)
printf("\t%d", a[i][j]);
printf("\n\n");
}
getch();
}



void traverse()
{

int i, j;

for(i=0; i<m; i++)
for(j=0; j<n; j++)
a[i][j] = a[i][j];
}
