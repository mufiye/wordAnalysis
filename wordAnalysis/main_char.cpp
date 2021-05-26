#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<utility>

using namespace std;

//关键字数组
vector<string> keywordVec= { "while","for","do","if","else","case","break","continue","switch",
					 "int","double","float","bool","short","long","string","char","void",
					 "public","private","static","return","true","false"};
//运算符数组
//vector<string> operatorVec = { "+", "-", "*", "/", "<", "<=", ">", ">=", "=", "==","!","!="};
//单字符运算符
vector<string> singleOperatorVec = { "+", "-", "*", "/" };
//界符数组
//vector<string> delimiterVec = { ";", "(", ")", ",", "[", "]", "{", "}" };

//判断是否是关键字
bool ifKeyword(const string str){
	for (int i = 0; i < keywordVec.size(); i++) {
		if (str.compare(keywordVec[i]) == 0) return true;
	}
	return false;
}

//判断是否是运算符
bool ifSingleOperator(const string str){
	for (int i = 0; i < singleOperatorVec.size(); i++) {
		if (str.compare(singleOperatorVec[i]) == 0) return true;
	}
	return false;
}
//自底向上分析，从左到右分析，DFA
//五类单词
//1. 关键字
//2. 标识符
//3. 常数
//4. 运算符
//5. 界符

int main() {
	ifstream infile;
	infile.open("./text/test.txt");//文件名
	ofstream outfile;
	outfile.open("./text/output.txt");
	vector<pair<string, int>> resultVec;
	char wordChar;
	string str;
	wordChar = infile.get();

	while (!infile.eof()) {
		if (wordChar == ',' || wordChar == ';' || wordChar == '(' || wordChar == ')' || 
			wordChar == '[' || wordChar == ']' || wordChar == '{' || wordChar == '}'){//5.界符
			//将界符存入结果向量
			str = "";
			str += wordChar;
			resultVec.push_back(make_pair(str, 5));
			wordChar = infile.get();
		}
		else if (wordChar == '+' || wordChar == '-' || wordChar == '/' || wordChar == '*') {//4.运算符（单字符）
			str = wordChar;
			resultVec.push_back(make_pair(str, 4));
			wordChar = infile.get();
		}
		else if (isdigit(wordChar)) {//3.常数,难！
			str = "";
			while (isdigit(wordChar)) {//判断该字符是否是数字
				str += wordChar;
				wordChar = infile.get();
				if (wordChar == '.') {//判断该字符是否是"."
					str += wordChar;
					wordChar = infile.get();
					if (isdigit(wordChar)) {
						while (isdigit(wordChar)) {
							str += wordChar;
							wordChar = infile.get();
						}
						resultVec.push_back(make_pair(str, 3));
						break;//退出大的while循环
					}
					else {//小数点后面不是数字的情况
						resultVec.push_back(make_pair(str, -1));
						break;
					}
				}
				if (!isdigit(wordChar)) {
					resultVec.push_back(make_pair(str, 3));
					break;
				}
			}
		}
		else if (isalpha(wordChar)) {//1.关键字 2.标识符
			str = "";
			while (isalpha(wordChar) || isdigit(wordChar)) {
				str += wordChar;
				wordChar = infile.get();
			}
			if (ifKeyword(str)) {//判断是否是关键字
				resultVec.push_back(make_pair(str, 1));
			}
			else {//判断是否是标识符
				if (str.size() >= 5) str = str.substr(0,5);
				resultVec.push_back(make_pair(str, 2));
			}
		}
		else if (wordChar == '<') {//4.多字符运算符"<="或单字符运算符"<"
			str = "";
			str += wordChar;
			wordChar = infile.get();
			if (wordChar == '=') {
				str += wordChar;
				wordChar = infile.get();
			}
			resultVec.push_back(make_pair(str, 4));
		}
		else if (wordChar == '>') {//4.多字符运算符">="或单字符运算符">"
			str = "";
			str += wordChar;
			wordChar = infile.get();
			if (wordChar == '=') {
				str += wordChar;
				wordChar = infile.get();
			}
			resultVec.push_back(make_pair(str, 4));
		}
		else if (wordChar == '=') {//4.多字符运算符"=="或单字符运算符"="
			str = "";
			str += wordChar;
			wordChar = infile.get();
			if (wordChar == '=') {
				str += wordChar;
				wordChar = infile.get();
			}
			resultVec.push_back(make_pair(str,4));
		}
		else if (wordChar == '!') {//4.多字符运算符"!="或单字符运算符"="
			str = "";
			str += wordChar;
			wordChar = infile.get();
			if (wordChar == '=') {
				str += wordChar;
				wordChar = infile.get();
			}
			resultVec.push_back(make_pair(str, 4));
		}
		else if (wordChar == ' ' || wordChar == 10 || wordChar == 13 || wordChar == 9) {//空格和换行符忽略
			wordChar = infile.get();
		}
		else {//其它的特殊符号,比如@
			str = "";
			str += wordChar;
			resultVec.push_back(make_pair(str, -1));
			wordChar = infile.get();
		}
	}
	//控制台输出
	for (int i = 0; i < resultVec.size(); i++) {
		cout << "---------------------------------" << endl;
		cout << "字符: " << resultVec[i].first << "  类别:" <<resultVec[i].second<< endl;
	}
	//写入文件
	for (int i = 0; i < resultVec.size(); i++) {
		outfile << "字符: " << resultVec[i].first << "  类别:" << resultVec[i].second << endl;
	}
	infile.close();
	outfile.close();
	system("pause");
	return 0;
}