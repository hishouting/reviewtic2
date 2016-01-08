#ifndef NOISY_H
#define NOISY_H 
using std::endl;
using std::cout;
using std::ostream;

class Noisy{
	static long create, assign, copycons, destroy;
	long id;
public:
	Noisy():id(create++){
		cout << "d[" << id << "]" << endl;
	}
    Noisy(const Noisy& rv):id(rv.id){
    	cout << "d[" << id << "]" << endl;
    	++copycons; 
    }
    Noisy& operator=(const Noisy& rv){
    	cout << "(" << id << ") = [" << rv.id << "]" << endl; 
    	id = rv.id;
    	++assign;
    	return *this;
    }
    friend bool operator<(const Noisy& lv, const Noisy& rv){
    	return lv.id < rv.id;
    }
    friend bool operator==(const Noisy& lv, const Noisy& rv){
    	return lv.id == rv.id;
    }
    ~Noisy(){
    	cout << "~[" << id << "]" << endl;
    	++destroy;
    }
    friend ostream& operator<<(ostream& os, const Noisy& n){
    	return os << n.id;
    }
    friend class NoisyReport;
};

struct NoisyGen{
	Noisy operator()(){
		return Noisy();
	}
};

class NoisyReport{
	static NoisyReport nr;
	NoisyReport(){}
	NoisyReport& operator=(NoisyReport&);
	NoisyReport(const NoisyReport&);
public:
	~NoisyReport(){
		cout << "\n---------\n"
		     << "Noisy creations: " << Noisy::create
		     << "\ncopy-constructors: " << Noisy::copycons
		     << "\nAssignments: " << Noisy::assign
		     << "\nDestructions: " << Noisy::destroy << endl;
	}
};

long Noisy::create = 0, Noisy::assign = 0, Noisy::copycons = 0, Noisy::destroy = 0;
NoisyReport NoisyReport::nr;
#endif	//NOISY_H