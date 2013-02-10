import os
import time

onPinForOutlet = { '1':'22', '2':'10', '3':'21' }
offPinForOutlet = { '1':'9', '2':'11', '3':'17' }

def application(environ, start_response):
	
	# Build a dictionary containing all of the request parameters
	
	querySplit = environ['QUERY_STRING'].split("&")
	query = {}
	for q in querySplit:
		qSplit = q.split("=")
		if len(qSplit) > 1:
			query[ qSplit[0] ] = qSplit[1]
	
	# Perform the requested operation
	
	if		query['function']=="turnOn":	pulse( onPinForOutlet[ query['outlet'] ] )
	elif	query['function']=="turnOff":	pulse( offPinForOutlet[ query['outlet'] ] )
	
	start_response('200 OK', [('Content-type', 'text/plain'), ('Content-Length', '')] )
	
	return ['']


def pulse(pin):
	spin = str(pin)
	os.system("gpio-admin export "+spin)
	os.system("echo out > /sys/devices/virtual/gpio/gpio"+spin+"/direction")
	os.system("echo 1 > /sys/devices/virtual/gpio/gpio"+spin+"/value")

	time.sleep(0.5)
	
	os.system("echo 0 > /sys/devices/virtual/gpio/gpio"+spin+"/value")
	os.system("gpio-admin unexport "+spin)
