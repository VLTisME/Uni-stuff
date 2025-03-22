#include <iostream>
#include <vector>

using namespace std;


struct Bookstote {
	struct Book {
		string* title, id, author, language;
		int* year, cnt;
		double* price;
	};

};


string menu[7]{ "Khởi tạo lại cửa hàng sách", "Nhập vào một sách", "Bán một sách", "Tìm một sách", "Xóa các sách có stock level ít hơn k", "Thoát chương trình" };



signed main() {
	   
	   while (1){
		   for (int i = 1; i <= 6; ++i) {
			   cout << "[" << i << "] " << menu[i] << "\n";
		    }
	   }
}