#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Flyweight {
public:
    Flyweight(string state):_state(state) {

    }

    virtual void Operation(const string&state) { }

    string GetState()const { return _state; }

    virtual ~Flyweight() { }
private:
    string _state;
};

class ConcreteFlyweight :public Flyweight {
public:
    ConcreteFlyweight(string state)
        :Flyweight(state) {
        cout << "ConcreteFlyweight Build..." << state << endl;
    }

    void Operation(const string& state) {
        cout << "ConcreteFlyweight " << GetState() << " \\ " << state << endl;
    }
};

class FlyweightFactory {
public:
    int count ()
    {
    return _flys.size();
	}
    Flyweight* GetFlyweight(std::string key) {
        for (auto fly : _flys) {
            if (fly->GetState() == key) {
                cout << "already created by users..." << endl;
                return fly;
            }
        }
        Flyweight *fn = new ConcreteFlyweight(key);
        _flys.push_back(fn);
        return fn;
    }
private:
    std::vector<Flyweight*> _flys;
};
