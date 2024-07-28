#include "data.h"

void data::init_Data(std::vector<int>& inputs, std::vector<std::vector<int>>& hiddenLayers, std::vector<int>& outputs) {
	// load data into class
	this->inputs = inputs;
	this->hiddenLayers = hiddenLayers;
	this->outputs = outputs;
	std::cout << "Data class setup." << std::endl;
}

void data::list_Data() {
	std::cout << std::endl;
	
	// list out inputs
	for (int ins = 0; ins < inputs.size(); ins++) {
		std::cout << inputs.at(ins) << " ";
		//std::cout << 'i';
	}
	std::cout << std::endl;

	// list out hidden layers
	for (int layers = 0; layers < hiddenLayers.size(); layers++) {
		for (int nodes_layers = 0; nodes_layers < hiddenLayers.at(layers).size(); nodes_layers++) {
			std::cout << hiddenLayers.at(layers).at(nodes_layers) << " ";
			//std::cout << 'h';
		}
		std::cout << std::endl;
	}

	// list out outputs
	for (int outs = 0; outs < outputs.size(); outs++) {
		std::cout << outputs.at(outs) << " ";
		//std::cout << 'o';
	}

	std::cout << "\n" << std::endl;
}

// set the number of inputs
void data::set_inputs(std::vector<int> inputs) {
	this->inputs = inputs;
	std::cout << "Inputs set." << std::endl;
}

// set the number of outputs
void data::set_outputs(std::vector<int> outputs) {
	this->outputs = outputs;
	std::cout << "Outputs set." << std::endl;
}

// setup the hidden layers
void data::set_hidden_layers(std::vector<std::vector<int>> hiddenLayers) {
	this->hiddenLayers = hiddenLayers;
	std::cout << "Hidden Layers set." << std::endl;
}

void data::solve_network() {
	int SOME_VALUE = 1;
	// get to the data in the vector
	for (int x = 0; x < hiddenLayers.size(); x++) {
		for (int y = 0; y < hiddenLayers.at(x).size(); y++) {
			// create a table for some_value
			// if it is the first hidden layer, get the inputs as data
			if (x == 0) {
				// iterate through the inputs and add to the node
				for (int in_index = 0; in_index < inputs.size(); in_index++) {
					hiddenLayers.at(x).at(y) += inputs.at(in_index) * SOME_VALUE;
				}
			}
			// if it is not the first hidden layer, use the previous hidden layer for data
			else {
				for (int node_index = 0; node_index < hiddenLayers.at(x-1).size(); node_index++) {
					hiddenLayers.at(x).at(y) += hiddenLayers.at(x-1).at(node_index) * SOME_VALUE;
				}
			}
		}
	}
	// calculate output vector
	for (int out_index = 0; out_index < outputs.size(); out_index++) {
		// find the last column in the network hidden layers
		int size_x = hiddenLayers.size();
		int size_y = hiddenLayers.at(size_x - 1).size();

		// calculate the outputs from the last hidden layer
		for (int y_index = 0; y_index < size_y; y_index++) {
			outputs.at(out_index) += hiddenLayers.at(size_x - 1).at(y_index) * SOME_VALUE;
		}
	}
}