#pragma once

#include <iostream>

using namespace std;

template < class T, class Alloc = allocator<T> > class vector{
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef pointer iterator;
        typedef const_pointer const_iterator;
        typedef reverse_iterator<const_iterator> const_reverse_iterator;
        typedef reverse_iterator<iterator> reverse_iterator;

    protected:
        iterator start;
        iterator finish;
        iterator end_of_storage;

        void insert_aux(iterator position, const T& x);
        void deallocate(){
            if (start){
                data_allocator::deallocate(start, end_of_storage - start);
            }
        }
        void fill_initialize(size_type n, const T& value){
            start = allocate_and_fill(n, value);
            finish = start + n;
            end_of_storage = finish;
        }
        iterator allocate_and_fill(size_type n, const T& x){
            iterator result = data_allocator::allocate(n);
            uninitialized_fill_n(result, n, x);
            return result;
        }
        template <class InputIterator>
        void range_initialize(InputIterator first, InputIterator last, input_iterator_tag){
            for (; first != last; ++first){
                push_back(*first);
            }
        }
        template <class ForwardIterator>
        void range_initialize(ForwardIterator first, ForwardIterator last, forward_iterator_tag){
            size_type n = 0;
            distance(first, last, n);
            start = allocate_and_copy(n, first, last);
            finish = start + n;
            end_of_storage = finish;
        }
        template <class InputIterator>
        void range_initialize(InputIterator first, InputIterator last){
            range_initialize(first, last, iterator_category(first));
        }
        void insert_aux(iterator position, const T& x){
            if (finish != end_of_storage){
                construct(finish, *(finish - 1));
                ++finish;
                T x_copy = x;
                copy_backward(position, finish - 2, finish - 1);
                *position = x_copy;
            }
            else{
                const size_type old_size = size();
                const size_type len = old_size != 0 ? 2 * old_size : 1;
                iterator new_start = data_allocator::allocate(len);
                iterator new_finish = new_start;
                try{
                    new_finish = uninitialized_copy(start, position, new_start);
                    construct(new_finish, x);
                    ++new_finish;
                    new_finish = uninitialized_copy(position, finish, new_finish);
                }
                catch (...){
                    destroy(new_start, new_finish);
                    data_allocator::deallocate(new_start, len);
                    throw;
                }
                destroy(begin(), end());
                deallocate();
                start = new_start;
                finish = new_finish;
                end_of_storage = new_start + len;
            }
        }
        template <class ForwardIterator>
        iterator allocate_and_copy(size_type n, ForwardIterator first, ForwardIterator last){
            iterator result = data_allocator::allocate(n);
            uninitialized_copy(first, last, result);
            return result;
        }
        void insert_aux(iterator position, size_type n, const T& x){
            if (n != 0){
                if (size_type(end_of_storage - finish) >= n){
                    T x_copy = x;
                    const size_type elems_after = finish - position;
                    iterator old_finish = finish;
                    if (elems_after > n){
                        uninitialized_copy(finish - n, finish, finish);
                        finish += n;
                        copy_backward(position, old_finish - n, old_finish);
                        fill(position, position + n, x_copy);
                    }
                    else{
                        uninitialized_fill_n(finish, n - elems_after, x_copy);
                        finish += n - elems_after;
                        uninitialized_copy(position, old_finish, finish);
                        finish += elems_after;
                        fill(position, old_finish, x_copy);
                    }
                }
                else{
                    const size_type old_size = size();
                    const size_type len = old_size + max(old_size, n);
                    iterator new_start = data_allocator::allocate(len);
                    iterator new_finish = new_start;
                    try{
                        new_finish = uninitialized_copy(start, position, new_start);
                        new_finish = uninitialized_fill_n(new_finish, n, x);
                        new_finish = uninitialized_copy(position, finish, new_finish);
                    }
                    catch (...){
                        destroy(new_start, new_finish);
                        data_allocator::deallocate(new_start, len);
                        throw;
                    }
                    destroy(start, finish);
                    deallocate();
                    start = new_start;
                    finish = new_finish;
                    end_of_storage = new_start + len;
                }
            }
        }
        template <class InputIterator>
        void insert_aux(iterator position, InputIterator first, InputIterator last, input_iterator_tag){
            for (; first != last; ++first){
                position = insert(position, *first);
                ++position;
            }
        }
        template <class ForwardIterator>
        void insert_aux(iterator position, ForwardIterator first, ForwardIterator last, forward_iterator_tag){
            if (first != last){
                size_type n = 0;
                distance(first, last, n);
                if (size_type(end_of_storage - finish) >= n){
                    const size_type elems_after = finish - position;
                    iterator old_finish = finish;
                    if (elems_after > n){
                        uninitialized_copy(finish - n, finish, finish);
                        finish += n;
                        copy_backward(position, old_finish - n, old_finish);
                        copy(first, last, position);
                    }
                    else{
                        ForwardIterator mid = first;
                        advance(mid, elems_after);
                        uninitialized_copy(mid, last, finish);
                        finish += n - elems_after;
                        uninitialized_copy(position, old_finish, finish);
                        finish += elems_after;
                        copy(first, mid, position);
                    }
                }
                else{
                    const size_type old_size = size();
                    const size_type len = old_size + max(old_size, n);
                    iterator new_start = data_allocator::allocate(len);
                    iterator new_finish = new_start;
                    try{
                        new_finish = uninitialized_copy(start, position, new_start);
                        new_finish = uninitialized_copy(first, last, new_finish);
                        new_finish = uninitialized_copy(position, finish, new_finish);
                    }
                    catch (...){
                        destroy(new_start, new_finish);
                        data_allocator::deallocate(new_start, len);
                        throw;
                    }
                    destroy(start, finish);
                    deallocate();
                    start = new_start;
                    finish = new_finish;
                    end_of_storage = new_start + len;
                }
            }
        }
        void deallocate(){
            if (start){
                data_allocator::deallocate(start, end_of_storage - start);
            }
        }
        void fill_initialize(size_type n, const T& value){
            start = allocate_and_fill(n, value);
            finish = start + n;
            end_of_storage = finish;
        }
        iterator allocate_and_fill(size_type n, const T& x){
            iterator result = data_allocator::allocate(n);
            uninitialized_fill_n(result, n, x);
            return result;
        }
    };
    template <class T, class Alloc>
    inline bool operator==(const vector<T, Alloc>& x, const vector<T, Alloc>& y){
        return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
    }
    template <class T, class Alloc>
    inline bool operator<(const vector<T, Alloc>& x, const vector<T, Alloc>& y){
        return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    }
    template <class T, class Alloc>
    inline bool operator!=(const vector<T, Alloc>& x, const vector<T, Alloc>& y){
        return !(x == y);
    }
    template <class T, class Alloc>
    inline bool operator>(const vector<T, Alloc>& x, const vector<T, Alloc>& y){
        return y < x;
    }
    template <class T, class Alloc>
    inline bool operator<=(const vector<T, Alloc>& x, const vector<T, Alloc>& y){
        return !(y < x);
    }
    template <class T, class Alloc>
    inline bool operator>=(const vector<T, Alloc>& x, const vector<T, Alloc>& y){
        return !(x < y);
    }
    template <class T, class Alloc>
    inline void swap(vector<T, Alloc>& x, vector<T, Alloc>& y){
        x.swap(y);
    }
    template <class T, class Alloc = alloc>
    class vector<bool>{
    public:
        typedef bool value_type;
        typedef value_type* pointer;
        typedef value_type* iterator;
        typedef value_type& reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
    private:
        typedef simple_alloc<value_type, Alloc> data_allocator;
        typedef simple_alloc<unsigned char, Alloc> bit_allocator;
        iterator start;
        iterator finish;
        iterator end_of_storage;
        static size_type buffer_size(){
            return static_cast<size_type>(sizeof(unsigned char) * 8);
        }
        static size_type bit_to_index(size_type n){
            return n / buffer_size();
        }
        static size_type bit_to_offset(size_type n){
            return n % buffer_size();
        }
        static unsigned char bit_to_mask(size_type n){
            return static_cast<unsigned char>(1 << bit_to_offset(n));
        }
        void allocate_and_fill(size_type n, const value_type& value){
            start = iterator(bit_allocator::allocate(bit_to_index(n) + 1));
            finish = start + bit_to_index(n);
            end_of_storage = finish + 1;
            uninitialized_fill(start, finish, static_cast<unsigned char>(0));
            if (value){
                for (size_type i = 0; i < bit_to_offset(n); ++i){
                    start[bit_to_index(n)] |= bit_to_mask(i);
                }
            }
        }
        void deallocate(){
            if (start){
                bit_allocator::deallocate(start, end_of_storage - start);
            }
        }
        void insert_aux(iterator position, size_type n, const value_type& x){
            if (n != 0){
                if (size_type(end_of_storage - finish) >= n){
                    const size_type elems_after = finish - position;
                    iterator old_finish = finish;
                    if (elems_after > n){
                        uninitialized_copy(finish - n, finish, finish);
                        finish += n;
                        copy_backward(position, old_finish - n, old_finish);
                        fill(position, position + n, x);
                    }
                    else{
                        uninitialized_fill_n(finish, n - elems_after, x);
                        finish += n - elems_after;
                        uninitialized_copy(position, old_finish, finish);
                        finish += elems_after;
                        fill(position, old_finish, x);
                    }
                }
                else{
                    const size_type old_size = size();
                    const size_type len = old_size + max(old_size, n);
                    iterator new_start = iterator(bit_allocator::allocate(bit_to_index(len) + 1));
                    iterator new_finish = new_start;
                    try{
                        new_finish = uninitialized_copy(start, position, new_start
                        );
                        new_finish = uninitialized_fill_n(new_finish, n, x);
                        new_finish = uninitialized_copy(position, finish, new_finish);
                    }
                    catch (...){
                        destroy(new_start, new_finish);
                        bit_allocator::deallocate(new_start, end_of_storage - start);
                        throw;
                    }
                    destroy(start, finish);
                    deallocate();
                    start = new_start;
                    finish = new_finish;
                    end_of_storage = new_start + bit_to_index(len) + 1;
                }
            }
        }
    public:
        vector(): start(0), finish(0), end_of_storage(0){}
        explicit vector(size_type n, const value_type& value = value_type()){
            allocate_and_fill(n, value);
        }
        vector(const vector& x){
            start = iterator(bit_allocator::allocate(bit_to_index(x.size()) + 1));
            finish = uninitialized_copy(x.begin(), x.end(), start);
            end_of_storage = finish;
        }
        ~vector(){
            destroy(start, finish);
            deallocate();
        }
        vector& operator=(const vector& x){
            if (&x != this){
                const size_type xlen = x.size();
                if (xlen > capacity()){
                    iterator tmp = iterator(bit_allocator::allocate(bit_to_index(xlen) + 1));
                    destroy(start, finish);
                    deallocate();
                    start = tmp;
                    end_of_storage = start + bit_to_index(xlen) + 1;
                }
                else if (size() >= xlen){
                    iterator i = copy(x.begin(), x.end(), begin());
                    destroy(i, finish);
                }
                else{
                    copy(x.begin(), x.begin() + size(), start);
                    uninitialized_copy(x.begin() + size(), x.end(), finish);
                }
                finish = start + xlen;
            }
            return *this;
        }
        void reserve(size_type n){
            if (capacity() < n){
                const size_type old_size = size();
                iterator tmp = iterator(bit_allocator::allocate(bit_to_index(n) + 1));
                uninitialized_copy(start, finish, tmp);
                destroy(start, finish);
                deallocate();
                start = tmp;
                finish = tmp + old_size;
                end_of_storage = start + bit_to_index(n) + 1;
            }
        }
        iterator begin(){
            return start;
        }
        iterator end(){
            return finish;
        }
        size_type size() const{
            return size_type(finish - start) * buffer_size() + bit_to_offset(finish - start);
        }
        size_type max_size() const{
            return size_type(-1);
        }
        void resize(size_type new_size, const value_type& x){
            if (new_size < size()){
                erase(begin() + new_size, end());
            }
            else{
                insert(end(), new_size - size(), x);
            }
        }
        size_type capacity() const{
            return size_type(end_of_storage - start) * buffer_size();
        }
        bool empty() const{
            return begin() == end();
        }
        reference operator[](size_type n){
            return reference(start[bit_to_index(n)], bit_to_mask(n));
        }
        reference front(){
            return *begin();
        }
        reference back(){
            return *(end() - 1);
        }
        void push_back(const value_type& x){
            if (finish != end_of_storage){
                *finish++ = x;
            }
            else{
                insert_aux(end(), 1, x);
            }
        }
        void swap(vector& x){
            std::swap(start, x.start);
            std::swap(finish, x.finish);
            std::swap(end_of_storage, x.end_of_storage);
        }
        iterator insert(iterator position, const value_type& x){
            const size_type n = position - begin();
            if (finish != end_of_storage && position == end()){
                *finish++ = x;
            }
            else{
                insert_aux(position, 1, x);
            }
            return begin() + n;
        }
        void insert(iterator position, size_type n, const value_type& x){
            insert_aux(position, n, x);
        }
        void pop_back(){
            --finish;
        }
        iterator erase(iterator position){
            if (position + 1 != end()){
                copy(position + 1, finish, position);
            }
            --finish;
            return position;
        }
        iterator erase(iterator first, iterator last){
            iterator i = copy(last, finish, first);
            destroy(i, finish);
            finish = finish - (last - first);
            return first;
        }
        void clear(){
            erase(begin(), end());
        }
    };
    template <class T, class Alloc>
    inline bool operator==(const vector<T, Alloc>& x, const vector<T, Alloc>& y){
        return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
    }
    template <class T, class Alloc>
    inline bool operator<(const vector<T, Alloc>& x, const vector<T, Alloc>& y){
        return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    }
    template <class T, class Alloc>
    inline void swap(vector<T, Alloc>& x, vector<T, Alloc>& y){
        x.swap(y);
    }
    template <class T, class Alloc>
    inline bool operator!=(const vector<T, Alloc>& x, const vector<T, Alloc>& y){
        return !(x == y);
    }
    template <class T, class Alloc>
    inline bool operator>(const vector<T, Alloc>& x, const vector<T, Alloc>& y){
        return y < x;
    }
    template <class T, class Alloc>
    inline bool operator<=(const vector<T, Alloc>& x, const vector<T, Alloc>& y){
        return !(y < x);
    }
    template <class T, class Alloc>
    inline bool operator>=(const vector<T, Alloc>& x, const vector<T, Alloc>& y){
        return !(x < y);
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::insert_aux(iterator position, size_type n, const value_type& x){
        if (n != 0){
            if (size_type(end_of_storage - finish) >= n){
                value_type x_copy = x;
                const size_type elems_after = finish - position;
                iterator old_finish = finish;
                if (elems_after > n){
                    uninitialized_copy(finish - n, finish, finish);
                    finish += n;
                    copy_backward(position, old_finish - n, old_finish);
                    fill(position, position + n, x_copy);
                }
                else{
                    uninitialized_fill_n(finish, n - elems_after, x_copy);
                    finish += n - elems_after;
                    uninitialized_copy(position, old_finish, finish);
                    finish += elems_after;
                    fill(position, old_finish, x_copy);
                }
            }
            else{
                const size_type old_size = size();
                const size_type len = old_size + max(old_size, n);
                iterator new_start = iterator(bit_allocator::allocate(bit_to_index(len) + 1));
                iterator new_finish = new_start;
                try{
                    new_finish = uninitialized_copy(start, position, new_start);
                    new_finish = uninitialized_fill_n(new_finish, n, x);
                    new_finish = uninitialized_copy(position, finish, new_finish);
                }
                catch(...){
                    destroy(new_start, new_finish);
                    bit_allocator::deallocate(new_start, bit_to_index(len) + 1);
                    throw;
                }
                destroy(start, finish);
                deallocate();
                start = new_start;
                finish = new_finish;
                end_of_storage = new_start + bit_to_index(len) + 1;
            }
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::deallocate(){
        if (start){
            bit_allocator::deallocate(start, end_of_storage - start);
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::fill_initialize(size_type n, const value_type& value){
        start = iterator(bit_allocator::allocate(bit_to_index(n) + 1));
        end_of_storage = start + bit_to_index(n) + 1;
        finish = uninitialized_fill_n(start, n, value);
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::insert(iterator position, const_iterator first, const_iterator last){
        if (first != last){
            size_type n = 0;
            distance(first, last, n);
            if (size_type(end_of_storage - finish) >= n){
                const size_type elems_after = finish - position;
                iterator old_finish = finish;
                if (elems_after > n){
                    uninitialized_copy(finish - n, finish, finish);
                    finish += n;
                    copy_backward(position, old_finish - n, old_finish);
                    copy(first, last, position);
                }
                else{
                    uninitialized_copy(first + elems_after, last, finish);
                    finish += n - elems_after;
                    uninitialized_copy(position, old_finish, finish);
                    finish += elems_after;
                    copy(first, first + elems_after, position);
                }
            }
            else{
                const size_type old_size = size();
                const size_type len = old_size + max(old_size, n);
                iterator new_start = iterator(bit_allocator::allocate(bit_to_index(len) + 1));
                iterator new_finish = new_start;
                try{
                    new_finish = uninitialized_copy(start, position, new_start);
                    new_finish = uninitialized_copy(first, last, new_finish);
                    new_finish = uninitialized_copy(position, finish, new_finish);
                }
                catch(...){
                    destroy(new_start, new_finish);
                    bit_allocator::deallocate(new_start, bit_to_index(len) + 1);
                    throw;
                }
                destroy(start, finish);
                deallocate();
                start = new_start;
                finish = new_finish;
                end_of_storage = new_start + bit_to_index(len) + 1;
            }
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::insert(iterator position, size_type n, const value_type& x){
        if (n != 0){
            if (size_type(end_of_storage - finish) >= n){
                const size_type elems_after = finish - position;
                iterator old_finish = finish;
                if (elems_after > n){
                    uninitialized_copy(finish - n, finish, finish);
                    finish += n;
                    copy_backward(position, old_finish - n, old_finish);
                    fill(position, position + n, x);
                }
                else{
                    uninitialized_fill_n(finish, n - elems_after, x);
                    finish += n - elems_after;
                    uninitialized_copy(position, old_finish, finish);
                    finish += elems_after;
                    fill(position, old_finish, x);
                }
            }
            else{
                const size_type old_size = size();
                const size_type len = old_size + max(old_size, n);
                iterator new_start = iterator(bit_allocator::allocate(bit_to_index(len) + 1));
                iterator new_finish = new_start;
                try{
                    new_finish = uninitialized_copy(start, position, new_start);
                    new_finish = uninitialized_fill_n(new_finish, n, x);
                    new_finish = uninitialized_copy(position, finish, new_finish);
                }
                catch(...){
                    destroy(new_start, new_finish);
                    bit_allocator::deallocate(new_start, bit_to_index(len) + 1);
                    throw;
                }
                destroy(start, finish);
                deallocate();
                start = new_start;
                finish = new_finish;
                end_of_storage = new_start + bit_to_index(len) + 1;
            }
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::pop_back(){
        --finish;
        destroy(finish);
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::push_back(const value_type& x){
        if (finish != end_of_storage){
            construct(finish, x);
            ++finish;
        }
        else{
            insert_aux(end(), x);
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::reserve(size_type n){
        if (capacity() < n){
            const size_type old_size = size();
            iterator tmp = iterator(bit_allocator::allocate(bit_to_index(n) + 1));
            try{
                uninitialized_copy(start, finish, tmp);
                destroy(start, finish);
                deallocate();
            }
            catch(...){
                bit_allocator::deallocate(tmp, bit_to_index(n) + 1);
                throw;
            }
            start = tmp;
            finish = tmp + old_size;
            end_of_storage = start + bit_to_index(n) + 1;
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::resize(size_type new_size, const value_type& x){
        if (new_size < size()){
            erase(start + new_size, finish);
        }
        else{
            insert(end(), new_size - size(), x);
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::swap(vector<T, Alloc>& x){
        std::swap(start, x.start);
        std::swap(finish, x.finish);
        std::swap(end_of_storage, x.end_of_storage);
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::deallocate(){
        if (start){
            bit_allocator::deallocate(start, bit_to_index(end_of_storage - start));
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::insert_aux(iterator position, const value_type& x){
        if (finish != end_of_storage){
            construct(finish, *(finish - 1));
            ++finish;
            value_type x_copy = x;
            copy_backward(position, finish - 2, finish - 1);
            *position = x_copy;
        }
        else{
            const size_type old_size = size();
            const size_type len = old_size != 0 ? 2 * old_size : 1;
            iterator new_start = iterator(bit_allocator::allocate(bit_to_index(len) + 1));
            iterator new_finish = new_start;
            try{
                new_finish = uninitialized_copy(start, position, new_start);
                construct(new_finish, x);
                ++new_finish;
                new_finish = uninitialized_copy(position, finish, new_finish);
            }
            catch(...){
                destroy(new_start, new_finish);
                bit_allocator::deallocate(new_start, bit_to_index(len) + 1);
                throw;
            }
            destroy(start, finish);
            deallocate();
            start = new_start;
            finish = new_finish;
            end_of_storage = new_start + bit_to_index(len) + 1;
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::insert_aux(iterator position){
        if (finish != end_of_storage){
            construct(finish, *(finish - 1));
            ++finish;
            copy_backward(position, finish - 2, finish - 1);
            *position = value_type();
        }
        else{
            const size_type old_size = size();
            const size_type len = old_size != 0 ? 2 * old_size : 1;
            iterator new_start = iterator(bit_allocator::allocate(bit_to_index(len) + 1));
            iterator new_finish = new_start;
            try{
                new_finish = uninitialized_copy(start, position, new_start);
                construct(new_finish);
                ++new_finish;
                new_finish = uninitialized_copy(position, finish, new_finish);
            }
            catch(...){
                destroy(new_start, new_finish);
                bit_allocator::deallocate(new_start, bit_to_index(len) + 1);
                throw;
            }
            destroy(start, finish);
            deallocate();
            start = new_start;
            finish = new_finish;
            end_of_storage = new_start + bit_to_index(len) + 1;
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::range_check(size_type n) const{
        if (n >= size()){
            throw std::out_of_range("vector");
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::reverse(iterator first, iterator last){
        while ((first != last) && (first != --last)){
            std::swap(*first++, *last);
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::reverse(iterator first, iterator last, size_type n){
        while (n > 0){
            std::swap(*first++, *last);
            --n;
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::reverse(iterator first, iterator middle1, iterator middle2, iterator last){
        reverse(first, middle1);
        reverse(middle1, middle2);
        reverse(middle2, last);
        reverse(first, last);
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::reverse(iterator first, iterator middle1, iterator middle2, iterator last, size_type n1, size_type n2){
        reverse(first, middle1, n1);
        reverse(middle1, middle2, n2);
        reverse(middle2, last, n1);
        reverse(first, last, n1 + n2);
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::rotate(iterator first, iterator middle, iterator last){
        if (first == middle){
            return;
        }
        if (middle == last){
            return;
        }
        iterator next = middle;
        do{
            std::swap(*first++, *next++);
            if (first == middle){
                middle = next;
            }
        } while (next != last);
        next = middle;
        while (next != last){
            std::swap(*first++, *next++);
            if (first == middle){
                middle = next;
            }
            else if (next == last){
                next = middle;
            }
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::rotate(iterator first, iterator middle, iterator last, size_type n, size_type len){
        if (n == 0){
            return;
        }
        if (n == len){
            return;
        }
        iterator next = middle;
        do{
            std::swap(*first++, *next++);
            if (--n == 0){
                middle = next;
            }
        } while (next != last);
        next = middle;
        while (next != last){
            std::swap(*first++, *next++);
            if (--n == 0){
                middle = next;
            }
            else if (next == last){
                next = middle;
            }
        }
    }
    template <class T, class Alloc>
    inline void vector<T, Alloc>::rotate(iterator first, iterator middle1, iterator middle2, iterator last){
        reverse(first, middle1);
        reverse(middle1, middle2);
        reverse(middle2, last);
        reverse(first, last);
    }
    