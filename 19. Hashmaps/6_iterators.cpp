#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
// iterators can be used in vector, set, map, unordered set, unordered map
// each one has a diff implementation of iterator so syntax is diff

int main() {
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;

    unordered_map<string, int> :: iterator it; // declaration of iterator
    it = ourmap.begin();
    // !IMPORTANT! ourmap.end() points to AFTER THE END OF MAP, NOT THE LAST ELEMENT
    while (it != ourmap.end()) {
        cout << "Key: " << it -> first << "  Value: " << it -> second << endl;
        it++;
    } // there will be no order as it is unordered map
    // we use "first" and "second" because unordered map store data in form of pairs

    // find - returns pointer to the specified key
    unordered_map<string, int> :: iterator it1 = ourmap.find("abc");
    // erase - can take both key and iterator, works similar in other containers
    ourmap.erase(it1);

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int> :: iterator it2 = v.begin();
    while (it2 != v.end()) {
        cout << *it2 << endl;
        it2++;
    }

    return 0;
}