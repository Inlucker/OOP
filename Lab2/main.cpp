#include <iostream>
#include <iterator>

#include "vector.h"

using namespace std;

int main()
{
    try
    {
        //BaseVector v1();
        Vector<double> test_vec(3, 3., 4., 5.);
        Vector<double> test_vec2(3, 5., 4., 3.);
        //Vector3D<double> v3;
        cout << "Length of vector "<< test_vec <<": " << test_vec.len() << "\n";
        for (auto elem:test_vec)
            cout << elem << endl;
        cout << endl;

        /*Iterator It2 = test_vec2.begin();
        for (Iterator<double> It = test_vec.begin(); It != test_vec.end(); It++)
        {
            auto elem = *It;
            cout << elem << endl;
            elem = *It2;
            cout << elem << endl;
            cout << bool(It2 == It) << endl;
            It2++;
        }
        cout << endl;*/

        /*for (Iterator<double> It = test_vec.begin(); It != test_vec.end(); ++It)
        {
            auto elem = *It;
            cout << elem << endl;
        }
        cout << endl;*/
    }
    catch (...)
    {
        cout << "Error" << endl;
    }
    return 0;
}
