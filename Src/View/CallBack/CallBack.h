
#ifndef DNA_ANALYZER_DESIGN_CALLBACK_H
#define DNA_ANALYZER_DESIGN_CALLBACK_H

#include <iostream>
#include <vector>

class CallBackBase{
public:
    virtual std::string operator()(const std::string&, std::vector<std::string>&) const =0;
    virtual ~CallBackBase() {};
};

template <typename T>
class CallBack : public CallBackBase{
public:
    typedef std::string (T::*F) (const std::string&, std::vector<std::string>&) const;
    CallBack(T & t, F f) : m_t(&t), m_f(f) {}
    std::string operator()(const std::string& string, std::vector<std::string>& vector) const {return (m_t->*m_f)(string, vector);}

private:
    T* m_t;
    F m_f;
};


template <typename T>
inline CallBack<T> makeCallBack(T& t, typename CallBack<T>::F f)
{
    return CallBack<T>(t, f);
}

#endif //DNA_ANALYZER_DESIGN_CALLBACK_H
