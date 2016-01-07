
#include <algorithm>
#include <iostream>
#include <iterator>
#include <functional>
#include <numeric>
#include "PrintSequence.h"
using namespace std;

int main(){
	int a[] = {1, 1, 2, 2, 3, 5, 7, 9, 11, 13};
	const int ASZ = sizeof a / sizeof *a;
	print(a, a+ASZ, "a");
	int r = accumulate(a, a+ASZ, 0);
	cout << "accumulate 1: " << r << endl;
	r = accumulate(a, a+ASZ, 0, plus<int>());
	cout << "accumulate 2: " << r << endl;
	int b[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2};
	print(b, b+sizeof b/sizeof *b, "b");
		r = inner_product(a, a+ASZ, b, 0);
	cout << "inner_product 1: " << r << endl;
	r = inner_product(a, a+ASZ, b, 0, plus<int>(), multiplies<int>());
	cout << "inner_product 2: " << r << endl;
	int* it = partial_sum(a, a+ASZ, b);
	print(b, it, "partial_sum 1");
	it = partial_sum(a, a+ASZ, b, plus<int>());
	print(b, it, "partial_sum 2");
	it = adjacent_difference(a, a+ASZ, b);
	print(b, it, "adjacent_difference 1");
	it = adjacent_difference(a, a+ASZ, b, minus<int>());
	print(b, it, "adjacent_difference 2");
}

// #include <algorithm>
// #include <vector>
// #include <ctime>
// #include "Inventory.h"
// #include "PrintSequence.h"
// using namespace std;

// struct Discounter{
// 	Inventory operator()(const Inventory& inv, float discount){
// 		return Inventory(inv.getItem(), inv.getQuantity(), int(inv.getValue() * inv.getQuantity()));
// 	}
// };
// struct DiscGen{
// 	float operator()(){
// 		float r = float(rand() % 10);
// 		return r / 100.0;
// 	}
// };

// int main(){
// 	vector<Inventory> vi;
// 	srand(time(0));
// 	generate_n(back_inserter(vi), 15, InvenGen());
// 	print(vi.begin(), vi.end(), "vi");
// 	vector<float> disc;
// 	generate_n(back_inserter(disc), 15, DiscGen());
// 	print(disc.begin(), disc.end(), "Discounts");
// 	vector<Inventory> discounted;
// 	transform(vi.begin(), vi.end(), disc.begin(), back_inserter(discounted), Discounter());
// 	print(discounted.begin(), discounted.end(), "discounted");
// }

// #include <algorithm>
// #include <ctime>
// #include <vector>
// #include "Inventory.h"
// #include "PrintSequence.h"
// using namespace std;

// class InvAccum{
// 	int quantity;
// 	int value;
// public:
// 	InvAccum():quantity(0), value(0){}
// 	void operator()(const Inventory& inv){
// 		quantity += inv.getQuantity();
// 		value += inv.getQuantity() * inv.getValue();
// 	}
// 	friend ostream& operator<<(ostream& os, const InvAccum& ia){
// 		return os << "total quantity: " << ia.quantity << ", total value: " << ia.value;
// 	}
// };

// int main(){
// 	vector<Inventory> vi;
// 	srand(time(0));
// 	generate_n(back_inserter(vi), 15, InvenGen());
// 	print(vi.begin(), vi.end(), "vi");
// 	InvAccum ia = for_each(vi.begin(), vi.end(), InvAccum());
// 	cout << ia << endl;
// }

// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include "Counted.h"
// using namespace std;

// template<class T> T* deleteP(T* x){ delete x; return 0; }

// template<class T>
// struct Deleter{
// 	T* operator()(T* x){ delete x; return 0; }
// };

// int main(){
// 	CountedVector cv("one");
// 	transform(cv.begin(), cv.end(), cv.begin(), deleteP<Counted>);
// 	CountedVector cv2("two");
// 	transform(cv2.begin(), cv2.end(), cv2.begin(), Deleter<Counted>());
// }

// #include <algorithm>
// #include <iostream>
// #include "Counted.h"
// using namespace std;

// template<class T>
// class DeleteT{
// public:
// 	void operator()(T* x){ delete x; }
// };

// template<class T>
// void wipe(T* x){ delete x; }

// int main(){
// 	CountedVector B("two");
// 	for_each(B.begin(), B.end(), DeleteT<Counted>());
// 	CountedVector C("three");
// 	for_each(C.begin(), C.end(), wipe<Counted>);
// }

// #include <algorithm>
// #include <vector>
// #include "Generators.h"
// #include "PrintSequence.h"
// using namespace std;

