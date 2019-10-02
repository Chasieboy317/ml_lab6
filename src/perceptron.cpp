#ifndef PERCEPTRON_CPP
#define PERCEPTRON_CPP

#include <iostream>
#include <vector>
#include "input.cpp"

class perceptron {
	public:
		std::vector<input> inputs;
		float theta;

		perceptron(std::vector<input> inputs, float theta) : inputs(inputs), theta(theta) {}
	
		int o() {
			float sum = 0;
			for (int i=0; i<inputs.size(); i++) {
				sum +=inputs[i].s;	
			}
			return sum > theta ? 1 : -1;
		}
};
#endif
