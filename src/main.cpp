#include <iostream>
#include <fstream>
#include <vector>
#include <new>

#include "planes.hpp"

using namespace std;

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Usage: " << argv[0] << " <script>" << endl;
		return 1; 
	}
	
	string line;
	ifstream script(argv[1]);
	
	PlaneField engine;
	
	while (getline(script, line)) 
		engine.planes.push_back(new Plane(line));
	
	script.close();
	
	while (1) {
		if (engine.execute() == HALT_SIGNAL) 
			break;
	}
	
	for (Plane* plane : engine.planes)
		delete plane;
		
	return 0;
}
