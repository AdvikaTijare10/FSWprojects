#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
void setBit(uint8_t *reg,int pos){
    *reg|=(1<<pos);
}
void decodeFlags(uint8_t reg){
const char* flags[]={"TEMP_HIGH",
 "BATTERY_LOW",
 "SENSOR_FAIL",
 "COMM_LOSS",
 "ORIENTATION_ERROR",
 "DATA_OVERFLOW",
 "SYSTEM_OK",
 "RESERVED"};
 for(int i=0;i<8;i++){
    
    if(reg&(1<<i))printf("%s\n",flags[i]);}
    if( !(reg&(1<<1)) )printf("SYSTEM_NOT_OK\n");
 
}
void printReg(uint8_t reg){
    for(int i=7;i>=0;i--){
        printf("%d",(reg>>i)&1);
    }
}
int main(){

float temp;
float battery;
int sensor_status;
int comm_status;
float orientation_error;
int buffer_level;
uint8_t reg=0;
    temp = rand() % 100; //0-100
    battery = rand() % 100; //0-100
    sensor_status = rand() % 2; //0-1
    comm_status = rand() % 2; //0-1
    orientation_error = rand() % 10; //0-10
    buffer_level = rand() % 100; //0-100
if(temp > 70) setBit(&reg, 0);
if(battery < 20) setBit(&reg, 1);
if(sensor_status == 0) setBit(&reg, 2);
if(comm_status == 0) setBit(&reg, 3);
if(orientation_error > 5) setBit(&reg, 4);
if(buffer_level > 80) setBit(&reg, 5);
if(reg==0)setBit(&reg,6); // if reg==0 means all flag bits are off meaning no fault, thus system ok
printReg(reg);
printf("\n");
decodeFlags(reg);

}