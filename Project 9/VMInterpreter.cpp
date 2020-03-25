/*
Author : Sarthak Kapoor
Date Created : 10th July 2019
Last Modified : 13th July 2019
*/

#include <iostream>
#include <fstream>
#include <string>

#define MAXLENGTH 100
#define OUTFILENAME "output"

using namespace std;

void removeInitialSpaces(const char* filename) { // function to remove spaces until first instance of a character
	ifstream input;
	input.open(filename);
	ofstream spaceRem;
	spaceRem.open("spaceRem");
	char* buffer = new char[MAXLENGTH];
	while (input.good() && !input.eof()) {
		input.getline(buffer, MAXLENGTH, '\n');
		int i;
		char* temp = new  char[MAXLENGTH];
		for (i = 0; i < MAXLENGTH && buffer[i] != '\n'; i++) {
			if (buffer[i] != ' ') {
				break;
			}
		}
		int k = i;
		int j = 0;
		for (; i < MAXLENGTH && buffer[i] != '\n'; i++) {
			temp[j] = buffer[i];
			j++;
		}
		temp[j] = '\0';
		if (j != 0) {  // if whole line is a space, do not write
			spaceRem << temp << '\n';
		}
		else if (temp[0] == '/') {
			spaceRem << temp << '\n';
		}
	}
	input.close();
	spaceRem.close();
}

void writeIntoFile(const char* filename) {  // function to write code from user into VMInput
	ofstream input;
	input.open(filename);
	int n, i;
	cout << "Enter the number of lines" << endl;
	cin >> n;
	char* buffer = new char[MAXLENGTH];
	cout << "Enter VM code" << endl;
	for (i = 0; i < n + 1; i++) {
		cin.getline(buffer, MAXLENGTH, '\n');
		input << buffer << '\n';
	}
	input.close();
}


void getCodeForAL(const char* filename, const char* symbol1, int labelMarker) {  // function to evaluate 9 Arithmetic Logical Operations
	ofstream outputFile;
	outputFile.open(filename, ios::app);
	if (strcmp(symbol1, "add") == 0) {
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "A = A -1" << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "M = D + M" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M - 1" << '\n';
	}
	else if (strcmp(symbol1, "sub") == 0) {
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "A = A -1" << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "M = M - D" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M - 1" << '\n';
	}
	else if (strcmp(symbol1, "and") == 0) {
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "A = A -1" << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "M = M & D" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M - 1" << '\n';
	}
	else if (strcmp(symbol1, "or") == 0) {
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "A = A -1" << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "M = M | D" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M - 1" << '\n';
	}
	else if (strcmp(symbol1, "eq") == 0) {
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "D = M - D" << '\n';
		outputFile << "@IF" << labelMarker << filename << '\n';
		outputFile << "D;JEQ" << '\n';
		outputFile << "D = 0" << '\n';
		outputFile << "@ELSE" << (labelMarker + 1) << filename << '\n';
		outputFile << "0; JEQ" << '\n';
		outputFile << "(IF" << labelMarker << filename << ")" << '\n';
		outputFile << "D = -1" << '\n';
		outputFile << "(ELSE" << (labelMarker + 1) << filename << ")" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M - 1" << '\n';
		outputFile << "A = M -1" << '\n';
		outputFile << "M = D" << '\n';
	}
	else if (strcmp(symbol1, "lt") == 0) {
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "D = M - D" << '\n';
		outputFile << "@IF" << labelMarker << filename << '\n';
		outputFile << "D;JLT" << '\n';
		outputFile << "D = 0" << '\n';
		outputFile << "@ELSE" << (labelMarker + 1) << filename << '\n';
		outputFile << "0; JEQ" << '\n';
		outputFile << "(IF" << labelMarker << filename << ")" << '\n';
		outputFile << "D = -1" << '\n';
		outputFile << "(ELSE" << (labelMarker + 1) << filename << ")" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M - 1" << '\n';
		outputFile << "A = M -1" << '\n';
		outputFile << "M = D" << '\n';
	}
	else if (strcmp(symbol1, "gt") == 0) {
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "D = M - D" << '\n';
		outputFile << "@IF" << labelMarker << filename << '\n';
		outputFile << "D;JGT" << '\n';
		outputFile << "D = 0" << '\n';
		outputFile << "@ELSE" << (labelMarker + 1) << filename << '\n';
		outputFile << "0; JEQ" << '\n';
		outputFile << "(IF" << labelMarker << filename << ")" << '\n';
		outputFile << "D = -1" << '\n';
		outputFile << "(ELSE" << (labelMarker + 1) << filename << ")" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M - 1" << '\n';
		outputFile << "A = M -1" << '\n';
		outputFile << "M = D" << '\n';
	}
	else if (strcmp(symbol1, "not") == 0) {
		outputFile << "@SP" << '\n';
		outputFile << "A = M - 1" << '\n';
		outputFile << "M = !M" << '\n';
	}
	else if (strcmp(symbol1, "neg") == 0) {
		outputFile << "@SP" << '\n';
		outputFile << "A = M - 1" << '\n';
		outputFile << "M = -M" << '\n';
	}
	outputFile.close();
}


