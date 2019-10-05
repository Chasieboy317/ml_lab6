#ifndef PERCEPTRON_CPP
#define PERCEPTRON_CPP

#include <iostream>
#include <vector>
#include "input.cpp"

class perceptron {
	public:
		std::vector<input> inputs;
		std::vector<int> outputs;

		float theta;
		float n;

		~perceptron() {
			inputs.clear();
			outputs.clear();
		}
		perceptron (float theta): theta(theta) {
			n = 0.1;
		}

		perceptron(std::vector<input> inputs, std::vector<int> outputs, float theta) : inputs(inputs), outputs(outputs), theta(theta)
		{
			n = 0.1;
		}
	
		int o(std::vector<input> x) {
			float sum = 0;
			for (int i=0; i<x.size(); i++) {
				sum +=x[i].x*x[i].w;	
			}
			std::cout<<"sum is: "<<sum<<std::endl;
			return sum > theta ? 1 : 0;
		}

		float updateW(float w, float t, float o, float x) {
			float deltaw = n*(t-o)*x;
			w+=deltaw;
			std::cout<<"updated weight for: "<<x<<" to "<<w<<std::endl;
			return w;
		}

		void learnPerceptron() {
			int count = 0;
			for (int i=0; i<outputs.size(); i++) {
				int O = 0;
				do {
					std::vector<input> temp {inputs[count], inputs[count+1]};
					O = o(temp);
					inputs[count].w = (updateW(inputs[count].w, outputs[i], O, inputs[count].x));
					inputs[count+1].w = (updateW(inputs[count+1].w, outputs[i], O, inputs[count+1].x));
					std::cout<<"output is: "<<O<<" and expected output is: "<<outputs[i]<<" for: "<<inputs[count].x<<", "<<inputs[count+1].x<<std::endl;
				}
				while (O!=outputs[i]);
				std::cout<<"learnt "<<outputs[i]<<" for: "<<inputs[count].x<<", "<<inputs[count+1].x<<std::endl;
				count+=2;
			}
		}
};
#endif
