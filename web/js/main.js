var controls = [ 
	{
		id: 3,
		type: "Lock",
		label: "Front door"
	}, {
		id: 1,
		type: "Outlet",
		label: "Living Room Lamp"
	}
];


$(document).ready( function() {
	
	$.each(controls, function(index,control) {
		try {
			var controlDef = window[control["type"]];
			var controlNode = controlDef.build( control.label, control.id ) 
			$("#controls").append( controlNode );
		}
		catch (err) {
			console.log("Couldn't build control at index "+index+" due to error: "+err.message);
		}
	});
	
});
