#include <iostream>
#include <vector>

using namespace std;

bool buscar_grilla(vector<vector<char> > square, int N, int bN, int i, int j)
{
	int fFila(0), stop(0);

	//if( (N-i) < bN) return false;

	for(int di = i; di < N && (di-i) < bN; di++)
	{
		for(int dj = j; dj < N && (dj-j) < bN; dj++)
		{
			if( square[di][dj] == '#' )
					return false;
		}
	}

	return true;


}


int main()
{

	int t, N, bN;
	bool found = false;

	vector< vector<char> > square;
	char caracter;

	cin >> t;

	while(t--)
	{
		cin >> N;
		for(int i = 0; i < N; i++)
		{
			vector<char> meh;
			for(int j = 0; j < N; j++)
			{
				cin >> caracter;
				meh.push_back(caracter);
			}
			square.push_back(meh);
		}

		bN = N;
    for(int x = 0; x < N; x++)
    {
		for(int i = 0; i < N && bN <= (N-i); i++)
		{
			for(int j = 0; j <  N && bN <= (N-j); j++)
			{
				found = buscar_grilla(square, N, bN, i, j);
				if( found )
					break;
			}
			if (found )
				break;
		}
		if (found )
				break;
        bN--;
    }
		cout << bN << endl;
		square.clear();

	}

	return 0;
}

/*#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> visits;
    int m,n, visited(0);

    while( cin >> m >> n && m != -1 && n != -1)
    {
        cin.ignore(), cin.clear();

        for(int i = m; visited < n; i = i+m)
        {
            visits.insert( (i%n) );
            visited++;
        }

        if( visits.size() == visited )
                cout << "YES" << endl;
            else
                cout << "POOR Haha" << endl;

        visited = 0;
        visits.clear();
    }

    return 0;
}


*/
/*

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string subfix(string verb)
{
int a = verb.size();
return ( a >= 2)? verb.substr(a-2) : "dude not";
}

string root(string verb)
{
return verb.substr(0, verb.size()-2);
}

string space(string pronoun)
{
int size = 10-pronoun.size();
string newstr = "";
for(int i=0; i < size; i++)
newstr += " ";

return newstr;
}

int main()
{

char letter = 243;

const char* pronoun[] = { "eu", "tu", "ele/ela", "n", "v", "eles/alas" };
vector<string> vpronoun(pronoun, pronoun + 6);

vpronoun[3].push_back(letter), vpronoun[3].push_back('s');
vpronoun[4].push_back(letter), vpronoun[4].push_back('s');

const char* con1[] = { "o", "as", "a", "amos", "ais", "am" };
vector<string> vcon1(con1, con1 + 6);

const char* con2[] = { "o", "es", "e", "emos", "eis", "em" };
vector<string> vcon2(con2, con2 + 6);

const char* con3[] = { "o", "es", "e", "imos", "is", "em" };
vector<string> vcon3(con3, con3 + 6);

string verb1, verb2;

while( cin >> verb1 >> verb2 )
{
cin.ignore(); cin.clear();
cout << verb1 << " " << "(to " << verb2 << ")" << endl;

if ( subfix(verb1) == "ar" )
{
for(unsigned int i = 0; i < vpronoun.size(); i++)
{
cout << vpronoun[i] << space(vpronoun[i]) << root(verb1)+vcon1[i] << endl;
}
}

else if ( subfix(verb1) == "er" )
{
for(unsigned int i = 0; i < vpronoun.size(); i++)
{
cout << vpronoun[i] << space(vpronoun[i]) << root(verb1)+vcon2[i] << endl;
}
}

else if ( subfix(verb1) == "ir" )
{
for(unsigned int i = 0; i < vpronoun.size(); i++)
{
cout << vpronoun[i] << space(vpronoun[i]) << root(verb1)+con3[i] << endl;
}
}
else
{
cout << "Unknown conjugation" << endl;
}

cout << endl;
}

return 0;
}
*/
