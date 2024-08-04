#include <iostream>
#include <vector>
#include "data.h"
#include "lib/eigen-3.4.0/Eigen/Dense"

// define size of network
const int numInputs = 5;
const int numOutputs = 4;
const int numHiddenLayers = 3;
const int nodesPerHiddenLayer = 3;

int main() {
	// setup hiddenLayers
	float hiddenLayers[numHiddenLayers][nodesPerHiddenLayer];
	for (int i = 0; i < numHiddenLayers; i++) {
		for (int j = 0; j < nodesPerHiddenLayer; j++) {
			hiddenLayers[i][j] = 1.0f;
		}
	}

	//setup inputs
	float inputs[numInputs];
	for (int i = 0; i < numInputs; i++) {
		inputs[i] = 1.0f;
	}

	// setup outputs
	float outputs[numOutputs];
	for (int i = 0; i < numOutputs; i++) {
		outputs[i] = 1.0f;
	}
	
	while (true) {
		// print command to terminal
		std::cout << "Commands:" << std::endl;
		std::cout << "	\"q\" to quit." << std::endl;
		std::cout << "	\"i\" to set inputs." << std::endl;
		std::cout << "	\"p\" to display the network." << std::endl;

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
		else if (userInput == 'p') {

			// print inputs
			for (int i = 0; i < numInputs; i++) {
				std::cout << inputs[i] << " ";
			}
			std::cout << std::endl;

			// print hiddenLayers
			for (int i = 0; i < numHiddenLayers; i++) {
				for (int j = 0; j < nodesPerHiddenLayer; j++) {
					std::cout << hiddenLayers[i][j];
				}
				std::cout << std::endl;
			}

			// print outputs
			for (int i = 0; i < numOutputs; i++) {
				std::cout << outputs[i];
			}
			std::cout << std::endl;
		}

	}

	// return default
	return 0;
}