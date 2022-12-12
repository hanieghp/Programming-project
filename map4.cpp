#include <stdio.h>
#include<windows.h>
#include<math.h>
#define size 9
#define color1 15//nembers 15
#define color2 31//waves 31
#define player1 FOCP1
#define player2 FOCP2

char playerships[size][size];
char player2ships[size][size];

void Friendlyships(){
	int i, j;
	for(i=0 ; i<size; i++){
		for(j=0; j<size; j++){
			playerships[i][j]=' ';
		}
	}
}

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
	for(i=0; i<size; i++){
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

	}
	printf(" \n");
	/*printf("ARE YOU READY? \n");
	printf("PLEASE ENTER THE NUBMER OF YOUR SHIP: ");
	scanf("%d",&num);*/
}