// int main(){
// 	const int SZ = 30;
// 	char v[SZ+1], v2[SZ+1];
// 	CharGen g;
// 	generate(v, v+SZ, g);
// 	generate(v2, v2+SZ, g);
// 	sort(v, v+SZ);
// 	sort(v2, v2+SZ);
// 	print(v, v+SZ, "v");
// 	print(v2, v2+SZ, "v2");
// 	bool b = includes(v, v+SZ, v+SZ/2, v+SZ);
// 	cout.setf(ios::boolalpha);
// 	cout << "includes: " << b << endl;
// 	char v3[SZ*2 +1], *end;
// 	end = set_union(v, v+SZ, v2, v2+SZ, v3);
// 	print(v3, end, "set_union");
// 	end = set_intersection(v, v+SZ, v2, v2+SZ, v3);
// 	print(v3, end, "set_intersection");
// 	end = set_difference(v, v+SZ, v2, v2+SZ, v3);
// 	print(v3, end, "set_difference");
// 	end = set_symmetric_difference(v, v+SZ, v2, v2+SZ, v3);
// 	print(v3, end, "set_symmetric_difference");
// }

// #include <algorithm>
// #include "PrintSequence.h"
// #include "Generators.h"
// using namespace std;

// int main(){
// 	const int SZ = 15;
// 	int a[SZ*2] = {0};
// 	generate(a, a+SZ, SkipGen(0, 2));
// 	a[3] = 4;
// 	a[4] = 4;
// 	generate(a+SZ, a+SZ*2, SkipGen(1, 3));
// 	print(a, a+SZ, "range1");
// 	print(a+SZ, a+SZ*2, "range2");
// 	int b[SZ*2] = {0};
// 	merge(a, a+SZ, a+SZ, a+SZ*2, b);
// 	print(b, b+SZ*2, "merge");
// 	for(int i = 0; i < SZ * 2; i++)
// 		b[i] = 0;
// 	inplace_merge(a, a+SZ, a+SZ*2);
// 	print(a, a+SZ*2, "inplace_merge");
// 	int* end = set_union(a, a+SZ, a+SZ, a+SZ*2, b);
// 	print(b, end, "set_union");
// }

// #include <algorithm>
// #include <cassert>
// #include <ctime>
// #include <cstdlib>
// #include <cstddef>
// #include <fstream>
// #include <iostream>
// #include <iterator>
// #include <vector>
// #include "NString.h"
// #include "PrintSequence.h"
// #include "../require.h"
// using namespace std;

// int main(){
// 	typedef vector<NString>::iterator sit;
// 	char* fname = "Text.txt";
// 	ifstream in(fname);
// 	assure(in, fname);
// 	srand(time(0));
// 	cout.setf(ios::boolalpha);
// 	vector<NString> original;
// 	copy(istream_iterator<string>(in), istream_iterator<string>(), back_inserter(original));
// 	require(original.size() >= 4, "Must have four elements");
// 	vector<NString> v(original.begin(), original.end()), w(original.size()/2);
// 	sort(v.begin(), v.end());
// 	print(v.begin(), v.end(), "v");
// 	v = original;
// 	stable_sort(v.begin(), v.end());
// 	print(v.begin(), v.end(), "stable_sort");
// 	v = original;
// 	sit it = v.begin(), it2;
// 	for(size_t i = 0; i < v.size()/2; i++)
// 		++it;
// 	partial_sort(v.begin(), it, v.end());
// 	// print(original.begin(), original.end(), "original");
// 	cout << "middle = " << *it << endl;
// 	print(v.begin(), v.end(), "partial_sort");
// 	v = original;
// 	it = v.begin();
// 	for(size_t i = 0; i < v.size()/4; i++)
// 		++it;
// 	partial_sort_copy(v.begin(), it, w.begin(), w.end());
// 	print(w.begin(), w.end(), "partial_sort_copy");
// 	partial_sort_copy(v.begin(), v.end(), w.begin(), w.end());
// 	print(w.begin(), w.end(), "partial_sort_copy");
// 	assert(v == original);
// 	nth_element(v.begin(), it, v.end());
// 	cout << "The nth_element = " << *it << endl;
// 	print(v.begin(), v.end(), "nth_element");
// 	string f = original[rand() % original.size()];
// 	cout << "binary search: "
// 	     << binary_search(v.begin(), v.end(), f) << endl;
//     sort(v.begin(), v.end());
//     it = lower_bound(v.begin(), v.end(), f);
//     it2 = upper_bound(v.begin(), v.end(), f);
//     print(it, it2, "found range");
//     pair<sit, sit> ip = equal_range(v.begin(), v.end(), f);
//     print(ip.first, ip.second, "equal_range");
// }

