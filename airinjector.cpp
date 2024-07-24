#include "airinjector.h"

airinjector::airinjector()
{
    hhandler = new hwHandler;
    vac = new Vaccum;

}

int airinjector::aivalue(int p)
{
    int preset;
    int actual;

    preset = p;
    if (preset == NULL)
       std::cout<<"useage airingector PRESET";
    int flow=90+ (int)(preset* 1.5);
    hhandler->write_motor(0x01,0x03,flow);

    actual=0;
    for(int i=0; i<10; i++)
    {
        actual += vac->convert(CHANNEL_2) * 0.1894;
    }
    actual = static_cast<int>(actual/10);
    std::cout << actual <<" "<< preset << std::endl;

    hhandler->ai_on();
    hhandler->ai_preset_count(preset);
    hhandler->ai_actual_count(actual);

    return actual;
    //emit aisignal(actual);

}

//void airinjector::aivalue2(int a)
//{
//    emit aisignal(a);
//}
