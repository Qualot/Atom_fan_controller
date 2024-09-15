#include <M5Unified.h>
#include <FastLED.h>
#include <ros.h>
#include <std_msgs/Bool.h>


// RGB LEDの数を指定(M5Atom Matrixなら25)
#define NUM_LEDS 1
// RGB LEDのDATA PINを指定
#define LED_DATA_PIN 27
#define GPIO_PIN 25  // GPIO 25番ピン

CRGB leds[NUM_LEDS];  // LEDの定義

ros::NodeHandle nh;  // ROSノードハンドル

void messageCb( const std_msgs::Bool& toggle_msg){
  //digitalWrite(GPIO_PIN, HIGH-digitalRead(GPIO_PIN));   // blink the led
  digitalWrite(GPIO_PIN, toggle_msg.data);   // blink the led

  if (toggle_msg.data) {
    leds[0] = CRGB::Green;      // LEDを赤に設定
  } else {
    leds[0] = CRGB::Black;    // LEDを消灯
  }
  FastLED.show();  // LED状態を反映
}

ros::Subscriber<std_msgs::Bool> sub("toggle_fan", &messageCb );

void setup()
{
  auto cfg = M5.config();
  M5.begin(cfg);
  FastLED.addLeds<WS2811, LED_DATA_PIN, GRB>(leds, NUM_LEDS);  // LED初期設定
  FastLED.setBrightness(20);  // 明るさを設定

  pinMode(GPIO_PIN, OUTPUT);
  digitalWrite(GPIO_PIN, LOW);   // blink the led
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}