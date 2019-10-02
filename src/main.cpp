#include <iostream>
#include <fstream>
#include <sstream>

int main (int argc, char* argv []) {
	std::ifstream ifs("input.txt");
	std::string line;
	std::stringstream ss;

	while (!ifs.eof()) {
		int input1, input2, output1;
		ifs >> input1 >> input2 >> output1;
		std::cout<<input1<<" "<<input2<<" "<<output1<<std::endl;	
	}

	ifs.close();
}
