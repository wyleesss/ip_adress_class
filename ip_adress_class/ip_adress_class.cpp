#include <iostream>
#include <string>
using namespace std;

class IPAdress
{
protected:

	string value;

public:

	IPAdress(const string& value)
	{
		this->value = value; 
	}

	IPAdress(const IPAdress& object) 
	{ 
		this->value = object.value; 
	}

	virtual void output_info() 
	{
		cout << "ip adress value -> << " << (value.empty() ? "void" : value) << " >>;" << endl;
	}
};

class IPAdressChecked :public IPAdress
{

	bool is_correct;

public:

	IPAdressChecked(const string& value) :IPAdress(value)
	{
		is_correct = check(value);
	}

	IPAdressChecked(const IPAdressChecked& object) :IPAdress(object.value)
	{ 
		is_correct = object.is_correct;
	}

	void output_info()
	{
		cout << "ip adress value -> << " << (value.empty() ? "void" : value) << " >> -> is " << (is_correct ? "correct;" : "incorrect;") << endl;
	}

private: 
	
	bool check(string value) 
	{
		string substr;
		int checking_part = NULL;

		for (int i = 0; i < 3; i++)
		{
			if (value.find('.') == string::npos)
				return false;
			
			substr = value.substr(0, value.find('.'));

			if (substr.size() > 3 || substr.empty())
				return false;
			
			for (auto& i : substr)
				if (!isdigit(i))
					return false;

			checking_part = stoi(substr);

			if (checking_part > 255 || checking_part < 0 || (checking_part == 0 && substr.size() > 1))
				return false;
			
			value.erase(0, value.find('.') + 1);
		}

		if (value.size() > 3 || value.empty())
			return false;
		
		for (auto& i : value)
			if (!isdigit(i))
				return false;
			
		checking_part = stoi(value);

		if (checking_part > 255 || checking_part < 0 || (checking_part == 0 && value.size() > 1))
			return false;

		else
			return true;
	}

};

int main()
{
	string first_value, second_value, third_value;

	IPAdress* default_1 = nullptr;
	IPAdressChecked* checked_1 = nullptr;
	IPAdressChecked* checked_2 = nullptr;

	cout << "input #1\n-> ";
	cin >> first_value;
	system("cls");

	cout << "input #2\n-> ";
	cin >> second_value;
	system("cls");

	cout << "input #3\n-> ";
	cin >> third_value;
	system("cls");

	cout << "#1 ";
	default_1 = new IPAdressChecked(first_value);
	default_1->output_info();

	cout << "#2 ";
	checked_1 = new IPAdressChecked(second_value);
	checked_1->output_info();

	cout << "#3 ";
	checked_2 = new IPAdressChecked(third_value);
	checked_2->output_info();

	delete default_1;
	delete checked_1;
	delete checked_2;
}