// #include <algorithm>
// #include <cctype>
// #include <string>
// #include "Generators.h"
// #include "PrintSequence.h"
// using namespace std;

// struct IsUpper{
// 	bool operator()(char c){ return isupper(c); }
// };

// int main(){
// 	string v;
// 	v.resize(25);
// 	generate(v.begin(), v.end(), CharGen());
// 	print(v.begin(), v.end(), "v original", " ");
// 	string us(v.begin(), v.end());
// 	string::iterator it = us.begin(), cit = v.end(), uend = unique(us.begin(), us.end());
// 	while(it != uend){
// 		cit = remove(v.begin(), cit, *it);
// 		print(v.begin(), v.end(), "Complete v", " ");
// 		print(v.begin(), cit, "Pseudo v", " ");
// 		cout << "removed element:\t" << *it << "\nPseudo last element:\t" << *cit << endl << endl;
// 		++it;
// 	}
// 	generate(v.begin(), v.end(), CharGen());
// 	print(v.begin(), v.end(), "v", " ");
// 	cit = remove_if(v.begin(), v.end(), IsUpper());
// 	print(v.begin(), cit, "v after remove_if IsUpper", " ");
// 	sort(v.begin(), cit);
// 	print(v.begin(), v.end(), "sorted", " ");
// 	string v2;
// 	v2.resize(cit - v.begin());
// 	unique_copy(v.begin(), cit, v2.begin());
// 	print(v2.begin(), v2.end(), "unique_copy", " ");
// 	cit = unique(v.begin(), cit, equal_to<char>());
// 	print(v.begin(), cit, "unique equal_to<char>", " ");
// }

// #include <algorithm>
// #include <functional>
// #include <string>
// #include <vector>
// #include "PrintSequence.h"
// using namespace std;

// int main(){
// 	string s1("This is a test");
// 	string s2("This is a Test");
// 	cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
// 	cout << "compare s1 & s1: " << equal(s1.begin(), s1.end(), s1.begin()) << endl;
// 	cout << "compare s1 & s2: " << equal(s1.begin(), s1.end(), s2.begin()) << endl;
// 	cout << "lexicographical_compare s1 & s1: " 
// 		 << lexicographical_compare(s1.begin(), s1.end(), s1.begin(), s1.end()) << endl;
// 	cout << "lexicographical_compare s1 & s2: " 
// 		 << lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()) << endl;
// 	cout << "lexicographical_compare s2 & s1: " 
// 		 << lexicographical_compare(s2.begin(), s2.end(), s1.begin(), s1.end()) << endl;
//     cout << "lexicographical_compare shortened s1 & full-length s2: " << endl;
//     string s3(s1);
//     while(s3.length() != 0){
//     	bool result = lexicographical_compare(s3.begin(), s3.end(), s2.begin(), s2.end());
//     	cout << s3 << endl << s2 << ", result = " << result << endl;
//     	if(result == true)break;
//     	s3 = s3.substr(0, s3.length()-1);
//     }
//     pair<string::iterator, string::iterator> p = mismatch(s1.begin(), s1.end(), s2.begin());
//     print(p.first, s1.end(), "p.first", " ");
//     print(p.second, s2.end(), "p.second", " ");
// }

// #include <algorithm>
// #include <functional>
// #include <vector>
// #include "PrintSequence.h"
// using namespace std;

// struct PluseOne{
// 	bool operator()(int i, int j){ return j == i + 1; }
// };
// class MulMoreThan{
// 	int value;
// public:
// 	MulMoreThan(int val):value(val){}
// 	bool operator()(int v, int m){ return v * m > value; }
// };

