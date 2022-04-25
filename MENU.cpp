#include "mylibrary.h"

int main(){
	int k,n;
	player a;
	//bool KT = false;
	while(true){
		system("cls");
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		GoTo(43,7);
		SetConsoleTextAttribute(hConsole, 11);
		printf("=====================================\n");
		GoTo(43,8);
		printf("||            1.CHOI               ||\n");
		GoTo(43,9);
		printf("||            2.LICH SU            ||\n");
		GoTo(43,10);
		printf("||            3.THOAT              ||\n");
		GoTo(43,11);
		printf("=====================================\n");
		GoTo(50,12);
		printf("NHAP LUA CHON CUA BAN : ");
		scanf("%d",&k);
		system("cls");
		switch(k){
			case 1:
				GoTo(52,4);
				printf("BAN DA LUA CHON CHOI\n");
				HANDLE  hConsole;
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 2);
				GoTo(35,6);
				printf("==================== TIC TAC TOE =====================");
				SetConsoleTextAttribute(hConsole, 3);
				GoTo(30,7);
				printf("---------------Nguoi choi 1 (X) - Nguoi choi 2 (O)--------------");
				SetConsoleTextAttribute(hConsole, 15);//tra ve mau trang
				GoTo(0,8);
				NhapPlayer(a);
				GoTo(0,8);
				XuatPlayer(a);
				GoTo(48,10);
				KhoiTaoBang();
				GoTo(55,11);
				printf("            ");
				GoTo(55,13);
				printf("            ");
				GoTo(55,15);
				printf("            ");
				GoTo(55,17);
				printf("            ");
				GoTo(55,19);
				printf("            ");
				GoTo(55,21);
				printf("            ");
				GoTo(55,23);
				printf("            ");
				GoTo(0,24);
				printf("            ");
				GoTo(30,10);
				printf("----------------------------------------------------------------\n");
				HienThiBang();
				while (1) {
					int x, y;
					NhapXY('X', &x, &y);//Nguoi choi dau tien nhap
					ThemVaoBoard('X', x, y);//Nhap xong them vao bang
					system("cls");
					printf("Nguoi choi X chon 1(%d,%d) \n", x+1, y+1);
					HienThiBang();
					if (checkWin('X') == 1)
				break;

					NhapXY('O', &x, &y);
					ThemVaoBoard('O', x, y);
					system("cls");
					printf("Nguoi choi O chon (%d,%d) \n", x + 1, y + 1);
					HienThiBang();
					if (checkWin('O') == 1)
				break;
				}
				noOfMoves = 0;
				_getch();
				break;
			case 2:
				printf("\nBAN DA LUA CHON XEM LICH SU\n");
				printf("NHAP SO LUONG XUAT DANH SACH : ");
				scanf("%d",&n);
				Xuatfile(a,n);
				getch();
				break;
			case 3:
				printf("\nBAN DA LUA CHON THOAT CHUONG TRINH!!!\n");
				return 0;
		}
	}
}




