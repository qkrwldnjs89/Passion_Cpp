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
        cout << "---���ָ� ��---" << endl;
        cout << "�ܿ� ���ָ�: " << gasolinGauge << endl;
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
        cout << "---���� ��---" << endl;
        cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
        cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
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
        cout << "---�� ��---" << endl;
        cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
        cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
        cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
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