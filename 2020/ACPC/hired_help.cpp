#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int>array) {
    int l = 0;
    int r = array.size()-1;
    while (l < r && l >= 0 && r < array.size()) {
        int mid = (l+ r)/2;

        if (array[mid] != array[0] && array[mid] != array[array.size()-1]) {
            return mid;
        }
        if (array[mid] == array[0]) {l = mid + 1;}
        else {r = mid;}
    }

    return -1;
}

int main() {
    int a,b;
    cin >> a >> b;
    
    vector<int> nums;
    for (int i = 0; i < a; i++) {
        int h;
        cin >> h;
        nums.push_back(h);
    }
    sort(nums.begin(), nums.end());
    // reverse(nums.begin(), nums.end());

    int count = 0;
    while (2 < nums.size() && nums[0] + 2 <= nums[nums.size()-1]) {
        // binary search here
        int middle_index = binary_search(nums);
        // cout << 0;
        // cout << middle_index<<endl;
        if (middle_index == -1) {
            // no unique middle number exists
            break;
        } else {
            nums.erase(nums.begin() + middle_index);
            nums.pop_back();
            nums.erase(nums.begin());
            count++;
        }
        // cout << nums.size() << endl;
    }

    cout << count << endl;

    return 0;
}
