#include <iostream>
#include <vector>
#include "data.h"

void requestData(std::vector<int>&, std::vector<int>&, std::vector<std::vector<int>>&);

int main() {
	data myData{};
	
	std::vector<int> inputs;
	std::vector<int> outputs;
	std::vector<std::vector<int>> hiddenLayers;
	requestData(inputs, outputs, hiddenLayers);

	myData.init_Data(inputs, hiddenLayers, outputs);
	myData.list_Data();
	

	// create loop
	while (true) {
		// print command to terminal
		std::cout << "Commands:" << std::endl;
		std::cout << "	\"q\" to quit." << std::endl;
		std::cout << "	\"i\" to set inputs." << std::endl;
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

	}
	// return default 0
	return 0;
}

void requestData(std::vector<int>& inputs, std::vector<int>& outputs, std::vector<std::vector<int>>& hiddenLayers) {
	int temp;
	std::cout << "How many input nodes would you like: ";
	std::cin >> temp;
	// fills the vector with 0 temp times
	inputs.assign(temp, 0);

	std::cout << "How many output nodes would you like: ";
	std::cin >> temp;
	// fills the vector with 0 temp times
	outputs.assign(temp, 0);

	// sets up a vector of hidden nodes
	std::cout << "How many nodes in the hidden layers would you like: ";
	std::cin >> temp;
	std::vector<int> tempVect;
	tempVect.assign(temp, 0);

	// creates a vector of vectors of hidden nodes
	std::cout << "How many hidden layers would you like: ";
	std::cin >> temp;
	hiddenLayers.assign(temp, tempVect);
}