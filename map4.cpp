#include <stdio.h>
#include<windows.h>
#define size 9
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

// This is my comment

int main(){
	int i, j, k, row=1;
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	ships();
	SetConsoleTextAttribute(h, color1);
	printf("   ");
	for(i=1; i<=size; i++){
		printf(" %d  ", i);
	}
	printf("\n  ");
	SetConsoleTextAttribute(h, color2);
	for(i=0; i<size; i++){
		printf("+---");
	}
	printf("+");
	SetConsoleTextAttribute(h, color1);
//	printf("%d |", row);
	
	for(i=0 ; i<size; i++){
		SetConsoleTextAttribute(h, color1);
		printf("\n%d ", row);
		SetConsoleTextAttribute(h, color2);
		printf("|", row);
		for(j=0; j<size; j++){
			printf("  %c|",playerships[i][j]);
		}
		row++;
		SetConsoleTextAttribute(h, color1);
		printf("\n  ");
		SetConsoleTextAttribute(h, color2);
		for(k=0; k<size; k++){
		printf("+---");
	}
	printf("+");
	SetConsoleTextAttribute(h, color1);

	}
}
