#include <iostream>
#include <algorithm>
#include <vector>
#include "ICollection.hpp"

using namespace std;
//using namespace DataStructure;

template <typename T>
class Vector: public ICollection<T> {
private:
    vector<T> _vector;
public:
    Vector(): _vector(){}

    inline virtual int Count(){
        return _vector.size();
    }

    inline virtual bool IsReadOnly(){
        return false;
    }

    inline virtual void Add(T item){
        _vector.emplace_back(item);
    }

    inline virtual void Clear(){
        _vector.clear();
    }

    inline virtual bool Contains(T item){
        return find(_vector.begin(), _vector.end(), item) != _vector.end();
    }

    virtual bool Remove(T item){
        bool isExist = (find(_vector.begin(), _vector.end(), item) != _vector.end());

        if(isExist){
            _vector.erase(remove(_vector.begin(), _vector.end(), item), _vector.end());
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Vector<int> vec;
    ICollection<int>& collection = vec;
    int num;

    for(int i = 0; i < 10; i++){
        cin >> num;
        collection.Add(num);
    }
    cout << "Now the collection has " << collection.Count() << " items!\n";

    cin >> num;
    while(!collection.Contains(num)){
        cout << "The collection doesn't contain the item " << num << "!!\n";
        cin >> num;
    }
    cout << "The item " << num << " is in the collection!\n";
    collection.Remove(num);
    cout << "After removing, the item " << ((collection.Contains(num))? "is still in the collection!" : "is successfully removed from the collection!") << endl;
    cout << "Now the collection has " << collection.Count() << " items!\n";
}