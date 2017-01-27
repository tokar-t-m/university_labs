/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab7(Smart_Pointer)
 * Standard: C++0x
*/
#ifndef RCOBJECT_H
#define RCOBJECT_H
class RCObject{
public:
    void addReference();
    void removeReference();
    void markUnshareable();
    bool isShareable() const;
    bool isShared() const;
    int showRefCount() const;
protected:
    RCObject();
    RCObject (const RCObject& rhs);
    RCObject& operator= (const RCObject& rhs);
    virtual ~RCObject() = 0;
private:
    int refCount;
    bool shareable;
};

#endif // RCOBJECT_H
