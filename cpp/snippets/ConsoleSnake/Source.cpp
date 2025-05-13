#include "Util.h"
#include <iostream>
using namespace std;

#define GWIDTH 50  // màn hình game gồm 50 cột
#define GHEIGHT 20 // và 20 dòng

void mainloop() {
	// vòng lặp chính xử lý logic trong này
}

void drawgame() {
	// vòng lặp chính xử lý đồ họa trong này
}

int main() {
	ShowCur(false); // Ẩn con trỏ
	SetColor(14); // Thiết lập màu chữ (vàng)

	while (true) {
		Tick(50, mainloop, drawgame); // Mainloop
	}
	return 0;
}
