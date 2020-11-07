/********************************************************************FATİH****OĞUZ*************************************************************************************************************************
**********************************************************************151044025****************************************************************************************************************************
*/

#include <stdio.h>																										/*	printf , scanf kütüphanesi																				*/									
int main()
{
	
	int num;
	int units ,tens,hundreds ,thousands, tens_of_thousands;
	int flag = 0;
	
	printf("Enter the number (23 - 98760)\n");
	scanf("%d",&num);
	
	
	while( flag == 0 )
	{
		if( num >= 23 && num <= 98760)																		/*   23 - 98760 arasındaki sayıların basamaklarını ayırmak için koşul	 */
		{
			flag = 1;																												/*	bir daha sayı almaması için flag = 1 yaptık													*/

				/* junk junk basamakları almasın diye her bir basamak grubunda grupta olmayan basamak değerleri 0'a eşitledik													*/
				/*	num değerini istenen aralıktan bir üs basamak değerine mod al. (kendi basamak degerine kadar olan kısım sıfırlandı)								*/
				/*	istenilen basamak değernden küçük olanları değerlerince çıkar (sayının sağındaki kısımda sıfırlandı)															*/
				/*	kendi değerine böl ve digit bul.																																																	*/
				
			units = num % 10;
			num = num - units;
			tens = num % 100;
			tens = tens / 10;
			hundreds = 0;																										
			thousands = 0;
			tens_of_thousands = 0;
			if(num >= 23 && num < 100)
			{
				hundreds = 0;		
				thousands = 0;
				tens_of_thousands = 0;
				
			}
			else if(num >= 100 && num < 1000)
			{
				hundreds = num % 1000;
				hundreds = hundreds - (tens * 10);
				hundreds = hundreds / 100 ;
				thousands = 0;
				tens_of_thousands = 0;
			}
			
			else if (num >=1000 && num < 10000)
			{
				hundreds = num % 1000;
				hundreds = hundreds - (tens * 10);
				hundreds = hundreds / 100 ;
				thousands = num % 10000 ;
				thousands = thousands - ((hundreds * 100) + (tens * 10));
				thousands = thousands / 1000;
				tens_of_thousands = 0;
			}
			
			else if(num >= 10000 )
			{
				hundreds = num % 1000;
				hundreds = hundreds - (tens * 10);
				hundreds = hundreds / 100 ;
				thousands = num % 10000 ;
				thousands = thousands -((hundreds * 100) + (tens * 10));
				thousands = thousands / 1000;
				tens_of_thousands = num - ( (tens * 10) + (hundreds * 100) + (thousands * 1000));
				tens_of_thousands = tens_of_thousands / 10000;
				
			}

			/*	Digitleri basma																*/
		
			printf("The fifth digit is %d\n",tens_of_thousands);
			printf("The fourth digit is %d\n",thousands);
			printf("The third digit is %d\n",hundreds);
			printf("The second digit is %d\n",tens);
			printf("The first digit is %d\n",units);
		}

			/* 23 - 98760 arasında olmayan sayı değeri ise bir daha sayı iste					*/
		else
		{
			printf("Enter the number (23 - 98760)\n");
			scanf("%d",&num);
		}
	}
	
	return(0);
	
}
