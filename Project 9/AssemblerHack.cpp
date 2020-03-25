/*
Project : Hack Assembler
Author : Sarthak Kapoor
Date Created : 28 August 2019
Date Modified : 28 August 2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#define FILENAME "input"
#define MAXLENGTH 100  // MAXLENGTH of a line

using namespace std;

class Pair {
public:
	string symbol;
	int address;
};

class symbolTable {
	map<string, int> table;
	vector<Pair> arr;
	int size;
public:
	symbolTable() {
		/*Initialize table with predefined symbols*/
		table["SP"] = 0;
		table["LCL"] = 1;
		table["ARG"] = 2;
		table["THIS"] = 3;
		table["THAT"] = 4;
		table["R0"] = 0;
		table["R1"] = 1;
		table["R2"] = 2;
		table["R3"] = 3;
		table["R4"] = 4;
		table["R5"] = 5;
		table["R6"] = 6;
		table["R7"] = 7;
		table["R8"] = 8;
		table["R9"] = 9;
		table["R10"] = 10;
		table["R11"] = 11;
		table["R12"] = 12;
		table["R13"] = 13;
		table["R14"] = 14;
		table["R15"] = 15;
		table["SCREEN"] = 16384;
		table["KBD"] = 24576;
		size = 23;
	}
	void add(string symbol) {  /*Function to add symbol to symbol table with unknown address*/
		if (table.find(symbol) != table.end()) { /*If symbol already present, do nothing*/
			return;
		}
		table[symbol] = -1;
		Pair symb;
		symb.symbol = symbol;
		symb.address = -1;
		arr.push_back(symb);
		size++;
	}

	void add(string symbol, int address) { /*Function to add symbol to symbol table with known address (in case of label)*/
		if (table.find(symbol) != table.end()) { /*if symbol already present and is mapped to some address, throw error as label is present only once in the code */
			if (table[symbol] == -1) {
				table[symbol] = address;
				int i = 0;
				for (i = 0; i < arr.size(); i++) {
					if (symbol.compare(arr[i].symbol) == 0) {
						arr[i].address = address;
					}
				}
				return;
			}
			cout << "Error, label cannot be present at more than one location" << endl;
			return;
		}
		table[symbol] = address;
		size++;
	}

	void set() {  /*Called after first pass to set the variables with addresses starting from 16*/
		int i = 16;
		int j;
		for (j = 0; j < arr.size(); j++) {
			if (arr[j].address == -1) {
				arr[j].address = i;
				i++;
				table[arr[j].symbol] = arr[j].address;
			}
		}

	}

	void print() {  /*prints the table*/
		cout << "The Symbol table is" << endl;
		for (auto & it : table) {
			cout << it.first << " " << it.second << endl;
		}
	}

	int getAddress(string s) {
		return table[s];
	}

	int sizeOfTable() const { /*returns size of the table*/
		return size;
	}
};

void removeSpaces(const char* filename) {  // removes whiteSpaces from the input file
	ifstream input;
	input.open(filename);
	ofstream temp;
	temp.open("removeSpaces");
	while (!input.eof()) {
		string s;
		char* buffer = new char[MAXLENGTH];
		input.getline(buffer, MAXLENGTH, '\n');
		s = buffer;
		int i;
		string t = "";
		int j = 0;
		for (i = 0; i < s.length(); i++) {
			if (s[i] != ' ' && s[i] != '	') { // both spaces and tabs must be checked 
				t += s[i];
				j++;
			}
		}
		if (t.length() > 0) {  // if length of t is zero this means the whole line is a space
			temp << t << '\0' << '\n';
		}
	}
	input.close();
	temp.close();
}

