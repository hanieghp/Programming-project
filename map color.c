#include <stdio.h>
#include<windows.h>
#include<math.h>
#define size 8
#define color1 15//nembers 15
#define color2 31//waves 31

char playerships[size][size];

void ships(){
	int i, j;
	for(i=0 ; i<size; i++){
		for(j=0; j<size; j++){
			playerships[i][j]=' ';
		}
	}
}
void setTextcolor(int textColor,int backColor){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int colorAttribute = backColor << 4 | textColor;
	SetConsoleTextAttribute(consoleHandle,colorAttribute);
}

int main(){
	int i, j, k,num;
	char row='A';
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	ships();
	SetConsoleTextAttribute(h,15);
	for(int i=1;i<=size/4;i++){
		printf("\t");
	}
	SetConsoleTextAttribute(h,9);
	printf("FOCP1");
	SetConsoleTextAttribute(h,15);
	for(int i=1;i<=size;i++){
		printf("\t");
	}
	SetConsoleTextAttribute(h,12);
	printf("FOCP2 \n");
	//number column
	printf("   ");
	SetConsoleTextAttribute(h,15);
	for(i=1; i<=size; i++){
		printf(" %d  ", i);
	}
	for(int i=0;i<size/2;i++){
		printf("\t");
	}
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
	for(int i=1;i<=size/2;i++){
		printf("\t");
	}
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
			printf("  %c|",playerships[i][j]);
		}
		for(int l=0;l<size;l++){
			printf("   ");
		}
		printf("%c",row);
		printf(" |");
		for(int z=0;z<size;z++){
			printf("  %c|",playerships[i][j]);
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
	for(int i=1;i<=size/2;i++){
		printf("\t");
	}
	for(int i=0;i<size;i++){
		printf("+---");
	}
	printf("+");
	SetConsoleTextAttribute(h, color1);

	}
	printf(" \n");
	printf("ARE YOU READY? \n");
	printf("PLEASE ENTER THE NUBMER OF YOUR SHIP: ");
	scanf("%d",&num);
}