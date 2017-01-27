#include <Adapter.h>

Adapter::Adapter(FahrenheitSensor *p): p_fsensor(p){
}

Adapter::~Adapter(){
    delete p_fsensor;
}

float Adapter::getTemperature(){
    return (p_fsensor->getFahrenheitTemp()-32.0)*5.0/9.0;
}
