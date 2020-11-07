/****************************************FATİH***OĞUZ***151044025*****HW08part1.c*************************************************************/
#include <stdio.h>
#include <string.h>			/* strcpy fonksiyonu kütüphanesi */
#include <stdlib.h>			/* rastgele sayı üretimi rand fonksiyonu için */
#include <time.h>			/* rastgele sayı üretimi rand fonksiyonu için */
typedef struct 
{
	char text[20];
	int data;
	char type;
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;
}block;

void print_board(block board[10][10])
{
	int i,j,n=0;

	while(n != 10)			/*board indislerini arttırarak arrayin elemanlarını dolduruyorum */
	{
		
		if(n==0)			/* 0. satırdaki elemanları for dngülerinde düzenli bir şekilde doldurulması ve hemen altında char karakteri elemanarın yazılması */
		{
			for(i=1;i<3;i++)
			{
				board[0][i-1].data=90+i;		
			}
			for(i=4;i<8;i++)
			{
				board[0][i-1].data=90+i;		
			}
			board[0][2].type='T';
			board[0][7].type='S';
			board[0][8].type='S';
			board[0][9].data=100;
			
		}	
		else if(n==1)			/* 1. satırdaki elemanları for dngülerinde düzenli bir şekilde doldurulması ve hemen altında char karakteri elemanarın yazılması */	
		{
			for(i=2;i<5;i++)
			{
				board[1][i].data=90-i;
			}
			for(i=6;i<8;i++)
			{
				board[1][i].data=90-i;
			}
			board[1][0].data=90;
			board[1][1].type='M';
			board[1][5].type='P';
			board[1][8].type='B';
			board[1][9].data=81;
		}
		else if(n==2)					/* 2. satırdaki elemanları for dngülerinde düzenli bir şekilde doldurulması ve hemen altında char karakteri elemanarın yazılması */
		{
			for(i=4;i<6;i++)
			{
				board[2][i-1].data=70+i;
			}
			for(i=7;i<9;i++)
			{
				board[2][i-1].data=70+i;
			}
			for(i=1;i<3;i++)
			{
				board[2][i-1].data=70+i;
			}
			for(i=10;i<11;i++)
			{
				board[2][i-1].data=70+i;
			}
			board[2][2].type='S';
			board[2][5].type='M';
			board[2][8].type='T';
		}
		else if(n==3)						/* 3. satırdaki elemanları for dngülerinde düzenli bir şekilde doldurulması ve hemen altında char karakteri elemanarın yazılması */
		{
			for(i=2;i<5;i++)
			{
				board[3][i].data=70-i;
			}
			for(i=5;i<8;i++)
			{
				board[3][i].data=70-i;
			}
			for(i=8;i<10;i++)
			{
				board[3][i].data=70-i;
			}
			board[3][0].data=70;
			board[3][1].type='M';
			board[3][4].type='B';
			board[3][7].type='S';
		}
		else if(n==4)						/* 4. satırdaki elemanları for dngülerinde düzenli bir şekilde doldurulması ve hemen altında char karakteri elemanarın yazılması */	
		{
			for(i=1;i<4;i++)
			{
				board[4][i-1].data=50+i;
			}
			for(i=5;i<7;i++)
			{
				board[4][i-1].data=50+i;
			}
			for(i=8;i<10;i++)
			{
				board[4][i-1].data=50+i;
			}
			board[4][3].type='T';
			board[4][6].type='M';
			board[4][9].type='S';
		}
		else if(n==5)							/* 5. satırdaki elemanları for dngülerinde düzenli bir şekilde doldurulması ve hemen altında char karakteri elemanarın yazılması */
		{
			for(i=3;i<5;i++)
			{
				board[5][i].data=50-i;
			}
			for(i=6;i<10;i++)
			{
				board[5][i].data=50-i;
			}
			board[5][0].type='B';
			board[5][1].data=49;
			board[5][2].type='P';
			board[5][5].type='S';

		}
		else if(n==6)							/* 6. satırdaki elemanları for dngülerinde düzenli bir şekilde doldurulması ve hemen altında char karakteri elemanarın yazılması */
		{	
			for(i=3;i<6;i++)
			{
				board[6][i-1].data=30+i;
			}
			for(i=7;i<10;i++)
			{
				board[6][i-1].data=30+i;
			}
			board[6][0].data=31;
			board[6][1].type='M';
			board[6][5].type='B';
			board[6][9].type='T';
		}
		else if(n==7)							/* 7. satırdaki elemanları for dngülerinde düzenli bir şekilde doldurulması ve hemen altında char karakteri elemanarın yazılması */
		{
			for(i=2;i<5;i++)
			{
				board[7][i].data=30-i;
			}
			for(i=6;i<10;i++)
			{
				board[7][i].data=30-i;
			}
			board[7][0].data=30;
			board[7][1].type='B';
			board[7][5].type='S';
		}
		else if(n==8)							/* 8. satırdaki elemanları for dngülerinde düzenli bir şekilde doldurulması ve hemen altında char karakteri elemanarın yazılması */	
		{
			for(i=1;i<4;i++)
			{
				board[8][i-1].data=10+i;
			}
			for(i=4;i<7;i++)
			{
				board[8][i-1].data=10+i;
			}
			for(i=8;i<11;i++)
			{
				board[8][i-1].data=10+i;
			}
			board[8][2].type='P';
			board[8][6].type='M';
		}
		else if(n==9)							/* 9. satırdaki elemanları for dngülerinde düzenli bir şekilde doldurulması ve hemen altında char karakteri elemanarın yazılması */	
		{
			for(i=0;i<3;i++)
			{
				board[9][i].data=10-i;
			}
			for(i=5;i<10;i++)
			{
				board[9][i].data=10-i;
			}
			board[9][3].type='M';
			board[9][4].type='S';
		}	
		n++;								/* arrayde satırları arttırmak için whiledaji n!=10 değerini arttırıyorum. */

	}
/* aşağıdaki for döngüsü ile çift katlı arrayin terminale yazılmasını char ve int değişkenleri ayrımlarını indislerin durumuna göre if koşulları ile ayırıyorum. */
	for(i=0;i<10;i++)			/* i değişkeni ile arrayin satırlarıı belirleyerek yazıyorum . */
	{
		for(j=0;j<10;j++)
		{
				if(i==0)
				{

					if(j==7)
					{
						printf("%s 	", strcpy(board[i][j].text,"S{72}"));
					}
					else if(j==8)
					{
						printf("%s 	", strcpy(board[i][j].text,"S{56}"));
					}
					else if(j==2)
					{
						printf("%c 	", board[i][j].type);
					}							 																				
					else if(j==9)
					{
						printf("%s 	", strcpy(board[i][j].text,"100(Finish)"));
					}																									
					else	/* arrayin o elemanında özel bir char karakteri yoksa printle */
					{
						printf("%d	",board[i][j].data);
					}																																																						

				}

				if(i==1)
				{
					if(j==1)
					{
						printf("%s 	", strcpy(board[i][j].text,"M{94}"));
					}
					else if(j==5)
					{
						printf("%c 	", board[i][j].type);
					}
					else if(j==8)
					{
						printf("%c 	",board[i][j].type);
					}
					else/* arrayin o elemanında özel bir char karakteri yoksa printle */
					{
						printf("%d	",board[i][j].data);
					}
				}

				if(i==2)
				{
					if(j==2)
					{
						printf("%s 	", strcpy(board[i][j].text,"S{68}"));
					}
					else if(j==5)
					{
						printf("%s 	", strcpy(board[i][j].text,"M{83}"));
					}
					else if(j==8)
					{
						printf("%c 	",board[i][j].type);
					}
					else/* arrayin o elemanında özel bir char karakteri yoksa printle */
					{
						printf("%d	",board[i][j].data);
					}
				}
				if(i==3)
				{
					if(j==1)
					{
						printf("%s 	", strcpy(board[i][j].text,"M{77}"));
					}
					else if(j==4)
					{
						printf("%c 	",board[i][j].type);
					}
					else if(j==7)
					{
						printf("%s 	", strcpy(board[i][j].text,"S{52}"));
					}
					else/* arrayin o elemanında özel bir char karakteri yoksa printle */
					{
						printf("%d	",board[i][j].data);
					}
				}

				if(i==4)
				{
					if(j==3)
					{
						printf("%c 	",board[i][j].type);
					}
					else if(j==6)
					{
						printf("%s 	", strcpy(board[i][j].text,"M{77}"));
					}
					else if(j==9)
					{
						printf("%s 	", strcpy(board[i][j].text,"S{44}"));
					}
					else/* arrayin o elemanında özel bir char karakteri yoksa printle */
					{
						printf("%d	",board[i][j].data);
					}
				}

				if(i==5)
				{
					if(j==0)
					{
						printf("%c 	",board[i][j].type);
					}
					else if(j==2)
					{
						printf("%c 	",board[i][j].type);
					}
					else if(j==5)
					{
						printf("%s 	", strcpy(board[i][j].text,"S{22}"));
					}
					else/* arrayin o elemanında özel bir char karakteri yoksa printle */
					{
						printf("%d	",board[i][j].data);
					}
				}
				if(i==6)
				{
					if(j==1)
					{
						printf("%s 	", strcpy(board[i][j].text,"M{52}"));
					}
					else if(j==5)
					{
						printf("%c 	",board[i][j].type);
					}
					else if(j==9)
					{
						printf("%c 	",board[i][j].type);
					}
					else/* arrayin o elemanında özel bir char karakteri yoksa printle */
					{
						printf("%d	",board[i][j].data);
					}
				}

				if(i==7)
				{
					if(j==1)
					{
						printf("%c 	",board[i][j].type);
					}
					else if(j==5)
					{
						printf("%s 	", strcpy(board[i][j].text,"S{12}"));
					}
				
					else/* arrayin o elemanında özel bir char karakteri yoksa printle */
					{
						printf("%d	",board[i][j].data);
					}
				}
				if(i==8)
				{
					if(j==2)
					{
						printf("%c 	",board[i][j].type);
					}
					else if(j==6)
					{
						printf("%s 	", strcpy(board[i][j].text,"M{28}"));
					}
				
					else/* arrayin o elemanında özel bir char karakteri yoksa printle */
					{
						printf("%d	",board[i][j].data);
					}
				}
				if(i==9)
				{
					if(j==3)
					{
						printf("%s 	", strcpy(board[i][j].text,"M{11}"));
					}
					else if(j==4)
					{
						printf("%s 	", strcpy(board[i][j].text,"S{1}"));
					}
					else if (j==9)
					{
						printf("%s 	", strcpy(board[i][j].text,"1(Start)"));
					}
				
					else/* arrayin o elemanında özel bir char karakteri yoksa printle */
					{
						printf("%d	",board[i][j].data);
					}
				}			
		}
		printf("\n");
	}

}
int move(block player)
{	int sonuc;
	int zar;
	
	/*printf("%d %d \n",player.pos_x,player.pos_y );*/
	
	sonuc=player.data;  /* counter tututmu ile player  fonksiyonlarında  kazanan kontrolü yapacağım */
	if(player.pos_x==0 && player.pos_y==9)	
	{	
		/* 2 player oynadığında ayrımı görmek için oyuncu ismini yazıyorum.*/
		printf("**************************************%s********************************************\n",player.text);
		return(sonuc);/* finish noktasında recursive durdurma kontrolu */
	}
	else	/*finish noktası değilse uygulanacak kurallar ve ilerleme durumuna göre yeni pos_x pos_y jump_x jump_y durumlarının atanması */
	{
		player.data++;											/* counter tutumu */
		zar = rand()%6+1;										/* rastgele zar atma */
		/*printf("cikan zar:%d\n",zar );*/
		if(player.pos_x%2==0)									/* sayıların artan sırasına göre haraket ettirmek için */
		{
			player.jump_y=player.pos_y+zar;
			player.jump_x=player.pos_x;
		}
		if(player.pos_x%2==1)									/* sayıların artan sırasına göre haraket ettirmek için */
		{
			player.jump_y=player.pos_y-zar;
			player.jump_x=player.pos_x;
		}

		
		if(player.jump_x==0)									/* oyuncu 100 'ü aşarsa onu zar atmadan önceki yerine gönderme */
		{
			if(player.jump_y>9)
			{
				player.jump_y=player.pos_y;
				player.pos_x=0;
				player.pos_y=player.pos_y-zar;
			}
		}

		if(player.jump_y<0)
		{
			player.jump_x--;									/* sol kanattan dışarı çıkarsa üst satıra taşıma */
			player.jump_y=0 - player.jump_y;
			player.jump_y=player.jump_y - 1;
			player.pos_x=player.jump_x;
			player.pos_y=player.jump_y;

		}


		if(player.jump_y>9)										/* sağ kanattan dışarı çıkarsa ;satır sonuna geldiğinde bir üst satıra geç */
		{
			player.jump_x--;
			player.jump_y=player.jump_y-10;						/* 0. İNDİSTEN DOLAYI -10 */
			player.jump_y=9 - player.jump_y;					/* S şeklinde çıkabilmesi için arrayin formal tamımı dışında */
			player.pos_x=player.jump_x;
			player.pos_y=player.jump_y;
		}
		/* T kuralı: 5 blok geri döner. çıkarma işlemi ve yeniden atama yapmak kodu karmaşıklastıracağı için o duruma göre yazmak daha hızlı çalıştıracaktır */
		if(player.jump_x==0 && player.jump_y==2)
		{
			/*printf("%d %d  T  ",player.jump_x,player.jump_y );*/				
			player.pos_x=1;
			player.pos_y=2;
			
		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==0 && player.jump_y==7)
		{
			/*printf("%d %d S{72}   ",player.jump_x,player.jump_y );*/
			player.jump_x=2;
			player.jump_y=1;

		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==0 && player.jump_y==8)
		{
			/*printf("%d %d S{56}   ",player.jump_x,player.jump_y );*/
			player.jump_x=4;
			player.jump_y=5;

		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==1 && player.jump_y==1)
		{
			/*printf("%d %d M{94}   ",player.jump_x,player.jump_y );*/
			player.jump_x=0;
			player.jump_y=3;

		}
		/* oyuncunun haraket etmeme durumu */
		if(player.jump_x==1 && player.jump_y==5)
		{
			/*printf("%d %d P   ",player.jump_x,player.jump_y );*/
			player.jump_x=player.jump_x;
			player.jump_y=player.jump_y;

		}
		/* T kuralı: 5 blok ilerler. çıkarma işlemi ve yeniden atama yapmak kodu karmaşıklastıracağı için o duruma göre yazmak daha hızlı çalıştıracaktır */
		if(player.jump_x==1 && player.jump_y==8)
		{
			/*printf("%d %d B  ",player.jump_x,player.jump_y );*/
			player.jump_x=1;
			player.jump_y=3;

		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==2 && player.jump_y==2)
		{
			/*printf("%d %d S{68}   ",player.jump_x,player.jump_y );*/
			player.jump_x=3;
			player.jump_y=2;

		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==2 && player.jump_y==5)
		{
			/*printf("%d %d M{83}   ",player.jump_x,player.jump_y );*/
			player.jump_x=1;
			player.jump_y=7;
		}
		/* T kuralı: 5 blok geri döner. çıkarma işlemi ve yeniden atama yapmak kodu karmaşıklastıracağı için o duruma göre yazmak daha hızlı çalıştıracaktır */
		if(player.jump_x==2 && player.jump_y==8)
		{
			/*printf("%d %d T   ",player.jump_x,player.jump_y );*/
			player.jump_x=3;
			player.jump_y=3;

		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==3 && player.jump_y==1)
		{
			/*printf("%d %d M{77}   ",player.jump_x,player.jump_y );*/
			player.jump_x=2;
			player.jump_y=6;
		}
		/* T kuralı: 5 blok ilerler. çıkarma işlemi ve yeniden atama yapmak kodu karmaşıklastıracağı için o duruma göre yazmak daha hızlı çalıştıracaktır */
		if(player.jump_x==3 && player.jump_y==4)
		{
			/*printf("%d %d B   ",player.jump_x,player.jump_y );*/
			player.jump_x=2;
			player.jump_y=9;
		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==3 && player.jump_y==7)
		{
			/*printf("%d %d S{52}   ",player.jump_x,player.jump_y );*/
			player.jump_x=4;
			player.jump_y=1;
		}
		/* T kuralı: 5 blok geri döner. çıkarma işlemi ve yeniden atama yapmak kodu karmaşıklastıracağı için o duruma göre yazmak daha hızlı çalıştıracaktır */
		if(player.jump_x==4 && player.jump_y==3)
		{
			/*printf("%d %d T   ",player.jump_x,player.jump_y );*/
			player.jump_x=5;
			player.jump_y=1;
		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==4 && player.jump_y==6)
		{
			/*printf("%d %d M{77}   ",player.jump_x,player.jump_y );*/
			player.jump_x=2;
			player.jump_y=6;
		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==4 && player.jump_y==9)
		{
			/*printf("%d %d S{44}   ",player.jump_x,player.jump_y );*/
			player.jump_x=5;
			player.jump_y=6;
		}
		/* T kuralı: 5 blok ilerler. çıkarma işlemi ve yeniden atama yapmak kodu karmaşıklastıracağı için o duruma göre yazmak daha hızlı çalıştıracaktır */
		if(player.jump_x==5 && player.jump_y==0)
		{
			/*printf("%d %d B   ",player.jump_x,player.jump_y );*/
			player.jump_x=4;
			player.jump_y=4;
		}
		/* oyuncunun haraket etmeme durumu */
		if(player.jump_x==5 && player.jump_y==2)
		{
			/*printf("%d %d P   ",player.jump_x,player.jump_y );*/
			player.jump_x=5;
			player.jump_y=2;
		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==5 && player.jump_y==5)
		{
			/*printf("%d %d S{22}   ",player.jump_x,player.jump_y );*/
			player.jump_x=7;
			player.jump_y=8;
		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==6 && player.jump_y==1)
		{
			/*printf("%d %d M{52}   ",player.jump_x,player.jump_y );*/
			player.jump_x=4;
			player.jump_y=1;
		}
		/* T kuralı: 5 blok ilerler. çıkarma işlemi ve yeniden atama yapmak kodu karmaşıklastıracağı için o duruma göre yazmak daha hızlı çalıştıracaktır */
		if(player.jump_x==6 && player.jump_y==5)
		{
			/*printf("%d %d B   ",player.jump_x,player.jump_y );*/
			player.jump_x=5;
			player.jump_y=9;
		}
		/* T kuralı: 5 blok geri döner. çıkarma işlemi ve yeniden atama yapmak kodu karmaşıklastıracağı için o duruma göre yazmak daha hızlı çalıştıracaktır */
		if(player.jump_x==6 && player.jump_y==9)
		{
			/*printf("%d %d T   ",player.jump_x,player.jump_y );*/
			player.jump_x=6;
			player.jump_y=4;
		}
		/* T kuralı: 5 blok ilerler. çıkarma işlemi ve yeniden atama yapmak kodu karmaşıklastıracağı için o duruma göre yazmak daha hızlı çalıştıracaktır */
		if(player.jump_x==7 && player.jump_y==1)
		{
			/*printf("%d %d B   ",player.jump_x,player.jump_y );*/
			player.jump_x=6;
			player.jump_y=3;
		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==7 && player.jump_y==5)
		{
			/*printf("%d %d S{12}   ",player.jump_x,player.jump_y );*/
			player.jump_x=8;
			player.jump_y=1;
		}
		/* oyuncunun haraket etmeme durumu */
		if(player.jump_x==8 && player.jump_y==2)
		{
			/*printf("%d %d P   ",player.jump_x,player.jump_y );*/
			player.jump_x=8;
			player.jump_y=2;
		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==8 && player.jump_y==6)
		{
			/*printf("%d %d M{28}   ",player.jump_x,player.jump_y );*/
			player.jump_x=7;
			player.jump_y=2;
		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==9 && player.jump_y==3)
		{
			/*printf("%d %d M{11}   ",player.jump_x,player.jump_y );*/
			player.jump_x=8;
			player.jump_y=0;
		}
		/* parantez içindeki sayının olduğu konuma götürme */
		if(player.jump_x==9 && player.jump_y==4)
		{
			/*printf("%d %d S{1}   ",player.jump_x,player.jump_y );*/
			player.jump_x=9;
			player.jump_y=9;
		}		
		else /* bir kural bloğuna takılmıyorsa */
		{
			player.pos_x=player.jump_x;
			player.pos_y=player.jump_y;
		}
		 sonuc=move(player);	/* çağırılan recursive fonkisyonuna yeniden sonuc counterını gönerebilmek için */
		
		printf("HAMLE:%d %d %d\n",player.data,player.jump_x,player.jump_y );
		player.pos_x=player.jump_x;
		player.pos_y=player.jump_y;
		return(sonuc);				/* çağırılan recursive fonkisyonuna yeniden sonuc counterını gönerebilmek için */		
		
	}

	

		
}

