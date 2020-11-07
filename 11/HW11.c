#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer_s  					/* customer için struct */
{
	char * surname;
	char   * name;
	int age;
	char * gender;
	struct customer_s * next;				/* birden fazla customer olursa birbirine bağlamak için pointer */
}customer_t;

typedef struct room_s						/* room için struct */
{
	int number;
	int capacity;
	int floor;
	
	struct room_s * next;						/* roomlar arası gezinmek için pointer */
	customer_t * next_customer ;				/* room un customer ile ilişkisini sağlamak için pointer */
}room_t;

struct room_s * add_room_to_end (struct room_s * room)
{
	struct room_s * room_add;
	room_add = (struct room_s * )malloc(sizeof(room_t));		/* eklenecek oda için yer ayırdım .													*/
	room_add->number = room->number;
	room_add->capacity = room->capacity;
	room_add->floor = room->floor;
	if(room->next == NULL)										/*	room listesinin son elemanının kontrolünün NULL karakteri ile  yapmış oluyorum. */
	{
		room->next = room_add;									/*	listedeki son elemanın ardına yeni elemanı bağladım.                             */
		room_add->next = NULL;									/* eklediğim elemanın son eleman olduğunu belirtmek için sonrasına NULL karakteri koydum. */
	}
	room = room_add;
	room->next = NULL;
	return(room);									
}


struct room_s * add_room_after_room_number (struct room_s * room, int number)
{
	
	struct room_s * temp;
	temp = (struct room_s * )malloc(sizeof(room_t));

	temp->number = number;									/* parametrdeki number allocate edilen temp node una attım listede var mıdiye kontrol etmek için */
	temp->next = NULL;
	while(room->next != NULL)								/* listenin sonuna kadar liste node larını gösterir */
		{
			if(temp->number == room->number)			/* parametrede gönderilen number listede varsa o node un hemen ardına node yerleştirilir */
			{
				printf("room number\n");
				scanf("%d",&temp->number);
				printf("room capacity->");
				scanf("%d",&temp->capacity);				/* eklenecek room un numarası capacitesi ve kat numarası kullanıcıdan alınır */
				printf("room floor->");
				scanf("%d",&temp->floor);					
				printf("%d %d %d \n", temp->number,temp->capacity,temp->floor);
				temp->next = room->next;
				room->next = temp;
				return(room);
			}
			room=room->next;
		}
		if(temp->next == NULL)			/* son node a kadar number a ulaşılamaz ise temp->next NULL olaraak kalır */
		{

			printf("room number\n");
			scanf("%d",&temp->number);

			printf("room capacity->");
			scanf("%d",&temp->capacity);			/* listenin sonuna kadar number a ulaşılamaz ise kullanıcıdan oda özellikleri alınır */

			printf("room floor->");
			scanf("%d",&temp->floor);

			room ->next = temp;						/* son node un devamına temp atanır */		
		}
		return(room);
}
customer_t * add_customer_to_end (customer_t * customer,int age,char name[],char surname[],char gender[])
{

	customer_t * add_customer;
	if(customer == NULL)        /* hiç müşteri eklenmemiş ise daha önce  customer NULLdır */ 
	{
		customer = (customer_t *)malloc(sizeof(customer_t));					/* mainde gönderilen parametreler için yer ayrılır ve bunlar costumer node nun değişkenlerine atanır */
		customer->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
		customer->surname = (char *)malloc(sizeof(char) * (strlen(surname) + 1));
		customer->gender = (char *)malloc(sizeof(char) * (strlen(gender) + 1));
		customer->age = age;
		strcpy(customer->name,name);
		strcpy(customer->surname,surname);
		strcpy(customer->gender,gender);
		customer->next = NULL;					/* bir sonraki yere null atanarak liste sonu kontrolu yapılır */
		printf("%s %s %d,%s\n",customer->name,customer->surname,customer->age,customer->gender );
		return customer;		/* baş node döndürülür */

	}
	add_customer = customer;		/* baş node add_customer atadım kaybolmasın diye */
	
	while(customer->next != NULL)			/* listenin sonuna doğru döngü gecer */
	{
		customer=customer->next;
	}/* listenin sonuna geldiğinde parametrelerden gelen bilgiler allocate edilen node un değişkenlerine atanır */
	customer->next = (customer_t *)malloc(sizeof(customer_t));
	customer->age = age;
	customer->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
		customer->surname = (char *)malloc(sizeof(char) * (strlen(surname) + 1));
		customer->gender = (char *)malloc(sizeof(char) * (strlen(gender) + 1));
		strcpy(customer->name,name);
		strcpy(customer->surname,surname);
		strcpy(customer->gender,gender);
		customer->next = NULL;  /* liste sonu kontrolü NULL ile saglanır */
		printf("%s %s %d,%s\n",customer->name,customer->surname,customer->age,customer->gender );
		return add_customer;			/* baş node return edilir */
}

