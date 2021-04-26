#include <iostream>
#include <iterator>

#include "vector.h"

using namespace std;

int main()
{
    try
    {
        cout << "CONSTRUCTORS TESTS:" << endl;

        Vector<double> empty_vec;
        cout << "empty_vec: " << empty_vec << endl;

        Vector<double> zero_vec(4);
        cout << "zero_vec: " << zero_vec << endl;

        double mas[5] = {3, 4, 5, 6, 7};
        Vector<double> mas_vec(5, mas);
        cout << "mas_vec: " << mas_vec << endl;

        Vector<double> param_vec(3, 3., 4., 5.);
        cout << "param_vec: " << param_vec << endl;

        Vector<double> init_list_vec{1., 2., 3.};
        cout << "init_list_vec: " << init_list_vec << endl;

        Vector<double> copy_vec(init_list_vec);
        cout << "copy_vec: " << copy_vec << endl;

        Vector<double> equal_vec{1, 2, 3};
        equal_vec = copy_vec;
        cout << "equal_vec: " << equal_vec << endl;
        /*cout << "param_vec[1] = -1" << endl;
        param_vec[1] = -1;
        cout << "param_vec: " << param_vec << endl;
        cout << "equal_vec: " << equal_vec << endl;*/

        cout << endl;

        cout << "MATH TESTS:" << endl;
        Vector<double> unit_vec = copy_vec.get_unit();
        cout << "unit_vec: " << unit_vec << endl;
        cout << "unit_vec.len(): " << unit_vec.len() << endl;

        cout << "copy_vec * copy_vec = " << copy_vec * copy_vec << endl;

        //cout << "{0, 1}.copy_vec.get_angle({1, 0}) = " << Vector<double>{0, 1}.get_angle(Vector<double>{1, 0}) << endl;
        cout << "{0, 1}.copy_vec.get_angle({1, 0}) = " << Vector<double>{0, 1}.get_angle({1, 0}) << endl;
        //cout << "get_angle({0, 1}, {1, 0}) = " << get_angle(Vector<double>{0, 1}, Vector<double>{1, 0}) << endl;
        cout << "get_angle({0, 1}, {1, 1}) = " << get_angle(Vector<double>{0, 1}, {1, 1}) << endl;

        cout << "is_collinear({1, 1}, {1, 1}) = " << is_collinear(Vector<double>{1, 1.0000000000001}, {1, 1.0000000000001}) << endl;
        cout << "is_collinear({1, 0}, {0, 1}) = " << is_collinear(Vector<double>{1, 0}, {0, 1}) << endl;

        cout << "is_orthogonal({1, 1}, {1, 1}) = " << is_orthogonal(Vector<double>{1, 1.0000000000001}, {1, 1.0000000000001}) << endl;
        cout << "is_orthogonal({1, 0}, {0, 1}) = " << is_orthogonal(Vector<double>{1, 0}, {0, 1}) << endl;

        Vector<double> start_vec{3, 2, 1};
        cout << "start_vec = " << start_vec << endl;
        cout << "start_vec + 10 = " << start_vec + 10 << endl;
        start_vec += 20;
        cout << "start_vec += 20 = " << start_vec << endl;

        cout << "{1, 2, 3} + {3, 2, 1} = " << Vector<double>{1, 2, 3} + Vector<double>{3, 2, 1} << endl;
        Vector<double> slog_vec1{1, 2, 3};
        cout << "slog_vec1 = " << slog_vec1 << endl;
        slog_vec1 += slog_vec1;
        cout << "slog_vec1 += slog_vec1 = " << slog_vec1 << endl;

        start_vec = Vector<double>{3, 2, 1};
        cout << "start_vec = " << start_vec << endl;
        cout << "start_vec - 10 = " << start_vec - 10 << endl;
        start_vec -= 20;
        cout << "start_vec -= 20 = " << start_vec << endl;

        cout << "{1, 2, 3} - {3, 2, 1} = " << Vector<double>{1, 2, 3} - Vector<double>{3, 2, 1} << endl;
        slog_vec1 = Vector<double>{1, 2, 3};
        cout << "slog_vec1 = " << slog_vec1 << endl;
        slog_vec1 -= slog_vec1;
        cout << "slog_vec1 -= slog_vec1 = " << slog_vec1 << endl;

        start_vec = Vector<double>{3, 2, 1};
        cout << "start_vec = " << start_vec << endl;
        cout << "start_vec * 10 " << start_vec * 10 << endl;
        cout << "start_vec / 10 " << start_vec / 10 << endl;
        start_vec *= 10;
        cout << "start_vec *= 10 = " << start_vec << endl;
        start_vec /= 10;
        cout << "start_vec /= 10 = " << start_vec << endl;


        cout << "\n\n" << endl;

        //BaseVector v1();
        //Vector<double> test_vec_zero{1.2, 2.3, 3.4, 4.5, 5.6};
        Vector<double> test_vec_zero(4);
        cout << test_vec_zero << endl;
        Vector<double> test_vec(3, 3., 4., 5.);
        //Vector<double> test_vec2(3, 5., 4., 3.);

        // checking copy constructor
        const Vector<double> test_vec2(test_vec);
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
