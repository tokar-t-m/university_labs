#ifndef SENSOR_H
#define SENSOR_H
class Sensor{
public:
    virtual ~Sensor();
    virtual float getTemperature() = 0;
};
#endif // SENSOR_H
