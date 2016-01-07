
#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main(){
	locale loc("C");
	cout << loc.name() << endl;
	locale lo("chs");
	cout << lo.name() << endl;
}

// #include <iostream>
// #include <locale>
// using namespace std;

// int main(){
// 	locale loc("french");
// 	cout << loc.name() << endl;

// 	locale def;
// 	cout << def.name() << endl;
// 	locale current = cout.getloc();
// 	cout << current.name() << endl;
// 	float val = 1234.56;
// 	cout << "哈哈" << endl;
// 	cout << val << endl;

// 	cout.imbue(locale("en_US.UTF8"));
// 	current = cout.getloc();
// 	cout << current.name() << endl;
// 	cout << val << endl;

// 	cout << "Enter the literal: ";
// 	cin >> val;
// 	cout.imbue(def);
// 	cout << val << endl;
// }

// #include <fstream>
// #include <iostream>
// #include "DataLogger.h"
// #include "../require.h"
// using namespace std;

// int main(){
// 	ifstream bindata("data.bin", ios::binary);
// 	assure(bindata, "data.bin");
// 	DataPoint d;
// 	while(bindata.read(reinterpret_cast<char*>(&d), sizeof d))
// 		cout << d << endl;
// }

// #include <cstddef>
// #include <cstdlib>
// #include <cstdio>
// #include <fstream>
// #include <iostream>
// #include <sstream>
// #include <string>
// #include "../require.h"
// using namespace std;

// const string USAGE = 
//     "USAGE";

// class Showerr{
//     const int CHAP;
//     const string MARKER, FNAME;
//     const string ERRNUM;
//     const string ERRFILE;
//     stringstream edited;
//     int counter;
// public:
// 	Showerr(const string& f, const string& en, const string& ef, int c)
// 	    : CHAP(c), MARKER("//!"), FNAME(f), ERRNUM(en), ERRFILE(ef), counter(0) {}
// 	void replaceErrors(){
// 		ifstream infile(FNAME.c_str());
// 		assure(infile, FNAME.c_str());
// 		ifstream count(ERRNUM.c_str());
// 		assure(count, ERRNUM.c_str());
// 		if(count) count >> counter;
// 		int linecount = 1;
// 		string buf;
// 		ofstream errlines(ERRFILE.c_str(), ios::app);
// 		assure(errlines, ERRFILE.c_str());
// 		while(getline(infile, buf)){
// 			size_t pos = buf.find(MARKER);
// 			if(pos != string::npos){
// 				ostringstream out;
// 				out << buf << " // (" << ++counter << ") "
// 				    << "Chapter " << CHAP
// 				    << "File: " << FNAME
// 				    << "line " << linecount << endl;
// 				    edited << out.str();
// 				    errlines << out.str();
// 			}
// 			else
// 				edited << buf << "\n";
// 			++linecount;
// 		}
// 	}
// 	void saveFiles(){
// 		ofstream outfile(FNAME.c_str());
// 		assure(outfile, FNAME.c_str());
// 		outfile << edited.rdbuf();
// 		ofstream count(ERRNUM.c_str());
// 		assure(count, ERRNUM.c_str());
// 		cout << counter;
// 	}	
// };

// int main(int argc, char const *argv[])
// {
// 	const string ERRCOUNT("../errnum.txt"), ERRFILE("../errlines.txt");
// 	requireMinArgs(argc, 1, USAGE.c_str());
// 	if (argv[1][0] == '/' || argv[1][0] == '-'){
// 		switch(argv[1][1]){
// 			case 'r': case 'R':
// 			    cout <<"reset counter" << endl;
// 			    remove(ERRCOUNT.c_str());
// 			    remove(ERRFILE.c_str());
// 			    return EXIT_SUCCESS;
// 			default:
// 			    cerr << USAGE << endl;
// 			    return EXIT_FAILURE;
// 		}
// 	}
// 	if(argc == 3){
// 		Showerr s(argv[1], ERRCOUNT, ERRFILE, atoi(argv[2]));
// 		s.replaceErrors();
// 		s.saveFiles();
// 	}
// }

