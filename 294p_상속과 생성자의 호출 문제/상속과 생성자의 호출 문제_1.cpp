#include <iostream>
using namespace std;

class Car
{
private:
    int gasolinGauge;
public:
    Car() : gasolinGauge(10) { }
    int GetGasGauge() const
    {
        return gasolinGauge;
    }
    void ShowCurrentGauge() const
    {
        cout << "---가솔린 차---" << endl;
        cout << "잔여 가솔린: " << gasolinGauge << endl;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar() : Car(), electricGauge(20) { }
    int GetElecGauge() const
    {
        return electricGauge;
    }
    void ShowCurrentGauge() const
    {
        cout << "---전기 차---" << endl;
        cout << "잔여 가솔린: " << GetGasGauge() << endl;
        cout << "잔여 전기량: " << GetElecGauge() << endl;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar() : HybridCar(), waterGauge(30) { }
    void ShowCurrentGauge() const
    {
        cout << "---물 차---" << endl;
        cout << "잔여 가솔린: " << GetGasGauge() << endl;
        cout << "잔여 전기량: " << GetElecGauge() << endl;
        cout << "잔여 워터량: " << waterGauge << endl;
    }
};

int main(void)
{
    Car car;
    car.ShowCurrentGauge();
    HybridCar hybridCar;
    hybridCar.ShowCurrentGauge();
    HybridWaterCar hybridWaterCar;
    hybridWaterCar.ShowCurrentGauge();
    return 0;
}