#include<iostream>
#include<time.h>
#include<conio.h>
#include<string>
#include<Windows.h>
using namespace std;

void start();
void howto();
void cardShuffle();
void Display1();
void Display2();
void selectPlay1();
void selectPlay2();
string front = "  ";

void start() {
	printf("■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■■                                  ■■\n");
	printf("■■                                  ■■\n");
	printf("■■                                  ■■\n");
	printf("■■   ___           ___  ___         ■■\n");
	printf("■■  |     |       _|__ _|__  |      ■■\n");
	printf("■■  |___  |__      |    |    |  __  ■■\n");
	printf("■■      | |  ||  | |    |    | |__| ■■\n");
	printf("■■  ____| |  ||__| |    |    | |___ ■■\n");
	printf("■■                                  ■■\n");
	printf("■■                                  ■■\n");
	printf("■■      ____               |        ■■\n");
	printf("■■     |      __  |___  ___|        ■■\n");
	printf("■■     |      __| |    |   |        ■■\n");
	printf("■■     |____ |__| |    |___|        ■■\n");
	printf("■■                                  ■■\n");
	printf("■■                                  ■■\n");
	printf("■■                                  ■■\n");
	printf("■■                                  ■■\n");
	printf("■■          시작하려면              ■■\n");
	printf("■■       아무 키나 누르세요         ■■\n");
	printf("■■                                  ■■\n");
	printf("■■                                  ■■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■\n");

	_getch();
	fflush(stdin);
	system("cls");

	howto();
};

void howto() {
	printf("■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■■                                  ■■\n");
	printf("■■         1   2   3   4   5        ■■\n");
	printf("■■         2   2   3   4   5        ■■\n");
	printf("■■         3   2   3   4   5        ■■\n");
	printf("■■         4   2   3   4   5        ■■\n");
	printf("■■                                  ■■\n");
	printf("■■                                  ■■\n");
	printf("■■  순서대로 나열되어 있는 카드를   ■■\n");
	printf("■■         골라 뒤집어 보자!        ■■\n");
	printf("■■      행과 열을 차례로 쓴 후      ■■\n");
	printf("■■       스페이스바를 누른다!       ■■\n");
	printf("■■  이때, 반드시 행과 열 사이에는   ■■\n");
	printf("■■     한 칸의 공백이 필요하다!     ■■\n");
	printf("■■      최대한 적은 횟수 내에       ■■\n");
	printf("■■      카드의 짝을 맞춰보자!!      ■■\n");
	printf("■■                                  ■■\n");
	printf("■■                                  ■■\n");
	printf("■■          시작하려면              ■■\n");
	printf("■■       아무 키나 누르세요         ■■\n");
	printf("■■                                  ■■\n");
	printf("■■                                  ■■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■\n");

	_getch();
	fflush(stdin);
};

int end(int playCount) {
	printf("축하합니다!\n");
	printf("%d번 만에 성공하셨습니다!", playCount);
	return 0;
}

string back[4][5] = { { "★","●","◆","■","▲" },
					  { "♠","♥","♣","☎","♨" },
					  { "★","●","◆","■","▲" },
					  { "♠","♥","♣","☎","♨" } };

int result[4][5] = { { 0, 1, 2, 3, 4 },
					 { 5, 6, 7, 8, 9 },
					 { 0, 1, 2, 3, 4 },
					 { 5, 6, 7, 8, 9 } };

int openCard[4][5] = { { 0 } };

int resultX1 = 5, resultY1 = 6, resultX2 = 5, resultY2 = 6;

int playCount = 0;
int openCount = 0;

void cardShuffle() {
	srand(time(NULL));
	int row1, row2, col1, col2;

	for (int i = 0;i < 1000; i++) {
		row1 = rand() % 4;
		row2 = rand() % 4;

		col1 = rand() % 5;
		col2 = rand() % 5;

		swap(back[row1][col1], back[row2][col2]);
		swap(result[row1][col1], result[row2][col2]);
	}
}

