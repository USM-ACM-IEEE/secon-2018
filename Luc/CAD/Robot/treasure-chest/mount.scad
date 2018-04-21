difference() {
	union() {
		cube([40, 70, 15]);
	}

	translate([0, 10, 5])
		cube([40, 50, 10]);

	for(y = [5, 65]) {
		for(x = [5:10:35])
			translate([x, y, 0])
				cylinder(d = 3, h = 15);
		for(x = [5, 35])
			translate([x, y, 0])
				cylinder(d = 6, h = 6);
	}
	for(x = [5:10:35])
		translate([x, 55, 0])
			cylinder(d = 3, h = 10);
}
