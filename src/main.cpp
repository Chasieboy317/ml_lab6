#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "input.cpp"
#include "perceptron.cpp"

perceptron learn(std::string filename) {
	std::ifstream ifs(filename);
	input x1[4];
	input x2[4];
	int outputs[4];

	for (int i=0; i<4; i++) {
		int input1, input2, output1;
		ifs >> input1 >> input2 >> output1;
		x1[i] = input(input1, 0);
		x2[i] = input(input2, 0);
		outputs[i] = output1;
	}

	ifs.close();

	perceptron p1(1.0f);
	for (int i=0; i<4; i++) {
		std::cout<<"inputs are: "<<x1[i].x<<" "<<x2[i].x<<" and the expected value is: "<<outputs[i]<<std::endl;
		p1.inputs.push_back(x1[i]);
		p1.inputs.push_back(x2[i]);
		p1.outputs.push_back(outputs[i]);
	}

	p1.learnPerceptron();
	std::cout<<"learnt perceptron"<<std::endl;
	return p1;
}

int main (int argc, char* argv []) {
	perceptron p1 = learn("and.txt");
	perceptron p2 = learn("or.txt");

	std::vector<int> xoroutputs;
	std::cout<<std::endl;

	int count = 0;
	for (int i=0; i<p1.outputs.size(); i++) {
		int result = p2.outputs[i]-p1.outputs[i]*2 > 0 ? 1 : 0; //use the outputs for and perceptron and or perceptron
		xoroutputs.push_back(result);
		std::cout<<"xor for: "<<p1.inputs[count].x<<", "<<p1.inputs[count+1].x<<" is: "<<xoroutputs[i]<<std::endl;
		count+=2;
	}

	/*std::ifstream ifs("xor.txt");
	int outputs[4];

	for (int i=0; i<4; i++) {
		int input1, input2, output1;
		ifs >> input1 >> input2, output1;
		outputs[i] = outpu1;
	}

	ifs.close();

	perceptron p3(1.0f);
	for (int i=0; i<4; i++) {
		std::cout<<"inputs are: "<<x1[i].x<<" "<<x2[i].x<<" and the expected value is: "<<outputs[i]<<std::endl;
		p1.inputs.push_back(x1[i]);
		p1.inputs.push_back(x2[i]);
		p1.outputs.push_back(outputs[i]);
	}

	p1.learnPerceptron();*/

}
