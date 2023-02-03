#include <stdio.h>
#include<windows.h>
#include <conio.h>
#include<string.h>
#define Size 9
#define color1 15//nembers 15
#define color2 31//waves 31
#define player1 FOCP1
#define player2 FOCP2

int size,round,  numPlayer1Ships, numPlayer2Ships,p1_row,p1_col,p2_row,p2_col,nrange,tool1,arz1,tool2,arz2,k1,k2,full1=0,full2=0,nrep1,nrep2;
char player1name[20], player2name[20], player1ships[Size][Size], player2ships[Size][Size], player1attacks[Size][Size], player2attacks[Size][Size],position1,position2,joda[10],rp[10];
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
FILE *infile;

void pFirstLine(){
if(round % 2){
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
	if(round %2){
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

int checkShips(int i, int j,int tool,int arz, char code, int player){//col cordinate, row cordinate , possition, player 1or 2
    int k,s;
    if(code == 'h' && j+arz-2 <= size && i+tool-2 <= size){
        if(player == 1){
        		for(k=i;k < i+arz-1 ; k++){
        			for(s=j ; s < j+tool-1 ;s++){
        				if(player1ships[k-1][s-1] != ' '){
        					return 0;//Error
						}
					}
				}
				return 1;
		}
        else if(player == 2){
            for(k=i;k < i+arz-1 ; k++){
        			for(s=j ; s < j+tool-1 ;s++){
        				if(player2ships[k-1][s-1] != ' '){
        					return 0;//Error
						}
					}
				}
			return 1;
        }
    }
    else if(code == 'v' && i+tool-2 <= size && j+arz-2 <= size){
        if(player == 1){
            for(k=i ; k < tool+i-1 ; k++){
            	for(s=j ; s < arz+j-1 ; s++){
            		if(player1ships[k-1][s-1] != ' '){
            			return 0;//Error
					}
				}
			}
			return 1;
		}
        if(player == 2){
            for(k=i ; k < tool+i-1 ; k++){
            	for(s=j ; s < arz+j-1 ; s++){
            		if(player2ships[k-1][s-1] != ' '){
            			return 0;//Error
					}
				}
			}
			return 1;
        }
    }
    return 0;//overFlow or wrong code 
}

void placementships(int row, int col, char pos,int tool,int arz, int code){//making ships
	int i,j;
	//for player1
	if(code==1){
		//****
		if(tool == 1 && arz == 1){
			player1ships[row-1][col-1] = 'O';
		}
		//****
		else if(arz == 1 && pos == 'h'){
			player1ships[row-1][col-1] = 17;
			for(i=0;i<tool-2;i++){
				player1ships[row-1][col+i] = 'O';
			}
			player1ships[row-1][col+tool-2] = 16;
		}
		//****
		else if(arz == 1 && pos == 'v'){
			player1ships[row-1][col-1] = 30;
			for(int i=0;i<tool-2;i++){
				player1ships[row+i][col-1] = 'O';
			}
			player1ships[row+arz-2][col-1] = 31;
		}
		//****
		else if(pos == 'h'){
			for(int i=-1;i<tool-1;i++){
				player1ships[row-1][col+i] = 30;
				player1ships[arz+row-2][col+i] = 31; 
			}
			for(int j=0;j<arz-2;j++){
				player1ships[row+j][col-1] = 17;
				for(int s=0;s<tool-2;s++){
				player1ships[row+j][col+s] = 'O';	
				}
				player1ships[row+j][col+tool-2] = 16;
			}
		}
		//****
		else if(pos == 'v'){
			for(int i=-1;i<tool-1;i++){
				player1ships[row+i][col-1] = 17;
				player1ships[row+i][col+arz-2] = 16;
			}
			for(int j=0;j<arz-2;j++){
				player1ships[row-1][col+j] = 30;
				for(int s=0;s<arz-2;s++){
					player1ships[row+j][col+s] = 'O';
				}
				player1ships[row+tool-2][col+j] = 31;
			}
		}
    } 
	//for player2
	else {
		//****
		if(tool == 1 && arz == 1){
			player2ships[row-1][col-1] = 'O';
		}
		//****
		else if(arz == 1 && pos == 'h'){
			player2ships[row-1][col-1] = 17;
			for(i=0;i<tool-2;i++){
				player2ships[row-1][col+i] = 'O';
			}
			player2ships[row-1][col+tool-2] = 16;
		}
		//****
		else if(arz == 1 && pos == 'v'){
			player2ships[row-1][col-1] = 30;
			for(int i=0;i<tool-2;i++){
				player2ships[row+i][col-1] = 'O';
			}
			player2ships[row+arz-2][col-1] = 31;
		}
		//****
		else if(pos == 'h'){
			for(int i=-1;i<tool-1;i++){
				player1ships[row-1][col+i] = 30;
				player1ships[arz+row-2][col+i] = 31; 
			}
			for(int j=0;j<arz-2;j++){
				player1ships[row+j][col-1] = 17;
				for(int s=0;s<tool-2;s++){
				player1ships[row+j][col+s] = 'O';	
				}
				player1ships[row+j][col+tool-2] = 16;
			}
		}
		//****
		else if(pos == 'v'){
			for(int i=-1;i<tool-1;i++){
				player2ships[row+i][col-1] = 17;
				player2ships[row+i][col+arz-2] = 16;
			}
			for(int j=0;j<arz-2;j++){
				player2ships[row-1][col+j] = 30;
				for(int s=0;s<arz-2;s++){
					player2ships[row+j][col+s] = 'O';
				}
				player2ships[row+tool-2][col+j] = 31;
			}
		}
    }
}

/*int checkNeigh(int row, int col){
	if(round % 2){
		return player2ships[row-2][col-1] != 30 && player2ships[row][col-1]!=31 && player2ships[row-1][col-2] != 17 && player2ships[row-1][col] != 16 ; 
	}
	else{
		return player1ships[row-2][col-1] != 30 && player1ships[row][col-1]!=31 && player1ships[row-1][col-2] != 17 && player1ships[row-1][col] != 16 ;
	}
}*/

/*void checkSink(int row, int col){
	if(round % 2){
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
}*/

void corAttack(){//attack to
	int row,col;
	scanf("%d %d",&row,&col);
	if(round % 2){
		if(player2ships[row-1][col-1] != ' '){
			/*checkSink(row, col);*/
			player2ships[row-1][col-1] = 'X';
			player1attacks[row-1][col-1] = 'X';
			printf("\a");
		}
	}
	else{
		if(player1ships[row-1][col-1] != ' '){
			/*checkSink(row, col);*/
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
	printf("%s,This is your board.\n",player1name);
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
	placementships(p1_row,p1_col,position1,tool1,arz1,1);
}

void ShowBoardFirst2(){//Showing the second player's board before the game starts
	char row='A';
	int i,j;
	printf("------------\n");
	printf("%s,This is your board.\n",player2name);
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
	placementships(p2_row,p2_col,position2,tool2,arz2,2);
}

void getShips1(int k){//placing ships in the order player1
	int i;
	printf("Enter the coordinates of your ships \n");
	for(i=1 ; i<=k ; i++){	
	scanf("%d %d %c",&p1_row,&p1_col,&position1);
	fscanf(infile,"%d %d %c",&p1_row,&p1_col,&position1);
		if(checkShips(p1_row, p1_col,tool1,arz1, position1, 1) != 0){
			placementships(p1_row, p1_col, position1,tool1,arz1, 1);
		}
		else{
			printf("again\n");
			i--;
		}
	}
}

void getShips2(int k){//placing ships in the order player2
	int i;
	printf("Enter the coordinates of your ships \n");
	for(i=1 ; i<=k ; i++){	
	scanf("%d %d %c",&p2_row,&p2_col,&position2);
	fscanf(infile,"%d %d %c",&p2_row,&p2_col,&position2);
		if(checkShips(p2_row, p2_col,tool2,arz2, position2, 2) != 0){
			placementships(p2_row, p2_col, position2,tool2,arz2,2);
		}
		else{
			printf("again\n");
			i--;
		}
	}
}
void inputDim1(){//getting the size and number of ships player1
	int temp;
	printf("Enter the dimensions of your ships and their number \n");
	scanf("%d %d %d",&tool1,&arz1,&k1);
	if(arz1 > tool1){
		temp = arz1;
		arz1 = tool1;
		tool1 = temp;
	}
}

void inputDim2(){//getting the size and number of ships player2
	int temp;
	printf("Enter the dimensions of your ships and their number \n");
	scanf("%d %d %d",&tool2,&arz2,&k2);
	if(arz2 > tool2){
		temp = arz2;
		arz2 = tool2;
		tool2 = temp;
	}
}
int checkNum(int n,int tool,int arz,int code){//Checking the number of allowed houses
	if(code == 1){
	full1 += tool*arz;
	   if(full1 > n){
		full1 -= tool*arz;
		return 0;//Error
	    }
	   else{
		return 1;
	    }  	
	}
	else{
	full2 += tool*arz;
	   if(full2 > n){
		full2 -= tool*arz;
		return 0;//Error
	    }
	   else{
		return 1;
	    }		
	}
}

void repair(int code,int nrep1,int nrep2){//repairing a attacked house
	int row,col;
	scanf("%d %d",&row,&col);
	if(code==1 && nrep1 != 0){
	  if(player1ships[row-1][col-1] == 'X'){
		player1ships[row-1][col-1] = 'R';
		nrep1--;
	  }
	  else if(player1ships[row-1][col-1] != ' '){
		printf("This house is safe");
	  }
	  else{
		printf("There is no ship in this house");
	  }	
	}
	else if(code==2 && nrep2 != 0){
	  if(player2ships[row-1][col-1] == 'X'){
		player2ships[row-1][col-1] = 'R';
		nrep2--;
	  }
	  else if(player2ships[row-1][col-1] != ' '){
		printf("This house is safe");
	  }
	  else{
		printf("There is no ship in this house");
	  }	
	}	
}

int main(){
	int i, j,temp,full;
	char row,plus; 
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
	
	printf("Enter the allowed number of ship houses \n");
	scanf("%d", &nrange);
	/*fprintf(infile,"%d \n",k);
	numPlayer1Ships = k ;
	numPlayer2Ships = k ;*/
	
	printf("Enter the name of first player \n");
	playername(1);
	
	do{
		inputDim1();
		while(checkNum(nrange,tool1,arz1,1) == 0){
			printf("The number of houses is more than the limit! \n");
			inputDim1();
		}
		getShips1(k1);
		printf("If you want to add another ship, enter '$$$' else enter '---' \n");
		scanf("%s",joda);	
	}
	while(strcmp(joda,"$$$") == 0);
	//*******
	printf("Enter the name of second player \n");
	playername(2);
	
	do{
		inputDim2();
		while(checkNum(nrange,tool2,arz2,2) == 0){
			printf("The number of houses is more than the limit! \n");
			inputDim2();
		}
		getShips2(k2);
		printf("If you want to add another ship, enter '$$$' else enter '---' \n");
		scanf("%s",joda);	
	}
	while(strcmp(joda,"$$$") == 0);
	printf("Enter the number of houses that can be repaired: ");
	scanf("%d",&nrep1);
	nrep2 = nrep1;
	
	fclose(infile);
	//**********************************************
    system("cls");
	ShowBoardFirst1();
	getch();
	system("cls");
	ShowBoardFirst2();
	getch();
	system("cls");
		
while( numPlayer1Ships && numPlayer2Ships){
	round ++ ;
	row='A' ;
	char row='A';
	printf("  round : %d \n", round);
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
	//attack to or repair a house
	if(round % 2){
		printf("attack or repair? \n");
		scanf("%s",rp);
		if(strcmp(rp,"attack") == 0){
		printf("%s,Enter the coordinate of your Attack: ",player1name);
		corAttack();	
		}
		else{
			printf("%s ,Enter the coordinates of the house you want to repair: ",player1name);
		repair(1,nrep1,nrep2);	
		}
	}
	else{
	    printf("attack or repair? \n");
		scanf("%s",rp);
		if(strcmp(rp,"attack") == 0){
		printf("%s,Enter the coordinate of your Attack:",player2name);
		corAttack();	
		}
		else{
			printf("%s ,Enter the coordinates of the house you want to repair: ",player2name);
		repair(2,nrep1,nrep2);	
		}
	}
	getch();
	system("cls");
}
	if(numPlayer1Ships){
		printf("%s won!!!", player1name);
	}
	else{
		printf("%s won!!!", player2name);
	}
}