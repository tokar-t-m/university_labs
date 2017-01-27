/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab7(Smart_Pointer)
 * Standard: C++0x
*/
#include <RCObject.h>
#include <iostream>
using std::cout;
using std::endl;

RCObject::RCObject() : refCount(0), shareable(true){

}

RCObject::RCObject(const RCObject&) : refCount(0), shareable(true){

}

RCObject& RCObject::operator= (const RCObject&){
    return *this;
}

RCObject::~RCObject(){

}

void RCObject::addReference(){
    ++refCount;
}

void RCObject::removeReference(){
    if(--refCount == 0)
        delete this;
}

void RCObject::markUnshareable(){
    shareable = false;
}

bool RCObject::isShareable() const{
    return shareable;
}

bool RCObject::isShared() const{
    return refCount > 1;
}

int RCObject::showRefCount() const{
    return refCount;
}
