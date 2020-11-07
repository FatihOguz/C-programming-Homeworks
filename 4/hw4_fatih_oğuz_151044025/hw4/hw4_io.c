/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include <stdio.h>
#include "hw4_io.h"



int read_polynomial3(double *a0, double *a1, double *a2, double *a3)
{
	/* x^3 dereceden polinomun katsayılarını kullanıcıdan  aldım. */
	printf("\nSirasiyla x^3, x^2 , x, ve x^0  icin baskatsayi giriniz.\n");
	scanf("%lf %lf %lf %lf",&*a3, &*a2, &*a1, &*a0);
	return(0);

}


int read_polynomial4(double *a0, double *a1, double *a2, double *a3, double *a4)
{
	/* x^4 dereceden polinomun katsayılarını kullanıcıdan  aldım. */
	printf("\nSirasiyla x^4 x^3, x^2 , x, ve x^0  icin baskatsayi giriniz.\n");
	scanf("%lf %lf %lf %lf %lf",&*a4, &*a3, &*a2, &*a1, &*a0);
	return(0);
}


void write_polynomial3(double a0, double a1, double a2, double a3)
{
	read_polynomial3(&a0, &a1, &a2, &a3);
	/*	pol,nomun ilki 0 değilse printlensin	sıfırsa yazma */
	if(a3 != 0)
	{
			/* sayı 1 ise başkatsayı girme		*/
		if(a3 == 1.0)
		{
			printf("x^3 ");
		}
		else if(a3 == -1)
		{
			/* sayı -1 ise başkatsayısı girme */
			printf("-x^3 ");
		}
		else
		{	/* ifade 0,1 ve  -1 den farklı ise başkatsayı gir */
			printf(" %.1lfx^3 ",a3);
		}
	}


	if(a2 > 0)
	{
		if(a2 == 1.0)
		{ /* sayı 1 ise başkatsayı girme		*/
			printf("x^2 ");
		}
		else
		{ /* ifade 0,1 ve  -1 den farklı ise başkatsayı gir */
			printf(" + %.1lfx^2 ",a2);	
		}
		
	}


	else if(a2 < 0)
	{	/* sayı -1 ise başkatsayısı girme */
		if(a2 == -1.0)
		{
			printf("-x^2");
		}
		else
		{/* ifade 0,1 ve  -1 den farklı ise başkatsayı gir */
			printf(" %.1lfx^2 ",a2);
		}
		
	}

	if(a1 > 0)
	{
		if(a1 == 1.0)
		{	/* sayı 1 ise başkatsayı girme		*/
			printf("x ");
		}
		else
		{/* ifade 0,1 ve  -1 den farklı ise başkatsayı gir */
			printf(" + %.1lfx ",a1);
		}
		
	}

	else if(a1 < 0)
	{	/* sayı -1 ise başkatsayısı girme */
		if(a1 == -1.0)
		{
			printf("-x ");
		}
		else
		{/* ifade 0,1 ve  -1 den farklı ise başkatsayı gir */
			printf(" %.1lfx ",a1);
		}
		
	}
	/* 0 hariç tüm durumlarda işareti ile yazma */
	if(a0 > 0)
	{
		printf(" + %.1lf ",a0);
	}
	else if(a0 < 0)
	{
		printf(" %.1lf ",a0);
	}
	
}


void write_polynomial4(double a0, double a1, double a2, double a3, double a4)
{
	read_polynomial4(&a0, &a1, &a2, &a3, &a4);

	
	if(a4 != 0)/*	pol,nomun ilki 0 değilse printlensin	sıfırsa yazma */
	{
		if(a4 == 1.0)
		{	/* sayı 1 ise başkatsayı girme		*/
			printf("x^4 ");
		}
		else if(a4 == -1)
		{	/* sayı -1 ise başkatsayısı girme */
			printf("-x^4 ");
		}
		else
		{/* ifade 0,1 ve  -1 den farklı ise başkatsayı gir */
			printf(" %.1lfx^4 ",a4);
		}
		
	}


	if(a3 > 0)
	{
		if(a3 == 1.0)
		{	/* sayı 1 ise başkatsayı girme		*/
			printf("x^3 ");
		}
		else if(a3 == -1.0)
		{	/* sayı -1 ise başkatsayısı girme */
			printf("-x^3 ");
		}
		else
		{/* ifade 0,1 ve  -1 den farklı ise başkatsayı gir */
			printf(" + %.1lfx^3 ",a3);
		}
		
	}
	else if(a3 < 0)
	{	/* sayı -1 ise başkatsayısı girme */
		if(a3 == -1.0)
		{
			printf("-x^3 ");
		}
		else
		{/* ifade 0,1 ve  -1 den farklı ise başkatsayı gir */
			printf("%.1lfx^3 ",a3);
		}
		
	}
	
	if(a2 > 0)
	{	/* sayı 1 ise başkatsayı girme		*/
		if(a2 == 1.0)
		{
			printf("x^2 ");
		}
		else
		{/* ifade 0,1 ve  -1 den farklı ise başkatsayı gir */
			printf(" + %.1lfx^2 ",a2);	
		}
		
	}


	else if(a2 < 0)
	{	/* sayı -1 ise başkatsayısı girme */
		if(a2 == -1.0)
		{
			printf("-x^2");
		}
		else
		{/* ifade 0,1 ve  -1 den farklı ise başkatsayı gir */
			printf(" %.1lfx^2 ",a2);
		}
		
	}

	if(a1 > 0)
	{	/* sayı 1 ise başkatsayı girme		*/
		if(a1 == 1.0)
		{
			printf("x ");
		}
		else
		{/* ifade 0,1 ve  -1 den farklı ise başkatsayı gir */
			printf(" + %.1lfx ",a1);
		}
		
	}

	else if(a1 < 0)
	{	/* sayı -1 ise başkatsayısı girme */
		if(a1 == -1.0)
		{
			printf("-x ");
		}
		else
		{/* ifade 0,1 ve  -1 den farklı ise başkatsayı gir */
			printf(" %.1lfx ",a1);
		}
		
	}

	/* 0 hariç tüm durumlarda işareti ile yazma */
	if(a0 > 0)
	{
		printf(" + %.1lf ",a0);
	}
	else if(a0 < 0)
	{
		printf(" %.1lf ",a0);
	}
}