void removeComments(const char* filename) {
	ifstream input;
	input.open(filename);
	ofstream temp;
	temp.open("removeComments");
	int count = 0; // to count the number of lines
	int flag = 0, indicate = 0;
	while (!input.eof()) {
		string s;
		char* buffer = new char[MAXLENGTH];
		input.getline(buffer, MAXLENGTH, '\n');
		s = buffer;
		count++;
		int i;
		string t(s);
		int j = 0;
		for (i = 0; i < s.length(); i++) {
			if (i + 1 < s.length() && s[i] == '/' && s[i + 1] == '/') { /*Break when '//' is found indicating a comment*/
				break;
			}
			else if (i + 1 < s.length() && s[i] == '/' && s[i + 1] == '*') {   /*Also consider /* for commenting */
				flag++;
				break;
			}
			else if (s[i] == '/') {  /*If only / is found  then throw error for unidentified symbol */
				cout << "Unidentified Symbol at " << count << endl;
				break;
			}
			else if (i + 1 < s.length() && s[i] == '*' && s[i + 1] == '/'  && flag == 1) {
				indicate = 1;
				break;
			}
			else if (i + 1 < s.length() && s[i] == '*' && s[i + 1] == '/' && flag == 0) {
				cout << "Unidentified Symbol at " << count << endl;
				break;
			}
			t[j] = s[i];
			j++;
		}
		if (j != 0 && flag == 0) {
			temp << t.substr(0, j) << '\0' << '\n';
		}
		if (indicate == 1) {
			flag = 0;
			indicate = 0;
		}
	}
	input.close();
	temp.close();
}

void setLabels(const char* filename) { // to remove any statement after a label
	ifstream i;
	i.open(filename);
	ofstream temp;
	temp.open("inter");
	while (!i.eof()) {
		char* buffer = new char[MAXLENGTH];
		i.getline(buffer, MAXLENGTH, '\n');
		string s = buffer;
		string t(s);
		if (s[0] == '(') {
			int i;
			string u = "";
			string v = "";
			for (i = 0; i < s.length(); i++) {
				if (s[i] == ')') {
					u += s[i];
					i++;
					break;
				}
				else {
					u += s[i];
				}
			}
			for (; i < s.length(); i++) {
				v += s[i];
			}
			temp << u << '\0' << '\n';
			if (v.length() > 0) {
				temp << v << '\0' << '\n';
			}
		}
		else {
			temp << t << '\0' << '\n';
		}
	}
	temp << EOF;
	i.close();
	temp.close();
}

int convertToDecimal(string s) {   //converts numerical string sequence to equivalent decimal expression
	int i;
	int num = 0;
	int fact = 1;
	for (i = s.length() - 1; i >= 0; i--) {
		num = num + fact * ((int)(s[i]) - 48);
		fact *= 10;
	}
	return num;
}

string convertToBinary(int num) {
	string binary = "";
	while (num > 0) {
		int rem = num % 2;
		if (rem == 1) {
			binary = '1' + binary;
		}
		else {
			binary = '0' + binary;
		}
		num /= 2;
	}
	int i;
	for (i = binary.length(); i < 16; i++) {
		binary = '0' + binary;
	}
	return binary;
}

string convertToBinary(string s) {
	int num = convertToDecimal(s);
	string binary = "";
	while (num > 0) {
		int rem = num % 2;
		if (rem == 1) {
			binary = '1' + binary;
		}
		else {
			binary = '0' + binary;
		}
		num /= 2;
	}
	int i;
	for (i = binary.length(); i < 16; i++) {
		binary = '0' + binary;
	}
	return binary;
}


string dataInstruction(string s) {  // to find data instruction
	if (s.compare("M") == 0) {
		return "001";
	}
	else if (s.compare("D") == 0) {
		return "010";
	}
	else if (s.compare("A") == 0) {
		return "100";
	}
	else if (s.compare("MD") == 0) {
		return "011";
	}
	else if (s.compare("DM") == 0) {
		return "011";
	}
	else if (s.compare("AD") == 0) {
		return "110";
	}
	else if (s.compare("DA") == 0) {
		return "110";
	}
	else if (s.compare("MA") == 0) {
		return "101";
	}
	else if (s.compare("AM") == 0) {
		return "101";
	}
	else if (s.compare("ADM") == 0) {
		return "111";
	}
	else if (s.compare("AMD") == 0) {
		return "111";
	}
	else if (s.compare("MAD") == 0) {
		return "111";
	}
	else if (s.compare("DAM") == 0) {
		return "111";
	}
	else if (s.compare("DMA") == 0) {
		return "111";
	}
	else if (s.compare("MDA") == 0) {
		return "111";
	}
	else {
		cout << "Error, unidentified instruction" << endl;
	}
}

