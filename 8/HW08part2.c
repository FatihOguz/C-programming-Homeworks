/**************************************FATİH***OĞUZ***151044025***HW08part2*******************************************************************/
#include <stdio.h>
char *find_operations(int arr[],int expected_val,char operations[] ,size_t arr_len,int cursor,int current)
{
	int i,divider=1,olasi_durumlar;
	char arr_search[3]={'+','-','*'};
	int sum=0;
	int arr_deneme[arr_len];		

	for(i=0;i<(int)arr_len-1;++i)
	{
		/* divider bir operations arrayinin olası tüm durumlarını çıkarmak için ilk değişken sabit diğerlerini değiştirme metodu ile kombinasyonları */
		/* bulmama yarayacak. örneğin +++++,++++-,++++*,+++-+,+++-*,+++-- şekilinde durumları ortaya koyarken ilk 81 sayının başında + ilk 27 sayının 2. */
		/* elemanı + ilk 9 elemanın 3 elemanı + ilk 3 sayının 4 elemanı + ve ilk sayının son elemanı + olaca şekilde kombine eder.Bu şekilde tüm kombinas*/
		/* yonlar oluşmuş olacak. burada 3 üzeri operations arrayinin size ı kadar durum oluşur bu for da bu sayıyı bulup alttaki satırlarda bu ilk 81*/
		/* ilk 27 eleman durumunu kontrol edicem */

		divider = divider * 3;
		olasi_durumlar = divider;			 
	}
	
	for(i=0;i<(int)arr_len;++i)
	{
		/* denemeler sonucunda array deki işlemler sonucu sum değeri sıfırlanmadan başladığı için (recursive dan dolayı) kopya arr arrrayi oluştueup işleme sokuyorum .*/
		arr_deneme[i]=arr[i];		
	}

	for(i=0;i<(int)(arr_len-1);i++)
	{
		/* kaç sırada bir karakter değişme durumunu divider ı karakter sayısı olan 3 e bölerek for da düzeltiyorum */
		divider = divider / 3;
		operations[i] = arr_search[(cursor / divider) % 3] ;		/* tüm durumları operations arrayine atıp expected value ile karşılastırıyorum .*/
		
		if(operations[i]=='+')
		{

			sum=arr[i] + arr[i+1] ;
			arr[i+1]=sum;
			
		}
		else if(operations[i]=='-')
		{
			sum=arr[i] - arr[i+1] ;
			arr[i+1]=sum;
		}
		else if(operations[i]=='*')
		{
			sum=arr[i] * arr[i+1] ;
			arr[i+1]=sum;
		}

		if(cursor == olasi_durumlar)
		{
			i=arr_len;
		}
		
	}
	if(sum==expected_val)   /* sum değişkeni expected value ile eşit ise tahmin doğrudur */
	{
		return operations;
	}
/* cursor 3 üzeri arr_len kadar olabilir sonsuz döngü kontrolü ve tüm değerler çalıştırıldığında expected value bulunamıyorsa böyle bi düzen yok demektir .*/
	if(cursor == olasi_durumlar)			
	{
		for(i=0;i<arr_len-1;i++)
		{
			operations[i]=' ';
			printf("%c" ,operations[i] );
		}
		return operations;
	}
	return find_operations(arr_deneme,expected_val,operations,arr_len,cursor+1,current);
}

int main()
{
	int arr_len=6;
	int arr[]={210,12,6,10,32,8};
	int expected_val=44;
	char operations[]={' ',' ',' ',' ',' '} ;
	int cursor=0,current=0;
	find_operations(arr,expected_val,operations,arr_len,cursor,current);
	printf("%s\n",operations );

	return 0;
}