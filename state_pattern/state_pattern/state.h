#include <string>

using namespace std;

class State
{
	string cur_state;
public:
	string get_state() { return cur_state; }
	void set_state(string s) { cur_state = s; }
};

class created:public State
{
public:
	created() { set_state("status: created;"); }
};

class consider :public State
{
public:
	consider() { set_state("status: in consideration;"); }
};

class postpon :public State
{
public:
	postpon() { set_state("status: postponed;"); }
};

class reject :public State
{
public:
	reject() { set_state("status: rejected;"); }
};

class affirm :public State
{
public:
	affirm() { set_state("status: affirmed;"); }
};

class revoke :public State
{
public:
	revoke() { set_state("status: revoked;"); }
};

//1-created 2-consider 3-postpon 4-reject 5-affirm 6-revoke

class Grant
{
	string name;
	State* current;
public:
	Grant(string n)
	{
		name = n; 
		current = new created();
	}
	void change_status(int s)
	{
		switch (s)
		{
		case 1:
		{
			current = new created();
			break;
		}
		case 2:
		{
			current = new consider();
			break;
		}
		case 3:
		{
			current = new postpon();
			break;
		}
		case 4:
		{
			current = new reject();
			break;
		}
		case 5:
		{
			current = new affirm();
			break;
		}
		case 6:
		{
			current = new revoke();
			break;
		}
		}
	}
	string get_name(){ return name; }
	string get_status(){ return current->get_state(); }
};