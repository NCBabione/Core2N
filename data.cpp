#include "data.h"

void data::init_Data(std::vector<float>& inputs, std::vector<std::vector<float>>& hiddenLayers, std::vector<float>& outputs) {
	// load data into class
	this->inputs = inputs;
	this->hiddenLayers = hiddenLayers;
	this->outputs = outputs;
	std::cout << "Data class setup." << std::endl;

	// create a column of node weights
	std::vector<std::vector<float>> whole_column_weights;
	for (int node_x = 0; node_x < hiddenLayers.size(); node_x++) {
		std::cout << "Setting up weights for layer " << node_x + 1 << std::endl;
		// pull input data
		if (node_x == 0) {

			// iterates through first hidden layer's nodes
			for (int node_y = 0; node_y < hiddenLayers.at(0).size(); node_y++) {
				std::vector<float> input_weights;
				// weights from the input nodes to the first layer
				// setting default weight to 1
				//input_weights.assign(inputs.size(), 1);
				for (int weight_index = 0; weight_index < inputs.size(); weight_index++) {
					input_weights.push_back((rand() % 100) / 100.0f);
				}

				// adds vector of input weights down the first column of hidden layers
				whole_column_weights.push_back(input_weights);
			}

			// push into weights
			weights.push_back(whole_column_weights);
		}

		// pull previous layer data
		else {
			whole_column_weights.clear();
			
			for (int node_y = 0; node_y < hiddenLayers.at(node_x).size(); node_y++) {
				std::vector<float> prev_layer_weights;
				// number of nodes in previous layer
				//hiddenLayers.at(node_x - 1).size();
				// setting default weight to 1
				//prev_layer_weights.assign(hiddenLayers.at(node_x - 1).size(), 1);
				for (int weight_index = 0; weight_index < hiddenLayers.at(node_x - 1).size(); weight_index++) {
					prev_layer_weights.push_back((rand() % 100) / 100.0f);
				}
				// fill in next layer

				whole_column_weights.push_back(prev_layer_weights);
			}

			weights.push_back(whole_column_weights);
		}


		/*for (int node_y = 0; node_y < hiddenLayers.at(node_x).size(); node_y++) {

			// create a simple vector with weights for previous nodes
			std::vector<int> prev_weights;
			prev_weights.assign(inputs.size(), 1);
			
			// fill in whole column of hidden layers weights
			whole_column_weights.assign(hiddenLayers.at(node_x).size(), prev_weights);
		}

		// fill in whole weight table with columns
		weights.assign(hiddenLayers.size(), whole_column_weights);
		*/
	}

	
	std::cout << "Setting up weights for layer " << hiddenLayers.size() + 1 << std::endl;

	// create for outputs
	std::vector<std::vector<float>> last_column_weights;
	for (int num_outs = 0; num_outs < outputs.size(); num_outs++) {
		// set weights to output nodes
		std::vector<float> prev_layer_weights;
		// create default weight vector for one node with a value of 1
		//prev_layer_weights.assign(hiddenLayers.at(hiddenLayers.size() - 1).size(), 1);
		for (int weight_index = 0; weight_index < hiddenLayers.at(hiddenLayers.size() - 1).size(); weight_index++) {
			prev_layer_weights.push_back((rand() % 100) / 100.0f);
		}

		last_column_weights.push_back(prev_layer_weights);
	}

	weights.push_back(last_column_weights);


}

// Print data to terminal
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
void data::set_inputs(std::vector<float> inputs) {
	this->inputs = inputs;
	std::cout << "Inputs set." << std::endl;
}

// set the number of outputs
void data::set_outputs(std::vector<float> outputs) {
	this->outputs = outputs;
	std::cout << "Outputs set." << std::endl;
}

// setup the hidden layers
void data::set_hidden_layers(std::vector<std::vector<float>> hiddenLayers) {
	this->hiddenLayers = hiddenLayers;
	std::cout << "Hidden Layers set." << std::endl;
}

// Solve the network
void data::solve_network() {
	int SOME_VALUE = 1;
	// get to the data in the vector
	for (int x = 0; x < hiddenLayers.size(); x++) {
		std::cout << "Solving layer " << x+1 << std::endl;
		for (int y = 0; y < hiddenLayers.at(x).size(); y++) {
			// create a table for some_value
			// if it is the first hidden layer, get the inputs as data
			if (x == 0) {
				// iterate through the inputs and add to the node
				for (int in_index = 0; in_index < inputs.size(); in_index++) {
					//hiddenLayers.at(x).at(y) += inputs.at(in_index) * SOME_VALUE;
					hiddenLayers.at(x).at(y) += inputs.at(in_index) * weights.at(x).at(y).at(in_index);
				}
				hiddenLayers.at(x).at(y) /= inputs.size();
			}
			// if it is not the first hidden layer, use the previous hidden layer for data
			else {
				for (int node_index = 0; node_index < hiddenLayers.at(x-1).size(); node_index++) {
					//hiddenLayers.at(x).at(y) += hiddenLayers.at(x-1).at(node_index) * SOME_VALUE;
					hiddenLayers.at(x).at(y) += hiddenLayers.at(x - 1).at(node_index) * weights.at(x).at(y).at(node_index);
				}
				hiddenLayers.at(x).at(y) /= hiddenLayers.at(x - 1).size();
			}
		}
	}

	std::cout << "Solving layer " << hiddenLayers.size() + 1 << std::endl;

	// calculate output vector
	for (int out_index = 0; out_index < outputs.size(); out_index++) {
		// find the last column in the network hidden layers
		int size_x = hiddenLayers.size();
		int size_y = hiddenLayers.at(size_x - 1).size();

		// calculate the outputs from the last hidden layer
		for (int y_index = 0; y_index < size_y; y_index++) {
			//outputs.at(out_index) += hiddenLayers.at(size_x - 1).at(y_index) * SOME_VALUE;
			outputs.at(out_index) += hiddenLayers.at(size_x - 1).at(y_index) * weights.at(weights.size() - 1).at(out_index).at(y_index);
		}
		outputs.at(out_index) /= hiddenLayers.at(size_x - 1).size();
	}
}