string computeInstruction(string s) {
	if (s.compare("0") == 0) {
		return "0101010";
	}
	else if (s.compare("1") == 0) {
		return "0111111";
	}
	else if (s.compare("-1") == 0) {
		return "0111010";
	}
    else if (s.compare("D") == 0) {
		return "0001100";
	}
	else if (s.compare("A") == 0) {
		return "0110000";
	}
	else if (s.compare("M") == 0) {
		return "1110000";
	}
	else if (s.compare("D+A") == 0) {
		return "0000010";
	}
	else if (s.compare("A+D") == 0) {
		return "0000010";
	}
	else if (s.compare("D+M") == 0) {
		return "1000010";
	}
	else if (s.compare("M+D") == 0) {
		return "1000010";
	}
	else if (s.compare("!D") == 0) {
		return "0001101";
	}
	else if (s.compare("!A") == 0) {
		return "0110001";
	}
	else if (s.compare("!M") == 0) {
		return "1110001";
	}
	else if (s.compare("-D") == 0) {
		return "0001111";
	}
	else if (s.compare("-A") == 0) {
		return "0110011";
	}
	else if (s.compare("-M") == 0) {
		return "1110011";
	}
	else if (s.compare("D+1") == 0) {
		return "0011111";
	}
	else if (s.compare("A+1") == 0) {
		return "0110111";
	}
	else if (s.compare("M+1") == 0) {
		return "1110111";
	}
	else if (s.compare("1+D") == 0) {
		return "0110011";
	}
	else if (s.compare("1+A") == 0) {
		return "0110111";
	}
	else if (s.compare("1+M") == 0) {
		return "1110111";
	}
	else if (s.compare("D-1") == 0) {
		return "0001110";
	}
	else if (s.compare("A-1") == 0) {
		return "0110010";
	}
	else if (s.compare("M-1") == 0) {
		return "1110010";
	}
	else if (s.compare("D&A") == 0) {
		return "0000000";
	}
	else if (s.compare("A&D") == 0) {
		return "0000000";
	}
	else if (s.compare("D&M") == 0) {
		return "1000000";
	}
	else if (s.compare("M&D") == 0) {
		return "1000000";
	}
	else if (s.compare("D-A") == 0) {
		return "0010011";
	}
	else if (s.compare("D-M") == 0) {
		return "1010011";
	}
	else if (s.compare("A-D") == 0) {
		return "0000111";
	}
	else if (s.compare("M-D") == 0) {
		return "1000111";
	}
	else if (s.compare("D|A") == 0) {
		return "0010101";
	}
	else if (s.compare("A|D") == 0) {
		return "0010101";
	}
	else if (s.compare("D|M") == 0) {
		return "1010101";
	}
	else if (s.compare("M|D") == 0) {
		return "1010101";
	}
	else {
	    cout << "Error, unidentified instruction" << endl;
	}
}

string computeJump(string s) {
	if (s.compare("JGT") == 0) {
		return "001";
	}
	else if (s.compare("JEQ") == 0) {
		return "010";
	}
	else if (s.compare("JGE") == 0) {
		return "011";
	}
	else if (s.compare("JLT") == 0) {
		return "100";
	}
	else if (s.compare("JNE") == 0) {
		return "101";
	}
	else if (s.compare("JLE") == 0) {
		return "110";
	}
	else if (s.compare("JMP") == 0) {
		return "111";
	}
	else {
		cout << "Error, unidentified instruction" << endl;
	}
}

