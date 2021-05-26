#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<utility>

using namespace std;

//�ؼ�������
vector<string> keywordVec= { "while","for","do","if","else","case","break","continue","switch",
					 "int","double","float","bool","short","long","string","char","void",
					 "public","private","static","return","true","false"};
//���������
//vector<string> operatorVec = { "+", "-", "*", "/", "<", "<=", ">", ">=", "=", "==","!","!="};
//���ַ������
vector<string> singleOperatorVec = { "+", "-", "*", "/" };
//�������
//vector<string> delimiterVec = { ";", "(", ")", ",", "[", "]", "{", "}" };

//�ж��Ƿ��ǹؼ���
bool ifKeyword(const string str){
	for (int i = 0; i < keywordVec.size(); i++) {
		if (str.compare(keywordVec[i]) == 0) return true;
	}
	return false;
}

//�ж��Ƿ��������
bool ifSingleOperator(const string str){
	for (int i = 0; i < singleOperatorVec.size(); i++) {
		if (str.compare(singleOperatorVec[i]) == 0) return true;
	}
	return false;
}
//�Ե����Ϸ����������ҷ�����DFA
//���൥��
//1. �ؼ���
//2. ��ʶ��
//3. ����
//4. �����
//5. ���

int main() {
	ifstream infile;
	infile.open("./text/test.txt");//�ļ���
	ofstream outfile;
	outfile.open("./text/output.txt");
	vector<pair<string, int>> resultVec;
	char wordChar;
	string str;
	wordChar = infile.get();

	while (!infile.eof()) {
		if (wordChar == ',' || wordChar == ';' || wordChar == '(' || wordChar == ')' || 
			wordChar == '[' || wordChar == ']' || wordChar == '{' || wordChar == '}'){//5.���
			//���������������
			str = "";
			str += wordChar;
			resultVec.push_back(make_pair(str, 5));
			wordChar = infile.get();
		}
		else if (wordChar == '+' || wordChar == '-' || wordChar == '/' || wordChar == '*') {//4.����������ַ���
			str = wordChar;
			resultVec.push_back(make_pair(str, 4));
			wordChar = infile.get();
		}
		else if (isdigit(wordChar)) {//3.����,�ѣ�
			str = "";
			while (isdigit(wordChar)) {//�жϸ��ַ��Ƿ�������
				str += wordChar;
				wordChar = infile.get();
				if (wordChar == '.') {//�жϸ��ַ��Ƿ���"."
					str += wordChar;
					wordChar = infile.get();
					if (isdigit(wordChar)) {
						while (isdigit(wordChar)) {
							str += wordChar;
							wordChar = infile.get();
						}
						resultVec.push_back(make_pair(str, 3));
						break;//�˳����whileѭ��
					}
					else {//С������治�����ֵ����
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
		else if (isalpha(wordChar)) {//1.�ؼ��� 2.��ʶ��
			str = "";
			while (isalpha(wordChar) || isdigit(wordChar)) {
				str += wordChar;
				wordChar = infile.get();
			}
			if (ifKeyword(str)) {//�ж��Ƿ��ǹؼ���
				resultVec.push_back(make_pair(str, 1));
			}
			else {//�ж��Ƿ��Ǳ�ʶ��
				if (str.size() >= 5) str = str.substr(0,5);
				resultVec.push_back(make_pair(str, 2));
			}
		}
		else if (wordChar == '<') {//4.���ַ������"<="���ַ������"<"
			str = "";
			str += wordChar;
			wordChar = infile.get();
			if (wordChar == '=') {
				str += wordChar;
				wordChar = infile.get();
			}
			resultVec.push_back(make_pair(str, 4));
		}
		else if (wordChar == '>') {//4.���ַ������">="���ַ������">"
			str = "";
			str += wordChar;
			wordChar = infile.get();
			if (wordChar == '=') {
				str += wordChar;
				wordChar = infile.get();
			}
			resultVec.push_back(make_pair(str, 4));
		}
		else if (wordChar == '=') {//4.���ַ������"=="���ַ������"="
			str = "";
			str += wordChar;
			wordChar = infile.get();
			if (wordChar == '=') {
				str += wordChar;
				wordChar = infile.get();
			}
			resultVec.push_back(make_pair(str,4));
		}
		else if (wordChar == '!') {//4.���ַ������"!="���ַ������"="
			str = "";
			str += wordChar;
			wordChar = infile.get();
			if (wordChar == '=') {
				str += wordChar;
				wordChar = infile.get();
			}
			resultVec.push_back(make_pair(str, 4));
		}
		else if (wordChar == ' ' || wordChar == 10 || wordChar == 13 || wordChar == 9) {//�ո�ͻ��з�����
			wordChar = infile.get();
		}
		else {//�������������,����@
			str = "";
			str += wordChar;
			resultVec.push_back(make_pair(str, -1));
			wordChar = infile.get();
		}
	}
	//����̨���
	for (int i = 0; i < resultVec.size(); i++) {
		cout << "---------------------------------" << endl;
		cout << "�ַ�: " << resultVec[i].first << "  ���:" <<resultVec[i].second<< endl;
	}
	//д���ļ�
	for (int i = 0; i < resultVec.size(); i++) {
		outfile << "�ַ�: " << resultVec[i].first << "  ���:" << resultVec[i].second << endl;
	}
	infile.close();
	outfile.close();
	system("pause");
	return 0;
}