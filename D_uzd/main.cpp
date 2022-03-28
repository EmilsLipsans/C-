/*******************************************

D6. Izveidot klasi, kurā glabājas masīvs ar sakitliskām vērtībām garumā 5.Klasei izveidot metodes :konstruktors, destruktors, IsEmpty, enqueue, dequeue, Count.
*******************************************/
#include "program.h"
#include <iostream>


using namespace std;

int main() {
	Queue q1;
	int option,value;
	do {
		cout << "Which operation do you want to perform? Select option number. Enter 0 to exit." << endl;
		cout << "1. Enqueue()" << endl;
		cout << "2. Dequeue()" << endl;
		cout << "3. IsEmpty()" << endl;
		cout << "4. IsFull()" << endl;
		cout << "5. Count()" << endl;
		cout << "6. Display()" << endl;

		cin >> option;

		int temp;

		switch (option) {
		case 0:
			break;
		case 1:
			cout << "Enter a number to Enqueue in the Queue" << endl;
			cin >> value;
			q1.enqueue(value);
			break;
		case 2:
			temp = q1.dequeue();

			if (temp != 0)
			{
				cout << "Dequeued value : " << temp << endl;
			}
			else {
				cout << "No value dequeued" << endl;
			}


		case 3:
			if (q1.IsEmpty())
				cout << "Queue is Empty" << endl;
			else
				cout << "Queue is not Empty" << endl;
			break;
		case 4:
			if (q1.IsFull())
				cout << "Queue is Full" << endl;
			else
				cout << "Queue is not Full" << endl;
			break;
		case 5:
			cout << "Count of items in Queue : " << q1.Count() << endl;
			break;
		case 6:
			cout << "Display Queue " << endl;
			q1.display();
		}

	} while (option != 0);


	return 0;

}
