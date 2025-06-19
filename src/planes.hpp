#ifndef __CPP_PLANES_HEADER
#define __CPP_PLANES_HEADER

#include <iostream>
#include <vector>

#define HALT_SIGNAL 1
#define CLEAR 0

using namespace std;

class Plane {
	public:
		string source;
		vector<int> loop_cell_stack;
		int pc = 0;
	
		Plane(std::string _source) {
			source = _source;
			loop_cell_stack.push_back(0);
		}
		
		void advance() {
			pc++;
		}
		
		void jump(int cell) {
			pc = cell;
		}
		
		char peek() {
			return source[pc];
		}
		
		void new_loop() {
			loop_cell_stack.push_back(pc);
		}
		
		void iterate() {
			jump(loop_cell_stack.back());
		}
		
		void end_loop() {
			loop_cell_stack.pop_back();
		}
};

class PlaneField {
	public:
		vector<Plane*> planes;
		vector<int> stack;
		int active_pointer = 0;
		
		int execute() {
			Plane *active = planes[active_pointer], *main = planes[0];
			int swap;
			
			int instruction = active->peek();
			active->advance();
			
			switch (instruction) {
				case '#':
					stack.push_back(getchar());
					break;
				case '.':
					cout << (char)(stack.back());
					stack.pop_back();
					break;
				case '~':
					stack.pop_back();
					break;
				case '\'':
					stack.push_back(active->peek());
					active->advance();
					break;
				case '(':
					active->new_loop();
					break;
				case ')':
					if (stack.back()) active->iterate();
					else active->end_loop();
					break;
				case '*':
					active->pc = main->pc;
					break;
				case '<':
					active_pointer--;
					break;
				case '>':
					active_pointer++;
					break;
				case '?':
					if (stack.back()) active_pointer++;
					break;
				case '!':
					if (stack.back()) active_pointer--;
					break;
				case '+':
					stack[stack.size() - 2] += stack.back();
					stack.pop_back();
					break;
				case '-':
					stack[stack.size() - 2] -= stack.back();
					stack.pop_back();
					break;
				case ':':
					stack.push_back(stack.back());
					break;
				case '%':
					swap = stack.back();
					stack[stack.size() - 1] = stack[stack.size() - 2];
					stack[stack.size() - 2] = swap;
					break;
				case 'h':
					active_pointer = 0;
					break;
				case '&':
					stack.push_back(active_pointer);
					break;
				case '^':
					active_pointer = stack.back();
					stack.pop_back();
					break;
				case '$':
					active->pc = 0;
					break;
				case 'H':
					return HALT_SIGNAL;
			}
			return CLEAR;
		}
};

#endif
