/* Array.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 05/31/2015
 * Last Modified    : 05/31/2015
 * 
 */

#pragma once
#ifndef ymp_ExportSafeLibs_Array_H
#define ymp_ExportSafeLibs_Array_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
namespace ymp{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
template <typename type>
static void local_arr_deleter(type* ptr){
    delete[] ptr;
}
////////////////////////////////////////////////////////////////////////////////
template <typename type>
class dll_uarr{
    type* m_ptr;
    void (*m_deleter)(type*);

public:
    //  Rule of 5
    dll_uarr(const dll_uarr&) = delete;
    void operator=(const dll_uarr&) = delete;
    dll_uarr(dll_uarr&& x)
        : m_ptr(x.m_ptr)
        , m_deleter(x.m_deleter)
    {
        x.m_ptr = nullptr;
    }
    void operator=(dll_uarr&& x){
        clear();
        m_ptr = x.m_ptr;
        m_deleter = x.m_deleter;
        x.m_ptr = nullptr;
    }
    ~dll_uarr(){ clear(); }

public:
    //  Constructors
    dll_uarr() : m_ptr(nullptr) {}
    dll_uarr(type* ptr, void (*deleter)(type*) = &local_arr_deleter)
        : m_ptr(ptr)
        , m_deleter(deleter)
    {}
    void clear(){
        if (m_ptr != nullptr){
            m_deleter(m_ptr);
        }
    }

public:
    //  Getters
    type* get(){
        return m_ptr;
    }
    const type* get() const{
        return m_ptr;
    }
    type& operator[](size_t index){
        return m_ptr[index];
    }
    const type& operator[](size_t index) const{
        return m_ptr[index];
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
