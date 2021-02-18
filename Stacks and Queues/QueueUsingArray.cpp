#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// #define int long long
// const int MOD = 1000000007;


struct myqueue
{
	int queuefront, queuerear, queuecapacity;
	int *arr;
	myqueue(int n)
	{
		queuefront = 0;
		queuerear = 0;
		queuecapacity = n;
		arr = new int[queuecapacity];
	}

	void qenqueue(int x)
	{
		if (queuerear == queuecapacity)
		{
			cout << "Queue is full" << endl;
			return;
		}
		arr[queuerear++] = x;
		cout << "Pushed " << x << endl;
	}

	int qdequeue()
	{
		if (queuefront == queuerear)
		{
			cout << "Queue is empty" << endl;
			return INT_MIN;
		}
		int res = arr[0];
		for (int i = 0; i < queuerear - 1; i++)
			arr[i] = arr[i + 1];
		queuerear--;
		return res;
	}

	int qfront()
	{
		if (queuefront == queuerear)
		{
			cout << "Queue is empty" << endl;
			return INT_MIN;
		}
		return arr[queuefront];
	}

	int qrear()
	{
		if (queuefront == queuerear)
		{
			cout << "Queue is empty" << endl;
			return INT_MIN;
		}
		return arr[queuerear - 1];
	}


	int qsiz()
	{
		return queuerear;
	}

	bool qempty()
	{
		return (queuefront == queuerear);
	}

};

void striker()
{
	myqueue q(5);
	q.qenqueue(1);
	q.qenqueue(2);
	q.qenqueue(3);
	cout << "Removed element : " << q.qdequeue() << endl;
	cout << "Removed element : " << q.qdequeue() << endl;
	cout << "Front element : " << q.qfront() << endl;
	cout << "Last element : " << q.qrear() << endl;
	cout << "Size : " << q.qsiz() << endl;
	cout << "Check Empty : " << q.qempty() << endl;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
    	// cout << "#Case: "<< i + 1 << endl;
    	striker();
    	// cout << endl;
    }
 	return 0;
}