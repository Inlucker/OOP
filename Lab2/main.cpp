#include <iostream>
#include <iterator>

#include "vector.h"

using namespace std;

int main()
{
    try
    {
        cout << "Constructors tests:\n" << endl;

        Vector<double> empty_vec;
        cout << "empty_vec: " << empty_vec << endl;

        Vector<double> zero_vec(4);
        cout << "zero_vec: " << zero_vec << endl;

        double mas[5] = {3, 4, 5, 6, 7};
        Vector<double> mas_vec(5, mas);
        cout << "mas_vec: " << mas_vec << endl;

        Vector<double> param_vec(3, 3., 4., 5.);
        cout << "param_vec: " << param_vec << endl;

        Vector<double> init_list_vec{1.1, 2.2, 3.3};
        cout << "init_list_vec: " << init_list_vec << endl;

        Vector<double> copy_vec(init_list_vec);
        cout << "copy_vec: " << copy_vec << endl;

        cout << "\n\n" << endl;

        //BaseVector v1();
        //Vector<double> test_vec_zero{1.2, 2.3, 3.4, 4.5, 5.6};
        Vector<double> test_vec_zero(4);
        cout << test_vec_zero << endl;
        Vector<double> test_vec(3, 3., 4.);
        //Vector<double> test_vec2(3, 5., 4., 3.);

        // checking copy constructor
        const Vector<double> test_vec2(test_vec);
        test_vec.set_elem(2, 1);
        double test_double = test_vec2[0];
        cout << "test_vec2[0] = " << test_double << endl;
        test_vec[0] = 55;

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

        //checkinh postfix increment
        for (Iterator<double> It = test_vec2.cbegin(); It != test_vec2.cend(); )
        {
            auto elem = *It++;
            //++It;
            cout << elem << endl;
        }
        cout << endl;
    }
    catch (BaseError& err)
    {
        cout << err.what() << endl;
    }
    catch (...)
    {
        cout << "Unexpected Error" << endl;
    }
    return 0;
}
