/************************Fatih***OĞUZ****151044025***********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void menu();
int getInt(int mini ,int maxi);
void horceRacingGame();
int numberGeneratorBetweenRange(int min, int max);
void triangleOfSequences();
void coutOccurence();
int main()
{
	menu();
}
void menu()
{
	int menu;
	do
	{
		printf("1.Horse Racing Game\n");
		printf("2.Occurence Counter\n");
		printf("3.Triangle of sequences\n");
		printf("0.Exit\n");

		printf("Enter a number for menu\n");
		scanf("%d",&menu);

		switch (menu)
		{
			/* srand:Rastgele sayı üretme fonksiyonu ( numberGeneratorBetweenRange fonksiyonu döngü dışı oldugundan */
			 /* hep aynı sayı veriyodu farklı sayı vermesi için buraya taşıdım) */
			srand(time(NULL));	
			case 1: 
			horceRacingGame();
			break;

			case 2: 
			coutOccurence();
			break;

			case 3: 
			triangleOfSequences();
			break;

			case 0: 
			printf("Exit\n");
			break;
		
			default :
			break;
		}
	}
	while(menu != 0);
}
int getInt(int mini ,int maxi)
{
	int number;
	int flag=0;

	while(flag == 0)
	{
		printf("Number of Horce:");
		scanf("%d",&number);
		/* maxi mini aralığında değer okumaya zorlama */
		if(number <= maxi && number >= mini)
		{
			flag=1;
		}
	}
		return(number);
}
int numberGeneratorBetweenRange(int min, int max)
{
	int num,i;

		num = rand()%(max - min + 1); /* max min aralığında değer üretmesi için mod alındı. */
		num = num + min;	
	return(num);	
}
void horceRacingGame()
{
	int numberHorce,speedest=21,num,speedCount,count=1,horceNumber,speedHorce;

	numberHorce = getInt(3,5);
	/* durumunu merak ettiğmiz (horceNumber) atın numarasının (numberHorce) yarışan at sayısı içerisinde olmasını sağlar */
	do
	{
		printf("Horce Number:");
		scanf("%d",&horceNumber);
	}
	while(!(horceNumber <= numberHorce && horceNumber > 0)); 

	printf("Racing starts...\n");
	do{
		num = numberGeneratorBetweenRange(10,20);	/* atların rastgele 10 ila 20 arasında hız yaptıran fonksiyon */
		/* aradığımız atın hızını speedHorce tutup ilerde ona göre durum analizi yapma (if / else if  )	*/
		if(count == horceNumber)
		{
			speedHorce = num;
		}
		printf("%d . Horce:%d \n",count,num);
		/* en hızlı atın numarasını ve hızını bulma	*/
		if(num < speedest)
		{
			speedest = num;
			speedCount = count;
		}
		
		count++;
	}
	while(count <= numberHorce);
	if(speedHorce == speedest)
	{
		printf("You win! \n\n");
	}
	else if(speedHorce > speedest)
	{
		printf("You lose!Winner is Horce %d. \n\n",speedCount);
	}	
}
void triangleOfSequences()
{
	int num,sum,j,i;

	num = numberGeneratorBetweenRange(2,10);	/* 2 - 1O arasında rastgele deger üreten fonksiyon */

	for(i=1 ;i<num;i++)
	{
		for(j=1; j <= i; j++)
		{	sum = sum+i;
			printf("%d ",sum);
		}
		
		printf("\n");
		sum = 0; /* ikinci satırda i değişkenine göre katlanması için sum = 0;	*/
	}
}
void coutOccurence()
{
	int search,searchNumber,bigNumber;
	int count=0,occurence = 0;

	printf("\nBig Number:");
	scanf("%d",&bigNumber);
	printf("\nSearch Number:");
	scanf("%d",&searchNumber);

	for(search = searchNumber;search > 1;search=search / 10)
		{
			count++; /* searchNumber ın basamak sayısını bulmak için 10 hangi üssü olması gerektiği bulundu */
		}
		

	while(bigNumber >= 1 && searchNumber <= bigNumber)
	{	
		/*searchNUmber ksımından çıkarıp oun basamak sayısınca modunu aldık aynı ise search = 0 olacaktır. */	
		search = bigNumber - searchNumber;	
		search = search % (int)pow(10,count);
		/* mod alma işleminde 1 ve 0 sayısınca modlar 0 olduğundan ayrı bir işlem yapmak gerekir */
		if(searchNumber == 1 || searchNumber == 0)
		{
	/* mod almak yerine bigNumber son basamağı sıfırlanır buradan son basamak searchNUmber ile aynı ise search sıfırlanmış olur. */
			search = bigNumber / 10 ;
			search = search * 10 ;
			search = bigNumber - search - searchNumber;		
		}
		
		if(search == 0)	
		{
			occurence++;
		}
		bigNumber = bigNumber /10; /* bigNumber son basamağı atılarak bir sonraki işleme hazır hale gelir */
	}
	printf("\nOccurence:%d \n",occurence);
}