// int main(){
// 	int a[] = {1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 8, 8, 8, 8, 11, 11, 11, 11, 11 };
// 	const int ASZ = sizeof a / sizeof *a;
// 	vector<int> v(a, a+ASZ);
// 	print(v.begin(), v.end(), "v", " ");
// 	vector<int>::iterator it = find(v.begin(), v.end(), 4);
// 	cout << "find: " << *it << endl;
// 	it = find_if(v.begin(), v.end(), bind2nd(greater<int>(), 8));
// 	cout << "find_if: " << *it << endl;
// 	it = adjacent_find(v.begin(), v.end());
// 	while(it != v.end()){
// 		cout << "adjacent_find: " << *it << ", " << *(it +1) << endl;
// 		it = adjacent_find(it + 1, v.end());
// 	}
// 	it = adjacent_find(v.begin(), v.end(), PluseOne());
// 	while(it != v.end()){
// 		cout << "adjacent_find PluseOne: " << *it << ", " << *(it +1) << endl;
// 		it = adjacent_find(it + 1, v.end(), PluseOne());
// 	}
// 	int b[] = {8, 11};
// 	const int BSZ = sizeof b / sizeof *b;
// 	print(b, b+BSZ, "b", " ");
// 	it = find_first_of(v.begin(), v.end(), b, b+BSZ);
// 	print(it, it+BSZ, "find_first_of", " ");
// 	it = find_first_of(v.begin(), v.end(), b, b+BSZ, PluseOne());
// 	print(it, it+BSZ, "find_first_of PluseOne", " ");
// 	it = search(v.begin(), v.end(), b, b+BSZ);
// 	print(it, it+BSZ, "search", " ");
// 	int c[] = { 5, 6, 7 };
// 	const int CSZ = sizeof c / sizeof *c;
// 	print(c, c+CSZ, "c", " ");
// 	it = search(v.begin(), v.end(), c, c+CSZ, PluseOne());
// 	print(it, it+CSZ, "search PluseOne", " ");
// 	int d[] = {11, 11, 11};
// 	const int DSZ = sizeof d / sizeof *d;
// 	print(d, d+DSZ, "d", " ");
// 	it = find_end(v.begin(), v.end(), d, d+DSZ);
// 	print(it, v.end(), "find_end", " ");
// 	int e[] = { 9, 9 };
// 	print(e, e+2, "e", " ");
// 	it = find_end(v.begin(), v.end(), e, e+2, PluseOne());
// 	print(it, v.end(), "find_end PluseOne", " ");
// 	it = search_n(v.begin(), v.end(), 3, 7);
// 	print(it, it+3, "search_n 3, 7", " ");
// 	it = search_n(v.begin(), v.end(), 10, 15, MulMoreThan(100));
// 	print(it, it+10, "search_n 10, 15, MulMoreThan(100)", " ");
// 	cout << "min element: " << *min_element(v.begin(), v.end()) << endl;
// 	cout << "max element: " << *max_element(v.begin(), v.end()) << endl;
// 	vector<int> v2;
// 	replace_copy(v.begin(), v.end(), back_inserter(v2), 8, 47);
// 	print(v2.begin(), v2.end(), "replace 8->47", "");
// 	replace_if(v.begin(), v.end(), bind2nd(greater_equal<int>(), 7), -1);
// 	print(v.begin(), v.end(), "replace_if >= 7 -> -1", " ");
// }

// #include <vector>
// #include <string>
// #include <algorithm>
// #include "PrintSequence.h"
// #include "NString.h"
// #include "Generators.h"
// using namespace std;

// int main(){
// 	vector<int> v1(10);
// 	generate(v1.begin(), v1.end(), SkipGen());
// 	print(v1.begin(), v1.end(), "v1", " ");
// 	vector<int> v2(v1.size());
// 	copy_backward(v1.begin(), v1.end(), v2.end());
// 	print(v2.begin(), v2.end(), "copy_backward", " ");
// 	reverse_copy(v1.begin(), v1.end(), v2.begin());
// 	print(v2.begin(), v2.end(), "reverse_copy", " ");
// 	reverse(v1.begin(), v1.end());
// 	print(v1.begin(), v1.end(), "reverse", " ");
// 	int half = v1.size()/2;
// 	swap_ranges(v1.begin(), v1.begin()+half, v1.begin()+half);
// 	print(v1.begin(), v1.end(), "swap_ranges", " ");
// 	generate(v1.begin(), v1.end(), SkipGen());
// 	print(v1.begin(), v1.end(), "v1", " ");
// 	int third = v1.size()/3;
// 	for (int i = 0; i < 10; i++){
// 		rotate(v1.begin(), v1.begin()+third, v1.end());
// 		print(v1.begin(), v1.end(), "rotate", " ");
// 	}
// 	cout << "Second rotate example:" << endl;
// 	char c[] = "aabbccddeeffgghhiijj";
// 	const char CSZ = strlen(c);
// 	for (int i = 0; i < 10; i++){
// 		rotate(c, c+2, c+CSZ);
// 		print(c, c+CSZ, "", "");
// 	}
// 	cout << "All n! permutations of abcd:" << endl;
// 	int nf = 4*3*2*1;
// 	char p[] = "abcd";
// 	for (int i = 0; i < nf; i++){
// 		next_permutation(p, p+4);
// 		print(p, p+4, "", "");
// 	}
// 	cout << "Using prev_permutation:" << endl;
// 	for (int i = 0; i < nf; i++){
// 		prev_permutation(p, p+4);
// 		print(p, p+4, "", "");
// 	}
// 	cout << "random_shuffling a word:" << endl;
// 	string s("hello");
// 	cout << s << endl;
// 	for (int i = 0; i < 5; i++){
// 		random_shuffle(s.begin(), s.end());
// 		cout << s << endl;
// 	}
// 	NString sa[] = {"a", "b", "c", "d","a", "b", "c", "d", "a", "b", "c", "d","a", "b", "c"};
//     const int SASZ = sizeof sa / sizeof *sa;
//     vector<NString> ns(sa, sa+SASZ);
//     print(ns.begin(), ns.end(), "ns", " ");
//     vector<NString>::iterator it = partition(ns.begin(), ns.end(), bind2nd(greater<NString>(), "b"));
//     cout << "partition point: " << *it << endl;
//     print(ns.begin(), ns.end(), "", " ");
//     copy(sa, sa+SASZ, ns.begin());
//     it = stable_partition(ns.begin(), ns.end(), bind2nd(greater<NString>(), "b"));
//     cout << "stable partition" << endl;
//     cout << "partition point: " << *it << endl;
//     print(ns.begin(), ns.end(), "", " ");
// }

