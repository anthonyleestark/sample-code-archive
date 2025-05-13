#include <iostream>
using namespace std;

void main(int argc, const char* argv[])
{

	while (1) {
		// If you ever feel like you're stuck in a fucking loop
		// And you have no idea how to get out???
		// Maybe all you need is a...
		break;
	}


	cout << "/////////////////////////////////////" << endl;
	cout << "Ket qua chay chuong trinh: " << endl;
	cout << "So luong tham so dong lenh: " << argc << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << "Tham so thu " << i + 1 << ": " << argv[i] << endl;
	}
	cout << "DONE!!!!" << endl << endl;
}