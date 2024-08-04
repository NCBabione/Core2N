#pragma once
#include <iostream>
#include <vector>
class neuralNetwork
{
private:
	int numInputs = 5;
	int numOutputs = 4;
	int numHid = 3;
	int numHidNodes = 16;

	//	first col hid, 	num inputs
	float inputWeights[16][5];

	// num hidden layers - 1, node in col, previos node weight
	float hiddenWeights[2][16][16];

	// num outputs, last col hid
	float outputWeights[4][16];


public:
	// constructor
	neuralNetwork();

	void solveNetwork(float (&input)[5], float (&hiddenLayers)[3][16], float (&output)[4]);
};