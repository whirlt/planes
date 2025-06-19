#include <iostream>
#include <fstream>
#include <vector>
#include <new>

#include "planes.hpp"

using namespace std;

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Usage: " << argv[0] << " [options] <script>" << endl;
		return 1; 
	}
	
	string line;
	ifstream script(argv[1]);
	
	if (!script.is_open()) {
		script.close();
		cout << "error: failed to read the file, perhaps it doesn't exist?" << endl;
		return 0;
	}
	
	PlaneField engine;
	
	while (getline(script, line)) 
		engine.planes.push_back(new Plane(line));
	
	script.close();

	int debug = 0;
	
	while (1) {
		if (debug) engine.dbg();
		if (engine.execute()) break;
	}
	
	for (Plane* plane : engine.planes)
		delete plane;
		
	return 0;
}