int one_player(block player1)
{	
		int hamle_sayisi; /*kaç hamlede bitirdiğini anlamak için fonksiyonun return degerinin atanacağı değişken */
	/* başlangıç koordinatları*/
		player1.pos_x=9;		
		player1.pos_y=9;
 /*	counter move da sıfırlarsam count tutamam bu yüzden struct taki bir int değişkeni sıfırlayarak orada sonuc değişkenini atama yaparak hamle sayısını bulcam */
		player1.data=0;

		strcpy(player1.text,"PLAYER1"); /* oyuncu adını bastırmak için structaki string i kullandım */
		srand(time(NULL));				/* move da bu fonksiyon olursa rastgele sayı üretimi hep aynı olurdu */
		hamle_sayisi=move(player1);


		printf("player %d sayisi hamlede oyunu bitirdi.\n",hamle_sayisi );
}

	int double_player(block player1,block player2)
	{
		/*kaç hamlede bitirdiğini anlamak için fonksiyonun return degerinin atanacağı değişken */
		int hamle_sayisi1;
		int hamle_sayisi2;
		/* başlangıç koordinatları ve counter sıfırlanması*/
		player1.pos_x=9;
		player1.pos_y=9;
		player1.data=0;

		player2.pos_x=9;
		player2.pos_y=9;
		player2.data=0;
		 /* oyuncu adını bastırmak için structaki string i kullandım */
		strcpy(player1.text,"PLAYER1");
		strcpy(player2.text,"PLAYER2");
		/* move da bu fonksiyon olursa rastgele sayı üretimi hep aynı olurdu */
		srand(time(NULL));
		
		hamle_sayisi1 = move(player1);
		hamle_sayisi2 = move(player2);
		printf("player1 %d sayisi hamlede oyunu bitirdi.\n",hamle_sayisi1);
		printf("player2 %d sayisi hamlede oyunu bitirdi.\n",hamle_sayisi2);
		/* kazanan bulma koşulları */
		if(hamle_sayisi1<hamle_sayisi2)
		{
			printf("Oyunu player 1 kazandi!..\n");
		}
		else if(hamle_sayisi2<hamle_sayisi1)
		{
			printf("Oyunu player 2 kazandi!..\n");
		}
		else
		{
			printf("Oyun berabere bitti!..\n");
		}
	}	



int main()
{
	
	block player1;
	block player2;
	block board[10][10];
	print_board(board);
	one_player(player1);
	double_player(player1,player2);
	return 0;
}
