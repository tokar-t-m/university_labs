#include <iostream>
#include <Sensor.h>
#include <Adapter.h>

using namespace std;

int main()
{
    Sensor* p = new Adapter(new FahrenheitSensor);
    cout << "Celsius temperature = " << p->getTemperature() << endl;
    delete p;
    return 0;
}

