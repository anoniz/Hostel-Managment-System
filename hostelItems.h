#include<iostream>
using namespace std;

class HostelItems {
    unsigned washRooms,kitchens,waterColors,wifiRouters;
    public:
    void setAll();
    void setWaterColors(unsigned);
    void setWifiRouters(unsigned);
    void showAll();
};
// HostelItems Member Functions....
void HostelItems::setAll() {
    cout<<"Hit Enter......\n";
    cin.ignore();
    cin.clear();
    cout<<"Enter How Many WaterColors Are There? = ";
    cin>>waterColors;
    cout<<"Enter How Many WashRooms Are There? = ";
    cin>>washRooms;
    cout<<"Enter How Many Kitchens Are There? = ";
    cin>>kitchens;
    cout<<"Enter How Many Wifi Routers Are Installed? = ";
    cin>>wifiRouters;
}

void HostelItems::setWaterColors(unsigned w) { waterColors = w;}
void HostelItems::setWifiRouters(unsigned w) { wifiRouters = w;}
void HostelItems::showAll() {
    cout<<"Total WaterColors Are = "<<waterColors<<endl;
    cout<<"Total WashRooms Are = "<<washRooms<<endl;
    cout<<"Total Kitches Are = "<<kitchens<<endl;
    cout<<"Totol Wifi Routers Are = "<<wifiRouters<<endl;
}