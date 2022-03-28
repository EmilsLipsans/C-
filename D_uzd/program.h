
class Queue {
	private:
		int front;			// Izmantoju mainīgo front, lai noteiktu queue sākotnējo elementu, bet rear, lai noteiktu queue beigu elementu.
		int rear;
		int arr[5];

	public:
		Queue();
		~Queue();
		bool IsEmpty();
		bool IsFull();
		void enqueue(int val);
		int dequeue();
		int Count();
		void display();
};
