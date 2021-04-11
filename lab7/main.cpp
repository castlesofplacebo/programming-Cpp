#include <iostream>
#include <iterator>
#include <exception>
#include <algorithm>
using namespace std;

/*Реализовать кольцевой буфер в виде stl-совместимого контейнера (например, может быть использован с стандартными
алгоритмами), обеспеченного итератором произвольного доступа.
Реализация не должна использовать ни одни из контейнеров STL.

Буфер должен обладать следующими возможностями:
1. Вставка и удаление в конец
2. Вставка и удаление в начало
3. Вставка и удаление в произвольное место по итератору
4. Доступ в конец, начало
5. Доступ по индексу
6. Изменение капасити*/

class bufExeption : public exception
{
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override
    {
        return "BUFFER IS EMPTY";
    }
};

class indexExeption : public exception
{
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override
    {
        return "INDEX IS NOT REAL";
    }
};

template <class T>
struct buffer_element
{
    buffer_element *prev;
    buffer_element *next;
    T value;
    bool is_end = false;
};

template <class T>
class buffer_iterator
    : public iterator<random_access_iterator_tag, T>
{
public:
    buffer_iterator() = delete;

    buffer_iterator(buffer_element<T> *p)
        : ptr_(p)
    {
    }

    buffer_iterator(const buffer_iterator<T> &it)
        : ptr_(it.ptr_)
    {
    }

    buffer_iterator<T> &operator=(const T &value)
    {
        ptr_ = *value;
        return *this;
    }

    buffer_iterator<T> &operator=(T *ptr)
    {
        ptr_ = ptr;
        return *this;
    }

    buffer_iterator<T> &operator=(const buffer_iterator<T> &it)
    {
        ptr_ = it.ptr_;
        return *this;
    }

    buffer_iterator<T> &operator+=(const int &val)
    {
        for (int i = 0; i < val; i++)
            ptr_ = ptr_->next;
        return *this;
    }

    buffer_iterator<T> &operator-=(const int &val)
    {
        for (int i = val; i > 0; i--)
            ptr_ = ptr_->prev;
        return *this;
    }

    T &operator*()
    {
        return ptr_->value;
    }

    buffer_iterator<T> &operator++()
    {
        ptr_ = ptr_->next;
        return *this;
    }

    buffer_iterator<T> &operator--()
    {
        ptr_ = ptr_->prev;
        return *this;
    }

    buffer_iterator<T> &operator++(int)
    {
        auto &tmp(*this);
        ptr_ = ptr_->next;
        return tmp;
    }

    buffer_iterator<T> &operator--(int)
    {
        auto &tmp(*this);
        ptr_ = ptr_->prev;
        return tmp;
    }

    buffer_iterator<T> operator+(const int val)
    {
        buffer_iterator it(*this);
        it += val;
        return it;
    }

    buffer_iterator<T> operator-(const int val)
    {
        buffer_iterator it(*this);
        it -= val;
        return it;
    }

    friend inline int operator+(const buffer_iterator<T> &it1, const buffer_iterator<T> &it2)
    {
        buffer_iterator<T> it = it1;
        int result1 = 0;
        while (it != it2)
        {
            result1++;
            it++;
        }

        it = it2;
        int result2 = 0;
        while (it != it1)
        {
            result2++;
            it++;
        }

        return min(result1, result2);
    }

    friend int operator-(buffer_iterator<T> it1, buffer_iterator<T> it2)
    {
        return -(it1 + it2);
    }

    friend buffer_iterator<T> operator+(const buffer_iterator<T> &it, const int &val)
    {
        return buffer_iterator(it + val);
    }

    friend buffer_iterator<T> operator-(const buffer_iterator<T> &it, const int &val)
    {
        return buffer_iterator(it - val);
    }

    friend bool operator==(const buffer_iterator<T> &it1, const buffer_iterator<T> &it2)
    {
        return it1.ptr_ == it2.ptr_;
    }

    bool operator==(T *it)
    {
        return ptr_ == it;
    }

    bool operator!=(const buffer_iterator<T> &it)
    {
        return ptr_ != it.ptr_;
    }

    bool operator!=(T *it)
    {
        return ptr_ != it;
    }

    friend bool operator>(const buffer_iterator<T> &it1, const buffer_iterator<T> &it2)
    {
        buffer_iterator<T> it = it1;
        int result1 = 0;
        while (it != it2)
        {
            result1++;
            it++;
        }

        it = it2;
        int result2 = 0;
        while (it != it1)
        {
            result2++;
            it++;
        }
        return result2 > result1;
    }

    friend bool operator>=(const buffer_iterator<T> &it1, const buffer_iterator<T> &it2)
    {
        return it1 > it2 || it1 == it2;
    }

    friend bool operator<(const buffer_iterator<T> &it1, const buffer_iterator<T> &it2)
    {
        return it2 > it1;
    }

private:
    buffer_element<T> *ptr_;
};

template <class T>
class circular_buffer
{
public:
    template <class V>
    friend class buffer_iterator;
    friend struct buffer_element<T>;

    typedef buffer_iterator<T> iterator;
    typedef buffer_iterator<const T> const_iterator;

    explicit circular_buffer(size_t capacity = 100)
        : capacity_(capacity)
    {
        if (capacity == 0)
            throw bufExeption();

        start_ = new buffer_element<T>();
        end_ = start_;
        buffer_element<T> *cur = start_;

        for (size_t i = 1; i < capacity; i++)
        {
            cur->next = new buffer_element<T>();
            cur->next->prev = cur;
            cur = cur->next;
        }

        cur->next = new buffer_element<T>;
        cur->next->is_end = true;
        cur->next->next = start_;
        cur->next->prev = cur;
        start_->prev = cur->next;
    }

