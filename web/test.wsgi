import os
import time
def log(message):
	#log message
	logfile = open("/home/pi/WSUEECS/haf/web/usage.log","a")
	logfile.write(time.asctime()+': '+message+'\n')
	logfile.close()

def application(environ, start_response):
	
	# Build a dictionary containing all of the request parameters
	
	log(environ['QUERY_STRING'].replace('&', ' '))
	querySplit = environ['QUERY_STRING'].split("&")
	query = {}
	for q in querySplit:
		qSplit = q.split("=")
		if len(qSplit) > 1:
			query[ qSplit[0] ] = qSplit[1]
	
	# Perform the requested operation
	
	send( query['address'], 1-int(query['state']) )
	
	start_response('200 OK', [('Content-type', 'text/plain'), ('Content-Length', '')] )
	
	return ['']

def send(address,state):
	sstate = str(state)
	os.system("sudo /home/pi/WSUEECS/haf/web/send "+address+" "+sstate)