// #include <algorithm>
// #include <functional>
// #include <iterator>
// #include <set>
// #include <vector>
// #include "Generators.h"
// #include "PrintSequence.h"
// using namespace std;

// int main(){
// 	vector<char> v;
// 	generate_n(back_inserter(v), 50, CharGen());
// 	print(v.begin(), v.end(), "v", " ");
// 	set<char> cs(v.begin(), v.end());
// 	typedef set<char>::iterator sci;
// 	for(sci it = cs.begin(); it != cs.end(); it++){
// 		int n = count(v.begin(), v.end(), *it);
// 		cout << *it << ": " << n << ", ";
// 	}
// 	int lc = count_if(v.begin(), v.end(), bind2nd(greater<char>(), 'a'));
// 	cout << "\nLowercase letters: " << lc << endl;
// 	sort(v.begin(), v.end());
// 	print(v.begin(), v.end(), "sorted", " ");
// 	// sort(cs.begin(), cs.end());
// 	print(cs.begin(), cs.end(), "set", " ");
// }

// #include <vector>
// #include <algorithm>
// #include <string>
// #include "Generators.h"
// #include "PrintSequence.h"
// using namespace std;

// int main(){
// 	vector<string> v1(5);
// 	fill(v1.begin(), v1.end(), "howdy");
// 	print(v1.begin(), v1.end(), "v1");
// 	vector<string> v2;
// 	fill_n(back_inserter(v2), 7, "bye");
// 	print(v2.begin(), v2.end(), "v2");
// 	vector<int> v3(10);
// 	generate(v3.begin(), v3.end(), SkipGen(4, 5));
// 	print(v3.begin(), v3.end(), "v3");
// 	vector<int> v4;
// 	generate_n(back_inserter(v4), 15, URandGen(30));
// 	print(v4.begin(), v4.end(), "v4");
// }

// #include <algorithm>
// #include <cassert>
// #include <cstdlib>
// #include <functional>
// #include <iostream>
// #include <iterator>
// #include <string>
// #include <vector>
// #include "NumStringGen.h"
// using namespace std;

// template<typename F1, typename F2>
// class unary_composer : public unary_function<typename F2::argument_type, typename F1::argument_type>{
// 	F1 f1;
// 	F2 f2;
// public:
// 	unary_composer(F1 f1, F2 f2):f1(f1), f2(f2){}
// 	typename F1::result_type operator()(typename F2::argument_type x){
// 		return f1(f2(x));
// 	}
// };

// template<typename F1, typename F2>
// unary_composer<F1, F2> compose(F1 f1, F2 f2){
// 	return unary_composer<F1, F2>(f1, f2);
// }

// int main(){
// 	const int SZ = 9;
// 	vector<string> vs(SZ);
// 	generate(vs.begin(), vs.end(), NumStringGen());
// 	copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, "\t"));
// 	cout << endl;
// 	vector<double> vd;
// 	transform(vs.begin(), vs.end(), back_inserter(vd),
// 	          compose(ptr_fun(atof), mem_fun_ref(&string::c_str)));
// 	copy(vd.begin(), vd.end(), ostream_iterator<double>(cout, "\t"));
// 	cout << endl;
// }

// #include <cassert>
// #include <cstdlib>
// #include <functional>
// #include <iostream>
// #include <string>
// using namespace std;

