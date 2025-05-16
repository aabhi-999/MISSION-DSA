#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestRectangle' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY h as parameter.
 */
long largestRectangle(vector<int> h) 
{
    if (h.size() == 0)
        return 0;
    else if (h.size() == 1)
        return long(h[0]);
        
    int h_min = *min_element(h.begin() , h.end());
    long area_h_min = long(h_min) * long(h.size());
    
    vector<int> h_short;
    vector<int> possible_ans;
    possible_ans.push_back(area_h_min);
    
    for (int i = 0 ; i < h.size() ; i++)
    {
        if (  h[i] > h_min )
        {
            h_short.push_back(h[i]);
        }   
        else if (h[i] == h_min)
        {
            possible_ans.push_back(largestRectangle(h_short));
            h_short.clear();
        }
    }
    possible_ans.push_back(largestRectangle(h_short));
    h_short.clear();
    
    return *max_element(possible_ans.begin() , possible_ans.end());

}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
