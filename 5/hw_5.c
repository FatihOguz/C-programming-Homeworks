/*********************************************************FATİH***OĞUZ***151044025***************************************************************/
#include <stdio.h>

typedef enum {white_man, black_man, white_king, black_king, empty}piece;
typedef enum {white=10, black=20}player;


void init_board(piece board[][8]);
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int check_end_of_game(piece board[][8]);
void display_board(piece board[][8]);
void sample_game_2();


int main()
{
	int a=99;
	piece board[8][8];
	player b=white;
	int from_x, from_y,  to_x,  to_y;

	init_board(board);
	sample_game_2();
	return(0);
}

void init_board(piece board[][8])
{
	/*	ilk olan i loop ile satırları 2. loop olan j ile atamaları if koşulları yardımıyla gerçekleştirerek start pozisyonu ekrana gösterdim.   */
	int i,j;
	for(i=0;i<8;++i)
	{
		for(j=0;j<8;++j)
		{
			if(i==1 || i==2)
			{
				board[i][j]=1;
				printf("b ");
			}
			else if( i==5 || i==6)
			{
				board[i][j]=0;
				printf("w ");
			}
			else
			{
				board[i][j]=4;
				printf("- ");
			}
		}
		printf("\n\n");
	}
}
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p)
{
	piece temp;
	int i,sum=0,j,count=0,countking=0,count1=0,flag=1;	


	/*	Kullanıcıdan 1 - 8 arasında koordinat aldım ancak işlem yaparken indexler 0 - 7 arasında kargaşa olmasın diye burada her bir */
	/* koordinatın değerini bir azaltıyorum.																						*/
	to_x = to_x -1;
	to_y = to_y -1;
	from_x= from_x -1;
	from_y=from_y - 1;



		if(board[from_x][from_y]==white_man)
			{
				if(board[from_x-2][from_y]==empty  && (board[from_x-1][from_y]==black_man  ||  board[from_x-1][from_y]==black_king))
				{
					board[from_x][from_y]=empty;
					board[from_x-1][from_y]=empty;
					board[from_x-2][from_y]=white_man;

					if(from_x == 1)
					{
						board[from_x][to_y]=white_king;
					
						
					}
				}
			}



	/*********************MAN TAŞLARIN KING OLMA DURUMLARI************************************/
	for(i=0;i<8;++i)
	{
		if(board[6][i]== black_man)	/* bir adım ileri gitse black king olucak */
		{
			if(to_x == 7)			/* gitmek istediği yer dama tahtasının dikey sınırı ise taşı kig yap */
			board[6][i]=black_king;
		}
		if(board[7][i]==black_man)
		{
			board[7][i]=black_king;
		}
		if (board[1][i]==white_man)
		{
			board[1][i]=white_king;
		}
		if(board[1][i]==white_man) /* bir adım ileri gitse white king olucak */
		{
			if(to_x==1)				/* gitmek istediği yer dama tahtasının dikey sınırı ise taşı king yap.*/
			board[1][i]=white_king;
		}
	}
	/**************************BAŞKA BİR TAŞ KULLANIMI VE RETURN -1 DURUMLARI*****************************/
	/* player kendi taşı dışında bir taşı oynatmaya kalkarsa return (-1) döndürmek için */
	/*	if ile player ın renginin değeri ile o renkin taşları dışında bir taşa dokunursa return(-1) */
	if(p==white)
	{
		if(board[from_x][from_y] == black_man)
		{
			return -1;
		}
		else if(board[from_x][from_y] == black_king) 			/* white player black taş kullanmaya çalışırsa		*/
		{
			return -1;
		}
	}
	if(p==black)
	{
		if(board[from_x][from_y] == white_man)
		{
			return -1;
		}
		else if(board[from_x][from_y] == white_king) 			/* black player white taş kullanmaya çalışırsa	*/
		{
			return -1;
		}
	}
	if(board[from_x][from_y] == empty)
	{
		return -1;								/* boş bir yerde taş olamaz			*/
	}
				/* ***********************MAN TAŞLARI İÇİN HARAKET DURUMLARI*********************************/
	/* 	bir man taşı sadece 1 adım ileri, sağa veya sola gidebilir.*/
	/*  gitiiği yerin öncelikle empty olan 4 değerine eşit olması gerekir.(zorunluluk olduğu için && bağlacı)*/
	/*	ve indisleri sağ için(i+1 , j), sol için(i-1,j), ileri için(i,j+1) durumlarından biri olmalıdır (||) bağlacı ile bu durum sağlanır */
		/*	dokunulan taşın man taşı olma şartı	*/
	
		if(board[from_x][from_y]==black_man )
		{
			
			if (board[to_x][to_y]==empty && ((to_x==from_x +1 && to_y==from_y)  || (to_x==from_x && to_y==from_y-1) || (to_x==from_x && to_y == from_y+1)) )
			{
				temp=board[from_x][from_y];
				board[from_x][from_y]=board[to_x][to_y];  /* swap işlemi ile görüntüleri değiştirdim */
				board[to_x][to_y]=temp;
				return 0;	/* taş yemeden haraket etme */
			}
		else if(board[to_x][to_y]!=empty)
			{
				return -2;
			}
		}
	
		else if(board[from_x][from_y]==white_man )
		{
			if (board[to_x][to_y]==empty && ((to_x==from_x -1 && to_y==from_y)  || (to_x==from_x && to_y==from_y-1) || (to_x==from_x && to_y == from_y+1)) )
			{
				temp=board[from_x][from_y];
				board[from_x][from_y]=board[to_x][to_y];  /* swap işlemi ile görüntüleri değiştirdim */
				board[to_x][to_y]=temp;
				return 0;	/* taş yemeden haraket etme */
			}
			else if(board[to_x][to_y]!=empty)
			{
				return -2;
			}
		
		}
		else if(board[from_x][from_y]==white_man)
		{
			if(to_x - from_x==-1)
			{
				return -2;		/* taşın geri gitmek istemesi	*/
			}
		}

		else if(board[from_x][from_y]==black_man)
		{
			if(to_x - from_x==1)
			{
				return -2;    /* taşın geri gitmek istemesi	*/
			}
		}
		
			/* white man içi n tane yeme durumunda*/
			flag=1;
			while(flag==1)
			{
				if(board[from_x][from_y]==white_man)
				{	
					count=0;
					if(board[from_x][from_y-2]==empty && (board[from_x][from_y-1]==black_man  ||  board[from_x][from_y-1]==black_king))
					{

						/* from_y>1 taşın tahtayı silindir gibi düşünü soldan sağa geçmesini engeller.(taş yeme durumunda)*/
						if(from_y > 0)
						{
							board[from_x][from_y-1]=empty;
							board[from_x][from_y-2]=white_man;/* 1 sol da siyah taş var ve onun solu boş ise soldaki siyahı yeme swap işlemi */
							board[from_x][from_y]=empty;
							count += 1;
						}
						else
						{
							return -2;
						}
					}
					if(board[from_x][from_y+2]==empty  && ( board[from_x][from_y+1]==black_man || board[from_x][from_y+1]==black_king) )
					{
						/* from_y<7 taşın tahtayı silindir gibi düşünü soldan sağa geçmesini engeller.(taş yeme durumunda)*/
						if(from_y < 7)
						{
							board[from_x][from_y+1]=empty;
							board[from_x][from_y+2]=white_man;/* 1 sağda da siyah taş var ve onun sağı boş ise sağdaki siyahı yeme swap işlemi */
							board[from_x][from_y]=empty;
							count += 1;
							
						}
						else
						{
							return -2;
						}
						
					}
					
					if( board[from_x-2][from_y]==empty  && (board[from_x-1][from_y]==black_man  ||  board[from_x-1][from_y]==black_king))
					{
						/* from_x > 1 olamlı çünkü o noktada ileri  yeme işlemi yapamaz */
						if(from_x>0)
						{
							board[from_x-1][from_y]=empty;
							board[from_x-2][from_y]=white_man;/* 1 önünde da siyah taş var ve onun solu boş ise soldaki siyahı yeme swap işlemi */
							board[from_x][from_y]=empty;
							count += 1;

						}
							else 
							{
								return -2;
							}
						
					
					}	
				}
				else 
				{
					
					flag=0;
				}
			}

		

			flag=1;
			while(flag==1)
			{
				/*  BLACK MAN İÇİN n tane yeme durumu*********************/
				 if(board[from_x][from_y]==black_man)
				{	
					if( board[from_x][from_y-2]==empty && (board[from_x][from_y-1]==white_man  ||  board[from_x][from_y-1]==white_king))
					{
						/* from_y>1 taşın tahtayı silindir gibi düşünü soldan sağa geçmesini engeller.(taş yeme durumunda)*/
						if(from_y > 1)
						{
							board[from_x][from_y-1]=empty;
							board[from_x][from_y-2]=black_man;	/* 1 sol da beyaz taş var ve onun solu boş ise soldaki beyazı yeme swap işlemi */
							board[from_x][from_y]=empty;
							count += 1;
						}
						else
						{
							return -2;
						}
					
						
					}
					else if(board[from_x][from_y+2]==empty  && ( board[from_x][from_y+1]==white_man || board[from_x][from_y+1]==white_king) )
					{
						/* from_y<7 taşın tahtayı silindir gibi düşünü soldan sağa geçmesini engeller.(taş yeme durumunda)*/
						if(from_y<7)
						{
							board[from_x][from_y+1]=empty;
							board[from_x][from_y+2]=black_man;/* 1 sağda da beyaz taş var ve onun sağı boş ise sağdaki beyazı yeme swap işlemi */
							board[from_x][from_y]=empty;
							count += 1;
						}
						else
						{
							return -2;
						}
						
					}
					else if( board[from_x+2][from_y]==empty  && (board[from_x+1][from_y]==white_man  ||  board[from_x+1][from_y]==white_king))
					{
						/* from_x < 6 olak zorunda onun ilerisindeki bir noktaa black taşları ileri yönde yeme işlemi yapamaz	*/
						if(from_x < 6)
						{
							board[from_x+1][from_y]=empty;
							board[from_x+2][from_y]=black_man;/* 1 önünde da beyaz taş var ve onun solu boş ise ilerideki beyaz yeme swap işlemi */
							board[from_x][from_y]=empty;
							count += 1;
						}
						else
						{
							return -2;
						}
						
					}
				}
					else
					{
						flag=0;
					}
			}
			

	/*****************************KING TAŞLARI İÇİN HARAKET DURUMLARI*******************************************/
	 if(board[from_x][from_y]==white_king || board[from_x][from_y]==black_king)
	{	
		if(from_y== to_y  && from_x > to_x)		/* yukarı doğru ilerleme durumunda*/
		{	count1=0;
			for(i=from_x-1 ;i>=to_x; --i)
			{
				if(board[i][to_y]==empty)
				{
					count1++;
				}	
			}
			if(count1==(from_x - to_x ))
					{
						temp=board[from_x][from_y];
						board[from_x][from_y]=empty;
						board[to_x][to_y]=temp;
					}
		}

		else if(from_y== to_y  && from_x < to_x)		/* aşağı doğru ilerleme durumunda*/
		{
			count1=0;
			for(i=from_x+1 ;i<=to_x; ++i)
			{
				if(board[i][to_y]==empty)
				{
					count1++;
				}	
			}
			if(count1==(to_x-from_x))
			{
				temp=board[from_x][from_y];
					board[from_x][from_y]=empty;
					board[to_x][to_y]=temp;
			}
					
		}

		else if(from_x== to_x  && from_y < to_y)		/* sağ doğru ilerleme durumunda*/
		{
			count1=0;
			for(i=from_y+1 ;i<=to_y ; i++)
			{
				if(board[from_x][i]==empty)
				{
					count1++;
				}	
			}
				if(count1==(to_y-from_y))
				{
					
					temp=board[from_x][from_y];
					board[from_x][from_y]=empty;
					board[to_x][to_y]=temp;
				}
					
		}


		else if(from_x== to_x  && from_y > to_y)		/* sol doğru ilerleme durumunda*/
		{
			count1=0;
			for(i=from_y-1 ;i>=to_y ; --i)
			{
				if(board[to_x][i]==empty)
				{
					count1++;
				}	
			}
				if(count1==(from_y-to_y))
					{
						temp=board[from_x][from_y];
					board[from_x][from_y]=empty;
					board[to_x][to_y]=temp;
					}
		}


		else if (board[to_x][to_y]!=empty)		/* dolu olan yere gidemez */
		{
	
			return(-2);/*haraket edemeyeceği yerler için */
		}

		else if(from_x!=to_x && from_y!=to_y)/* çapraz gitmemesi : koordinatların ikisi birden değişemez */
			{
				return -2;/*haraket edemeyeceği yerler için*/
			}
	

	}


/********KING TAŞLARI N TANE YEME DURUMU******************/
flag=1;
while(flag==1)
{
			if(board[from_x][from_y]==white_king)
			{
																	if(from_y== to_y  && from_x > to_x)		/* yukarı doğru ilerleme durumunda*/
																	{
																		if(board[to_x][to_y]==empty)
																		{
																			if(board[to_x +1][to_y]==black_man  || board[to_x +1][to_y]==black_king)
																			{
																				countking=0;
																				count1=0;
																				for(i=from_x-1;i>to_x+1;--i)
																				{
																					if(board[i][to_y]==empty)
																					{
																						count1++;
																					}
																				}
																				if(count1==(from_x - to_x - 2))
																				{
																					board[to_x][to_y]=white_king;
																					board[from_x][from_y]=empty;
																					board[to_x+1][to_y]=empty;
																					countking++;
																				}
																				

																			}
																		}
																	}

																	else if(from_y== to_y  && from_x < to_x)		/* aşağı doğru ilerleme durumunda*/
																	{
																		if(board[to_x][to_y]==empty)
																		{
																			if(board[to_x-1][to_y]==black_king  || board[to_x-1][to_y]==black_man)
																			{
																				countking=0;
																				count1=0;
																				for(i=from_x+1;i<to_x-1;++i)
																				{
																					if(board[i][to_y]==empty)
																					{
																						count1++;
																					}
																				}
																				if(count1==(to_x - from_x -2))
																				{
																					board[to_x][to_y]=white_king;
																				board[from_x][from_y]=empty;
																				board[to_x-1][to_y]=empty;
																				countking++;

																				}
																				
																			}
																		}
																	}

																	else if(from_y < to_y && from_x==to_x)
																	{
																		if(board[to_x][to_y]==empty)
																		{
																			if(board[to_x][to_y-1]==black_man || board[to_x][to_y-1]==black_king)  /* sağa yeme durumu */ 
																			{
																				countking=0;
																				count1=0;
																				for(i=from_y+1;i<to_y-1;++i)
																				{
																					if(board[to_x][i]==empty)
																					{
																							count1++;
																					}
																				}
																				if(count1==(to_y - from_y - 2))
																				{
																					board[to_x][to_y]=white_king;
																				board[from_x][from_y]=empty;
																				board[to_x][to_y-1]=empty;
																				countking++;
																				}
																				
																			}
																		}
																	}

																	else if(from_x==to_x && from_y > to_y)
																	{
																		if(board[to_x][to_y]==empty)
																		{
																			if(board[to_x][to_y+1]== black_king  || board[to_x][to_y+1]== black_man)
																			{
																				count1=0;
																				countking=0;
																				for(i=from_y-1;i>to_y+1;i--)
																				{
																					if(board[to_x][i]==empty)
																					{
																							count1++;
																					}
																				}
																				if(count1==(from_y - to_y -2))
																				{
																					board[to_x][to_y]=white_king;
																				board[from_x][from_y]=empty;
																				board[to_x][to_y+1]=empty;
																				countking++;

																				}
																				
																			}
																		}
																	
																	}
		}
			

			/*black king*/

			if(board[from_x][from_y]==black_king)
			{	
				if(from_y== to_y  && from_x > to_x)		/* yukarı doğru ilerleme durumunda*/
				{
					if(board[to_x][to_y]==empty)
					{
						if(board[to_x +1][to_y]==white_man  || board[to_x +1][to_y]==white_king)
						{
							count1=0;
							for(i=from_x-1;i>to_x+1;--i)
							{
								if(board[i][to_y]!=empty)
								{

								}
							}
							board[to_x][to_y]=black_king;
							board[from_x][from_y]=empty;
							board[to_x+1][to_y]=empty;
							countking++;

						}
					}
				}

				else if(from_y== to_y  && from_x < to_x)		/* aşağı doğru ilerleme durumunda*/
				{
					if(board[to_x][to_y]==empty)
					{
						if(board[to_x-1][to_y]==white_king  || board[to_x-1][to_y]==white_man)
						{
							count1=0;
							for(i=from_x+1;i<to_x-1;++i)
							{
								if(board[i][to_y]!=empty)
								{
								}
							}
							board[to_x][to_y]=black_king;
							board[from_x][from_y]=empty;
							board[to_x-1][to_y]=empty;
							countking++;
						}
					}
				}

				else if(from_y < to_y && from_x==to_x)
				{
					if(board[to_x][to_y]==empty)
					{	
						if(board[to_x][to_y-1]==white_man || board[to_x][to_y-1]==white_king)	/* sağa yeme durumunda*/
						{
							count1=0;
							for(i=from_y+1;i<to_y-1;++i)
							{
								if(board[to_x][i]==empty)
								{
										count1++;
								}
							}
							if(count1 == (to_y - from_y - 2))
							{
								board[to_x][to_y]=black_king;
								board[from_x][from_y]=empty;
								board[to_x][to_y-1]=empty;
								countking++;
							}
						}
					}
			}

			else if(from_x==to_x && from_y > to_y)
			{
				if(board[to_x][to_y]==empty)
				{
					if(board[to_x][to_y+1]== white_king  || board[to_x][to_y+1]== white_man)
					{
						count1=0;
						for(i=from_y;i>to_y+1;i--)
						{
							if(board[to_x][i]!=empty)
							{

							}

						}
						board[to_x][to_y]=black_king;
						board[from_x][from_y]=empty;
						board[to_x][to_y+1]=empty;
						countking++;

					}

				}

			}
			
		}
	
	
		else
			{
				flag=0;
			}	

	

if(board[from_x][from_y]==white_man  || board[from_x][from_y]==black_man)
{
	return count;
}
else if(board[from_x][from_y]==white_king  || board[from_x][from_y]==black_king)
{
	return countking;
}


	
}	

}