// template<typename R, typename E, typename F1, typename F2>
// class unary_composer{
// 	F1 f1;
// 	F2 f2;
// public:
// 	unary_composer(F1  fone, F2 ftwo):f1(fone), f2(ftwo){}
// 	R operator()(E x){ return f1(f2(x)); }
// };

// template<typename R, typename E, typename F1, typename F2>
// unary_composer<R, E, F1, F2>
// compose(F1 f1, F2 f2){
// 	return unary_composer<R, E, F1, F2>(f1, f2);
// }

// int main(){
// 	double x = compose<double, const string&>(atof, mem_fun_ref(&string::c_str))("12.34");
// 	cout << x << endl;
// }

// #include <algorithm>
// #include <cstdlib>
// #include <ctime>
// #include <functional>
// #include <iostream>
// #include <iterator>
// #include <string>
// #include <vector>
// #include "NumStringGen.h"
// using namespace std;

// int main(){
// 	const int SZ = 9;
// 	vector<string> vs(SZ);
// 	srand(time(0));
// 	generate(vs.begin(), vs.end(), NumStringGen());
// 	copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, "\t"));
// 	cout << endl;
// 	const char* vcp[SZ];
// 	transform(vs.begin(), vs.end(), vcp, mem_fun_ref(&string::c_str));
// 	vector<double> vd;
// 	transform(vcp, vcp+SZ, back_inserter(vd), std::atof);
// 	cout.precision(4);
// 	cout.setf(ios::showpoint);
// 	copy(vd.begin(), vd.end(), ostream_iterator<double>(cout, "\t"));
// 	cout << endl;
// }

// #include <iostream>
// #include <algorithm>
// #include <cassert>
// #include <cmath>
// #include <cstddef>
// #include <fstream>
// #include <functional>
// #include <string>
// #include <vector>
// #include "../purge.h"
// #include "../require.h"
// using namespace std;

// typedef vector<string>::iterator LSI;

// int main(int argc, char* argv[]){
// 	char* fname = "6.1203.cpp";//"PrintSequence.h";
// 	if(argc > 1)
// 		fname = argv[1];
// 	ifstream in(fname);
// 	assure(in, fname);
// 	vector<string> vs;
// 	string s;
// 	while(getline(in, s))
// 		vs.push_back(s);
// 	vector<string> cpy = vs;
// 	LSI lsi = find_if(vs.begin(), vs.end(), mem_fun_ref(&string::empty));
// 	while(lsi != vs.end()){
// 		*lsi = "A BLANK LINE";
// 		lsi = find_if(vs.begin(), vs.end(), mem_fun_ref(&string::empty));
// 	}
// 	for(size_t i = 0; i < cpy.size(); i++)
// 		if(cpy[i].size() == 0)
// 			cout << "=" << endl; //assert(vs[i] == "A BLANK LINE");
// 		else
// 			cout << "!" << endl; //assert(vs[i] != "A BLANK LINE");
// }

// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <iterator>
// #include <vector>
// using namespace std;

// class Angle{
// 	int degrees;
// public:
// 	Angle(int deg):degrees(deg){}
// 	int mul(int times){ return degrees *= times; }
// };

// int main(){
// 	vector<Angle> a;
// 	for (int i = 0; i < 50; i += 10){
// 		a.push_back(Angle(i));
// 	}
// 	int x[] = {1,2,3,4,5};
// 	transform(a.begin(), a.end(), x, ostream_iterator<int>(cout, " "), mem_fun_ref(&Angle::mul));
// 	cout << endl;
// }

// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <vector>
// #include "../purge.h"
// using namespace std;

// class Shape{
// public:
// 	virtual void draw() = 0;
// 	virtual ~Shape(){}
// };

// class Circle : public Shape{
// public:
// 	virtual void draw() { cout << "Circle::Draw()" << endl; }
// 	~Circle(){ cout << "Circle::~Circle()" << endl; }
// };

// class Square : public Shape{
// public:
// 	virtual void draw() { cout << "Square::Draw()" << endl; }
// 	~Square(){ cout << "Square::~Square()" << endl; }
// };

// int main(){
// 	vector<Shape*> vs;
// 	vs.push_back(new Circle);
// 	vs.push_back(new Square);
// 	vs.push_back(new Circle);
// 	for_each(vs.begin(), vs.end(), mem_fun(&Shape::draw));
// 	purge(vs);
// }

// #include <algorithm>
// #include <cmath>
// #include <functional>
// #include <iostream>
// #include <iterator>
// #include <vector>
// using namespace std;

// double d[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};
// const int DSZ = sizeof d / sizeof *d;

