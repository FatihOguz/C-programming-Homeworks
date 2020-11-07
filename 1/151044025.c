/***********************************FATÝH OÐUZ 151044025**********************************************************/
/**********************************CSE102 HOMEWORK #01************************************************************/

#include<stdio.h>											/*	printf, scanf definitions						*/
#include<math.h>											/*	pow, sqrt definitions							*/
#define PI 3.14												/*	conversion constant								*/

double circle_area(double radius);							/*	input - radius of circle ; output - area		*/
double calc_hypotenuse(int side1, int side2);			    /*	input - side1,side2  	 ; output - hypotenuse	*/
double calc_radius_of_smallest_circle(int side1,int side2); /*	input - side1,side2      ; output - radius 		*/
double calc_radius_of_largest_circle(int side1,int side2);	/*	input - side1,side2      ; output - radius 		*/
double calc_area_of_smallest_circle(int side1,int side2);	/*	input - side1,side2 	 ; output - area		*/
double calc_area_of_largest_circle(int side1,int side2);	/*	input - side1,side2      ; output - area		*/
double calc_area_of_smallest_square(int side1,int side2);	/*	input - side1,side2      ; output - area		*/
double calc_area_of_largest_square(int side1,int side2);	/*	input - side1,side2      ; output - area		*/
double calc_area_of_square (int side);						/*	input - side		     ; output - area		*/
void display_results(double largest_circle,
					double largest_square,
					double smallest_circle,
					double smallest_square);				/*	displays area functions	*/


int main(void)		
{
	double largest_circle,largest_square,smallest_circle,smallest_square;

	display_results( largest_circle, largest_square, smallest_circle, smallest_square);
	
}

double circle_area(double radius)
{
	/*	circle area calculation	*/
	double area;
	area = PI	*	(double)pow(radius,2);
	return (area);
	
}

double calc_hypotenuse(int side1, int side2)
{
	/*	hypotenuse calculation	*/
	double hypotenuse;

	hypotenuse = (double)pow(side1,2) + (double)pow(side2,2);
	hypotenuse = (double)sqrt(hypotenuse);
	return(hypotenuse);
}

double calc_radius_of_largest_circle(int side1,int side2)
{
	/*	the radius of the circle inside the rectangle is half the small edge.	*/
	
	double radius;
	if(side1 < side2)
	{
		radius = (double)side1;
	}
	else
	{
		radius = (double)side2;
	}
	radius /= 2;
	return(radius);
}

double calc_radius_of_smallest_circle(int side1,int side2)
{
	/*	radius of circle that surrounded rectangle is half the diagonal of rectangle.	*/
	
	double radius;
	
	radius = (double)pow(side1,2) + (double)pow(side2,2);
	radius = sqrt(radius);
	radius /= 2;
	return(radius);
	
}

double calc_area_of_smallest_circle(int side1,int side2)
{
	/*	area of smallest circle calculation	*/
	double area,radius;
	radius = calc_radius_of_smallest_circle( side1, side2);
	area = PI * pow(radius,2);
	return(area);	
}

double calc_area_of_largest_circle(int side1,int side2)
{
	/*	area of largest circle calculation	*/
	double area,radius;
	radius = calc_radius_of_largest_circle( side1, side2);
	area = PI * pow(radius,2);
	return(area);
}
double calc_area_of_smallest_square(int side1,int side2)
{
	/*	edge of square that surrounds rectangle is same as length large side of rectangle	*/ 
	double side,area;
	
	if(side1 > side2)
	{
		side = (double)side1;
	}
	else
	{
		side = (double)side2;
	}
	area = calc_area_of_square (side);
	return(area);
}
double calc_area_of_largest_square(int side1,int side2)
{
	/* edge of square that fits inside a rectangle is same as small edge of rectangle.		*/
	double side,area;
	if(side1 < side2)
	{
		side = (double)side1;
	}
	else
	{
		side = (double)side2;
	}
	area = calc_area_of_square (side);
	return(area);
}
double calc_area_of_square (int side)
{
	/*	area of square calculation	*/
	double area;
	area = pow(side,2);
	return(area);
}
void display_results(double largest_circle,double largest_square,double smallest_circle,double smallest_square)
{
	/*	displays functions on screen	*/
	int side1,side2;
	
	printf("Enter first side for rectangle>\n");
	scanf("%d",&side1);
	printf("Enter second side for rectangle>\n");
	scanf("%d",&side2);
	
	largest_circle = calc_area_of_largest_circle( side1, side2);
	largest_square = calc_area_of_largest_square(side1,side2);
	smallest_circle = calc_area_of_smallest_circle( side1, side2);
	smallest_square = calc_area_of_smallest_square(side1,side2);
	printf("The area of the largest circle that fits inside a rectangle:	        %.2f\n",largest_circle);
	printf("The area of the largest square that fits inside a rectangle:	        %.2f\n",largest_square);
	printf("The area of the smallest circle that surrounds the same rectangle:	%.2f\n",smallest_circle);
	printf("The area of the smallest square that surrounds the same rectangle:	%.2f\n",smallest_square);	
}


