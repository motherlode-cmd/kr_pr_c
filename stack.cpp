#include <stdio.h>
#include <iostream>
#include <stdlib.h>
class Stack {
	int* arr;
	int size;
	int num;
public:

	int getSize() {
		return num + 1;
	}

	int getElen(int i) {
		return arr[i];
	}

	Stack() {
		size = 10;
		num = -1;
		arr = new int[size];
	}

	void push(int val){ // 
		if(num < size - 1) {
			num++;
			arr[num] = val;
		} else {
			size += size;
			int *temp = (int *)realloc(arr, size);
			arr = temp;
			num++;
			arr[num] = val;
		}
	}
	void pop() {
		if(num >= 0) {
			num--;
		} else {
			printf("vse huynya davay po novoy\n");
		}
	}
	bool isEmpty() {
		return num >= 0;
	}
	int top() {
		return arr[num];
	}
};

void print_stack(Stack s) {
	printf("\n{ Stack: ");
	for(int i = 0; i < s.getSize(); i++) {
		printf("[ %d ]", s.getElen(i));
	}
	printf(" } \n");
}

using namespace std;

int main() {
	Stack s;
	for(int i = 0; i < 15; i++) {
		s.push(i);
		printf("\n %d ", s.top());
	}
	print_stack(s);
	s.pop();
	print_stack(s);
	return 0;
}