// int main(){
// 	vector<double> vd;
// 	transform(d, d+DSZ, back_inserter(vd), bind2nd(ptr_fun<double, double,double>(pow), 2.0));
// 	copy(vd.begin(), vd.end(),ostream_iterator<double>(cout, " "));
// 	cout << endl;
// }

// #include <algorithm>
// #include <cmath>
// #include <functional>
// #include <iostream>
// #include <iterator>
// #include <vector>
// using namespace std;

// int d[] = { 213, 4, 10, 333, 334 };
// const int DSZ = sizeof d / sizeof *d;
// bool isEven(int x) { return x%2 == 0; }

// int main(){
// 	vector<bool> vb;
// 	transform(d, d+DSZ, back_inserter(vb), not1(ptr_fun(isEven)));
// 	copy(vb.begin(), vb.end(), ostream_iterator<bool>(cout, " "));
// 	cout << endl;
// }

// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <iterator>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// int boundedRand() { return rand() % 100; }

// int main(){
// 	const int SZ = 20;
// 	int a[SZ], b[SZ] = { 0 };
// 	srand(time(0));
// 	generate(a, a+SZ, boundedRand);
// 	int val = boundedRand();
// 	int* end = remove_copy_if(a, a+SZ, b, bind2nd(greater<int>(), val));

// 	sort(a, a+SZ);
// 	sort(b, end);
// 	ostream_iterator<int> out(cout, " ");
// 	cout << "Orilinal Sequence:" << endl;
// 	copy(a, a+SZ, out);
// 	cout << endl;
// 	cout << "Values <= " << val << endl;
// 	copy(b, end, out);
// 	cout << endl;
// }

// #include <algorithm>
// #include <cstdlib>
// #include <ctime>
// #include <functional>
// #include <iostream>
// #include <iterator>
// #include <vector>
// #include "Generators.h"
// using namespace std;

// int main(){
// 	ostream_iterator<int> out(cout, " ");
// 	vector<int> v(15);
// 	srand(time(0));
// 	generate(v.begin(), v.end(), URandGen(20));
// 	copy(v.begin(), v.end(), out);
// 	cout << endl;
// 	// out >> endl;
// 	transform(v.begin(), v.end(), v.begin(), bind2nd(multiplies<int>(), 10));
// 	copy(v.begin(), v.end(), out);
// 	cout << endl;
// 	bool b = 1;
// 	cout << boolalpha << b << endl << !b;
// }

// #include <algorithm>
// #include <cstdlib>
// #include <ctime>
// #include <functional>
// #include <iostream>
// #include <iterator>
// #include <vector>
// #include "Generators.h"
// #include "PrintSequence.h"
// using namespace std;

// template<typename Contain, typename UnaryFunc>
// void testUnary(Contain& source, Contain& dest, UnaryFunc f){
// 	transform(source.begin(), source.end(), dest.begin(), f);
// }

// template<typename Contain1, typename Contain2, typename BinaryFunc>
// void testBinary(Contain1& src1, Contain1& src2, Contain2& dest, BinaryFunc f){
// 	transform(src1.begin(), src1.end(), src2.begin(), dest.begin(), f);
// }

// #define T(EXPR) EXPR; print(r.begin(), r.end(), "After " #EXPR);
// #define B(EXPR) EXPR; print(br.begin(), br.end(), "After " #EXPR);

// struct BRand{
// 	bool operator()(){ return rand() % 2 == 0; }
// };
// int main(){
// 	const int SZ = 10;
// 	const int MAX = 50;
// 	vector<int> x(SZ), y(SZ), r(SZ);

// 	URandGen urg(MAX);
// 	srand(time(0));
// 	generate_n(x.begin(), SZ, urg);
// 	generate_n(y.begin(), SZ, urg);

// 	// print(x.begin(), x.end(), "x");
// 	// print(y.begin(), y.end(), "y");
// 	transform(y.begin(), y.end(), y.begin(), bind2nd(plus<int>(), 1));
// 	x[0] = y[0];
// 	print(x.begin(), x.end(), "x");
// 	print(y.begin(), y.end(), "y");

// 	// T(testUnary(x, r, negate<int>()))
// 	// T(testBinary(x, y, r, minus<int>()));
// 	// T(testBinary(x, y, r, multiplies<int>()));
// 	// // T(testBinary(x, y, r, less<int>()));
// 	vector<bool> br(SZ);
// 	// B(testBinary(x, y, br, equal_to<int>()));
// 	vector<bool> b1(SZ), b2(SZ);
// 	generate_n(b1.begin(), SZ, BRand());
// 	generate_n(b2.begin(), SZ, BRand());	
// 	print(b1.begin(), b1.end(), "b1");
// 	print(b2.begin(), b2.end(), "b2");
// 	B(testBinary(b1, b2, br, logical_and<int>()));
// 	B(testUnary(b1, br, logical_not<int>()));
// 	B(testUnary(b1, br, not1(logical_not<int>())));
// }

