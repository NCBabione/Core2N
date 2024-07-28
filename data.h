#pragma once
#include <iostream>
#include <vector>
class data
{
private:
	// private functions and data
	std::vector<float> inputs;
	std::vector<float> outputs;
	std::vector<std::vector<float>> hiddenLayers;

	//    x			y		 vect prev int
	std::vector<std::vector<std::vector<float>>> weights;

public:
	// public functions and data
	// init function
	void init_Data(std::vector<float>&, std::vector<std::vector<float>>& , std::vector<float>&);
	void list_Data();
	void solve_network();
	void reset();


	// induvidual size set functions
	void set_inputs(std::vector<float>);
	void set_hidden_layers(std::vector<std::vector<float>>);
	void set_outputs(std::vector<float>);
};