    circular_buffer(const circular_buffer<T> &other)
        : capacity_(other.capacity_)
    {
        start_ = new buffer_element<T>();

        buffer_element<T> *cur = start_;
        buffer_element<T> *other_cur = other.start_;

        bool content_end = other.end_ == other.start_;

        for (int i = 0; i < capacity_; i++)
        {
            if (!content_end)
                cur->value = other_cur->value;

            if (other_cur == other.end_)
            {
                end_ = cur;
                content_end = true;
            }
            cur->value = other_cur->value;

            cur->next = new buffer_element<T>();
            cur->next->prev = cur;

            cur = cur->next;
            other_cur = other_cur->next;
        }

        cur->next = new buffer_element<T>();
        cur->is_end = true;
        cur->next->prev = cur;
        cur->next->next = start_;
    }

    ~circular_buffer()
    {
        buffer_element<T> *cur = start_->next;
        while (cur != start_)
        {
            buffer_element<T> *next = cur->next;
            delete cur;
            cur = next;
        }
        delete start_;
    }

    void push_back(T value)
    {
        if (end_->is_end)
        {
            start_ = start_->next;
            end_->is_end = false;
            end_->next->is_end = true;
        }

        end_ = end_->next;
        end_->prev->value = value;
    }

    T pop_back()
    {
        if (end_ == start_)
            throw bufExeption();

        end_ = end_->prev;

        return end_->value;
    }

    void push_front(T value)
    {
        if (end_ == start_)
        {
            end_ = start_->next;
            start_->value = value;
            return;
        }
        else if (start_->prev == end_)
        {
            end_->is_end = false;
            end_ = end_->prev;
            end_->is_end = true;
        }

        start_->prev->is_end = false;
        start_->prev->prev->is_end = true;
        start_->prev->value = value;
        start_ = start_->prev;
    }

    T pop_front()
    {
        if (end_ == start_)
            throw bufExeption();

        T value = start_->value;

        start_->prev->is_end = false;
        start_ = start_->next;
        start_->prev->is_end = true;

        return value;
    }

    T &front()
    {
        if (end_ == nullptr)
            throw indexExeption();
        return start_->value;
    }

    T &back()
    {
        return end_->prev->value;
    }

    int size()
    {
        if (end_ == nullptr)
            return 0;
        buffer_element<T> *cur = start_;
        int size = 0;
        while (cur != end_)
        {
            size++;
            cur = cur->next;
        }
        return size;
    }

    unsigned capacity()
    {
        return capacity_;
    }

    T &operator[](unsigned idx) const
    {
        if (idx > capacity_ || end_ == nullptr)
            throw indexExeption();

        buffer_element<T> *cur = start_;
        for (int i = 0; i < idx; i++)
        {
            if (cur == end_)
                throw indexExeption();
            cur = cur->next;
        }
        if (cur == end_)
            throw indexExeption();

        return cur->value;
    };

    void resize(unsigned new_capacity)
    {
        if (new_capacity == 0)
        {
            throw bufExeption();
        }
        else if (new_capacity < capacity_)
        {
            for (int cur_capacity = capacity_; cur_capacity > new_capacity; cur_capacity--)
            {
                start_->prev->prev->prev->next = start_->prev;
                buffer_element<T> *del_el = start_->prev->prev;
                if (del_el == end_)
                    end_ = start_->prev;
                start_->prev->prev = start_->prev->prev->prev;
                delete del_el;
            }
        }
        else
        {
            for (int cur_capacity = capacity_; cur_capacity < new_capacity; cur_capacity++)
            {
                start_->prev->prev->next = new buffer_element<T>();
                start_->prev->prev->next->prev = start_->prev->prev;
                start_->prev->prev->next->next = start_->prev;
                start_->prev->prev = start_->prev->prev->next;
                if (start_->prev == end_)
                    end_ = start_->prev->prev;
            }
        }
        capacity_ = new_capacity;
    }

    iterator begin()
    {
        return iterator(start_);
    }

    iterator end()
    {
        return iterator(end_);
    }

    const_iterator begin() const
    {
        return const_iterator(start_);
    }

    const_iterator end() const
    {
        return const_iterator(end_);
    }

private:
    unsigned capacity_;

    buffer_element<T> *start_;
    buffer_element<T> *end_;
};

int main()
{
    unsigned capacity, cur_size;
    cin >> capacity >> cur_size;
    circular_buffer<int> buffer(capacity);

    for (size_t i = 0; i < cur_size; i++)
    {
        int value;
        cin >> value;
        buffer.push_back(value);
    }

    for (auto item : buffer)
    {
        cout << item << ' ';
    }
    cout << endl;

    buffer.push_back(6);
    for (auto item : buffer)
    {
        cout << item << ' ';
    }
    cout << endl;

    buffer.pop_back();
    for (auto item : buffer)
    {
        cout << item << ' ';
    }
    cout << endl;

    buffer.push_front(5);
    for (auto item : buffer)
    {
        cout << item << ' ';
    }
    cout << endl;

    buffer.pop_front();
    for (auto item : buffer)
    {
        cout << item << ' ';
    }
    cout << endl;

    sort(buffer.begin(), buffer.end());
    for (auto item : buffer)
    {
        cout << item << ' ';
    }
    cout << endl;

    buffer.resize(4);
    buffer.push_back(10);
    buffer.push_back(20);
    for (auto item : buffer)
    {
        cout << item << ' ';
    }
    cout << endl;

    return 0;
}