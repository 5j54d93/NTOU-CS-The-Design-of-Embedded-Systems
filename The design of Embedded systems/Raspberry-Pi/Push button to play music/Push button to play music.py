import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

BUZZER_PIN = 11
BTN_PIN = 7

MELODY_DO = 523
MELODY_RE = 587
MELODY_ME = 659
MELODY_FA = 698
MELODY_SO = 784
MELODY_LA = 880
MELODY_SI = 988
MELODY_DOI = 1046
MELODY_REI = 1175
MELODY_MEI = 1318

LIST = [MELODY_MEI,MELODY_REI,MELODY_MEI,MELODY_REI,MELODY_MEI,MELODY_SI,MELODY_REI,MELODY_DOI,MELODY_LA,0,MELODY_DO,MELODY_ME,MELODY_LA,MELODY_SI,0,MELODY_ME,MELODY_SO,MELODY_SI,MELODY_DOI]

WAIT_TIME = 200
DURATION = 0.2

GPIO.setup(BUZZER_PIN, GPIO.OUT)
GPIO.setup(BTN_PIN, GPIO.IN, pull_up_down = GPIO.PUD_UP)

def buzz(pitch) :
    period = 1.0 / pitch
    half_period = period / 2
    cycles = int(DURATION * pitch)

    for i in range(cycles) :
        GPIO.output(BUZZER_PIN, GPIO.HIGH)
        time.sleep(half_period)
        GPIO.output(BUZZER_PIN, GPIO.LOW)
        time.sleep(half_period)

def mycallback(channel):
    print("Button pressed @:", channel, time.ctime())

    for i in LIST:
        if i == 0:
            time.sleep(1)
        else:
            buzz(i)

try:
    GPIO.add_event_detect(BTN_PIN, GPIO.FALLING, callback=mycallback, bouncetime=WAIT_TIME)

    while True:
        time.sleep(1)

except KeyboardInterrupt:
    print("Exception: KeyboardInterrupt")

finally:
    GPIO.cleanup()
