#pragma once
#include <iostream>

using namespace std;

class BeanMachine
{
public:
	void dropBalls();
	int* determineBallBuckets(const int numberOfBalls, const int numberOfLevels);
	int* tallyBalls(const int numberOfBalls, int* balls, const int numberOfLevels);
};

