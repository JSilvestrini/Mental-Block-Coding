#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using std::string, std::cout, std::endl, std::cin, std::vector, std::unordered_map, std::stack;

int main() {
	string instructions;
	cout << "Please enter instructions" << endl;
	cin >> instructions;

	vector<unsigned char> tape = { 0 };
	size_t cellIndex = 0;
	string userInput;
	size_t instructionPointer = 0;
	char currentInstruction;

	unordered_map<size_t, size_t> bracketPairs;
	stack<size_t> brackets;

	for (size_t i = 0; i < instructions.size(); i++) {
		currentInstruction = instructions[i];
		if (currentInstruction == '[') {
			brackets.push(i);
		}
		else if (currentInstruction == ']') {
			bracketPairs[brackets.top()] = i;
			bracketPairs[i] = brackets.top();
			brackets.pop();
		}
	}

	while (instructionPointer < instructions.size()) {
		currentInstruction = instructions[instructionPointer];

		switch (currentInstruction) {
			case '+':
				tape[cellIndex] += 1;
				break;
			case '-':
				tape[cellIndex] -= 1;
				break;
			case '>':
				cellIndex++;
				if (cellIndex >= tape.size()) {
					tape.push_back(0);
				}
				break;
			case '<':
				cellIndex--;
				break;
			case '.':
				cout << tape[cellIndex];
				break;
			case ',':
				if (userInput.empty()) {
					cin >> userInput;
					userInput.push_back('\n');
				}
				tape[cellIndex] = userInput[0];
				userInput.erase(0, 1);
				break;
			case '[':
				if (!tape[cellIndex]) {
					instructionPointer = bracketPairs[instructionPointer];
				}
				break;
			case ']':
				if (tape[cellIndex]) {
					instructionPointer = bracketPairs[instructionPointer];
				}
				break;
			default:
				break;
		}
		instructionPointer++;
	}
}