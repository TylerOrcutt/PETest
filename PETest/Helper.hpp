#pragma once
class Helper{
    public:
static unsigned long getTime(){
  timeval time;
gettimeofday(&time, NULL);
unsigned long m1 =  (time.tv_sec * 1000) ;
unsigned long m2 =  (time.tv_usec / 1000);
if(m2> ULONG_MAX - m1){
  std::cout<<"======OVERFLOW=====\n";
}


unsigned long millis = (time.tv_sec * 1000) + (time.tv_usec / 1000);
return millis;
}
};
