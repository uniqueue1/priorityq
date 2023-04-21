#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int main()
{

	PriorityQueue pq;

	pq.push(10);
	pq.push(20);
	pq.push(30);
	pq.push(40);
	pq.push(50);
	pq.push(60);
	pq.push(70);
	/*pq.printAsArray();*/
	pq.printAsTree(0, 0);
	system("pause");
	return 0;
}