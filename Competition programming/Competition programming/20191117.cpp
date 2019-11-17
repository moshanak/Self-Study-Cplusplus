#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class A
{
public:
	A(int id):id_(id){}
	int getID() { return id_; }
private:
	int id_;
};

class B
{
public:
	void createA(int id) {
		aVec_.push_back(make_shared<A>(id));
	}
	weak_ptr<A> getA(int id) {
		for (auto& a : aVec_) {
			if (id == a->getID()) {
				return weak_ptr<A>(a);
			}
		}
		return weak_ptr<A>();
	}

	void deleteA(int id) {
		auto itr = find_if(aVec_.begin(), aVec_.end(), [&](shared_ptr<A> a){ return a->getID() == id;});
		if (itr != aVec_.end()) {
			aVec_.erase(itr);
		}
	}

private:
	vector<shared_ptr<A>> aVec_;
};

class C
{
public:
	void restoreA(weak_ptr<A> a) {
		ap_ = a;
	}

	void checkA() {
		if (shared_ptr<A> a = ap_.lock()) {
			cout << a->getID() << endl;
		}
		else {
			cout << "invalid ap_" << endl;
		}
	}

private:
	weak_ptr<A> ap_;
};

int main() 
{
	B b;
	vector<C> cVec(5);
	for (int i = 0; i < 5; ++i) {
		b.createA(i);
		cVec[i].restoreA(b.getA(i));
	}
	for (int i = 0; i < 5; ++i) {
		cVec[i].checkA();
	}
	b.deleteA(2);
	b.deleteA(4);
	for (int i = 0; i < 5; ++i) {
		cVec[i].checkA();
	}

	system("pause");
	return 0;
}