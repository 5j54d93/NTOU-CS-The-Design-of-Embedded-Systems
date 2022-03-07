import RPi.GPIO as GPIO
import time
import random

GPIO.setmode(GPIO.BOARD)                
BTN_PIN = 11
BTN_PIN1 = 10
LED_PIN = 12				
WAIT_TIME = 200
status = GPIO.LOW
GPIO.setup(BTN_PIN, GPIO.IN, pull_up_down = GPIO.PUD_UP)
# GPIO.setup(LED_PIN, GPIO.OUT, initial = status)

R_pin = 33 # R：33 號腳位（第 33 根 pin）
G_pin = 35 # G：35 號腳位（第 35 根 pin）
B_pin = 37 # B：37 號腳位（第 37 根 pin）

GPIO.setup(R_pin, GPIO.OUT)
GPIO.setup(G_pin, GPIO.OUT)
GPIO.setup(B_pin, GPIO.OUT)

R_pwm = GPIO.PWM(R_pin, 100)
G_pwm = GPIO.PWM(G_pin, 100)
B_pwm = GPIO.PWM(B_pin, 100)

# use python RPi.GPIO, square wave is 70k Hz
# use python wiringpi2 or bindings, square wave is 28k Hz
# use C wiringPi, square wave is 4.1-4.6M Hz

def check_RGB_range(R,G,B):
    
    if R < 0 : R = 0
    if G < 0 : G = 0
    if B < 0 : B = 0
    if R > 255 : R = 255
    if G > 255 : G = 255
    if B > 255 : B = 255
    
    return R,G,B

R,G,B = 255,255,255
state = 0
interval = 32

R_pwm.start(0)
G_pwm.start(0)
B_pwm.start(0)

def mycallback(channel):                                                 
	print("Button pressed @", time.ctime())
	global R,G,B,state
	while(1):
		if (state == 0):
			R = R
			G = G - interval
			B = B - interval
		if (state == 1):
			R = R - interval
			G = G + interval
			B = B
		if (state == 2):
			R = R
			G = G - interval
			B = B + interval
		if (state == 3):
			R = R + interval
			G = G
			B = B
		if (state == 4):
			R = R - interval
			G = G + interval
			B = B
		if (state == 5):
			R = R + interval
			G = G
			B = B - interval
		if (state == 6):
			R = R 
			G = G - interval
			B = B
            
		R,G,B = check_RGB_range(R,G,B)

		if(R == 255 and G == 255 and B == 255): state = 0 # WHITE
		if(R == 255 and G == 0 and B == 0): state = 1 # RED
		if(R == 0 and G == 255 and B == 0): state = 2 # GREEN
		if(R == 0 and G == 0 and B == 255): state = 3 # BLUE
		if(R == 255 and G == 0 and B == 255): state = 4 # Magenta
		if(R == 0 and G == 255 and B == 255): state = 5 # cyan-blue
		if(R == 255 and G == 255 and B == 0): state = 6 # YELLOW
        
        #mapping
		R_mapping = int (R / 255 * 100)
		G_mapping = int (G / 255 * 100)
		B_mapping = int (B / 255 * 100)
        
		R_pwm.ChangeDutyCycle(R_mapping)
		G_pwm.ChangeDutyCycle(G_mapping)
		B_pwm.ChangeDutyCycle(B_mapping)

		print("R,G,B:\t",R,G,B,"\t mapping: ",R_mapping,G_mapping,B_mapping)
		time.sleep(0.3)
	#GPIO.output(LED_PIN, status)

def mycallback1(channel):                                                 
	print("Button pressed @", time.ctime())
	global R,G,B,state
	state=random.random(0,6)
	while(1):
		if (state == 0):
			R = R
			G = G - interval
			B = B - interval
		if (state == 1):
			R = R - interval
			G = G + interval
			B = B
		if (state == 2):
			R = R
			G = G - interval
			B = B + interval
		if (state == 3):
			R = R + interval
			G = G
			B = B
		if (state == 4):
			R = R - interval
			G = G + interval
			B = B
		if (state == 5):
			R = R + interval
			G = G
			B = B - interval
		if (state == 6):
			R = R 
			G = G - interval
			B = B
            
		R,G,B = check_RGB_range(R,G,B)

		if(R == 255 and G == 255 and B == 255): state = 0 # WHITE
		if(R == 255 and G == 0 and B == 0): state = 1 # RED
		if(R == 0 and G == 255 and B == 0): state = 2 # GREEN
		if(R == 0 and G == 0 and B == 255): state = 3 # BLUE
		if(R == 255 and G == 0 and B == 255): state = 4 # Magenta
		if(R == 0 and G == 255 and B == 255): state = 5 # cyan-blue
		if(R == 255 and G == 255 and B == 0): state = 6 # YELLOW
        
        #mapping
		R_mapping = int (R / 255 * 100)
		G_mapping = int (G / 255 * 100)
		B_mapping = int (B / 255 * 100)
        
		R_pwm.ChangeDutyCycle(R_mapping)
		G_pwm.ChangeDutyCycle(G_mapping)
		B_pwm.ChangeDutyCycle(B_mapping)

		print("R,G,B:\t",R,G,B,"\t mapping: ",R_mapping,G_mapping,B_mapping)
		time.sleep(0.3)

try:
	GPIO.add_event_detect(BTN_PIN, GPIO.FALLING, callback=mycallback(11), bouncetime=WAIT_TIME)
	GPIO.add_event_detect(BTN_PIN1, GPIO.FALLING, callback=mycallback1(10), bouncetime=WAIT_TIME)

	while True:
		time.sleep(10)

except KeyboardInterrupt:
	print("Exception: KeyboardInterrupt")

finally:
	GPIO.cleanup()