int main() {
	removeSpaces(FILENAME);
	removeComments("removeSpaces");
	setLabels("removeComments");
	ifstream inter;
	inter.open("inter");  //Inter File contains the assembly code without spaces and comments
	int count = 0;

	symbolTable table;
	//Pass 1 begins
	while (!inter.eof()) {
		char* buffer = new char[MAXLENGTH];
		inter.getline(buffer, MAXLENGTH, '\n');
		string s = buffer;
		count++;
		if (s[0] == '@') {  //instruction is an A instruction
			if (s.length() >= 2) {
				int digit = (int)(s[1]) - 48;
				if (digit >= 0 && digit <= 9) { //symbol is a constant number
					int i;
					for (i = 2; i < s.length(); i++) {
						digit = (int)(s[i]) - 48;
						if (digit < 0 || digit > 9) {
							cout << "Error at" << count << "Variable names must not start with a digit" << endl; // throw an error if first character is a digit but rest are not
							break;
						}
					}
					// s[1...] is a valid digit
				}
				
				else { // symbol is a variable
					table.add(s.substr(1, s.length() - 1));
				}
			}
		}
		else if (s[0] == '(') { // symbol is the beginning of a label
			int i;
			string t = "";
			if (s.length() >= 2) {
				int digit = (int)(s[1]) - 48;
				if (digit >= 0 && digit <= 9) {
					cout << "Invalid Label name at" << count << endl;
				}
			}
			for (i = 1; i < s.length(); i++) {
				if (s[i] != ')') {
					t += s[i];
				}
				if (s[i] == ')') {
					break;
				}
			}
			count--;
			table.add(t, count);
		}
	}
	table.set();
	// Pass 1 is complete and symbol table is populated
	ofstream out;
	out.open("output");
	inter.seekg(0, ios::beg);
	int orgCount = count;
	count = 0;

	//Pass 2 begins
	while (!inter.eof()) {
		char* buffer = new char[MAXLENGTH];
		inter.getline(buffer, MAXLENGTH, '\n');
		string s = buffer;
		count++;
		if (s[0] == '@') {  //instruction is an A instruction
			if (s.length() >= 1) {
				int digit = (int)(s[1]) - 48;
				if (digit >= 0 && digit <= 9) {
					int i;
					for (i = 2; i < s.length(); i++) {
						digit = (int)(s[i]) - 48;
						if (digit < 0 || digit > 9) {
							cout << "Variable names must not start with a digit" << endl; // throw an error if first character is a digit but rest are not
							break;
						}
					}
					// s[1...] is a valid digit
					string t = convertToBinary(s.substr(1, s.length() - 1));
					out << t << '\n';
				}
				else {  // the symbol is a variable and we must get the address
					int address = table.getAddress(s.substr(1, s.length() - 1));
					string t = convertToBinary(address);
					out << t << '\n';
				}
			}
		}
		else if (s[0] == '(') {
			// do nothing as it is a label
			count--;
		}
		else { // it is a C instruction
			string compute;
			string data;
			string jump;
			int flag = -1;
			int i;
			for (i = 0; i < s.length(); i++) {
				if (s[i] == '=') {
					flag = 0;
					break;
				}
				else if (s[i] == ';') {
					flag = 1;
					break;
				}
			}
			if (flag == -1) {
				if (count == orgCount - 1) {
					break;
				}
				cout << "Invalid C instruction at line " << count << endl;
				break;
			}
			if (flag == 0) { // it is a compute instruction
				jump = "000";
				int i;
				string t = "";
				for (i = 0; i < s.length(); i++) {
					if (s[i] == '=') {
						break;
					}
					else {
						t += s[i];
					}
				}
				data = dataInstruction(t);
				t = "";
				for (i = i + 1; i < s.length(); i++) {
					t += s[i];
				}
				compute = computeInstruction(t);
			}
			else { // it is a jump instruction
				data = "000";
				int i;
				string t = "";
				for (i = 0; i < s.length(); i++) {
					if (s[i] == ';') {
						break;
					}
					else {
						t += s[i];
					}
				}
				compute = computeInstruction(t);
				t = "";
				for (i = i + 1; i < s.length(); i++) {
					t += s[i];
				}
				jump = computeJump(t);
				
			}
			string ans = "111" + compute + data + jump;
			out << ans << '\n';
		}
	}   
	//Pass 2 Complete
	out.close();
	inter.close();
	return 0;
}