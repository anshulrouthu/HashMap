#include <iostream>
#include <string>
#include <assert.h>
#include "HashMap.h"

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
	hmap[2] = "2";
	hmap.Put(3, "3");
 
	string value;
	bool result = hmap.Get(2, value);
	assert(result);
	assert(value == "2");

	result = hmap.Get(3, value);
	assert(result);
	assert(value == "3");

    assert(hmap[1] == "1");
    assert(hmap[2] == "2");
    assert(hmap[3] == "3");

	hmap.Remove(3);
	result = (hmap[3] == "3");
	assert(!result);

	HashMap<const char*, int> hmap2;

	hmap2["12"] = 1;
	hmap2["21"] = 2;
	hmap2["3"] = 3;

    assert(hmap2["12"] == 1);
    assert(hmap2["21"] == 2);
    assert(hmap2["3"] == 3);

    hmap2["3"] = 4;
    assert(!(hmap2["3"] == 3));
    assert(hmap2["3"] == 4);

	cout << "All tests passed!" << endl;
}
