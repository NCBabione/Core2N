#include "neuralNetwork.h"

neuralNetwork::neuralNetwork() {
	// initialize network, set weights
	for (int i = 0; i < numHidNodes; i++) {
		for (int j = 0; j < numInputs; j++) {
			inputWeights[i][j] = 1.0f;
		}
	}
	for (int i = 0; i < numHid - 1; i++) {
		for (int j = 0; j < numHidNodes; j++) {
			for (int k = 0; k < numHidNodes; k++) {
				hiddenWeights[i][j][k] = 1.0f;
			}
		}
	}
	for (int i = 0; i < numOutputs; i++) {
		for (int j = 0; j < numHidNodes; j++) {
			outputWeights[i][j] = 1.0f;
		}
	}
}

void neuralNetwork::solveNetwork(float(&input)[5], float(&hiddenLayers)[3][16], float(&output)[4]) {
	// calculate first hidden layer
	for (int i = 0; i < numHidNodes; i++) {
		for (int j = 0; j < numInputs; j++) {
			hiddenLayers[0][i] += input[j] * inputWeights[i][j];
		}
	}

	// calculate remaining hidden layers
	for (int i = 1; i < numHid; i++) {
		for (int j = 0; j < numHidNodes; j++) {
			for (int k = 0; k < numHidNodes; k++) {
				hiddenLayers[i][j] += hiddenLayers[i - 1][k] * hiddenWeights[i - 1][j][k];
			}
		}
	}

	// calculate output layers nodes
	for (int i = 0; i < numOutputs; i++) {
		for (int j = 0; j < numHidNodes; j++) {
			output[i] += hiddenLayers[numHid - 1][j] * outputWeights[i][j];
		}
	}

	// display the network
	// print inputs
	for (int i = 0; i < numInputs; i++) {
		std::cout << input[i];
		if (input[i] < 10) {
			std::cout << "    ";
		}
		else if (input[i] < 100) {
			std::cout << "   ";
		}
		else if (input[i] < 1000) {
			std::cout << "  ";
		}
		else if (input[i] < 10000) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	// print hiddenLayers
	for (int i = 0; i < numHid; i++) {
		for (int j = 0; j < numHidNodes; j++) {
			std::cout << hiddenLayers[i][j];
			if (hiddenLayers[i][j] < 10) {
				std::cout << "    ";
			}
			else if (hiddenLayers[i][j] < 100) {
				std::cout << "   ";
			}
			else if (hiddenLayers[i][j] < 1000) {
				std::cout << "  ";
			}
			else if (hiddenLayers[i][j] < 10000) {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

	// print outputs
	for (int i = 0; i < numOutputs; i++) {
		std::cout << output[i];
		if (output[i] < 10) {
			std::cout << "    ";
		}
		else if (output[i] < 100) {
			std::cout << "   ";
		}
		else if (output[i] < 1000) {
			std::cout << "  ";
		}
		else if (output[i] < 10000) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}