string getSegmentCode(const char* filename, const char* symbol2, const char* symbol3) {  // generate segment code as understandable by the assembler
	if (strcmp(symbol2, "local") == 0) {
		return "LCL";
	}
	else if (strcmp(symbol2, "argument") == 0) {
		return "ARG";
	}
	else if (strcmp(symbol2, "this") == 0) {
		return "THIS";
	}
	else if (strcmp(symbol2, "that") == 0) {
		return "THAT";
	}
	else if (strcmp(symbol2, "pointer") == 0) {
		return "3";
	}
	else if (strcmp(symbol2, "temp") == 0) {
		return "5";
	}
	else if (strcmp(symbol2, "static") == 0) {
		string file = filename;
		string symb3 = symbol3;
		return file + "." + symb3;
	}
	else if (strcmp(symbol2, "constant") == 0) {
		string symb2 = symbol2;
		return symb2;
	}
	else {
		cout << "segment name not found" << endl;
	}

}

int getNum(string symbol) { // converts string to number
	int i;
	int num = 0;
	int factor = 1;
	for (i = symbol.length() - 1; i >= 0; i--) {
		num = num + factor * (int)(symbol[i] - 48);
		factor = factor * 10;
	}
	return num;
}


void getCodePush(const char* filename, string segCode, int index, const char* symbol2) {

	ofstream outputFile;
	outputFile.open(filename, ios::app);
	if (segCode.compare("constant") == 0) { // code to push constant into file
		outputFile << "@" << index << '\n';
		outputFile << "D = A" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "M = D" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M + 1" << '\n';
	}
	else if (segCode.compare("5") == 0 || segCode.compare("3") == 0) { // code to push value from pointer and temp
		outputFile << "@" << segCode << '\n';
		outputFile << "D = A" << '\n';
		outputFile << "@" << index << '\n';
		outputFile << "A = D + A" << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "M = D" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M + 1" << '\n';
	}
	else if (strcmp(symbol2, "static") == 0) { // code to push value from static
		outputFile << "@" << segCode << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "M = D" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M + 1" << '\n';
	}
	else {
		outputFile << "@" << segCode << '\n'; // code to push value from a given segment and index
		outputFile << "D = M" << '\n';
		outputFile << "@" << index << '\n';
		outputFile << "A = D + A" << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "M = D" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M + 1" << '\n';
	}
	outputFile.close();
}

void getCodePop(const char* filename, string segCode, int index, const char* symbol2) {

	ofstream outputFile;
	outputFile.open(filename, ios::app);
	if (segCode.compare("LCL") == 0 || segCode.compare("ARG") == 0 || segCode.compare("THIS") == 0 || segCode.compare("THAT") == 0) {// code to pop to given segment and index
		outputFile << "@" << segCode << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "@" << index << '\n';
		outputFile << "D = A + D" << '\n';
		outputFile << "@R13" << '\n';
		outputFile << "M = D" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "@R13" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "M = D" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M - 1" << '\n';
	}
	else if (strcmp(symbol2, "static") == 0) {  // code to pop to static variable
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "@" << segCode << '\n';
		outputFile << "M = D" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M - 1" << '\n';
	}
	else if (segCode.compare("3") == 0 || segCode.compare("5") == 0) { // code to pop to location specified by pointer and temp
		outputFile << "@" << segCode << '\n';
		outputFile << "D = A" << '\n';
		outputFile << "@" << index << '\n';
		outputFile << "D = A + D" << '\n';
		outputFile << "@R13" << '\n';
		outputFile << "M = D" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "A = A - 1" << '\n';
		outputFile << "D = M" << '\n';
		outputFile << "@R13" << '\n';
		outputFile << "A = M" << '\n';
		outputFile << "M = D" << '\n';
		outputFile << "@SP" << '\n';
		outputFile << "M = M - 1" << '\n';
	}
	outputFile.close();
}

