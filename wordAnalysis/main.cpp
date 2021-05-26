//#include<iostream>
//#include<string>
//#include<fstream>
//#include<vector>
//#include<utility>
//
//using namespace std;
//
////关键字数组
//vector<string> keywordVec= { "while","for","do","if","else","case","break","continue","switch",
//					 "int","double","float","bool","short","long","string","char","void",
//					 "public","private","static","return"};
////运算符数组
//vector<string> operatorVec = { "+", "-", "*", "/", "<", "<=", ">", ">=", "=", "==","!="};
////界符数组
//vector<string> delimiterVec = { ";", "(", ")", ",", "[", "]", "{", "}" };
//
////判断是否是关键字
//bool ifKeyword(const string str){
//	for (int i = 0; i < keywordVec.size(); i++) {
//		if (str.compare(keywordVec[i]) == 0) return true;
//	}
//	return false;
//}
//
////判断是否是运算符
//bool ifOperator(const string str){
//	for (int i = 0; i < operatorVec.size(); i++) {
//		if (str.compare(operatorVec[i]) == 0) return true;
//	}
//	return false;
//}
//
////判断是否是界符
//bool ifDelimiter(const string str){
//	for (int i = 0; i < delimiterVec.size(); i++) {
//		if (str.compare(delimiterVec[i]) == 0) return true;
//	}
//	return false;
//}
//
////有问题！
//////判断是否是数字
////bool ifNumber(const string str) {
////	for (int i = 0; i < str.length(); i++) {
////		if (!isdigit(str[i])) return false;
////	}
////	return true;
////}
//
////分割字符串
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
////查看该字符是否包含某个字符串
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
////先是要将文件中的或者控制台输入的字符串读进来
////读进来之后进行处理
////五类单词
////1. 关键字
////2. 标识符
////3. 常数
////4. 运算符
////5. 界符
//
////处理的步骤，此处的输入是整串的字符串
////1.先以空格为分隔符进行分割 
////2.之后再以运算符和界符为分隔符进行分割，运算符和界符也要作为单词计入单词序列 
////3.之后对于剩下的字符串首先判断是否是关键字，再判断是否是常数，最后判断是否是标识符（如果不是则报错）
////4.最后输出一个单词序列
//
//int Nomain(){
//	// 以读模式打开文件
//	string totalStr = "",temp = "";
//	vector<string> strVec;
//	vector<pair<string,int>> resultVec;
//	ifstream infile;
//	infile.open("./text/test.txt");//文件名
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
//	//词法分析操作
//	//用int表示词语类型，1=关键字 2=标识符 3=常数 4=运算符 5=界符
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
//	// 关闭打开的文件
//	infile.close();
//
//	return 0;
//
//}