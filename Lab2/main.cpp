#include <iostream>
#include <iterator>

#include "vector.h"

using namespace std;

int main()
{
    try
    {
        //BaseVector v1();
        Vector3D<double> test_vec(3., 4., 5.);
        //Vector3D<double> v3;
        cout << "Length of vector "<< test_vec <<": " << test_vec.len() << "\n";
        for (auto elem:test_vec)
            cout << elem << endl;
        for (Iterator It = test_vec.begin(); It != test_vec.end(); It++)
        {
            auto elem = *It;
            cout << elem << endl;
        }
        for (Iterator It = test_vec.begin(); It != test_vec.end(); ++It)
        {
            auto elem = *It;
            cout << elem << endl;
        }
    }
    catch (...)
    {
        cout << "Error" << endl;
    }
    return 0;
}
