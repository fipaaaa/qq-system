#include<iostream>
using namespace std;
int main() {
	int n;
	while (1) {
		cin >> n;
		if (n > 2) {
			cout << "s";
		}
		if (n < 1) {
			cout << "d";
		}
	}
}