void generateCodeForFunctionCall(const char* filename, const char* symbol2, int numArg, int labelIndex) {
	ofstream outputFile;
	outputFile.open(filename, ios::app);
	string symb2 = symbol2;
	string labelFlag = "";
	labelFlag += (char)(labelIndex + 48);
	string fileLabel = filename;
	string callLabel = fileLabel + "." + labelFlag;
	// push callLabel
	outputFile << "@" << callLabel << '\n';
	outputFile << "D = A" << '\n';
	outputFile << "@SP" << '\n';
	outputFile << "A = M" << '\n';
	outputFile << "M = D" << '\n';
	outputFile << "@SP" << '\n';
	outputFile << "M = M + 1" << '\n';
	// push LCL of calling function
	outputFile << "@LCL" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@SP" << '\n';
	outputFile << "A = M" << '\n';
	outputFile << "M = D" << '\n';
	outputFile << "@SP" << '\n';
	outputFile << "M = M + 1" << '\n';
	// push ARG of calling function
	outputFile << "@ARG" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@SP" << '\n';
	outputFile << "A = M" << '\n';
	outputFile << "M = D" << '\n';
	outputFile << "@SP" << '\n';
	outputFile << "M = M + 1" << '\n';
	// push THIS of calling function
	outputFile << "@THIS" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@SP" << '\n';
	outputFile << "A = M" << '\n';
	outputFile << "M = D" << '\n';
	outputFile << "@SP" << '\n';
	outputFile << "M = M + 1" << '\n';
	// push THAT of calling function
	outputFile << "@THAT" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@SP" << '\n';
	outputFile << "A = M" << '\n';
	outputFile << "M = D" << '\n';
	outputFile << "@SP" << '\n';
	outputFile << "M = M + 1" << '\n';
	// ARG of called function is set as SP - numArg - 5
	outputFile << "@SP" << "\n";
	outputFile << "D = M" << '\n';
	outputFile << "@" << numArg << '\n';
	outputFile << "D = D - A" << '\n';
	outputFile << "@5" << '\n';
	outputFile << "D = D - A" << '\n';
	outputFile << "@ARG" << '\n';
	outputFile << "M = D" << '\n';
	// LCL of called function is set as SP
	outputFile << "@SP" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@LCL" << '\n';
	outputFile << "M = D" << '\n';
	//call next function
	outputFile << "@" << symbol2 << '\n';
	outputFile << "0; JEQ" << '\n';
	// call label is added to take control after the called function returns
	outputFile << "(" << callLabel << ")" << '\n';
	outputFile.close();
}

void generateCodeForFunctionDefinition(const char* filename, const char* symbol2, int numLocal, int counter) {

	ofstream outputFile;
	outputFile.open(filename, ios::app);
	outputFile << "(" << symbol2 << ") // function created" << '\n';
	outputFile << "@i" << '\n';
	outputFile << "M = 0" << '\n';
	outputFile << "(LOOP" << counter << filename << ")" << '\n';
	outputFile << "@" << numLocal << '\n';
	outputFile << "D = A" << '\n';
	outputFile << "@i" << '\n';
	outputFile << "D = D - M" << '\n';
	outputFile << "@ENDLOOP" << counter << filename << '\n';
	outputFile << "D; JEQ" << '\n';
	outputFile << "@LCL" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@i" << '\n';
	outputFile << "A = D + M" << '\n';
	outputFile << "M = 0" << '\n';
	outputFile << "@i" << '\n';
	outputFile << "M = M + 1" << '\n';
	outputFile << "@LOOP" << counter << filename << '\n';
	outputFile << "0; JEQ" << '\n';
	outputFile << "(ENDLOOP" << counter << filename << ")" << '\n';
	outputFile << "@i" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@LCL" << '\n';
	outputFile << "D = D + M" << '\n';
	outputFile << "@SP" << '\n';
	outputFile << "M = D" << '\n';
	outputFile.close();
}


