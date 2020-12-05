
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    string ;
}

int main(){
    int cases;

    while (cin >> cases) {
        vector<string> names;
        while (cases--) {
            string tmp;
            cin >> tmp;
            names.push_back(tmp);
        }

        int other_cases;
        cin >> other_cases;
        vector<pair<string, string>> hate;
        while (other_cases--) {
            string a,b;
            cin >> a >> b;
            hate.push_back(make_pair(a,b));
        }

        // debug
        // sort(names.begin(), names.end());
        for (auto str : hate) {
            cout << str.first << endl;
        }
    }
    

    return 0;
}