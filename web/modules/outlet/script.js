Outlet = {
	
	build: function (label,id) {
	
		var control = $("<span>");
	
		control.addClass("outlet control");
	
		var labelSpan = $("<span>");
		labelSpan.text(label);
		control.append(labelSpan);
	
		var offButton = $("<button>");
		offButton.addClass("off");
		offButton.text("Off")
		control.append(offButton);
	
		offButton.on("click", function() {
			$.post( 'control/'+id, { state: 0 } );
		});
	
	
		var onButton = $("<button>");
		onButton.addClass("on");
		onButton.text("On");
		control.append(onButton);
	
		onButton.on("click", function() {
			$.post( 'control/'+id, { state: 1 } );
		});
	
		return control[0];
	}
}
