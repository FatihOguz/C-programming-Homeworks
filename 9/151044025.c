/*****************************************FATİH***OĞUZ***151044025***HW09*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
	char **Map;
	int Width;	
	int Height;	
	int Flower_X;
	int Flower_Y;
}Forest;
typedef struct 
{
	int Coord_X;
	int Coord_Y;
	int Water_Bottle_SIZE;		/* mililitre cinsinden su */
}Botanist;

void init_game(Forest *forest,Botanist *botanist)
{

	FILE *fp;
	char arr[10][12];
	int count=0,i,j;
	fp = fopen("init.csv","r");								/* dosya okuma */
	while(count<12)
	{
		if(count==0)										/* dosyadan okunan ilk satır water bottle size olacak */
		{
			fscanf(fp,"%d",&botanist->Water_Bottle_SIZE );
			printf("%d\n",botanist->Water_Bottle_SIZE );
		}
		else if(count==1)									/* dosyadan okunan ikinci satır width ve height olacak. */
		{
			fscanf(fp,"%d,%d",&forest->Width, &forest->Height);
			printf("%d  %d\n",forest->Width ,forest->Height);
			/* calloc fonksiyonu ile bilmediğimiz map arrayine dinamik yer açtım */
			forest->Map = (char**)calloc(forest->Width,sizeof(int*));
			for(i=0;i<forest->Height;i++)
			{
				forest->Map[i] = (char*)calloc(forest->Height,sizeof(int));
			}

		}
		/* map haritasını dosyadan aldım */
		else
		{
			for(i=0;i<12;i++)
			{
				fscanf(fp,"%c,",&arr[count-2][i]);
			}	
		}
		count++;
	}
	/* dosyadan aldığım bilgileri forest->Map e attım */
	for(i=0;i<10;i++)
		{
			for ( j = 2; j <12; ++j)
			{
				forest->Map[i][j-2] = arr[i][j];
				if(forest->Map[i][j-2] == 'B')
				{
					botanist->Coord_X=i;
					botanist->Coord_Y=j - 2;
						
				}
				else if(forest->Map[i][j-2] == 'F')
				{
					forest->Flower_X=i;
					forest->Flower_Y=j-2;
				}
			}		
		}

	fclose(fp);	
}

void print_map(Forest *forest)
{
	int i,j;
	/*  forest->Map teki bilgileri terminale printledim */
	printf("\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%c",forest->Map[i][j] );
		}
		printf("\n");
	}
	printf("\n");
}

void search(Forest *forest, Botanist *botanist)
{
	int adim;
	printf("Searching...\n");
	print_map(forest);
	adim = rand()%4;
	printf("\n");

	/* botanist koordinatları flower koordinatarına eşit ise buldu .*/
	if(botanist->Coord_X==forest->Flower_X && botanist->Coord_Y==forest->Flower_Y)
	{
		printf("I have found it on (%d,%d)!\n",botanist->Coord_X,botanist->Coord_Y);
	} 
	/*botanistin suyu sıfırlanırsa yardım ister */
	else if(botanist->Water_Bottle_SIZE == 0)
	{
		printf("Help!.. I am on (%d,%d)\n",botanist->Coord_X,botanist->Coord_Y);		
	}
	/* aşağı daha inemeyeceği için atama yapmadan fonksiyonu çağırır. */
	else if(adim== 0 && botanist->Coord_X==9)
	{
		search(forest,botanist);
	}

	/* Aşağı random dan 0 gelirse aşağı inme atamaları yapım ve suyu azalttım fonksiyon çağırdım */
	else if(adim==0 && forest->Map[botanist->Coord_X+1][botanist->Coord_Y]!='#')
	{
		if(botanist->Coord_X < 9)
		{
			botanist->Coord_X =botanist->Coord_X + 1;
			forest->Map[botanist->Coord_X - 1][botanist->Coord_Y] = ' ';
			forest->Map[botanist->Coord_X][botanist->Coord_Y]='B';
			botanist->Water_Bottle_SIZE = botanist->Water_Bottle_SIZE - 1;
		}
		search(forest,botanist);
	}
	/* SAĞA random dan 1 gelirse sağa gitme atamaları yapım ve suyu azalttım fonksiyon çağırdım */
	else if(adim==1 && forest->Map[botanist->Coord_X][botanist->Coord_Y+1]!='#')
	{

		if(botanist->Coord_Y < 9)
		{
			botanist->Coord_Y = botanist->Coord_Y+1;
			forest->Map[botanist->Coord_X][botanist->Coord_Y - 1] = ' ';
			forest->Map[botanist->Coord_X][botanist->Coord_Y]='B';
			botanist->Water_Bottle_SIZE = botanist->Water_Bottle_SIZE - 1;
		}
			search(forest,botanist);
	}
	/* YUKARI random dan 2 gelirse yukarı çıkma atamaları yapım ve suyu azalttım fonksiyon çağırdım */
	else if(adim==2 && forest->Map[botanist->Coord_X-1][botanist->Coord_Y]!='#')
	{
		
		
		if(botanist->Coord_X > 0)
		{
			botanist->Coord_X = botanist->Coord_X-1;
			forest->Map[botanist->Coord_X + 1][botanist->Coord_Y] = ' ';
			forest->Map[botanist->Coord_X][botanist->Coord_Y]='B';
			botanist->Water_Bottle_SIZE = botanist->Water_Bottle_SIZE - 1;
		}
		search(forest,botanist);
	}
	/*SOLA random dan 3 gelirse sola gitme atamaları yapım ve suyu azalttım fonksiyon çağırdım */
	else if(adim==3 && forest->Map[botanist->Coord_X][botanist->Coord_Y-1]!='#')
	{
		if(botanist->Coord_Y-1 > 0)
		{
			botanist->Coord_Y = botanist->Coord_Y-1;
			forest->Map[botanist->Coord_X][botanist->Coord_Y + 1] = ' ';
			forest->Map[botanist->Coord_X][botanist->Coord_Y]='B';
			botanist->Water_Bottle_SIZE = botanist->Water_Bottle_SIZE - 1;
		}
		search(forest,botanist);		
	}
	else
	{ /* haraket edeceği durumlar yoksa fonksiyonu çağırdım */
		search(forest,botanist);
	}
	
	
	
}

int main()
{
	Forest forest;
	Botanist botanist;

	init_game(&forest,&botanist);
	print_map(&forest);
	srand(time(NULL));
	search(&forest,&botanist);
free(forest.Map);
return(0);


}
