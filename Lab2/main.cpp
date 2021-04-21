#include <iostream>
#include <iterator>

#include "vector.h"

using namespace std;

int main()
{
    try
    {
        //BaseVector v1();
        //Vector3D<double> v3(3.0, 4.0, 5.0);
        Vector3D<double> v3(3., 4., 5.);
        //cout << v3 << endl;
        cout << "Length of vector "<< v3 <<": " << v3.len() << "\n";
        /*for (auto elem:v3)
            cout << elem << endl;*/
        for (Iterator It = v3.begin(); It != v3.end(); It++)
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