// #include <fstream>
// #include <sstream>
// #include <string>
// #include <cstddef>
// #include "../require.h"
// using namespace std;

// bool startsWith(const string& base, const string& key){
// 	return base.compare(0, key.size(), key) == 0;
// }

// void cppCheck(string fileName){
// 	enum bufs { BASE, HEADER, IMPLEMENT, HLINE1, GUARD1, 
// 	            GUARD2, GUARD3, CPPLINE1, INCLUDE, BUFNUM, };
//     string part[BUFNUM];
//     part[BASE] = fileName;
//     size_t loc = part[BASE].find('.');
//     if(loc != string::npos)
//     	part[BASE].erase(loc);
//     for(size_t i = 0; i < part[BASE].size(); i++)
//     	part[BASE][i] = toupper(part[BASE][i]);
//     part[HEADER] = part[BASE] + ".h";
//     part[IMPLEMENT] = part[BASE] + ".cpp";
//     part[HLINE1] = "//: " + part[HEADER];
//     part[GUARD1] = "#ifndef " + part[BASE] + "_H";
//     part[GUARD2] = "#define " + part[BASE] + "_H";
//     part[GUARD3] = "#endif // " + part[BASE] + "_H";
//     part[CPPLINE1] = string("//") + ": " + part[IMPLEMENT];
//     part[INCLUDE] = "#include \"" + part[HEADER] +"\"";

//     ifstream existh(part[HEADER].c_str()),
//              existcpp(part[IMPLEMENT].c_str());
//     if(!existh){
//     	ofstream newheader(part[HEADER].c_str());
//     	assure(newheader, part[HEADER].c_str());
//     	newheader << part[HLINE1] << endl
//     	          << part[GUARD1] << endl
//     	          << part[GUARD2] << endl << endl
//     	          << part[GUARD3] << endl;
//     }else{
//     	stringstream hfile;
//     	ostringstream newheader;
//     	hfile << existh.rdbuf();
//     	bool changed = false;
//     	string s;
//     	hfile.seekg(0);
//     	getline(hfile, s);
//     	bool lineUsed = false;
//     	for(int line = HLINE1; hfile.good() && line <= GUARD2; ++line){
//     		if (startsWith(s, part[line])){
//     			newheader << s << endl;
//     			lineUsed = true;
//     			if(getline(hfile, s))
//     				lineUsed = false;
//     		}else{
//     			newheader << part[line] << endl;
//     			changed = true;
//     			lineUsed = false;
//     		}
//     	}
//     	if(!lineUsed)
//     		newheader << s << endl;
//     	newheader << hfile.rdbuf();
//     	string head = hfile.str();
//     	if (head.find(part[GUARD3]) == string::npos){
//     		newheader << part[GUARD3] << endl;
//     		changed = true;
//     	}
//     	if(changed){
//     		existh.close();
//     		ofstream newH(part[HEADER].c_str());
//     		assure(newH, part[HEADER].c_str());
//     		newH << "//@//\n" << newheader.str();
//     	}
//     }
//     if(!existcpp){
//     	ofstream newcpp(part[IMPLEMENT].c_str());
//     	assure(newcpp, part[IMPLEMENT].c_str());
//     	newcpp << part[CPPLINE1] << endl
//     	       << part[INCLUDE] << endl;
//     }else{
//     	stringstream cppfile;
//     	ostringstream newcpp;
//     	cppfile << existcpp.rdbuf();
//     	bool changed = false;
//     	string s;
//     	cppfile.seekg(0);
//     	getline(cppfile, s);
//     	bool lineUsed = false;
//     	for(int line = CPPLINE1; cppfile.good() && line <= INCLUDE; ++line){
//     		if (startsWith(s, part[line])){
//     			newcpp << s << endl;
//     			lineUsed = true;
//     			if(getline(cppfile, s))
//     				lineUsed = false;
//     		}else{
//     			newcpp << part[line] << endl;
//     			changed = true;
//     			lineUsed = false;
//     		}
//     	}
//     	if(!lineUsed)
//     		newcpp << s << endl;
//     	newcpp << cppfile.rdbuf();
//     	if (changed){
//     		existcpp.close();
//     		ofstream newCPP(part[IMPLEMENT].c_str());
//     		assure(newCPP, part[IMPLEMENT].c_str());
//     		newCPP << "//@//\n" << newcpp.str();
//     	}
//     }
// }

