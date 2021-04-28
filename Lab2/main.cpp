#include <iostream>
#include <iterator>

#include "vector.h"

using namespace std;

Vector<double> generate_double_Vector(int n)
{
    Vector<double> item(n);
    return item; // это возвращаемое значение приведет к вызову конструктора перемещения
}

int main()
{
    try
    {
        cout << "CONSTRUCTORS TESTS:" << endl;

        Vector<double> empty_vec;
        cout << "empty_vec: " << empty_vec << endl;

        cout << endl;

        Vector<double> zero_vec(4);
        cout << "zero_vec: " << zero_vec << endl;

        cout << endl;

        double mas[5] = {3, 4, 5, 6, 7};
        Vector<double> mas_vec(5, mas);
        cout << "mas_vec: " << mas_vec << endl;

        cout << endl;

        Vector<double> param_vec(3, 3., 4., 5.);
        cout << "param_vec: " << param_vec << endl;

        cout << endl;

        Vector<double> init_list_vec{1., 2., 3.};
        cout << "init_list_vec: " << init_list_vec << endl;

        cout << endl;

        Vector<double> copy_vec(init_list_vec);
        cout << "copy_vec: " << copy_vec << endl;
        copy_vec[2] = 333;
        cout << "copy_vec[2] = 333; copy_vec: " << copy_vec << endl;

        cout << endl;

        Vector<double> equal_vec{1, 2, 3};
        equal_vec = copy_vec;
        cout << "equal_vec: " << equal_vec << endl;
        equal_vec.set_elem(2, 222);
        cout << "equal_vec.set_elem(2, 222); equal_vec: " << copy_vec << endl;

        cout << "\n" << endl;

        cout << "MATH TESTS:" << endl;
        Vector<double> unit_vec = copy_vec.get_unit();
        cout << "unit_vec: " << unit_vec << endl;
        cout << "unit_vec.len(): " << unit_vec.len() << endl;

        cout << endl;

        cout << "copy_vec * copy_vec = " << copy_vec * copy_vec << endl;

        cout << endl;

        //cout << "{0, 1}.copy_vec.get_angle({1, 0}) = " << Vector<double>{0, 1}.get_angle(Vector<double>{1, 0}) << endl;
        cout << "{0, 1}.copy_vec.get_angle({1, 0}) = " << Vector<double>{0, 1}.get_angle({1, 0}) << endl;
        //cout << "get_angle({0, 1}, {1, 0}) = " << get_angle(Vector<double>{0, 1}, Vector<double>{1, 0}) << endl;
        cout << "get_angle({0, 1}, {1, 1}) = " << get_angle(Vector<double>{0, 1}, {1, 1}) << endl;

        cout << endl;

        cout << "is_collinear({1, 1}, {1, 1}) = " << is_collinear(Vector<double>{1, 1.0000000000001}, {1, 1.0000000000001}) << endl;
        cout << "is_collinear({1, 0}, {0, 1}) = " << is_collinear(Vector<double>{1, 0}, {0, 1}) << endl;

        cout << endl;

        cout << "is_orthogonal({1, 1}, {1, 1}) = " << is_orthogonal(Vector<double>{1, 1.0000000000001}, {1, 1.0000000000001}) << endl;
        cout << "is_orthogonal({1, 0}, {0, 1}) = " << is_orthogonal(Vector<double>{1, 0}, {0, 1}) << endl;

        cout << endl;

        Vector<double> start_vec{3, 2, 1};
        cout << "start_vec = " << start_vec << endl;
        cout << "start_vec + 10 = " << start_vec + 10 << endl;
        cout << "start_vec + start_vec = " << start_vec + start_vec << endl;
        start_vec += 20;
        cout << "start_vec += 20 = " << start_vec << endl;

        cout << endl;

        cout << "{1, 2, 3} + {3, 2, 1} = " << Vector<double>{1, 2, 3} + Vector<double>{3, 2, 1} << endl;
        Vector<double> slog_vec1{1, 2, 3};
        cout << "slog_vec1 = " << slog_vec1 << endl;
        //slog_vec1 = (slog_vec1 + slog_vec1); // нельзя вызвать конструктор переноса явно
        slog_vec1 += slog_vec1;
        cout << "slog_vec1 += slog_vec1 = " << slog_vec1 << endl;

        cout << endl;

        start_vec = Vector<double>{3, 2, 1};
        cout << "start_vec = " << start_vec << endl;
        cout << "start_vec - 10 = " << start_vec - 10 << endl;
        cout << "start_vec - start_vec = " << start_vec - start_vec << endl;
        start_vec -= 20;
        cout << "start_vec -= 20 = " << start_vec << endl;

        cout << endl;

        cout << "{1, 2, 3} - {3, 2, 1} = " << Vector<double>{1, 2, 3} - Vector<double>{3, 2, 1} << endl;
        slog_vec1 = Vector<double>{1, 2, 3};
        cout << "slog_vec1 = " << slog_vec1 << endl;
        slog_vec1 -= slog_vec1;
        cout << "slog_vec1 -= slog_vec1 = " << slog_vec1 << endl;

        cout << endl;

        start_vec = Vector<double>{3, 2, 1};
        cout << "start_vec = " << start_vec << endl;
        cout << "start_vec * 10 " << start_vec * 10 << endl;
        cout << "start_vec / 10 " << start_vec / 10 << endl;
        start_vec *= 10;
        cout << "start_vec *= 10 = " << start_vec << endl;
        start_vec /= 10;
        cout << "start_vec /= 10 = " << start_vec << endl;

        cout << endl;

        Vector<double> mn_vec1{1, 2, 3};
        cout << "mn_vec1 = " << mn_vec1 << endl;
        Vector<double> mn_vec2{3, 2, 1};
        cout << "mn_vec2 = " << mn_vec2 << endl;
        cout << "mn_vec1 & mn_vec2" << (mn_vec1 & mn_vec2) << endl;
        mn_vec1 &= mn_vec2;
        cout << "mn_vec1 &= mn_vec2 =" << mn_vec1 << endl;
        mn_vec2 &= mn_vec1;
        cout << "mn_vec2 &= mn_vec1 =" << mn_vec2 << endl;

        cout << endl;

        Vector<double> mn_vec3{1, 2};
        cout << "mn_vec3 = " << mn_vec3 << endl;
        Vector<double> mn_vec4{3, 2};
        cout << "mn_vec4 = " << mn_vec4 << endl;
        cout << "mn_vec3 & mn_vec4" << (mn_vec3 & mn_vec4) << endl;
        /*mn_vec3 &= mn_vec4;
        cout << "mn_vec3 &= mn_vec4 =" << mn_vec3 << endl;
        mn_vec4 &= mn_vec3;
        cout << "mn_vec4 &= mn_vec3 =" << mn_vec4 << endl;*/

        cout << endl;

        Vector<double> double_vec{1.5, 2.5, 3.5};
        cout << "double_vec = " << double_vec << endl;
        Vector<int> int_vec{30, 15, 10};
        cout << "int_vec = " << int_vec << endl;
        cout << "double_vec * int_vec = " << double_vec * int_vec << endl;
        cout << "int_vec * double_vec = " << int_vec * double_vec << endl;
        double_vec *= int_vec;
        cout << "double_vec *= int_vec = " << double_vec << endl;
        int_vec *= double_vec;
        cout << "int_vec *= int_vec = " << int_vec << endl;

        cout << endl;

        cout << "double_vec = " << double_vec << "; int_vec = " << int_vec << endl;
        cout << "int_vec + double_vec" << int_vec + double_vec << endl;
        cout << "double_vec + int_vec" << double_vec + int_vec << endl;
        double_vec += int_vec;
        cout << "double_vec += int_vec = " << double_vec << endl;
        int_vec += double_vec;
        cout << "int_vec += double_vec = " << int_vec << endl;

        cout << endl;

        Vector<double> gen_vec;
        gen_vec = generate_double_Vector(7);
        cout << "gen_vec = " << gen_vec << endl;

        cout << "\n" << endl;

        cout << "ITERATOR TESTS:" << endl;
        Vector<int> vec{10, 9, 8, 7, 6, 5};
        cout << "vec = " << vec << endl;
        Iterator<int> it1 = vec.begin();
        Iterator<int> it2 = vec.end();
        cout << "*it1 = " << *it1 << endl;
        cout << "*it2 = " << *it2 << endl;

        cout << endl;


        Iterator<int> it3;
        it3 = it1;
        cout << "it3 = it1; *it3 = " << *it1 << endl;
        it3++;
        cout << "it3++; *it1 = " << *it1 << "; *it3 = " << *it3 << endl;

        cout << "it2 == it1 = " << (it2 == it1) << endl;
        cout << "it2 != it1 = " << (it2 != it1) << endl;

        cout << endl;

        cout << "*++it1 = " << *++it1 << endl;
        cout << "*it1++ = " << *it1++ << endl;
        cout << "*it1 = " << *it1 << endl;

        cout << endl;

        cout << "*--it2 = " << *--it2 << endl;
        cout << "*it2-- = " << *it2-- << endl;
        cout << "*it2 = " << *it2 << endl;

        cout << endl;

        cout << "*(it1 + 2) = " << *(it1 + 2) << endl;
        it1 += 3;
        cout << "it1 += 3; *it1 = " << *it1 << endl;

        cout << endl;

        cout << "*(it2 - 2) = " << *(it2 - 2) << endl;
        it2 -= 3;
        cout << "it2 -= 3; *it2 = " << *it2 << endl;

        cout << endl;

        cout << "it1 - it2 = " << it1 - it2 << endl;

        cout << endl;

        cout << "it1[-4] = " << it1[-4] << endl;
        cout << "it2[4] = " << it2[4] << endl;

        cout << endl;

        cout << "*it1 = " << *it1 << "; *it2 = " << *it2 << endl;
        cout << "it1 id = " << it1.get_id() << "; it2 id = " << it2.get_id() << endl;
        cout << "it1 < it2 = " << (it1 < it2) << endl;
        cout << "it1 <= it2 = " << (it1 <= it2) << endl;
        cout << "it1 > it2 = " << (it1 > it2) << endl;
        cout << "it1 >= it2 = " << (it2 >= it1) << endl;

        cout << endl;

        it1 -= 4;
        cout << "*it1 = " << *it1 << "; *it2 = " << *it2 << endl;
        cout << "it1 id = " << it1.get_id() << "; it2 id = " << it2.get_id() << endl;
        cout << "it1 < it2 = " << (it1 < it2) << endl;
        cout << "it1 <= it2 = " << (it1 <= it2) << endl;
        cout << "it1 > it2 = " << (it1 > it2) << endl;
        cout << "it1 >= it2 = " << (it1 >= it2) << endl;

        /*cout << endl;

        cout << "it1.operator->() = " << it1.operator->() << endl;
        cout << "it2.operator->() = " << it2.operator->() << endl;
        cout << "*(it1.operator->()) = " << *(it1.operator->()) << endl;
        cout << "*(it2.operator->()) = " << *(it2.operator->()) << endl;*/

        //cout << "\n\n" << endl;
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
