#include "BeanMachine.h"
#include <iostream>
#include <crtdbg.h>
#include <time.h>

using namespace std;

void BeanMachine::dropBalls()
{
	cout << "How many balls do you wish to drop? ";
	int numberOfBalls;
	cin >> numberOfBalls;
	cout << "And how many levels do you want to drop them through? ";
	int numberOfLevels;
	cin >> numberOfLevels;

	int* balls = determineBallBuckets(numberOfBalls, numberOfLevels);

	//for (int i = 0; i < numberOfBalls; i++)
	//{
	//	cout << "Ball " << i + 1 << " : " << balls[i] << "\n";
	//}

	int numberOfBuckets = numberOfLevels + 1;

	int* tally = tallyBalls(numberOfBalls, balls, numberOfBuckets);

	for (int i = 0; i < numberOfBuckets; i++)
	{
		cout << tally[i] << "\t";
		for (int j = 0; j < tally[i] / numberOfBuckets; j++)
		{
			cout << "x";
		}
		cout << "\n";
	}

	free(tally);

	tally = nullptr;

	free(balls);

	balls = nullptr;

}

int* BeanMachine::determineBallBuckets(const int numberOfBalls, const int numberOfLevels)
{
	int* balls = (int*)malloc(sizeof(int) * numberOfBalls);

	for (int i = 0; i < numberOfBalls; i++)
	{
		balls[i]=1;
		for (int j = 0; j < numberOfLevels; j++)
		{
		  if (rand() < (RAND_MAX / 2)) balls[i]++;
		}
	}

	return balls;

}


int* BeanMachine::tallyBalls(const int numberOfBalls, int* balls, const int numberOfBuckets)
{
	int* tally = (int*)malloc(sizeof(int) * numberOfBuckets);
	for (int i = 1; i <= numberOfBuckets; i++)
	{
		tally[i - 1] = 0;
		for (int j = 0; j < numberOfBalls; j++)
		{
			if (balls[j] == i) tally[i-1]++;
		}
	}

	return tally;

	
}

int main()
{
#ifdef _DEBUG
	//  _CrtSetBreakAlloc(87);
	_onexit(_CrtDumpMemoryLeaks);
#endif
	srand((int) time(nullptr));

	BeanMachine bm = BeanMachine();
	bm.dropBalls();

	
	return 0;
}
