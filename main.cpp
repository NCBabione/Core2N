#include <iostream>
#include <vector>
#include "neuralNetwork.h"

// define size of network
const int numInputs = 5;
const int numOutputs = 4;
const int numHiddenLayers = 3;
const int nodesPerHiddenLayer = 16;

int main() {
	neuralNetwork myNet;


	// setup hiddenLayers
	float hiddenLayers[numHiddenLayers][nodesPerHiddenLayer];
	for (int i = 0; i < numHiddenLayers; i++) {
		for (int j = 0; j < nodesPerHiddenLayer; j++) {
			hiddenLayers[i][j] = 0.0f;
		}
	}

	//setup inputs
	float inputs[numInputs];
	for (int i = 0; i < numInputs; i++) {
		inputs[i] = 0.0f;
	}

	// setup outputs
	float outputs[numOutputs];
	for (int i = 0; i < numOutputs; i++) {
		outputs[i] = 0.0f;
	}
	
	while (true) {
		// print command to terminal
		std::cout << "Commands:" << std::endl;
		std::cout << "	\"q\" to quit." << std::endl;
		std::cout << "	\"i\" to set inputs." << std::endl;
		//std::cout << "	\"p\" to display the network." << std::endl;
		std::cout << "	\"s\" to solve the neural network." << std::endl;

		// check for user input
		char userInput;
		std::cin >> userInput;

		// use the data user has given
		// if input is 'q', exit loop 
		if (userInput == 'q') {
			break;
		}

		// if 'i', set inputs for the network
		else if (userInput == 'i') {
			std::cout << "Type " << numInputs << " numbers for the input layer.";
			std::cout << std::endl;
			for (int i = 0; i < numInputs; i++) {
				std::cin >> inputs[i];
			}
		}

		// if 'p', print the network
		/*
		else if (userInput == 'p') {

		}*/

		// if 's', solve the network
		else if (userInput == 's') {
			// solve network
			myNet.solveNetwork(inputs, hiddenLayers, outputs);
		}

	}

	// return default
	return 0;
}