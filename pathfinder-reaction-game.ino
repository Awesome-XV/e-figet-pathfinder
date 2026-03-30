// Quick Map of the pins for refrence
// D0 = Led 7 (Most right)
// D9 = Led 4
// D3 = Led 1
// D2 = Led 2 (Center)
// D7 = Led 3
// D8 = Led 5
// D1 = Led 6 (Most Left)

// D6 = Switch 1 (clutch)
// D5 = Switch 2 (TBD)
// D4 = Switch 3(accelerate)
// D10 = Switch 4 (Start)

const int LED_COUNT = 7;
const int LEDS[7] = { D0, D1, D9, D2, D3, D8, D7 };
const int BTN_CLUTCH = D6;
const int BTN_ACCELERATE = D4;
const int BTN_START = D5;

const int STEP = 800;
const int MIN_HOLD = 500;
const int MAX_HOLD = 7000;
const int TIMEOUT = 5000;

void allOn() {
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LEDS[i], HIGH);
  }
}

void allOff() {
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LEDS[i], LOW);
  }
}

void keyPress(int pin) {
  while (digitalRead(pin) == HIGH) {
    delay(5);
  }
}

void keyRelease(int pin) {
  while (digitalRead(pin) == LOW) {
    delay(5);
  }
}

void falseStart() {
  allOff();
}

bool checkFalseStart() {
  if (digitalRead(BTN_ACCELERATE) == LOW) {
    falseStart();
    return true;
  }

  if (digitalRead(BTN_CLUTCH) == HIGH) {
    falseStart();
    return true;
  }

  return false;
}

void showResult(long reactionTime) {
  char digits[8];
  sprintf(digits, "%07ld", reactionTime);
  for (int i = 0; i < 7; i++) {
    int count = digits[i] - '0';

    if (count == 0) continue;
    for (int x = 0; x < count; x++) {
      digitalWrite(LEDS[i], HIGH);
      delay(250);
      digitalWrite(LEDS[i], LOW);
      delay(200);
    }

    delay(500);
  }
}

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(LEDS[i], OUTPUT);
    digitalWrite(LEDS[i], LOW);
  }

  pinMode(BTN_START, INPUT_PULLUP);
  pinMode(BTN_CLUTCH, INPUT_PULLUP);
  pinMode(BTN_ACCELERATE, INPUT_PULLUP);

  randomSeed(analogRead(A3));
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LEDS[i], HIGH);
    delay(80);
  }

  delay(300);
  allOff();
}

void loop() {
  while (digitalRead(BTN_START) == HIGH || digitalRead(BTN_CLUTCH) == HIGH) {
    delay(5);
  }

  keyRelease(BTN_START);
  delay(500);

  int seqL[4] = {0, 1, 2, 3};
  int seqR[4] = {6, 5, 4, 3};

  for (int step = 0; step < 3; step++) {
    digitalWrite(LEDS[seqL[step]], HIGH);
    digitalWrite(LEDS[seqR[step]], HIGH);
    delay(STEP);
    if (checkFalseStart()) {
      return;
    }
  }

  digitalWrite(LEDS[3], HIGH);
  
  if (checkFalseStart()) {
    return;
  }

  long holdEnd = millis() + random(MIN_HOLD, MAX_HOLD);

  while (millis() < holdEnd) {
    if (checkFalseStart()) {
      return;
    }
  }

  allOff();

  long goTime = millis();
  bool clutchReleased = false;
  long reactionTime = -1;

  while (millis() - goTime < TIMEOUT) {
    if (!clutchReleased && digitalRead(BTN_CLUTCH) == HIGH) {
      clutchReleased = true;
    }
    if (clutchReleased && digitalRead(BTN_ACCELERATE) == LOW) {
      reactionTime = millis() - goTime;
      break;
    }
  }

  if (reactionTime < 0) {
    return;
  }

  showResult(reactionTime);
}