struct room_s * link_customers_to_room (int number, struct room_s * room, customer_t *  customer)
{
	while(room->next != NULL) 					/* listenin sonuna kadar ilerle (room ana liste) */
	{
		if(number == room->number)  			/* parametredeki numara ile room odası aynı ise */
		{
			room->next_customer = customer;		/* room_t struct ında bulunan customer pointeri ile customer listesine bağlan */
		}
		room=room->next;
	}
	return(room);
}

struct room_s * remove_room (int number, struct room_s * room)
{
	struct room_s * temp;
	temp = (struct room_s *)malloc(sizeof(room_t)); 	/* temp için allocate ettim */
	if(number == room->number)							/* listin ilk elemanı ise */
	{
		temp = room;									/* head i kaybetmemliyiz */
		room = room->next;								/* ilk elemanı atladım */ 
		free(temp);										/* ilk elemanı free ledim */
		return (room);									/* baş node return edildi */
	} 
	while(room->next != NULL)				/* listenin arasında bir yerde ise */
	{
		if(number == room->next->number)		/* parametredeki number room un bir sonraki room numberına eşit ise */
		{
			temp = room->next;					/* aynı numaraya sahip node u tempe attım */
			room->next = room->next->next;		/* aradaki bağı  kırıp yeni bap olusturdum bir sonraki ile */
			free(temp);							/* silenecek veriyi free ledim */
			return (room);					
		}
		if(room->next->next == NULL)					/* son eleman silinecek ise */
		{
			if(number == room->next->number)
			{
				temp = room->next;					/* freelenecek  veri atandı */
				room->next = NULL;				/* liste sonu kontrolü yapıldı */
				free(temp);						/* silinecek veri frelendi */
				return (room);
			}
		}
		room= room->next;
	}
}
void show_vacancy (struct room_s * room,struct customer_s * customer)
{
	while(room->next != NULL)
	{
		if(room-> next_customer == NULL)			/* room a bağlı bir müşteri yoksa oda boştur ve bunu yazdır. */
		{
			printf("%d %d %d \n", room->number,room->capacity,room->floor);
		}

		room=room->next;
	}
}
void get_by_floor (struct room_s * room,int floor)
{
	while(room->next != NULL)							/* listeyi döndürür */
	{
		if(room->floor == floor)				/* parametrede verilen kat numarası ile aynı ise ekrana bas */		
		{
			printf("%d %d %d \n", room->number,room->capacity,room->floor);
		}

		room=room->next;
	}	
}
void print_list (struct room_s * room, struct customer_s customer)
{
	while(room->next != NULL)							/* listeyi döndürür */
	{
		

		room=room->next;
	}

}

int main()
{
	customer_t * customer;
	customer_t * customer_root;

	char comma;
	struct room_s * head;
	struct room_s * link;
	char name[12],surname[12],gender[7];
	int age;
	head = (struct room_s * )malloc(sizeof(room_t));
	link = (struct room_s * )malloc(sizeof(room_t));
	head= link;
	FILE *fp; 
	FILE * fp_customer;
	 customer = (customer_t *)malloc(sizeof(customer_t));
	customer->next = NULL;
	fp=fopen("rooms.txt","r");
	/* dosyadan odaları okur ve bunları add_room_to_end fonksiyonu ile listeyi birbirine pointer ile bağlar. */
		while(fscanf(fp,"%d%c%d%c%d\n",&link->number,&comma,&link->capacity,&comma,&link->floor) != EOF)  
		{
			link= add_room_to_end(link);	
		}
		fclose(fp); /* dosyayı kapatır */
		link = head;		/* başlangıç pointeri olan head e atama yapar. */

		while(link ->next != NULL)
		{
			printf("%d %d %d \n", link->number,link->capacity,link->floor);
			link=link->next;
		}
		printf("ffffffffffffffffffffffffffffffffff\n");

		customer_root = customer;
		fp_customer = fopen("customers.txt","r");
		while(!feof(fp_customer))
		{
			fscanf(fp_customer,"%d,%s ",&link->number,name);
			fscanf(fp_customer,"%[^,],",surname);
			fscanf(fp_customer,"%d,%[^\n]",&age,gender);
			customer = add_customer_to_end (customer,age,name,surname,gender);
		}
		fclose(fp_customer);
		customer = customer_root;
		
		link = head;		/* başlangıç pointeri olan head e atama yapar. */


}