#include<stdio.h>
#include<stdint.h>
void decodeTags(uint8_t reg){
    const char* tags[]={"SYSTEM_READY",
                        "ERROR_FLAG",
                        "COMM_ACTIVE",
                        "LOW_POWER_MODE",
                        "SENSOR_ACTIVE",
                        "DATA_AVAILABLE",
                        "RESERVED",
                        "RESERVED"};
        for(int i=0;i<8;i++){
            if(reg>>i &1){printf("%s\n",tags[i]);}
        }
}
uint8_t setBit(uint8_t reg,int pos){
    return reg|=1<<pos;
}
uint8_t clearBit(uint8_t reg,int pos){
    return reg&=~(1<<pos);
}
int checkBit(uint8_t reg,int pos){
    return (reg>>pos)&1;
}
uint8_t toggleBit(uint8_t reg,int pos){
    return reg^=1<<pos;
}
void printBinary(uint8_t reg) {
    for(int i = 7; i >= 0; i--) {
        printf("%d", (reg >> i) & 1);
    }
    printf("\n");
}
int main(){
    uint8_t reg;
    scanf("%hhu",&reg);
    printBinary(reg);
    decodeTags(reg);

}