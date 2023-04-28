#include <iostream>
using namespace std;
#include <string>
// this code does rehashing in insert function

template <typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key, V value) {
        this -> key = key;
        this -> value = value;
        this -> next = NULL;
    }

    ~MapNode() {
        delete this -> next;
    }
};

template <typename V>
class ourmap{

    MapNode<V>** buckets; // array of MapNode<V>*
    int count;
    int noOfBuckets;

    public:

    ourmap() {
        count = 0;
        noOfBuckets = 5;
        buckets = new MapNode<V>*[noOfBuckets];
        for (int i=0; i<noOfBuckets; i++) {
            buckets[i] = NULL; // to remove garbage addresses
        }
    }

    ~ourmap() {
        for (int i=0; i<noOfBuckets; i++) {
            delete buckets[i]; // deleting all linked lists
        }
        delete [] buckets;
    }

    int size() {
        return count;
    }

    private:
    int getBucketIndex(string key) {
        int hashCode = 0;

        int currCoeff = 1;
        for (int i=key.length()-1; i>=0; i++) {
            hashCode += key[i] * currCoeff;
            currCoeff *= 37;
            currCoeff = currCoeff % noOfBuckets; // to make sure hashcode is in range of int
            hashCode = hashCode % noOfBuckets; // to make sure hashcode is in range of int
        }

        return hashCode % noOfBuckets;
    }

    void rehash() { // rehashing function
        MapNode<V>** temp = buckets; // old array
        buckets = new MapNode<V>*[2*noOfBuckets]; // new bucket of double size
        int oldBucketCount = noOfBuckets;
        noOfBuckets *= 2;
        for (int i=0; i<noOfBuckets; i++) {
            buckets[i] = NULL; // to remove garbage
        }
        count = 0; // as will re add elements to new bucket from old using insert func
        for (int i=0; i<oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            while (head != NULL) {
                insert(head -> key, head -> value);
                head = head -> next;
            }
        }
        for (int i=0; i<oldBucketCount; i++) {
            delete temp[i];
        }
        delete [] temp;
    }

    public:
    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL) {
            if (head -> key == key) {
                head -> value = value;
                return;
            }
            head = head -> next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* newNode = new MapNode<V>(key, value);
        newNode -> next = head;
        buckets[bucketIndex] = newNode;
        count++;
        // rehashing:
        double loadfactor = (1.0*count)/noOfBuckets;  // we did 1.0* as count was int
        if (loadfactor > 0.7) {
            rehash();
        }
    }

    double getLoadFactor() {
        return (1.0*count)/noOfBuckets;
    }

    V getValue(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while (head != NULL) {
            if (head -> key == key) {
                return head -> value;
            }
            head = head -> next;
        }
        return 0; // if given key is not present
    }

    V remove(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while (head != NULL) {
            if (head -> key == key) {
                if (prev == NULL) {
                    buckets[bucketIndex] = head -> next;
                } else {
                    prev -> next = head -> next;
                }
                V ans = head -> value;
                head -> next = NULL;
                delete head;
                return ans;
                count--;
            }
            prev = head;
            head = head -> next;
        }
        return 0; // if given key is not present
    }
};

int main() {
    ourmap<int> mymap;
    for (int i=0; i<10; i++) {
        char c = '0' + i;
        string key = "abc" + c;
        int value = i + 1;
        mymap.insert(key, value);
        cout << mymap.getLoadFactor() << endl;
    }
    cout << mymap.size() << endl;
    mymap.remove("abc2");
    mymap.remove("abc8");
    cout << mymap.size() << endl;
    for (int i=0; i<10; i++) {
        char c = '0' + i;
        string key = "abc" + c;
        cout << key << " : " << mymap.getValue(key) << endl;
    }
    return 0;
}