#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int row, col; //khai bao 2 bien luu hang va cot
char board[10][10];//khoi tao bang tro choi 
int noOfMoves = 0;//khai bao bien de luu khi khong con o nao de dien buoc di
                                         
void HienThiBang()
{                
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j;
	// in ra dong dau tien la so cot
	printf("    ");
	for ( j = 0; j < col; j++)
	{
		printf("%d   ", j + 1);
	}
	printf("\n");

	for ( i = 0; i < row; i++)
	{
		printf("  ");
		for ( j = 0; j < col; j++)
		{
			SetConsoleTextAttribute(hConsole, 9);
			printf(" ---");
			
		}
		printf("\n");
		SetConsoleTextAttribute(hConsole, 15);
		printf("%d ", i + 1);
		SetConsoleTextAttribute(hConsole, 9);
		printf("|");
		SetConsoleTextAttribute(hConsole, 15);

		for ( j = 0; j < col; j++)
		{
			if (board[i][j] == ' ') 
			{
				printf("   ");
				SetConsoleTextAttribute(hConsole, 9);
				printf("|");
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				if (board[i][j] == 'X')
				{
					SetConsoleTextAttribute(hConsole, 2);
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 6);
				}
				printf(" %c ", board[i][j]);
				SetConsoleTextAttribute(hConsole, 9);
				printf("|");
				SetConsoleTextAttribute(hConsole, 15);
			}
		}
		printf("\n");
	}
	printf("  ");

	for ( j = 0; j < col; j++) 
	{
		SetConsoleTextAttribute(hConsole, 9);
		printf(" ---");
	}
	SetConsoleTextAttribute(hConsole, 15);
	printf("\n\n");
}

char gameStatus() 
{
	//Check dong cho chien thang
	int i, j;
	int isWin;
	for ( i = 0; i < row; i++)
	{
		isWin = 1;
		for ( j = 0; j < col-1; j++)
		{
			if (board[i][j] == ' ' || (board[i][j] != board[i][j + 1])) // dieu kien neu o kiem tra con trong hoac ky tu trong o do va o nam canh trong dong khong giong thi isWIN = 0
			{
				isWin = 0;
				break;
			}
		}
		if (isWin == 1)
			return board[i][j];// neu chien thang thi return 1 gia tri cuoi cung(hoac bat ky) tai dong do
	}
	//Check cot cho chien thang
	for (i = 0; i < col; i++)
	{
		isWin = 1;
		for (j = 0; j < row - 1; j++)
		{
			if (board[j][i] == ' ' || (board[j][i] != board[j+1][i]))
			{
				isWin = 0;
				break;
			}
		}
		if (isWin == 1)
			return board[j][i];// neu chien thang thi return 1 gia tri cuoi cung(hoac bat ky) tai cot do
	}
	
	//Check duong cheo chinh
	isWin = 1;
	for ( i = 0; i < row - 1; i++)
	{
		if (board[i][i] == ' ' || (board[i][i] != board[i + 1][i + 1]))
		{
			isWin = 0;
			break;
		}
	}
	if (isWin == 1)
		return board[i][i];// neu chien thang thi chi return 1 gia tri bat ky tren duong cheo chinh
		
	//Check duong cheo phu
	isWin = 1;
	for ( i = 0; i < row - 1; i++)
	{
		if (board[i][row - i - 1] == ' ' || (board[i][row - i - 1] != board[i + 1][row - i -2]))
		{
			isWin = 0;
			break;
		}
	}
	if (isWin == 1)
		return board[0][row - 1];// neu chien thang thi chi return 1 gia tri bat ky tren duong cheo phu

	if (noOfMoves < (row*col))
		return 'C';// tiep tuc tro choi

	return 'D';// Hoa, khong ai chien thang
}

int checkWin(char player) 
{
	char status = gameStatus();

	if (status == player) 
	{
		if(player == 'X')
			printf("Nguoi choi 1(X) chien thang!\n");
		else
			printf("Nguoi choi 2(O) chien thang!\n");
		return 1;
	}
	else if (status == 'D') 
	{
		printf("Tro choi ket thuc voi ket qua la hoa!\n");
		return 1;
	}
	else if (status == 'C') 
	{
		return 0;
	}
	else
		return 1;
}

int kiemTraNhap(int x, int y) 
{
	if (0 <= x && x <= (row-1) && 0 <= y && y <= (col-1) && board[x][y] == ' ')
		return 1;// nhap hop le
	else
		return 0;//nhap khong hop le
}

void NhapXY(char player, int *x, int *y) {
	do {
		printf("Luot nguoi choi %c nhap: ", player);
		printf("\nNHAP HANG : ");
		scanf("%d",&*x);
		printf("NHAP COT : ");
		scanf("%d", &*y);
		*x = *x - 1;
		*y = *y - 1;
	} while (0 == kiemTraNhap(*x, *y));//nhap sai thi nhap lai
	return;
}

void ThemVaoBoard(char player, int x, int y)
{
	if (0 == kiemTraNhap(x, y))
		return;

	board[x][y] = player;
	noOfMoves++;
}

void KhoiTaoBang(){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	printf("MOI NHAP KICH THUOC TRO CHOI ");
	SetConsoleTextAttribute(hConsole, 13);
	printf("\n\t\t\t\t\t\t\t3. [3x3]\n");
	SetConsoleTextAttribute(hConsole, 9);
	printf("\n\t\t\t\t\t\t\t4. [4x4]\n");
	SetConsoleTextAttribute(hConsole, 14);
	printf("\n\t\t\t\t\t\t\t5. [5x5]\n");
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n\t\t\t\t\t\t\t6. [6x6]\n");
	SetConsoleTextAttribute(hConsole, 12);
	printf("\n\t\t\t\t\t\t\t7. [7x7]\n");
	SetConsoleTextAttribute(hConsole, 3);
	printf("\n\t\t\t\t\t\t\t8. [8x8]\n");
	SetConsoleTextAttribute(hConsole, 5);
	printf("\n\t\t\t\t\t\t\t9. [9x9]\n");
	SetConsoleTextAttribute(hConsole, 15);
	scanf("%d", &row);
	col = row ;
	int i, j;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
typedef struct Nguoichoi{
	char player1[30];
	char player2[30];
}player;
void NhapPlayer(player &a){
	printf("\t\t\t\t\t\tMOI NHAP TEN NGUOI CHOI THU 1 : ");
	fflush(stdin);
	gets(a.player1);
	printf("\t\t\t\t\t\tMOI NHAP TEN NGUOI CHOI THU 2 : ");
	fflush(stdin);
	gets(a.player2);
}
void XuatPlayer(player a){
	printf("\t\t\t\t\t\t***** TEN NGUOI CHOI THU 1 : %s *****\n",a.player1);
	printf("\t\t\t\t\t\t***** TEN NGUOI CHOI THU 2 : %s *****",a.player2);
}

void Xuatfile(player a,int n){
	char kt;
	kt = gameStatus();
	FILE *fp;
	fp = fopen("D:\\Bai tap lon\\WINER.txt","w");
	fprintf(fp,"SO THU TU\t");
	fprintf(fp,"TEN NGUOI THANG\t");
	for(int i=0;i<n;++i){
		fprintf(fp,"\n%d",i+1);
		if(kt == 'X'){
			fprintf(fp,"\t\t%s",a.player1);
		}else if(kt == 'O'){
			fprintf(fp,"\t\t%s",a.player2);
		}	
	}
	fclose(fp);
}
void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}
