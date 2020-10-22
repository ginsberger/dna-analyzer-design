
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
    typedef std::string (T::*MemFuncP) (const std::string&, std::vector<std::string>&) const;
    CallBack(T & instance, MemFuncP instanceMemberFunc) : m_instance(instance), m_instanceMemberFunc(instanceMemberFunc) {}
    std::string operator()(const std::string& string, std::vector<std::string>& vector) const {return (m_instance.*m_instanceMemberFunc)(string, vector);}

private:
    T& m_instance;
    const MemFuncP m_instanceMemberFunc;
};

//the first argument 'instance' is not const to enable call non const functions
template <typename T>
inline CallBack<T> makeCallBack(T& instance, typename CallBack<T>::MemFuncP instanceMemberFunc)
{
    return CallBack<T>(instance, instanceMemberFunc);
}

#endif //DNA_ANALYZER_DESIGN_CALLBACK_H
