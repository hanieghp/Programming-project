#include <stdio.h>
#include<windows.h>
#include <conio.h>
#include<string.h>
#define Size 9
#define color1 15//nembers 15
#define color2 31//waves 31
#define player1 FOCP1
#define player2 FOCP2

int size, round0,  k, numPlayer1Ships, numPlayer2Ships,p1_row,p1_col,p2_row,p2_col;
char player1name[20], player2name[20], player1ships[Size][Size], player2ships[Size][Size], player1attacks[Size][Size], player2attacks[Size][Size],position1,position2;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
FILE *infile;

void pFirstLine(){
if(round0 % 2){
	printf("  %s",player2name);
	for(int i=0;i<(4*size-1)-strlen(player2name);i++){
		printf(" ");
	}
	printf("\t\t\t  ");
	printf("%s \n", player1name);
}
else {
	printf("  %s",player1name);
	for(int i=0;i<(4*size-1)-strlen(player1name);i++){
		printf(" ");
	}
	printf("\t\t\t  ");
	printf("%s \n", player2name);
}
}

void pSecondLine(){
	if(round0 %2){
		printf("  remaining ships: %d", numPlayer2Ships);	
		for(int i=0;i<(4*size-1)-16;i++){
			printf(" ");
		}
		printf("\t\t\t  ");
		printf("remaining ships: %d \n", numPlayer1Ships);
	}
	else{
		printf("  remaining ships: %d", numPlayer1Ships);	
		for(int i=0;i<(4*size-1)-16;i++){
			printf(" ");
		}
		printf("\t\t\t  ");
		printf("remaining ships: %d \n", numPlayer2Ships);
	}
}

void pPlayerBoard(int n, int i){
	int j;
	if(round0 % 2){
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
		if(n==1){
			for(j=0; j<size; j++){
				printf(" %c |",player2attacks[i][j]);
			}
		}
		else if(n==2){
			for(j=0; j<size; j++){
				printf(" %c |",player2ships[i][j]);
			}
		}
	}
}



void SetBlack(){//change background to black
	SetConsoleTextAttribute(h, color1);
}

void SetBlue(){//change background to blue
	SetConsoleTextAttribute(h, color2);
}

