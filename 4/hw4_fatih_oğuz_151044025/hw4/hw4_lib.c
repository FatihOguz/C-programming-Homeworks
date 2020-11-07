/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"




double integral(double f(double x), double xs, double xe, double delta)
{
	/* riemann teoreminde kısa kenar delta uzun kenar fonksiyonun 0 dan f(x) değerine ulaşan değeri ile çarptım */
	/* bu şekilde sınır değerleri arasında elde edilen tüm dikkdörtgenlerin toplamı altta kalan alan integral sonucunu verir.	*/
	double x,a,sum=0.0;
	for(x=xs; x < xe; x += delta)
	{
		a = f(x);
		sum = sum + (a * delta);
	}
	return(sum);
}


double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta)
{
	/* R(f,P) = toplam sembolü i=1 den m ye toplam sembolü j=1 den n ye f(xij,yij) * delta * delta Riemann toplamı */
	/*	(küçük kareler metodu)formülünü kullanarak  yaptım. */
	double i,j,sum=0,a;
	for(i=xs;i<=xe;i+=delta)
	{
		for(j=ys;j<=ye;j+=delta)
		{
			a = f(i,j) * delta * delta;
			sum += a;
		}
	}
	return(sum);
}


int derivatives(double f(double a), double x, double eps, double *d1, double *d2)
{
	if(eps == 0)
	{
		return (-1);		/* epsilon değeri 0 girildiğinde return -1 bölü 0 durumunu düzeltmek için */
	}
	else					/* diğer durumlarda return 1	*/
	{
		*d1 = (f(x + eps) - f(x - eps)) / (2 * eps);
		*d2 = (f(x + eps) -  (2 * f(x)) + f(x - eps) ) / (eps * eps); /* pdf te verilen formülü kullandım.	*/
		return (1);
	}

}


int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double *e1, double *e2)
{
	double z1,z2,fonk , b;

	fonk = derivatives(f,x,eps, &z1, &z2);
	*e1 = z1 - d1(b);		/* doğru fonksiyondan hatalı fonksiyonu çıkararak bulunan hata payını*/
	*e2 = z2 - d2(b) ;

	if(*e1 < 0 )			/* hata payı negatif çıkarsa bu sonucu pozitif döndürmek için	*/
	{
		*e1 *= -1;
	}
	if(*e2 < 0)
	{
		*e2 *= -1;
	}

	return(0);

	/* hocam siz gerçek fonksiyonu verip bizden sadece dericatives fonsiyonundaki hata payını bulabileceğimizi söylemişsiniz. */
	/* ben bunu öğrenmeden önce türevde hata payına çalıştım ve sizin verdiğiniz derivates fonksiyonunun hata payını aşağıda */
	/*	yazdığım formülle bulunduğunu öğrenmiştim bu yüzden hem sizin dediğinizi hemde öğrendiğim formülle yazdım.				*/
	/*	 	*e1 = -1 * d1 * eps * eps / 6;									*/
	/*		*e2 = -1 * d2 * eps * eps / 6 ;									*/
	
}

int find_roots(double f(double x), double *x1, double *x2, double *x3, double *x4)
{
	double root[4];		/* bulduğum kökleri tutmak için kullandığım array	*/
	double i;
	int j=0;

	for(j=0;j<4;j++)		/* 4 tane kök bulunup bulunmadığını  kontrol etmek için önce arrayin tüm elemanlarını -101 e atadım.	*/
	{
		root[j] = -101;
	}

	j = 0;						/* x1 kökünü arrayin 0. elamanına göndermek için j yi sıfırladım.	*/
	for(i=-100;i<100;i+=0.5)
	{
		if(f(i) == 0)			/* f(x) 0 a eşit olduğunda fonksiyon x eksenini keser ve böylelikle kök bulunur.	*/
		{						/* bu x değerini döngüde i ile tutup ilk kökü arayin 0. indisine atadım bir sonraki kök gelirse diye arrayin indisi j yi arttırdım . */ 
			root[j] = i;
			j++;
		}
	}

	*x1 = root[0];				/* arraydeki sıraya göre kökleri fonksiyon parametresindeki pointer x lere atadım.	*/
	*x2 = root[1];
	*x3 = root[2];
	*x4 = root[3];
	/* arrayi basta -101 ile doldurmustum. ve for da kökleri -100 ve  100 aralığında aramıstım yani eğer pointerlardan biri bile -101 ise demekki
	4 tane kökten az bu durumda return 0 4 kök varsa return 1 döndürdüm . */
	if(*x1 != -101 && *x2 != -101 && *x3 != -101 && *x4 != -101)		 
	{
		return (1);
	}
	else 
	{
		return(0);
	}
}

