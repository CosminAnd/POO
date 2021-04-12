#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
ifstream fin("textIN.txt");
ofstream fout("textOUT.txt");


void Conv_to_lower(string &s)
{
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = tolower(s[i]);
	}
}

void Del(string s, vector<string> &m)
{
	string const delims{ " .,:;!?" };
	size_t beg, pos = 0;
	while ((beg = s.find_first_not_of(delims, pos)) != std::string::npos)
	{
		pos = s.find_first_of(delims, beg + 1);
		m.push_back(s.substr(beg, pos - beg));
	}

}

void Mapping(vector<string> s, map<string, int> &m)
{
	for (int i = 0; i < s.size(); i++)
	{
		Conv_to_lower(s[i]);
	}

	for (int i = 0; i < s.size(); i++)
	{
		m[(s[i])] = m[s[i]] + 1;
	}
}
void afisare(priority_queue<int>q)
{
	while (!q.empty())
	{
		cout << q.top() << endl;
		q.pop();
	}
}

class CompareMap {
public:
	bool operator() (pair<string, int> const& a, pair<string, int> const& b) const 
	{
		if (a.second != b.second)
			return a.second < b.second;
		else if (a.first.compare(b.first) > 0)
			return true;
		else
			return false;
	}
};


int main()
{
	string s;
	vector <string> m;
	map < string,int > MAP;
	priority_queue < pair <string, int>, vector<pair<string, int> >, CompareMap> q;

	getline(fin, s);
	Del(s, m);
	Mapping(m, MAP);

	for (auto i = MAP.begin(); i!=MAP.end(); i++)
	{
		pair<string, int> temp(i->first, i->second);
		q.push(temp);
	}
	while (!q.empty() ) 
	{
		cout << '"' << q.top().first <<'"'<< " => " << q.top().second << "\n";
		q.pop();
	}
	return 0;
  
}

