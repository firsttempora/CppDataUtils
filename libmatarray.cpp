#include <string>
#include <sstream>
#include <vector>
#include <exception>

using namespace std;

namespace matarray{
   
    class reshape_exception : public exception{
        // Strings are immutable, so a char array pointer to a string
        // must be constant
        const char* msg_;

        reshape_exception(){
            msg_ = "Bad reshape operation";
        }
        
        reshape_exception(const char* msg){
            msg_ = msg;
        }
   
        virtual const char* what() const throw(){
            return msg_;
        }
    };        
 
    template <class T>
    class NdArray{
        vector<int> shape_;
        T* data_;

        public:
        // Constructor
        NdArray(vector<int> new_shape){
            shape_ = vector<int>(new_shape);
            int n = numel();
            data_ = new T[n];
        }

        //Destructor - needs to free the data pointer
        ~NdArray(){
            delete[] data_;
        }
        
        // Getters and setters
        vector<int> const& shape() const { return shape_; }

        string shapestr() {
            stringstream strs;
            strs << "[ ";
            for(int i=0; i<shape_.size(); i++){
                strs << shape_[i] << " ";
            }
            strs << "]";
            return strs.str();
        }

        // Other public methods
        int numel(vector<int> the_shape){
            // Number of elements of an array that has the given shape. Unlikely
            // to be used, rather this is usually going to be called by the no-argument
            // version, but will keep this public just in case.
            int numel = 1;
            for(int i=0; i<the_shape.size(); i++){
                numel *= the_shape[i];
            }
            return numel;
        }

        int numel(){
            // Number of elements of this instance of NdArray
            return numel(shape_);
        }

        void reshape(vector<int> new_shape){
            int new_n = numel(new_shape);
            if ( new_n != numel() ){

            }
        }

        // Non-numerical methods
    };

/*    NdArray<int> seq_mat(vector<int> shape){

    }*/

}
