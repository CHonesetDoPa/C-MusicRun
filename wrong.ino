
#include <TuyaWifi.h>

TuyaWifi my_device;

#define DPID_SWITCH1 101
#define DPID_SWITCH2 102
#define DPID_SWITCH3 103
#define DPID_SWITCH4 104
#define DPID_SWITCH5 105
#define DPID_SWITCH6 106
#define DPID_SWITCH7 107

unsigned char dp_array[][2] =
{
  {DPID_SWITCH1, DP_TYPE_BOOL},
  {DPID_SWITCH2, DP_TYPE_BOOL},
  {DPID_SWITCH3, DP_TYPE_BOOL},
  {DPID_SWITCH4, DP_TYPE_BOOL},
  {DPID_SWITCH5, DP_TYPE_BOOL},
  {DPID_SWITCH6, DP_TYPE_BOOL},
  {DPID_SWITCH7, DP_TYPE_BOOL},
};

unsigned char dp_bool_value = 0;
unsigned long last_time = 0;
unsigned char run = 0;
unsigned char dp_process(unsigned char dpid,const unsigned char value[], unsigned short length)
{
  switch (dpid) {
   case DPID_SWITCH1:
    bool mem1 = my_device.mcu_get_dp_download_data(dpid, value, length);
    my_device.mcu_dp_update(DPID_SWITCH1, dp_bool_value, 1);
    break;
   case DPID_SWITCH2:
    bool mem2 = my_device.mcu_get_dp_download_data(dpid, value, length);
    my_device.mcu_dp_update(DPID_SWITCH2, dp_bool_value, 1);
    break;
   case DPID_SWITCH3:
    bool mem3 = my_device.mcu_get_dp_download_data(dpid, value, length);
    my_device.mcu_dp_update(DPID_SWITCH3, dp_bool_value, 1);
    break;
   case DPID_SWITCH4:
    bool mem4 = my_device.mcu_get_dp_download_data(dpid, value, length);
    my_device.mcu_dp_update(DPID_SWITCH4, dp_bool_value, 1);
    break;
   case DPID_SWITCH5:
    bool mem5 = my_device.mcu_get_dp_download_data(dpid, value, length);
    my_device.mcu_dp_update(DPID_SWITCH5, dp_bool_value, 1);
    break;
   case DPID_SWITCH6:
    bool mem6 = my_device.mcu_get_dp_download_data(dpid, value, length);
    my_device.mcu_dp_update(DPID_SWITCH6, dp_bool_value, 1);
    break;
   case DPID_SWITCH7:
    bool mem7 = my_device.mcu_get_dp_download_data(dpid, value, length);
    my_device.mcu_dp_update(DPID_SWITCH7, dp_bool_value, 1);
    break;
    default:break;
}

  return SUCCESS;
}

void music_test(){
    noTone(5);
    digitalWrite(3,HIGH);
    delay(1000);
}

void setup(){
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  pinMode(7, INPUT_PULLUP);
  my_device.init("rtoqxyuwhnpr3aya", "1.0.0");
  my_device.set_dp_cmd_total(dp_array, 7);
  my_device.dp_process_func_register(dp_process);
  my_device.dp_update_all_func_register(dp_update_all);
  last_time = millis();
}

void loop(){


  if (digitalRead(7) == LOW) {
    delay(80);
    if (digitalRead(7) == LOW) {
      my_device.mcu_set_wifi_mode(SMART_CONFIG);

    }

  }
  my_device.uart_service();
  if ((digitalRead(13) == LOW && digitalRead(6) == LOW) && (digitalRead(12) == LOW && digitalRead(8) == LOW)) {
    music_test();

  } else if (digitalRead(13) == LOW) {
    tone(5,532);
    digitalWrite(3,HIGH);
  } else if (digitalRead(12) == LOW) {
    tone(5,587);
    digitalWrite(3,HIGH);
  } else if (digitalRead(11) == LOW) {
    tone(5,659);
    digitalWrite(3,HIGH);
  } else if (digitalRead(10) == LOW) {
    tone(5,698);
    digitalWrite(3,HIGH);
  } else if (digitalRead(9) == LOW) {
    tone(5,784);
    digitalWrite(3,HIGH);
  } else if (digitalRead(8) == LOW) {
    tone(5,880);
    digitalWrite(3,HIGH);
  } else if (digitalRead(6) == LOW) {
    tone(5,988);
    digitalWrite(3,HIGH);
  } else {
    noTone(5);
    digitalWrite(3,LOW);

  }

}
void dp_update_all(void)
{
  my_device.mcu_dp_update(DPID_SWITCH1, mem1, 1);
  my_device.mcu_dp_update(DPID_SWITCH2, mem2, 1);
  my_device.mcu_dp_update(DPID_SWITCH3, mem3, 1);
  my_device.mcu_dp_update(DPID_SWITCH4, mem4, 1);
  my_device.mcu_dp_update(DPID_SWITCH5, mem5, 1);
  my_device.mcu_dp_update(DPID_SWITCH6, mem6, 1);
  my_device.mcu_dp_update(DPID_SWITCH7, mem7, 1);
}