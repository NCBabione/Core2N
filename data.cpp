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
		std::cout << inputs.at(ins);
		//std::cout << 'i';
	}
	std::cout << std::endl;

	// list out hidden layers
	for (int layers = 0; layers < hiddenLayers.size(); layers++) {
		for (int nodes_layers = 0; nodes_layers < hiddenLayers.at(layers).size(); nodes_layers++) {
			//std::cout << hiddenLayers.at(layers).at(nodes_layers);
			std::cout << 'h';
		}
		std::cout << std::endl;
	}

	// list out outputs
	for (int outs = 0; outs < outputs.size(); outs++) {
		//std::cout << outputs.at(outs);
		std::cout << 'o';
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
