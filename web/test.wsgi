import os
import time

onPinForOutlet = { '1':'0', '2':'1', '3':'4' }
offPinForOutlet = { '1':'17', '2':'21', '3':'22' }

def application(environ, start_response):
	
	# Build a dictionary containing all of the request parameters
	
	querySplit = environ['QUERY_STRING'].split("&")
	query = {}
	for q in querySplit:
		qSplit = q.split("=")
		if len(qSplit) > 1:
			query[ qSplit[0] ] = qSplit[1]
	
	# Perform the requested operation
	
	if query['id']=="4":
		send( 1-int(query['state']) )
	else:
		if query['state']=="0":
			pulse( onPinForOutlet[ query['id'] ] )
		
		elif query['state']=="1":
			pulse( offPinForOutlet[ query['id'] ] )
	
	start_response('200 OK', [('Content-type', 'text/plain'), ('Content-Length', '')] )
	
	return ['']


def pulse(pin):
	spin = str(pin)
	os.system("gpio-admin export "+spin)
	os.system("echo out > /sys/devices/virtual/gpio/gpio"+spin+"/direction")
	os.system("echo 1 > /sys/devices/virtual/gpio/gpio"+spin+"/value")

	time.sleep(0.3)
	
	os.system("echo 0 > /sys/devices/virtual/gpio/gpio"+spin+"/value")
	os.system("gpio-admin unexport "+spin)

def send(state):
	sstate = str(state)
	os.system("sudo /home/pi/WSUEECS/haf/send "+sstate)