void Display1() {
	system("cls");

	cout << endl;
	cout << "                   카드 뒤집기 게임" << endl;
	cout << " 뒤집은 횟수 : " << playCount << endl;
	cout << " ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;


	cout << "  ┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐" << endl;
	cout << "  │ ";

	if ((resultX1 == 0 && resultY1 == 0) || (resultX2 == 0 && resultY2 == 0) || openCard[0][0] == 1) { cout << back[0][0]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 0 && resultY1 == 1) || (resultX2 == 0 && resultY2 == 1) || openCard[0][1] == 1) { cout << back[0][1]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 0 && resultY1 == 2) || (resultX2 == 0 && resultY2 == 2) || openCard[0][2] == 1) { cout << back[0][2]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 0 && resultY1 == 3) || (resultX2 == 0 && resultY2 == 3) || openCard[0][3] == 1) { cout << back[0][3]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 0 && resultY1 == 4) || (resultX2 == 0 && resultY2 == 4) || openCard[0][4] == 1) { cout << back[0][4]; }
	else { cout << front; }

	cout << "│" << endl;
	cout << "  └───┘ └───┘ └───┘ └───┘ └───┘" << endl;



	cout << "  ┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐" << endl;
	cout << "  │ ";

	if ((resultX1 == 1 && resultY1 == 0) || (resultX2 == 1 && resultY2 == 0) || openCard[1][0] == 1) { cout << back[1][0]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 1 && resultY1 == 1) || (resultX2 == 1 && resultY2 == 1) || openCard[1][1] == 1) { cout << back[1][1]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 1 && resultY1 == 2) || (resultX2 == 1 && resultY2 == 2) || openCard[1][2] == 1) { cout << back[1][2]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 1 && resultY1 == 3) || (resultX2 == 1 && resultY2 == 3) || openCard[1][3] == 1) { cout << back[1][3]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 1 && resultY1 == 4) || (resultX2 == 1 && resultY2 == 4) || openCard[1][4] == 1) { cout << back[1][4]; }
	else { cout << front; }

	cout << "│" << endl;
	cout << "  └───┘ └───┘ └───┘ └───┘ └───┘" << endl;



	cout << "  ┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐" << endl;
	cout << "  │ ";

	if ((resultX1 == 2 && resultY1 == 0) || (resultX2 == 2 && resultY2 == 0) || openCard[2][0] == 1) { cout << back[2][0]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 2 && resultY1 == 1) || (resultX2 == 2 && resultY2 == 1) || openCard[2][1] == 1) { cout << back[2][1]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 2 && resultY1 == 2) || (resultX2 == 2 && resultY2 == 2) || openCard[2][2] == 1) { cout << back[2][2]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 2 && resultY1 == 3) || (resultX2 == 2 && resultY2 == 3) || openCard[2][3] == 1) { cout << back[2][3]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 2 && resultY1 == 4) || (resultX2 == 2 && resultY2 == 4) || openCard[2][4] == 1) { cout << back[2][4]; }
	else { cout << front; }

	cout << "│" << endl;
	cout << "  └───┘ └───┘ └───┘ └───┘ └───┘" << endl;



	cout << "  ┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐" << endl;
	cout << "  │ ";

	if ((resultX1 == 3 && resultY1 == 0) || (resultX2 == 3 && resultY2 == 0) || openCard[3][0] == 1) { cout << back[3][0]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 3 && resultY1 == 1) || (resultX2 == 3 && resultY2 == 1) || openCard[3][1] == 1) { cout << back[3][1]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 3 && resultY1 == 2) || (resultX2 == 3 && resultY2 == 2) || openCard[3][2] == 1) { cout << back[3][2]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 3 && resultY1 == 3) || (resultX2 == 3 && resultY2 == 3) || openCard[3][3] == 1) { cout << back[3][3]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 3 && resultY1 == 4) || (resultX2 == 3 && resultY2 == 4) || openCard[3][4] == 1) { cout << back[3][4]; }
	else { cout << front; }

	cout << "│" << endl;
	cout << "  └───┘ └───┘ └───┘ └───┘ └───┘" << endl;
	cout << " ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

}

void selectPlay1() {
	int x, y;	// 0행 0열이 아닌 1행 1열로 시작하게 하기 위한 변수

	cout << " 1번째 뒤집을 카드를 선택하세요 ( ex) 1 1 ~ 4 5 ) : ";
	cin >> x >> y;

	resultX1 = x - 1;
	resultY1 = y - 1;

	while (resultX1 > 3 || resultX1 < 0 || resultY1 > 4 || resultY1 < 0 || openCard[resultX1][resultY1] == 1) {
		cout << " 잘못입력하셨거나 이미 오픈된 카드입니다." << endl;
		cout << " 1번째 뒤집을 카드를 재선택하세요 ( ex) 1 1 ~ 4 5 ) : ";
		cin >> x >> y;

		resultX1 = x - 1;
		resultY1 = y - 1;
	}
}

void selectPlay2() {
	playCount++;	// 입력할때마다 증가

	int x, y;		// 0행 0열이 아닌 1행 1열로 시작하게 하기 위한 변수

	cout << " 2번째 뒤집을 카드를 선택하세요 ( ex) 1 1 ~ 4 5 ) : ";
	cin >> x >> y;

	resultX2 = x - 1;
	resultY2 = y - 1;

	while (resultX2 > 3 || resultX2 < 0 || resultY2 > 4 || resultY2 < 0 || openCard[resultX2][resultY2] == 1 || (resultX1 == resultX2 && resultY1 == resultY2)) {
		cout << " 잘못입력하셨거나 이미 오픈된 카드입니다." << endl;
		cout << " 2번째 뒤집을 카드를 재선택하세요 ( ex) 1 1 ~ 4 5 ) : ";
		cin >> x >> y;

		resultX2 = x - 1;
		resultY2 = y - 1;
	}

	// 카드를 맞추었다면 
	if (result[resultX1][resultY1] == result[resultX2][resultY2]) {
		openCard[resultX1][resultY1] = 1;
		openCard[resultX2][resultY2] = 1;
		openCount += 2;
	}
}

