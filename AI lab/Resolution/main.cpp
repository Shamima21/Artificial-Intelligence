#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main ( )
{
	string line;

	int i = 0;

	vector < string > v;
	vector < string > Clause;

	ifstream fin;

	fin.open( ( "file.txt" ) );

	if ( fin.is_open())
	{
		while ( getline ( fin, line ))
		{
			stringstream ss ( line );

			if ( getline ( ss, line, ','))
			{
				v.push_back( line );
			}
		}

		while ( v.size() )
		{
			cout << v [ i] << "\n";


        int s=v[i].find("->");
        cout<<v[i].substr(0,s)<<endl;
        v[i].replace(s+1,s,"**");
        cout<<v[i]<<endl;

            i++;
		}

	}

	return 0;
}
