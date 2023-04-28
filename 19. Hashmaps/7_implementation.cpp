#include <iostream>
using namespace std;
#include <string>

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
        return 0;
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
        return 0;
    }
};

int main() {

    return 0;
}