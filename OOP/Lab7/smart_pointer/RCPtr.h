/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab7(Smart_Pointer)
 * Standard: C++0x
*/
#ifndef RCPTR_H
#define RCPTR_H
template<class T>
class RCPtr{
public:
    RCPtr(T* realPtr = 0);
    RCPtr(const RCPtr& rhs);
    ~RCPtr();
    RCPtr& operator= (const RCPtr& rhs);
    T* operator-> () const;
    T& operator* () const;
private:
    T *pointee;
    void init();
};

                                    /* Реазизация шаблонов методов RCPtr */

template<class T>
void RCPtr<T>::init(){
    if (pointee == 0)
        return;
    if (pointee->isShareable() == false)
        pointee = new T(*pointee);
    pointee->addReference();
}

template<class T>
RCPtr<T>::RCPtr(T* realPtr) : pointee(realPtr){
    init();
}

template<class T>
RCPtr<T>::RCPtr(const RCPtr& rhs) : pointee(rhs.pointee){
    init();
}

template<class T>
RCPtr<T>::~RCPtr(){
    if (pointee)
        pointee->removeReference();
}

template<class T>
RCPtr<T>& RCPtr<T>::operator= (const RCPtr& rhs){
    if (pointee != rhs.pointee){
        T *oldPointee = pointee;
        pointee = rhs.pointee;
        init();
        if (oldPointee)
            oldPointee->removeReference();
    }
    return *this;
}

template<class T>
T* RCPtr<T>::operator ->() const{
    return pointee;
}

template<class T>
T& RCPtr<T>::operator *() const{
    return *pointee;
}
#endif // RCPTR_H
