Lock = {
	build: function (label,id) {
	
		var control = $("<span>");
	
		control.addClass("lock control");
	
		var labelSpan = $("<span>");
		labelSpan.text(label);
		control.append(labelSpan);
	
		var unlockButton = $("<button>");
		unlockButton.addClass("unlock");
		unlockButton.text("Unlock")
		control.append(unlockButton);
	
		unlockButton.on("click", function() {
			$.post( 'control/'+id, { state: 0 } );
		});
	
	
		var lockButton = $("<button>");
		lockButton.addClass("lock");
		lockButton.text("Lock");
		control.append(lockButton);
	
		lockButton.on("click", function() {
			$.post( 'control/'+id, { state: 1 } );
		});
	
		return control[0];
	}
}