// int main(int argc, char const *argv[])
// {
// 	if(argc > 1)
// 		cppCheck(argv[1]);
// 	else
// 		cppCheck("cppCheckTest.h");
// }

// #include <iostream>
// #include <limits>
// #include <sstream>
// #include <string>
// using namespace std;

// class Fixw{
//     string str;
// public:
// 	Fixw(const string& s, int width) : str(s, 0, width) {}
// 	friend ostream& operator<<(ostream& os, const Fixw& fw){
// 		return os << fw.str;
// 	}	
// };

// typedef unsigned long ulong;

// class Bin{
//     ulong n;
// public:
// 	Bin(ulong nn) : n(nn) {}
// 	friend ostream& operator<<(ostream& os, const Bin& b){
// 		const ulong ULMAX = numeric_limits<ulong>::max();
// 		ulong bit = ~(ULMAX >> 1);
// 		while(bit){
// 			os << (b.n & bit ? '1' : '0');
// 			bit >>= 1;
// 		}
// 		return os;
// 	}	
// };

// int main(){
// 	string words = "Things that make us happy, make us wise";
// 	for(int i = words.size(); --i >= 0;){
// 		ostringstream s;
// 		s << Fixw(words, i);
// 		// cout << s.str() << endl;
// 		// cout << words.substr(0, i) << endl;
// 	}
// 	ostringstream xs, ys;
// 	xs << Bin(0xCAFEBABEUL);
// 	cout << xs.str() << endl;
// 	ys << Bin(0x76543210UL);
// 	cout << ys.str() << endl;
// 	cout << hex << numeric_limits<ulong>::max() << endl;
// }

// #include <iostream>
// using namespace std;

// ostream& nl(ostream& os){
// 	return os << '\n';
// }

// int main(){
// 	cout << "newlines" << nl << "between" << nl 
// 	     << "each" << (nl) << "word" << nl;
// }

// #include <fstream>
// #include <iostream>
// #include "../require.h"
// using namespace std;
// #define D(A) T << #A << endl; A

// int main(){
// 	ofstream T("format.out");
// 	assure(T);
// 	D(int i = 47;)
// 	D(float f = 20391039.2345;)
// 	const char* s = "Is there anymore?";
// 	D(T.setf(ios::unitbuf);)
// 	D(T.setf(ios::showbase);)
// 	D(T.setf(ios::uppercase | ios::showpos);)
// 	D(T << i << endl;)
// 	D(T.setf(ios::hex, ios::basefield);)
// 	D(T << i << endl;)
// 	D(T.setf(ios::oct, ios::basefield);)
// 	D(T << i << endl;)
// 	D(T.unsetf(ios::showbase);)
// 	D(T.setf(ios::dec, ios::basefield);)
// 	D(T.setf(ios::left, ios::adjustfield);)
// 	D(T.fill('*');)
// 	D(T << "fill char: " << T.fill() << endl;)
// 	D(T.width(10);)
// 	T << i << endl;
// 	D(T.setf(ios::right, ios::adjustfield);)
// 	D(T.width(10);)
// 	T << i << endl;
// 	D(T.setf(ios::internal, ios::adjustfield);)
// 	D(T.width(10);)
// 	T << i << endl;
// 	D(T << i << endl;)

