#include <bits/stdc++.h>
using namespace std;
vector<int> hashTable(10, -1);
bool insert(int key)
{
    int originalIndex, index, i;
    originalIndex = (key % hashTable.size());
    index = originalIndex;
    i = 0;
    while (hashTable[index] != -1)
    {
        index = (originalIndex + ++i) % hashTable.size();
        if (index == originalIndex)
        {
            cout << "Full hai bhai" << endl;
            break;
        }
    }
    if (hashTable[index] == -1)
    {
        hashTable[index] = key;
        return true;
    }
    return false;
}
bool find(int key)
{
    int index, originalIndex, i;

    originalIndex = key % hashTable.size();
    index = originalIndex;
    i = 0;
    while (hashTable[index] != key)
    {
        index = (originalIndex + ++i) % hashTable.size();
        if (index == originalIndex)
        {

            break;
        }
    }
    if (hashTable[index] == key)
        return true;
    return false;
}
bool deleteKey(int key)
{
    int index, originalIndex, i;

    originalIndex = key % hashTable.size();
    index = originalIndex;
    i = 0;
    while (hashTable[index] != key)
    {
        index = (originalIndex + ++i) % hashTable.size();
        if (index == originalIndex)
        {
            break;
        }
    }
    if (hashTable[index] == key)
    {
        hashTable[index] = -1;
        return true;
    }
    return false;
}
void printHashTable()
{
    int i = 0;
    for (auto el : hashTable)
        cout
            << i++ << "  " << el << endl;
}
void setPlay()
{
    unordered_set<int> ht;
    ht.insert(10);
    ht.erase(10);
    if (ht.find(10) != ht.end())
        cout << "present " << endl;
    else
        cout << "not present " << endl;
}
int main()
{
    vector<int> nums = {5, 50, 10, 15, 60, 3, 56, 23, 90, 332, 454, 45};
    for (int el : nums)
        insert(el);
    for (int el : nums)
        cout << "does " << el << " exist in hashTable " << find(el) << endl;
    printHashTable();
    cout << "successfully deleted " << deleteKey(56) << endl;
    setPlay();
}