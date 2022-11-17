#include <stdio.h>

#include <stdlib.h>

#define N 255



int main()

{

    int i,j,n;

    char cell[N][N];

    scanf("%d",&n);

    for(i=0;i<n;i++)

    {

        scanf("%s",cell[i]);

    }

    for(i=0;i<n;i++)

    {

        for(j=0;;j++)

        {

            if(cell[i][j]=='A')

                cell[i][j]='T';

            else if(cell[i][j]=='T')

                cell[i][j]='A';

            else if(cell[i][j]=='C')

                cell[i][j]='G';

            else if (cell[i][j]=='G')

                cell[i][j]='C';

            else if(cell[i][j]=='\0')

                break;



        }

    }



    for(i=0;i<n;i++)

    {

       printf("%s\n",cell[i]);

    }





    return 0;

}

