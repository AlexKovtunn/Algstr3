#include <iostream>
#include "bst.h"

using namespace std;

int main() {
	BST bst;
	int arr[10] = { 8, 3, 10, 1, 6, 4, 7, 14, 13, 15 };
	for (int i = 0; i < 10; i++) bst.insert(arr[i]);
	Iterator* iter = bst.create_dft_iterator();
	for (int i = 0; i < 10; i++) {
		cout << iter->next() << " ";
		cout << bst.contains(arr[i]) << endl;
	}
	return 0;
}