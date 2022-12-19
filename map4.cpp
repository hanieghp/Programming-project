3#include <stdio.h>
#include<windows.h>
#include<math.h>
<<<<<<< HEAD
#include<string.h>
#define Size 9
=======
#define size 9
>>>>>>> 69f4d8eb9989a7e5e95fc72741b332386d808660
#define color1 15//nembers 15
#define color2 31//waves 31
#define player1 FOCP1
#define player2 FOCP2

<<<<<<< HEAD
int size;
char player1name[20];
char player2name[20];
char player1ships[Size][Size];
char player2ships[Size][Size];
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

void SetBlack(){//change background to black
	SetConsoleTextAttribute(h, color1);
}

void SetBlue(){
	SetConsoleTextAttribute(h, color2);//change background to blue
}

void emptyships(char playerships[][Size]){//makes cells empty
=======
char playerships[size][size];
char player2ships[size][size];

void Friendlyships(){
>>>>>>> 69f4d8eb9989a7e5e95fc72741b332386d808660
	int i, j;
	for(i=0 ; i<size; i++){
		for(j=0; j<size; j++){
			playerships[i][j]=' ';
		}
	}
}

<<<<<<< HEAD
void GetCordinates(int code){//Gets cordinates and destroy them
	int col, row;
	scanf("%d %d", &row, &col);
	if(code==1){
		player1ships[row-1][col-1]='*';
	}
	else if(code == 2){
		player2ships[row-1][col-1]='*';
	}
}



void printing_shape(){//printing shapes(+-) for boards
	int i;
	SetBlue();			
=======
void Oppentships(){
	int i, j;
	for(i=0 ; i<size; i++){
		for(j=0; j<size; j++){
			player2ships[i][j]=' ';
		}
	}
}

int main(){
	int i, j, k,num;
	char row='A';
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	Friendlyships();
	Oppentships();
	SetConsoleTextAttribute(h, color1);
	printf("  FOCP1");
	printf("\t\t\t  ");
	for(i=0; i<4*size-4; i++){
		printf(" ");
	}
	printf("FOCP2 \n");
	//number column
	printf("   ");
	for(i=1; i<=size; i++){
		printf(" %d  ", i);
	}
	printf("\t\t\t   ");
	for(int i=1;i<=size;i++){
		printf(" %d  ",i);
	}
	printf("\n  ");
	
	//board shape1 +-
	SetConsoleTextAttribute(h, color2);
>>>>>>> 69f4d8eb9989a7e5e95fc72741b332386d808660
	for(i=0; i<size; i++){
		printf("+---");
	}
	printf("+");
<<<<<<< HEAD
	SetBlack();
	printf("\t\t\t  ");
	SetBlue();
	for(i=0; i<size; i++){
		printf("+---");
	}
	printf("+");
}
=======
	SetConsoleTextAttribute(h, color1);
	printf("\t\t\t  ");
	SetConsoleTextAttribute(h, color2);
	for(int i=0;i<size;i++){
		printf("+---");
	}
	printf("+");
	//boards shape |
	SetConsoleTextAttribute(h, color1);
	for(i=0 ; i<size; i++){
		SetConsoleTextAttribute(h, color1);
		printf("\n%c ", row);
		SetConsoleTextAttribute(h, color2);
		printf("|",row);
		for(j=0; j<size; j++){
			printf(" %c |",playerships[i][j]);
		}
		SetConsoleTextAttribute(h, color1);
		printf("\t\t\t");
		printf("%c ",row);
		SetConsoleTextAttribute(h, color2);
		printf("|");
		for(int z=0;z<size;z++){
			printf(" %c |",player2ships[i][j]);
		}
		row++;
	//board shape2 +-
		SetConsoleTextAttribute(h, color1);
		printf("\n  ");
		SetConsoleTextAttribute(h, color2);
		for(k=0; k<size; k++){
		printf("+---");
	}
	printf("+");
	SetConsoleTextAttribute(h, color1);
	printf("\t\t\t  ");
	SetConsoleTextAttribute(h, color2);
	for(int i=0;i<size;i++){
		printf("+---");
	}
	printf("+");
	SetConsoleTextAttribute(h, color1);
>>>>>>> 69f4d8eb9989a7e5e95fc72741b332386d808660

void playername(int code){//getting the name of player
	if(code==1){
	scanf("%s",player1name);	
	}
	else if(code==2){
		scanf("%s",player2name);
	}	
}

int strlen(char string[]) {//Specifying the length of players' names
   int lenght;
   for (lenght=0; string[lenght]; lenght++) ;
   return(lenght);
}

void placementships(int k,int code){
	int row,col;
	char position;
	if(code==1){
		for(int i=0;i<k;i++){
		 scanf("%d %d %c \n",&row,&col,&position);
		 if(position=='h'){
		 	for(int j=0;j<3;j++){
		 		player1ships[row][col+j]='k';
			 }
		 }
		 else if(position=='v'){
		 	for(int j=0;j<3;j++){
		 		player1ships[row+j][col]='k';
			 }
		 }	
		}
	}
	if(code==2){
		for(int i=0;i<k;i++){
		scanf("%d %d %c \n",&row,&col,&position);
		   if(position=='h'){
		 	for(int j=0;j<3;j++){
		 		player2ships[row][col+j]='k';
			 }
		 }
		 else if(position=='v'){
		 	for(int j=0;j<3;j++){
		 		player2ships[row+j][col]='k';
			 }
		 }		
		}
	}
}

int main(){
	int n=3,i, j, k, z, p_col, p_row;
	char row='A'; 
	emptyships(player1ships);//makes cells empty
	emptyships(player2ships);//makes cells empty
	
	//getting inputs
	printf("give size\n");
	scanf("%d", &size);
	
	printf("Enter the number of your ships \n");
	scanf("%d", &k);
	
	printf("Enter the name of first player \n");
	playername(1);
	
	printf("Enter the coordinates of your ships \n");
	for(i=0 ; i<k; i++){
		placementships(k,1);
	}
	printf("--- \n");
	
	printf("Enter the name of second player \n");
	playername(2);
	
	printf("Enter the coordinates of your ships \n");
	for(i=0 ; i<k; i++){
		placementships(k,2);
	}
	
	//printing first line include players' names
	printf("  %s",player1name);
	for(int i=0;i<(4*size-1)-strlen(player1name);i++){
		printf(" ");
	}
	printf("\t\t\t  ");
	printf("%s \n",player2name);
	
	//printing second line include remaining ships
	printf("  remaining ships: %d", k);	
	for(int i=0;i<(4*size-1)-16;i++){
		printf(" ");
	}
	printf("\t\t\t  ");
	printf("remaining ships: %d \n", k);
	
	//printing third line include col numbers
	printf("   ");
	for(i=1; i<=size; i++){
		printf(" %d  ", i);
	}
	printf("\t\t\t   ");
	for(i=1; i<=size; i++){
		printf(" %d  ",i);
	}
	
	printf("\n  ");
	printing_shape();
	
	//printing boards
	for(i=0 ; i<size; i++){
		SetBlack();
		printf("\n%c ", row);
		SetBlue();
		printf("|");
		
		//printing first player board row(i)
		for(j=0; j<size; j++){
			printf(" %c |",player1ships[i][j]);
		}
		
		SetBlack();
		printf("\t\t\t");
		printf("%c ",row);
		SetBlue();
		printf("|");
		
		//printing second player board row(i)
		for(j=0; j<size; j++){
			printf(" %c |",player2ships[i][j]);
		}
		
		row++;
		SetBlack();
		printf("\n  ");	
		printing_shape();
	}
	SetBlack();
	printf(" \n");
<<<<<<< HEAD
=======
	/*printf("ARE YOU READY? \n");
	printf("PLEASE ENTER THE NUBMER OF YOUR SHIP: ");
	scanf("%d",&num);*/
>>>>>>> 69f4d8eb9989a7e5e95fc72741b332386d808660
}