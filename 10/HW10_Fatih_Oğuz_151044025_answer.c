/************************************************ Fatih***OĞUZ***151044025*************************************************************************************/
#include <stdio.h>
#include <stdlib.h>		/* malloc fonksiyonu kullanmak için */
#include <time.h>		/* link list ve allocation metodu ile dosya yazarken zaman bulmak için kullandığım difftime */
#include <conio.h>		/* ve time fonksiyonlarını kullanabilmem için time.h ve conio.h kütüphanelerini kullandım.*/
#define SIZE 1000000		/* 500.000 - 750.000 - 1.000.000 arası sayıları size'a atarak kolay görünüm oluşturdum */
typedef struct node  	/* link list kullanırken pointer ile bağlama ve prime fonksiyonuna veri göndermede kullandığım değişkenlerin struct ı*/
{
	int val;
	struct node * next;
}node_t;

int read();
int prime_number(int number);
int dynamic(int *number);
int link_list(int number);
int main()
{
	read();	
	return (0);
}

int read()
{
	/* oluşturduğum 3 dosyanın pointerları */
	FILE * linkedList_p;
	FILE * dynamic_fp;
	FILE *fp;

	/* link list bağlamamda kullandığım değişkenler */
	node_t *head=NULL;
	node_t * new;
	
	int *nump;			/* allocate te kullandığım pointer */

	time_t start,end;	/* zaman fonksiyonları değişkenleri */

	int number,number2;
	char comma;

	int prime,i=0,prime_size;
	fp = fopen("data.txt","r");				/* data dosyası aç */
	/* data dan satır satır sayı çek ve bunları size sayısına koşulu kadarını al */
	while(fscanf(fp,"%d%c%d\n",&number,&comma,&number2)!=EOF && number<SIZE)		
	{
		/* i counterı ile öncelikle size sayısına kadar kaç tane prime sayı olduğunu buluyorum.*/
		/*printf("%d\n",number);*/
		if(number==2)
		{
			i++;
		}

		if(number%2!=0)
		{
			prime=prime_number(number);
			if(prime!=0)
			{
				i++;
			}
		}	
	}
	prime_size=i;		/* prime_size'a prime sayısını atadım. */ 
	fclose(fp);			/* dosyamı kapadım */

	nump=(int *)malloc(prime_size * sizeof(int));	/* prime_size kadar integer bir memory alanı allocate ettim */
	i=0;
	time(&start);										/* zamanı başlattım */
	fp = fopen("data.txt","r");							/* data dosyası açıldı*/
	dynamic_fp= fopen("output_prime_dynamic_array.txt","a");		/* output_prime_dynamic_array dosyası açıldı */
	fprintf(dynamic_fp, "***********************************************%d***(DYNAMIC***ARRAY)******************************************************************\n",SIZE);
	while(fscanf(fp,"%d%c%d\n",&number,&comma,&number2)!=EOF && number<SIZE)
	{

		/*printf("%d\n",number);*/
		if(number==2)
		{
			*nump=2;
			dynamic(nump);	/* asal sayı olan 2 allocate li yere atandı dosyaya yazmak için dynamic fonksiyona gönderildi */
			i++;			/* bir sonraki memory alanına gitmek için i arttırıldı */
		}

		if(number%2!=0)
		{
			prime=prime_number(number);
			if(prime!=0)
			{
				*(nump+i)=prime;				/* prime sayı allocate li yere atandı */
				*nump =	*(nump+i);
				/*printf("%d\n",*(nump) );*/
				dynamic((nump));				/* allocateli prime dosyaya yazılmak için dynamic fonksiyonuna gönderildi.*/
				i++;							/* bir sonraki memory alanına gitmek için i arttırıldı */
			}
		}
			
	}
	
	time(&end);						/* işlemler tamamlandı dosyaya yazma işlemi bitti ve son zaman belirlendi */
	printf("%.2lf  saniye dynamic metodu \n",difftime(end,start) );	/* zaman farkı terminale yazıldı */
	/* zaman farkı dosyaya yazıldı .*/
	fprintf(dynamic_fp, "1 - %d  arasında dynamic metodla %.2lf kadar saniye geçer.\n",SIZE,difftime(end,start));
	/* dosyalar kapatıldı */
	fclose(fp);
	fclose(dynamic_fp);
	free(nump);					/* free fonksiyonu ile allocate li memory free edildi */





	head =(node_t *) malloc(prime_size * sizeof(node_t));	/* link list için prime sayısı kadar memory allocate edildi (node_t tipinde) */
	i=0;
	time(&start);		/* zaman başlatıldı */
	/* data dan okunmak için output_prime_LinkedList dosyasına yazmak için dosyalar açıldı */
	fp = fopen("data.txt","r");
	linkedList_p= fopen("output_prime_LinkedList.txt","a");
	fprintf(linkedList_p, "******************************************%d****(LINK***LIST)*********************************************************************\n",SIZE);
	while(fscanf(fp,"%d%c%d\n",&number,&comma,&number2)!=EOF && number<SIZE)
	{

		/*printf("%d\n",number);*/
		if(number==2)
		{
			head->val=2;			/* node un val ıne prime atandı */
			new=head;
			link_list(head->val);	/* 	prime sayısı output_prime_LinkedList dosyasına yazılmak için link_list fonksiyonuna atandı. */
			new->next = head ;		/* new nodunun pointer la gösterdiği adrese head i atadım */
			head = new;				/* head e new atadım böylelikle head bir sonraki adresin değerlerine sahip oluyor. */
		}

		if(number%2!=0)				/* bu koşul ile aradan çift sayıları çıkarıp prime sayıları bulmasını kolaylaştırıyorum (hız farkı)  */
		{
			prime=prime_number(number);		
			if(prime!=0)				/* prime fonksiyonunda gelen return değeri 0 'sıfır' değilse prime sayıdır */
			{
				head->val=prime;				/* prime sayıyı nodun val değişkenine atıyorum */
				/*printf("%d\n",head->val );*/
				link_list(head->val);			/* atadığım prime sayıyı link_list fonksiyonunda dosyaya yazıyorum */
				new->next = head ;					/* bir sonraki nodu head değişkenine atayarak headi bir sonraki nodu göstermiş oluyor. */
				head = new;
			}
		}
			
	}
	
	time(&end);				/* zamanı bitirdim */
	printf("%.2lf  saniye linked metodu \n",difftime(end,start) );			/* terminale zaman farkını yazdırdım */
	/* dosyaya zaman farkını yazdırdım (son satıra) */
	fprintf(linkedList_p, "1 - %d arasinda linked list metoduyla  %.2lf kadar saniye geçer \n",SIZE,difftime(end,start));
	/* dosylarımı kapattım */
	fclose(fp);
	fclose(linkedList_p);
	/* link list için allocate edilen yeri free fonksiyonu ile free ledim */
	free(head);

	return (0);
}

int prime_number(int number)
{
	int i,counter=0;

	for(i=2;i<number/2;i++)		/* 2 sayısını asal olark kabul edip  sayının yarısına kadar her sayıya böldüm */
	{
		if(number%i==0)
		{
			counter++;		/* bir tane bile kendinden başka sayıya bölünğrse asal sayı değildir */
		}
	}

	if(counter==0)
	{
		if(number==1)
		{
			return (0);
		}
		return(number);				/* hiç bir sayıya bölünmemiş ise prime sayıdır */
	}
	else
	{
		return(0);
	}	
}

int dynamic(int * number)
{
	
	FILE * dynamic_fp;			
	dynamic_fp= fopen("output_prime_dynamic_array.txt","a");	/* dosya açtım */
	fprintf(dynamic_fp, "%d \n",*number);						/* dosyaya yazdım */
	fclose(dynamic_fp); 										/* dosyayı kapattım */
	return(0);
}
int link_list(int number)
{
	
	FILE * linkedList_p;
	linkedList_p= fopen("output_prime_LinkedList.txt","a");		/* dosya açtım */
	fprintf(linkedList_p, "%d \n",number);						/* dosyaya yazdım */
	fclose(linkedList_p);										/* dosyayı kapattım */
	return(0);
}


	

