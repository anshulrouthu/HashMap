#include <iostream>
#include <string>
#include <assert.h>
#include "../src/HashMap.h"

using namespace std;

struct MyKeyHash {
    unsigned long operator()(const int& k) const
    {
        return k % 10;
    }
};

int main() 
{
	HashMap<int, string, MyKeyHash> hmap;
	hmap.Put(1, "1");
	hmap.Put(2, "2");
	hmap.Put(3, "3");
 
	string value;
	bool result = hmap.Get(2, value);
	assert(result);
	assert(value == "2");

	result = hmap.Get(3, value);
	assert(result);
	assert(value == "3");

	hmap.Remove(3);
	result = hmap.Get(3, value);
	assert(!result);

	cout << "All tests passed!" << endl;
}
