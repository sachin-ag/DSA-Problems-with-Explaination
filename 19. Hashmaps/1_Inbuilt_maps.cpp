#include <iostream>
using namespace std;
// two types of inbuilt maps
// Ordered-Maps -> using BST -> O(logn)
// Unordered-Maps -> using Hash Tables -> O(1)
#include <unordered_map>
#include <string>

int main () {
    unordered_map<string, int> ourmap;

    // insert method 1 :-
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    // insert method 2 :-
    ourmap["def"] = 2;

    // find or access :-
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;

    // cout << ourmap.at("ghi") << endl; // gives error
    cout << "Size: " << ourmap.size() << endl;
    // !IMPORTANT!
    cout << ourmap["ghi"] << endl; // ghi does not exist but
    // calling this adds "ghi" to the map with default value 0
    // so beware while using this!
    cout << "Size: " << ourmap.size() << endl;

    // check presence
    if (ourmap.count("ghi") > 0) { // count returns no of times a key appears, it can be 0 or 1
        cout << "ghi is present" << endl;
    } else {
        cout << "ghi is not present" << endl;
    }

    // erase
    ourmap.erase("ghi");
    cout << "Size: " << ourmap.size() << endl;

    if (ourmap.count("ghi") > 0) {
        cout << "ghi is present" << endl;
    } else {
        cout << "ghi is not present" << endl;
    }

    return 0;
}