// 	D(T.unsetf(ios::showpos);)
// 	D(T.setf(ios::showpoint);)
// 	D(T << "prec = " << T.precision() << endl;)
// 	D(T.setf(ios::scientific, ios::floatfield);)
// 	D(T << f << endl;)
// 	D(T.setf(ios::fixed, ios::floatfield);)
// 	D(T << f << endl;)

// 	D(T.precision(20);)
// 	D(T << "prec = " << T.precision() << endl;)
// 	D(T << f << endl;)
// 	D(T.setf(ios::scientific, ios::floatfield);)
// 	D(T << f << endl;)
// 	D(T.setf(ios::fixed, ios::floatfield);)
// 	D(T << f << endl;)

// 	D(T.width(10);)
// 	T << s << endl;
// 	D(T.width(40);)
// 	T << s << endl;
// 	D(T.setf(ios::left, ios::adjustfield);)
// 	D(T.width(40);)
// 	T << s << endl;
// 	D(T.setf(ios::right, ios::adjustfield);)
// 	D(T.width(40);)
// 	T << s << endl;
// 	D(T.setf(ios::internal, ios::adjustfield);)
// 	D(T.width(40);)
// 	T << s << endl;
// 	D(T.fill(' ');)
// 	D(T.setf(ios::left, ios::adjustfield);)
// 	D(T.width(40);)
// 	T << s << endl;
// }

// #include <iostream>
// using namespace std;

// int main(){
// 	cout.unsetf(ios::showpoint);
// 	cout << 0987633456780.3 << endl;
// 	// int i = ios::width();
// 	// cout << i << endl;
// }

// #include <cstdlib>
// #include <fstream>
// #include <iostream>
// using namespace std;

// int main(){
// 	ofstream out("log.txt");
// 	out.unsetf(ios::unitbuf);
// 	out << "one" << endl;
// 	out << "two" << endl;
// 	abort();
// }

// #include <cassert>
// #include <sstream>
// #include <string>
// #include <iostream>
// using namespace std;

// int main(){
// 	string text = "We will hook no fish";
// 	stringstream ss(text);
// 	ss.seekp(0, ios::end);
// 	ss << " before its time.";
// 	cout << ss.str() << endl;
// 	ss.seekg(8, ios::beg);
// 	string word;
// 	ss >> word;
// 	cout << word << endl;
// 	ss.seekp(8, ios::beg);
// 	// cout << ss.str() << endl;
// 	ss << "ship";
// 	cout << ss.str() << endl;
// 	ss.seekg(16, ios::beg);
// 	ss >> word;
// 	cout << word << endl;
// 	ss.seekp(16, ios::beg);
// 	ss << "code";
// 	cout << ss.str() << endl;
// 	ss.str("fsjdfj j .");
// 	cout << ss.str() << endl;
// }


// #include <cstddef>
// #include <cstdlib>
// #include <fstream>
// #include <iostream>
// #include <sstream>
// #include <stdexcept>
// #include <string>
// #include "../c3/ReplaceAll.h"
// #include "../require.h"
// using namespace std;

// string& stripHTMLTags(string& s) throw(runtime_error){
// 	size_t leftPos;
// 	while((leftPos = s.find('<')) != string::npos){
// 		size_t rightPos = s.find('>', leftPos + 1);
// 		if (rightPos == string::npos){
// 			ostringstream msg;
// 			msg << "Incomplete HTML tag starting in position " 
// 			    << leftPos;
// 			throw runtime_error(msg.str());
// 		}
// 		s.erase(leftPos, rightPos - leftPos + 1);
// 	}
// 	replaceAll(s, "&lt;", "<");
// 	replaceAll(s, "&gt;", ">");
// 	replaceAll(s, "&amp;", "&");
// 	replaceAll(s, "&nbsp;", " ");
// 	return s;
// }