void generateCodeForFunctionReturn(const char* filename, int labelIndex) {
	ofstream outputFile;
	outputFile.open(filename, ios::app);
	string labelFlag = "";
	labelFlag += (char)(labelIndex + 48);
	string fileLabel = filename;
	string callLabel = fileLabel + "." + labelFlag;
	outputFile << "@LCL" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@R13" << '\n';
	outputFile << "M = D" << '\n';

	outputFile << "@5" << '\n';
	outputFile << "A = D - A" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@R14" << '\n';
	outputFile << "M = D" << '\n';

	outputFile << "@SP" << '\n';
	outputFile << "M = M - 1" << '\n';
	outputFile << "A = M" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@ARG" << '\n';
	outputFile << "A = M" << '\n';
	outputFile << "M = D" << '\n';

	outputFile << "@ARG" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@SP" << '\n';
	outputFile << "M = D + 1" << '\n';

	outputFile << "@R13" << '\n';
	outputFile << "M = M - 1" << '\n';
	outputFile << "A = M" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@THAT" << '\n';
	outputFile << "M = D" << '\n';

	outputFile << "@R13" << '\n';
	outputFile << "M = M - 1" << '\n';
	outputFile << "A = M" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@THIS" << '\n';
	outputFile << "M = D" << '\n';

	outputFile << "@R13" << '\n';
	outputFile << "M = M - 1" << '\n';
	outputFile << "A = M" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@ARG" << '\n';
	outputFile << "M = D" << '\n';

	outputFile << "@R13" << '\n';
	outputFile << "M = M - 1" << '\n';
	outputFile << "A = M" << '\n';
	outputFile << "D = M" << '\n';
	outputFile << "@LCL" << '\n';
	outputFile << "M = D" << '\n';

	outputFile << "@R14" << '\n';
	outputFile << "A = M" << '\n';
	outputFile << "0; JEQ //returned" << '\n';


	outputFile.close();
}


