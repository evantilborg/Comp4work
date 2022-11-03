/************************************************************
 *Name: <Erik van Tilborg>
 *Course name: <COMP.2040>
 *Assignment: <PS1a>
 *Instructor's name: <Dr. James Daly>
 *Date: <1/31/22>
 *Sources Of Help: <class notes>
************************************************************/
#include "FibLFSR.h"

#define MAXBITS 16 //LFSR designed to take in 16 bit strings, nothing more, nothing less

FibLFSR::FibLFSR(const std::string& seed){
	if(seed.size() > MAXBITS || seed.size() < MAXBITS){
		throw std::invalid_argument("Expected a 16 bit string for the seed");
	}
	for(size_t i = 0; i < seed.size(); i++){
		vecOfBits.push_back(seed[i] - 48);
	}
} 

int FibLFSR::step(){
	int XORresult;
	int vecSize = vecOfBits.size();
	XORresult = vecOfBits[0] ^ vecOfBits[2]; //XOR bit 15 and 13
	XORresult = XORresult ^ vecOfBits[3]; //XOR bit 12 with previous result
	XORresult = XORresult ^ vecOfBits[5]; //XOR bit 10 with previous result
	for (int i = 0; i < vecSize; i++){ //shift internal state
		if((i + 1) > vecSize){
			vecOfBits.push_back(0);
		}
		else{
			vecOfBits[i] = vecOfBits[i + 1];
		}
	}
	vecOfBits.pop_back();
	vecOfBits.push_back(XORresult);
	return XORresult; //return final XOR value
} 

int FibLFSR::generate(int k) {
	if (k > 32 || k < 0){ //check if k is out of range
		std::cout << "The k value is out of range and creates an overflow issue... exiting program" << std::endl;
		exit(1);
	}
	int val = 0; //int val = 0
	for (int i = 0; i < k; i++){ //loop step for k times
		val *= 2; //take val * 2
		val = val + step(); //then add return val of step
	}
	return val; //return final value
}

int FibLFSR::getSize() const {
	return vecOfBits.size();
}

int FibLFSR::getBitAtIndex(int i) const {
	return vecOfBits[i];
}

std::ostream& operator << (std::ostream& out, const FibLFSR& obj){
	for (int i = 0; i < obj.getSize(); i++) {
		out << obj.getBitAtIndex(i);
	}
	return out;
}

