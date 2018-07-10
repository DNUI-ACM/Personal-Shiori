#include <iostream>
#include <functional>
#include <cstdlib>
#include <cstdio>
#include <stdexcept>

using namespace std;

template <class T>
class Vector
{
  public:
    Vector() : _size(0), _capacity(8)
    {
        arr = new T[8];
    }

    Vector(const T &value) : _size(0), _capacity(8)
    {
        arr = new T[8];
        for (int iter = 0; iter < 8; iter++)
        {
            arr[iter] = value;
        }
    }

    Vector(int cou, const T &value) : _size(cou), _capacity(cou)
    {
        arr = new T[8];
        for (int iter = 0; iter < cou; iter++)
        {
            arr[iter] = value;
        }
    }

    Vector(const Vector &V) : _size(V->_size), _capacity(V->_capacity)
    {
        arr = new T[V->_capacity];
        for (int iter = 0; iter < _capacity; iter++)
        {
            arr[iter] = V[iter];
        }
    }

    ~Vector()
    {
        delete[](arr);
    }

    void clear()
    {
        _size = 0;
    }

    void push_back(const T &value)
    {
        return insert(_size, value);
    }

    void pop_back()
    {
        if (_size > 0)
        {
            _size--;
        }
    }

    void erase(int pos)
    {
        _size--;
        for (int iter = pos; iter < _size; iter++)
        {
            arr[iter] = arr[iter + 1];
        }
    }

    void insert(int pos, const T &value)
    {
        if (pos < _size - 1)
        {
            _size++;
        }
        else if (pos > _size && (pos < _capacity))
        {
            _size = pos + 1;
        }
        else
        {
            d_cap();
            while (pos >= _capacity)
            {
                d_cap();
            }
            _size = pos + 1;
        }
        arr[pos] = value;
    }

    int capacity() const
    {
        return _capacity;
    }

    void reserve(unsigned long long new_cap)
    {
        // try
        // {
        //     arr[new_cap];
        // }
        if (new_cap < _capacity)
        {
            cout << "std::length_error" << endl;
            //throw length_error();
        }

        else
        {
            while (new_cap > _capacity)
            {
                d_cap();
            }
            // function<void(T *)> fun = [&](T *arr) -> void {
            //     T *arr1 = new T[2 * max_size];
            //     arr1 = arr;
            //     while (new_cap > arr1->_capacity)
            //     {
            //         fun(arr1);
            //     }
            // };
            // fun(arr);
        }
    }

    int max_size()
    {
        return _capacity;
    }

    int size()
    {
        return _size;
    }

    T *begin()
    {
        return arr;
    }

    T *end()
    {
        return _size + arr;
    }

    bool empty()
    {
        return begin() == end();
    }

    void shrink_to_fit()
    {
        if (_capacity > _size)
        {
            r_cap(_size);
        }
    }

    T front()
    {
        return arr[0];
    }

    T back()
    {
        return arr[_size - 1];
    }

    T at(int pos)
    {
        if (pos >= _size - 1)
        {
            cout << "std::out_of_range" << endl;
            //throw out_of_range();
            return 0;
        }
        return arr[pos];
    }

    T *data(int pos)
    {
        return arr + pos;
    }

    void resize(int count, const T &value)
    {
        if (count != _capacity)
        {
            int x = _capacity;
            r_cap(count);
            if (x < count)
            {
                for (int i = x; i < count; i++)
                {
                    arr[i] = value;
                }
            }
        }
    }

    T operator[](int pos) const
    {
        return arr[pos];
    };

  private:
    T *arr;
    int _capacity;
    int _size;
    void r_cap(int count)
    {
        T *arr1 = new T[count];
        for (int iter = 0; iter < count; iter++)
        {
            arr1[iter] = arr[iter];
        }
        _capacity = count;
        _size = count;
        delete[](arr);
        arr = arr1;
    }
    void d_cap()
    {
        T *arr1 = new T[2 * _capacity];
        for (int iter = 0; iter < _capacity; iter++)
        {
            arr1[iter] = arr[iter];
        }
        _capacity *= 2;
        delete (arr);
        arr = arr1;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Vector<int> V;
    V.push_back(1);
    V.push_back(7);
    V.insert(18, 18);
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << ' ';
    }
    cout << endl
         << endl;
    V.resize(40, 3);
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << ' ';
    }
    cout << endl
         << endl;
    V.reserve(99999);
    return 0;
}

// V.push_back(1);
// V.push_back(7);
//first print

// cout << V.begin() << endl;
// cout << V.end() << endl
//      << endl;

// V.clear();
// cout << V.size() << endl
//      << V.max_size() << endl
//      << endl;
// V.push_back(1);
// V.push_back(7);
// V.insert(1, 9);
// cout << V[0] << ' ' << V[1] << ' ' << V[2] << endl;
// V.insert(18, 18);
// cout << V[18] << ' ' << V.max_size() << endl;
// V.erase(1);
// for (int i = 0; i < V.size(); i++)
// {
//     cout << V[i] << ' ';
// }
// cout << endl
//      << endl;
// V.reserve(40);
// for (int i = 0; i < V.capacity(); i++)
// {
//     cout << V[i] << ' ';
// }
// cout << endl
//      << endl;
// V.shrink_to_fit();
// cout << V.front() << ' ' << V.back() << endl
//      << endl;
// // cout << V.at(1) << endl;
// cout << V.data(0) << endl;
// V.resize(3, 2);
// for (int i = 0; i < V.size(); i++)
// {
//     cout << V[i] << ' ';
// }
// cout << endl
//      << endl;
// // cout << V.at(1) << endl;
// V.insert(10, 2);
// for (int i = 0; i < V.capacity(); i++)
// {
// cout << V[i] << ' ';
// }
// cout << endl
//      << endl;
// V.shrink_to_fit();
// for (int i = 0; i < V.capacity(); i++)
// {
//     cout << V[i] << ' ';
// }
// cout << endl
//      << endl;
