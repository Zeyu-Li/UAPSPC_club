#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric>

using namespace std;

int main(){
    int cases;
    scanf("%d",&cases);
    
    while (cases--) {
        int inputs, tmp;
        cin >> inputs;
        tmp = inputs;
        vector<int> nums;
        while (tmp--) {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        float average = accumulate( nums.begin(), nums.end(), 0.0) / nums.size();

        int count = 0;
        for (int i : nums) {
            if (i > average)
                count++;
        }
        // cout << count << ':' << nums.size() << endl;

        // cout << fixed;
        cout << setprecision(3) << fixed;
        cout <<  100* count / float(nums.size()) << '%' <<endl;
    }

    return 0;
}