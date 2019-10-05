#ifndef INPUT_CPP
#define INPUT_CPP

class input {
	public:
		float x;
		float w;
		float s;

		input(float x, float w) : x(x), w(w) {s = w*x;}

		input() {
			x = 1;
			w = 0;
			s = x*w;
		}

		void setX(float x) {
			this->x = x;
			s = x*w;
		}

		void setW(float w) {
			this->w=w;
		}
};

#endif
