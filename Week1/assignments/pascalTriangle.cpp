#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'nthRowOfPascalTriangle' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */

int factorial(int n)
{
    if(n==0) return 1;
  int ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    return ans;
}

vector<int> nthRowOfPascalTriangle(int n) {
//the first thing we have to note is that in ith row there will be i-1 integers
    //then each term is basically nCr=n!/(n-r)!*r! 
    n=n-1;
    vector<int> pascal;
    int compute=0;
    for (int i=0;i<=n;i++){
        compute=(factorial(n)/(factorial(n-i)*factorial(i)));
        pascal.push_back(compute);
    }
    return pascal;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> result = nthRowOfPascalTriangle(n);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