// int main(int argc, char const *argv[])
// {
// 	requireArgs(argc, 1, "usage: HTMLStripper2 InputFile");
// 	ifstream in(argv[1]);
// 	assure(in, argv[1]);
// 	ostringstream ss;
// 	ss << in.rdbuf();
// 	try{
// 		string s = ss.str();
// 		cout << stripHTMLTags(s) << endl;
// 		return EXIT_SUCCESS;
// 	}catch(runtime_error& x){
// 		cout << x.what() << endl;
// 		return EXIT_FAILURE;
// 	}
// }

// #include <iostream>
// #include <sstream>
// #include <string>
// using namespace std;
// int main(){
// 	cout << "type an int, a float and a string: ";
// 	int i;
// 	float f;
// 	string stuff;
// 	cin >> i >> f;
// 	cin >> ws;
// 	getline(cin, stuff);
// 	ostringstream os;
// 	os << "integer = " << i << endl;
// 	os << "float = " << f << endl;
// 	os << "string = " << stuff;// << endl;
// 	string result = os.str();
// 	cout << result;// << endl;
// }

// #include <iostream>
// #include <sstream>
// #include "../c2/Date.h"
// using namespace std;

// void testDate(const string& s){
// 	istringstream os(s);
// 	Date d;
// 	os >> d;
// 	if(os)
// 		cout << d << endl;
// 	else
// 		cout << "Input error with \"" << s << "\"" << endl;
// }

// int main(){
// 	testDate("08-10-2013");
// 	testDate("9   - 09 -98765");
// 	testDate("jsdcbid");
// }

// #include <cassert>
// #include <cmath>
// #include <iostream>
// #include <limits>
// #include <sstream>
// #include <string>
// using namespace std;

// int main(){
// 	istringstream s(" 1.414 47This is a test");
// 	int i;
// 	double f;
// 	s >> i >> f;
// 	cout << i << endl << f << endl;
// 	double relerr = (fabs(f) - 1.414) / 1.414;
// 	assert(relerr <= numeric_limits<double>::epsilon());
// 	string buf2;
// 	s >> buf2;
// 	cout << buf2 << endl;
// 	cout << s.rdbuf();
// }

// #include <fstream>
// #include <iostream>
// #include "../require.h"
// using namespace std;

// int main(){
// 	ifstream in("FileClass.cpp");
// 	assure(in, "FileClass.cpp");
// 	ofstream out("Iofile.out");
// 	assure(out, "Iofile.out");
// 	out << in.rdbuf();
// 	in.close();
// 	out.close();
// 	ifstream in2("Iofile.out", ios::in | ios::out);
// 	assure(in2, "Iofile.out");
// 	ostream out2(in2.rdbuf());
// 	cout << in2.rdbuf();
// 	cout << endl << endl;
// 	out2 << "Where does this end up?";
// 	out2.seekp(0, ios::beg);
// 	out2 << "7chars ";
// 	in2.seekg(0, ios::beg);
// 	cout << in2.rdbuf();
// }

// #include <cassert>
// #include <cstddef>
// #include <cstring>
// #include <fstream>
// #include <iostream>
// #include "../require.h"
// using namespace std;

// int main(){
// 	int i = 0;
// 	const int STR_NUM = 5, STR_LEN = 30;
// 	char origData[STR_NUM][STR_LEN] = {
// 		"Hickory dickory dus...",
// 		"Are you tried C++?",
// 		"Well, if you have,",
// 		"That's just too bad,",
//    		"There's plenty more for us!",
// 	};
// 	char readData[STR_NUM][STR_LEN] = { { 0 }, };
// 	ofstream out("Peom.bin", ios::out | ios::binary);
// 	assure(out, "Peom.bin");
// 	for(int i = 0; i < STR_NUM; i++)
// 		out.write(origData[i], STR_LEN);
// 	out.close();
// 	// ofstream ot("ascii", ios::out | ios::binary);
// 	// for ( i = 0; i < 127; i++){
// 	// 	ot.write((char*)i, 2);
// 	// }
// 	// ot.close();
	