int main(int argc, char** argv) {
	writeIntoFile("VMInput"); // VMInput contains VM code generated by compiler
	removeInitialSpaces("VMInput");
	ifstream interFile;
	interFile.open("spaceRem");// spaceRem is the space removed file
	char* buffer = new char[MAXLENGTH];
	ofstream tempFile;
	tempFile.open("temp");
	ofstream outputFile;
	outputFile.open(OUTFILENAME);
	outputFile.close();
	int counter = 0;
	int funcLabel = 0;
	while (interFile.good() && !interFile.eof()) {
		interFile.getline(buffer, MAXLENGTH, '\n');
		counter += 2;
		int i;
		char* symbol1 = new char[MAXLENGTH];  // symbol1 holds the first statement
		char* symbol2 = new char[MAXLENGTH];  // symbol2 holds the second statement
		char* symbol3 = new char[MAXLENGTH];  // symbol3 holds the third statement
		char* comment = new char[MAXLENGTH];  // comment holds the comments
		int k = 0;
		for (i = 0; i < MAXLENGTH; i++) {
			if (buffer[i] == '/' && buffer[i + 1] == '/') {
				break;
			}
		}
		int limit = i;
		k = 0;
		for (i = 0; i < limit && buffer[i] != '\n'; i++) {
			if (buffer[i] != ' ') {
				symbol1[k] = buffer[i];
				k++;
			}
			else {
				break;
			}
		}
		while (i < limit && buffer[i] == ' ') {
			i++;
		}
		symbol1[k] = '\0';
		k = 0;
		for (; i < limit && buffer[i] != '\n'; i++) {
			if (buffer[i] != ' ') {
				symbol2[k] = buffer[i];
				k++;
			}
			else {
				break;
			}
		}
		while (i < limit && buffer[i] == ' ') {
			i++;
		}
		symbol2[k] = '\0';
		k = 0;
		for (; i < limit && buffer[i] != '\n'; i++) {
			if (buffer[i] != ' ') {
				symbol3[k] = buffer[i];
				k++;
			}
			else {
				break;
			}
		}
		symbol3[k] = '\0';
		k = 0;
		for (i = limit; i < MAXLENGTH && buffer[i] != '\n'; i++) {
			comment[k] = buffer[i];
			k++;
		}
		comment[k] = '\0';
		tempFile << symbol1 << "  " << symbol2 << "  " << symbol3 << "  " << comment << '\n';
		string segCode;
		int index;
		string symb3 = symbol3;
		if (strlen(symbol1) == 0) { // comment which is directly written into file
			ofstream outputFile;
			outputFile.open(OUTFILENAME, ios::app);
			outputFile << comment << '\n';
			outputFile.close();
		}
		else if (strcmp(symbol1, "push") == 0 || strcmp(symbol1, "pop") == 0) { // memory access command
			if (strlen(symbol2) == 0) {
				// cout << "Error, segment name missing" << endl; // do nothing as we have an empty line
			}
			else if (symb3.length() != 0) {
				segCode = getSegmentCode(OUTFILENAME, symbol2, symbol3);
			}
			if (symb3.length() == 0) {
				cout << "Index missing" << endl;
			}
			else {
				index = getNum(symb3);
			}
			if (strcmp(symbol1, "push") == 0) {
				getCodePush(OUTFILENAME, segCode, index, symbol2); // generates the code for push
			}
			else {
				getCodePop(OUTFILENAME, segCode, index, symbol2);// generates the code for pop
			}
		}
		else if (strcmp(symbol1, "label") == 0) {
			if (strlen(symbol2) == 0) {
				cout << "Error, label name missing" << endl;
			}

			else if (symbol2[0] == '(') {
				ofstream outputFile;
				outputFile.open(OUTFILENAME, ios::app);
				outputFile << symbol2 << '\n';
				outputFile.close();
			}

			else if (symbol2[0] != '(') {
				ofstream outputFile;
				outputFile.open(OUTFILENAME, ios::app);
				outputFile << "(" << symbol2 << ")" << '\n';
				outputFile.close();
			}

		}
		else if (strcmp(symbol1, "goto") == 0) {
			if (strlen(symbol2) == 0) {
				cout << "Error, label name missing" << endl;
			}
			else {
				ofstream outputFile;
				outputFile.open(OUTFILENAME, ios::app);
				outputFile << "@" << symbol2 << '\n';
				outputFile << "0; JEQ" << '\n';
				outputFile.close();
			}
		}
		else if (strcmp(symbol1, "if-goto") == 0) {
			if (strlen(symbol2) == 0) {
				cout << "Error, label name missing" << endl;
			}

			ofstream outputFile;
			outputFile.open(OUTFILENAME, ios::app);
			outputFile << "@SP" << '\n';
			outputFile << "M = M - 1" << '\n';
			outputFile << "A = M" << '\n';
			outputFile << "D = M" << '\n';
			outputFile << "@" << symbol2 << '\n';
			outputFile << "D; JNE" << '\n';
			outputFile.close();
		}
		else if (strcmp(symbol1, "call") == 0) {
			if (strlen(symbol2) == 0) {
				cout << "Called function name missing" << endl;
			}
			else if (strlen(symbol3) == 0) {
				cout << "Number of arguments missing" << endl;
			}
			else {
				string symb3 = symbol3;
				int numArg = getNum(symb3);
				generateCodeForFunctionCall(OUTFILENAME, symbol2, numArg, funcLabel);
				funcLabel++;
			}
		}
		else if (strcmp(symbol1, "function") == 0) {
			if (strlen(symbol2) == 0) {
				cout << "Called function name missing" << endl;
			}
			else if (strlen(symbol3) == 0) {
				cout << "Number of local variables missing" << endl;
			}
			else {
				string symb3 = symbol3;
				int numLocal = getNum(symb3);
				generateCodeForFunctionDefinition(OUTFILENAME, symbol2, numLocal, counter);
			}
		}
		else if (strcmp(symbol1, "return") == 0) {
			generateCodeForFunctionReturn(OUTFILENAME, funcLabel);
		}
		else {  // Arithmetic Logical Command
			if (strlen(symbol2) != 0 || strlen(symbol3) != 0) {
				cout << "Error, improper syntax" << endl;
			}
			getCodeForAL(OUTFILENAME, symbol1, counter);
		}
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
