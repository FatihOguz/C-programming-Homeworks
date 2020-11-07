#include <stdio.h>

void encrypt_open_msg();
void decrypt_secret_msg();
int find_size_of_line(char line[]);
void reverse_line (char line[],int line_lenght);
void menu();
int main()
{
	
	menu();
}

void menu()
{/* karakter yada 1 ve 2 haricinde bir sayı girdiğinde menu döner 0 da çıkar. */
	char choice;
	do
	{
		printf("1. Encrypt\n2. Decrypt\n0. Exit\n");
		scanf("%c",&choice);
		switch(choice)
		{
			case '1':   encrypt_open_msg();    break; 
			case '2':   decrypt_secret_msg();   break;
		}

	} while (choice != '0');
	printf("\n\n");
}
void decrypt_secret_msg()
{
	int i=0,key,size;
	char buff[1024];

	FILE *fp_open;
	FILE *fp_secret;

	fp_open=fopen("open_msg","w");
	fp_secret=fopen("secret_msg","r");

	printf("key giriniz\n");
	scanf("%d",&key);
while(fgets(buff,1024,fp_secret)!=NULL)		/* buff tan satın satır cümleler çekilier	*/
	{
		printf("%s \n",buff );				
		size=find_size_of_line(buff);		/* array size bulma fonksiyonu */
		reverse_line(buff,size);			/* satırı ters çevirme işlemi.*/
		i=0;
	while(i<size)
	{
		 if(buff[i]!='*' && buff[i]!='_'  && buff[i]!='\n')
		{
			buff[i]=buff[i] + key;
			if(buff[i]>'z')
			{
				buff[i]=(buff[i] - 'z' - 1 + 'a');		/* nokta veya boşluk değilse key ile işleme sokar harf aralığnı gecerse harfler arası mod alınarak bir silndir gibi o aralığı döndürür . */
			}
		}
		else if( buff[i]=='\n')
		{
			buff[i]='\n';
		}

		else if(buff[i]=='_')						/* diğer durumlar için if koşulları ile atama işlemleri */
		{
			buff[i]=' ';
		}
		else if (buff[i]=='*')
		{
			buff[i]='.';
		}
		printf("%c",buff[i]);						/* o karakteri terminale yazar */
		i++;
		
	}
		printf("\n\n");
		if(size!=0)				/* çevirme işlemi yaparken ilk satırı boş bırakmaması için size 0 olmadığında \n ve \0 ları koysun */
		{
			buff[size]='\n';							/* satır sonundan önce bir \n karakteri ile alt satıra geçer . */
			buff[size+1] = '\0';
		}

													/* satır sonunu temsil eder. */
		fputs(buff,fp_open );						/* open_msg dosyasına şifreli mesajın yazılması */
	}
fclose(fp_open);
fclose(fp_secret);
}
void encrypt_open_msg()
{

	int i=0,key,size;
	char buff[1024];
	
	FILE *fp_open;
	FILE *fp_secret;

	fp_open=fopen("open_msg","r");
	fp_secret=fopen("secret_msg","w");

	printf("key giriniz\n");
	scanf("%d",&key);
	while(fgets(buff,1024,fp_open)!=NULL)										/* buff tan satın satır cümleler çekilier	*/
	{	
	printf("%s \n",buff );
	size=find_size_of_line(buff);												/* array size bulma fonksiyonu */
	reverse_line(buff,size);													/* satırı ters çevirme işlemi.*/
	i=0;
	while(i<size)
	{
		 if(buff[i]!=' ' && buff[i]!='.' && buff[i]!='\n')			/* nokta veya boşluk değilse key ile işleme sokar harf aralığnı gecerse harfler arası mod alınarak bir silndir gibi o aralığı döndürür . */
		{
			buff[i]=buff[i]-key;
			if(buff[i]<'a')
			{
				buff[i]='z' - ('a' - buff[i] - 1);
			}
		}
		else if(buff[i]=='\n')										/* diğer durumlar için if koşulları ile atama işlemleri */
		{
			buff[i]='\n';
		
		}
		else if(buff[i]==' ')
		{
			buff[i]='_';
		}
		else if (buff[i]=='.')
		{
			buff[i]='*';
		}
		printf("%c",buff[i]);									/* o karakteri terminale yazar */
		i++;
	}
	
	printf("\n\n");
	fputc(buff[size],fp_secret); 
	fputs(buff,fp_secret);	/* secret_msg dosyasına şifreli mesajın yazılması */
	}	
fclose(fp_open);
fclose(fp_secret);
}

int find_size_of_line(char line[])
{
	int i=0;
	while(line[i]!='\0')	/*char array içindeki eleman sayısı kadar return eder. */
	{
		i++;
	}
	return(i);
}
void reverse_line (char line[],int line_lenght)
{
	char temp;
	int i;
	/*int index1=0, index2,i=0,const_index2;
	while(i <= line_lenght)
	{
		if(line[i]==' '  || i==line_lenght - 1)
		{
			index2 = i;
			const_index2 = i;
			
		}
		while(index1 < index1 + ((index2 - index1) / 2))
		{
			temp = line[index1];
			line[index1] = line[index2-1];
			line[index2-1] = temp;
			index1++;
			index2--;

			if(index1 >= index1 + ((index2 - index1) / 2))
			{
				index1=const_index2+1;
				
			}
		}
		i++;
	}*/
	/*yukarıdaki kod kelime kelime ters çevirme algoritmasıdır. */
	/* ödevi pdfte öyle anlamıstım moodle sorularında satır satır olması gerektiğini görene kadar. */
	for(i=0;i<line_lenght/2;i++)
	{
		temp = line[i];
		line[i] = line[line_lenght -1 -i];
		line[line_lenght -1 -i] = temp;
	}
	for(i=0;i<line_lenght;i++)
	{
		printf("%c",line[i]);			/* tersine çevirilen array yazdırılır.	*/
	}
}