// 	ifstream in("Peom.bin", ios::in | ios::binary);
// 	assure(in, "Peom.bin");
// 	in.read(readData[0], STR_LEN);
// 	assert(strcmp(readData[0], "Hickory dickory dus...") == 0);
// 	in.seekg(-STR_LEN, ios::end);
// 	in.read(readData[1], STR_LEN);
// 	assert(strcmp(readData[1], "There's plenty more for us!") == 0);
// 	in.seekg(3 * STR_LEN);
// 	in.read(readData[2], STR_LEN);
// 	assert(strcmp(readData[2], "That's just too bad,") == 0);
// 	in.seekg(-STR_LEN * 2,  ios::cur);
// 	in.read(readData[3], STR_LEN);
// 	assert(strcmp(readData[3], "Well, if you have,") == 0);
// 	in.seekg(0, ios::beg);
// 	cout << in.get() <<endl;
// 	// in.seekg(1, ios::cur);
// 	// cout << in.get() << endl;
// }

// #include <fstream>
// #include <iostream>
// #include "../require.h"
// using namespace std;

// int main(){
// 	ifstream in("FileClass.cpp");
// 	assure(in);
// 	streambuf& sb = *cout.rdbuf();
// 	while(!in.get(sb).eof()){
// 		if(in.fail())
// 			in.clear();
// 		cout << char(in.get());
// 	}
// }

// #include <fstream>
// #include <iostream>
// #include "../require.h"
// using namespace std;

// int main(){
// 	const int SZ = 1000;
// 	char buf[SZ];
// 	{
// 		ifstream in("FileClass.cpp");
// 		assure(in, "FileClass.cpp");
// 		ofstream out("Strfile.out");
// 		assure(out, "Strfile.out");
// 		int i = 1;

// 		while(in.get(buf, SZ)){
// 			in.get();
// 			cout << buf << endl;
// 			out << i++ << ": " << buf << endl;
// 		}
// 		cout << "======================\n";
// 	}
// 	ifstream in("Strfile.out");
// 	assure(in, "Strfile.out");
// 	ifstream ii("FileClass.cpp");
// 	assure(ii, "FileClass.cpp");
// 	// ofstream out("Strfile.out");
// 	// assure(out, "Strfile.out");
// 	// cout << ii.rdbuf();
// 	cout << "------------\n";
// 	while(in.getline(buf, 200)){
// 		char* cp = buf;
// 		while(*cp != ':')
// 			++cp;
// 		cp += 2;
// 		cout << cp << endl;
// 		// cout << in.rdbuf();
// 		// out << cp << endl;
// 	}
// 	cout << "=======================\n";
// 	cout << ii.rdbuf();
// }

// #include <iostream>
// using namespace std;

// int main(){
// 	int i;
// 	cin >> i;
// 	float f;
// 	cin >> f;
// 	char c;
// 	cin >> c;
// 	char buf[3];
// 	cin >> buf;

// 	cout << "i = " << i << endl;
// 	cout << "f = " << f << endl;
// 	cout << "c = " << c << endl;
// 	cout << "buf = " << buf << endl;

// 	cout << flush;
// 	cout << hex << "0x" << i << endl;
// }

// #include <cstdlib>
// #include <iostream>
// #include "FileClass.h"
// using namespace std;
// int main(){
// 	try{
// 		FileClass f("FileClass.h");
// 		const int BSIZE = 100;
// 		char buf[BSIZE];
// 		while(fgets(buf, BSIZE, f.fp()))
// 			fputs(buf, stdout);
// 	}catch(FileClass::FileClassError& e){
// 		cout << e.what() << endl;
// 		return EXIT_FAILURE;
// 	}
// 	return EXIT_SUCCESS;
// }