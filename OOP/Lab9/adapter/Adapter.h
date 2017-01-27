#ifndef ADAPTER_H
#define ADAPTER_H
#include <Sensor.h>
#include <FahrenheitSensor.h>
class Adapter: public Sensor{
public:
    Adapter(FahrenheitSensor* p);
    ~Adapter();
    float getTemperature();
private:
    FahrenheitSensor* p_fsensor;
};
#endif // ADAPTER_H
