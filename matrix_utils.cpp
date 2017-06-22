#include <iostream>
#include <limits>
#include <boost/multi_array.hpp>
#include <math.h>
#include <vector>

template<class T>
void boost_minmax_internal(const T& arr, double* curr_min, std::vector<int>* ind_arr, size_t curr_dim){
    typename T::size_type dims = arr.num_dimensions();
    if( dims > 1 ){
        for(typename T::index i=0; i<arr.shape()[0]; i++){
            double last_min = *curr_min;
            //T sub_arr = arr[0];
            boost_minmax_internal(arr[0], curr_min, ind_arr, curr_dim+1);
            if( *curr_min < last_min ){
                (*ind_arr)[curr_dim] = i;
            }
        }
    }else{
        for(typename T::index i=0; i<arr.shape()[0]; i++){
            if(arr[i] < *curr_min){
                *curr_min = arr[i];
                (*ind_arr)[curr_dim] = i;
            }
        }
    }
    return;
}

template<class T>
std::vector<int> boost_min_inds(T& arr){
    std::vector<int> inds(arr.num_dimensions());
    double curr_min = std::numeric_limits<double>::max();
    boost_minmax_internal(arr, &curr_min, &inds, (size_t)0);
    return inds;
}


//main for testing only
int main(){
    typedef boost::multi_array<double,2> array;
    array A(boost::extents[9][9]);
    for(array::index i=0; i<A.shape()[0]; i++){
        std::cout << "[ ";
        for(array::index j=0; j<A.shape()[1]; j++){
            double val = pow((double)i-5,2) + pow((double)j-3,2);
//            std::cout << "(" << i << "," << j << ") =" << val << std::endl;
            std::cout << val << " ";
            A[i][j] = val;
        }
        std::cout << "]" << std::endl;
    }

    std::vector<int> min_inds = boost_min_inds(A);
    std::cout << "Indicies of minimum value: ";
    for(size_t i=0; i<A.num_dimensions(); i++){
        std::cout << min_inds[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}


/*template<class T>
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
}*/
