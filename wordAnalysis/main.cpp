//#include<iostream>
//#include<string>
//#include<fstream>
//#include<vector>
//#include<utility>
//
//using namespace std;
//
////�ؼ�������
//vector<string> keywordVec= { "while","for","do","if","else","case","break","continue","switch",
//					 "int","double","float","bool","short","long","string","char","void",
//					 "public","private","static","return"};
////���������
//vector<string> operatorVec = { "+", "-", "*", "/", "<", "<=", ">", ">=", "=", "==","!="};
////�������
//vector<string> delimiterVec = { ";", "(", ")", ",", "[", "]", "{", "}" };
//
////�ж��Ƿ��ǹؼ���
//bool ifKeyword(const string str){
//	for (int i = 0; i < keywordVec.size(); i++) {
//		if (str.compare(keywordVec[i]) == 0) return true;
//	}
//	return false;
//}
//
////�ж��Ƿ��������
//bool ifOperator(const string str){
//	for (int i = 0; i < operatorVec.size(); i++) {
//		if (str.compare(operatorVec[i]) == 0) return true;
//	}
//	return false;
//}
//
////�ж��Ƿ��ǽ��
//bool ifDelimiter(const string str){
//	for (int i = 0; i < delimiterVec.size(); i++) {
//		if (str.compare(delimiterVec[i]) == 0) return true;
//	}
//	return false;
//}
//
////�����⣡
//////�ж��Ƿ�������
////bool ifNumber(const string str) {
////	for (int i = 0; i < str.length(); i++) {
////		if (!isdigit(str[i])) return false;
////	}
////	return true;
////}
//
////�ָ��ַ���
////https://zhuanlan.zhihu.com/p/56163976
//void split(const string& s, vector<string>& tokens, char delim = ' ') {
//	tokens.clear();
//	auto string_find_first_not = [s, delim](size_t pos = 0) -> size_t {
//		for (size_t i = pos; i < s.size(); i++) {
//			if (s[i] != delim) return i;
//		}
//		return string::npos;
//	};
//	size_t lastPos = string_find_first_not(0);
//	size_t pos = s.find(delim, lastPos);
//	while (lastPos != string::npos) {
//		tokens.emplace_back(s.substr(lastPos, pos - lastPos));
//		lastPos = string_find_first_not(pos);
//		pos = s.find(delim, lastPos);
//	}
//}
//
////�鿴���ַ��Ƿ����ĳ���ַ���
//bool isContainsStr(const string str,const string contains_str)
//{
//	string::size_type idx = str.find(contains_str);
//	if (idx != string::npos)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
////����Ҫ���ļ��еĻ��߿���̨������ַ���������
////������֮����д���
////���൥��
////1. �ؼ���
////2. ��ʶ��
////3. ����
////4. �����
////5. ���
//
////����Ĳ��裬�˴����������������ַ���
////1.���Կո�Ϊ�ָ������зָ� 
////2.֮������������ͽ��Ϊ�ָ������зָ������ͽ��ҲҪ��Ϊ���ʼ��뵥������ 
////3.֮�����ʣ�µ��ַ��������ж��Ƿ��ǹؼ��֣����ж��Ƿ��ǳ���������ж��Ƿ��Ǳ�ʶ������������򱨴�
////4.������һ����������
//
//int Nomain(){
//	// �Զ�ģʽ���ļ�
//	string totalStr = "",temp = "";
//	vector<string> strVec;
//	vector<pair<string,int>> resultVec;
//	ifstream infile;
//	infile.open("./text/test.txt");//�ļ���
//
//	//cout << "Reading from the file" << endl;
//
//	while (getline(infile, temp))
//	{
//		totalStr = totalStr + temp + " ";
//	}
//	cout << totalStr << endl;
//	split(totalStr, strVec);
//	//cout << "---------------------------------------"<<endl;
//	//cout << "---------------------------------------"<<endl;
//	//for (int i = 0; i < strVec.size(); i++) {
//	//	cout << strVec[i] << endl;
//	//}
//
//	//�ʷ���������
//	//��int��ʾ�������ͣ�1=�ؼ��� 2=��ʶ�� 3=���� 4=����� 5=���
//	for (int i = 0; i < strVec.size(); i++) {
//		if(ifKeyword(strVec[i])) {
//			resultVec.push_back(make_pair(strVec[i],1));
//			continue;
//		}
//		else if(ifNumber(strVec[i])) {
//			resultVec.push_back(make_pair(strVec[i], 3));
//			continue;
//		}
//		else if() {
//
//		}
//	}
//
//	system("pause");
//	// �رմ򿪵��ļ�
//	infile.close();
//
//	return 0;
//
//}