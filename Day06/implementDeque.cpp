#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


struct Deque
{
    int size, cap, front;
    int *arr;
    Deque(int c)
    {
        cap = c;
        size = 0;
        front = 0;
        arr = new int[cap];
    }

    bool isFull()
    {
        return (size == cap);
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void deleteFront()
    {
        if (isEmpty())
            return;
        front = (front + 1) % cap;
        size--;
    }

    void deleteRear()
    {
        if (isEmpty())
            return;
        size--;
    }

    void insertFront(int x)
    {
        if (isFull())
            return;
        front = (front + cap - 1) % cap;
        arr[front] = x;
        size++;
    }

    void insertRear(int x)
    {
        if (isFull())
            return;
        int n_rear = (front + size) % cap;
        arr[n_rear] = x;
        size++;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[(front + size - 1) % cap];
    }

};



void striker()
{
    Deque dq(5);
    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertRear(30);
    dq.insertFront(40);
    cout << "Get Rear " << dq.getRear() << endl;
    cout << "Get Front " << dq.getFront() << endl;
    dq.deleteFront();
    cout << "Get Rear " << dq.getRear() << endl;
    cout << "Get Front " << dq.getFront() << endl;
    dq.deleteRear();
    cout << "Get Rear " << dq.getRear() << endl;
    cout << "Get Front " << dq.getFront() << endl;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
    	// cout << "#Case: "<< i + 1 << endl;
    	striker();
    	cout << endl;
    }
 	return 0;
}