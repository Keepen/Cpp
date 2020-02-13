#include <iostream>
using namespace std;
#define Max 100000000

void memOut(){
	
	cerr << "ÄÚ´æÉêÇëÊ§°Ü£¡£¡£¡" << endl;
	throw bad_alloc();
}


int main() {
	set_new_handler(memOut);
	//try {
	int* p1 = new int[Max];
	int* p2 = new int[Max];
	int* p3 = new int[Max];
	int* p4 = new int[Max];
	int* p5 = new int[Max];
	int* p6 = new int[Max];
	int* p7 = new int[Max];
	int* p8 = new int[Max];
	//}
	//catch (bad_alloc& bc) {
	//	cout << "bad_alloc" << endl;
	//	cout << bc.what();
	//}
	return 0;
}