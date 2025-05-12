#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER n as parameter.
 */

string solve(int n) {
    long long res;
    queue<long long> q;
    set<long long> visited;
    q.push(9);
    while(!q.empty()){
        long long curr=q.front();
        if(curr%n==0){
            res=curr;
            break;
        }
        long long num1=curr*10;
        long long num2=curr*10+9;
        if(visited.find(num1)==visited.end()){
            q.push(num1);
            visited.insert(num1);
        }
        if(visited.find(num2)==visited.end()){
            q.push(num2);
            visited.insert(num2);
        }
        q.pop();
    }
    return to_string(res);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string result = solve(n);

        fout << result << "\n";
    }

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
