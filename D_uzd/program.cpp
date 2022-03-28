#include "program.h"
#include <iostream>

using namespace std;

Queue::Queue() {
	front = -1;
	rear = -1;

	for (int x = 0; x < 5; x++) {
		arr[x] = 0;
	}
}
Queue::~Queue(){
	if (!IsEmpty())cout <<"The object has been removed. Number of elements eliminated : "<<Count();
}
bool Queue::IsEmpty() {
	if (front == -1 && rear == -1)
		return true;
	else
		return false;

}
bool Queue::IsFull() {
	if (rear == 4)
		return true;
	else
		return false;

}
void Queue::enqueue(int val) {
	if (IsFull()) {
		cout << "Queue is full" << endl;
		return;
	}

	else if (IsEmpty()) {
		rear = 0;
		front = 0;
		arr[rear] = val;
	}
	else {
		rear++;
		arr[rear] = val;
	}
}
int Queue::dequeue(){
	int x;
	if (IsEmpty()) {
		return 0;
	}
	else if (rear == front) {		//Ja masīvam ir viena vērtība, tad saglabāju to mainīgajā x, arr[0] vērtību samainu uz 0 un atgriežu x vērtību.
		x = arr[front];
		arr[front] = 0;
		rear = -1;
		front = -1;
		return x;
	}
	else {
		x = arr[front];
		arr[front] = 0;
		front++;
		return x;
	}
}
int Queue::Count() {
	if (rear == -1 && front == -1)
		return 0;
	else
		return rear - front + 1;
}

void Queue::display(){
	for (int i = 0;i < 5;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}











