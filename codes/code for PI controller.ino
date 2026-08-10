const int ADC_PIN = 34;
const int PWM_PIN = 18;
const int PWM_FREQ = 1000;
const int PWM_CHANNEL = 0;
const int PWM_RES = 10;
const int MAX_DUTY = 1023;

float Kp = 15.0;            // Proportional Gain
float Ki = 0.5;             // Integral Gain
float dt = 0.001;           // Sampling time (1ms)
float setpoint = 5.0;
float integral = 0;
float output_voltage = 0;
int duty_cycle = 0;
const float DIVIDER_RATIO = 2.0;

void setup() {
  Serial.begin(115200);
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(PWM_PIN, PWM_CHANNEL);
  ledcWrite(PWM_CHANNEL, 0); // Start with 0% duty cycle
  analogReadResolution(12);  // 0-4095
}

void loop() {
  static uint32_t lastMillis = 0;
  
  if (millis() - lastMillis >= 1) {
    lastMillis = millis();
    
    int adcRaw = analogRead(ADC_PIN);
    float voltageAtPin = (adcRaw / 4095.0) * 3.3;
    output_voltage = voltageAtPin * DIVIDER_RATIO;
    
    float error = setpoint - output_voltage;
    float Pout = Kp * error;

    integral += error * dt;
    float Iout = Ki * integral;
    
    float control_variable = Pout + Iout;
    duty_cycle = (int)constrain(control_variable, 0, MAX_DUTY);
    ledcWrite(PWM_CHANNEL, duty_cycle);
    
    static int count = 0;
    if (count++ > 100) { // Print every 100ms
      Serial.print("V_Out: "); 
      Serial.print(output_voltage);
      Serial.print("V | Duty: "); 
      Serial.println(duty_cycle);
      count = 0;
    }
  }
}
