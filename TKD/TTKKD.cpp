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
  {DPID_SWITCH7, DP_TYPE_BOOL}, //前一个填入DP点ID，后一个为DP点的数据类型
};

void setup(){
    my_device.set_dp_cmd_total(dp_array, 7);
}