#include "libmatarray.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace matarray;

int main(){
    vector<int> v = {3,4,5};
    NdArray<double> test_array = NdArray<double>(v);
    
    cout << "Array size = " << test_array.numel() << endl;
    cout << "Array shape = " << test_array.shapestr() << endl;
    return 0;
}
