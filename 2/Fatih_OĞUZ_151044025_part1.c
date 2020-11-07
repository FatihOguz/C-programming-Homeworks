/*
************************************************************FATİH****OĞUZ***********************************************************
***************************************************************151044025************************************************************
*/


#include <stdio.h>																							/*	printf-scanf fonksiyonları kütüphanesi																														*/ 
#include <stdlib.h>																							/*	srand fonksiyonu kütüphanesi																																			*/
#include <time.h>																								/* 	srand fonksiyonun zaman ile değişen rastgele sayı üretmesi için kütüphane													*/

char letter_grade(int grade);																		

int main()
{		
	char letter;																									

	int flag = 0;																									/*	student count'un 3-5 arası girdiği zaman döngüden çıkmak için flag																	*/
	int menu=1;																										
	int student_count;																						
	int count=1,																									
	count_a=0,count_b=0,count_c=0,count_d=0,count_f=0;					
	int successful_index ,unsuccessful_index,							
	most_successful_student=0, most_unsuccessful_student=100;				
	int grade;																										
                                  
	double sum = 0.0;																							
	
	
	while(flag != 1)
	{
		printf("Enter student count:");																
		scanf("%d",&student_count);																													/*	öğrenci sayısını alır																														*/
			
		if(student_count >=3 && student_count<=50)																					/*	öğrenci sayısı kontrolü yapılır																									*/
		{
			flag = 1;																																					/*	kontrol tutuyorsa flag = 1 yapılır ve öğrenci sayısı alma döngüsü tekrarlanmaz	*/
			srand(40);																																				/* 	rastgele not üretmek için fonksiyon																							*/
			
			
   				 while(count <= student_count)																								/*	öğrenci sayısınca rastgele sayı basma kontrolü																	*/
					{
					
                				grade=rand()%101;																								/*	0 - 100 arasında rastgele sayı bastırma																					*/
                	  	
                				if(most_successful_student < grade)
                				{
                					most_successful_student = grade;															/*	most_successful_student 'ın puanı ve indexini belirleme													*/
                					successful_index = count;
				        			 	}
				         	
					      			  if(most_unsuccessful_student > grade)														/*	most_unsuccessful_student 'ın puanı ve indexini belirleme												*/
					       				 {
						     			 	  most_unsuccessful_student = grade;
						      				 unsuccessful_index = count;
					       				 }
					       	 
					        			/*	rastgele üretilen puanların harf notunu belirleyip her harf notun count ile adetini belirleme																										*/
                				if(grade >= 90 && grade <= 100)
                				{
                           count_a++;
					              }
					              else if(grade >= 80 && grade <= 89)
					              {
						              count_b++;
					              }
					              else if(grade >= 70 && grade <= 79)
					              {
						              count_c++;
					              }
					              else if(grade >= 60 && grade <= 69)
					              {
						              count_d++;
					              }
					              else if(grade >= 0 && grade <= 59)
					              {
						              count_f++;
					              }

												
					              sum = sum + grade; 																				/*	avarage notunu belirlemek için her bir notun toplamını bulma													*/
								        printf("%d ",grade);   																		/*	puanları printle   																																		*/
                        count++;																									/*	count arttılıp while de student_countrolü yap																					*/
                 }
                
                	
        	}
			    
			
		
		else
		{
			printf("Not in Range!!!\n");																								/*	student_count 3 - 5 arasında değilse 																									*/
		}
		
		
	}
	
	/*	ekrana menüyü bastır																																																																										*/
		
	printf("\nStudent Score Calculator Menu for %d Student",student_count);
	printf("\n1)Most Successful Student\n");
	printf("2)Most Unsuccessful Student\n");
	printf("3)Letter Grade Statistics\n");
	printf("4)Calculate Avarage\n");
	printf("5)Show all Data\n");

	
	while(menu != -1)																															/*	menu seceneği olarak -1 girerse programı kapat																						*/
	{  
		scanf("%d",&menu);
		printf("\t\t\t\t\tMake Selection:%d\n",menu);
		
		
		
		switch(menu)
		{
			
			case -1:																																	/*	-1	girildiğinde false seletion demeden çıkması için break																*/
				break;
			case 1:
				letter=letter_grade(most_successful_student);
				printf("Most Successfully student:\nIndex:%d\nScore:%d\nLetter grade:%c\n",successful_index,most_successful_student,letter);
				
				break;
			case 2:
				letter=letter_grade(most_unsuccessful_student);
				printf("Most Unsuccessfully student:\nIndex:%d\nScore:%d\nLetter grade:%c\n",unsuccessful_index,most_unsuccessful_student,letter);
				break;
			case 3:
				printf("%d student got letter grade 'A'\n",count_a);
				printf("%d student got letter grade 'B'\n",count_b);
				printf("%d student got letter grade 'C'\n",count_c);
				printf("%d student got letter grade 'D'\n",count_d);
				printf("%d student got letter grade 'F'\n",count_f);
				
				break;
			case 4:
				printf("The avarage Score of %.d Student is %.2f\n",student_count,(sum / (double)student_count));
				break;
			case 5:
				letter=letter_grade(most_successful_student);
				printf("Most Successfully student:\nIndex:%d\nScore:%d\nLetter grade:%c\n",successful_index,most_successful_student,letter);
				letter=letter_grade(most_unsuccessful_student);
				printf("Most Unsuccessfully student:\nIndex:%d\nScore:%d\nLetter grade:%c\n",unsuccessful_index,most_unsuccessful_student,letter);
				printf("%d student got letter grade 'A'\n",count_a);
				printf("%d student got letter grade 'B'\n",count_b); 
				printf("%d student got letter grade 'C'\n",count_c);
				printf("%d student got letter grade 'D'\n",count_d);
				printf("%d student got letter grade 'F'\n",count_f);
				printf("The avarage Score of %d Student is %.2f\n",student_count,(sum / (double)student_count));
					break;
			default:
				printf("False selection!!!\n");
				break;
				
		}
	
		
		
	}
	
}

		/*	most_successful_student ve most_unsuccessful_student 'ın harf notunu belirlemek için fonksiyon																																				*/

char letter_grade(int grade)
{
	char letter;
	
					if(grade >= 90 && grade <= 100)
          {
         		letter = 'A';
					}
					else if(grade >= 80 && grade <= 89)
					{
						letter = 'B';
					}
					else if(grade >= 70 && grade <= 79)
					{
						letter = 'C';
					}
					else if(grade >= 60 && grade <= 69)
					{
						letter = 'D';
					}
					else if(grade >= 0 && grade <= 59)
					{
						letter = 'F';
					}
	
	return(letter);
}