// #include <algorithm>
// #include <cstddef>
// #include <iostream>
// #include <functional>
// #include <iterator>
// using namespace std;

// int main(){
// 	int a[] = {10, 20, 30};
// 	const size_t SIZE = sizeof a /sizeof a[0];
// 	remove_copy_if(a, a+SIZE, ostream_iterator<int>(cout, "\n"), bind2nd(greater<int>(), 15));
// 	remove_copy_if(a, a+SIZE, ostream_iterator<int>(cout, "\n"), bind1st(greater<int>(), 15));
// }

// #include <iostream>
// using namespace std;

// class gt_n{
//     int val;
// public:
// 	gt_n(int val) :val(val) {}
// 	bool operator()(int n){ return n > val; }	
// };

// int main(){
// 	gt_n f(4);
// 	cout << f(3) << endl;
// 	cout << f(5) << endl;
// }

// #include <algorithm>
// #include <fstream>
// #include <iostream>
// #include <iterator>
// #include "../require.h"
// using namespace std;

// bool gt15(int x) { return 15 < x; }

// int main(){
// 	ofstream ints("someInts.dat");
// 	ints << " 1 3 47 5 84 9";
// 	ints.close();
// 	ifstream inf("someInts.dat");
// 	assure(inf, "someInts.dat");
// 	remove_copy_if(istream_iterator<int>(inf),
// 				   istream_iterator<int>(),
// 				   ostream_iterator<int>(cout, "\n"),
// 				   gt15);
// }

// #include <algorithm>
// #include <cstddef>
// #include <iostream>
// #include <iterator>
// #include <fstream>
// using namespace std;

// bool gt15(int x){ return 15 < x; }

// int main(){
// 	int a[] = {10, 20, 30};
// 	const size_t SIZE = sizeof a / sizeof a[0];
// 	remove_copy_if(a, a+SIZE, ostream_iterator<int>(cout, "\n"), gt15);
// 	ofstream outf("ints.out");
// 	remove_copy_if(a, a+SIZE, ostream_iterator<int>(outf, "\n"), gt15);
// }

// #include <algorithm>
// #include <cstddef>
// #include <iostream>
// #include <string>
// using namespace std;

// bool contain_e(const string& s){
// 	return s.find('e') != string::npos;
// }

// int main(){
// 	string a[] = { "read", "my", "lips" };
// 	const size_t SIZE = sizeof a / sizeof a[0];
// 	string b[SIZE];
// 	string* endb = replace_copy_if(a, a+SIZE, b, contain_e, string("kiss"));
// 	replace_if(a, a+SIZE, contain_e, string("kiss"));
// 	string* beginb = b;
// 	while(beginb != endb)
// 		cout << *beginb++ << endl;
// 	string* p = a;
// 	while(p != a+SIZE)
// 		cout<< *p++ << endl;
// }

// #include <algorithm>
// #include <cstddef>
// #include <iostream>
// using namespace std;

// bool gt15(int x) { return 15 < x; }

// int main(){
// 	int a[] = { 10, 20, 30 };
// 	const size_t SIZE = sizeof a / sizeof a[0];
// 	int b[SIZE];
// 	int* endb = remove_copy_if(a, a+SIZE, b, gt15);
// 	int* beginb = b;
// 	while(beginb != endb)
// 		cout << *beginb++ << endl;
// }

// #include <algorithm>
// #include <iostream>
// #include <cstddef>
// #include <cassert>
// #include <iterator>
// #include <vector>
// using namespace std;

// int main(){
// 	int a[] = { 10, 20, 30, };
// 	// string a[] = { "10", "20", "30", };
// 	const size_t SIZE = sizeof a / sizeof a[0];
// 	string b[SIZE];
// 	vector<int> v1(a, a+SIZE);
// 	vector<int> v2;
// 	copy(v1.begin(), v1.end(), back_inserter(v2));
// 	// copy(a, a + SIZE, b);
// 	// for(size_t i = 0; i < SIZE; ++i)
// 	// 	// assert(a[i] == b[i]);
// 	// 	cout << a[i] << ":" << b[i] << endl;
// 	// assert(equal(v1.begin(), v1.end(), v2.begin()));
// 	assert(equal(v1.begin(), v1.end(), v2.begin()));
// 	// cout << equal(v1.begin(), v1.end(), v2.begin()) << endl;
// }