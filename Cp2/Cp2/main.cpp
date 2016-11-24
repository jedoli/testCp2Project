#include <process.h>
#include <iostream>
#include <windows.h>
#include "Frame.h"
using namespace std;
class KeyEvent {
private:
	HANDLE hln;
	COORD KeyWhere;
	DWORD EventCount;
	INPUT_RECORD InRec;
	DWORD NumRead;
	int downKey;

public:
	KeyEvent() {
		hln = GetStdHandle(STD_INPUT_HANDLE);
		EventCount = 1;
	}

	int getkey() {
		ReadConsoleInput(hln, &InRec, 1, &NumRead);
		if (InRec.EventType == KEY_EVENT) {
			if (InRec.Event.KeyEvent.bKeyDown) {
				downKey = InRec.Event.KeyEvent.wVirtualKeyCode;
				return downKey;
			}
			else
				return -1;
		}
		return -1;
	}

};

/*
unsigned int __stdcall mythread(void*) {
	int i = 0;
	while (1) {
		cout << GetCurrentThread() << ": " << i++ << endl;
		Sleep(500);
	}
	return 0;
}

unsigned int __stdcall keyEvent(void*) {
	KeyEvent k;
	int i;
	while (1) {
		i = k.getkey();
		switch (i) {
		case 37: cout << "Left" << endl; break;
		case 38: cout << "Up" << endl; break;
		case 39: cout << "Right" << endl; break;
		case 40: cout << "Down" << endl; break;
		}
	}
	return 0;
}
*/

class Game {
private:
	int x;
	int y;
	int direction;
	void gotoXY(int x, int y) {
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

public:
	Game() {
		x = 5;
		y = 5;
		direction = 0;
	}
	void setDirection(int i) {
		direction = i;
	}
	void move() {
		if (direction == 37) {
			x--;
		}
		else if (direction == 38) {
			y--;
		}
		else if (direction == 39) {
			x++;
		}
		else if (direction == 40) {
			y++;
		}
		system("cls");
		this->gotoXY(x, y);
		cout << x << " " << y;
		cout << "бс";
	}
};
	Game* game = new Game();
	unsigned int __stdcall mythread(void*) {
		int i = 0;
		while (1) {
			game->move();
			Sleep(500);
		}
		return 0;
	}
	unsigned int __stdcall keyEvent(void*) {
		KeyEvent k;
		int i;
		while (1) {
			i = k.getkey();
			if (i != -1) game->setDirection(i);
		}
		return 0;
	}




int main() {
	/*
	HANDLE handleA, handleB;
	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);
	*/


	try {
		Frame *f1 = new Frame;
		Frame *f2 = new Frame[10];

		delete f1;
		delete[] f2;
	}
	catch (string msg) {
		cout << "Error msg : " << msg << endl;
	}

	return 0;
}