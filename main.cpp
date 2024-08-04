#include <iostream>
#include <vector>
#include "data.h"
#include "lib/eigen-3.4.0/Eigen/Dense"

// define function
void requestData(std::vector<float>&, std::vector<float>&, std::vector<std::vector<float>>&);

// new function to easily create a new line
void end();

int main() {
	// setup hiddenLayers
	float hiddenLayers[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			hiddenLayers[i][j] = 1.0f;
		}
	}

	//setup inputs
	float inputs[5];
	for (int i = 0; i < 5; i++) {
		inputs[i] = 1.0f;
	}

	// setup outputs
	float outputs[4];
	for (int i = 0; i < 4; i++) {
		outputs[i] = 1.0f;
	}
	
	// print inputs
	for (int i = 0; i < 5; i++) {
		std::cout << inputs[i];
	}
	end();

	// print hiddenLayers
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << hiddenLayers[i][j];
		}
		end();
	}

	// print outputs
	for (int i = 0; i < 4; i++) {
		std::cout << outputs[i];
	}
	end();
	

	/*
	data myData{};
	
	std::vector<float> inputs;
	std::vector<float> outputs;
	std::vector<std::vector<float>> hiddenLayers;
	requestData(inputs, outputs, hiddenLayers);

	myData.init_Data(inputs, hiddenLayers, outputs);
	myData.list_Data();
	

	// create loop
	while (true) {
		// print command to terminal
		std::cout << "Commands:" << std::endl;
		std::cout << "	\"q\" to quit." << std::endl;
		std::cout << "	\"i\" to set inputs." << std::endl;
		std::cout << "	\"r\" to reset and reallocate memory." << std::endl;
		std::cout << std::endl;

		// check for input
		char input;
		std::cin >> input;
		// if input is 'q', exit loop 
		if (input == 'q') {
			break;
		}

		// set inputs
		else if (input == 'i') {
			for (int ins = 0; ins < inputs.size(); ins++) {
				std::cin >> inputs.at(ins);
			}
			myData.set_inputs(inputs);
			myData.solve_network();
			myData.list_Data();
		}

		else if (input == 'r') {
			myData.reset();
		}

	}
	// return default 0
	return 0;
	*/

	return 0;
}

void requestData(std::vector<float>& inputs, std::vector<float>& outputs, std::vector<std::vector<float>>& hiddenLayers) {
	int temp;
	std::cout << "How many input nodes would you like: ";
	std::cin >> temp;
	// fills the vector with 0 temp times
	inputs.assign(temp, 0.0f);

	std::cout << "How many output nodes would you like: ";
	std::cin >> temp;
	// fills the vector with 0 temp times
	outputs.assign(temp, 0.0f);

	// sets up a vector of hidden nodes
	std::cout << "How many nodes in the hidden layers would you like: ";
	std::cin >> temp;
	std::vector<float> tempVect;
	tempVect.assign(temp, 0.0f);

	// creates a vector of vectors of hidden nodes
	std::cout << "How many hidden layers would you like: ";
	std::cin >> temp;
	hiddenLayers.assign(temp, tempVect);
}

void end() {
	std::cout << std::endl;
}