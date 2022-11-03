#pragma once

#include <string>
#include <vector>
#include <iostream>

class FibLFSR {
public:
	FibLFSR(const std::string& seed); // constructor to create LFSR with the given initial seed
	int step(); // simulate one step and return the new bit as 0 or 1
	int generate(int k); // simulate k steps and return k-bit integer
	int getSize() const;
	int getBitAtIndex(int i) const;
private:
	std::vector<int> vecOfBits;
};

std::ostream& operator<<(std::ostream& out, const FibLFSR& obj);