void emptyships(){//makes cells empty
	int i, j;
	for(i=0 ; i<size; i++){
		for(j=0; j<size; j++){
			player1ships[i][j]=' ';
			player2ships[i][j]=' ';
			player1attacks[i][j]=' ';
			player2attacks[i][j]=' ';			
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
		fprintf(infile,"%s \n",player1name);	
	}
	else {
		scanf("%s",player2name);
		fprintf(infile,"%s \n",player2name);
	}	
}

int checkShips(int i, int j, char code, int player){//cow cordinate, row cordinate , possition, player 1or 2
    int k;
    if(code == 'h' && j+2 <= size){
        if(player == 1){
            for(k=j ; k<j+3 ; k++){
                if(player1ships[i-1][k-1] != ' '){
                        return 0;//error    
                }            
            }
            return 1;
    	}
    	
        if(player == 2){
            for(k=j ; k<j+3 ; k++){
                if(player2ships[i-1][k-1] != ' '){
                        return 0;//error    
                }            
            }
            return 1;
		}
    }
    else if(code == 'v' && i+2 <= size){
        if(player == 1){
            for(k=i ; k<i+3 ; k++){
                if(player1ships[k-1][j-1] != ' '){
                        return 0;//error    
                }            
            }
        	return 1;
		}
            
        if(player == 2){
            for(k=i ; k<i+3 ; k++){
                if(player2ships[k-1][j-1] != ' '){
                        return 0;//error    
                }            
            }
			return 1;
        }
    }
    return 0;//overFlow or wrong code 
}

void placementships(int row, int col, char pos, int code){//get coordinate and position of ships
	int temp;
	if(code==1){
		 if(pos =='h'){
		 	player1ships[row-1][col-1] = 17 ;
		 	player1ships[row-1][col] = 'O';
		 	player1ships[row-1][col+1] = 16 ;
		 }
		 else if(pos =='v'){
		 	player1ships[row-1][col-1] = 30 ;
		 	player1ships[row][col-1] = 'O';
		 	player1ships[row+1][col-1] = 31 ;
		 }	
	}
	else {
		   if(pos =='h'){
		 	player2ships[row-1][col-1] = 17 ;
		 	player2ships[row-1][col] = 'O';
		 	player2ships[row-1][col+1] = 16 ;
		 }
		 else if(pos =='v'){
		 	player2ships[row-1][col-1] = 30 ;
		 	player2ships[row][col-1] = 'O';
		 	player2ships[row+1][col-1] = 31 ;
			 }
		 }		
}

int checkNeigh(int row, int col){
	if(round0 % 2){
		return player2ships[row-2][col-1] != 30 && player2ships[row][col-1]!=31 && player2ships[row-1][col-2] != 17 && player2ships[row-1][col] != 16 ; 
	}
	else{
		return player1ships[row-2][col-1] != 30 && player1ships[row][col-1]!=31 && player1ships[row-1][col-2] != 17 && player1ships[row-1][col] != 16 ;
	}
}

void checkSink(int row, int col){
	if(round0 % 2){
		if(player2ships[row-1][col-1] == 'O' && checkNeigh(row, col)){
			numPlayer2Ships --;
		}
		else if(player2ships[row-1][col-1] == 30 && player2ships[row][col-1] == 'X' && player2ships[row+1][col-1] == 'X'){
			numPlayer2Ships --;
		}
		else if(player2ships[row-1][col-1] == 31 && player2ships[row-2][col-1] == 'X' && player2ships[row-3][col-1] == 'X'){
			numPlayer2Ships --;
		}
		else if(player2ships[row-1][col-1] == 16 && player2ships[row-1][col-2] == 'X' && player2ships[row-1][col-3] == 'X'){
			numPlayer2Ships --;
		}
		else if(player2ships[row-1][col-1] == 17 && player2ships[row-1][col] == 'X' && player2ships[row-1][col+1] == 'X'){
			numPlayer2Ships --;
		}
	}
	
	else{
		if(player1ships[row-1][col-1] == 'O' && checkNeigh(row, col)){
			numPlayer1Ships --;
		}
		else if(player1ships[row-1][col-1] == 30 && player1ships[row][col-1] == 'X' && player1ships[row+1][col-1] == 'X'){
			numPlayer1Ships --;
		}
		else if(player1ships[row-1][col-1] == 31 && player1ships[row-2][col-1] == 'X' && player1ships[row-3][col-1] == 'X'){
			numPlayer1Ships --;
		}
		else if(player1ships[row-1][col-1] == 16 && player1ships[row-1][col-2] == 'X' && player1ships[row-1][col-3] == 'X'){
			numPlayer1Ships --;
		}
		else if(player1ships[row-1][col-1] == 17 && player1ships[row-1][col] == 'X' && player1ships[row-1][col+1] == 'X'){
			numPlayer1Ships --;
		}
	}
}

void corAttack(){
	int row,col;
	scanf("%d %d",&row,&col);
	fprintf(infile,"%d %d\n", row, col);
	if(round0 % 2){
		if(player2ships[row-1][col-1] != ' '){
			checkSink(row, col);
			player2ships[row-1][col-1] = 'X';
			player1attacks[row-1][col-1] = 'X';
			printf("\a");
		}
	}
	else{
		if(player1ships[row-1][col-1] != ' '){
			checkSink(row, col);
			player1ships[row-1][col-1] = 'X';
			player2attacks[row-1][col-1] = 'X';
			printf("\a");
		}
	}
}

void ShowBoardFirst1(){//Showing the first player's board before the game starts
	char row='A';
	int i,j;
	printf("------------\n");
	printf("%s,This is your stupid board.\n",player1name);
	printf("   ");
	for(i=1; i<=size; i++){
		printf(" %d  ", i);
	}
	printf("\n  ");
	SetBlue();
	for(i=0; i<size; i++){
		printf("+---");
	}
	printf("+");
	SetBlack();
	
	for(i=0 ; i<size; i++){
		SetBlack();
		printf("\n%c ", row);
		SetBlue();
		printf("|", row);
		for(j=0; j<size; j++){
			printf(" %c |",player1ships[i][j]);
		}
		row++;
		SetBlack();
		printf("\n  ");
		SetBlue();
		for(int k=0; k<size; k++){
		printf("+---");
	}
	printf("+");
	SetBlack();

	}
	if(position1=='h'){
		 	player1ships[p1_row-1][p1_col-1] = 17 ;
		 	player1ships[p1_row-1][p1_col] = 'O';
		 	player1ships[p1_row-1][p1_col+1] = 16 ;
		 }
		 else if(position1=='v'){
		 	player1ships[p1_row-1][p1_col-1] = 30 ;
		 	player1ships[p1_row][p1_col-1] = 'O';
		 	player1ships[p1_row+1][p1_col-1] = 31 ;
		 }
}

void ShowBoardFirst2(){//Showing the second player's board before the game starts
	char row='A';
	int i,j;
	printf("------------\n");
	printf("%s,This is your stupid board.\n",player2name);
	printf("   ");
	for(i=1; i<=size; i++){
		printf(" %d  ", i);
	}
	printf("\n  ");
	SetBlue();
	for(i=0; i<size; i++){
		printf("+---");
	}
	printf("+");
	SetBlack();
	
	for(i=0 ; i<size; i++){
		SetBlack();
		printf("\n%c ", row);
		SetBlue();
		printf("|", row);
		for(j=0; j<size; j++){
			printf(" %c |",player2ships[i][j]);
		}
		row++;
		SetBlack();
		printf("\n  ");
		SetBlue();
		for(int k=0; k<size; k++){
		printf("+---");
	}
	printf("+");
	SetBlack();

	}
	if(position2=='h'){
		 	player2ships[p2_row-1][p2_col-1] = 17 ;
		 	player2ships[p2_row-1][p2_col] = 'O';
		 	player2ships[p2_row-1][p2_col+1] = 16 ;
		 }
		 else if(position2=='v'){
		 	player2ships[p2_row-1][p2_col-1] = 30 ;
		 	player2ships[p2_row][p2_col-1] = 'O';
		 	player2ships[p2_row+1][p2_col-1] = 31 ;
		 }
}

int checkSave(char order[]){//return 1 if player wants to save
	if(!strcmp(order,"save")){
		return 1;
	}
	return 0;
}

void savedGame(){
	int i, row, col;
	infile = fopen("inputt.txt","rt");
	if (!infile) {
      printf("can't open file!!!\n");
   }

   fscanf(infile ,"%d", &size);
   fscanf(infile, "%d", &k);
   fscanf(infile, "%s",player1name);
   for(i=0 ; i<k ; i++){
		fscanf(infile, "%d %d %c", &p1_row, &p1_col, &position1);
		placementships(p1_row, p1_col, position1, 1);
	}
	fscanf(infile, "%s",player2name);
	for(i=0 ; i<k ; i++){
		fscanf(infile, "%d %d %c", &p2_row, &p2_col, &position2);
		placementships(p2_row, p2_col, position2, 2);			
	}
	while(1){
		fscanf(infile, "%d %d",&row,&col);
		if(round0 % 2){
			if(player2ships[row-1][col-1] != ' '){
				checkSink(row, col);
				player2ships[row-1][col-1] = 'X';
				player1attacks[row-1][col-1] = 'X';
			}
		}
		else{
			if(player1ships[row-1][col-1] != ' '){
				checkSink(row, col);
				player1ships[row-1][col-1] = 'X';
				player2attacks[row-1][col-1] = 'X';
			}
		}
	}
	fclose(infile);
	infile = fopen("inputt.txt", "at");
}


int main(){
	int i, j, z;
	char row, order[10]; 
	

   printf("press c if you want to continue\n");
   gets(order);
   if(!strcmp("c", order)){
		savedGame();
	//	goto startingGame;
   }
   infile = fopen("inputt.txt","wt");
	if (!infile) {
      printf("can't open file!");
      return 0;
   }

	//getting inputs
	printf("give size\n");
	scanf("%d", &size);
	fprintf(infile,"%d \n",size);
	emptyships();//makes cells empty
	
	printf("Enter the number of your ships \n");
	scanf("%d", &k);
	fprintf(infile,"%d \n",k);
	numPlayer1Ships = k ;
	numPlayer2Ships = k ;
	
	printf("Enter the name of first player \n");
	playername(1);
	
	printf("Enter the coordinates of your ships \n");
	for(i=0 ; i<k ; i++){
		scanf("%d %d %c", &p1_row, &p1_col, &position1);
		if(checkShips(p1_row, p1_col, position1, 1)){
			fprintf(infile,"%d %d %c \n",p1_row,p1_col,position1);
			placementships(p1_row, p1_col, position1, 1);
		}
		else{
			printf("again\n");
			i--;
		}			
	}
	printf("--- \n");
	//fprintf(infile,"--- \n");
	printf("Enter the name of second player \n");
	playername(2);
	
	printf("Enter the coordinates of your ships \n");
	for(i=0 ; i<k ; i++){
		scanf("%d %d %c", &p2_row, &p2_col, &position2);
		if(checkShips(p2_row, p2_col, position2, 2)){
			fprintf(infile,"%d %d %c \n",p2_row,p2_col,position2);
			placementships(p2_row, p2_col, position2, 2);
		}
		else{
			printf("again\n");
			i--;
		}			
	}
	//**********************************************
	system("cls");
	ShowBoardFirst1();
	getch();
	system("cls");
	ShowBoardFirst2();
	getch();
	system("cls");

	//stratingGame :
		
while( numPlayer1Ships && numPlayer2Ships){
	round0 ++ ;
	row='A' ;
	char row='A';
	printf("  round : %d \n", round0);
	//printing first line include players' names
	pFirstLine();
	
	//printing second line include remaining ships
	pSecondLine();
	
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
	if(round0 % 2){
		printf("%s,Enter the coordinate of your Attack:",player1name);
	}
	else{
		printf("%s,Enter the coordinate of your Attack:",player2name);
	}
	corAttack();
	gets(order);
	if(checkSave(order)){
	//	fcloseall();
		system("cls");
		printf("game saved\n");
		getch();
		return 0;
	}
	system("cls");
}
	fclose(infile);
	if(numPlayer1Ships){
		printf("%s won!!!", player1name);
	}
	else{
		printf("%s won!!!", player2name);
	}
	getch();
	return 0;
}