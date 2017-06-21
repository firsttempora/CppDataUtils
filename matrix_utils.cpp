#include <iostream>
#include <boost/multi_array.hpp>


template<class T>
int[] find_min_inds(T& arr){
    double min_val = 1.79E+308;
    return find_min_inds(arr, min_val);
}

template<class T>
int[] find_min_inds(T& arr, double* min_val){
    size_type dims = arr.num_dimensions();
    int[] inds = new int[dims];

    if(dims == 1){
        for(arr::index i = 0; i<arr.shape(); i++){
            if(arr[i] < min_val){
                *min_val = arr[i];
                inds[0] = i;
            }
        }
    }
    else{
        for(arr::index i=0; i<arr.shape()[0]; i++){
            double last_min;
            int[] last_min_inds = find_min_inds(arr, &last_min);
            if(last_min < min_val){
                *min_val = last_min;
                inds[0] = i;
                for(size_t j=1; j<dims; j++){
                    inds[j] = last_min_inds[j+1];
                }
            }
        }
    }

    return inds
}
