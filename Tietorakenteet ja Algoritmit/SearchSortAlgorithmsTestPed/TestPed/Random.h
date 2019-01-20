#pragma once

class Random {
public:
	Random(bool pseudo = false);
	int random_integer(int low, int high);
	double random_real();
	int poisson(double mean);

private:
	int reseed();
	int seed,
		multiplier, add_on;
};