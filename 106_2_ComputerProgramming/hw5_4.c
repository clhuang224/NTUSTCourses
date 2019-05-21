#include <stdio.h>
typedef struct{
	double voltage; //(V)
	double max_energy; //(J)
	double current_energy; //(J)
}battery_t;

int power_device(double current,double time, battery_t *bat);
double max_time(battery_t bat, double current);
void recharge(battery_t *bat);

int main(){
	battery_t battery; //宣告電池
	battery.voltage = 12;
	battery.max_energy = 5000000;
	battery.current_energy = battery.max_energy;
	
	printf("=New battery=\nVoltage: %.2fV\nMax energy: %.2fJ\nCurrent energy: %.2fJ\n\n", battery.voltage, battery.max_energy, battery.current_energy); //印出電池現況
	
	printf(">>Use the battery to power a 4-A light for 15 minutes......\n\n");
	power_device(4, 15*60, &battery); //使用4A的設備15分鐘
	
	printf("Remaining energy time for 8A device: %.2f seconds\n\n", max_time(battery, 8)); //印出還可以用8A的設備多久
	
	printf(">>Recharge the battery...\n\n");
	recharge(&battery); //充電
	
	printf("Remaining energy time for 8A device: %.2f seconds\n", max_time(battery, 8)); //印出還可以用8A的設備多久
}

int power_device(double current,double time, battery_t *bat){ //使用電池
	double usage = current * time * bat->voltage; //宣告總用電量

	if(bat->current_energy >= usage){ //電池夠用的話，把用量扣掉，return 1
		bat->current_energy -= usage;
		return 1;
	} else { //不夠的話 return 0
		return 0;
	}
}

double max_time(battery_t bat, double current){ //計算在某電流下，電池還能用多久
	return (bat.current_energy / bat.voltage / current); // t = E / IV
}

void recharge(battery_t *bat){ //充電
	bat->current_energy = bat->max_energy; //現有能量=最大能量
}