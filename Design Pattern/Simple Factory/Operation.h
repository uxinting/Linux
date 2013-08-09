#ifndef _OP
#define _OP

class Operation
{
	private:
		double _nA;
		double _nB;

	public:
	double getA() {
		return _nA;
	}

	double getB() {
			return _nB;
	}

	void setA(double a) {
		_nA = a;
	}

	void setB(double b) {
		_nB = b;
	}

	virtual double GetResult() {
		double result = 0;
		return result;
	}
};

#endif
