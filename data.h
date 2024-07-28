#pragma once
#include <iostream>
#include <vector>
class data
{
private:
	// private functions and data
	std::vector<int> inputs;
	std::vector<int> outputs;
	std::vector<std::vector<int>> hiddenLayers;

public:
	// public functions and data
	// init function
	void init_Data(std::vector<int>&, std::vector<std::vector<int>>& , std::vector<int>&);
	void list_Data();
	void solve_network();


	// induvidual size set functions
	void set_inputs(std::vector<int>);
	void set_hidden_layers(std::vector<std::vector<int>>);
	void set_outputs(std::vector<int>);
};