/* move fonk sonu */

int check_end_of_game(piece board[][8])
{
	int i,j,count_white=0,count_black=0;

	for(i=0;i<8;++i)
	{
		for(j=0;j<8;++j)
		{
			if(board[i][j]==white_man  ||   board[i][j]==white_king)
			{
					count_white++;
			}
			else if(board[i][j]==black_man  ||   board[i][j]==black_king)
			{
				count_black++;
			}
		}
	}

	if(count_white==0)
	{
		printf("winner is black\n");
		return 1;
	}
	else if(count_black==0)
	{
		printf("winner is white\n");
		return 1;
	}
	else 
	{
		printf("game countinues\n");
		return -1;
	}


}

void sample_game_2()
{
	piece board[8][8];
	player p;
	int from_x, from_y,  to_x,  to_y,i,j,r_move;

	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			board[i][j]=empty;
		}
	}
	board[1][2]=black_man;
	board[1][3]=black_man;
	board[1][4]=black_man;
	board[1][5]=black_man;
	board[2][1]=black_man;
	board[2][2]=black_man;
	board[2][3]=black_man;
	board[2][4]=black_man;
	board[2][6]=black_man;
	board[2][7]=black_man;
	board[3][0]=black_man;
	board[3][1]=black_man;
	board[3][2]=black_man;
	board[3][5]=black_man;
	board[3][7]=black_man;
	board[4][5]=black_man;

	board[6][2]=white_man;
	board[6][3]=white_man;
	board[6][4]=white_man;
	board[6][5]=white_man;
	board[5][0]=white_man;
	board[5][1]=white_man;
	board[5][2]=white_man;
	board[5][3]=white_man;
	board[5][4]=white_man;
	board[5][6]=white_man;
	board[5][7]=white_man;
	board[4][2]=white_man;
	board[4][3]=white_man;
	board[4][4]=white_man;
	board[4][6]=white_man;
	board[4][7]=white_man;


	
	
	display_board(board);
	r_move=move(board, 6, 2, 5, 2,  white);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 4, 2, 6, 2,  black);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 5, 4, 4, 4,  white);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 5, 6, 5, 4,  black);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 4, 4, 4, 2,  white);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 5, 4, 5, 2,  black);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 4, 2, 2, 2,  white);
	display_board(board);
	check_end_of_game(board);
	
	r_move=move(board, 2, 3, 2, 1,  black);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 6, 4, 5, 4,  white);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 6, 2, 6, 4,  black);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 6, 4, 6, 6,  black);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 6, 6, 8, 6,  black);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 5, 4, 4, 4,  white);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 3, 4, 5, 4,  black);
	display_board(board);
	check_end_of_game(board);

		r_move=move(board, 6, 7, 6, 6,  white);
	display_board(board);
	check_end_of_game(board);

	r_move=move(board, 8, 6, 5, 6,  black);
	display_board(board);
	check_end_of_game(board);

		r_move=move(board, 5, 7, 5, 5,  white);
	display_board(board);
	check_end_of_game(board);

		r_move=move(board, 5, 5, 5, 3,  white);
	display_board(board);
	check_end_of_game(board);

		r_move=move(board, 5, 3, 5, 1,  white);
	display_board(board);
	check_end_of_game(board);

		r_move=move(board, 5, 1, 3, 1,  white);
		display_board(board);
		check_end_of_game(board);

		r_move=move(board, 3, 1, 1, 1,  white);
		display_board(board);
		check_end_of_game(board);
	


}
void display_board(piece board[][8])
{
	/* typedef enum piece e göre numaraları if aracılığı ile  board a atayıp sayının karşılığı harfi veya sembolü tahtaya yazdırdım	*/
	int i, j;
	printf("\n\n\n");
	printf("    1 2 3 4 5 6 7 8\n\n");
	for(i=0;i<8;++i)
	{
		printf("%d   ",i+1);

		for(j=0;j<8;++j)
		{

			if(board[i][j] == 0)
			{
				printf("w ");
			}
			if(board[i][j] == 1)
			{
				printf("b ");
			}
			if(board[i][j] == 2)
			{
				printf("W ");
			}
			if(board[i][j] == 3)
			{
				printf("B ");
			}
			if(board[i][j] == 4)
			{
				printf("- ");
			}
		}
		printf("\n\n");
	} 
}
