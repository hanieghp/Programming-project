#include <stdio.h>
#include<windows.h>
#include <conio.h>
#define Size 9
#define color1 15//nembers 15
#define color2 31//waves 31
#define player1 FOCP1
#define player2 FOCP2

int size, round;
char player1name[20], player2name[20], player1ships[Size][Size], player2ships[Size][Size], player1attacks[Size][Size], player2attacks[Size][Size];
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

void pFirstLine(){
if(round % 2){
	printf("  %s",player1name);
	for(int i=0;i<(4*size-1)-strlen(player1name);i++){
		printf(" ");
	}
	printf("\t\t\t  ");
	printf("%s \n", player2name);
}
else {
	printf("  %s",player2name);
	for(int i=0;i<(4*size-1)-strlen(player2name);i++){
		printf(" ");
	}
	printf("\t\t\t  ");
	printf("%s \n", player1name);
}
}

void pPlayerBoard(int n, int i){
	int j;
	if(round % 2){
		if(n==1){
			for(j=0; j<size; j++){
				printf(" %c |",player1attacks[i][j]);
			}
		}
		else if(n==2){
			for(j=0; j<size; j++){
				printf(" %c |",player1ships[i][j]);
			}
		}
	}
	else{
		if(n==2){
			for(j=0; j<size; j++){
				printf(" %c |",player2attacks[i][j]);
			}
		}
		else if(n==1){
			for(j=0; j<size; j++){
				printf(" %c |",player2ships[i][j]);
			}
		}
	}
}



void SetBlack(){//change background to black
	SetConsoleTextAttribute(h, color1);
}

void SetBlue(){
	SetConsoleTextAttribute(h, color2);//change background to blue
}

void emptyships(){//makes cells empty
	int i, j;
	for(i=0 ; i<size; i++){
		for(j=0; j<size; j++){
			player1ships[i][j]=' ';
		}
	}
	for(i=0 ; i<size; i++){
		for(j=0; j<size; j++){
			player2ships[i][j]=' ';
		}
	}
}

void printing_shape(){//printing shapes(+-) for boards
	int i;
	SetBlue();			
	for(i=0; i<size; i++){
		printf("+---");
	}
	printf("+");
	SetBlack();
	printf("\t\t\t  ");
	SetBlue();
	for(i=0; i<size; i++){
		printf("+---");
	}
	printf("+");
}

void playername(int code){//getting the name of player
	if(code==1){
		scanf("%s",player1name);	
	}
	else {
		scanf("%s",player2name);
	}	
}

int strlen(char string[]) {//Specifying the length of players' names
   int lenght;
   for (lenght=0; string[lenght]; lenght++) ;
   return(lenght);
}

int checkShips(int i, int j, char code, int player){//cow cordinate, row cordinate , possition, player 1or 2
    int k;
    if(code == 'h' && j+2 <= size){
        if(player == 1){
            for(k=j ; k<j+3 ; k++){
                if(player1ships[i-1][j-1] == 'X'){
                        return 0;//error    
                }            
            }
            return 1;
    	}
    	
        if(player == 2){
            for(k=j ; k<j+3 ; k++){
                if(player2ships[i-1][j-1] == 'X'){
                        return 0;//error    
                }            
            }
            return 1;
		}
    }
    else if(code == 'v' && i+2 <= size){
        if(player == 1){
            for(k=i ; k<i+3 ; k++){
                if(player1ships[i-1][j-1] == 'X'){
                        return 0;//error    
                }            
            }
        	return 1;
		}
            
        if(player == 2){
            for(k=i ; k<i+3 ; k++){
                if(player2ships[i-1][j-1] == 'X'){
                        return 0;//error    
                }            
            }
			return 1;
        }
    }
    return 0;//overFlow or wrong code 
}

void placementships(int row, int col, char position, int code){//get coordinate and position of ships
	int temp;
	if(code==1){
		 if(position=='h'){
		 	for(int j=0;j<3;j++){
		 		player1ships[row-1][col+j-1]='X';
			 }
		 }
		 else if(position=='v'){
		 	for(int j=0;j<3;j++){
		 		player1ships[row+j-1][col-1]='X';
			 }
		 }	
	}
	else {
		   if(position=='h'){
		 	for(int j=0;j<3;j++){
		 		player2ships[row-1][col+j-1]='X';
			 }
		 }
		 else if(position=='v'){
		 	for(int j=0;j<3;j++){
		 		player2ships[row+j-1][col-1]='X';
			 }
		 }		
	}
}



int main(){
	int i, j, k, z, p_col, p_row;
	char position, row; 
	emptyships();//makes cells empty
	emptyships();//makes cells empty
	
	//getting inputs
	printf("give size\n");
	scanf("%d", &size);
	emptyships();//makes cells empty
	emptyships();//makes cells empty
	
	printf("Enter the number of your ships \n");
	scanf("%d", &k);
	
	printf("Enter the name of first player \n");
	playername(1);
	
	printf("Enter the coordinates of your ships \n");
	for(i=0 ; i<k ; i++){
		scanf("%d %d %c", &p_row, &p_col, &position);
		if(checkShips(p_row, p_col, position, 1)){
			placementships(p_row, p_col, position, 1);
		}
		else{
			printf("again\n");
			i--;
		}			
	}
	printf("--- \n");
	
	printf("Enter the name of second player \n");
	playername(2);
	
	printf("Enter the coordinates of your ships \n");
	for(i=0 ; i<k ; i++){
		scanf("%d %d %c", &p_row, &p_col, &position);
		if(checkShips(p_row, p_col, position, 2)){
			placementships(p_row, p_col, position, 2);
		}
		else{
			printf("again\n");
			i--;
		}			
	}
	//**********************************************
	
while(1){
	round ++ ;
	row='A' ;
	char row='A';
	printf("  round : %d \n", round);
	//printing first line include players' names
	pFirstLine();
	
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
		pPlayerBoard(1, i);
		
		SetBlack();
		printf("\t\t\t");
		printf("%c ",row);
		SetBlue();
		printf("|");
		
		//printing second player board row(i)
		pPlayerBoard(2, i);
		
		row++;
		SetBlack();
		printf("\n  ");	
		printing_shape();
	}
	SetBlack();
	printf(" \n");
	getch();
	system("cls");
}
}