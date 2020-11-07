/********************************151044025_FATİH_OĞUZ******************************************************************************/
#include <stdio.h>
typedef enum {
	January=31, February=59, March=90, April=120, May=151, June=181, Jully=212, August=243, September=273, October=304, November=334, December=365
}month;
typedef enum {
	Monday,Tuesday,Wednesday,Thursday, Friday, Saturday, Sunday
}day;
void new_date(day day1);
int main()
{
	char buff[50];
	int i, s_day, s_year, f_day, f_year, counter=0,  start_month,j, final_month, artik_s_year,artik,flag;
	month s_month,f_month,month1,h_start_month,h_final_month;
	day day1,d_day1;
	
	FILE *input_date_p;
	FILE *new_date_p;

	input_date_p=fopen("input_date.txt","w");	/* dosyaya yazılacak w */
	
	/*	 Başlangıç ve bitiş tarihini kullanıcıdan alma */
	printf("Lutfen baslangic tarihinin gününü giriniz.\n");
	scanf("%d",&s_day);
	printf("Lutfen baslangic tarihinin ayini sayi ile giriniz.\n");
	scanf("%d",&start_month);
	printf("Lutfen baslangic tarihinin yilini giriniz.\n");
	scanf("%d",&s_year);
	
	printf("Lutfen bitis tarihinin gününü giriniz.\n");
	scanf("%d",&f_day);
	printf("Lutfen bitis tarihinin ayini sayi ile giriniz.\n");
	scanf("%d",&final_month);
	printf("Lutfen bitis tarihinin yilini giriniz.\n");
	scanf("%d",&f_year);

	/* bitiş ve başlangıç tarihi arasında kaç gün var bulma  burada typedeften o ayın son gününün yılın kaçıncı günü olduğu bilgisini kullanark yararlandım .*/
	if(start_month==1 )
	{
		h_start_month=January;
	}
	if(start_month==2)
	{
		h_start_month=February;
	}
	if(start_month==3)
	{
		h_start_month=March;
	}
	if(start_month==4)
	{
		h_start_month=April;
	}
	if(start_month==5)
	{
		h_start_month=May;
	}
	if(start_month==6)
	{
		h_start_month=June;
	}
	if(start_month==7)
	{
		h_start_month=Jully;
	}
	if(start_month==8)
	{
		h_start_month=September;
	}
	if(start_month==9)
	{
		h_start_month=October;
	}
	if(start_month==10)
	{
		h_start_month=November;
	}
	if(start_month==11)
	{
		h_start_month=December;
	}
	if(start_month==12)
	{
		h_start_month=January;
	}
	if(final_month==1)
	{
		h_final_month=January;
	}
	if(final_month==2)
	{
		h_final_month=February;
	}
	if(final_month==3)
	{
		h_final_month=March;
	}
	if(final_month==4)
	{
		h_final_month=April;
	}
	if(final_month==5)
	{
		h_final_month=May;
	}
	if(final_month==6)
	{
		h_final_month=June;
	}
	if(final_month==7)
	{
		h_final_month=Jully;
	}
	if(final_month==8)
	{
		h_final_month=September;
	}
	if(final_month==9)
	{
		h_final_month=October;
	}
	if(final_month==10)
	{
		h_final_month=November;
	}
	{
		h_final_month=December;
	}
	if(final_month==11)
	{
		h_final_month=January;
	}
	if(final_month==12)
	{
		h_final_month=January;
	}
	/* tarihin hangi güne denk geldigini miladı refarans alarak buldum */
	artik=0; 
	for(i=1;i<=s_year;i++)
	{
		
			if(i % 4 == 0 )
			{

				if(i%100==0 && i%400!=0)
				{
					
						artik--;
				}
				artik++;
				if(i==s_year)
				{
					artik--;
				}
			}

			else if(i%400==0 && i%4000!=0)
			{
				
				artik++;
				if(i==s_year)
				{
					artik--;
				}
			}

	}


	/* her yıl ocak ayı bir gün sonraki gün ile başlar artıl yıldan bir sonraki yıla geçerken bu 2 gün olur */
	/* bundan dolayı ilk günü hesaplarken o yıl kaçıncı günde olduğu + her yıl 1 arttığı için yıl sayısı + artık*/
	/* yıl varsa onun eklenmesi bu durum milattan başladığı için o zamana kadar olan tüm artık yıl sayısı eklernir.*/
	/* 2000 artık yıldır. 01.01.2000 cumartesi 01.01.2001 pazartesi 2 gün artmış 01.01.2002 salı 1 gün arttı.*/
	/* 01.01.2003 çarşamba 01.01.2004 perşembe 01.01.2005 cumartesi yine bir atık yıldan sonraki yıla geçiş durumu ve 2 artmış */
	/* asağıda bu durumların kontrolü yapılarak milattan itibaren takvimin günleri belirlenmiştir .*/

	if(start_month==1)
	{
		day1=s_day + s_year + artik;
	}
	else if(start_month==2)
	{
		day1=s_day + 31 +s_year + artik;
	}
	else if(start_month==3)
	{
		day1=s_day + 59 +s_year + artik;
	}
	else if(start_month==4)
	{
		day1=s_day + 90 +s_year + artik;
	}
	else if(start_month==5)
	{
		day1=s_day + 120 +s_year + artik;
	}
	else if(start_month==6)
	{
		day1=s_day + 151 +s_year + artik;
	}
	else if(start_month==7)
	{
		day1=s_day + 181 +s_year + artik;
	}
	else if(start_month==8)
	{
		day1=s_day + 212 +s_year + artik;
	}
	else if(start_month==9)
	{
		day1=s_day + 243 +s_year + artik;
	}
	else if(start_month==10)
	{
		day1=s_day + 273 +s_year + artik;
	}
	else if(start_month==11)
	{
		day1=s_day + 304 +s_year + artik;
	}
	else if(start_month==12)
	{
		day1=s_day + 334 +s_year + artik;
	}

	day1 = day1 % 7;
	d_day1=day1 + 6;
	if(start_month>2 && s_year%4==0)
	{
		 d_day1++;   /* artık yılda 29 subat sonrasında 29 subat durumundan dolaryı eklenmesi gerekn artık gün meselesi için yazdım */
	}

		counter = ((f_year - s_year) * 365 )+ (f_day - s_day) + (h_final_month - h_start_month);
/*fprintf(input_date_p, "%d",counter );*/
	/* AY SONU BİTİŞ TARİHİ OLUNCA COUNTER ALIP BAŞINI GİDİYO */
	for(i=1;i<=counter;i++)
	{
		if(i>=2)
		{s_day++;}
		fprintf(input_date_p,"%d%c%d%c%d\n",s_day,'/',start_month,'/',s_year);
		
		if(start_month==1  || start_month==3  || start_month==5  || start_month==7  || start_month==8  || start_month==10  )
		{
			if(s_day==31)
			{
			/* bitiş tarihi ayın son günü ise döngüyü sonlandır bu işlem yapılmaz ise döngü bitiş tarihini geçicektir.bu işlem for yerine */
			/* while ile çok koşullu yapılabilirdi ama koşula az sayıda girerek programın hızını yüksek oranda tutmak istedim. */
				if(s_day==f_day && start_month==final_month && s_year==f_year)		
				{
					i=counter;																				
				}
				start_month++;
				s_day=0;
			}
		}
		if(start_month==4  || start_month==6  || start_month==9  || start_month==11)
		{
			if(s_day==30)
			{
				/* bitiş tarihi ayın son günü ise döngüyü sonlandır bu işlem yapılmaz ise döngü bitiş tarihini geçicektir.bu işlem for yerine */
			/* while ile çok koşullu yapılabilirdi ama koşula az sayıda girerek programın hızını yüksek oranda tutmak istedim. */
				if(s_day==f_day && start_month==final_month && s_year==f_year)
				{
					i=counter;
				}
				start_month++;
				s_day=0;
			}
		}
		if(start_month==2)	/* artık yılların kontrolü */
		{
			if(s_year%4==0)
			{
				if(s_day==29)
				{
				/* bitiş tarihi ayın son günü ise döngüyü sonlandır bu işlem yapılmaz ise döngü bitiş tarihini geçicektir.bu işlem for yerine */
			/* while ile çok koşullu yapılabilirdi ama koşula az sayıda girerek programın hızını yüksek oranda tutmak istedim. */
						if(s_day==f_day && start_month==final_month && s_year==f_year)
					{
						i=counter;
					}
					
					start_month++;
					s_day=0;
				}
			}

			else if(s_year%100==0 && s_year%400==0)
			{
				if(s_day==29)
				{
/* bitiş tarihi ayın son günü ise döngüyü sonlandır bu işlem yapılmaz ise döngü bitiş tarihini geçicektir.bu işlem for yerine */
			/* while ile çok koşullu yapılabilirdi ama koşula az sayıda girerek programın hızını yüksek oranda tutmak istedim. */
					if(s_day==f_day && start_month==final_month && s_year==f_year)
					{
						i=counter;
					}
					start_month++;
					s_day=0;
				}
			}

			else if(s_year%400==0 && s_year%4000!=0)
			{
				if(s_day==29)
				{
			/* bitiş tarihi ayın son günü ise döngüyü sonlandır bu işlem yapılmaz ise döngü bitiş tarihini geçicektir.bu işlem for yerine */
			/* while ile çok koşullu yapılabilirdi ama koşula az sayıda girerek programın hızını yüksek oranda tutmak istedim. */
					if(s_day==f_day && start_month==final_month && s_year==f_year)
					{
						i=counter;
					}
					start_month++;
					s_day=0;
				}
			}
			else 
			{
				if(s_day==28)
				{
				/* bitiş tarihi ayın son günü ise döngüyü sonlandır bu işlem yapılmaz ise döngü bitiş tarihini geçicektir.bu işlem for yerine */
			/* while ile çok koşullu yapılabilirdi ama koşula az sayıda girerek programın hızını yüksek oranda tutmak istedim. */
					if(s_day==f_day && start_month==final_month && s_year==f_year)
					{
						i=counter;
					}
					start_month++;
					s_day=0;
				}
			}	
		}
		
		if(start_month==12 && s_day==31)
		{
			/* bitiş tarihi ayın son günü ise döngüyü sonlandır bu işlem yapılmaz ise döngü bitiş tarihini geçicektir.bu işlem for yerine */
			/* while ile çok koşullu yapılabilirdi ama koşula az sayıda girerek programın hızını yüksek oranda tutmak istedim. */
				if(s_day==f_day && start_month==final_month && s_year==f_year)
				{
					i=counter;
				}
			s_year++;
			start_month=1;
			s_day=0;
		}
		if(day1!=6)
		{
			day1++;
		}
		else if(day1==6)
		{
			day1=0;
		}
		
		if(s_day == f_day && start_month==final_month  && s_year==f_year)		/* döngünün bitiminin bitiş tarihi olma konrolü */
		{
			i=counter;
		}

	}
	fclose(input_date_p); /* dosya kapat */

	new_date(d_day1); /* tarih ceviri fonksiyonu ve new_date dosyasına yazma */


}

	void new_date(day day1)
	{

		
		int s_day,s_year,start_month;

		FILE *new_date_p;
		FILE *input_date_p;

		input_date_p=fopen("input_date.txt","r"); /* okuma işlemi */
		new_date_p=fopen("new_date.txt","w");	  /* yazma işlemi */
		while(fscanf(input_date_p,"%d/%d/%d\n",&s_day,&start_month,&s_year)!=EOF)
		{
			day1 = day1 % 7 ;
			/* günleri yazı ile yazma */
			if(day1==1)
			{
				fprintf(new_date_p, "%s","Monday," );
			}
			else if(day1==2)
			{
				fprintf(new_date_p, "%s","Tuesday," );
			}
			else if(day1==3)
			{
				fprintf(new_date_p, "%s","Wednesday," );
			}
			else if(day1==4)
			{
				fprintf(new_date_p, "%s","Thursday," );
			}
			else if(day1==5)
			{
				fprintf(new_date_p, "%s","Friday," );
			}
			else if(day1==6)
			{
				fprintf(new_date_p, "%s","Saturday," );
			}
			else if(day1==0)
			{
				fprintf(new_date_p, "%s","Sunday," );
			}

			/* ayları yazı ile yazma */
			if(start_month==1)
			{
				fprintf(new_date_p, "%s","January," );
			}
			else if(start_month==2)
			{
				fprintf(new_date_p, "%s","February," );
			}
			else if(start_month==3)
			{
				fprintf(new_date_p, "%s","March," );
			}
			else if(start_month==4)
			{
				fprintf(new_date_p, "%s","April," );
			}
			else if(start_month==5)
			{
				fprintf(new_date_p, "%s","May," );
			}
			else if(start_month==6)
			{
				fprintf(new_date_p, "%s","June," );
			}else if(start_month==7)
			{
				fprintf(new_date_p, "%s","Jully," );
			}
			else if(start_month==8)
			{
				fprintf(new_date_p, "%s","August," );
			}
			else if(start_month==9)
			{
				fprintf(new_date_p, "%s","September," );
			}
			else if(start_month==10)
			{
				fprintf(new_date_p, "%s","October," );
			}else if(start_month==11)
			{
				fprintf(new_date_p, "%s","November," );
			}
			else if(start_month==12)
			{
				fprintf(new_date_p, "%s","December," );
			}
			/* new date dosyasına yeni tarih versiyonunu yazma */
			fprintf(new_date_p, "%d,%d\n",s_day,s_year);
			day1++;
		}

		fclose(input_date_p);
		fclose(new_date_p);
	}