void Display2() {
	system("cls");

	cout << endl;
	cout << "                카드 뒤집기 게임" << endl;
	cout << " 뒤집은 횟수 : " << playCount << endl;
	cout << " ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

	cout << "  ┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐" << endl;
	cout << "  │ ";

	if ((resultX1 == 0 && resultY1 == 0) || (resultX2 == 0 && resultY2 == 0) || openCard[0][0] == 1) { cout << back[0][0]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 0 && resultY1 == 1) || (resultX2 == 0 && resultY2 == 1) || openCard[0][1] == 1) { cout << back[0][1]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 0 && resultY1 == 2) || (resultX2 == 0 && resultY2 == 2) || openCard[0][2] == 1) { cout << back[0][2]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 0 && resultY1 == 3) || (resultX2 == 0 && resultY2 == 3) || openCard[0][3] == 1) { cout << back[0][3]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 0 && resultY1 == 4) || (resultX2 == 0 && resultY2 == 4) || openCard[0][4] == 1) { cout << back[0][4]; }
	else { cout << front; }

	cout << "│" << endl;
	cout << "  └───┘ └───┘ └───┘ └───┘ └───┘" << endl;



	cout << "  ┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐" << endl;
	cout << "  │ ";

	if ((resultX1 == 1 && resultY1 == 0) || (resultX2 == 1 && resultY2 == 0) || openCard[1][0] == 1) { cout << back[1][0]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 1 && resultY1 == 1) || (resultX2 == 1 && resultY2 == 1) || openCard[1][1] == 1) { cout << back[1][1]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 1 && resultY1 == 2) || (resultX2 == 1 && resultY2 == 2) || openCard[1][2] == 1) { cout << back[1][2]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 1 && resultY1 == 3) || (resultX2 == 1 && resultY2 == 3) || openCard[1][3] == 1) { cout << back[1][3]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 1 && resultY1 == 4) || (resultX2 == 1 && resultY2 == 4) || openCard[1][4] == 1) { cout << back[1][4]; }
	else { cout << front; }

	cout << "│" << endl;
	cout << "  └───┘ └───┘ └───┘ └───┘ └───┘" << endl;



	cout << "  ┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐" << endl;
	cout << "  │ ";

	if ((resultX1 == 2 && resultY1 == 0) || (resultX2 == 2 && resultY2 == 0) || openCard[2][0] == 1) { cout << back[2][0]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 2 && resultY1 == 1) || (resultX2 == 2 && resultY2 == 1) || openCard[2][1] == 1) { cout << back[2][1]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 2 && resultY1 == 2) || (resultX2 == 2 && resultY2 == 2) || openCard[2][2] == 1) { cout << back[2][2]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 2 && resultY1 == 3) || (resultX2 == 2 && resultY2 == 3) || openCard[2][3] == 1) { cout << back[2][3]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 2 && resultY1 == 4) || (resultX2 == 2 && resultY2 == 4) || openCard[2][4] == 1) { cout << back[2][4]; }
	else { cout << front; }

	cout << "│" << endl;
	cout << "  └───┘ └───┘ └───┘ └───┘ └───┘" << endl;



	cout << "  ┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐" << endl;
	cout << "  │ ";

	if ((resultX1 == 3 && resultY1 == 0) || (resultX2 == 3 && resultY2 == 0) || openCard[3][0] == 1) { cout << back[3][0]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 3 && resultY1 == 1) || (resultX2 == 3 && resultY2 == 1) || openCard[3][1] == 1) { cout << back[3][1]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 3 && resultY1 == 2) || (resultX2 == 3 && resultY2 == 2) || openCard[3][2] == 1) { cout << back[3][2]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 3 && resultY1 == 3) || (resultX2 == 3 && resultY2 == 3) || openCard[3][3] == 1) { cout << back[3][3]; }
	else { cout << front; }

	cout << "│ │ ";

	if ((resultX1 == 3 && resultY1 == 4) || (resultX2 == 3 && resultY2 == 4) || openCard[3][4] == 1) { cout << back[3][4]; }
	else { cout << front; }

	cout << "│" << endl;
	cout << "  └───┘ └───┘ └───┘ └───┘ └───┘" << endl;
	cout << " ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

	Sleep(1000);

	resultX1 = 5;
	resultY1 = 6;
	resultX2 = 5;
	resultY2 = 6;
}

int main() {
	start();
	
	_getch();

	cardShuffle();

	while (true) {
		Display1();
		selectPlay1();
		Display1();
		selectPlay2();
		Display2();

		if (openCount == 20) break;
	}

	Display1();
	end(playCount);

	return 0;
}